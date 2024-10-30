#include <iostream>
#include <vector>
#include "Studentas.h"

int main() {
    std::vector<Studentas> studentai;
    int studentuSkaicius;

    std::cout << "Įveskite studentų skaičių: ";
    std::cin >> studentuSkaicius;

    for (int i = 0; i < studentuSkaicius; ++i) {
        std::string vardas, pavarde;
        std::cout << "Įveskite " << i + 1 << "-ojo studento vardą ir pavardę: ";
        std::cin >> vardas >> pavarde;

        Studentas studentas(vardas, pavarde);
        studentas.ivestiDuomenis();

        char pasirinkimas;
        std::cout << "Skaičiuoti galutinį pagal (v)idurkį ar (m)edianą? ";
        std::cin >> pasirinkimas;
        studentas.skaiciuotiGalutini(pasirinkimas == 'm');

        studentai.push_back(studentas);
    }

    std::cout << "\nPavardė          Vardas          Galutinis (Vid. / Med.)\n";
    std::cout << "---------------------------------------------------------\n";
    for (const auto& studentas : studentai) {
        std::cout << studentas << std::endl;
    }

    return 0;
}

