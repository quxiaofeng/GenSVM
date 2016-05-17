/**
 * @file gensvm_grid.h
 * @author Gertjan van den Burg
 * @date May, 2016
 * @brief Structs necessary for the grid search
 *
 * @details
 * The grid search for the optimal parameters is done through a queue.
 * This file contains struct definitions for this queue and a single
 * task in a queue, as well as a structure for the complete training
 * scheme. Function declarations are also included.
 *
 */

#ifndef GENSVM_GRID_H
#define GENSVM_GRID_H

#include "globals.h"

/**
 * @brief Structure for describing the entire grid search
 *
 * @param traintype 		type of training to use
 * @param kerneltype 		type of kernel to use throughout training
 * @param repeats 		number of repeats to be done after the grid
 * 				search to find the parameter set with the
 * 				most consistent high performance
 * @param folds 		number of folds in cross validation
 * @param Np 			size of the array of p values
 * @param Nl 			size of the array of lambda values
 * @param Nk 			size of the array of kappa values
 * @param Ne 			size of the array of epsilon values
 * @param Nw 			size of the array of weight_idx values
 * @param Ng 			size of the array of gamma values
 * @param Nc 			size of the array of coef values
 * @param Nd 			size of the array of degree values
 * @param *weight_idxs 		array of weight_idxs
 * @param *ps 			array of p values
 * @param *lambdas 		array of lambda values
 * @param *kappas 		array of kappa values
 * @param *epsilons 		array of epsilon values
 * @param *gammas 		array of gamma values
 * @param *coefs 		array of coef values
 * @param *degrees 		array of degree values
 * @param *train_data_file 	filename of train data file
 * @param *test_data_file 	filename of test data file
 *
 */
struct GenGrid {
	TrainType traintype;
	KernelType kerneltype;
	long repeats;
	long folds;
	long Np;
	long Nl;
	long Nk;
	long Ne;
	long Nw;
	long Ng;
	long Nc;
	long Nd;
	int *weight_idxs;
	double *ps;
	double *lambdas;
	double *kappas;
	double *epsilons;
	double *gammas;
	double *coefs;
	double *degrees;
	char *train_data_file;
	char *test_data_file;
};

// function declarations
struct GenGrid *gensvm_init_grid();
void gensvm_free_grid(struct GenGrid *grid);

#endif