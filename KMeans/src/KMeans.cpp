#include "Loading data/LoadData.h"
#include "Loading data/ParametersReader.h"
#include "Algorithm/KMeansAlgorithm.h"
#include <iostream>

int main(int arg, char** argv)
{
    ParametersReader parametersReader;
	LoadData loader;
    try {
        parametersReader.ReadParameters(arg, argv);     
        std::string inputFile = parametersReader.GetInputFile();
        std::string outputFile = parametersReader.GetOutputFile();
        int dimensions = parametersReader.GetDimensionsValue();
        int clusters = parametersReader.GetClustersValue();

        //std::string inputFile = "input2.txt";
        //std::string outputFile = "output.txt";
        //int dimensions = 2;
        //int clusters = 3;

        std::vector<Point> points = loader.ReadFile(inputFile, dimensions);
        KMeansAlgorithm algorithm(points, dimensions, clusters);
        algorithm.PerformAlgorithm(10);
        algorithm.SaveValuesToFile(outputFile);
    }
    catch (std::exception e)
    {
        std::cout<< e.what() << std::endl;
    }
}