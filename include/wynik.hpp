//
// Created by jakub on 26.11.2026.
//

#ifndef DCCIRCUITCALCULATOR_WYNIK_HPP
#define DCCIRCUITCALCULATOR_WYNIK_HPP

#include <string>
#include <vector>

struct Pomiar {
    std::string id;
    double rezystancja;
    double napiecie;
    double prad;
    double moc() const { return napiecie * prad; }
};

class Wynik {
public:
    void dodaj(const std::string& id, double rezystancja, double napiecie, double prad);
    const Pomiar& pomiar(const std::string& id) const;
    const std::vector<Pomiar>& pomiary() const;

private:
    std::vector<Pomiar> pomiary_;
};

#endif //DCCIRCUITCALCULATOR_WYNIK_HPP