#include "Peliculas.hpp"

Peliculas::Peliculas(string id, string nombre, string duracion, string genero, float calificacion) 
    : Video(id, nombre, duracion, genero, calificacion) {}

void Peliculas::calificar(float nuevaCalificacion) {
    calificacion = nuevaCalificacion;
}

void Peliculas::mostrar() const {
    cout << "Pelicula: " << nombre << ", Duracion: " << duracion << ", Genero: " << genero 
         << ", Calificacion: " << calificacion << endl;
}
