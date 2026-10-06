#pragma once

#include "Structs.h"
#include "Logic.h"

void printCoords(Entity* localPlayer, Entity* target);

float getDistance(Entity* a, Entity* b);

void calculateDistance(Entity* localPlayer, Entity* target);

Vec2 getDirection(Entity* a, Entity* b);

void calculateDirection(Entity* localPlayer, Entity* target);

float getMagnitude(const Vec2& v);

void calculateMagnitude(Entity* localPlayer, Entity* target);

Vec2 calculateNormalize(Entity* localPlayer, Entity* target);