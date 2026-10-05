#pragma once

#include "Structs.h"
#include "Logic.h"

float getDistance(Entity* a, Entity* b);

void calculateDistance(Entity* localPlayer, Entity* target);

void getDirection(Entity* a, Entity* b);

void calculateDirection(Entity* localPlayer, Entity* target);