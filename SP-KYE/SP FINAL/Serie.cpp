#include "Serie.hpp"

Serie::Serie(string id, string nombre, string duracion, string genero, float calificacion, int numEpisodios, int numTemporadas) 
    : Video(id, nombre, duracion, genero, calificacion) {
    // Asignación de episodios aleatorios para demostración
    for (int i = 0; i < numEpisodios; ++i) {
        episodios.push_back(Episodio("Episodio " + to_string(i+1), rand() % numTemporadas + 1));
    }
}

void Serie::agregarEpisodio(string titulo, int temporada) {
    episodios.push_back(Episodio(titulo, temporada));
}

void Serie::calificar(float nuevaCalificacion) {
    calificacion = nuevaCalificacion;
}

void Serie::mostrar() const {
    cout << "Serie: " << nombre << ", Duracion: " << duracion << ", Genero: " << genero 
         << ", Calificacion: " << calificacion << ", Episodios: " << episodios.size() << endl;
    for (const auto& episodio : episodios) {
        cout << "    Episodio: " << episodio.titulo << ", Temporada: " << episodio.temporada << endl;
    }
}
