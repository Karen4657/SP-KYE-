#include <iostream>
#include <vector>
#include "Video.hpp"
#include "Serie.hpp"
#include "Peliculas.hpp"
#include "Episodio.hpp"

using namespace std;

int main() {
    vector<Video*> videos;
    int opcion;

    do {
        cout << "Menu:" << endl;
        cout << "1. Cargar archivo de datos" << endl;
        cout << "2. Mostrar los videos" << endl;
        cout << "3. Mostrar las peliculas" << endl;
        cout << "4. Mostrar los episodios" << endl;
        cout << "5. Mostrar los videos con una cierta calificacion o de un cierto genero" << endl;
        cout << "6. Mostrar los episodios de una determinada serie con una calificacion determinada" << endl;
        cout << "7. Mostrar las peliculas con cierta calificacion" << endl;
        cout << "8. Calificar un video" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Video::leerArchivo(videos);
                break;
            }
            case 2: {
                Video::mostrarVideos(videos);
                break;
            }
            case 3: {
                Video::mostrarPeliculas(videos);
                break;
            }
            case 4: {
                Video::mostrarEpisodios(videos);
                break;
            }
            case 5: {
                int subopcion;
                cout << "1. Filtrar por calificacion" << endl;
                cout << "2. Filtrar por genero" << endl;
                cout << "Opcion: ";
                cin >> subopcion;

                if (subopcion == 1) {
                    float calificacionMinima;
                    cout << "Ingrese la calificacion minima: ";
                    cin >> calificacionMinima;
                    Video::mostrarVideosPorCalificacion(videos, calificacionMinima);
                } else if (subopcion == 2) {
                    string genero;
                    cout << "Ingrese el genero: ";
                    cin >> genero;
                    Video::mostrarVideosPorGenero(videos, genero);
                } else {
                    cout << "Opcion no valida." << endl;
                }
                break;
            }
            case 6: {
                string nombreSerie;
                float calificacionMinima;
                cout << "Ingrese el nombre de la serie: ";
                cin.ignore();
                getline(cin, nombreSerie);
                cout << "Ingrese la calificacion minima: ";
                cin >> calificacionMinima;
                Video::mostrarEpisodiosPorCalificacion(videos, nombreSerie, calificacionMinima);
                break;
            }
            case 7: {
                float calificacionMinima;
                cout << "Ingrese la calificacion minima: ";
                cin >> calificacionMinima;
                Video::mostrarPeliculasPorCalificacion(videos, calificacionMinima);
                break;
            }
            case 8: {
                string nombre;
                float nuevaCalificacion;
                cout << "Ingrese el nombre del video a calificar: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese la nueva calificacion: ";
                cin >> nuevaCalificacion;
                Video::calificarVideo(videos, nombre, nuevaCalificacion);
                break;
            }
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    } while (opcion != 0);

    // Liberar memoria
    for (auto video : videos) {
        delete video;
    }

    return 0;
}
