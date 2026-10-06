#pragma once

#include "Includes.h"

enum mainMenu
{
	MovePlayer = 1,
	SelectTarget,
	MoveTarget,
	Distance,
	Direction,
	Magnitude,
	Normalize,
	Exit
};

enum subMenu
{
	Bot = 1,
	Meters,
	Return
};

struct Vec2
{
	float x, y;
};

struct Entity
{
	string name;
	bool isLocal;
	Vec2 Position;
};

struct Setting
{
	bool toggleBot = false; // Will Display "[Bot]" Next To Name
	bool showMeters = false;
	static constexpr float unitsPerMeter = 100.0f;
};