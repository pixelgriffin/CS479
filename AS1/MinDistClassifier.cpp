#include "MinDistClassifier.h"
#include "BoxMullerGenerator.h"

MinDistClassifier::MinDistClassifier(BayesClassifierCase3* bc)
{
	this->data1 = bc->GetDataGenerator1();
	this->data2 = bc->GetDataGenerator2();
}

MinDistClassifier::~MinDistClassifier()
{
}

float MinDistClassifier::CalculateDiscriminant(Vector2f point, Vector2f m, Matrix2f sig, float prob)
{
	//Min dist function
	Vector2f v = point - m;
	float val = (v.transpose() * v);
	return val * -1;
}

void MinDistClassifier::ClassifyP3()
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

	this->SaveMissclassifications("p3_misses.csv");
	this->misses1.clear();
	this->misses2.clear();

	//Save the bounds
	this->SaveErrorBounds("errorBounds3.csv", m1, sig1, m2, sig2);

	//No need to save test sample data here since it's just using P2's samples
}