#pragma once

#include <vector>

class Classifier
{
protected:
	virtual float CalculateDiscriminant(Vector2f point, Vector2f m, Matrix2f sig, float prob) = 0;

	void SaveMissclassifications(const char* fname)
	{
		if (!this->misses1.empty() || !this->misses2.empty())
		{
			std::ofstream f(fname);

			if (f.is_open())
			{
				f << "x,y,SAMPLE1" << std::endl;

				for (std::vector<Vector2f>::iterator it = this->misses1.begin(); it != this->misses1.end(); ++it)
				{
					f << (*it)(0, 0) << "," << (*it)(1, 0) << std::endl;
				}

				f << "x,y,SAMPLE2" << std::endl;

				for (std::vector<Vector2f>::iterator it = this->misses2.begin(); it != this->misses2.end(); ++it)
				{
					f << (*it)(0, 0) << "," << (*it)(1, 0) << std::endl;
				}

				f.close();
			}
		}
	}

protected:
	std::vector<Vector2f> misses1, misses2;
};