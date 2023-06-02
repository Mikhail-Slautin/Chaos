#pragma once
class Henon_Heles
{
private:
	int n=4;
	
public:
	Henon_Heles(double ht);
	void SetInit(double* init);
	void DoOneStep();
	//void(*RHS)(double* y, double* dy);void(*rhs)(double*, double*)
	void RHS(double* y, double* dy);
	bool istrue;
	double* sum;
	double* y0;
	double* y1;
	double* dy;
	double ht;
	
};

