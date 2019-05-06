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
	float CalculateDiscriminant(VectorXf point, VectorXf m, MatrixXf sig, float prob);

private:
	DataGenerator * data1;
	DataGenerator* data2;
};