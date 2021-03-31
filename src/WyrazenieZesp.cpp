#include <cstring>
#include <ios>
#include "WyrazenieZesp.hh"
#include "LZespolona.hh"

// WyrazenieZesp WcztajWyrz(WyrazenieZesp Wyrz)
// {
//     std::cout << std::endl;
//     std::cin >> Wyrz.Arg1;
//     std::cin >> Wyrz.Op;
//     std::cin >> Wyrz.Arg2;
// }

LZespolona Oblicz(WyrazenieZesp Wyrz)
{
    LZespolona Wynik;

    switch (Wyrz.Op)
    {
    case Op_Dodaj:
        Wynik = Wyrz.Arg1 + Wyrz.Arg2;
        break;
    case Op_Odejmij:
        Wynik = Wyrz.Arg1 - Wyrz.Arg2;
        break;
    case Op_Mnoz:
        Wynik = Wyrz.Arg1 * Wyrz.Arg2;
        break;
    case Op_Dziel:
        Wynik = Wyrz.Arg1 / Wyrz.Arg2;
        break;
    default:
        break;
    }
    return Wynik;
}

void Wyswietl(WyrazenieZesp Wyrz)
{
    std::cout << "(" << Wyrz.Arg1 << Wyrz.Op << Wyrz.Arg2 << "i"
              << ")";
}

// std::istream &operator>>(std::istream &StrmWej, Operator &WczytSym)
// {
//     Operator TabTypOp[] = {Op_Dodaj, Op_Odejmij, Op_Dziel, Op_Mnoz};
//     const char TabSymOp[] = "+-/*", *wSymOp;
//     char CzytSymOp = 'x';

//     StrmWej >> CzytSymOp;
//     if ((wSymOp = strchr(wSymOp, CzytSymOp)) == nullptr)
//     {
//         StrmWej.setstate(std::ios::failbit);
//     }
//     else
//     {
//         WczytSym = TabTypOp[wSymOp - TabSymOp];
//     }
//     return StrmWej;
// }

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

std::istream &operator>>(std::istream &stream, WyrazenieZesp &Skl1)
{
    char oper;
    stream >> Skl1.Arg1;
    stream >> oper;
    switch (oper)
    {
    case '+':
        Skl1.Op = Op_Dodaj;
        break;
    case '-':
        Skl1.Op = Op_Odejmij;
        break;
    case '*':
        Skl1.Op = Op_Mnoz;
        break;
    case '/':
        Skl1.Op = Op_Dziel;
        break;
    default:
        break;
    }
    stream >> Skl1.Arg2;
    return stream;
}
