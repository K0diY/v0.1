#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class Studentas {
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
    double galutinisVid;
    double galutinisMed;

public:
    // Konstruktorius
    Studentas(const std::string& vardas = "", const std::string& pavarde = "");

    // Kopijavimo konstruktorius
    Studentas(const Studentas& other);

    // Priskyrimo operatorius
    Studentas& operator=(const Studentas& other);

    // Destruktorius
    ~Studentas();

    // Duomenų įvedimo metodas
    void ivestiDuomenis();

    // Galutinio balo skaičiavimas (vidurkis arba mediana)
    void skaiciuotiGalutini(bool naudotiMediana);

    // Perkeltas cout
    friend std::ostream& operator<<(std::ostream& os, const Studentas& studentas);

    // Papildomi metodai duomenų gavimui (naudojami faile)
    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
};

#endif // STUDENTAS_H
