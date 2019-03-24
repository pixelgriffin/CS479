#pragma once

#include "Eigen\Dense"

using namespace Eigen;

class ImageType
{
public:
	ImageType();
	ImageType(int n, int m, int q);
	~ImageType();

	void GetImageInfo(int& rows, int& cols, int& qs);
	void SetImageInfo(int rows, int cols, int qs);
	void SetPixelVal(int i, int j, Vector3i val);
	Vector3i GetPixelVal(int i, int j);

	void ReadImage(const char* fname);
	void WriteImage(const char* fname);

private:
	int n, m, q;//N: # rows, M: # columns
	Vector3i **pixelValue;//Stored in RGB
};

