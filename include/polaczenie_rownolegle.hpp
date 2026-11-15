//
// Created by jakub on 15.11.2026.
//

#ifndef DCCIRCUITCALCULATOR_POLACZENIE_ROWNOLEGLE_HPP
#define DCCIRCUITCALCULATOR_POLACZENIE_ROWNOLEGLE_HPP

#include <memory>
#include <vector>
#include "element_obwodu.hpp"

class PolaczenieRownolegle : public ElementObwodu
{
public:
    void dodaj(std::unique_ptr<ElementObwodu> element);
    double rezystancja() const override;

private:
    std::vector< std::unique_ptr<ElementObwodu> >  elementy_;
};


#endif //DCCIRCUITCALCULATOR_POLACZENIE_ROWNOLEGLE_HPP