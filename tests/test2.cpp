#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test LZespolona Sprzezenie 1 - dla niezreowej czesci im")
{
    LZespolona y, x;

    x.re = 2;
    x.im = 3;

    y.re = 2;
    y.im = -3;

    CHECK((x.Sprzezenie()) == y);
}
TEST_CASE("test LZespolona Sprzezenie 2 - dla zreowej czesci im")
{
    LZespolona y, x;

    x.re = 2;
    x.im = 0;

    y.re = 2;
    y.im = 0;

    CHECK((x.Sprzezenie()) == y);
}
TEST_CASE("test modul2")
{
    LZespolona x;
    int y;

    x = {3, 4};

    y = 25;

    CHECK(x.modul2() == y);
}
TEST_CASE("LZespolona - porownanie 1")
{
    LZespolona x, y;

    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;

    CHECK(x != y);
}

TEST_CASE("LZespolona - porownanie 2")
{
    LZespolona x, y;

    x.re = 2;
    x.im = 2;

    y.re = 2;
    y.im = 2;

    CHECK(x == y);
}
TEST_CASE("LZespolona - porownanie 3")
{
    LZespolona x, y;

    x.re = 2;
    x.im = 2;

    y.re = 2.0000000001;
    y.im = 2.0000000001;

    CHECK(x == y);
}
TEST_CASE("LZespolona - dzielenie przez skalar - standardowe 1")
{
    LZespolona x, y;
    double t = 2;

    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;

    CHECK((x / t) == y);
}

TEST_CASE("LZespolona - dzielenie przez skalar - standardowe z przyblizeniem")
{
    LZespolona x, y;
    double t = 3;

    x.re = 1;
    x.im = 1;

    y.re = 0.33;
    y.im = 0.33;
    std::cout << (x / t) << std::endl;
    std::cout << y << std::endl;
    std::cout << ((x / t) == y) << std::endl;
    CHECK((x / t) == y);
}

TEST_CASE("LZespolona - dzielenie przez skalar - zero")
{
    LZespolona x;
    double t = 0;

    x.re = 2;
    x.im = 2;

    WARN_THROWS(x / t);
}
TEST_CASE("LZespolona - delenie przez liczbe zespolona")
{
    LZespolona x, y, z;

    x.re = 4;
    x.im = 3;

    y.re = 1;
    y.im = -2;

    z.re = 2;
    z.im = -1;

    std::cout << (y.Sprzezenie()) << std::endl;
    std::cout << (x * y.Sprzezenie()) << std::endl;
    std::cout << (y.modul2()) << std::endl;
    std::cout << (x / y) << std::endl;

    CHECK((x / y) == z);
}
TEST_CASE("LZespolona - dzielenie przez skalar - standardowe 2")
{
    LZespolona x, y;
    double t = 2;

    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;

    CHECK((x /= t) == y);
}

TEST_CASE("LZespolona - dzielenie przez skalar - standardowe z przyblizeniem 2")
{
    LZespolona x, y;
    double t = 3;

    x.re = 1;
    x.im = 1;

    y.re = 0.33;
    y.im = 0.33;
    std::cout << (x /= t) << std::endl;
    std::cout << y << std::endl;
    std::cout << ((x /= t) == y) << std::endl;
    CHECK((x /= t) == y);
}

TEST_CASE("LZespolona - dzielenie przez skalar - zero 2")
{
    LZespolona x;
    double t = 0;

    x.re = 2;
    x.im = 2;

    WARN_THROWS(x /= t);
}
