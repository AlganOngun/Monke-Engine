#pragma once

#include "../Macros.h"
#include <functional>

class EI Event
{
public:
	virtual void dispatch() = 0;
};
