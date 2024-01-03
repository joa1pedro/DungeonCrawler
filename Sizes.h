#pragma once

enum Sizes
{
	// Numbers for the enum representing the Damage based on the size (See enemy.h::CreateRandomEnemy)
	Small = 0,
	Medium,
	Large,
	ExtraLarge,
	Count, // For sake of tracking how many enums we have. Keep it at the bottom
};

// Converts int to Size Enum name in string
std::string sizeEnumToStr(int size)
{
	std::string str("unknown");
	switch (size)
	{
	case 0: { str = "Small"; } break;
	case 1: { str = "Medium"; } break;
	case 2: { str = "Large"; } break;
	case 3: { str = "ExtraLarge"; } break;
	}
	return str;
}

// Converts int to Sizes Enum
Sizes sizeIntToEnum(int size)
{
	switch (size)
	{
	case 0: { return Small; } break;
	case 1: { return Medium; } break;
	case 2: { return Large; } break;
	case 3: { return ExtraLarge; } break;
	}
}