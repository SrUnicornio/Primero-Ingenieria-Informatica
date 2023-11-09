#ifndef POINT2D_H
#define POINT2D_H

class Point2D {
    public:
        Point2D();
        Point2D(double x, double y);
        void Show(int a);
        void Move(double x, double y);
        double Distance(Point2D p);
        Point2D Middle(Point2D p);
    private:
        double x_;
        double y_;
};

#endif
