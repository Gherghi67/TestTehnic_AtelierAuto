#ifndef CAMION_H
#define CAMION_H

#include "Masina.h"

class Camion : public Masina {

private:
	int tonaj;
	
	const float discount = 0.15;

public:
	Camion(int numarDeKilometri, int anulFabricatiei, bool diesel, int tonaj);

	float calcularePolita(bool discount = false);

	std::string getType();
};

#endif