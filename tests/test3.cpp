#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "Statystyki.hh"

TEST_CASE("LZespolona - wyswietlanie standard")
{
    LZespolona x;

    x.re = 2;
    x.im = 2;

    std::ostringstream out;

    out << x;
    std::cout << out.str() << std::endl;
    CHECK("(2.00+2.00i)" == out.str());
}

TEST_CASE("LZespolona - wyswietlanie zaokraglane")
{
    LZespolona x;

    x.re = 2.0 / 3.0;
    x.im = 2.0 / 3.0;

    std::ostringstream out;

    out << x;
    std::cout << out.str() << std::endl;
    CHECK("(0.67+0.67i)" == out.str());
}

TEST_CASE("LZespolona - wczytywanie standard")
{
    LZespolona x;

    std::istringstream in("(10+10.10i)");
    in >> x;
    std::ostringstream out;
    out << x; // lub strcmp? ew. == dla LZesp

    CHECK("(10.00+10.10i)" == out.str());
}
// TEST_CASE("WyrazenieZesp - wyswietlanie")
// {

//     WyrazenieZesp x;

//     x.Arg1 = {3, 3};
//     x.Op = Op_Dodaj;
//     x.Arg2 = {4, 8};

//     std::ostringstream out;
//     out << x;
//     std::cout << out.str() << std::endl;
//     CHECK("(3.00+3.00i)+(4.00+8.00)" == out.str());
// }
TEST_CASE("WyrazenieZesp - dodawanie")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1 = {3, 3};
    x.Op = Op_Dodaj;
    x.Arg2 = {4, 8};

    y.re = 7;
    y.im = 11;

    CHECK(x.Oblicz() == y);
}
TEST_CASE("WyrazenieZesp - odejmowanie")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1 = {3, 3};
    x.Op = Op_Odejmij;
    x.Arg2 = {4, 8};

    y.re = -1;
    y.im = -5;

    CHECK(x.Oblicz() == y);
}
TEST_CASE("WyrazenieZesp - mnozenie")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1 = {3, 3};
    x.Op = Op_Mnoz;
    x.Arg2 = {4, 8};

    y.re = -12;
    y.im = 36;

    CHECK(x.Oblicz() == y);
}
TEST_CASE("WyrazenieZesp - dzielenie")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1 = {4, 3};
    x.Op = Op_Dziel;
    x.Arg2 = {1, -2};

    y.re = 2;
    y.im = -1;

    CHECK(x.Oblicz() == y);
}
TEST_CASE("Modul Staystyka")
{
    Statystyka odp;
    double x;

    odp.DodajNiepoprawna();
    odp.DodajPoprawna();

    x = 50.0;
    CHECK(odp.Wykonaj() == x);
}