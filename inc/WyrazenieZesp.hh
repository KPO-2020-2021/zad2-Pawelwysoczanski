#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include "LZespolona.hh"

/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator
{
  Op_Dodaj,
  Op_Odejmij,
  Op_Mnoz,
  Op_Dziel
};

/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp
{
  LZespolona Arg1; // Pierwszy argument wyrazenia arytmetycznego
  Operator Op;     // Opertor wyrazenia arytmetycznego
  LZespolona Arg2; // Drugi argument wyrazenia arytmetycznego
  void Wyswietl();
  LZespolona Oblicz();
  WyrazenieZesp WczytajWyrz();
};

std::istream &operator>>(std::istream &StrmWej, WyrazenieZesp Skl1);
std::ostream &operator<<(std::ostream &StrmWyj, WyrazenieZesp Skl1);
#endif
