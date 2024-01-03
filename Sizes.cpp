#pragma once
#include <iostream>
#include "Sizes.h"

const std::string& sizeEnumToStr(int size)
{
	switch (size) {
		case 0: { return "Small"; } break;
		case 1: { return "Medium"; } break;
		case 2: { return "Large"; } break;
		case 3: { return "ExtraLarge"; } break;
	}
}

Sizes sizeIntToEnum(int size)
{
	switch (size) {
		case 0: { return Small; } break;
		case 1: { return Medium; } break;
		case 2: { return Large; } break;
		case 3: { return ExtraLarge; } break;
	}
}