#include "BayesClassifier.h"
#include "BoxMullerGenerator.h"

BayesClassifier::BayesClassifier()
{
	this->data1 = new BoxMullerGenerator();
	this->data2 = new BoxMullerGenerator();
}

BayesClassifier::~BayesClassifier()
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

float BayesClassifier::CalculateDiscriminant(Vector2f point, Vector2f m, Matrix2f sig, float prob)
{
	//Bayes discriminant function
	return  ((sig.inverse() * m).transpose() * point)(0) - (0.5 * m.transpose() * sig.inverse() * m) + (prob == 0.5 ? 0 : log(prob));
}

//Part one
void BayesClassifier::ClassifyP1()
{
	//In this case both data sets share the same sigma matrix
	Matrix2f sig;
	sig << 1, 0,
		   0, 1;

	//Different ms
	Vector2f m1(1, 1);
	Vector2f m2(4, 4);

	//Number of data points in each set
	int pointCount = 100000;

	//Generate two sets of data
	this->data1->GenerateNewData(pointCount, m1, sig);
	this->data2->GenerateNewData(pointCount, m2, sig);

	//Here we do P(w1)=P(w2)=0.5 -----------------------------------------------------------
	for (int i = 0; i < pointCount; i++)
	{
		float d1 = CalculateDiscriminant(this->data1->data[i], m1, sig, 0.5);
		float d2 = CalculateDiscriminant(this->data1->data[i], m2, sig, 0.5);

		if (d1 < d2)
		{
			//We consider this data point a part of the data2 set, and it is therefore misclassified
			this->misses1.push_back(this->data1->data[i]);
		}

		d1 = CalculateDiscriminant(this->data2->data[i], m1, sig, 0.5);
		d2 = CalculateDiscriminant(this->data2->data[i], m2, sig, 0.5);

		if (d1 > d2)
		{
			//We consider this data point a part of the data1 set, and it is therefore misclassified
			this->misses2.push_back(this->data2->data[i]);
		}
	}

	this->SaveMissclassifications("p1a_misses.csv");
	this->misses1.clear();
	this->misses2.clear();

	//Here we do P(w1)=0.2 and P(w2)=0.8 -----------------------------------------------------------
	for (int i = 0; i < pointCount; i++)
	{
		float d1 = CalculateDiscriminant(this->data1->data[i], m1, sig, 0.2);
		float d2 = CalculateDiscriminant(this->data1->data[i], m2, sig, 0.8);

		if (d1 < d2)
		{
			//We consider this data point a part of the data2 set, and it is therefore misclassified
			this->misses1.push_back(this->data1->data[i]);
		}

		d1 = CalculateDiscriminant(this->data2->data[i], m1, sig, 0.2);
		d2 = CalculateDiscriminant(this->data2->data[i], m2, sig, 0.8);

		if (d1 > d2)
		{
			//We consider this data point a part of the data1 set, and it is therefore misclassified
			this->misses2.push_back(this->data2->data[i]);
		}
	}

	this->SaveMissclassifications("p1b_misses.csv");
	this->misses1.clear();
	this->misses2.clear();

	//Save the test data
	this->data1->SaveDataToFile("data1_1.csv");
	this->data2->SaveDataToFile("data1_2.csv");
}

//Part two
void BayesClassifier::ClassifyP2()
{
	Matrix2f sig1;
	sig1 << 1, 0,
		0, 1;
	Matrix2f sig2;
	sig2 << 4, 0,
		0, 8;

	Vector2f m1(1, 1);
	Vector2f m2(4, 4);

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
}