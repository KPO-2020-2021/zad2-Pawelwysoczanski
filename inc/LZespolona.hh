#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
#include <cmath>
#include <stdexcept>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */

/*!
 * Modeluje pojecie liczby zespolonej
 */
struct LZespolona
{
  double re; /*! Pole repezentuje czesc rzeczywista. */
  double im; /*! Pole repezentuje czesc urojona. */

  void Sprzezenie(); /*Fukcja tworzaca sprzezenie liczby zespolonej*/
};
/*
*  Przeciazenia operatorow arytmetycznych
*/

double arg(LZespolona Skl1);

LZespolona operator += (LZespolona Skl1, LZespolona Skl2);

LZespolona operator+(LZespolona Skl1, LZespolona Skl2); /*opearcja dodania dwoczh liczb zespolonych*/

LZespolona operator/(LZespolona Skl1, double Skl2); /* operacja dzielenia liczby zespolonej przez skalar*/

LZespolona operator-(LZespolona Skl1, LZespolona Skl2); /*operacja odjecia dwoch liczb zespolonych*/

LZespolona operator/(LZespolona Skl1, LZespolona Skl2); /*operacja dzielenia dwoch liczb zespolonych*/

LZespolona operator*(LZespolona Skl1, LZespolona Skl2); /* operacje mnozenia dwoch liczb zespolonych*/

LZespolona operator/=(LZespolona Skl1, LZespolona Skl2);

LZespolona operator/=(LZespolona Skl1, double Skl2);
/*
*
*/

void Sprzezenie(LZespolona &Skl2); /*Fukcja tworzaca sprzezenie liczby zespolonej*/

std::istream &operator>>(std::istream &StrmWej, LZespolona &LZesp); /*Funkcja przeciazenia operatora przesuniecia bitowego w prawo*/

std::ostream &operator<<(std::ostream &StrmWyj, LZespolona LZesp); /*Funkcja przeciazenia operatora przesuniecia bitowego w lewo*/

bool operator==(LZespolona Skl1, LZespolona Skl2); /*Funkja porownujaca dwie liczby zespolone*/

void Wyswietl(LZespolona Skl1); /*Funkcja wyswietlajaca liczbe zespolona*/

void WczytajTenZnak(std::istream &StrmWej, char Znak); /**/

double modul2(LZespolona Skl2); /*Funkcja tworzaca modul w postaci skalarnej z liczby zespolonej podniesiony do kwadratu*/

#endif
