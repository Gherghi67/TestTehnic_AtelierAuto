#ifndef STANDARD_H
#define STANDARD_H

#include <string>

#include "Masina.h"

class Standard : public Masina {
private:
	std::string modTransmisie;

	const float discount = 0.05;

public:
	Standard();
	Standard(int numarDeKilometri, int anulFabricatiei, bool diesel, std::string modTransmisie);

	float calcularePolita(bool discount = false);

	std::string getType();
};

#endif