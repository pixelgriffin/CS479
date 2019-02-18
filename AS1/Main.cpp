#include <iostream>

#include "BayesClassifier.h"
#include "MinDistClassifier.h"

int main(int argc, char** argv){
	BayesClassifier bc;

	std::cout << "working on P1" << std::endl;
	bc.ClassifyP1();
	std::cout << "working on P2" << std::endl;
	bc.ClassifyP2();

	MinDistClassifier md(&bc);//Defined here so we can just copy over the data sets from P2

	std::cout << "working on P3" << std::endl;
	md.ClassifyP3();

	std::cout << "Done";

	return 0;
}