#ifndef PELICULAS_HPP
#define PELICULAS_HPP

#include "Video.hpp"

class Peliculas : public Video {
public:
    Peliculas(string id, string nombre, string duracion, string genero, float calificacion);
    void calificar(float nuevaCalificacion) override;
    void mostrar() const override;
};

#endif // PELICULAS_HPP
