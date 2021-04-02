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
    int poprawna = 0;    /*Ilosc poprawnych odpowiedzi*/
    int niepoprawna = 0; /*Ilosc niepoprawnych odpowiedzi*/
    double procent;

    void DodajPoprawna();    /*Funkcja zliczajaca ilosc poprawnych odpowiedzi*/
    
    void DodajNiepoprawna(); /*Funkcja zliczajaca ilosc blednych odpowiedzi*/
    
    double Wykonaj();        /*Funkcja wykonujaca podsumowanie poprze wyliczenie wyniku procentowego odpowiedzi poprawnych do sumy mozliwych */
    
    void WyswietlWyniki();   /*Funkcja wyswietlajaca podsumowanie*/
};

#endif
