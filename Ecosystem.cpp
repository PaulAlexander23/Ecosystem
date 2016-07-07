// Ecspecies.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{

	System system;

	double dt = 0.02;
	double t = 0;
	int n = 0;

	std::string input1;
	char temp;

	double score = 0.0f;
	double dscore = 0.0f;



	while (t <= 10)
	{
		if (n % 10 == 0){
			std::cout << "\nTime: " << t << "\n";
			for (int i = 0; i < nS; i++)
			{
				std::cout << "Species No:" << i << ", Population:" << *system.x[i] << "\n";
			}
			std::cout << "Score:" << score << std::endl;
			_sleep(400);
		}



		system.timestep(t, dt);

		n += 1;
		t += dt;
		score += dt*dscore;

		if (n % 50 == 0){
			std::cout << "\nSales: \nSpecies1: " << system.species[0]->cnstgrowth << "\nSpecies2: " << system.species[1]->cnstgrowth << "\nSpecies3: " << system.species[2]->cnstgrowth << "\n";

			std::cout << "Input: Press 1, 2, 3 to increase sales; 4, 5, 6 to decrease:" << std::endl;			
			std::getline(std::cin, input1);		

			while (input1.length() > 0)
			{
				temp = input1.front();

				switch (temp)
				{
				case '1':
					system.species[0]->cnstgrowth -= 10;
					dscore = -system.species[0]->cnstgrowth;
					break;
				case '2':
					system.species[1]->cnstgrowth -= 10;
					dscore = -system.species[1]->cnstgrowth;
					break;
				case '3':
					system.species[2]->cnstgrowth -= 10;
					dscore = -5*system.species[2]->cnstgrowth;
					break;
				case '4':
					if (system.species[0]->cnstgrowth < 0){
						system.species[0]->cnstgrowth += 10;
						dscore = -system.species[0]->cnstgrowth;
					}
					break;
				case '5':
					if (system.species[1]->cnstgrowth < 0){
						system.species[1]->cnstgrowth += 10;
						dscore = -system.species[1]->cnstgrowth;
					}
					break;
				case '6':
					if (system.species[2]->cnstgrowth < 0){
						system.species[2]->cnstgrowth += 10;
						dscore = -5 * system.species[2]->cnstgrowth;
					}
					break;
				default:
					break;
				}

				input1.erase(input1.begin());
			}
		}

	}


	return 0;
}

