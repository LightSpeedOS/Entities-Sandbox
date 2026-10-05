#pragma once

#include "Structs.h"
#include "Includes.h"

inline Entity* findLocalPlayer(vector<Entity>& entities)
{
	Entity* pLocalPlayer = nullptr;

	for (size_t i = 0; i < entities.size(); i++)
	{
		if (entities[i].isLocal) return pLocalPlayer = &entities[i];
	}
	return nullptr;
}

inline void moveLocalPlayer(Entity* localPlayer)
{
	clear();
	int step = 5;

	while (true)
	{ 
		clear();

	cout << "======== Move Player ========" << endl;
	space();

	cout << "Position: " << localPlayer->Position.x << ", " << localPlayer->Position.y << endl;
	cout << "Step: " << step << "m" << endl;
	space();

	cout << setw(14) << "[W]" << " Forward" << endl;
	cout << "[A] Left   [S] Back   [D] Right" << endl;
	space();

	cout << "[1] 5m   [2] 10m   [3] 15m" << endl;
	cout << "[R] Return" << endl;

	char key = _getch();

	switch (tolower(key))
	{
	case 'w':
		localPlayer->Position.y += step;
		break;

	case 's':
		localPlayer->Position.y -= step;
		break;

	case 'a':
		localPlayer->Position.x -= step;
		break;

	case 'd':
		localPlayer->Position.x += step;
		break;

	case '1':
		step = 5;
		break;

	case '2':
		step = 10;
		break;

	case '3':
		step = 15;
		break;

	case 'r':
		clear();
		cout << "Returning." << endl;
		return;


	default:
		invalid();
		while (_kbhit()) _getwch();
		break;
	}
	}
}

inline Entity* selectTarget(vector<Entity>& entities)
{
	clear();

	string nameSearch;
	Entity* currentTarget = nullptr;

	cout << "=======Pick a Target=======" << endl;
	space();

	for (size_t i = 0; i < entities.size(); i++)
	{
		if (entities[i].isLocal) continue;

		cout << "[ " << i << " ] Name: " << entities[i].name << " ("
			<< entities[i].Position.x << ", " << entities[i].Position.y << ")" << endl;
		space();
	}

	cout << "Enter Name: ";
	cin.ignore();
	getline(cin, nameSearch);
	space();

	if (nameSearch.empty())
	{
		clear();
		cout << "[!] Name Cannot Be Left Empty" << endl;
		pause();
		return nullptr;
	}

	for (size_t i = 0; i < entities.size(); i++)
	{
		if (entities[i].isLocal) continue;

		if (toLower(nameSearch) == toLower(entities[i].name))
		{
			currentTarget = &entities[i];
			break;
		}
	}

	if (currentTarget == nullptr)
	{
		clear();
		cout << "[!] Entity Not Found: " << nameSearch << endl;
		pause();
		return nullptr;
	}

	clear();
	cout << "[+] " << green << "Successfully " << reset << "Found Target -> " << currentTarget->name
		<< " (" << currentTarget->Position.x << ", " << currentTarget->Position.y << ")" << endl;
	getKey();

	return currentTarget;
}