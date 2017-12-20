#pragma once

#include "../headers/objetCarte.h"

class objetCombat : public objetCarte
{
	protected:
		int attack;
		int defense;

	public:
			void theFct();
		objetCombat(string nom_n, int att_n, int def_n, bool ramassable_n);
		int getAttack();
		int getDefense();
		string toString() override;
		~objetCombat();
};
