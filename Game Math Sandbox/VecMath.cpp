#include "VecMath.h"

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

	cout << localPlayer->name << " (" << localPlayer->Position.x << ", " << localPlayer->Position.y << ")" << endl;
	cout << target->name << " (" << target->Position.x << ", " << target->Position.y << ")" << endl;
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

void getDirection(Entity* a, Entity* b)
{
	float disX = b->Position.x - a->Position.x;
	float disY = b->Position.y - a->Position.y;

	cout << "Direction: " << "(" << disX << ", " << disY << ")" << endl;
	getKey();
}

void calculateDirection(Entity* localPlayer, Entity* target)
{

	cout << localPlayer->name << " (" << localPlayer->Position.x << ", " << localPlayer->Position.y << ") -> "
		<< target->name << " (" << target->Position.x << ", " << target->Position.y << endl;
	space();

	getDirection(localPlayer, target);
}