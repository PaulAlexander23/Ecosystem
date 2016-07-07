#include "stdafx.h"
#include "System.h"


System::System()
{
	double tmp[nS];


	//tmp[0] = 0;
	//tmp[1] = 0;
	//tmp[2] = -0.1;


	//species[0] = new Species(0, 5.0f, 0.0f, tmp, 0.05f, true, 0.0f);
	//species[1] = new Species(1, 5.0f, 0.0f, tmp, 0.05f, true, 0.0f);

	//tmp[0] = 0.1;
	//tmp[1] = 0.1;
	//tmp[2] = 0;

	//species[2] = new Species(2, 1.0f, -5.0f, tmp, false, 0.0f, 0.0f);

	tmp[0] = 0;
	tmp[1] = 0;
	tmp[2] = 0;


	species[0] = new Species(0, 5.0, -0.001, tmp, 0.00, true, 0.0);
	species[1] = new Species(1, 5.0, -0.1, tmp, 0.00, true, 0.0);
	species[2] = new Species(2, 1.0, 0.0, tmp, 0.00,false, 0.0);


	for (int i = 0; i < nS; i++)
	{
		x[i] = &(species[i]->pop);
		for (int j = 0; j < nS; j++)
		{
			dependence[i][j] = &(species[i]->dpgrowth[j]);
		}
	}

	control[0] = 100;
}


System::~System()
{
}


 double	System::f(double t, double x[nS],int id)
{
	double temp;
	double temp2 = 0;

	temp = species[id]->indpgrowth*x[id];

	for (int i = 0; i < nS; i++)
	{
		temp += species[id]->dpgrowth[i] * x[id] * x[i];
	}
	if (species[id]->ctrlgp != 0)
	{

		for (int i = 0; i < nS; i++)
		{
			if (species[i]->ctrlgp == species[id]->ctrlgp)
				temp2 += x[i];
		}

		temp += species[id]->popctrlgrowth*x[id]*(control[species[id]->ctrlgp-1] - temp2);
	}
	
	
	temp += species[id]->cnstgrowth;

	return temp;
}

int System::euler(double t, double h)
{

	for (int i = 0; i < nS; i++)
	{
		dx[i] = h*f(t, *x, i);
		std::cout << dx[i] << "\n";
	}

	return 0;
}


int System::rk4(double t, double h)
{
	double k[4][nS];
	double x1[nS];
	double x2[nS];
	double x3[nS];

	for (int i = 0; i < nS; i++)
	{
		k[0][i] = f(t, *x, i);
		x1[i] = *x[i] + h * k[0][i] * 0.5;
	}

	for (int i = 0; i < nS; i++)
	{
		k[1][i] = f(t + h * 0.5, x1, i);
		x2[i] = *x[i] + h * k[1][i] * 0.5;
	}

	for (int i = 0; i < nS; i++)
	{
		k[2][i] = f(t + h * 0.5, x2, i);
		x3[i] = *x[i] + h * k[2][i];
	}

	for (int i = 0; i < nS; i++)
	{
		k[3][i] = f(t + h, x3, i);
		dx[i] = h*(k[0][i] + k[1][i] * 2 + k[2][i] * 2 + k[3][i]) / 6;
	}

	return 0;
}

int System::timestep(double t, double h)
{
	euler(t, h);

	for (int i = 0; i < nS; i++)
	{
		*x[i] += dx[i];
		if (*x[i] < 0)
		{
			*x[i] = 0;
		}

	}


	return 0;
}