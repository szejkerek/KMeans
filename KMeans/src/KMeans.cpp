#include "Loading data/LoadData.h"
#include <iostream>

int main()
{
	LoadData loader;

	auto points = loader.ReadFile("input3.txt", 3);

    for (const auto& point : points) {
        for (const auto& value : point.values) {
            std::cout << value << " ";
        }

        std::cout << std::endl;
    }
}