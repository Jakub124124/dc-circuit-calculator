//
// Created by jakub on 15.11.2026.
//

#include <gtest/gtest.h>
#include <memory>
#include "polaczenie_rownolegle.hpp"
#include "polaczenie_szeregowe.hpp"
#include "rezystor.hpp"
#include "blad_obwodu.hpp"

TEST(PolaczenieRownolegle, DwaRowneRezystory) {
    PolaczenieRownolegle p;
    p.dodaj(std::make_unique<Rezystor>("R1", 100.0));
    p.dodaj(std::make_unique<Rezystor>("R2", 100.0));
    EXPECT_NEAR(p.rezystancja(), 50.0, 1e-9);
}

TEST(PolaczenieRownolegle, DwaRozneRezystory) {
    PolaczenieRownolegle p;
    p.dodaj(std::make_unique<Rezystor>("R1", 200.0));
    p.dodaj(std::make_unique<Rezystor>("R2", 300.0));
    EXPECT_NEAR(p.rezystancja(), 120.0, 1e-9);
}

TEST(PolaczenieRownolegle, PojedynczyElement) {
    PolaczenieRownolegle p;
    p.dodaj(std::make_unique<Rezystor>("R1", 47.0));
    EXPECT_NEAR(p.rezystancja(), 47.0, 1e-9);
}

TEST(PolaczenieRownolegle, PusteToBlad) {
    PolaczenieRownolegle p;
    EXPECT_THROW(p.rezystancja(), BladObwodu);
}

TEST(PolaczenieRownolegle, DodanieNullaToBlad) {
    PolaczenieRownolegle p;
    EXPECT_THROW(p.dodaj(nullptr), BladObwodu);
}

TEST(PolaczenieRownolegle, SzeregWRownoleglym) {
    // (100 + 100) || 200 = 200 || 200 = 100
    auto szereg = std::make_unique<PolaczenieSzeregowe>();
    szereg->dodaj(std::make_unique<Rezystor>("R1", 100.0));
    szereg->dodaj(std::make_unique<Rezystor>("R2", 100.0));

    PolaczenieRownolegle p;
    p.dodaj(std::move(szereg));
    p.dodaj(std::make_unique<Rezystor>("R3", 200.0));
    EXPECT_NEAR(p.rezystancja(), 100.0, 1e-9);
}

TEST(PolaczenieRownolegle, RownoleglyWSzeregu) {
    // 100 + (200 || 300) = 100 + 120 = 220
    auto rownolegle = std::make_unique<PolaczenieRownolegle>();
    rownolegle->dodaj(std::make_unique<Rezystor>("R2", 200.0));
    rownolegle->dodaj(std::make_unique<Rezystor>("R3", 300.0));

    PolaczenieSzeregowe p;
    p.dodaj(std::make_unique<Rezystor>("R1", 100.0));
    p.dodaj(std::move(rownolegle));
    EXPECT_NEAR(p.rezystancja(), 220.0, 1e-9);
}