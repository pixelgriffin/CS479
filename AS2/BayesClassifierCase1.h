#pragma once

#include "DataGenerator.h"
#include "Classifier.h"

class BayesClassifierCase1 : public Classifier
{
public:
	BayesClassifierCase1();
	~BayesClassifierCase1();

	void ClassifyP1();

	DataGenerator* GetDataGenerator1();
	DataGenerator* GetDataGenerator2();

protected:
	float CalculateDiscriminant(Vector2f point, Vector2f m, Matrix2f sig, float prob);

private:
	DataGenerator* data1;
	DataGenerator* data2;
};