#include <iostream>

#include "Point2D.h"

int main() {
    Point2D p1(5, 1);
    Point2D p2(2, 0);
    p1.Show(1);
    p2.Show(2);
    p1.Move(5, 6);
    p1.Show(1);
    std::cout << "La distancia entre los puntos es: " << p1.Distance(p2) << std::endl;
    Point2D p3 = p1.Middle(p2);
    p3.Show(3);
    return 0;
}
