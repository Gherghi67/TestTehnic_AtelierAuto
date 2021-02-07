#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <string>

#include "Angajat.h"
#include "Date.h"

class Director : public Angajat {
public:
	Director();
	Director(std::string nume, std::string prenume, Date dataNasterii, Date dataAngajarii);
};

#endif