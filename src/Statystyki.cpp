#include "Statystyki.hh"
#include "BazaTestu.hh"

/*
*Funkcja odpowiadajaca za zliczanie dobrych odpowiedzi uzytkownika
*/
void Statystyka::DodajPoprawna()
{
    poprawna++;
}
/*
*Funkcja odpowiadajac za zliczanie blednych odpowiedzi uzytkownika
*/
void Statystyka::DodajNiepoprawna()
{
    niepoprawna++;
}
/*
*Funkcja odpowiadajaca za wyliczenie wyniku procentowego
*/
double Statystyka::Wykonaj()
{

    procent = ((double)poprawna / ((double)poprawna + (double)niepoprawna) * 100);

    return procent;
}
/*
*Funkcja odpowiadajaca za wyswietlenie podsumowania sprawdzianu
*/
void Statystyka::WyswietlWyniki()
{

    double Wynik = Wykonaj();
    std::cout << "Ilosc dobrych odpowiedzi: " << poprawna << std::endl;
    std::cout << "Ilosc blednych odpowiedzi: " << niepoprawna << std::endl;
    std::cout << "Wynik procentowy poprawnych odpowiedzi: " << Wynik << "%" << std::endl;
}
