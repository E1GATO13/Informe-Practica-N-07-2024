#include <iostream>
#include <string>

using namespace std;

// a) Clase base "Cliente"
class Cliente {
protected:
    string nombre;
    string apellido;
    string email;
    string telefono;
    string direccion;
    double ingresos;
    string informacion_encriptada;

    void encriptar_informacion() {
        string informacion = nombre + "|" + apellido + "|" + email + "|" + telefono + "|" + direccion + "|" + to_string(ingresos);
        informacion_encriptada = informacion; // En una implementación real, se debería encriptar la información aquí
    }

public:
    Cliente(string nombre, string apellido, string email, string telefono, string direccion, double ingresos) {
        this->nombre = nombre;
        this->apellido = apellido;
        this->email = email;
        this->telefono = telefono;
        this->direccion = direccion;
        this->ingresos = ingresos;
        encriptar_informacion(); // Encriptar la información al crear el objeto
    }

    virtual ~Cliente() {
        // Código para liberar recursos de la clase base, si es necesario
    }
};

// b) Clase derivada "ClienteSeguro"
class ClienteSeguro : public Cliente {
private:
    string clave;

public:
    // e) Constructor en la clase derivada
    ClienteSeguro(string nombre, string apellido, string email, string telefono, string direccion, double ingresos, string clave)
        : Cliente(nombre, apellido, email, telefono, direccion, ingresos), clave(clave) {}

    string obtener_informacion_encriptada() {
        return informacion_encriptada; // Acceder a la información encriptada desde la clase base
    }

    bool verificar_autenticidad(string clave_ingresada) {
        return clave_ingresada == clave; // En una implementación real, se debería verificar la clave encriptada
    }

    // f) Destructor en la clase derivada
    ~ClienteSeguro() {}
};

class ClienteSeguroPublico : public Cliente {
private:
    string clave;

public:
    ClienteSeguroPublico(string nombre, string apellido, string email, string telefono, string direccion, double ingresos, string clave)
        : Cliente(nombre, apellido, email, telefono, direccion, ingresos), clave(clave) {}

    string obtener_informacion_encriptada() {
        return informacion_encriptada; // Acceder a la información encriptada desde la clase base
    }

    bool verificar_autenticidad(string clave_ingresada) {
        return clave_ingresada == clave; // En una implementación real, se debería verificar la clave encriptada
    }

    ~ClienteSeguroPublico() {}
};

// h) Herencia protegida
class ClienteSeguroProtegido : protected Cliente {
private:
    string clave;

public:
    ClienteSeguroProtegido(string nombre, string apellido, string email, string telefono, string direccion, double ingresos, string clave)
        : Cliente(nombre, apellido, email, telefono, direccion, ingresos), clave(clave) {}

    string obtener_informacion_encriptada() {
        return informacion_encriptada; // Acceder a la información encriptada desde la clase base
    }

    bool verificar_autenticidad(string clave_ingresada) {
        return clave_ingresada == clave; // En una implementación real, se debería verificar la clave encriptada
    }

    ~ClienteSeguroProtegido() {}
};

// i) Herencia privada
class ClienteSeguroPrivado : private Cliente {
private:
    string clave;

public:
    ClienteSeguroPrivado(string nombre, string apellido, string email, string telefono, string direccion, double ingresos, string clave)
        : Cliente(nombre, apellido, email, telefono, direccion, ingresos), clave(clave) {}

    string obtener_informacion_encriptada() {
        return informacion_encriptada; // Acceder a la información encriptada desde la clase base
    }

    bool verificar_autenticidad(string clave_ingresada) {
        return clave_ingresada == clave; // En una implementación real, se debería verificar la clave encriptada
    }

    ~ClienteSeguroPrivado() {}
};

int main() {
    ClienteSeguroPublico* cliente1 = new ClienteSeguroPublico("Juan", "Pérez", "juan@example.com", "1234567890", "Calle Falsa 123", 50000.0, "miClave123");
    ClienteSeguroProtegido* cliente2 = new ClienteSeguroProtegido("Ana", "Gómez", "ana@example.com", "9876543210", "Calle Real 456", 75000.0, "otraClave456");
    ClienteSeguroPrivado* cliente3 = new ClienteSeguroPrivado("Pedro", "Rodríguez", "pedro@example.com", "5555555555", "Calle Privada 789", 90000.0, "clave789");

    // Acceder a los métodos públicos de las clases derivadas
    cout << "Información encriptada de cliente1: " << cliente1->obtener_informacion_encriptada() << endl;
    cout << "Cliente1 autenticado: " << (cliente1->verificar_autenticidad("miClave12") ? "Sí" : "No") << endl;

    cout << "Información encriptada de cliente2: " << cliente2->obtener_informacion_encriptada() << endl;
    cout << "Cliente2 autenticado: " << (cliente2->verificar_autenticidad("otraClave456") ? "Sí" : "No") << endl;

    cout << "Información encriptada de cliente3: " << cliente3->obtener_informacion_encriptada() << endl;
    cout << "Cliente3 autenticado: " << (cliente3->verificar_autenticidad("clave789") ? "Sí" : "No") << endl;

    delete cliente1;
    delete cliente2;
    delete cliente3;

    return 0;
}