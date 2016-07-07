#pragma once
extern const int nS;

class Species
{
public:
	Species(int id, double ppop, double pindpgrowth, double pdpgrowth[], double ppopctrlgrowth, int pctrlgp, double pcnstgrowth);
	~Species();
	double pop;
	double dpop;
	double indpgrowth;
	double dpgrowth[nS];
	double popctrlgrowth;
	int ID;
	int ctrlgp;
	double cnstgrowth;
};

