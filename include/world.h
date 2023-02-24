#ifndef RAG_WORLD_H
#define RAG_WORLD_H

#include "body.h"

typedef struct World {
    Body *bodies;
    int size;
    int width;
    int height;
} World;

/* Allocate World with given SIZE, WIDTH and HEIGHT. */
World *World_create(int size, int width, int height);

/* Free previously allocated World. */
void World_destroy(World *world);

/* Update WORLD assuming T seconds passed. */
void World_update(World *world, double t);

#endif //RAG_WORLD_H