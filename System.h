#pragma once
class System
{
public:
	Species *species[nS];
	double *x[nS];
	double dx[nS];
	double *dependence[nS][nS];
	double control[1];
	


	System();
	~System();

	double f(double t, double x[nS], int id);
	int rk4(double t, double h);
	int timestep(double t, double h);


};

