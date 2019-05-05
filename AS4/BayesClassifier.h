#pragma once

#include "DataGenerator.h"
#include "Classifier.h"

class BayesClassifier : public Classifier
{
public:
	BayesClassifier();
	~BayesClassifier();

	void ClassifyP1();
	void ClassifyP2();

	DataGenerator* getDataGenerator1();
	DataGenerator* getDataGenerator2();

protected:
	float CalculateDiscriminant(Vector2f point, Vector2f m, Matrix2f sig, float prob);

private:
	DataGenerator* data1;
	DataGenerator* data2;
};