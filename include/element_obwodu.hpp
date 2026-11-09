//
// Created by jakub on 9.11.2026.
//

#ifndef DCCIRCUITCALCULATOR_ELEMENT_OBWODU_HPP
#define DCCIRCUITCALCULATOR_ELEMENT_OBWODU_HPP

class ElementObwodu {
public:
    virtual ~ElementObwodu() = default;
    virtual double rezystancja() const = 0;
};

#endif //DCCIRCUITCALCULATOR_ELEMENT_OBWODU_HPP