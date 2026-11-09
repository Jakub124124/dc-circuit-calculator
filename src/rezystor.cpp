#include "rezystor.hpp"
#include "blad_obwodu.hpp"
#include <cmath>

Rezystor::Rezystor(std::string id, double wartosc)
    : id_(std::move(id)), wartosc_(wartosc) {
    if (!std::isfinite(wartosc_) || wartosc_ <= 0.0) {
        throw BladObwodu("Rezystancja musi byc dodatnia: " + id_);
    }
    if (id_.empty()) {
        throw BladObwodu("Rezystor musi miec identyfikator");
    }
}

double Rezystor::rezystancja() const { return wartosc_; }
const std::string& Rezystor::id() const { return id_; }