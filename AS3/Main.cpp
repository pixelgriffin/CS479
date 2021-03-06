#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

/*
* Get File Name from a Path with or without extension
*/
std::string getFileName(std::string filePath, bool withExtension = true, char seperator = '\\')
{
	// Get last dot position
	std::size_t dotPos = filePath.rfind('.');
	std::size_t sepPos = filePath.rfind(seperator);

	if (sepPos != std::string::npos)
	{
		return filePath.substr(sepPos + 1, filePath.size() - (withExtension || dotPos != std::string::npos ? 1 : dotPos));
	}
	return "";
}

void load_flat_images(const String &dirname, vector<Mat> &img_list, vector<int> &label_list, bool showImages = false)
{
	/* Load PGM images
	and create a vector of flattened images
	*/
	vector<String> files;
	glob(dirname, files);
	for (size_t i = 0; i < files.size(); ++i)
	{
		Mat img = imread(files[i], IMREAD_UNCHANGED); // load the images
		if (img.empty())            // invalid image, skip it.
		{
			cout << files[i] << " is invalid!" << endl;
			continue;
		}
		if (showImages)
		{
			imshow("Faces", img);
			waitKey(0);
		}
		img = img.reshape(0, 1); //flatten images
		img_list.push_back(img);


		string fname = getFileName(files[i]);
		string label = fname.substr(0, fname.find("_"));
		int labelid = stoi(label);
		label_list.push_back(labelid);
	}
}


Mat average_face(vector<Mat> &img_list, bool showAvgFace = false)
{
	/* Calculates the mean face */

	cout << "Calculating the average face..." << endl;
	Mat mean;
	Mat mean_mean, stddev_mean;
	for (int col = 0; col < img_list[0].cols; ++col)
	{
		int sum = 0;
		for (int row = 0; row < img_list.size(); ++row)
		{
			sum += (int)img_list[row].at<uchar>(0, col);
		}
		mean.push_back((double)(sum / img_list.size()));
	}

	mean = mean.reshape(0, 20); // reshape to size of original image 48x60, 16x20 (3x smaller) for lowres
	mean.convertTo(mean, CV_8U);
	cout << "DONE" << endl;

	if (showAvgFace)
	{
		imshow("Average Face", mean);
		waitKey(0);
	}

	return mean;
}

static Mat prepareDataForPCA(const vector<Mat> &images)
{
	cout << "Prepare images for PCA ..." << endl;

	Mat data(static_cast<int>(images.size()), images[0].rows * images[0].cols, CV_8U);

	// Turn an image into one row vector in the data matrix
	for (unsigned int i = 0; i < images.size(); i++)
	{
		// Copy the long vector into one row of the dest
		images[i].copyTo(data.row(i));
	}

	cout << "DONE" << endl;
	return data;
}

int CountLabels(vector<int>& labels, int label)
{
	int c = 0;

	for (vector<int>::iterator it = labels.begin(); it != labels.end(); ++it)
	{
		if (*it == label)
			c++;
	}

	return c;
}

int main() {

	vector<Mat> images;
	vector<int> labels;
	load_flat_images(".\\Faces_FA_FB\\fa2_H\\", images, labels, false); //images as rows 

	cout << "Number of faces is: " << images.size() << endl; //number of images in the folder, rows
															 //cout << images[0].rows << endl;
	cout << "Number of pixels for each face is: " << images[0].cols << endl;
	//cout << (int)images[0].at<uchar>(0,0) << endl;
	//cout << images[0] << endl;


	Mat avg_face = average_face(images, false);
	Mat PCA_data = prepareDataForPCA(images);

	// Mat covar, mean_temp;
	// calcCovarMatrix(PCA_data, covar, mean_temp, CV_COVAR_ROWS | CV_COVAR_NORMAL, CV_32F);
	// cout << covar.rows << endl;
	// cout << covar.cols << endl;

	// cout << PCA_data.rows << endl;
	//cout << images[0] << endl;
	//cout << (int)PCA_data.at<uchar>(0,0) << endl;

	// //Calculate PCA of the data matrix
	// cout << "Calculating PCA ..." << endl;
	// PCA pca(PCA_data, Mat(), PCA::DATA_AS_ROW); 
	// cout << "DONE"<< endl;
	// cout << (int)PCA_data.at<uchar>(0,0) << endl;

	// // eigenvectors
	// Mat eigenVectors = pca.eigenvectors;
	// cout << eigenVectors.rows << endl;
	// cout << eigenVectors.cols << endl;

	// Mat eigenValues = pca.eigenvalues;
	// cout << eigenValues.rows << endl;
	// cout << eigenValues.cols << endl;

	// normalize(eigenVectors, eigenVectors, 0, 255, NORM_MINMAX); // normalize eigenvectors for display

	// // Display the eigenfaces corresponding to the 10 largest eigenvalues   
	// cout << "EigenFaces corresponding to the 10 highest eigenvalues ..." << endl;
	// for(int i = 0; i < 10; i++)
	// {
	//     //cout << eigenVectors.row(i) << endl;
	//     Mat eigenFace = eigenVectors.row(i).reshape(0, 60);
	//     eigenFace.convertTo(eigenFace, CV_8U);
	//     imshow("EigenFaces", eigenFace);
	//     waitKey(0);
	//     //Mat eigenFaces.push_back(eigenFace);

	// }
	// cout << "DONE"<< endl;

	// // Display the eigenfaces corresponding to the 10 smallest eigenvalues   
	// cout << "EigenFaces corresponding to the 10 smallest eigenvalues ..." << endl; 
	// for(int i = eigenVectors.rows - 1; i > eigenVectors.rows - 11; i--)
	// {

	//     Mat eigenFace = eigenVectors.row(i).reshape(0, 60);
	//     eigenFace.convertTo(eigenFace, CV_8U);
	//     imshow("EigenFaces", eigenFace);
	//     waitKey(0);
	//     //Mat eigenFaces.push_back(eigenFace);

	// }
	// cout << "DONE"<< endl;


	// Calculate PCA of the data matrix preserving 80% of the information
	cout << "Calculating PCA ..." << endl;
	PCA pca(PCA_data, Mat(), PCA::DATA_AS_ROW, 0.95);
	cout << "DONE" << endl;

	//Mat pca_mean = pca.mean;
	//cout << "PCA MEAN = "<< endl << " "  << pca_mean << endl << endl;
	// // // eigenvectors
	cout << "eigenVectors" << endl;
	Mat eigenVectors = pca.eigenvectors;
	cout << eigenVectors.rows << endl;
	cout << eigenVectors.cols << endl;

	cout << "eigenValues" << endl;
	Mat eigenValues = pca.eigenvalues;
	cout << eigenValues.rows << endl;
	cout << eigenValues.cols << endl;

	// Project training images and get the eigen-coefficients (retained variance = 80%)
	Mat compressed, coeffs_train;
	compressed.create(PCA_data.rows, 0.95, PCA_data.type());
	for (int i = 0; i < PCA_data.rows; i++)
	{
		Mat vec = PCA_data.row(i);
		Mat coeffs_temp = compressed.row(i);
		pca.project(vec, coeffs_temp);
		coeffs_train.push_back(coeffs_temp);
	}

	cout << coeffs_train.rows << endl;
	cout << coeffs_train.cols << endl;
	cout << "COEFFS_TRAIN = " << endl << " " << coeffs_train << endl << endl;




	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	// Load query images, project to the eigen-space 
	// and get the eigen-coefficients (retained variance = 80%)

	// Load query images
	vector<Mat> query_images;
	vector<int> query_labels;
	load_flat_images(".\\Faces_FA_FB\\fb_H\\", query_images, query_labels, false); //images as rows 
																  // Compute and flatten mean face
	Mat avg_query_face = average_face(query_images, false);
	avg_query_face = avg_query_face.reshape(0, 1); // flatten mean shape
												   // Convert query images to Mat structure
	Mat query_data = prepareDataForPCA(query_images);

	// Project query images and get the eigen-coefficients (retained variance = 80%)
	Mat compressed_query, coeffs_query;
	compressed_query.create(query_data.rows, 0.95, query_data.type());
	for (int i = 0; i < query_data.rows; i++)
	{
		Mat vec = query_data.row(i);
		Mat coeffs_temp = compressed_query.row(i);
		pca.project(vec, coeffs_temp);
		coeffs_query.push_back(coeffs_temp);
	}
	//cout << "COEFFS_query = " << endl;
	cout << coeffs_query.rows << endl;
	cout << coeffs_query.cols << endl;

	Mat coeffs;
	vconcat(coeffs_train, coeffs_query, coeffs);
	Mat covar, mean_temp;
	calcCovarMatrix(coeffs, covar, mean_temp, CV_COVAR_ROWS | CV_COVAR_NORMAL, CV_32F);
	cout << covar.rows << endl;
	cout << covar.cols << endl;

	// Compute inverted covariance matrix
	Mat icovar;
	invert(covar, icovar, DECOMP_SVD);

	//cout << "COEFFS_query = "<< endl << " "  << coeffs_query << endl << endl;

	std::cout << "Classifying faces" << std::endl;

	std::ofstream classificationData("classification.csv");

	classificationData << "threshold,FPs,TPs,FNs,TNs,FP-R,TP-R,FN-R,TN-R" << std::endl;

	//float maxNum = coeffs_train.rows * coeffs_query.rows;

	for (float n = 0.25; n < 0.5; n += 0.01)
	{
		float maxPositives = 0;
		float maxNegatives = 0;

		int fps = 0;
		int fns = 0;
		int tps = 0;
		int tns = 0;
		for (int i = 0; i < coeffs_query.rows; i++)
		{
			int labelCount = CountLabels(labels, query_labels[i]);
			maxPositives += labelCount;
			maxNegatives += coeffs_train.rows - labelCount;

			for (int j = 0; j < coeffs_train.rows; j++)
			{
				// Calculate Mahalanobis distance 
				double distance_temp = Mahalanobis(coeffs_train.row(j), coeffs_query.row(i), icovar);

				//cout << i << "->" << j << " " << distance_temp << std::endl;

				//thresh
				if (distance_temp < n)
				{
					if (query_labels[i] != labels[j])
					{
						fps++;
					}
					else
					{
						tps++;
					}
				}
				else
				{
					if (query_labels[i] == labels[j])
					{
						fns++;
					}
					else
					{
						tns++;
					}
				}
			}
		}

		classificationData << n << "," << fps << "," << tps << "," << fns << "," << tns << "," << ((float)fps / maxNegatives) << "," << ((float)tps / maxPositives) << "," << ((float)fns / maxNegatives) << "," << ((float)tns / maxPositives) << std::endl;
	}

	classificationData.close();

	/*double minVal, maxVal;
	Point minLoc, maxLoc;
	minMaxLoc(distance, &minVal, &maxVal, &minLoc, &maxLoc);
	cout << minVal << " " << minLoc;*/

	waitKey(0);

	return 0;
}