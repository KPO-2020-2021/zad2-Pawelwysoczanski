#include "Statystyki.hh"
#include "BazaTestu.hh"

/*
*Funkcja odpowiadajaca za zliczanie dobrych odpowiedzi uzytkownika
*/
void DodajPoprawna(Statystyka &odp)
{
    odp.poprawna++;
}
/*
*Funkcja odpowiadajac za zliczanie blednych odpowiedzi uzytkownika
*/
void DodajNiepoprawna(Statystyka &odp)
{
    odp.niepoprawna++;
}
/*
*Funkcja odpowiadajaca za wyliczenie wyniku procentowego
*/
double Wykonaj(Statystyka &odp)
{
    Statystyka Wynik;
    Wynik.procent = odp.poprawna / (odp.poprawna + odp.niepoprawna);

    return Wynik.procent;
}
/*
*Funkcja odpowiadajaca za wyswietlenie podsumowania sprawdzianu
*/
void WyswietlWyniki(Statystyka odp)
{

    double Wynik = Wykonaj(odp);
    std::cout << "Ilosc dobrych odpowiedzi: " << odp.poprawna << std::endl;
    std::cout << "Ilosc blednych odpowiedzi: " << odp.niepoprawna << std::endl;
    std::cout << "Wynik w procentach: " << Wynik << "%" << std::endl;

}
void Inicjalizuj(Statystyka odp)
{

    odp.poprawna = 0;
    odp.niepoprawna = 0;
}
