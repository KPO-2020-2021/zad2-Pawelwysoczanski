#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
TEST_CASE("test LZespolona Suma 1")
{
    LZespolona x, y, z;
    LZespolona a, b, c;

    a.re = -1;
    a.im = -2;

    b.re = -3;
    b.im = -4;

    c.re = -4;
    c.im = -6;

    x.re = 2;
    x.im = 3;

    y.re = 4;
    y.im = 1;

    z.re = 6;
    z.im = 4;

    CHECK(a + b == c);
    CHECK(x + y == z);
}
TEST_CASE("test LZespolona Suma 2")
{
    LZespolona x, y, z;
    LZespolona a, b, c;

    a.re = -1;
    a.im = -2;

    b.re = 0.0;
    b.im = 0.0;

    c.re = -1;
    c.im = -2;

    x.re = 0.009;
    x.im = 0.009;

    y.re = 0.001;
    y.im = 0.001;

    z.re = 0.01;
    z.im = 0.01;

    CHECK(a + b == c);
    CHECK(x + y == z);
}
TEST_CASE("test LZespolona Suma 3")
{
    LZespolona x, y, z;
    LZespolona a, b, c;

    a.re = -1;
    a.im = -2;

    b.re = -3;
    b.im = -4;

    c.re = -4;
    c.im = -6;

    x.re = 2;
    x.im = 3;

    y.re = 4;
    y.im = 1;

    z.re = 6;
    z.im = 4;

    CHECK((a += b) == c);
    CHECK((x += y) == z);
}
TEST_CASE("test LZespolona Suma 4")
{
    LZespolona x, y, z;
    LZespolona a, b, c;

    a.re = -1;
    a.im = -2;

    b.re = 0.0;
    b.im = 0.0;

    c.re = -1;
    c.im = -2;

    x.re = 0.009;
    x.im = 0.009;

    y.re = 0.001;
    y.im = 0.001;

    z.re = 0.01;
    z.im = 0.01;

    CHECK((a += b) == c);
    CHECK((x += y) == z);
}
TEST_CASE("test LZespolona Różnica 1")
{
    LZespolona x, y, z;
    LZespolona a, b, c;

    a.re = -1;
    a.im = -2;

    b.re = -3;
    b.im = -4;

    c.re = 2;
    c.im = 2;

    x.re = 3;
    x.im = 4;

    y.re = 2;
    y.im = 1;

    z.re = 1;
    z.im = 3;

    CHECK(a - b == c);
    CHECK(x - y == z);
}
TEST_CASE("test LZespolona Różnica 2")
{
    LZespolona x, y, z;
    LZespolona a, b, c;

    a.re = 0;
    a.im = 0;

    b.re = 0.0;
    b.im = 0.0;

    c.re = 0;
    c.im = 0;

    x.re = 0;
    x.im = 0;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = -0.00001;
    z.im = -0.00001;

    CHECK(a - b == c);
    CHECK(x - y == z);
}
TEST_CASE("test LZespolona Iloczyn")
{
    LZespolona x, y, z;
    LZespolona a, b, c;
    LZespolona u, w, k;

    a.re = -1;
    a.im = -2;

    b.re = 0;
    b.im = 0;

    c.re = 0;
    c.im = 0;

    x.re = 2;
    x.im = 3;

    y.re = 1;
    y.im = 0;

    z.re = 2;
    z.im = 3;

    u.re = 3;
    u.im = 9;

    w.re = 1;
    w.im = 1;

    k.re = -6;
    k.im = 12;
    CHECK(a * b == c);
    CHECK(x * y == z);
    CHECK(u * w == k);
}
TEST_CASE("test LZespolona Iloczyn")
{
    LZespolona x, y, z;
    LZespolona a, b, c;

    a.re = -1;
    a.im = -2;

    b.re = -3;
    b.im = -4;

    c.re = -5;
    c.im = 10;

    x.re = 2;
    x.im = 3;

    y.re = 2;
    y.im = 3;

    z.re = -5;
    z.im = 12;

    CHECK(a * b == c);
    CHECK(x * y == z);
}
