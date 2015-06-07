#include "MMVector.h"

// -------------------- Funciones Friends --------------------------------------
Punto puntoMasCercano(Punto punto, Punto puntos[], int n){
    float d;
    Punto p;
    
    d = n > 0 ? MMVector(punto, puntos[0]).magnitud() : 0, p = puntos[0];
    
    for(int i = 1; i < n; i++)
        if(MMVector(punto, puntos[i]).magnitud() < d)
            d = MMVector(punto, puntos[i]).magnitud(), p = puntos[i];
    
    return p;
}

Punto puntoProm(Punto puntos[], int n){
    float x = 0, y = 0, z = 0;
    
    for(int i = 0; i < n; i++)
        x += puntos[i].x(), y += puntos[i].y(), z += puntos[i].z();
    
    return Punto(x / n, y / n, z / n);
}

// ------------------------- Constructores -------------------------------------
MMVector::MMVector(const Punto &p) : p2(p){}

MMVector::MMVector(const Punto &p1, const Punto &p2) : p1(p1), p2(p2){}

MMVector::MMVector(float x, float y, float z) : p2(x, y, z){}

MMVector::MMVector(float x1, float y1, float z1, float x2, float y2, float z2) : p1(x1, y1, z1), p2(x2, y2, z2){}

// ----------------------- Funciones Miembros ----------------------------------
double *MMVector::angle() const{
    double *angle = new double[3];
    angle[0] = angleX();
    angle[1] = angleY();
    angle[2] = angleZ();
    
    return angle;
}

double MMVector::angleX() const{
    return acos((double)directorCosX()) * 180 / M_PI;
}

double MMVector::angleY() const{
    return acos((double)directorCosX()) * 180 / M_PI;
}

double MMVector::angleZ() const{
    return acos((double)directorCosX()) * 180 / M_PI;
}

float *MMVector::directorCos() const{
    float *directorCos = new float[3];
    directorCos[0] = directorCosX();
    directorCos[1] = directorCosY();
    directorCos[2] = directorCosZ();
    
    return directorCos;
}

float MMVector::directorCosX() const{
    return x() / magnitud();
}

float MMVector::directorCosY() const{
    return y() / magnitud();
}

float MMVector::directorCosZ() const{
    return z() / magnitud();
}

float MMVector::distancia(Punto punto) const{
    float n = x() * (punto.x() - puntoI().x()) + y() * (punto.y() - puntoI().y()) + z() * (punto.z() - puntoI().z());
    float d = std::pow(x(), 2) + std::pow(y(), 2) + std::pow(z(), 2);
    float lamda = n / d;
    
    return MMVector(puntoI().x() - punto.x() + x() * lamda, puntoI().y() - punto.y() + y() * lamda, puntoI().z() - punto.z() + z() * lamda).magnitud();
}

float MMVector::distancia(MMVector mmvector) const{
    float f = acos(productoPunto(mmvector) / (magnitud() * mmvector.magnitud())) * 180 / M_PI;
    
    if(f == 0)
        return distancia(Punto(mmvector.puntoI().x(), mmvector.puntoI().y(), mmvector.puntoI().z()));
    else{
        MMVector temp(mmvector.puntoI().x() - puntoI().x(), mmvector.puntoI().y() - puntoI().y(), mmvector.puntoI().z() - puntoI().z());
        float det = (temp.x() * y() * mmvector.z() + x() * mmvector.y() * temp.z() + mmvector.x() * z() * temp.y()) - (mmvector.x() * y() * temp.z() + temp.x() * mmvector.y() * z() + x() * temp.y() * mmvector.z());
        float pro = productoCruz(mmvector).magnitud();
        
        return det / pro;
    }
}

double MMVector::magnitud() const{
    return std::sqrt(std::pow((double)x(), 2) + std::pow((double)y(), 2) + std::pow((double)z(), 2));
}

MMVector MMVector::productoCruz(MMVector &mmvector) const{
    return MMVector(y() * mmvector.z() - z() * mmvector.y(), z() * mmvector.x() - x() * mmvector.z(), x() * mmvector.y() - y() * mmvector.x());
}

float MMVector::productoPunto(MMVector &mmvector) const{
    return x() * mmvector.x() + y() * mmvector.y() + z() * mmvector.z();
}

Punto MMVector::puntoF() const{
    return p2;
}

Punto MMVector::puntoI() const{
    return p1;
}

MMVector MMVector::vectorUnitario() const{
    double mag = magnitud();
    
    return MMVector(x() / mag, y() / mag, z() / mag);
}

float MMVector::x() const{
    return puntoF().x() - puntoI().x();
}

float MMVector::y() const{
    return puntoF().y() - puntoI().y();
}

float MMVector::z() const{
    return puntoF().z() - puntoI().z();
}