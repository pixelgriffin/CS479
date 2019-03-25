#pragma once

#include "ImageType.h"
#include "Eigen\Dense"
#include <vector>

using namespace Eigen;

struct MLESkinParameters
{
	Vector2f skinMu, nonSkinMu;
	Matrix2f skinSig, nonSkinSig;
};

class SkinClassifier
{
public:
	SkinClassifier();
	~SkinClassifier();

	void SolveP3A();
	void SolveP3B();

private:
	void SkinThresholdRGB(const char* fname, ImageType train, ImageType ref, MLESkinParameters params);
	void SkinThresholdYCBCR(const char* fname, ImageType train, ImageType ref, MLESkinParameters params);

	bool ThresholdCaseThree(Vector2f x, Vector2f m, Matrix2f sig, float thresh);

	MLESkinParameters GetEstimatedSkinParametersRGB(ImageType train, ImageType ref);
	MLESkinParameters GetEstimatedSkinParametersYCBCR(ImageType train, ImageType ref);

	Vector2f EstimateSampleMean(std::vector<Vector2f> points)
	{
		Vector2f sum(0, 0);

		for (std::vector<Vector2f>::iterator it = points.begin(); it != points.end(); ++it)
		{
			sum += (*it);
		}

		return sum / points.size();
	}

	Matrix2f EstimateSampleCovariance(std::vector<Vector2f> points, Vector2f sampleMean)
	{
		Matrix2f sum;
		sum << 0, 0,
			0, 0;

		for (std::vector<Vector2f>::iterator it = points.begin(); it != points.end(); ++it)
		{
			sum += (sampleMean - (*it)) * (sampleMean - (*it)).transpose();
		}

		return sum / points.size();
	}
};