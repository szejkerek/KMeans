#pragma once
#include "../Data structures/Point.h"
#include <string>
#include <sstream>
#include <fstream>

struct LoadData
{
    std::vector<Point> ReadFile(const std::string& fileName, int dimesnions)
    {
        std::vector<Point> points;
        std::ifstream file(fileName);
        std::string line;

        while (std::getline(file, line)) {
            Point point;
            std::stringstream lineStream(line);
            double value;

            while (lineStream >> value) {
                point.position.push_back(value);
            }

            if (point.position.size() != dimesnions) {
                throw std::runtime_error("Values don't match given dimensions!");
            }

            points.push_back(point);
        }

        return points;
    }
};

