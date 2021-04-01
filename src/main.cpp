#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"
#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#define PI 3.141592
int main(int argc, char **argv)
{
  Statystyka odp;

  if (argc < 2)
  {
    std::cout << std::endl;
    std::cout << " Brak opcji okreslajacej rodzaj testu." << std::endl;
    std::cout << " Dopuszczalne nazwy to:  latwy, trudny." << std::endl;
    std::cout << std::endl;
    return 1;
  }

  BazaTestu BazaT = {nullptr, 0, 0};
  LZespolona liczba, l1;

  std::cout << "Wartość Argumentu głównego dla kąta 45 stopni zapis liczby (1+1i) w radianach: " << PI / 4 << std::endl;
  std ::cout << "Podaj liczbe zesp" << std::endl;
  std::cin >> l1;
  std::cout << "Argument glowny: " << arg(l1) << std::endl;

  if (InicjalizujTest(&BazaT, argv[1]) == false)
  {
    std::cerr << " Inicjalizacja testu nie powiodla sie." << std::endl;
    return 1;
  }

  WyrazenieZesp WyrZ_PytanieTestowe;

  std ::cout << "Podaj liczbe zesp" << std::endl;
  std::cin >> l1;
  std::cout << "Argument glowny: " << arg(l1) << std::endl;

  try
  {

    while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe))
    {
      std::cout << ":? Podaj wynik operacji: ";
      std::cout << WyrZ_PytanieTestowe << "=" << std::endl;
      std::cin >> liczba;

      std::cout << "Twoja odpowiedz: " << liczba << std::endl;
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

  //Sprzezenie(liczba);
  DodajPoprawna(odp);
  DodajNiepoprawna(odp);

  std::cout << " Koniec testu" << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  WyswietlWyniki(odp);
}
