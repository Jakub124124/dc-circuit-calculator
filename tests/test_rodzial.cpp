#include <gtest/gtest.h>
#include <memory>
#include "rezystor.hpp"
#include "polaczenie_szeregowe.hpp"
#include "polaczenie_rownolegle.hpp"
#include "wynik.hpp"

TEST(Rozdzial, RezystorZapisujeSwojPomiar) {
    Rezystor r("R1", 100.0);
    Wynik w;
    r.rozdziel(5.0, 0.05, w);
    EXPECT_NEAR(w.pomiar("R1").napiecie, 5.0, 1e-9);
    EXPECT_NEAR(w.pomiar("R1").prad, 0.05, 1e-9);
}

TEST(Rozdzial, SzeregDzieliNapiecieProporcjonalnie) {
    PolaczenieSzeregowe p;
    p.dodaj(std::make_unique<Rezystor>("R1", 100.0));
    p.dodaj(std::make_unique<Rezystor>("R2", 200.0));
    const double prad = 12.0 / p.rezystancja();
    Wynik w;
    p.rozdziel(12.0, prad, w);

    EXPECT_NEAR(w.pomiar("R1").napiecie, 4.0, 1e-9);
    EXPECT_NEAR(w.pomiar("R2").napiecie, 8.0, 1e-9);
    EXPECT_NEAR(w.pomiar("R1").prad, 0.04, 1e-9);
    EXPECT_NEAR(w.pomiar("R2").prad, 0.04, 1e-9);
}

TEST(Rozdzial, RownolegleDzieliPradProporcjonalnie) {
    PolaczenieRownolegle p;
    p.dodaj(std::make_unique<Rezystor>("R2", 200.0));
    p.dodaj(std::make_unique<Rezystor>("R3", 300.0));
    const double prad = 12.0 / p.rezystancja();
    Wynik w;
    p.rozdziel(12.0, prad, w);

    EXPECT_NEAR(w.pomiar("R2").napiecie, 12.0, 1e-9);
    EXPECT_NEAR(w.pomiar("R3").napiecie, 12.0, 1e-9);
    EXPECT_NEAR(w.pomiar("R2").prad, 0.06, 1e-9);
    EXPECT_NEAR(w.pomiar("R3").prad, 0.04, 1e-9);
}

TEST(Rozdzial, PrzykladZagniezdzony) {
    // 100 + (200 || 300) przy 12 V
    auto rownolegle = std::make_unique<PolaczenieRownolegle>();
    rownolegle->dodaj(std::make_unique<Rezystor>("R2", 200.0));
    rownolegle->dodaj(std::make_unique<Rezystor>("R3", 300.0));

    PolaczenieSzeregowe p;
    p.dodaj(std::make_unique<Rezystor>("R1", 100.0));
    p.dodaj(std::move(rownolegle));

    const double prad = 12.0 / p.rezystancja();   // 12 / 220
    Wynik w;
    p.rozdziel(12.0, prad, w);

    EXPECT_NEAR(w.pomiar("R1").napiecie, 5.4545454545, 1e-6);
    EXPECT_NEAR(w.pomiar("R2").napiecie, 6.5454545454, 1e-6);
    EXPECT_NEAR(w.pomiar("R3").napiecie, 6.5454545454, 1e-6);
    EXPECT_NEAR(w.pomiar("R2").prad, 0.0327272727, 1e-6);
    EXPECT_NEAR(w.pomiar("R3").prad, 0.0218181818, 1e-6);
}

TEST(Rozdzial, PrawaKirchhoffaDlaPrzykladu) {
    auto rownolegle = std::make_unique<PolaczenieRownolegle>();
    rownolegle->dodaj(std::make_unique<Rezystor>("R2", 200.0));
    rownolegle->dodaj(std::make_unique<Rezystor>("R3", 300.0));
    PolaczenieSzeregowe p;
    p.dodaj(std::make_unique<Rezystor>("R1", 100.0));
    p.dodaj(std::move(rownolegle));

    const double prad = 12.0 / p.rezystancja();
    Wynik w;
    p.rozdziel(12.0, prad, w);

    // napiecia: U(R1) + U(R2) = zrodlo
    EXPECT_NEAR(w.pomiar("R1").napiecie + w.pomiar("R2").napiecie, 12.0, 1e-9);
    // prady: I(R2) + I(R3) = prad calkowity = I(R1)
    EXPECT_NEAR(w.pomiar("R2").prad + w.pomiar("R3").prad, w.pomiar("R1").prad, 1e-9);
}