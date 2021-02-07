#include "AngajatiService.h"

int AngajatiService::cautaAngajat(int id) const {
	std::vector<Angajat*>::const_iterator it;

	for (it = angajati.begin(); it != angajati.end(); ++it) {
		if ((*it)->getId() == id) {
			return it - angajati.begin();
		}
	}
	return -1; // se returneaza -1 in cazul in care angajatul cautat nu exista
}


void AngajatiService::afisareAngajati() const {
	std::vector<Angajat*>::const_iterator it;

	std::cout << "Lista angajatilor: \n";
	for (it = angajati.begin(); it != angajati.end(); ++it) {
		std::cout << "ID: " << (*it)->getId() << "\n";
		std::cout << "Nume: " << (*it)->getNume() << "\n";
		std::cout << "Prenume: " << (*it)->getPrenume() << "\n";
		std::cout << "Data nasterii: ";
		(*it)->getDataNasterii().printDate();
		std::cout << "\nData angajarii: ";
		(*it)->getDataAngajarii().printDate();
		std::cout << "\nSalariu: " << (*it)->calculareSalariu() << " lei\n";
	}
}

void AngajatiService::adaugareAngajat(Angajat* angajat) {
	angajati.push_back(angajat);
}

void AngajatiService::citireAngajati(std::ifstream& file) {
	std::string line;

	// pentru citirea din fisier am facut o tokenizare
	while (std::getline(file, line) && line != "") {
		std::stringstream check(line);

		std::string intermediate;

		std::vector<std::string> tokens;

		while (getline(check, intermediate, ' ')) {
			tokens.push_back(intermediate);
		}

		std::string nume = tokens[1];
		std::string prenume = tokens[2];

		Date dataNasterii(atoi(tokens[3].c_str()), atoi(tokens[4].c_str()), atoi(tokens[5].c_str()));
		Date dataAngajarii(atoi(tokens[6].c_str()), atoi(tokens[7].c_str()), atoi(tokens[8].c_str()));

		if (tokens[0] == "1") {
			Angajat* angajat = new Director(nume, prenume, dataNasterii, dataAngajarii);
			adaugareAngajat(angajat);
		}
		else if (tokens[0] == "2") {
			Angajat* angajat = new Mecanic(nume, prenume, dataNasterii, dataAngajarii);
			adaugareAngajat(angajat);
		}
		else if (tokens[0] == "3") {
			Angajat* angajat = new Asistent(nume, prenume, dataNasterii, dataAngajarii);
			adaugareAngajat(angajat);
		}
	}
}

int AngajatiService::stergereAngajat(int id) {
	int index = cautaAngajat(id);

	if (index == -1) {
		return -1; // se returneaza -1 in cazul in care angajatul nu este gasit
	}

	angajati.erase(angajati.begin() + index);
}

int AngajatiService::editareAngajat(int id, std::string nume, std::string prenume, Date dataNasterii) {
	int index = cautaAngajat(id);

	if (index == -1) {
		return -1;
	}

	angajati[index]->setNume(nume);
	angajati[index]->setPrenume(prenume);
	angajati[index]->setDataNasterii(dataNasterii);
}

float AngajatiService::calculareSalariu(int id) const {
	int index = cautaAngajat(id);

	if (index == -1) {
		return -1;
	}

	return angajati[index]->calculareSalariu();
}

void AngajatiService::update() {
	std::vector<Angajat*>::iterator it;

	for (it = angajati.begin(); it != angajati.end(); ++it) {
		(*it)->startWorking();
	}

	while (true) {
		

		for (it = angajati.begin(); it != angajati.end(); ++it) {
			if ((*it)->getTimePassed() >= (*it)->getDurataReparare() && (*it)->getNumarDeMasini() > 0) {
				std::cout << "Angajatul " << (*it)->getId() << " a terminat masina cu id-ul " << (*it)->getCurrentWorkingCar()->getId()
					<< "\n";

				(*it)->stopWorking();
				

				if ((*it)->getNumarDeMasini() > 0) {
					(*it)->startWorking();
					std::cout << "Angajatul " << (*it)->getId() << " mai are " << (*it)->getNumarDeMasini() << "\n";


					std::cout << "Angajatul " << (*it)->getId() << " a inceput sa lucreze la masina cu id-ul "
						<< (*it)->getCurrentWorkingCar()->getId() << "\n";
				}
			}
		}
	}
}

void AngajatiService::assignCarToAngajat(Masina* masina, int id) {
	int index = cautaAngajat(id);

	angajati[index]->adaugaMasina(masina);
}

int AngajatiService::getAngajatiSize() const {
	return angajati.size();
}

bool AngajatiService::isAvailable(Masina* masina, int id) const {
	int index = cautaAngajat(id);

	if (angajati[index]->isAvailable(masina)) {
		return true;
	}
	return false;
}

int AngajatiService::findFirstAvailableAngajat(Masina* masina) const {
	std::vector<Angajat*>::const_iterator it;

	for (it = angajati.begin(); it != angajati.end(); ++it) {
		if ((*it)->isAvailable(masina)) {
			return (*it)->getId();
		}
	}

	return -1; // se returneaza -1 in cazul in care toti angajatii sunt ocupati
}