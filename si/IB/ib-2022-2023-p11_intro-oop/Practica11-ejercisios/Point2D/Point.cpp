
#include <iostream>
#include <string>
#include <cmath>

#include "Point2D.h"

/*
 * @brief constructor por defecto
 */

Point2D::Point2D() : x_{0}, y_{0} {
    std::cout << "DEBUG: Constructor Point2D por DEFECTO ejecutado" << std::endl;

}

/*
 * @brief constructor con parametros
 */

Point2D::Point2D(double x, double y) : x_{x}, y_{y} {
    std::cout << "DEBUG: Constructor Point2D con PARAMETROS ejecutado" << std::endl;
}

/*
 * @brief metodo para mostrar las coordenadas del punto
 */

void Point2D::Show(int a) {
    std::cout << "Las coordenadas del punto" << a << " son: (" << x_ << ", " << y_ << ")" << std::endl;    
}

/*
 * @brief metodo para mover las coordenadas del punto
 */

void Point2D::Move(double x, double y) {
    x_ = x;
    y_ = y;

    std::cout << "Las coordenadas del punto han sido cambiadas a: (" << x_ << ", " << y_ << ")" << std::endl;
}

/*
 * @brief metodo para calcular la distancia entre dos puntos
 */

double Point2D::Distance(Point2D p) {
    double distance = sqrt(pow((p.x_ - x_), 2) + pow((p.y_ - y_), 2));
    return distance;
}

/*
 * @brief metodo para calcular el punto medio entre dos puntos
 */

Point2D Point2D::Middle(Point2D p) {
    double x = (p.x_ + x_) / 2;
    double y = (p.y_ + y_) / 2;
    Point2D middle(x, y);
    return middle;
}
