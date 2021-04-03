#include <cstring>
#include <ios>
#include "WyrazenieZesp.hh"
#include "LZespolona.hh"

// WyrazenieZesp WyrazenieZesp::WczytajWyrz()
// {

//     WyrazenieZesp Wyrz;

//     std::cout << std::endl;
//     std::cin >> Wyrz.Arg1;
//     std::cin >> Wyrz.Op;
//     std::cin >> Wyrz.Arg2;
// }

LZespolona WyrazenieZesp::Oblicz()
{
    LZespolona Wynik;

    switch (this->Op)
    {
    case Op_Dodaj:
        Wynik = this->Arg1 + this->Arg2;
        break;
    case Op_Odejmij:
        Wynik = this->Arg1 - this->Arg2;
        break;
    case Op_Mnoz:
        Wynik = this->Arg1 * this->Arg2;
        break;
    case Op_Dziel:
        Wynik = this->Arg1 / this->Arg2;
        break;
    default:
        break;
    }
    return Wynik;
}

void WyrazenieZesp::Wyswietl()
{
    std::cout << "(" << Arg1 << Op << Arg2 << "i"
              << ")";
}

std::ostream &operator<<(std::ostream &StrmWyj, WyrazenieZesp Skl1)
{
    StrmWyj << Skl1.Arg1;
    switch (Skl1.Op)
    {
    case Op_Dodaj:
        StrmWyj << '+';
        break;
    case Op_Odejmij:
        StrmWyj << '-';
        break;
    case Op_Mnoz:
        StrmWyj << '*';
        break;
    case Op_Dziel:
        StrmWyj << '/';
        break;
    default:
        break;
    }
    StrmWyj << Skl1.Arg2;

    return StrmWyj;
}
std::istream &operator>>(std::istream &StrmWej, WyrazenieZesp Wyrz)
{
    char oper;
    StrmWej >> Wyrz.Arg1;
    StrmWej >> oper;
    switch (oper)
    {
    case '+':
        Wyrz.Op = Op_Dodaj;
        break;
    case '-':
        Wyrz.Op = Op_Odejmij;
        break;
    case '*':
        Wyrz.Op = Op_Mnoz;
        break;
    case '/':
        Wyrz.Op = Op_Dziel;
        break;
    default:
        break;
    }
    StrmWej >> Wyrz.Arg2;
    return StrmWej;
}
