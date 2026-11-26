#include <gtest/gtest.h>
#include "wynik.hpp"
#include "blad_obwodu.hpp"

TEST(Wynik, ZapisujeIOdczytujePomiar) {
    Wynik w;
    w.dodaj("R1", 100.0, 5.0, 0.05);
    const Pomiar& p = w.pomiar("R1");
    EXPECT_NEAR(p.rezystancja, 100.0, 1e-9);
    EXPECT_NEAR(p.napiecie, 5.0, 1e-9);
    EXPECT_NEAR(p.prad, 0.05, 1e-9);
    EXPECT_NEAR(p.moc(), 0.25, 1e-9);
}

TEST(Wynik, PowtorzonyIdToBlad) {
    Wynik w;
    w.dodaj("R1", 100.0, 5.0, 0.05);
    EXPECT_THROW(w.dodaj("R1", 200.0, 1.0, 0.01), BladObwodu);
}

TEST(Wynik, BrakIdToBlad) {
    Wynik w;
    EXPECT_THROW(w.pomiar("R9"), BladObwodu);
}