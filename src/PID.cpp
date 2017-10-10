#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	
	p_error = 0;
	i_error = 0;
	d_error = 0;

}

void PID::UpdateError(double cte) {

	// CTE is cross-track error
	
	d_error = cte - p_error;	// d_error = cte - prior_cte. But p_error is equal to the prior CTE.
	p_error = cte;				// Proportional error is def'n of CTE
	i_error = cte + i_error;	// Accumulated errors. If hovering around center, will be ~0

}

double PID::TotalError() {

	// u(t) = Kp*e(t) + Ki * {I0_t e(Tau)dTau} + Kd*d(e(t))/dt
	return Kp*p_error + Ki*i_error + Kd*d_error;

}

