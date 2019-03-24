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
				f << "x,y,MISS-SAMPLE1" << std::endl;

				for (std::vector<Vector2f>::iterator it = this->misses1.begin(); it != this->misses1.end(); ++it)
				{
					f << (*it)(0, 0) << "," << (*it)(1, 0) << std::endl;
				}

				f << "x,y,MISS-SAMPLE2" << std::endl;

				for (std::vector<Vector2f>::iterator it = this->misses2.begin(); it != this->misses2.end(); ++it)
				{
					f << (*it)(0, 0) << "," << (*it)(1, 0) << std::endl;
				}

				f.close();
			}
		}
	}

	void SaveErrorBounds(const char* fname, Vector2f m1, Matrix2f sig1, Vector2f m2, Matrix2f sig2)
	{
		std::ofstream f(fname);

		if (f.is_open())
		{
			ChernoffData data = GetChernoffBound(m1, sig1, m2, sig2);

			f << "Bhattacharyya-value,Chernoff-beta,Chernoff-value" << std::endl;
			f << GetBhattacharyyaBound(m1, sig1, m2, sig2) << "," << data.beta << "," << data.value << std::endl;

			f.close();
		}
	}

	//KB from the slides
	float KB(float b, Vector2f m1, Matrix2f sig1, Vector2f m2, Matrix2f sig2)
	{
		return exp(-1.0 * ((((b * (1 - b)) / 2.0) * ((m1 - m2).transpose() * ((1 - b) * sig1 + b * sig2).inverse() * (m1 - m2)))(0) + (0.5 * log(((1 - b) * sig1 + b * sig2).determinant() / (pow(sig1.determinant(), 1 - b) * pow(sig2.determinant(), b))))));
	}

	struct ChernoffData
	{
		ChernoffData(float val, float b)
		{
			value = val;
			beta = b;
		}

		float value;
		float beta;
	};

	ChernoffData GetChernoffBound(Vector2f m1, Matrix2f sig1, Vector2f m2, Matrix2f sig2)
	{
		float smallest = 1;
		float beta = 0;

		//Find smallest error value given some beta i
		for (float i = 0; i <= 1; i += 0.001)
		{
			float val = KB(i, m1, sig1, m2, sig2);

			if (val < smallest)
			{
				smallest = val;
				beta = i;
			}
		}

		return ChernoffData(smallest, beta);
	}

	//Bhattacharyya is just 0.5 input into KB
	float GetBhattacharyyaBound(Vector2f m1, Matrix2f sig1, Vector2f m2, Matrix2f sig2)
	{
		return KB(0.5, m1, sig1, m2, sig2);
	}

protected:
	std::vector<Vector2f> misses1, misses2;
};