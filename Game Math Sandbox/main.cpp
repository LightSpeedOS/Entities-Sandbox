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
		cout << "[7] Options" << endl;
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
			moveLocalPlayer(pLocalPlayer);
			break;

		case SelectTarget:
			currentTarget = selectTarget(entities);
			break;

		case MoveTarget:

			break;

		case Distance:

			break;

		case Direction:

			break;

		case Magnitude:

			break;

		case Normalize:

			break;

		case Options:

			break;

		case Exit:

			break;
		}
	}
}