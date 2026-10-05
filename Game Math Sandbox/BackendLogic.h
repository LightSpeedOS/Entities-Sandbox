#pragma once


inline void showStatus(Entity* pLocalPlayer, Entity* target)
{

	SetConsoleTitleA("Entity Sandbox");

	cout << "====== Game Math Sandbox ======" << endl;
	space();

	cout << pLocalPlayer->name << " Position: (" << pLocalPlayer->Position.x << ", " << pLocalPlayer->Position.y << ")" << endl;

	if (target == nullptr) cout << "Selected Target : None" << endl;
	else cout << "Selected Target " << target->name << ": (" << target->Position.x << ", " << target->Position.y << ")" << endl;
	space();
}

inline string toLower(string text)
{
	for (char& c : text)
	{
		c = tolower(c);
	}
	return text;
}

inline void tagBot(Entity* entity, Setting* setting)
{
	clear();

	if (entity == nullptr)
	{
		cout << "Select a Target Before Using This Option" << endl;
		pause();
		return;
	}
	string nameSnapshot = entity->name;

	if (setting->toggleBot)
	{
		setting->toggleBot = false;
		entity->name = nameSnapshot;
		return;
	}

	string addBot = entity->name + " [Bot]";
	setting->toggleBot = true;
}