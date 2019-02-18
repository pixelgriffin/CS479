#pragma once

#include "DataGenerator.h"
#include "Classifier.h"
#include "BayesClassifier.h"

class MinDistClassifier : public Classifier
{
public:
	MinDistClassifier(BayesClassifier* bc);
	~MinDistClassifier();

	void ClassifyP3();

protected:
	float CalculateDiscriminant(Vector2f point, Vector2f m, Matrix2f sig, float prob);

private:
	DataGenerator* data1;
	DataGenerator* data2;
};