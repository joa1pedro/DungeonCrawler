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

// Converts int to Sizes Enum string name 
const std::string& sizeEnumToStr(int size);

// Converts int to Sizes Enum
Sizes sizeIntToEnum(int size);