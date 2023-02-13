#include "LoadData.h"
#include <sstream>
#include <fstream>

std::vector<Point> LoadData::ReadFile(const std::string& fileName, int dimesnions)
{
    std::vector<Point> points;
    std::ifstream file(fileName);
    std::string line;

    while (std::getline(file, line)) {
        Point point;
        std::stringstream lineStream(line);
        double value;

        while (lineStream >> value) {
            point.values.push_back(value);
        }

        if (point.values.size() != dimesnions) {
            throw std::runtime_error("Values don't match given dimensions!");
        }

        points.push_back(point);
    }

    return points;
}