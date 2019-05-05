#pragma once

#include "DataGenerator.h"
#include "Classifier.h"

class BayesClassifierCase3 : public Classifier
{
public:
	BayesClassifierCase3();
	~BayesClassifierCase3();

	void ClassifyP2();

	DataGenerator* GetDataGenerator1();
	DataGenerator* GetDataGenerator2();

protected:
	float CalculateDiscriminant(Vector2f point, Vector2f m, Matrix2f sig, float prob);

private:
	DataGenerator * data1;
	DataGenerator* data2;
};