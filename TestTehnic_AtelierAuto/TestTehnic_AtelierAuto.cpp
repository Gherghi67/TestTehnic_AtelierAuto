

#include <iostream>
#include <fstream>
#include <windows.h>
#include <thread>

#include "Mecanic.h"
#include "AngajatiService.h"
#include "Timer.h"
#include "Atelier.h"



int main()
{
    /*Masina* masina1 = new Standard();
    Masina* masina2 = new Standard();
    Masina* masina3 = new Standard();
    Masina* masina4 = new Standard();
    Masina* masina5 = new Standard();
    Masina* masina6 = new Standard();

    AngajatiService service;

    std::ifstream file("angajati.txt");
    service.citireAngajati(file);

    service.assignCarToAngajat(masina1, 1);
    service.assignCarToAngajat(masina2, 1);
    service.assignCarToAngajat(masina3, 1);
    service.assignCarToAngajat(masina4, 2);
    service.assignCarToAngajat(masina5, 2);
    service.assignCarToAngajat(masina6, 2);

    std::thread t(&AngajatiService::update, &service);

    int x;
    std::cin >> x;
    if (x == 1) {
        t.detach();
    }*/

    Atelier atelier;

    return 0;
}


