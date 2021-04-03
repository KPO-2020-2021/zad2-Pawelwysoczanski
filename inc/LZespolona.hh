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

  LZespolona operator+(LZespolona Skl1); /*opearcja dodania dwoczh liczb zespolonych*/

  LZespolona operator+=(LZespolona Skl1);

  LZespolona operator-(LZespolona Skl1); /*operacja odjecia dwoch liczb zespolonych*/

  LZespolona operator*(LZespolona Skl1); /* operacje mnozenia dwoch liczb zespolonych*/

  LZespolona operator/(double Skl2); /* operacja dzielenia liczby zespolonej przez skalar*/

  LZespolona operator/(LZespolona Skl1); /*operacja dzielenia dwoch liczb zespolonych*/

  LZespolona operator/=(LZespolona Skl1); /*operacja dzielenia dwoch liczb zespolonych*/

  LZespolona operator/=(double Skl2);/* operacja dzielenia liczby zespolonej przez skalar*/

  double modul2(); /*Funkcja tworzaca modul w postaci skalarnej z liczby zespolonej podniesiony do kwadratu*/

    LZespolona Sprzezenie(); /*Fukcja tworzaca sprzezenie liczby zespolonej*/

  void Wyswietl();/*Funkcja wyswietlajaca liczbe zespolona*/

  double arg();/*Funkcja odczytujaca wartosc Argumentu glownego liczby zespolonej*/
};

std::istream &operator>>(std::istream &StrmWej, LZespolona &Lzesp); /*Funkcja przeciazenia operatora przesuniecia bitowego w prawo*/

std::ostream &operator<<(std::ostream &StrmWyj, LZespolona Lzesp); /*Funkcja przeciazenia operatora przesuniecia bitowego w lewo*/

void WczytajTenZnak(std::istream &StrmWej, char Znak); /**/

bool operator==(LZespolona Skl1, LZespolona Skl2); /*Funkja porownujaca dwie liczby zespolone*/
#endif
