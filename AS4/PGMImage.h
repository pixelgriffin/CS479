#pragma once

class PGMImage
{
public:
	PGMImage();
	PGMImage(int n, int m, int q);
	~PGMImage();

	int GetN();
	int GetM();
	int GetQ();
	void SetImageInfo(int rows, int cols, int qs);
	void SetPixelVal(int i, int j, int val);
	int GetPixelVal(int i, int j);

	void ReadImage(const char* fname);
	void WriteImage(const char* fname);

private:
	int n, m, q;//N: # rows, M: # columns
	int **pixelValue;//Stored in RGB
};

