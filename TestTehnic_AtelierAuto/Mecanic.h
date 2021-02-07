#ifndef MECANIC_H
#define MECANIC_H

#include <string>

#include "Angajat.h"
#include "Date.h"

class Mecanic : public Angajat {
public:
	Mecanic();
	Mecanic(std::string nume, std::string prenume, Date dataNasterii, Date dataAngajarii);
};

#endif