#include "Point2D.h"
#include <iostream>

Point2D::Point2D() {
    x = 0;
    y = 0;
}

Point2D::Point2D(const float x, const float y) {
    this->x = x;
    this->y = y;
}

Point2D::Point2D(const Point2D &p) {
    x = p.x;
    y = p.y;
    std::cout<<"Copy constructor called"<<std::endl;
}

void Point2D::setX(const float x) {
    this->x = x;
}

void Point2D::setY(const float y) {
    this->y = y;
}

float Point2D::getX() const {
    return x;
}

float Point2D::getY() const {
    return y;
}
