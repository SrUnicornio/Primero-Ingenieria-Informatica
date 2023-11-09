#include "banck-count.h"

int main() {
    Cuenta cuenta1("Juan", 20, "ES325", 1000);
    Cuenta cuenta2("Maria", 30, "ES346", 3000);
    Cuenta cuenta3("Pepe", 40, "ES1234", 2000);
    Cuenta cuenta4("Luis", 50, "ES9821", 4000);
    Cuenta cuenta5("Ana", 60, "ES12345689", 5000);
    Cuenta cuenta6("Jose", 70, "ES987654321", 6000);
    Cuenta cuenta7("Rosa", 80, "ES3454", 7000);
    Cuenta cuenta8("Lola", 90, "ES9321", 8000);
    Cuenta cuenta9("Paco", 100, "ES21352", 9000);
    Cuenta cuenta10("Lola", 110, "ES215436", 10000);
    std::vector<Cuenta> cuentas;
    cuentas.push_back(cuenta1);
    cuentas.push_back(cuenta2);
    cuentas.push_back(cuenta3);
    cuentas.push_back(cuenta4);
    cuentas.push_back(cuenta5);
    cuentas.push_back(cuenta6);
    cuentas.push_back(cuenta7);
    cuentas.push_back(cuenta8);
    cuentas.push_back(cuenta9);
    cuentas.push_back(cuenta10);
    int opcion;
    std::string name;
    int age;
    double amount;
    double balance;
    do {
        std::cout << "1. Mostrar informacion de la cuenta por el nombre del titular" << std::endl;
        std::cout << "2. Hacer un ingreso solicitando el nombre de usuario" << std::endl;
        std::cout << "3. Hacer un retiro solicitando el nombre de usuario" << std::endl;
        std::cout << "4. Hacer media de los saldos introducidos" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Introduzca una opcion: ";
        std::cin >> opcion;
        switch (opcion) {
            case 1:
                std::cout << "Introduzca el nombre: ";
                std::cin >> name;
                for (int i = 0; i < cuentas.size(); i++) {
                        cuentas[i].print(name);
                }
                break;
            case 2:
                std::cout << "Introduzca el nombre: ";
                std::cin >> name;
                std::cout << "Introduzca la cantidad: ";
                std::cin >> amount;
                for (int i = 0; i < cuentas.size(); i++) {
                        cuentas[i].Ingreso(name, amount);
                }
                break;
            case 3:
                std::cout << "Introduzca el nombre: ";
                std::cin >> name;
                std::cout << "Introduzca la cantidad: ";
                std::cin >> amount;
                for (int i = 0; i < cuentas.size(); i++) {
                        cuentas[i].Retiro(name, amount);
                    }
                break;
            case 4:
                std::cout << "Introduzca el saldo: ";
                std::cin >> balance;
                cuenta1.Media(balance);
                break;
            case 5:
                cuenta1.Salir();
                break;
            default:
                std::cout << "Opcion no valida" << std::endl;
                break;
        }
    } while (opcion != 5);
    return 0;
}