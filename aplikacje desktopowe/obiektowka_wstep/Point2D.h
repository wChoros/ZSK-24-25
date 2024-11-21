#ifndef POINT2D_H
#define POINT2D_H

class Point2D {
private:
    float x, y;
    int *a;

public:
    // default constructor
    Point2D();

    // constructor with parameters
    Point2D(float x, float y);

    Point2D(const Point2D &p);

    // setters
    void setX(float x);

    void setY(float y);

    // getters
    float getX() const;

    float getY() const;
};

#endif //POINT2D_H
