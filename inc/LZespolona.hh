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
};

bool operator==(LZespolona Skl1, LZespolona Skl2); /*Funkja porownujaca dwie liczby zespolone*/

LZespolona operator+(LZespolona Skl1, LZespolona Skl2); /*Funkcja dodajaca dwie liczby zespolone*/

LZespolona operator/(LZespolona Skl1, double Skl2); /*Funkcja wykonujaca operacje dzielenia liczby zespolonej przez skalar*/

void WczytajTenZnak(std::istream &StrmWej, char Znak); /**/

LZespolona operator-(LZespolona Skl1, LZespolona Skl2); /*Funkcja odjemujaca dwie liczby zespolone*/

LZespolona operator/(LZespolona Skl1, LZespolona Skl2);/*Funkcja wykonujaca operacje dzielenia dwoch liczb zespolonych*/

LZespolona operator*(LZespolona Skl1, LZespolona Skl2); /*Funkcja wykonujaca operacje mnozenia dwoch liczb zespolonych*/

LZespolona Sprzezenie(LZespolona Skl2); /*Fukcja tworzaca sprzezenie liczby zespolonej*/

double modul2(LZespolona Skl2); /*Funkcja tworzaca modul w postaci skalarnej z liczby zespolonej podniesiony do kwadratu*/

std::istream &operator>>(std::istream &StrmWej, LZespolona &LZesp); /*Funkcja przeciazenia operatora przesuniecia bitowego w prawo*/

std::ostream &operator<<(std::ostream &StrmWyj, LZespolona LZesp); /*Funkcja przeciazenia operatora przesuniecia bitowego w lewo*/

void Wyswietl(LZespolona Skl1); /*Funkcja wyswietlajaca liczbe zespolona*/

#endif
