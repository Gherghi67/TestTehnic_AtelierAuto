#ifndef MASINA_H
#define MASINA_H

#include <chrono>
#include <string>

class Masina {

private:
	static int currentId;

	int calculareAniVechime(int anulFabricatiei) const;

protected:
	int id;
	int numarDeKilometri;
	int anulFabricatiei;
	int aniVechime;

	bool diesel;


public:
	Masina();
	Masina(int numarDeKilometri, int anulFabricatiei, bool diesel);

	virtual float calcularePolita(bool discount = false) = 0;

	virtual std::string getType() = 0;

	int getId() const;
};

#endif