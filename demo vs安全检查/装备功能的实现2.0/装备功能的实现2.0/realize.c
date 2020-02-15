#include "equipment.h"
void equit(Player * players)
{
	players->attack += players->weapon.attack;
	players->defense += players->weapon.defense;
	players->hp += players->weapon.hp;
	players->mp += players->weapon.mp;
	players->attack += players->armor.attack;
	players->defense += players->armor.defense;
	players->hp += players->armor.hp;
	players->mp += players->armor.mp;
}