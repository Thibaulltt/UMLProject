#pragma once

#include "../headers/objetCombat.h"

class mousquet : public objetCombat
{
	public:
		mousquet();
		virtual string getType() override;
};