#include "BoxMullerGenerator.h"
#include <time.h>

BoxMullerGenerator::BoxMullerGenerator()
{
	srand(time(NULL));
}

void BoxMullerGenerator::GenerateNewData(int count, Vector2f m, Matrix2f sig)
{
	this->data.clear();

	for (int i = 0; i < count; i++)
	{
		this->data.push_back(
			Vector2f(BoxMuller(m(0, 0), sqrt(sig(0, 0))),
				BoxMuller(m(1, 0), sqrt(sig(1, 1))))
		);
	}
}

float BoxMullerGenerator::Ranf()
{
	return (rand()) / (float)RAND_MAX;
}

/* boxmuller           Implements the Polar form of the Box-Muller
Transformation

(c) Copyright 1994, Everett F. Carter Jr.
Permission is granted by the author to use
this software for any application provided this
copyright notice is preserved.

*/
float BoxMullerGenerator::BoxMuller(float m, float s)
{				        /* mean m, standard deviation s */
	float x1, x2, w, y1;
	static float y2;
	static int use_last = 0;

	if (use_last)		        /* use value from previous call */
	{
		y1 = y2;
		use_last = 0;
	}
	else
	{
		do {
			x1 = 2.0 * Ranf() - 1.0;
			x2 = 2.0 * Ranf() - 1.0;
			w = x1 * x1 + x2 * x2;
		} while (w >= 1.0);

		w = sqrt((-2.0 * log(w)) / w);
		y1 = x1 * w;
		y2 = x2 * w;
		use_last = 1;
	}

	return(m + y1 * s);
}