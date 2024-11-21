#include <iostream>
#include "Point2D.h"

using namespace std;

int main() {
    Point2D p1;
    Point2D p2(1, 2);

    cout<<"p1: ("<<p1.getX()<<", "<<p1.getY()<<")"<<endl;
    cout<<"p2: ("<<p2.getX()<<", "<<p2.getY()<<")"<<endl;

    p1.setX(10);
    p1.setY(20);
    cout<<"p1: ("<<p1.getX()<<", "<<p1.getY()<<")"<<endl;

    Point2D p3(p1);
    cout<<"p3: ("<<p3.getX()<<", "<<p3.getY()<<")"<<endl;

}