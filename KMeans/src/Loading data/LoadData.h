#pragma once
#include <string>
#include "../Data structures/Point.h"

class LoadData
{
public:
	std::vector<Point> ReadFile(const std::string& fileName, int dimesnions);
};

