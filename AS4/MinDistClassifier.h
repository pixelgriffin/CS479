#pragma once

#include "DataGenerator.h"
#include "Classifier.h"
#include "BayesClassifierCase3.h"

class MinDistClassifier : public Classifier
{
public:
	MinDistClassifier(BayesClassifierCase3* bc);
	~MinDistClassifier();

	void ClassifyP3();

protected:
	float CalculateDiscriminant(Vector2f point, Vector2f m, Matrix2f sig, float prob);

private:
	DataGenerator* data1;
	DataGenerator* data2;
};