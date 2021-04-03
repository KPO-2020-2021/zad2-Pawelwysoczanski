#include "LZespolona.hh"

#define MIN_DIFF 0.0001
#define PI 3.141592
/****************************************************************
*                       Modul LZespolona                        *
*Kolejnosc wystepowania przeciazen i metod zapisanychw kodzie:  *
*Operator + linia:34                                            * 
*Operator += linia:46                                           *
*Operator - linia:62                                            *
*Operator * linia:79                                            * 
*Operator / linia:98                                            *   
*Operator /= linia:113                                          *
*Operator / przez skalar linia:134                              *
*Operator /= przez skalar linia:146                             *
*Sprzezenie() linia:164                                         * 
*Modul2() linia:177                                             *
*Operator == linia:194                                          *
*WczytajTenZnak() linia:212                                     *
*Operator >> linia:221                                          *
*Operator << linia:232                                          *
*Wyswietl() linia:243                                           *
*arg()  linia:243 252                                           *
*****************************************************************/

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator+(LZespolona Skl1)
{

  LZespolona Wynik;

  Wynik.re = Skl1.re + this->re;
  Wynik.im = Skl1.im + this->im;
  return Wynik;
}
/*
*Modyfikacja przeciazenia operatora dodawnia
*/
LZespolona LZespolona::operator+=(LZespolona Skl1)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re + this->re;
  Wynik.im = Skl1.im + this->im;
  return Wynik;
}
/*!
 * Realizuje odjecie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator-(LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = this->re - Skl2.re;
  Wynik.im = this->im - Skl2.im;

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
LZespolona LZespolona::operator*(LZespolona Skl1)
{
  LZespolona Wynik;

  Wynik.re = (Skl1.re * this->re) + ((Skl1.im * this->im) * (-1));
  Wynik.im = (Skl1.im * this->re) + (Skl1.re * this->im);

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
LZespolona LZespolona::operator/(LZespolona Skl2)
{
  LZespolona Wynik, licznik;
  double mianownik;

  licznik = *this * Skl2.Sprzezenie();
  mianownik = Skl2.modul2();

  Wynik = licznik / mianownik;

  return Wynik;
}
/*
*Modyfikacaj pzreciazenia opeartora dzielenia
*/
LZespolona LZespolona::operator/=(LZespolona Skl2)
{
  LZespolona Wynik, licznik;
  double mianownik;

  licznik = *this * Skl2.Sprzezenie();
  mianownik = Skl2.modul2();

  Wynik = licznik / mianownik;

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

LZespolona LZespolona::operator/(double Skl2)
{
  if (Skl2 == 0)
  {
    throw std::runtime_error("Math error: Attempted to divide by Zero\n");
  }
  LZespolona Wynik;
  Wynik.re = this->re / Skl2;
  Wynik.im = this->im / Skl2;
  return Wynik;
}

LZespolona LZespolona::operator/=(double Skl2)
{
  if (Skl2 == 0)
  {
    throw std::runtime_error("Math error: Attempted to divide by Zero\n");
  }
  LZespolona Wynik;
  Wynik.re = this->re / Skl2;
  Wynik.im = this->im / Skl2;
  return Wynik;
}
/*
* Funkcja realizujaca operacje sprzezenia liczby zespolonej,
*     Skl2- skladnik funkcji liczba zespolona,
* Zwraca:
*     Sprzezona liczbe zespolona.
*/

LZespolona LZespolona::Sprzezenie()
{
  this->im = -this->im;

  return *this;
}
/*
* Funkcja realizujaca zmiane liczby zespolonej na skalar,
*     Skl2- skladnik funkcji liczba zespolona,
* Zwraca:
*     Sklara liczby zespolonej.
*/

double LZespolona::modul2()
{
  double Wynik;

  Wynik = (this->re * this->re) + ((this->im * this->im));

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
void LZespolona::Wyswietl()
{

  std::cout << "(" << re << std::showpos << im << "i"
            << ")" << std::endl;
}
/*
*Funkcja odczytujaca wartosc Argumentu glownego z liczby zespolonej
*/
double LZespolona::arg()
{

  double Arg;

  if (re > 0)
  {
    Arg = atan2(im, re);
  }
  else if (re < 0)
  {
    Arg = atan2(re, im);
  }
  else if (re == 0)
  {
    if (im > 0)
    {
      Arg = PI / 2;
    }
    else if (im < 0)
    {
      Arg = -(PI / 2);
    }
    else if (im == 0)
    {
      Arg = 0;
    }
  }

  return Arg;
}
