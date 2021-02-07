#include "Atelier.h"

void Atelier::generareMeniu() {
	std::cout << "1. Adauga masina\n";
	std::cout << "2. Iesire atelier\n";

	int alegere;
	std::cin >> alegere;

	if (alegere == 1) {
		generareMeniuAdaugareMasina();
	}
	else if (alegere == 2) {
		deschis = false;
	}
}

Masina* Atelier::adaugaMasina() {
	int tip;

	std::cout << "Alege tipul masinii:\n";
	std::cout << "1. Standard\n";
	std::cout << "2. Autobuz\n";
	std::cout << "3. Camion\n";

	std::cin >> tip;

	if (tip == 1) {
		int numarDeKilometri, anulFabricatiei;
		
		bool diesel;

		std::string modTransmisie;

		std::cout << "Numar de kilometri: ";
		std::cin >> numarDeKilometri;
		std::cout << "\nAnul fabricatiei: ";
		std::cin >> anulFabricatiei;
		std::cout << "\nDiesel(1 sau 0): ";
		std::cin >> diesel;
		std::cout << "\nMod transmisie(Manual sau Automat): ";
		std::cin >> modTransmisie;

		Masina* masina = new Standard(numarDeKilometri, anulFabricatiei, diesel, modTransmisie);
		return masina;
	}
	else if (tip == 2) {
		int numarDeKilometri, anulFabricatiei;

		bool diesel;

		int numarDeLocuri;

		std::cout << "Numar de kilometri: ";
		std::cin >> numarDeKilometri;
		std::cout << "\nAnul fabricatiei: ";
		std::cin >> anulFabricatiei;
		std::cout << "\nDiesel(1 sau 0): ";
		std::cin >> diesel;
		std::cout << "\nNumar de locuri: ";
		std::cin >> numarDeLocuri;

		Masina* masina = new Autobuz(numarDeKilometri, anulFabricatiei, diesel, numarDeLocuri);
		return masina;
	}
	else if (tip == 3) {
		int numarDeKilometri, anulFabricatiei;

		bool diesel;

		int tonaj;

		std::cout << "Numar de kilometri: ";
		std::cin >> numarDeKilometri;
		std::cout << "\nAnul fabricatiei: ";
		std::cin >> anulFabricatiei;
		std::cout << "\nDiesel(1 sau 0): ";
		std::cin >> diesel;
		std::cout << "\nTonaj: ";
		std::cin >> tonaj;

		Masina* masina = new Camion(numarDeKilometri, anulFabricatiei, diesel, tonaj);
		return masina;
	}
}

void Atelier::generareMeniuAdaugareMasina() {

	Masina* masina = adaugaMasina();

	std::cout << "Doresti ca masina sa fie reparata de un anumit angajat?\n";
	std::cout << "1. Da\n";
	std::cout << "2. Nu\n";

	int alegere;
	std::cin >> alegere;

	if (alegere == 1) {
		std::cout << "Alege id-ul angajatului dorit\n";

		service.afisareAngajati();

		int id;
		std::cin >> id;


		if (service.isAvailable(masina, id)) {
			service.assignCarToAngajat(masina, id);

			std::cout << "Masina a fost asignata angajatului cu succes!\n";
			return;
		}
		else {
			std::cout << "Ne pare rau, angajatul nu este disponibil! Ce doresti sa faci?\n";
			std::cout << "1. Astept\n";
			std::cout << "2. Gasirea primului angajat liber\n";
			std::cout << "3. Sa plec\n";

			std::cin >> alegere;

			if (alegere == 1) {
				std::cout << "Se asteapta...\n";

				while (!service.isAvailable(masina, id));

				service.assignCarToAngajat(masina, id);
				
				std::cout << "Masina a fost asignata angajatului cu succes\n";
			}
			else if (alegere == 2) {
				assignCarToFirstAvailableAngajat(masina);
			}
			else if (alegere == 3) {
				return;
			}
		}
	}
	else if (alegere == 2) {
		assignCarToFirstAvailableAngajat(masina);
	}

}

void Atelier::assignCarToFirstAvailableAngajat(Masina* masina) {
	int index = service.findFirstAvailableAngajat(masina);

	if (index == -1) {
		std::cout << "Ne pare rau, toti angajatii atelierului sunt ocupati! Ce doriti sa faceti?\n";
		std::cout << "1. Astept\n";
		std::cout << "2. Plec\n";

		int alegere;
		std::cin >> alegere;

		if (alegere == 1) {
			std::cout << "Se asteapta...\n";

			while (service.findFirstAvailableAngajat(masina) == -1);

			service.assignCarToAngajat(masina, service.findFirstAvailableAngajat(masina));

			std::cout << "Masina a fost asignata unui angajat cu succes!\n";
		}
		else if (alegere == 2) {
			return;
		}
	}

	service.assignCarToAngajat(masina, index);
}


Atelier::Atelier() {
	std::ifstream file("angajati.txt");
	service.citireAngajati(file);

	if (service.getAngajatiSize() >= 1) {
		std::cout << "Bun venit, atelierul este deschis!\n";

		deschis = true;

		std::thread t(&AngajatiService::update, &service); // threadul care va rula metoda update() din obiectul service

		while (deschis) {
			generareMeniu();
		}

		t.detach();
	}
	else {
		std::cout << "Ne pare rau, atelierul nu este deschis!\n";

		deschis = false;
	}
}
