#ifndef VIDEO_HPP
#define VIDEO_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Video {
protected:
    string id;
    string nombre;
    string duracion;
    string genero;
    float calificacion;

public:
    Video(string id, string nombre, string duracion, string genero, float calificacion);
    virtual ~Video() = default; // Destructor virtual
    virtual void calificar(float nuevaCalificacion) = 0; // Método abstracto
    virtual void mostrar() const = 0; // Método abstracto
    virtual float getCalificacion() const;
    virtual string getGenero() const;
    virtual string getNombre() const;

    static void leerArchivo(vector<Video*>& videos);
    static float calificacionPromedio(const vector<Video*>& videos);
    static void mostrarPeliculasPorCalificacion(const vector<Video*>& videos, float calificacionMinima);
    static void mostrarVideosPorCalificacion(const vector<Video*>& videos, float calificacionMinima);
    static void mostrarVideosPorGenero(const vector<Video*>& videos, const string& genero);
    static void mostrarEpisodiosPorCalificacion(const vector<Video*>& videos, const string& nombreSerie, float calificacionMinima);
    static void calificarVideo(vector<Video*>& videos, const string& nombre, float nuevaCalificacion);
    static void mostrarPeliculas(const vector<Video*>& videos);
    static void mostrarEpisodios(const vector<Video*>& videos);
    static void mostrarVideos(const vector<Video*>& videos);

    // Sobrecarga de operador
    bool operator<(const Video& other) const {
        return calificacion < other.calificacion;
    }
};

#endif // VIDEO_HPP
