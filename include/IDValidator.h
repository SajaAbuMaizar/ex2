#pragma once
#include <cstdint>
#include "Validator.h"

class IDValidator : public Validator <uint32_t>
{
public:
	IDValidator& get() { return *this; };

private:
};
