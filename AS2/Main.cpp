#include <iostream>

#include "BayesClassifierCase1.h"
#include "BayesClassifierCase3.h"
#include "MinDistClassifier.h"
#include "ImageType.h"
#include "SkinClassifier.h"

using namespace std;

int main(int argc, char** argv)
{
	SkinClassifier skinner;

	cout << "Solving Part 3-A..." << endl;
	skinner.SolveP3A();

	cout << "Solving Part 3-B..." << endl;
	skinner.SolveP3B();

	return 0;
}