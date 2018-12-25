#include "matrixReading.h"
#include <vector>
#include <fstream>

std::vector<std::vector<int>> readMatrix(std::ifstream &file)
{
	std::vector<std::vector<int>> result;

	int matrixHeight = 0;
	int matrixWidth = 0;

	file >> matrixHeight;
	file >> matrixWidth;

	result.resize(matrixHeight);

	for (size_t i = 0; i < matrixHeight; ++i)
	{
		result[i].resize(matrixWidth);

		for (size_t j = 0; j < matrixWidth; ++j)
		{
			int value = 0;
			file >> value;
			result[i][j] = value;
		}
	}

	return result;
}