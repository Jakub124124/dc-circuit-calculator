//
// Created by jakub on 9.11.2026.
//

#ifndef DCCIRCUITCALCULATOR_REZYSTOR_HPP
#define DCCIRCUITCALCULATOR_REZYSTOR_HPP

#include <string>
#include "element_obwodu.hpp"

class Rezystor : public ElementObwodu {
public:
    Rezystor(std::string id, double wartosc);
    double rezystancja() const override;
    const std::string& id() const;

private:
    std::string id_;
    double wartosc_;
};

#endif //DCCIRCUITCALCULATOR_REZYSTOR_HPP