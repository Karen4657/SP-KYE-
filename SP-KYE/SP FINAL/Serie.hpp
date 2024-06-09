#ifndef SERIE_HPP
#define SERIE_HPP

#include "Video.hpp"
#include "Episodio.hpp"
#include <vector>

class Serie : public Video {
private:
    vector<Episodio> episodios;

public:
    Serie(string id, string nombre, string duracion, string genero, float calificacion, int numEpisodios, int numTemporadas);
    void agregarEpisodio(string titulo, int temporada);
    void calificar(float nuevaCalificacion) override;
    void mostrar() const override;
};

#endif // SERIE_HPP
