#ifndef ANGAJAT_H
#define ANGAJAT_H

#include <string>
#include <chrono>
#include <vector>

#include "Date.h"
#include "Standard.h"
#include "Autobuz.h"
#include "Camion.h"
#include "Timer.h"

class Angajat {
private:
	// id-ul curent static care ajuta la autoincrementare
	static int currentId;

	int aniVechime;

	std::vector<Masina*> masini;

	int numarMasiniStandard;
	int numarMasiniAutobuz;
	int numarMasiniCamion;

	const int DURATA_REPARARE = 1000; // durata de reparare pentru fiecare masina care se exprima in secunde

	// bool working;

	Timer timer;

	int calculareAniVechime(Date dataAngajarii) const;

	

protected:
	int id;

	std::string nume;
	std::string prenume;

	Date dataNasterii;
	Date dataAngajarii;

	const float coeficientSalariat;

public:
	Angajat(float coeficient);
	Angajat(std::string nume, std::string prenume, Date dataNasterii, Date dataAngajarii, float coeficient);

	int getId() const;

	std::string getNume() const;
	std::string getPrenume() const;

	void setNume(std::string nume);
	void setPrenume(std::string prenume);

	Date getDataNasterii() const;
	Date getDataAngajarii() const;

	void setDataNasterii(Date dataNasterii);
	void setDataAngajarii(Date dataAngajarii);

	float calculareSalariu() const;

	const float getCoeficient() const;

	bool isAvailable(Masina* masina) const;

	void adaugaMasina(Masina* masina);

	bool isWorking() const;

	void startWorking();
	void stopWorking();

	int getTimePassed() const;

	const int getDurataReparare() const;

	int getNumarDeMasini() const;

	Masina* getCurrentWorkingCar() const;
	// friend std::istream& operator >> (std::istream& input, )
};

#endif