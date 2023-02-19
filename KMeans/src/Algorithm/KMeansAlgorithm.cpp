#include "KMeansAlgorithm.h"
#include <algorithm>
#include <float.h>
#include <random>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <fstream>

void KMeansAlgorithm::Initialize(const std::vector<Point>& points, int dimensionsNumber, int clusersNumber)
{
	srand(time(NULL));
	_allPoints = points;
	_dimensionsNumber = dimensionsNumber;
	_clusersNumber = clusersNumber;

	for (int i = 0; i < clusersNumber; i++)
	{
		Cluster temp;
		InitializeCluster(temp, i);
		_clusters.push_back(temp);
	}
}

void KMeansAlgorithm::PerformAlgorithm(int iterations)
{
	for (int i = 0; i < iterations; i++)
	{
		AssignClustersToPoints();
		CalculateClustersPosition();
	}
	PrintResultsOnScreen();
}

void KMeansAlgorithm::SaveValuesToFile(const std::string& filename)
{
	std::ofstream myfile(filename);

	if (!myfile)
	{
		throw std::runtime_error("Couldn't create output file!");
		return;
	}

	for (auto cluster : _clusters)
	{
		myfile << "[Klaster " << cluster.cluserID << "] ";
		for (int i = 0; i < _dimensionsNumber; i++)
		{
			myfile << cluster.position[i] << " ";
		}
		myfile << std::endl;

		for (auto point : _allPoints)
		{
			if (point.currentCluserID == cluster.cluserID)
			{
				for (int i = 0; i < _dimensionsNumber; i++)
				{
					myfile << point.position[i] << "\t";
				}
				myfile << std::endl;
			}
		}
		myfile << std::endl;
		myfile << std::endl;
	}

	myfile.close();
}

void KMeansAlgorithm::PrintResultsOnScreen()
{
	for (auto cluster : _clusters)
	{
		std::cout << "[Klaster " << cluster.cluserID << "] ";
		for (int i = 0; i < _dimensionsNumber; i++)
		{		
			std::cout << cluster.position[i] << " ";
		}
		std::cout << std::endl;

		for (auto point : _allPoints)
		{
			if (point.currentCluserID == cluster.cluserID)
			{
				for (int i = 0; i < _dimensionsNumber; i++)
				{
					std::cout << point.position[i] << "\t";
				}
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
}

static void MinMax(const std::vector<Point>& vec, int posIndex, double& min, double& max) {
	min = vec[0].position[posIndex];
	max = vec[0].position[posIndex];

	for (Point num : vec) {
		double posValue = num.position[posIndex];
		if (posValue < min) {
			min = posValue;
		}
		if (posValue > max) {
			max = posValue;
		}
	}
}

std::vector<double> KMeansAlgorithm::CalculateRandomClusterPosition()
{
	std::vector<double> position;
	for (int i = 0; i < _dimensionsNumber; i++)
	{ 
		double min;
		double max;
		MinMax(_allPoints, i, min, max);

		position.push_back(GetRandomNumber(min, max));
	}
	return position;
}

void KMeansAlgorithm::InitializeCluster(Cluster& cluster, int clusterID)
{
	cluster.cluserID = clusterID;
	for (int i = 0; i < _dimensionsNumber; i++)
	{
		cluster.position = CalculateRandomClusterPosition();
	}
}

Cluster KMeansAlgorithm::FindMinCluster(const Point& point)
{
	double minDistance = FindDistance(_clusters[0], point);
	int minIndex = 0;
	for (int i = 1; i < _clusersNumber; i++) {
		double distance = FindDistance(_clusters[i], point);
		if (distance < minDistance) {
			minDistance = distance;
			minIndex = i;
		}
	}
	return _clusters[minIndex];
}

static bool AreAllZeros(const std::vector<double>& vec) 
{
	for (int num : vec) {
		if (num != 0) {
			return false;
		}
	}
	return true;
}

void KMeansAlgorithm::CalculateClustersPosition()
{
	for (Cluster& cluster : _clusters)
	{	
		bool hasPoints = false;
		int n = _dimensionsNumber;
		std::vector<double> avg(n, 0.0);

		for (const auto& point : _allPoints) {
			if (point.currentCluserID != cluster.cluserID)
			{
				continue;
			}
			else 
			{
				hasPoints = true;
			}

			for (int i = 0; i < n; i++) {
				avg[i] += point.position[i];
			}
		}

		if (!AreAllZeros(avg))
		{
			for (int i = 0; i < n; i++) {
				avg[i] /= _allPoints.size();
			}
			cluster.position = avg;
		}
	}	
}

double KMeansAlgorithm::GetRandomNumber(double min, double max)
{
	double f = (double)rand() / RAND_MAX;
	return min + f * (max - min);
}

double KMeansAlgorithm::FindDistance(const Cluster& cluster, const Point& point)
{
	double distance = 0.0;
	for (int i = 0; i < _dimensionsNumber; i++) {
		distance += std::pow(cluster.position[i] - point.position[i], 2);
	}
	return std::sqrt(distance);
}

void KMeansAlgorithm::AssignClustersToPoints()
{
	for (Point& currentPoint : _allPoints)
	{
		Cluster min = FindMinCluster(currentPoint);
		currentPoint.currentCluserID = min.cluserID;
	}
}
