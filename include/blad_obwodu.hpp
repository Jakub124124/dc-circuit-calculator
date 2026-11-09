

#ifndef DCCIRCUITCALCULATOR_BLAD_OBWODU_HPP
#define DCCIRCUITCALCULATOR_BLAD_OBWODU_HPP

#include <stdexcept>
#include <string>

class BladObwodu : public std::runtime_error {
public:
    explicit BladObwodu(const std::string& komunikat)
        : std::runtime_error(komunikat) {}
};

#endif //DCCIRCUITCALCULATOR_BLAD_OBWODU_HPP