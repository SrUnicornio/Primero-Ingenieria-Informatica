#include <iostream>
#include <string>

#ifndef Circulo_H
#define Circulo_H
class Circulo {
    public:
        enum class Color {Rojo, Verde, Azul};
        Circulo();
        Circulo(double x, double y, double r, Color c);
        void Show(int a);
        void Area(int a);
        void Perimetro(int a);
        void Print(int a);
        void IsInterior(double x, double y);
    private:
        double x_;
        double y_;
        double r_;
        Color c_;
};

#endif