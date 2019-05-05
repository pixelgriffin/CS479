#pragma once

#include <fstream>
#include <vector>
#include "Eigen\Dense"

using namespace Eigen;

class DataGenerator
{
public:
	virtual void GenerateNewData(int count, Vector2f m, Matrix2f sig) = 0;
	
	void SaveDataToFile(const char* fname)
	{
		if (!this->data.empty())
		{
			std::ofstream f(fname);

			if (f.is_open())
			{
				f << "x,y" << std::endl;

				for (std::vector<Vector2f>::iterator it = this->data.begin(); it != this->data.end(); ++it)
				{
					f << (*it)(0, 0) << "," << (*it)(1, 0) << std::endl;
				}

				f.close();
			}
		}
	}

public:
	std::vector<Vector2f> data;
};