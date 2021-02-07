#ifndef ASISTENT_H
#define ASISTENT_H

#include <string>

#include "Angajat.h"
#include "Date.h"

class Asistent : public Angajat {
public:
	Asistent(std::string nume, std::string prenume, Date dataNasterii, Date dataAngajarii);
};

#endif