#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Complejo {
 public:
  Complejo();
  Complejo(const double real, const double imaginario);
  double real() const { return real_; }
  double imaginario() const { return imaginario_; }
  Complejo operator+(const Complejo& complejo) const;
  Complejo operator-(const Complejo& complejo) const;
  Complejo operator*(const Complejo& complejo) const;
  Complejo operator/(const Complejo& complejo) const;
  friend ostream& operator<<(ostream& os, const Complejo& complejo);
  friend istream& operator>>(istream& is, Complejo& complejo);
 private:
  double real_{0};
  double imaginario_{0};
};

#endif