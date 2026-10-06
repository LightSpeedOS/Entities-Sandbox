#include "VecMath.h"

void printCoords(Entity* localPlayer, Entity* target)
{
	cout << localPlayer->name << " (" << localPlayer->Position.x << ", " << localPlayer->Position.y << ")" << endl;
	cout << target->name << " (" << target->Position.x << ", " << target->Position.y << ")" << endl;
}

float getDistance(Entity* a, Entity* b)
{
	float disX = b->Position.x - a->Position.x;
	float disY = b->Position.y - a->Position.y;

	return sqrt((disX * disX) + (disY * disY));
}

void calculateDistance(Entity* localPlayer, Entity* target)
{
	clear();

	if (target == nullptr)
	{
		cout << "[!] No Target Selected" << endl;
		pause();
		return;
	}

	float distance = getDistance(localPlayer, target);

	printCoords(localPlayer, target);
	cout << "Distance: " << setprecision(2) << distance << endl;

	space();
	cout << "[1] Move Player   [2] Move Target   [R] Return" << endl;

	char key = _getch();

	switch (tolower(key))
	{
	case '1':
		moveEntity(localPlayer);
		break;

	case '2':
		moveEntity(target);
		break;

	case 'r':

		return;

	default:
		invalid();
		while (_kbhit()) _getch();
		break;
	}
}

Vec2 getDirection(Entity* a, Entity* b)
{
	clear();

	if (a == nullptr || b == nullptr)
	{
		clear();
		cout << "[!] No Entity To Calculate" << endl;
		pause();
		return Vec2{};
	}
	Vec2 dir;
	dir.x = b->Position.x - a->Position.x;
	dir.y = b->Position.y - a->Position.y;
	return dir;
}

void calculateDirection(Entity* localPlayer, Entity* target)
{
	clear();

	printCoords(localPlayer, target);

	Vec2 dir;
	dir.x = target->Position.x - localPlayer->Position.x;
	dir.y = target->Position.y - localPlayer->Position.y;

	cout << "Direction: " << "(" << dir.x << ", " << dir.y << ")" << endl;
	getKey();
}

float getMagnitude(const Vec2& v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

void calculateMagnitude(Entity* localPlayer, Entity* target)
{
	clear();
	if (localPlayer == nullptr || target == nullptr)
	{
			clear();
			cout << "[!] No Entity To Calculate" << endl;
			pause();
			return;
	}

	Vec2 dir = getDirection(localPlayer, target);
	float mag = getMagnitude(dir);

	printCoords(localPlayer, target);
	cout << "Magnitude: " << mag << endl;
	getKey();
}

Vec2 calculateNormalize(Entity* localPlayer, Entity* target)
{
	Vec2 dir = getDirection(localPlayer, target);
	float mag = getMagnitude(dir);

	if (mag == 0) return Vec2{};

	Vec2 result;

	result.x = dir.x / mag;
	result.y = dir.y / mag;

	cout << "Normalized Direction: " << "(" << result.x << ", " << result.y << endl;
	cout << "Magnitude Check: " << getMagnitude(dir) << endl;
	getKey();
}