#include "Punto.h"

Punto::Punto(float x, float y, float z) : x_(x), y_(y), z_(z){}

float Punto::x()const{
    return x_;
}

float Punto::y()const{
    return y_;
}

float Punto::z()const{
    return z_;
}
