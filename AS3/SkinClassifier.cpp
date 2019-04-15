#include "SkinClassifier.h"
#include <iostream>
#include <fstream>

using namespace std;


SkinClassifier::SkinClassifier()
{
}


SkinClassifier::~SkinClassifier()
{
}


void SkinClassifier::SolveP3A()
{
	PGMImage ref1;
	ref1.ReadImage("Data/ref1.ppm");
	PGMImage train1;
	train1.ReadImage("Data/Training_1.ppm");

	//Calculate estimated parameters given the first set of images
	MLESkinParameters params = GetEstimatedSkinParametersRGB(train1, ref1);

	//Thresholding on second set of images
	PGMImage ref3;
	ref3.ReadImage("Data/ref3.ppm");
	PGMImage train3;
	train3.ReadImage("Data/Training_3.ppm");

	SkinThresholdRGB("img3_RGB_results.csv", train3, ref3, params);

	//Thresholding on third set of images
	PGMImage ref6;
	ref6.ReadImage("Data/ref6.ppm");
	PGMImage train6;
	train6.ReadImage("Data/Training_6.ppm");

	SkinThresholdRGB("img6_RGB_results.csv", train6, ref6, params);
}

void SkinClassifier::SolveP3B()
{
	ImageType ref1;
	ref1.ReadImage("Data/ref1.ppm");
	ImageType train1;
	train1.ReadImage("Data/Training_1.ppm");

	//Calculate estimated parameters given the first set of images
	MLESkinParameters params = GetEstimatedSkinParametersYCBCR(train1, ref1);

	//Thresholding on second set of images
	ImageType ref3;
	ref3.ReadImage("Data/ref3.ppm");
	ImageType train3;
	train3.ReadImage("Data/Training_3.ppm");

	SkinThresholdYCBCR("img3_YCBCR_results.csv", train3, ref3, params);

	//Thresholding on third set of images
	ImageType ref6;
	ref6.ReadImage("Data/ref6.ppm");
	ImageType train6;
	train6.ReadImage("Data/Training_6.ppm");

	SkinThresholdYCBCR("img6_YCBCR_results.csv", train6, ref6, params);
}

void SkinClassifier::SkinThresholdYCBCR(const char* fname, ImageType train, ImageType ref, MLESkinParameters params)
{
	int n = train.GetN();
	int m = train.GetM();
	int q = train.GetQ();

	ofstream outFile(fname);

	if (outFile.is_open())
	{
		outFile << "Threshold,Skin False Positives,Skin False Negatives,Skin Classifications,Non-Skin Classifications" << endl;

		for (float t = 0; t <= 0.1; t += 0.1)
		{
			int skinFalsePositives = 0;
			int skinFalseNegatives = 0;
			int skinCount = 0;
			int nonSkinCount = 0;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					Vector3i trainPix = train.GetPixelVal(i, j);
					Vector2f calc;
					calc << (-0.169 * (float)trainPix(0)) + (-0.169 * (float)trainPix(1)) + (0.5 * (float)trainPix(2)), //Cb
							(0.5 * (float)trainPix(0)) + (-0.419 * (float)trainPix(1)) + (-0.081 * (float)trainPix(2)); //Cr

					Vector3i refPix = ref.GetPixelVal(i, j);
					float refSum = refPix(0) + refPix(1) + refPix(2);

					bool skinClass = ThresholdCaseThree(calc, params.skinMu, params.skinSig, t);

					if (skinClass)
						skinCount++;
					else
						nonSkinCount++;

					if (refSum > 0)//i.e. not black (skin)
					{
						if (!skinClass)
							skinFalsePositives++;
					}
					else//Black (not skin)
					{
						if (skinClass)
							skinFalseNegatives++;
					}
				}
			}

			outFile << t << "," << skinFalsePositives << "," << skinFalseNegatives << "," << skinCount << "," << nonSkinCount << endl;
		}

		outFile.close();
	}
}

void SkinClassifier::SkinThresholdRGB(const char* fname, ImageType train, ImageType ref, MLESkinParameters params)
{
	int n = train.GetN();
	int m = train.GetM();
	int q = train.GetQ();

	ofstream outFile(fname);

	if (outFile.is_open())
	{
		outFile << "Threshold,Skin False Positives,Skin False Negatives,Skin Classifications,Non-Skin Classifications" << endl;

		for (float t = 0; t <= 0.1; t += 0.1)
		{
			int skinFalsePositives = 0;
			int skinFalseNegatives = 0;
			int skinCount = 0;
			int nonSkinCount = 0;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					Vector3i trainPix = train.GetPixelVal(i, j);
					Vector2f calc;
					calc << 0, 0;

					float trainSum = trainPix(0) + trainPix(1) + trainPix(2);

					if (trainSum > 0)
						calc << (trainPix(0) / trainSum), (trainPix(1) / trainSum);

					Vector3i refPix = ref.GetPixelVal(i, j);
					float refSum = refPix(0) + refPix(1) + refPix(2);

					bool skinClass = ThresholdCaseThree(calc, params.skinMu, params.skinSig, t);

					if (skinClass)
						skinCount++;
					else
						nonSkinCount++;

					if (refSum > 0)//i.e. not black (skin)
					{
						if (!skinClass)
							skinFalsePositives++;
					}
					else//Black (not skin)
					{
						if (skinClass)
							skinFalseNegatives++;
					}
				}
			}

			outFile << t << "," << skinFalsePositives << "," << skinFalseNegatives << "," << skinCount << "," << nonSkinCount << endl;
		}

		outFile.close();
	}
}

bool SkinClassifier::ThresholdCaseThree(Vector2f x, Vector2f m, Matrix2f sig, float thresh)
{
	return (-0.5 * (x - m).transpose() * sig.inverse() * (x - m)) > thresh;
}

MLESkinParameters SkinClassifier::GetEstimatedSkinParametersYCBCR(ImageType train, ImageType ref)
{
	MLESkinParameters params;

	int n = train.GetN();
	int m = train.GetM();
	int q = train.GetQ();

	std::vector<Vector2f> skinSamples;
	std::vector<Vector2f> nonSkinSamples;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Vector3i trainPix = train.GetPixelVal(i, j);

			Vector2f calc;

			calc << (-0.169 * (float)trainPix(0)) + (-0.169 * (float)trainPix(1)) + (0.5 * (float)trainPix(2)), //Cb
					(0.5 * (float)trainPix(0)) + (-0.419 * (float)trainPix(1)) + (-0.081 * (float)trainPix(2)); //Cr

			Vector3i refPix = ref.GetPixelVal(i, j);

			float refSum = refPix(0) + refPix(1) + refPix(2);

			if (refSum > 0)//i.e. not black (white/red)
			{
				skinSamples.push_back(calc);
			}
			else//Black (not skin)
			{
				nonSkinSamples.push_back(calc);
			}
		}
	}

	params.nonSkinMu = EstimateSampleMean(nonSkinSamples);
	params.nonSkinSig = EstimateSampleCovariance(nonSkinSamples, params.nonSkinMu);

	params.skinMu = EstimateSampleMean(skinSamples);
	params.skinSig = EstimateSampleCovariance(skinSamples, params.skinMu);

	return params;
}

MLESkinParameters SkinClassifier::GetEstimatedSkinParametersRGB(ImageType train, ImageType ref)
{
	MLESkinParameters params;

	int n = train.GetN();
	int m = train.GetM();
	int q = train.GetQ();

	std::vector<Vector2f> skinSamples;
	std::vector<Vector2f> nonSkinSamples;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Vector3i trainPix = train.GetPixelVal(i, j);

			Vector2f calc;
			calc << 0, 0;

			float sum = trainPix(0) + trainPix(1) + trainPix(2);

			if (sum > 0)
				calc << (trainPix(0) / sum), (trainPix(1) / sum);

			Vector3i refPix = ref.GetPixelVal(i, j);

			float refSum = refPix(0) + refPix(1) + refPix(2);

			if (refSum > 0)//i.e. not black (white/red)
			{
				skinSamples.push_back(calc);
			}
			else//Black (not skin)
			{
				nonSkinSamples.push_back(calc);
			}
		}
	}

	params.nonSkinMu = EstimateSampleMean(nonSkinSamples);
	params.nonSkinSig = EstimateSampleCovariance(nonSkinSamples, params.nonSkinMu);

	params.skinMu = EstimateSampleMean(skinSamples);
	params.skinSig = EstimateSampleCovariance(skinSamples, params.skinMu);

	return params;
}