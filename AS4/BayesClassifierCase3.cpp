#include <iostream>
#include <math.h>

#include "BayesClassifierCase3.h"
#include "BoxMullerGenerator.h"

BayesClassifierCase3::BayesClassifierCase3()
{
	this->data1 = new BoxMullerGenerator();
	this->data2 = new BoxMullerGenerator();
}

BayesClassifierCase3::~BayesClassifierCase3()
{
	if (this->data1 != NULL)
	{
		delete this->data1;
	}
	if (this->data2 != NULL)
	{
		delete this->data2;
	}
}

float BayesClassifierCase3::CalculateDiscriminant(VectorXf point, VectorXf m, MatrixXf sig, float prob)
{
	//Bayes discriminant function case 3
	return (point.transpose() * (-0.5 * sig.inverse()) * point) +
		((sig.inverse() * m).transpose() * point)(0) +
		(-0.5 * m.transpose() * sig.inverse() * m);
		//(-0.5 * log(sig.determinant()));
}

//Part two
void BayesClassifierCase3::ClassifyP2()
{
	for (int i = 1; i < 4; i++)
	{
		std::vector<VectorXf> maleFaces;
		std::vector<VectorXf> femaleFaces;

		std::string infname("genderdata/16_20/new-trPCA_0");
		infname = infname + std::to_string(i);
		infname = infname + ".txt";

		std::string tgfname("genderdata/16_20/TtrPCA_0");
		tgfname = tgfname + std::to_string(i);
		tgfname = tgfname + ".txt";

		ReadEigenFaceData(maleFaces, femaleFaces, infname, tgfname);

		std::cout << "mf size: " << maleFaces.size() << std::endl;
		std::cout << "ff size: " << femaleFaces.size() << std::endl;

		VectorXf mm = EstimateSampleMean(maleFaces);
		MatrixXf mc = EstimateSampleCovariance(maleFaces, mm);

		VectorXf fm = EstimateSampleMean(femaleFaces);
		MatrixXf fc = EstimateSampleCovariance(femaleFaces, fm);

		int maleCorrect = 0;
		int femaleCorrect = 0;

		//Here we do P(w1)=P(w2)=0.5 -----------------------------------------------------------
		std::cout << "classifying male faces" << std::endl;

		for (int i = 0; i < maleFaces.size(); i++)
		{
			float d1 = CalculateDiscriminant(maleFaces[i], mm, mc, 0.5);
			float d2 = CalculateDiscriminant(maleFaces[i], fm, fc, 0.5);

			//std::cout << "face: " << maleFaces[i] << std::endl;
			//std::cout << "d1: " << d1 << std::endl;
			//std::cout << "d2: " << d2 << std::endl;

			if (d1 >= d2)
			{
				maleCorrect++;
			}
		}

		std::cout << "classifying female faces" << std::endl;

		for (int i = 0; i < femaleFaces.size(); i++)
		{
			float d1 = CalculateDiscriminant(femaleFaces[i], fm, fc, 0.5);
			float d2 = CalculateDiscriminant(femaleFaces[i], mm, mc, 0.5);

			if (d1 >= d2)
			{
				femaleCorrect++;
			}
		}

		std::cout << "male correct: " << maleCorrect << std::endl;
		std::cout << "female correct: " << femaleCorrect << std::endl;

		std::string outfname("bayes_results_0");
		outfname = outfname + std::to_string(i);
		outfname = outfname + ".txt";
		std::ofstream f(outfname);

		if (f.is_open())
		{
			f << "male accuracy: " << (float)maleCorrect / (float)maleFaces.size() << std::endl;
			f << "female accuracy: " << (float)femaleCorrect / (float)femaleFaces.size() << std::endl;
			f << "total accuracy: " << (float)(maleCorrect + femaleCorrect) / (float)(maleFaces.size() + femaleFaces.size()) << std::endl;
			f.close();
		}
	}
}

DataGenerator* BayesClassifierCase3::GetDataGenerator1()
{
	return this->data1;
}

DataGenerator* BayesClassifierCase3::GetDataGenerator2()
{
	return this->data2;
}