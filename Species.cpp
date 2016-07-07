#include "stdafx.h"
#include "Species.h"


Species::Species(int id, double ppop, double pindpgrowth, double pdpgrowth[], double ppopctrlgrowth, int pctrlgp, double pcnstgrowth)
{
	ID = id;

	pop = ppop;
	indpgrowth = pindpgrowth;

	for (int i = 0; i < nS; i++){
		dpgrowth[i] = pdpgrowth[i];
	}	
	popctrlgrowth = ppopctrlgrowth;
	ctrlgp = pctrlgp;
	cnstgrowth = pcnstgrowth;

}


Species::~Species()
{
}

