#include "Studentas.h"
#include <algorithm>
#include <numeric>
#include <stdexcept>

// Konstruktorius
Studentas::Studentas(const std::string& vardas, const std::string& pavarde)
    : vardas(vardas), pavarde(pavarde), egzaminas(0), galutinisVid(0), galutinisMed(0) {}

// Kopijavimo konstruktorius
Studentas::Studentas(const Studentas& other)
    : vardas(other.vardas), pavarde(other.pavarde), namuDarbai(other.namuDarbai),
    egzaminas(other.egzaminas), galutinisVid(other.galutinisVid), galutinisMed(other.galutinisMed) {}

// Priskyrimo operatorius
Studentas& Studentas::operator=(const Studentas& other) {
    if (this == &other) return *this;
    vardas = other.vardas;
    pavarde = other.pavarde;
    namuDarbai = other.namuDarbai;
    egzaminas = other.egzaminas;
    galutinisVid = other.galutinisVid;
    galutinisMed = other.galutinisMed;
    return *this;
}

// Destruktorius
Studentas::~Studentas() {}

// Duomenų įvedimo metodas
void Studentas::ivestiDuomenis() {
    int namuDarbas;
    std::cout << "Įveskite namų darbų rezultatus (baigti -1): ";
    while (std::cin >> namuDarbas && namuDarbas != -1) {
        namuDarbai.push_back(namuDarbas);
    }
    std::cout << "Įveskite egzamino rezultatą: ";
    std::cin >> egzaminas;
}

// Galutinio balo skaičiavimas (vidurkis arba mediana)
void Studentas::skaiciuotiGalutini(bool naudotiMediana) {
    if (naudotiMediana) {
        std::sort(namuDarbai.begin(), namuDarbai.end());
        galutinisMed = namuDarbai.size() % 2 == 0
            ? (namuDarbai[namuDarbai.size() / 2 - 1] + namuDarbai[namuDarbai.size() / 2]) / 2.0
            : namuDarbai[namuDarbai.size() / 2];
        galutinisMed = 0.4 * galutinisMed + 0.6 * egzaminas;
    }
    else {
        double vidurkis = std::accumulate(namuDarbai.begin(), namuDarbai.end(), 0.0) / namuDarbai.size();
        galutinisVid = 0.4 * vidurkis + 0.6 * egzaminas;
    }
}

// Perkeltas cout
std::ostream& operator<<(std::ostream& os, const Studentas& studentas) {
    os << std::left << std::setw(15) << studentas.pavarde
        << std::setw(15) << studentas.vardas;
    if (studentas.galutinisVid > 0) {
        os << std::setw(15) << std::fixed << std::setprecision(2) << studentas.galutinisVid;
    }
    else {
        os << std::setw(15) << std::fixed << std::setprecision(2) << studentas.galutinisMed;
    }
    return os;
}
