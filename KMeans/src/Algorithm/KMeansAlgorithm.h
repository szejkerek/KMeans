#pragma once
#include "../Data structures/Point.h"
#include "../Data structures/Cluster.h"
#include <string>

class KMeansAlgorithm 
{
	std::vector<Cluster> _clusters;
	std::vector<Point> _allPoints;
	std::vector < std::pair<double, double> > _minMaxValues;

	int _dimensionsNumber = 0;
	int _clusersNumber = 0;

public:
	KMeansAlgorithm(const std::vector<Point>& points, int dimensionsNumber, int clusersNumber);

	void PerformAlgorithm(int iterations);
	void SaveValuesToFile(const std::string& filename);

private:
	void PrintResultsOnScreen();
	void AssignClustersToPoints();
	double GetRandomNumber(double min, double max);
	double FindDistance(const Cluster& cluster, const Point& point);
	void InitializeCluster(Cluster& cluster, int ClusterID);
	Cluster FindMinCluster(const Point& point);
	void CalculateClustersPosition();
	std::vector<double> CalculateRandomClusterPosition();

};