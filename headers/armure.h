#pragma once

#include "../headers/objetCombat.h"

class armure : public objetCombat
{
	public:
		armure();
		virtual string getType() override;
};