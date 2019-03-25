#include "ImageType.h"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "Eigen\Dense"

using namespace Eigen;
using namespace std;

ImageType::ImageType()
{
	n = 0;
	m = 0;
	q = 0;

	pixelValue = NULL;
}

ImageType::ImageType(int _n, int _m, int _q)
{
	n = _n;
	m = _m;
	q = _q;

	//Initialize image matrix with 0s
	pixelValue = new Vector3i*[n];

	for (int i = 0; i < n; i++)
	{
		pixelValue[i] = new Vector3i[m];

		for (int j = 0; j < m; j++)
		{
			pixelValue[i][j] = Vector3i(0, 0, 0);
		}
	}
}

ImageType::~ImageType()
{
}

int ImageType::GetN()
{
	return this->n;
}

int ImageType::GetM()
{
	return this->m;
}

int ImageType::GetQ()
{
	return this->q;
}

void ImageType::SetImageInfo(int rows, int cols, int qs)
{
	this->n = rows;
	this->m = cols;
	this->q = qs;
}

void ImageType::SetPixelVal(int i, int j, Vector3i val)
{
	pixelValue[i][j] = val;
}

Vector3i ImageType::GetPixelVal(int i, int j)
{
	return pixelValue[i][j];
}

void ImageType::ReadImage(const char* fname)
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
		(header[1] != 54)) {   /* '6' */
		cout << "Image " << fname << " is not PPM" << endl;
		exit(1);
	}

	ifp.getline(header, 100, '\n');
	while (header[0] == '#')
		ifp.getline(header, 100, '\n');

	M = strtol(header, &ptr, 0);
	N = atoi(ptr);

	ifp.getline(header, 100, '\n');
	Q = strtol(header, &ptr, 0);

	charImage = (unsigned char *) new unsigned char[3 * M*N];

	ifp.read(reinterpret_cast<char *>(charImage), (3 * M*N) * sizeof(unsigned char));

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

	cout << "applying image info: " << N << ", " << M << ", " << Q << endl;
	SetImageInfo(N, M, Q);
	cout << "image info: " << this->n << ", " << this->m << ", " << this->q << endl;

	//Initialize image matrix with 0s
	pixelValue = new Vector3i*[n];

	for (int i = 0; i < n; i++)
	{
		pixelValue[i] = new Vector3i[m];

		for (int j = 0; j < m; j++)
		{
			pixelValue[i][j] = Vector3i(0, 0, 0);
		}
	}

	//Convert to RGB

	Vector3i val;

	for (i = 0; i < N; i++)
		for (j = 0; j < 3 * M; j += 3) {
			val(0) = (int)charImage[i * 3 * M + j];
			val(1) = (int)charImage[i * 3 * M + j + 1];
			val(2) = (int)charImage[i * 3 * M + j + 2];
			SetPixelVal(i, j / 3, val);
		}

	delete[] charImage;
}

void ImageType::WriteImage(const char* fname)
{
	int i, j;
	int N, M, Q;
	unsigned char *charImage;
	ofstream ofp;

	N = GetN();
	M = GetM();
	Q = GetQ();

	charImage = (unsigned char *) new unsigned char[3 * M*N];

	Vector3i val;

	for (i = 0; i<N; i++)
		for (j = 0; j<3 * M; j += 3) {
			val = GetPixelVal(i, j / 3);
			charImage[i * 3 * M + j] = (unsigned char)val(0);
			charImage[i * 3 * M + j + 1] = (unsigned char)val(1);
			charImage[i * 3 * M + j + 2] = (unsigned char)val(2);
		}

	ofp.open(fname, ios::out | ios::binary);

	if (!ofp) {
		cout << "Can't open file: " << fname << endl;
		exit(1);
	}

	ofp << "P6" << endl;
	ofp << M << " " << N << endl;
	ofp << Q << endl;

	ofp.write(reinterpret_cast<char *>(charImage), (3 * M*N) * sizeof(unsigned char));

	if (ofp.fail()) {
		cout << "Can't write image " << fname << endl;
		exit(0);
	}

	ofp.close();

	delete[] charImage;
}