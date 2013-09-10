//**********************
// lipiji.sdu@gmail.com
// 2013-06-25
//*********************/ 
#ifndef DEEP_H
#define DEEP_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

double sample_from_gaussian(double miu, double sigma);

class Conf
{
	public:
		string f_train_x;
		string f_train_y;
		string f_test_x;
		string f_test_y;

		int epoch;
		int batch_size;
		int *hidden_layer_size;
		int cd_k;
		double learning_rate;
		int n_layers;
		int n_labels; //num of classes

		Conf(string, string, int, int, int*, int, double, int, int);
		~Conf();

};

class Dataset
{
	public:
		int N;
		int n_f;
		//double **X;
		//double *Y;
		vector<vector<double> > X;
		vector<double> Y;
		int batch_index;
		Dataset(Conf);
		~Dataset();
};

class RBM
{
	public:
		int n_samples;
		int n_visible;
		int n_hidden;
		double **W;
		double *hbias;
		double *vbias;

		RBM(int, int, int,  double**, double*, double*);
		~RBM();
		void train(double*, double, int);
		void activate_hidden(double*, double*, int*, int, int);
		void activate_visible(int*, double*, int*, int, int);
};

class DBN
{
	public:
		int n_samples;
		int n_features;
		int n_layers;
		int n_labels;
		int *hidden_layer_size;
		RBM **rbm_layers;
		DBN(Dataset, Conf);
		~DBN();
		void pretrain(Dataset, Conf);
		void finetune(int*, int*, double, int);
		void predict(int*, double*);

};
#endif //DEEP_H



