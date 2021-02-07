#pragma warning(disable : 4996) // pentru a putea folosi functia localtime()

#include "Angajat.h"

int Angajat::currentId = 1;

int Angajat::calculareAniVechime(Date dataAngajarii) const {
	time_t currentTime = time(NULL);
	struct tm* aTime = localtime(&currentTime);

	int currentDay = aTime->tm_mday;
	int currentMonth = aTime->tm_mon + 1;
	int currentYear = aTime->tm_year + 1900;

	int aniVechime = currentYear - dataAngajarii.getYear();
	
	if (currentMonth < dataAngajarii.getMonth()) {
		aniVechime--;
	}
	else if (currentMonth == dataAngajarii.getMonth() && currentDay < dataAngajarii.getDay()) {
		aniVechime--;
	}
	return aniVechime;
}

Angajat::Angajat(float coeficient) : coeficientSalariat(coeficient) {}

Angajat::Angajat(std::string nume, std::string prenume, Date dataNasterii, Date dataAngajarii, float coeficient) 
	: coeficientSalariat(coeficient) {

	this->id = currentId;
	currentId++;

	this->nume = nume;
	this->prenume = prenume;
	this->dataNasterii = dataNasterii;
	this->dataAngajarii = dataAngajarii;

	aniVechime = calculareAniVechime(dataAngajarii);

	numarMasiniStandard = 0;
	numarMasiniAutobuz = 0;
	numarMasiniCamion = 0;
}

int Angajat::getId() const {
	return id;
}

std::string Angajat::getNume() const {
	return nume;
}

std::string Angajat::getPrenume() const {
	return prenume;
}

void Angajat::setNume(std::string nume) {
	this->nume = nume;
}

void Angajat::setPrenume(std::string prenume) {
	this->prenume = prenume;
}

Date Angajat::getDataNasterii() const {
	return dataNasterii;
}

Date Angajat::getDataAngajarii() const {
	return dataAngajarii;
}

void Angajat::setDataNasterii(Date dataNasterii) {
	this->dataNasterii = dataNasterii;
}

void Angajat::setDataAngajarii(Date dataAngajarii) {
	this->dataAngajarii = dataAngajarii;
}

float Angajat::calculareSalariu() const {
	return aniVechime * coeficientSalariat * 1000;
}

const float Angajat::getCoeficient() const {
	return coeficientSalariat;
}

bool Angajat::isAvailable(Masina* masina) const {
	if (masina->getType() == "Standard") {
		if (numarMasiniStandard == 3) {
			return false;
		}
		return true;
	}
	else if (masina->getType() == "Autobuz") {
		if (numarMasiniAutobuz == 1) {
			return false;
		}
		return true;
	}
	else if (masina->getType() == "Camion") {
		if (numarMasiniCamion == 1) {
			return false;
		}
		return true;
	}
	return false;
}

void Angajat::adaugaMasina(Masina* masina) {
	masini.push_back(masina);

	if (masina->getType() == "Standard") {
		numarMasiniStandard++;
	}
	else if (masina->getType() == "Autobuz") {
		numarMasiniAutobuz++;
	}
	else if (masina->getType() == "Camion") {
		numarMasiniCamion++;
	}
}

bool Angajat::isWorking() const {
	return timer.isRunning();
}

void Angajat::startWorking() {
	timer.start();
}

void Angajat::stopWorking() {
	if (masini.size() > 0) {
		if (masini[0]->getType() == "Standard") {
			numarMasiniStandard--;
		}
		else if (masini[0]->getType() == "Autobuz") {
			numarMasiniAutobuz--;
		}
		else if (masini[0]->getType() == "Camion") {
			numarMasiniCamion--;
		}

		masini.erase(masini.begin()); // elimina prima masina din vector
		
	}

	timer.stop();
}

int Angajat::getTimePassed() const {
	return timer.getDuration();
}

const int Angajat::getDurataReparare() const {
	return DURATA_REPARARE;
}

int Angajat::getNumarDeMasini() const {
	return numarMasiniStandard + numarMasiniAutobuz + numarMasiniCamion;
}

Masina* Angajat::getCurrentWorkingCar() const {
	if (masini.size() > 0) {
		return masini[0];
	}
	return NULL;
}