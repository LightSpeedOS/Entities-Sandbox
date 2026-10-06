#pragma once


inline void showStatus(Entity* pLocalPlayer, Entity* target)
{

	SetConsoleTitleA("Entity Sandbox");

	cout << "====== Entities Sandbox ======" << endl;
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