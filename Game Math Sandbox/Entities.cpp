#include "Entities.h"

void setUpEntities(vector<Entity>& entities)
{
	Entity localPlayer;
	localPlayer.name = "Jamaal";
	localPlayer.isLocal = true;
	localPlayer.Position.x = 20;
	localPlayer.Position.y = 9;
	entities.push_back(localPlayer);

	Entity tomBot;
	tomBot.name = "Tom";
	tomBot.isLocal = false;
	tomBot.Position.x = 45;
	tomBot.Position.y = 13;
	entities.push_back(tomBot);

	Entity samBot;
	samBot.name = "Sam";
	samBot.isLocal = false;
	samBot.Position.x = 34;
	samBot.Position.y = 20;
	entities.push_back(samBot);

	Entity claude;
	claude.name = "Claude";
	claude.isLocal = false;
	claude.Position.x = 10;
	claude.Position.y = 5;
	entities.push_back(claude);
}