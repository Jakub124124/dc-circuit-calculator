#include "wynik.hpp"
#include "blad_obwodu.hpp"

void Wynik::dodaj(const std::string& id, double rezystancja, double napiecie, double prad) {
    for (const auto& p : pomiary_) {
        if (p.id == id) {
            throw BladObwodu("Powtorzony identyfikator elementu: " + id);
        }
    }
    pomiary_.push_back({id, rezystancja, napiecie, prad});
}

const Pomiar& Wynik::pomiar(const std::string& id) const {
    for (const auto& p : pomiary_) {
        if (p.id == id) {
            return p;
        }
    }
    throw BladObwodu("Brak elementu o identyfikatorze: " + id);
}

const std::vector<Pomiar>& Wynik::pomiary() const {
    return pomiary_;
}