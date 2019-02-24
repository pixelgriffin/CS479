#include "BayesClassifierCase1.h"
#include "BoxMullerGenerator.h"

BayesClassifierCase1::BayesClassifierCase1()
{
	this->data1 = new BoxMullerGenerator();
	this->data2 = new BoxMullerGenerator();
}

BayesClassifierCase1::~BayesClassifierCase1()
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

float BayesClassifierCase1::CalculateDiscriminant(Vector2f point, Vector2f m, Matrix2f sig, float prob)
{
	//Bayes discriminant function case 1
	float sigma = sig(0, 0);//Sample sigma once for speed
	float mtrans = (m.transpose() * m);
	return ((((1.0 / sigma) * m).transpose() * point) - (1.0 / (2 * sigma)) * mtrans) + (prob == 0.5 ? 0 : log(prob));
}

//Part one
void BayesClassifierCase1::ClassifyP1()
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

	//Save the bounds
	this->SaveErrorBounds("errorBounds1.csv", m1, sig, m2, sig);
}

DataGenerator* BayesClassifierCase1::GetDataGenerator1()
{
	return this->data1;
}

DataGenerator* BayesClassifierCase1::GetDataGenerator2()
{
	return this->data2;
}