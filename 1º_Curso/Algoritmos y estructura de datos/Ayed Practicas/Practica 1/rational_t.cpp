// AUTOR: 
// FECHA: 14/02/2023
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include "rational_t.hpp"

// Constructor, parametrizado
rational_t::rational_t(const double n, const double d) 
{
  assert(d != 0); // Si el denominador es 0, se aborta el programa
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
// Obtiene el numerador, devuelve el valor del numerador
double 
rational_t::get_num() const 
{
  return num_;
}



// Obtiene el denominador, devuelve el valor del denominador
double 
rational_t::get_den() const 
{
  return den_; }



// Define el numerador, no devuelve nada
void 
rational_t::set_num(const double n) 
{
  num_ = n;
}



// Define el denominador, siempre que sea distdoubleo a 0, no devuelve nada
void 
rational_t::set_den(const double d) 
{
  assert(d != 0); // Si el denominador es 0, se aborta el programa
  den_ = d;
}



// Devuelve el valor del racional como un double
double 
rational_t::value() const 
{
  return double(get_num()) / get_den();
}



// comparaciones
//Compara si dos racionales son iguales, devuelve 1 si lo son, 0 si no
bool 
rational_t::is_equal(const rational_t& r, const double precision) const 
{
  return fabs(value() - r.value()) < precision;
}



//Compara si un racional es mayor que otro, devuelve 1 si lo es, 0 si no
bool 
rational_t::is_greater(const rational_t& r, const double precision) const 
{
  return r.value() - value() > precision;
}



//Compara si un racional es menor que otro, devuelve 1 si lo es, 0 si no
bool 
rational_t::is_less(const rational_t& r, const double precision) const 
{
  return value()-r.value() > precision;
}



//Compara si un racional es igual a 0, devuelve 1 si lo es, 0 si no
bool 
rational_t::is_zero(const double precision) const 
{
  return fabs(value()) < precision;
}



// operaciones
//Suma dos racionales, devuelve el resultado
rational_t 
rational_t::add(const rational_t& r) 
{
  double num = get_num() * r.get_den() + get_den() * r.get_num();
  double den = get_den() * r.get_den();
  return rational_t(num, den);
}



//Resta dos racionales, devuelve el resultado
rational_t 
rational_t::substract(const rational_t& r) 
{
  double num = get_num() * r.get_den() - get_den() * r.get_num();
  double den = get_den() * r.get_den();
  return rational_t(num, den);
}



//Multiplica dos racionales, devuelve el resultado.
rational_t 
rational_t::multiply(const rational_t& r) 
{
  double num = get_num() * r.get_num();
  double den = get_den() * r.get_den();
  return rational_t(num, den);
}



//Divide dos racionales, devuelve el resultado
rational_t 
rational_t::divide(const rational_t& r) 
{
  double num = get_num() * r.get_den();
  double den = get_den() * r.get_num();
  return rational_t(num, den);
}




// Escribe un racional en el flujo de salida
void 
rational_t::write(ostream& os) const 
{
  os << get_num() << "/" << get_den() << "=" << value() << endl; // Escribir el racional en forma fractionaria y decimal
}



// Lee un racional desde el flujo de entrada
void 
rational_t::read(istream& is) 
{
  cout << "Numerador? ";
  is >> num_; 
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}

rational_t
rational_t::root() 
{
  double sol = sqrt(value());
  cout << "La raiz cuadrada de " << value() << " es " << sol << endl;
  return rational_t(1, sol);
}
