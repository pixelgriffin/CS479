#pragma once

#include "DataGenerator.h"

class BoxMullerGenerator : public DataGenerator
{
public:
	BoxMullerGenerator();

	void GenerateNewData(int count, Vector2f m, Matrix2f sig);

private:
	float Ranf();
	float BoxMuller(float m, float s);
};