//
// Created by jakub on 15.11.2026.
//
#include "polaczenie_rownolegle.hpp"
#include "blad_obwodu.hpp"
#include <utility>

void PolaczenieRownolegle::dodaj(std::unique_ptr<ElementObwodu> element)
{
    if (!element)
    {
        throw BladObwodu("Nie można dodać pustego elementu do polaczenia");

    }
    elementy_.push_back(std::move(element));
}

double PolaczenieRownolegle::rezystancja() const
{
    if (elementy_.empty())
    {
        throw BladObwodu("Polaczenie rownolegle nie zawiera elementow");

    }
    double suma_odwrotnosci =0.0;
    for (const auto& element : elementy_){
        const double r = element->rezystancja();
        if (r<=0)
        {
            throw BladObwodu("Element o niedodatniej rezystancji w polaczeniu rownoleglym");
        }
        suma_odwrotnosci += 1.0/r;
    }
    return 1.0/suma_odwrotnosci;
}
