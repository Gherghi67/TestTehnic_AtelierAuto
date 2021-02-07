#ifndef ANGAJATI_SERVICE_H
#define ANGAJATI_SERVICE_H

#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <thread>

#include "Mecanic.h"
#include "Director.h"
#include "Asistent.h"
#include "Date.h"
#include "Masina.h"



class AngajatiService {
private:
	std::vector<Angajat*> angajati;

	

	int cautaAngajat(int id) const; // metoda care imi cauta angajatul in vector dupa id folosita la stergere, editare si calculare
									// salariu

public:
	void afisareAngajati() const;
	void adaugareAngajat(Angajat* angajat);
	void citireAngajati(std::ifstream& file);

	int stergereAngajat(int id);

	// am considerat ca data angajarii nu poate fi editata
	int editareAngajat(int id, std::string nume, std::string prenume, Date dataNasterii);

	float calculareSalariu(int id) const;

	// metoda care va gestiona timerele fiecarui angajat si care va fi apelata de catre un thread diferit de threadul principal
	void update(); 

	void assignCarToAngajat(Masina* masina, int id);
	

	int getAngajatiSize() const;

	bool isAvailable(Masina* masina, int id) const;

	int findFirstAvailableAngajat(Masina* masina) const;
};

#endif