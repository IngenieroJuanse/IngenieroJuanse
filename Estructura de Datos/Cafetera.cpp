//Hola proffeeeeee
//Profee aca esta el RETO 01, Espero haya quedado bien 
#include <iostream>
#include <memory>  // Biblioteca que se usa para unique_ptr y make_unique
#include <string>

using namespace std;

// Clase abstracta para las cafeteras
class Cafetera {
public:
    // Método virtual que debe ser implementado por las clases derivadas
    virtual void preparar(const string& receta) = 0;

    // Destructor virtual para permitir la destrucción correcta de las clases derivadas
    virtual ~Cafetera() = default;
};

// Clase Haceb que hereda de Cafetera
class Haceb : public Cafetera {
public:
    // Implementación del método preparar para la cafetera Haceb
    void preparar(const string& receta) override {
        if (receta == "capuccino") {
            cout << "Preparando capuccino en Haceb.\n";
            // Aquí va la receta para capuccino en Haceb
        } else if (receta == "tinto") {
            cout << "Preparando tinto en Haceb.\n";
            // Aquí va la receta para tinto en Haceb
        }
    }
};

// Clase Oster que hereda de Cafetera
class Oster : public Cafetera {
public:
    // Implementación del método preparar para la cafetera Oster
    void preparar(const string& receta) override {
        if (receta == "capuccino") {
            cout << "Preparando capuccino en Oster.\n";
            // Aquí va la receta para capuccino en Oster
        } else if (receta == "tinto") {
            cout << "Preparando tinto en Oster.\n";
            // Aquí va la receta para tinto en Oster
        }
    }
};

int main() {
    string opcion, opcion2;
    // Puntero inteligente para manejar las instancias de las cafeteras
    unique_ptr<Cafetera> cafetera;

    // Saludo inicial
    cout << "Hola, bienvenido a mi cafetera \n";
    cout << "¿Qué receta quieres preparar hoy?\n";
    cout << "1. capuccino\n";
    cout << "2. tinto\n";
    // Leer la opción del usuario
    cin >> opcion;

    // Validar y asignar la receta seleccionada
    if (opcion == "1") {
        opcion = "capuccino";
    } else if (opcion == "2") {
        opcion = "tinto";
    } else {
        cout << "Opción no válida.\n";
        return 1;
    }

    // Preguntar el tipo de cafetera
    cout << "¿Qué tipo de cafetera deseas?\n";
    cout << "1. Haceb\n";
    cout << "2. Oster\n";
    // Leer la opción del usuario
    cin >> opcion2;

    // Crear la instancia de la cafetera adecuada
    if (opcion2 == "1") {
        cafetera = make_unique<Haceb>();
    } else if (opcion2 == "2") {
        cafetera = make_unique<Oster>();
    } else {
        cout << "Opción no válida.\n";
        return 1;
    }

    // Preparar la receta con la cafetera seleccionada
    cafetera->preparar(opcion);
    return 0;
}
