#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH

#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

/*
 * Modeluje pojecie Statystyka zawierajacej ilosc poprawnych
 * i blednych odpowiedzi jednoczesnie wyciagajac wynik procentowy 
 * testu
 */
struct Statystyka
{
    int poprawna;    /*Ilosc poprawnych odpowiedzi*/
    int niepoprawna; /*Ilosc niepoprawnych odpowiedzi*/
    double procent;
};

void DodajPoprawna(Statystyka &odp);    /*Funkcja zliczajaca ilosc poprawnych odpowiedzi*/
void DodajNiepoprawna(Statystyka &odp); /*Funkcja zliczajaca ilosc blednych odpowiedzi*/
void Wykonaj();                         /*Funkcja wykonujaca podsumowanie poprze wyliczenie wyniku procentowego odpowiedzi poprawnych do sumy mozliwych */
void WyswietlWyniki(Statystyka odp);   /*Funkcja wyswietlajaca podsumowanie*/
void Inicjalizuj(Statystyka odp);
std::ostream &operator<<(std::ostream StrmWyj, Statystyka odp);

#endif
