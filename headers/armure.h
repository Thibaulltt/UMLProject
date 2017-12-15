#include "../headers/objetCombat.h"

#pragma once

class armure : public objetCombat
{
	public:
		armure();
		virtual string getType() override;
};