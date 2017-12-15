#pragma once

#include <string>

#include "../headers/objetCarte.h"

class objet : public objetCarte
{
	public:
		objet();
		~objet();
		virtual string getType() override;
};