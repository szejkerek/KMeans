# K-Means Clustering Algorithm

This repository contains an implementation of the K-Means clustering algorithm in C++. The K-Means algorithm is an unsupervised machine learning algorithm used to partition a dataset into K distinct clusters based on their similarity. It is widely used in various applications, such as image compression, customer segmentation, and anomaly detection.

## Usage

To use the K-Means clustering algorithm, you need to follow these steps:

1. Create a file containing your data points. Each line in the file represents a data point, where each value is separated by a space. For example:
```
4.44 5 7
45 65 70
4 5 8
6 4 7
50 70 50
66 68 40
59 44 43
```

2. Run the program, providing the input file, output file, number of dimensions, and number of clusters as command-line arguments. For example:

```
./kmeans -i input.txt -o output.txt -d 2 -k 3
```

4. The program will read the data points from the input file, perform the K-Means algorithm, and save the results to the output file.

## File Structure

The repository is structured as follows:

- `main.cpp`: The main entry point of the program. It reads command-line arguments, initializes the algorithm, and saves the results to a file.
- `KMeansAlgorithm.h`: Header file containing the declaration of the `KMeansAlgorithm` class, which implements the K-Means algorithm.
- `KMeansAlgorithm.cpp`: Source file containing the implementation of the `KMeansAlgorithm` class methods.
- `Point.h`: Header file defining the `Point` struct, which represents a data point.
- `Cluster.h`: Header file defining the `Cluster` struct, which represents a cluster.
- `LoadData.h`: Header file containing the declaration of the `LoadData` struct, which reads data points from a file.
- `LoadData.cpp`: Source file containing the implementation of the `LoadData` struct methods.
- `ParametersReader.h`: Header file containing the declaration of the `ParametersReader` class, which reads command-line arguments.
- `ParametersReader.cpp`: Source file containing the implementation of the `ParametersReader` class methods.

## Installation

To use this code, follow these steps:

1. Clone this repository to your local machine using the following command:

```
git clone https://github.com/szejkerek/KMeans
```

2. Build the project using your preferred C++ compiler.

## Contributing

Contributions to this project are welcome. If you find any issues or want to suggest improvements, please open an issue or submit a pull request.
