/**
 * \file        SVDasym.h
 * \author      Zongxiao He (zongxiah@bcm.edu)
 * \copyright   Copyright 2013, Leal Group
 * \date        2013-11-20
 *
 * \brief
 *
 *
 */


#ifndef SVDASYM_H
#define SVDASYM_H

#include "utilities.h"
#include "baseline.h"
#include "basic.h"

class SVDasym: public MovieLensModel{

public:
	SVDasym(std::string projid, int nfactor, double g0, double l0, int bi, double g1, double g2, double l6, double l7, double a, double sr, int mi, bool debug);
	void train();
	void predict();
	~SVDasym(){}

private:
	// training paramter
	int K_NUM;
	double _gamma0, _lambda0; // from baseline model
	int _base_iter;
	double _gamma1, _gamma2;
	double _lambda6, _lambda7;
	double _slow_rate, _alpha;
	int _max_iter;

	// model parameter
	double __gamma1, __gamma2;
	vectorF bu_, bi_;  // the user and movie bias
	vectorF buBase_, biBase_;
    vectorUI buNum_, biNum_;       // num of ratings given by user, num of ratings given to item
    
	vector2F pall_, q_, y_, x_;   // user character Matrix
	//  item character Matrix
    //implicit weight y
    //user complete character (pu + sum y_i)

    double mean_;                         // mean of all ratings

	int probe_iter_;
	double rmse_, prmse_;


	float predict_rate(int user, int item);

	void init_base_model();
	void init_para();
	double dot_product(vectorF& p, vectorF& q, int dim);
	void log_parameter();
};

#endif /* SVDASYM_H */
