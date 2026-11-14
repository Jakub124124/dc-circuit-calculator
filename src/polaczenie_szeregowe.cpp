#include "polaczenie_szeregowe.hpp"
#include "blad_obwodu.hpp"
#include <utility>

void PolaczenieSzeregowe::dodaj(std::unique_ptr<ElementObwodu> element) {
    if (!element) {
        throw BladObwodu("Nie mozna dodac pustego elementu do polaczenia");
    }
    elementy_.push_back(std::move(element));
}

double PolaczenieSzeregowe::rezystancja() const {
    if (elementy_.empty()) {
        throw BladObwodu("Polaczenie szeregowe nie zawiera elementow");
    }
    double suma = 0.0;
    for (const auto& element : elementy_) {
        suma += element->rezystancja();
    }
    return suma;
}