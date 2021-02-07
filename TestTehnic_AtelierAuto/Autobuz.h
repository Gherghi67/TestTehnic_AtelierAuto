#ifndef AUTOBUZ_H
#define AUTOBUZ_H

#include "Masina.h"

class Autobuz : public Masina {
private:
	int numarDeLocuri;

	const float discount = 0.1;

public:
	Autobuz(int numarDeKilometri, int anulFabricatiei, bool diesel, int numarDeLocuri);

	float calcularePolita(bool discount = false);

	std::string getType();
};
#endif