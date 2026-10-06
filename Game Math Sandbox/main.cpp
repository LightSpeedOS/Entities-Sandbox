#include "Includes.h"
#include "Structs.h"
#include "BackendLogic.h"
#include "Logic.h"
#include "Entities.h"
#include "VecMath.h"

using namespace std;

auto main() -> int
{
	vector<Entity> entities;
	setUpEntities(entities);

	Entity* currentTarget = nullptr;
	Entity* pLocalPlayer = findLocalPlayer(entities);

	Setting setting;

	int mainOption;

	while (true)
	{
		clear();

		showStatus(pLocalPlayer, currentTarget);

		cout << "[1] Move Player" << endl;
		cout << "[2] Select Taregt" << endl;
		cout << "[3] Move Target" << endl;
		cout << "[4] Distance" << endl;
		cout << "[5] Direction To Target" << endl;
		cout << "[6] Magnitude" << endl;
		cout << "[7] Normalize" << endl;
		cout << "[8] Exit" << endl;

		space();
		cout << "> ";
		cin >> mainOption;

		if (input())
		{
			continue;
		}

		switch (mainOption)
		{

		case MovePlayer:
			moveEntity(pLocalPlayer);
			break;

		case SelectTarget:
			currentTarget = selectTarget(entities);
			break;

		case MoveTarget:
			moveEntity(currentTarget);
			break;

		case Distance:
			calculateDistance(pLocalPlayer, currentTarget);
			break;

		case Direction:
			calculateDirection(pLocalPlayer, currentTarget);
			break;

		case Magnitude:
			calculateMagnitude(pLocalPlayer, currentTarget);
			break;

		case Normalize:
			calculateNormalize(pLocalPlayer, currentTarget);
			break;

		case Exit:
			invalid();
			break;

		default:
			invalid();
			break;

		}
	}
}