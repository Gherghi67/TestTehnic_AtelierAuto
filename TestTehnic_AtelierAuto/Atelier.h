#ifndef ATELIER_H
#define ATELIER_H

#include <iostream>
#include <fstream>
#include <thread>

#include "AngajatiService.h"
#include "Standard.h"
#include "Autobuz.h"
#include "Camion.h"

class Atelier {

private:
	AngajatiService service;


	bool deschis;

	void generareMeniu(); // metoda care va genera optiunile utilizatorului
	void generareMeniuAdaugareMasina();

	Masina* adaugaMasina();

	void assignCarToFirstAvailableAngajat(Masina* masina);

public:
	Atelier();


};

#endif