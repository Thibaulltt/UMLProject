#include "../headers/objet.h"

#pragma once

class tresor : public objet
{
	public:
		tresor();
		virtual string getType() override;
};