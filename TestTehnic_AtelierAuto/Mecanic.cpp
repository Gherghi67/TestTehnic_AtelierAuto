#include "Mecanic.h"

Mecanic::Mecanic() : Angajat(1.5) {}

Mecanic::Mecanic(std::string nume, std::string prenume, Date dataNasterii, Date dataAngajarii)
	: Angajat(nume, prenume, dataNasterii, dataAngajarii, 1.5) {}