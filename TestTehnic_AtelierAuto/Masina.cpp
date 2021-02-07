#pragma warning(disable : 4996)

#include "Masina.h"

int Masina::currentId = 1;

int Masina::calculareAniVechime(int anulFabricatiei) const {
	time_t currentTime = time(NULL);
	struct tm* aTime = localtime(&currentTime);

	int currentYear = aTime->tm_year + 1900;

	return currentYear - anulFabricatiei;
}

Masina::Masina() {
	this->id = currentId;

	currentId++;
}

Masina::Masina(int numarDeKilometri, int anulFabricatiei, bool diesel) {
	this->id = currentId;

	currentId++;

	this->numarDeKilometri = numarDeKilometri;
	this->anulFabricatiei = anulFabricatiei;
	this->diesel = diesel;

	aniVechime = calculareAniVechime(anulFabricatiei);
}

int Masina::getId() const {
	return id;
}