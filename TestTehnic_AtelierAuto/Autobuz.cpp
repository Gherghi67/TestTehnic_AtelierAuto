#include "Autobuz.h"

Autobuz::Autobuz(int numarDeKilometri, int anulFabricatiei, bool diesel, int numarDeLocuri)
	: Masina(numarDeKilometri, anulFabricatiei, diesel) {
	this->numarDeLocuri = numarDeLocuri;
}

float Autobuz::calcularePolita(bool discount) {
	float polita = aniVechime * 200;

	if (diesel) {
		polita = polita + 1000;
	}

	if (numarDeKilometri > 200000) {
		polita = polita + 1000;
	}
	else if (numarDeKilometri > 100000) {
		polita = polita + 500;
	}

	if (discount) {
		polita = polita - this->discount * polita;
	}

	return polita;
}

std::string Autobuz::getType() {
	return "Autobuz";
}