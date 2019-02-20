#include <iostream>

#include "BayesClassifierCase1.h"
#include "BayesClassifierCase3.h"
#include "MinDistClassifier.h"

int main(int argc, char** argv)
{
	BayesClassifierCase1 bc1;
	BayesClassifierCase3 bc3;

	std::cout << "working on P1" << std::endl;
	bc1.ClassifyP1();
	std::cout << "working on P2" << std::endl;
	bc3.ClassifyP2();

	MinDistClassifier md(&bc3);//Defined here so we can just copy over the data sets from P2

	std::cout << "working on P3" << std::endl;
	md.ClassifyP3();

	std::cout << "Done";

	return 0;
}