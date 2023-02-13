#include "Loading data/LoadData.h"
#include "Loading data/ParametersReader.h"
#include <iostream>

int main(int arg, char** argv)
{
    ParametersReader parametersReader;
	LoadData loader;
    try {
       // parametersReader.ReadParameters(arg, argv);
        
        std::vector<Point> points = loader.ReadFile("input3.txt", 3);
    }
    catch (std::exception e)
    {
        std::cout<< e.what() << std::endl;
    }
}