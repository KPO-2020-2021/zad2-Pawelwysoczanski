#include "LZespolona.hh"

#define MIN_DIFF 0.0001
#define PI 3.141592
/****************************************************************
*                       Modul LZespolona                        *
*Kolejnosc wystepowania przeciazen i metod zapisanychw kodzie:  *
*Operator + linia:                                              * 
*Operator += linia:                                             *
*Operator - linia:                                              *
*Operator * linia:                                              * 
*Operator / linia:                                              *   
*Operator /= linia:                                             *
*Operator / przez skalar linia:                                 *
*Operator /= przez skalar linia                                 *
*Sprzezenie() linia:                                            * 
*Modul2() linia:                                                *
*Operator == linia:                                             *
*WczytajTenZnak() linia:                                        *
*Operator >> linia:                                             *
*Operator << linia:                                             *
*Wyswietl() linia:                                              *
*arg()  linia:                                                  *
*****************************************************************/

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator+(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
/*
*Modyfikacja przeciazenia operatora dodawnia
*/
LZespolona LZespolona::operator+=(LZespolona const &Skl2)
{

  this.re += Skl2.re;
  this.im += Skl2.im;

  return this;
}
/*!
 * Realizuje odjecie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator-(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;

  return Wynik;
}
/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator*(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = (Skl1.re * Skl2.re) + ((Skl1.im * Skl2.im) * (-1));
  Wynik.im = (Skl1.im * Skl2.re) + (Skl1.re * Skl2.im);

  return Wynik;
}
/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 *    Sprzezenie()-funkcja tworzaca sprzezenie z liczby zespolonej,
 *    Modul2()-funkcja tworzaca skalar z liczby zespolonej,
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator/(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik = Skl1 * Sprzezenie(Skl2) / (Modul2(Skl2));

  return Wynik;
}
/*
*Modyfikacaj pzreciazenia opeartora dzielenia
*/
LZespolona::LZespolona operator/=(LZespolona &Skl1, LZespolona const &Skl2)
{
  LZespolona Licznik, Wynik;
  double Mianownik;

  Licznik = Skl1 * Sprzezenie(Skl2);
  Mianownik = Modul2(Skl2);

  Wynik = Licznik / Mianownik;

  return Wynik;
}
/*!
 * Realizuje dzielenie liczby zespolonej przez skakar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */

LZespolona operator/(LZespolona Skl1, double Skl2)
{
  if (Skl2 == 0)
  {
    throw std::runtime_error("Math error: Attempted to divide by Zero\n");
  }
  LZespolona Wynik;
  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;
  return Wynik;
}

LZespolona operator/=(LZespolona Skl1, double Skl2)
{
  if (Skl2 == 0)
  {
    throw std::runtime_error("Math error: Attempted to divide by Zero\n");
  }
  LZespolona Wynik;
  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;
  return Wynik;
}
/*
* Funkcja realizujaca operacje sprzezenia liczby zespolonej,
*     Skl2- skladnik funkcji liczba zespolona,
* Zwraca:
*     Sprzezona liczbe zespolona.
*/

void LZespolona::Sprzezenie()
{
  this->im = -this->im;
  std::cout << this << std::endl;
}
/*
* Funkcja realizujaca zmiane liczby zespolonej na skalar,
*     Skl2- skladnik funkcji liczba zespolona,
* Zwraca:
*     Sklara liczby zespolonej.
*/

double Modul2(LZespolona Skl2)
{
  double Wynik;

  Wynik = (Skl2.re * Skl2.re) + ((Skl2.im * Skl2.im) * (-1));

  return Wynik;
}
/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool operator==(LZespolona Skl1, LZespolona Skl2)
{
  /*  if ((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
    return true;
  else
    return false;
*/
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika

  if ((std::abs(Skl1.re - Skl2.re) <= MIN_DIFF) && (std::abs(Skl1.im - Skl2.im) <= MIN_DIFF))
  {
    return true;
  }
  else
  {
    return false;
  }
}
void WczytajTenZnak(std::istream &StrmWej, char Znak)
{
  char CzytanyZnak = ' ';
  StrmWej >> CzytanyZnak;
  if (CzytanyZnak != Znak)
  {
    StrmWej.setstate(std::ios::failbit);
  }
}
std::istream &operator>>(std::istream &StrmWej, LZespolona &LZesp)
{
  //Korzystamy tutaj z tego, że jak strumień jest w stanie fail, to żadna operacja czytania już się nie wykona.
  WczytajTenZnak(StrmWej, '(');
  StrmWej >> LZesp.re;
  StrmWej >> LZesp.im;
  WczytajTenZnak(StrmWej, 'i');
  WczytajTenZnak(StrmWej, ')');
  return StrmWej;
}

std::ostream &operator<<(std::ostream &StrmWyj, LZespolona LZesp)
{
  StrmWyj.precision(2);
  StrmWyj << "(" << std::fixed << LZesp.re << std::showpos << LZesp.im << std::noshowpos << "i)";
  return StrmWyj;
}

/*!
* Reazlizuje wyswietlenie liczby zespolonej na wyjscie standardowe.
*
*/
void Wyswietl(LZespolona Skl1)
{

  std::cout << "(" << Skl1.re << std::showpos << Skl1.im << "i"
            << ")" << std::endl;
}
double arg(LZespolona Skl1)
{

  double Arg;

  if (Skl1.re > 0)
  {
    Arg = atan2(Skl1.im, Skl1.re);
  }
  else if (Skl1.re < 0)
  {
    Arg = atan2(Skl1.re, Skl1.im);
  }
  else if (Skl1.re == 0)
  {
    if (Skl1.im > 0)
    {
      Arg = PI / 2;
    }
    else if (Skl1.im < 0)
    {
      Arg = -(PI / 2);
    }
    else if (Skl1.im == 0)
    {
      Arg = 0;
    }
  }

  return Arg;
}
