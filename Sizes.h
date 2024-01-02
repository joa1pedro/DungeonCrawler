#pragma once

enum Sizes
{
	// Numbers for the enum representing the Damage based on the size
	Small = 0,
	Medium,
	Large,
	Count, // For sake of tracking how many enums we have. Keep it at the bottom
};

// Sizes goes from 0 to 2 where 0 = Small | 1 = Medium | 2 = Large
std::string sizeEnumToStr(int size)
{
	std::string str("unknown");
	switch (size)
	{
	case 0: { str = "Small"; } break;
	case 1: { str = "Medium"; } break;
	case 2: { str = "Large"; } break;
	}
	return str;
}