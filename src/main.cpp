#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"
#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#define PI 3.141592
int main(int argc, char **argv)
{
  Statystyka odp;
  LZespolona liczba;

  if (argc < 2)
  {
    std::cout << std::endl;
    std::cout << " Brak opcji okreslajacej rodzaj testu." << std::endl;
    std::cout << " Dopuszczalne nazwy to:  latwy, trudny." << std::endl;
    std::cout << std::endl;
    return 1;
  }

  std::cout << std::endl;
  std::cout << "Sprawdzian liczb zespolonych" << std::endl;
  std::cout << std::endl;

  BazaTestu BazaT = {nullptr, 0, 0};

  if (InicjalizujTest(&BazaT, argv[1]) == false)
  {
    std::cerr << " Inicjalizacja testu nie powiodla sie." << std::endl;
    return 1;
  }

  WyrazenieZesp WyrZ_PytanieTestowe;

  try
  {

    while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe))
    {
      std::cout << ":? Podaj wynik operacji: ";
      std::cout << WyrZ_PytanieTestowe << "=" << std::endl;

      for (int i = 0; i < 3; i++) /*Petla odpowiadajaca za mozliwosc ponownego wprowadzenia odpowiedzi*/
      {

        std::cin >> liczba;

        if (std::cin.fail()) /*Sprawdzenie poprawnosci zapisu liczby zespolonej*/
        {
          std::cout << std::endl;
          std::cout << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz" << std::endl;
          std::cout << std::endl;

          std::cin.clear();
          std::cin.ignore();
        }
        else
          break;
      }
      if (liczba == WyrZ_PytanieTestowe.Oblicz()) /*Jesli odpowiedz poprawna*/
      {
        std::cout << "Twoja odpowiedz: " << liczba << std::endl;
        std::cout << ":) Odpowiedz poprwana" << std::endl;
        std::cout << std::endl;

        odp.DodajPoprawna();

        std::cin.clear();
      }
      else /*Jesli odpowiedz bledna */
      {
        std::cout << "Twoja odpowiedz: " << liczba << std::endl;
        std::cout << ":( Blad. Prawdidlowym wynikiem jest: " << WyrZ_PytanieTestowe.Oblicz() << std::endl;
        std::cout << std::endl;

        odp.DodajNiepoprawna();

        std::cin.clear();
      }
    }
  }
  catch (std::runtime_error &e)
  {

    // prints that exception has occurred
    // calls the what function
    // using runtime_error object
    std::cout << "Exception occurred" << std::endl
              << e.what();
  }

  std::cout << " Koniec testu." << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  odp.WyswietlWyniki(); /*Wyswietlenie podsumowania*/

  LZespolona argglow;

  std::cout << std::endl;
  std::cout << "Podaj liczbe zespolona dla ktorej chcesz otrzymac Argument glowny" << std::endl;
  std::cin >> argglow;
  std::cout << "Argument glowny: " << argglow.arg() << std::endl;
}
