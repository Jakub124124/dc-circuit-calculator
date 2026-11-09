#include <gtest/gtest.h>
#include "rezystor.hpp"
#include "blad_obwodu.hpp"

TEST(Rezystor, ZwracaPodanaRezystancje) {
    Rezystor r("R1", 100.0);
    EXPECT_DOUBLE_EQ(r.rezystancja(), 100.0);
}

TEST(Rezystor, ZeroToBlad) {
    EXPECT_THROW(Rezystor("R1", 0.0), BladObwodu);
}

TEST(Rezystor, UjemnaToBlad) {
    EXPECT_THROW(Rezystor("R1", -5.0), BladObwodu);
}

TEST(Rezystor, PustyIdToBlad) {
    EXPECT_THROW(Rezystor("", 10.0), BladObwodu);
}