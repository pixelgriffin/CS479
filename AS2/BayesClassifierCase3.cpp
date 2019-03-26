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

float BayesClassifierCase3::CalculateDiscriminant(Vector2f point, Vector2f m, Matrix2f sig, float prob)
{
	//Bayes discriminant function case 3
	return (point.transpose() * (-0.5 * sig.inverse()) * point) + ((sig.inverse() * m).transpose() * point)(0) + (-0.5 * m.transpose() * sig.inverse() * m) + (-0.5 * log(sig.determinant())) + (prob == 0.5 ? 0 : log(prob));
}

//Part two
void BayesClassifierCase3::ClassifyP2()
{
	Matrix2f sig1;
	sig1 << 1, 0,
		0, 1;
	Matrix2f sig2;
	sig2 << 4, 0,
		0, 8;

	Vector2f m1(1, 1);
	Vector2f m2(4, 4);
	
	/*
	// parameters for assignment2 problem1
	Vector2f m1(0.998582, 1.00151);
	Vector2f m2(3.99429, 3.99695);

	Matrix2f sig1;
	sig1 << 1.00643, -0.00239859,
			-0.00239859, 1.00596;
	Matrix2f sig2;
	sig2 << 0.996028, 0.00524115,
			0.00524115, 0.994026;
	

	// parameters for assignment2 problem2
		Vector2f m1(0.997173, 1.00321);
		Vector2f m2(4.00088, 3.99697);

		Matrix2f sig1;
		sig1 << 1.00117, -0.000106357,
				-0.000106357, 0.99675;
		Matrix2f sig2;
		sig2 << 3.99783, 0.00549449,
				0.00549449, 7.97935;

	// insert generated data from previous assignment
	this->data1->ReadDataFromFile("question2_sample1.csv");
	this->data2->ReadDataFromFile("question2_sample2.csv");
	*/
	
	//Number of data points in each set
	int pointCount = 100000;

	//Generate two sets of data
	this->data1->GenerateNewData(pointCount, m1, sig1);
	this->data2->GenerateNewData(pointCount, m2, sig2);

	//Here we do P(w1)=P(w2)=0.5 -----------------------------------------------------------
	for (int i = 0; i < pointCount; i++)
	{
		float d1 = CalculateDiscriminant(this->data1->data[i], m1, sig1, 0.5);
		float d2 = CalculateDiscriminant(this->data1->data[i], m2, sig2, 0.5);

		if (d1 < d2)
		{
			//We consider this data point a part of the data2 set, and it is therefore misclassified
			this->misses1.push_back(this->data1->data[i]);
		}

		d1 = CalculateDiscriminant(this->data2->data[i], m1, sig1, 0.5);
		d2 = CalculateDiscriminant(this->data2->data[i], m2, sig2, 0.5);

		if (d1 > d2)
		{
			//We consider this data point a part of the data1 set, and it is therefore misclassified
			this->misses2.push_back(this->data2->data[i]);
		}
	}

	this->SaveMissclassifications("p2a_misses.csv");
	this->misses1.clear();
	this->misses2.clear();

	//Here we do P(w1)=0.2 and P(w2)=0.8 -----------------------------------------------------------
	for (int i = 0; i < pointCount; i++)
	{
		float d1 = CalculateDiscriminant(this->data1->data[i], m1, sig1, 0.2);
		float d2 = CalculateDiscriminant(this->data1->data[i], m2, sig2, 0.8);

		if (d1 < d2)
		{
			//We consider this data point a part of the data2 set, and it is therefore misclassified
			this->misses1.push_back(this->data1->data[i]);
		}

		d1 = CalculateDiscriminant(this->data2->data[i], m1, sig1, 0.2);
		d2 = CalculateDiscriminant(this->data2->data[i], m2, sig2, 0.8);

		if (d1 > d2)
		{
			//We consider this data point a part of the data1 set, and it is therefore misclassified
			this->misses2.push_back(this->data2->data[i]);
		}
	}

	this->SaveMissclassifications("p2b_misses.csv");
	this->misses1.clear();
	this->misses2.clear();

	//Save the test data
	this->data1->SaveDataToFile("data2_1.csv");
	this->data2->SaveDataToFile("data2_2.csv");

	//Save the bounds
	this->SaveErrorBounds("errorBounds2.csv", m1, sig1, m2, sig2);
}

DataGenerator* BayesClassifierCase3::GetDataGenerator1()
{
	return this->data1;
}

DataGenerator* BayesClassifierCase3::GetDataGenerator2()
{
	return this->data2;
}
