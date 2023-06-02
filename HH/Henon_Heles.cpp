#include "Henon_Heles.h"
#include<iostream>

Henon_Heles::Henon_Heles(double ht)
{
	
	this->ht = ht;
	//RHS = rhs;
	sum = new double[n];
	y0 = new double[n];
	y1 = new double[n];
	dy = new double[n];
	istrue = false;
}
void Henon_Heles::SetInit(double* init)
{
	for (int i = 0;i < n;i++)
	{
		y0[i] = init[i];
	}
	istrue = true;
}
void Henon_Heles::RHS(double* y, double* dy)
{
	dy[0] = y[2];
	dy[1] = y[3];
	dy[2] = -y[0] - 2 * y[0] * y[1];
	dy[3] = y[1] * y[1] - y[1] - y[0] * y[0];
}
void Henon_Heles::DoOneStep()
{
	if (!istrue) return;
	RHS(y0, dy);
	for (int i = 0;i < n;i++)
	{
		sum[i] = dy[i];
		y1[i] = y0[i] + 0.5 * ht * dy[i];
	}
	RHS(y1, dy);
	for (int i = 0;i < n;i++)
	{
		sum[i] = sum[i] + 2 * dy[i];
		y1[i] = y0[i] + 0.5 * ht * dy[i];
	}
	RHS(y1, dy);
	for (int i = 0;i < n;i++)
	{
		sum[i] = sum[i] + 2 * dy[i];
		y1[i] = y0[i] + ht * dy[i];
	}
	RHS(y1, dy);
	for (int i = 0;i < n;i++)
	{
		sum[i] = sum[i] + dy[i];
		y1[i] = y0[i] + ht * sum[i] / 6.;
		y0[i] = y1[i];

	}




}