#include "Complejo.h"

/*
 * @brief constructor por defecto
 */
Complejo::Complejo() {}

/*
 * @brief constructor con parametros
 */

Complejo::Complejo(double real, double imaginario) : real_{real}, imaginario_{imaginario} {}

/*
 * @brief metodo para sumar dos numeros complejos
 */

Complejo Complejo::operator+(const Complejo& complejo) const {
    double real = real_ + complejo.real_;
    double imaginario = imaginario_ + complejo.imaginario_;
    Complejo suma(real, imaginario);
    return suma;
}

/*
 * @brief metodo para restar dos numeros complejos
 */

Complejo Complejo::operator-(const Complejo& complejo) const {
    double real = real_ - complejo.real_;
    double imaginario = imaginario_ - complejo.imaginario_;
    Complejo resta(real, imaginario);
    return resta;
}

/*
 * @brief metodo para multiplicar dos numeros complejos
 */

Complejo Complejo::operator*(const Complejo& complejo) const {
    double real = (real_ * complejo.real_) - (imaginario_ * complejo.imaginario_);
    double imaginario = (real_ * complejo.imaginario_) + (imaginario_ * complejo.real_);
    Complejo multiplicacion(real, imaginario);
    return multiplicacion;
}

/*
 * @brief metodo para dividir dos numeros complejos
 */

Complejo Complejo::operator/(const Complejo& complejo) const {
    double real = ((real_ * complejo.real_) + (imaginario_ * complejo.imaginario_)) / (pow(complejo.real_, 2) + pow(complejo.imaginario_, 2));
    double imaginario = ((imaginario_ * complejo.real_) - (real_ * complejo.imaginario_)) / (pow(complejo.real_, 2) + pow(complejo.imaginario_, 2));
    Complejo division(real, imaginario);
    return division;
}