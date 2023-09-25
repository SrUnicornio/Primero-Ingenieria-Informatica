#include <iostream>
#include <string>
#include <vector>

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

class Cuenta {
  public:
    Cuenta(std::string name, int age, std::string number_account, double balance);
    void print(std::string name);
    void Ingreso(std::string name, double amount);
    void Retiro(std::string name, double amount);
    void Media(double balance);
    void Salir();
  private:
      std::string name;
      std::string number_account;
      int age;
      std::string type_account;
      double balance;
};

#endif
/*
 *@breif: Constructor de la clase Cuenta
 *@param name: Nombre del titular de la cuenta
 *@param age: Edad del titular de la cuenta
 *@param number_account: Numero de cuenta
 *@param balance: Saldo de la cuenta
 */
Cuenta::Cuenta(std::string name, int age, std::string number_account, double balance) {
    this->name = name;
    this->age = age;
    this->number_account = number_account;
    this->balance = balance;
    this -> type_account = (age < 26) ? "Cuenta joven" : "Cuenta normal";
}

/* 
 *@breif: Imprime la informacion de la cuenta
 *@param name: Nombre del titular de la cuenta
 */
void Cuenta::print(std::string name) {
    std::cout << "Nombre: " << name << std::endl;
    std::cout << "Edad: " << age << std::endl;
    std::cout << "Numero de cuenta: " << number_account << std::endl;
    std::cout << "Saldo: " << balance << std::endl;
}

/* 
 *@breif: Ingresa dinero en la cuenta
 *@param name: Nombre del titular de la cuenta
 *@param amount: Cantidad de dinero a ingresar
 */
void Cuenta::Ingreso(std::string name, double amount) {
    if (name == this->name) {
        this->balance += amount;
    }
}

/* 
 *@breif: Retira dinero de la cuenta
 *@param name: Nombre del titular de la cuenta
 *@param amount: Cantidad de dinero a retirar
 */
void Cuenta::Retiro(std::string name, double amount) {
    if (name == this->name) {
        this->balance -= amount;
    }
}

/* 
 *@breif: Calcula la media de los saldos de las cuentas
 *@param balance: Saldo de la cuenta
 */
void Cuenta::Media(double balance) {
    std::vector<double> balances;
    balances.push_back(balance);
    double sum = 0;
    for (int i = 0; i < balances.size(); i++) {
        sum += balances[i];
    }
    std::cout << "La media de los saldos es: " << sum / balances.size() << std::endl;
}

/* 
 *@breif: Mensaje de despedida
 */
void Cuenta::Salir() {
    std::cout << "Gracias por usar el programa" << std::endl;
}