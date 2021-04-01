#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test LZespolona Suma 1")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;

    CHECK(x + y == z);
}
TEST_CASE("test LZespolona Różnica")
{
    LZespolona x, y, z;

    x.re = 3;
    x.im = 4;

    y.re = 2;
    y.im = 1;

    z.re = 1;
    z.im = 3;

    CHECK(x + y == z);
}
TEST_CASE("test LZespolona Iloczyn")
{
    LZespolona x, y, z;

    x.re = 2;
    x.im = 3;

    y.re = 2;
    y.im = 3;

    z.re = -5;
    z.im = 12;

    CHECK(x * y == z);
}
TEST_CASE("test LZespolona Sprzezenie")
{
    LZespolona y, x;

    x.re = 2;
    x.im = 3;

    y.re = 2;
    y.im = -3;
}
TEST_CASE("test LZespolona Suma 2")
{
    LZespolona x, y, z;

    x.re = 2;
    x.im = 3;

    y.re = 4;
    y.im = 1;

    z.re = 6;
    z.im = 4;

    CHECK((x += y) == z);
}
