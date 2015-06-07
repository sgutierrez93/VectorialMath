#ifndef MMVECTOR_H
#define	MMVECTOR_H

#include <cmath>
#include "Punto.h"

/**
	Esta clase proporciona las herramientas basicas que se utilizan con los vectores.
	Entre ellas estan determinar sus cosenos, angles, producto punto, producto cruz, entre otras.

	@author Sergio Gutierrez
	@date 21 de Enero de 2015
*/
class MMVector{
    /**
     * Esta funcion determina el punto mas cercano a un conjunto de puntos dados.
     * 
     * @param punto Recibe un punto cualquiera.
     * @param puntos Recibe un conjunto de puntos.
     * @param n Recibe el tamanio del conjunto de puntos.
     * @return Devuelve el punto mas cercano del conjunto de puntos, al punto dado.
    */
    friend Punto puntoMasCercano(Punto punto, Punto puntos[], int n);
    /**
     * Esta funcion determina un punto medio entre un conjunto de puntos dados.
     * 
     * @param puntos Recibe un conjunto de puntos.
     * @param n Recibe el tamanio del conjunto de puntos.
     * @return Devuelve el punto promedio del conjunto de puntos.
    */
    friend Punto puntoProm(Punto puntos[], int n);
    public:
        /**
         * Constructor de la Clase MMVector, siendo este un vector que parte del origen.
         * 
         * @param p Recibe un punto que sera la cabeza del Vector.
        */
        MMVector(const Punto &p);
        /**
         * Constructor de la Clase MMVector, siendo este un vector en el espacio no necesariamente pasa por el origen.
         * 
         * @param p1 Recibe un punto que sera la cola del Vector.
         * @param p2 Recibe un punto que sera la cabeza del Vector.
        */
        MMVector(const Punto &p1, const Punto &p2);
        /**
         * Constructor de la Clase MMVector, siendo este un vector que parte del origen.
         * 
         * @param x Recibe la coordenada cartesiana en el eje X.
         * @param y Recibe la coordenada cartesiana en el eje Y.
         * @param z Recibe la coordenada cartesiana en el eje Z.
        */
        MMVector(float x, float y, float z);
        /**
         * Constructor de la Clase MMVector, siendo este un vector en el espacio no necesariamente pasa por el origen.
         * 
         * @param x1 Recibe la coordenada cartesiana en el eje X del punto inicial del vector.
         * @param y1 Recibe la coordenada cartesiana en el eje Y del punto inicial del vector.
         * @param z1 Recibe la coordenada cartesiana en el eje Z del punto inicial del vector.
         * @param x2 Recibe la coordenada cartesiana en el eje X del punto final del vector.
         * @param y2 Recibe la coordenada cartesiana en el eje Y del punto final del vector.
         * @param z2 Recibe la coordenada cartesiana en el eje Z del punto final del vector.
        */
        MMVector(float x1, float y1, float z1, float x2, float y2, float z2);
        /**
         * Determina los Angulos Directores del Vector.
         * 
         * @return Devuelve los valores de los Angulos Directores del Vector.
        */
        double*angle() const;
        /**
         * Determina el Angulo Director del Vector en el eje X.
         * 
         * @return Devuelve el valor del Angulo en el eje X del Vector.
        */
        double angleX() const;
        /**
         * Determina el Angulo Director del Vector en el eje Y.
         * 
         * @return Devuelve el valor del Angulo en el eje Y del Vector.
        */
        double angleY() const;
        /**
         * Determina el Angulo Director del Vector en el eje Z.
         * 
         * @return Devuelve el valor del Angulo en el eje Z del Vector.
        */
        double angleZ() const;
        /**
         * Determina los Cosenos Directores del Vector.
         * 
         * @return Devuelve los valores de los Cosenos Directores del Vector.
        */
        float*directorCos() const;
        /**
         * Determina el Coseno Director del Vector en el eje X.
         * 
         * @return Devuelve el valor del Coseno en el eje X del Vector.
        */
        float directorCosX() const;
        /**
         * Determina el Coseno Director del Vector en el eje Y.
         * 
         * @return Devuelve el valor del Coseno en el eje Y del Vector.
        */
        float directorCosY() const;
        /**
         * Determina el Coseno Director del Vector en el eje Z.
         * 
         * @return Devuelve el valor del Coseno en el eje Z del Vector.
        */
        float directorCosZ() const;
        /**
         * Calcula la distancia entre un punto cualquiera y una recta.
         * La recta es dada por el vector.
         * 
         * @param punto Recibe el punto en el espacio.
         * @return Devuelve la distancia entre el punto y la recta.
        */
        float distancia(Punto punto) const;
        /**
         * Calcula la distancia entre dos rectas.
         * Las recta son dadas por los vectores.
         * 
         * @param mmvector Recibe el vector que dara como resultado una recta.
         * @return Devuelve la distancia entre dos rectas.
        */
        float distancia(MMVector mmvector) const;
        /**
         * Calcua la magnitud del Vector.
         * 
         * @return Devuelve el valor de la magnitud del Vector.
        */
        double magnitud() const;
        /**
         * Calcula el Producto Cruz entre dos Vectores.
         * 
         * @param mmvector Recibe el vector necesario para el Producto.
         * @return Devuelve el valor del Producto Cruz.
        */
        MMVector productoCruz(MMVector &mmvector) const;
        /**
         * Calcula el Producto Punto entre dos Vectores.
         * 
         * @param mmvector Recibe el vector necesario para el Producto.
         * @return Devuelve el valor del Producto Punto.
        */
        float productoPunto(MMVector &mmvector) const;
        /**
         * Funcion que retorna el Punto Final del Vector.
         * 
         * @return Devuelve el Punto Final del Vector.
         */
        Punto puntoF() const;
        /**
         * Funcion que retorna el Punto Inicial del Vector.
         * 
         * @return Devuelve el Punto Inicial del Vector.
         */
        Punto puntoI() const;
        /**
         * Crea un Vector Unitario a partir del Vector dado.
         * 
         * @return Devuelve el Vector Unitario de este Vector.
        */
        MMVector vectorUnitario() const;
        /**
         * Devuelve la posicion del Vector en el eje X.
         * 
         * @return Devuelve la posicion del Vector en el eje X.
        */
        float x() const;
        /**
         * Devuelve la posicion del Vector en el eje Y.
         * 
         * @return Devuelve la posicion del Vector en el eje Y.
        */
        float y() const;
        /**
         * Devuelve la posicion del Vector en el eje Z.
         * 
         * @return Devuelve la posicion del Vector en el eje Z.
        */
        float z() const;
    private:
        const Punto p1;
        const Punto p2;
};

#endif