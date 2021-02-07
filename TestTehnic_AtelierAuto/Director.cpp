#include "Director.h"

Director::Director() : Angajat(2.0) {}

Director::Director(std::string nume, std::string prenume, Date dataNasterii, Date dataAngajarii)
	: Angajat(nume, prenume, dataNasterii, dataAngajarii, 2.0) {}