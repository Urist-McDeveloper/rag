#ifndef RAG_H
#define RAG_H

#include <math.h>   // hypotf

/*
 * Gravitational constant; controls pulling force.
 *      g = RAG_G * mass / dist^2
 */
#define RAG_G   10.0f

/*
 * "Negative" gravity; controls pushing force.
 *      n = RAG_N * mass / dist^3
 */
#define RAG_N   (-80.f * RAG_G)

/* A fraction of velocity that becomes friction. */
#define RAG_FRICTION    (-0.01f)

/* 2D vector of floats. */
typedef struct V2 {
    float x, y;
} V2;

/* Zero-length vector. */
#define V2_ZERO         (V2){ .x = 0.0, .y = 0.0 }

/* Constructor macro. */
#define V2_From(X, Y)   (V2){ .x = (X), .y = (Y) }

/* Vector addition. */
static inline V2 V2_Add(V2 a, V2 b) {
    return V2_From(a.x + b.x, a.y + b.y);
}

/* Scalar multiplication. */
static inline V2 V2_Mul(V2 v, float f) {
    return V2_From(v.x * f, v.y * f);
}

/* Simulation particle. */
typedef struct Particle {
    V2 pos, vel, acc;
    float mass, radius;
} Particle;

// Vulkan requires structs to be aligned on 16 bytes
_Static_assert(sizeof(Particle) == 32, "sizeof(Particle) must be 32");

/* The simulated world with fixed particle count. */
typedef struct World World;

/* Create World of given SIZE and randomize particle positions within MIN and MAX. */
World *World_Create(int size, V2 min, V2 max);

/* Destroy World. */
void World_Destroy(World *w);

/* Perform N updates using CPU simulation. */
void World_Update(World *w, float dt, int n);

/* Get Particle array and its size. */
void World_GetParticles(World *w, Particle **ps, int *size);

#endif //RAG_H
