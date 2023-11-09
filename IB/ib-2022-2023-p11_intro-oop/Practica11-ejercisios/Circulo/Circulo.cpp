#include <iostream>
#include <string>
#include <cmath>
#include "Circulo.h"

/*
 * @brief constructor por defecto
 */

Circulo::Circulo() : x_{0}, y_{0}, r_{0}, c_{Color::Rojo} {
    std::cout << "DEBUG: Constructor Circulo por DEFECTO ejecutado" << std::endl;
}

/*
 * @brief constructor con parametros
 */

Circulo::Circulo(double x, double y, double r, Color c) : x_{x}, y_{y}, r_{r}, c_{c} {
    std::cout << "DEBUG: Constructor Circulo con PARAMETROS ejecutado" << std::endl;
}

/*
 * @brief metodo para mostrar las coordenadas del punto
 */

void Circulo::Show(int a) {
    std::cout << "El circulo " << a << " tiene las coordenadas: (" << x_ << ", " << y_ << ")" << std::endl;
}

/*
 * @brief metodo para calcular el area del circulo
 */

void Circulo::Area(int a) {
    double area = M_PI * pow(r_, 2);
    std::cout << "El area del circulo " << a << " es: " << area << std::endl;
}

/*
 * @brief metodo para calcular el perimetro del circulo
 */

void Circulo::Perimetro(int a) {
    double perimetro = 2 * M_PI * r_;
    std::cout << "El perimetro del circulo " << a << " es: " << perimetro << std::endl;
}

/*
 * @brief metodo para imprimir el color del circulo
 */

void Circulo::Print(int a) {
    switch (c_) {
        case Color::Rojo:
            std::cout << "El color del circulo " << a << " es: Rojo" << std::endl;
            break;
        case Color::Verde:
            std::cout << "El color del circulo " << a << " es: Verde" << std::endl;
            break;
        case Color::Azul:
            std::cout << "El color del circulo " << a << " es: Azul" << std::endl;
            break;
    }
}

/*
 * @brief metodo para comprobar si un punto esta dentro del circulo
 */

void Circulo::IsInterior(double x, double y) {
    double distancia = sqrt(pow(x - x_, 2) + pow(y - y_, 2));
    if (distancia <= r_) {
        std::cout << "El punto (" << x << ", " << y << ") esta dentro del circulo" << std::endl;
    } else {
        std::cout << "El punto (" << x << ", " << y << ") esta fuera del circulo" << std::endl;
    }
}