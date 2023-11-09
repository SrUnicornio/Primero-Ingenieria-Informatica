
#include <iostream>
#include <string>
#include "Circulo.h"

int main()
{
    Circulo c1(1, 2, 3, Circulo::Color::Rojo);
    Circulo c2(4, 5, 6, Circulo::Color::Verde);
    Circulo c3(7, 8, 9, Circulo::Color::Azul);

    c1.Show(1);
    c2.Show(2);
    c3.Show(3);

    c1.Area(1);
    c2.Area(2);
    c3.Area(3);

    c1.Perimetro(1);
    c2.Perimetro(2);
    c3.Perimetro(3);

    c1.Print(1);
    c2.Print(2);
    c3.Print(3);

    c1.IsInterior(1, 2);
    c2.IsInterior(4, 5);
    c3.IsInterior(0, 0);

    return 0;
}