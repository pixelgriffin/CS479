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

	void ReadDataFromFile(const char* fname)
	{
		   this->data.clear();

		   std::vector<std::vector<float>> M;

		   std::ifstream f(fname);
		   std::string line;
		   getline(f, line);
		   while (getline(f, line))
		   {
			  std::stringstream ss(line);
			  std::vector<float> row;
			  std::string values;
		      while (getline(ss, values, ','))
		      {
		         row.vector::push_back(stof(values));
		      }
		      if (row.size() > 0) M.vector::push_back(row);
		   }

		   std::cout << M.size() <<std::endl;

		   for (unsigned int i = 0; i < M.size(); i++)
		   	{

			   this->data.push_back(
		   			Vector2f(M[i][0],M[i][1])
			   );

		   	}
	}
	
public:
	std::vector<Vector2f> data;
};
