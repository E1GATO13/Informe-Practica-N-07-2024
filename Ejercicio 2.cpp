#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
    string nombre;
    int edad;
    float salario;
    string correoElectronico;

public:
    Persona(string nombre, int edad, float salario, string correoElectronico)
        : nombre(nombre), edad(edad), salario(salario), correoElectronico(correoElectronico) {}

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    float getSalario() const { return salario; }
    string getCorreoElectronico() const { return correoElectronico; }
};

class Empleado : public Persona {
public:
    Empleado(string nombre, int edad, float salario, string correoElectronico)
        : Persona(nombre, edad, salario, correoElectronico) {}
};

class Cliente : public Persona {
public:
    Cliente(string nombre, int edad, float salario, string correoElectronico)
        : Persona(nombre, edad, salario, correoElectronico) {}
};

int main() {
    string nombre;
    int edad;
    float salario;
    string correoElectronico;

    cout << "Ingrese los datos del Empleado:" << endl;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Edad: ";
    cin >> edad;
    cout << "Salario: ";
    cin >> salario;
    cout << "Correo Electronico: ";
    cin >> correoElectronico;

    Empleado emp(nombre, edad, salario, correoElectronico);

    cout << "Ingrese los datos del Cliente:" << endl;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Edad: ";
    cin >> edad;
    cout << "Salario (use 0 si no aplica): ";
    cin >> salario;
    cout << "Correo Electronico: ";
    cin >> correoElectronico;
    
    Cliente cli(nombre, edad, salario, correoElectronico);
    
    cout << "Empleado: " << emp.getNombre() << ", Edad: " << emp.getEdad()
         << ", Salario: " << emp.getSalario() << ", Correo: " << emp.getCorreoElectronico() << endl;

    cout << "Cliente: " << cli.getNombre() << ", Edad: " << cli.getEdad()
         << ", Salario: " << cli.getSalario() << ", Correo: " << cli.getCorreoElectronico() << endl;

    return 0;
}

