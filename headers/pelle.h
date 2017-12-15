#include "../headers/objet.h"

#pragma once

class pelle : public objet
{
	public:
		pelle();
		virtual string getType() override;
};