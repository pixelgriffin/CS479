#pragma once

#include <vector>
#include <fstream>
#include <sstream>

class Classifier
{
protected:
	virtual float CalculateDiscriminant(VectorXf point, VectorXf m, MatrixXf sig, float prob) = 0;

	void ReadEigenFaceData(std::vector<VectorXf>& male, std::vector<VectorXf>& female, std::string fname, std::string targetname)
	{
		std::ifstream faces(fname);
		std::ifstream target(targetname);

		std::string ln;
		getline(target, ln);

		std::istringstream tstream(ln);

		while (getline(faces, ln))
		{
			std::istringstream iss(ln);

			std::vector<float> vals;

			float val;
			while (iss >> val)
			{
				vals.push_back(val);
			}

			VectorXf f(vals.size());

			for (int i = 0; i < vals.size(); i++)
			{
				f.row(i) << vals[i];
			}

			int classification = 0;
			tstream >> classification;

			if (classification == 1)
				male.push_back(f);
			else
				female.push_back(f);
		}
	}

	VectorXf EstimateSampleMean(std::vector<VectorXf> points)
	{
		VectorXf sum = VectorXf::Zero(points[0].rows());

		for (std::vector<VectorXf>::iterator it = points.begin(); it != points.end(); ++it)
		{
			sum += (*it);
		}

		return sum / points.size();
	}

	MatrixXf EstimateSampleCovariance(std::vector<VectorXf> points, VectorXf sampleMean)
	{
		MatrixXf sum = MatrixXf::Zero(points[0].rows(), points[0].rows());

		for (std::vector<VectorXf>::iterator it = points.begin(); it != points.end(); ++it)
		{
			sum += (sampleMean - (*it)) * ((sampleMean - (*it)).transpose());
		}

		return sum / points.size();
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
	std::vector<VectorXf> misses1, misses2;
};