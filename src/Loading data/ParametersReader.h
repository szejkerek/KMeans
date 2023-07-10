#pragma once
#include <iostream>
#include <string>
class ParametersReader
{
	std::string inputFile = "";
	std::string outputFile = "";
	std::string clustersValue = "";
	std::string dimensionsValue = "";

public:
	void ReadParameters(int arg, char* argv[])
	{
		bool i_onceUsed = false;
		bool k_onceUsed = false; 
		bool o_onceUsed = false;
		bool d_onceUsed = false;

		for (int i = 1; i < arg; i++)
		{
			if (argv[i][0] == '-')
			{
				switch (argv[i][1])
				{
					case 'i':
					{
						if (i_onceUsed)
							throw std::runtime_error("Use of the same parameter!");

						i_onceUsed = true;
						inputFile = argv[i + 1];
						break;
					}
					case 'k':
					{
						if (k_onceUsed)
							throw std::runtime_error("Use of the same parameter!");

						k_onceUsed = true;
						clustersValue = argv[i + 1];
						break;
					}
					case 'o':
					{
						if (o_onceUsed)
							throw std::runtime_error("Use of the same parameter!");

						o_onceUsed = true;
						outputFile = argv[i + 1];
						break;
					}
					case 'd':
					{
						if (d_onceUsed)
							throw std::runtime_error("Use of the same parameter!");

						d_onceUsed = true;
						dimensionsValue = argv[i + 1];
						break;
					}
					default:
					{
						throw std::runtime_error("Undefined parameter!");
						return;
					}

				}
			}
			i++;
		}

		if(inputFile.empty())
			throw std::runtime_error("Failed to read all parameters!");
		if (outputFile.empty())
			throw std::runtime_error("Failed to read all parameters!");
		if (clustersValue.empty())
			throw std::runtime_error("Failed to read all parameters!");
		if (dimensionsValue.empty())
			throw std::runtime_error("Failed to read all parameters!");

	}

	std::string GetInputFile()	{ return inputFile; };
	std::string GetOutputFile() { return outputFile; };
	int GetClustersValue()		{ return std::stoi(clustersValue); };
	int GetDimensionsValue()	{ return std::stoi(dimensionsValue); };
};