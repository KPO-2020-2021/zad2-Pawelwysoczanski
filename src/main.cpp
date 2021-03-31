#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"
#include "WyrazenieZesp.hh"
#include "LZespolona.hh"

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

  if (InicjalizujTest(&BazaT, argv[1]) == false)
  {
    std::cerr << " Inicjalizacja testu nie powiodla sie." << std::endl;
    return 1;
  }

  std::cout << std::endl;
  std::cout << " Start testu arytmetyki zespolonej: " << argv[1] << std::endl;
  std::cout << std::endl;

  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona liczba;
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
  Statystyka WyswietlWyniki(odp);

  Statystyka Inicjalizuj(odp);

  std::cout << "ilosc pop: " << odp.poprawna << std::endl;
  std::cout << "ilosc npop: " << odp.niepoprawna << std::endl;

  std::cout << " Koniec testu" << std::endl;
  std::cout << std::endl;
}
