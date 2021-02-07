#include "Standard.h"

Standard::Standard() : Masina() {}

Standard::Standard(int numarDeKilometri, int anulFabricatiei, bool diesel, std::string modTransmisie)
	: Masina(numarDeKilometri, anulFabricatiei, diesel) {
	this->modTransmisie = modTransmisie;
}

float Standard::calcularePolita(bool discount) {
	float polita = aniVechime * 100;

	if (diesel) {
		polita = polita + 500;
	}

	if (numarDeKilometri > 200000) {
		polita = polita + 500;
	}

	if (discount) {
		polita = polita - this->discount * polita;
	}

	return polita;
}

std::string Standard::getType() {
	return "Standard";
}