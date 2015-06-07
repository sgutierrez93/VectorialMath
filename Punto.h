#ifndef PUNTO_H
#define	PUNTO_H

/**
	Esta clase proporciona los puntos en el espacio R^3.

	@author Sergio Gutierrez
	@date 28 de Enero de 2015
*/
class Punto{
    public:
        /**
            Constructor de la Clase Punto.

            @param x Recibe un punto cartesiana en el eje X.
            @param y Recibe un punto cartesiana en el eje Y.
            @param z Recibe un punto cartesiana en el eje Z.
        */
        Punto(float x = 0, float y = 0, float z = 0);
        /**
            Devuelve el punto en el eje X.

            @return Devuelve el punto en el eje X.
        */
        float x() const;
        /**
            Devuelve el punto en el eje Y.

            @return Devuelve el punto en el eje Y.
        */
        float y() const;
        /**
            Devuelve el punto en el eje Z.

            @return Devuelve el punto en el eje Z.
        */
        float z() const;
    private:
        float x_;
        float y_;
        float z_;
};

#endif

