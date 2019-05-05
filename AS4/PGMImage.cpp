#include "PGMImage.h"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "Eigen\Dense"

using namespace Eigen;
using namespace std;

PGMImage::PGMImage()
{
	n = 0;
	m = 0;
	q = 0;

	pixelValue = NULL;
}

PGMImage::PGMImage(int _n, int _m, int _q)
{
	n = _n;
	m = _m;
	q = _q;

	//Initialize image matrix with 0s
	pixelValue = new int*[n];

	for (int i = 0; i < n; i++)
	{
		pixelValue[i] = new int[m];

		for (int j = 0; j < m; j++)
		{
			pixelValue[i][j] = 0;
		}
	}
}

PGMImage::~PGMImage()
{
}

int PGMImage::GetN()
{
	return this->n;
}

int PGMImage::GetM()
{
	return this->m;
}

int PGMImage::GetQ()
{
	return this->q;
}

void PGMImage::SetImageInfo(int rows, int cols, int qs)
{
	this->n = rows;
	this->m = cols;
	this->q = qs;
}

void PGMImage::SetPixelVal(int i, int j, int val)
{
	pixelValue[i][j] = val;
}

int PGMImage::GetPixelVal(int i, int j)
{
	return pixelValue[i][j];
}

void PGMImage::ReadImage(const char* fname)
{
	int i, j;
	int N, M, Q;
	unsigned char *charImage;
	char header[100], *ptr;
	ifstream ifp;

	ifp.open(fname, ios::in | ios::binary);

	if (!ifp) {
		cout << "Can't read image: " << fname << endl;
		exit(1);
	}

	// read header

	ifp.getline(header, 100, '\n');

	if ((header[0] != 80) ||    /* 'P' */
		(header[1] != 53)) {   /* '5' */
		cout << "Image " << fname << " is not PGM " << endl;
		exit(1);
	}

	while (header[0] == '#')
		ifp.getline(header, 100, '\n');

	M = strtol(header, &ptr, 0);
	N = atoi(ptr);
	Q = strtol(header, &ptr, 0);

	charImage = (unsigned char *) new unsigned char[M*N];

	ifp.read(reinterpret_cast<char *>(charImage), (M*N) * sizeof(unsigned char));

	if (ifp.fail()) {
		cout << "Image " << fname << " has wrong size" << endl;
		exit(1);
	}

	ifp.close();

	//Read in new matrix size, delete old matrix if necessary
	if (pixelValue != NULL)
	{
		for (int i = 0; i < n; i++)
		{
			delete[] pixelValue[i];
		}

		delete[] pixelValue;
	}
	pixelValue = NULL;

	SetImageInfo(N, M, Q);

	//Initialize image matrix with 0s
	pixelValue = new int*[n];

	for (int i = 0; i < n; i++)
	{
		pixelValue[i] = new int[m];

		for (int j = 0; j < m; j++)
		{
			pixelValue[i][j] = 0;
		}
	}

	int val;

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j ++) {
			val = (int)charImage[i * M + j];
			SetPixelVal(i, j, val);
		}

	delete[] charImage;
}

void PGMImage::WriteImage(const char* fname)
{
	int i, j;
	int N, M, Q;
	unsigned char *charImage;
	ofstream ofp;

	N = GetN();
	M = GetM();
	Q = GetQ();

	charImage = (unsigned char *) new unsigned char[M*N];

	int val;

	for (i = 0; i<N; i++)
		for (j = 0; j<3 * M; j ++) {
			val = GetPixelVal(i, j);
			charImage[i * M + j] = (unsigned char)val;
		}

	ofp.open(fname, ios::out | ios::binary);

	if (!ofp) {
		cout << "Can't open file: " << fname << endl;
		exit(1);
	}

	ofp << "P5" << endl;
	ofp << M << " " << N << endl;
	ofp << Q << endl;

	ofp.write(reinterpret_cast<char *>(charImage), (M*N) * sizeof(unsigned char));

	if (ofp.fail()) {
		cout << "Can't write image " << fname << endl;
		exit(0);
	}

	ofp.close();

	delete[] charImage;
}