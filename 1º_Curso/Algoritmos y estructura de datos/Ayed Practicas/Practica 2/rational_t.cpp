// AUTOR: Álvaro Pérez Ramos
// FECHA: 04/03/2023
// EMAIL: alu0101574042@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2


#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d) // Constructor
{
  assert(d != 0); // Comprueba que el denominador no sea 0
  num_ = n, den_ = d; // Asigna el numerador y el denominador
}



inline
int
rational_t::get_num() const // Obtiene el numerador
{
  return num_;
}



inline
int
rational_t::get_den() const // Obtiene el denominador
{
  return den_;
}


  
void
rational_t::set_num(const int n) // Asigna el numerador
{
  num_ = n; // Asigna el numerador
}


  
void
rational_t::set_den(const int d) // Asigna el denominador
{
  assert(d != 0); // Comprueba que el denominador no sea 0
  den_ = d; // Asigna el denominador
}



inline
double
rational_t::value() const // Devuelve el valor del racional
{ 
  return double(get_num()) / get_den();
}



rational_t 
rational_t::opposite() const // Devuelve el racional opuesto
{ 
  return rational_t((-1)*get_num(), get_den());
}



rational_t
rational_t::reciprocal() const // Devuelve el racional reciproco
{ 
  return rational_t(get_den(), get_num()); 
}



// comparaciones
bool
rational_t::is_equal(const rational_t& r, const double precision) const // Compara si dos números racionales son iguales
{ 
  return fabs(value() - r.value()) < precision;
}



bool
rational_t::is_greater(const rational_t& r, const double precision) const // Compara si el número racional es mayor que otro
{
  return (value() - r.value()) > precision;
}



bool
rational_t::is_less(const rational_t& r, const double precision) const // Compara si el número racional es menor que otro
{
  return r.is_greater(*this, precision);
}


// operaciones
rational_t
rational_t::add(const rational_t& r) const // Sobrecarga del operador de suma
{
  return rational_t(get_num() * r.get_den() + get_den() * r.get_num(), 
                    get_den() * r.get_den()); // Suma los números racionales
}



rational_t
rational_t::substract(const rational_t& r) const // Sobrecarga del operador de resta
{
  return add(r.opposite()); // Resta los números racionales
}



rational_t
rational_t::multiply(const rational_t& r) const // Sobrecarga del operador de multiplicación
{
  return rational_t(get_num() * r.get_num(), get_den() * r.get_den()); // Multiplica los números racionales
}



rational_t
rational_t::divide(const rational_t& r) const // Sobrecarga del operador de división
{
  return multiply(r.reciprocal()); // Divide los números racionales
}


// FASE I: operadores
// Sobrecarga del operador de suma
rational_t
operator+(const rational_t& a, const rational_t& b) 
{
  return a.add(b);
}


// Sobrecarga del operador de resta
rational_t
operator-(const rational_t& a, const rational_t& b) 
{
  return a + b.opposite();
}


// Sobrecarga del operador de multiplicación
rational_t
operator*(const rational_t& a, const rational_t& b) 
{
  return a.multiply(b);
}


// Sobrecarga del operador de división
rational_t
operator/(const rational_t& a, const rational_t& b)
{
  return a.divide(b);
}



// E/S
void
rational_t::write(ostream& os) const // Escribe el número racional
{
  os << get_num() << "/" << get_den() << "=" << value() << endl; // Escribir el número racional y su valor
}



void
rational_t::read(istream& is)
{
  is >> num_ >> den_;
  assert(den_ != 0);
}


// Sobrecarga de los operadores de E/S
ostream&
operator<<(ostream& os, const rational_t& r)
{
  r.write(os);
  return os;
}

// Sobrecarga de los operadores de E/S
istream&
operator>>(istream& is, rational_t& r)
{
  r.read(is);
  return is;
}