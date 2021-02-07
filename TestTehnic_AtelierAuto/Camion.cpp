#include "Camion.h"

Camion::Camion(int numarDeKilometri, int anulFabricatiei, bool diesel, int tonaj)
	: Masina(numarDeKilometri, anulFabricatiei, diesel) {
	this->tonaj = tonaj;
}

float Camion::calcularePolita(bool discount) {
	float polita = aniVechime * 300;

	if (numarDeKilometri > 800000) {
		polita = polita + 700;
	}

	if (discount) {
		polita = polita - this->discount * polita;
	}

	return polita;
}

std::string Camion::getType() {
	return "Camion";
}