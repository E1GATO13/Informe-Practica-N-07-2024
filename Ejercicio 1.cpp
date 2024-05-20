#include <iostream>
#include <string>

using namespace std;

class Vehiculo { //Se crea la clase base
public:
    Vehiculo(string marca, string modelo, int año, float precio)
        : marca(marca), modelo(modelo), año(año), precio(precio) {}
    //4 atributos iniciales
    string marca;
    string modelo;
    int año;
    float precio;
};

class Automovil : public Vehiculo { //Clase derivada 1
public:
    Automovil(string marca, string modelo, int año, double precio, int num_puertas, string tipo_combustible)
        : Vehiculo(marca, modelo, año, precio), num_puertas(num_puertas), tipo_combustible(tipo_combustible) {}

    int num_puertas;    //Se agregan 2 atributos
    string tipo_combustible;
};

class Motocicleta : public Vehiculo {   //Clase derivada 2
public:
    Motocicleta(string marca, string modelo, int año, double precio, int cilindrada)
        : Vehiculo(marca, modelo, año, precio), cilindrada(cilindrada) {}

    int cilindrada; //Se agrega un atributo
};

int main() {
    //Se crean objetos
    Automovil carrito("Toyota", "Corolla", 2022, 25000, 4, "Gasolina"); //Se asignan valores
    Motocicleta moto("Honda", "CBR500R", 2020, 8000, 500);
    
    //Se muestra la información asignada a los objetos
    cout << "Automóvil:" << endl;
    cout << "Marca: " << carrito.marca << endl;
    cout << "Modelo: " << carrito.modelo << endl;
    cout << "Año: " << carrito.año << endl;
    cout << "Precio: " << carrito.precio << endl;
    cout << "Número de puertas: " << carrito.num_puertas << endl;
    cout << "Tipo de combustible: " << carrito.tipo_combustible << endl;

    cout << "\nMotocicleta:" << endl;
    cout << "Marca: " << moto.marca << endl;
    cout << "Modelo: " << moto.modelo << endl;
    cout << "Año: " << moto.año << endl;
    cout << "Precio: " << moto.precio << endl;
    cout << "Cilindrada: " << moto.cilindrada << endl;

    return 0;
}

int main() { 

    //Se crean objetos 

    Automovil carrito("Toyota", "Corolla", 2022, 25000, 4, "Gasolina"); //Se asignan valores 

    Motocicleta moto("Honda", "CBR500R", 2020, 8000, 500); 

     

    //Se muestra la información asignada a los objetos 

    cout << "Automóvil:" << endl; 

    cout << "Marca: " << carrito.marca << endl; 

    cout << "Modelo: " << carrito.modelo << endl; 

    cout << "Año: " << carrito.año << endl; 

    cout << "Precio: " << carrito.precio << endl; 

    cout << "Número de puertas: " << carrito.num_puertas << endl; 

    cout << "Tipo de combustible: " << carrito.tipo_combustible << endl; 

 

    cout << "\nMotocicleta:" << endl; 

    cout << "Marca: " << moto.marca << endl; 

    cout << "Modelo: " << moto.modelo << endl; 

    cout << "Año: " << moto.año << endl; 

    cout << "Precio: " << moto.precio << endl; 

    cout << "Cilindrada: " << moto.cilindrada << endl; 

 

    return 0; 

} 