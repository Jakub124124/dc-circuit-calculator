#include <gtest/gtest.h>
#include <memory>
#include "polaczenie_szeregowe.hpp"
#include "rezystor.hpp"
#include "blad_obwodu.hpp"

TEST(PolaczenieSzeregowe, SumujeRezystancje) {
    PolaczenieSzeregowe p;
    p.dodaj(std::make_unique<Rezystor>("R1", 100.0));
    p.dodaj(std::make_unique<Rezystor>("R2", 200.0));
    EXPECT_NEAR(p.rezystancja(), 300.0, 1e-9);
}

TEST(PolaczenieSzeregowe, PojedynczyElement) {
    PolaczenieSzeregowe p;
    p.dodaj(std::make_unique<Rezystor>("R1", 47.0));
    EXPECT_NEAR(p.rezystancja(), 47.0, 1e-9);
}

TEST(PolaczenieSzeregowe, PusteToBlad) {
    PolaczenieSzeregowe p;
    EXPECT_THROW(p.rezystancja(), BladObwodu);
}

TEST(PolaczenieSzeregowe, DodanieNullaToBlad) {
    PolaczenieSzeregowe p;
    EXPECT_THROW(p.dodaj(nullptr), BladObwodu);
}

TEST(PolaczenieSzeregowe, ZagniezdzoneSzeregi) {
    auto wewnetrzne = std::make_unique<PolaczenieSzeregowe>();
    wewnetrzne->dodaj(std::make_unique<Rezystor>("R2", 20.0));
    wewnetrzne->dodaj(std::make_unique<Rezystor>("R3", 30.0));

    PolaczenieSzeregowe p;
    p.dodaj(std::make_unique<Rezystor>("R1", 10.0));
    p.dodaj(std::move(wewnetrzne));
    EXPECT_NEAR(p.rezystancja(), 60.0, 1e-9);
}