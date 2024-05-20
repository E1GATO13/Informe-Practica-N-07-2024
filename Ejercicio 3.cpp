#include <iostream>

#include <iomanip> // Para formatear la salida de datos

using namespace std;
class Banco {

public:

    // Atributo estático para almacenar la tasa de interés

    static double tasa_interes;

    static void establecer_tasa_interes(double tasa) {

        // Método estático para cambiar la tasa de interés

        tasa_interes = tasa;

    }

};


// Inicializar el atributo estático

double Banco::tasa_interes = 0.05;


class CuentaBancaria {

private:

    double saldo;

public:

    CuentaBancaria(double saldo_inicial = 0) : saldo(saldo_inicial) {}

    double obtener_saldo() const {

        return saldo;

    }


    double depositar(double monto) {

        saldo += monto;

        return saldo;

    }


    bool retirar(double monto) {

        if (monto > saldo) {

            cout << "Fondos insuficientes" << endl;

            return false;

        }

        saldo -= monto;

        return true;

    }


    double calcular_interes() const {

        // Usa la tasa de interés estática del Banco

        return saldo * Banco::tasa_interes;

    }

};


int main() {

    // Crea una cuenta bancaria con un saldo inicial de s/.1000

    CuentaBancaria cuenta(1000);


    // Deposita s/.500 en la cuenta

    cuenta.depositar(500);

    cout << "Nuevo saldo: s/." << cuenta.obtener_saldo() << endl;


    // Retira s/.200 de la cuenta

    if (cuenta.retirar(200)) {

        cout << "Nuevo saldo: s/." << cuenta.obtener_saldo() << endl;

    }


    // Calcula el interés ganado por la cuenta

    double interes = cuenta.calcular_interes();

    cout << "Interés ganado: s/." << fixed << setprecision(2) << interes << endl;


    // Cambia la tasa de interés para todas las cuentas bancarias

    Banco::establecer_tasa_interes(0.07);


    // Calcula el nuevo interés ganado por la cuenta

    double nuevo_interes = cuenta.calcular_interes();

    cout << "Nuevo interés ganado: s/." << fixed << setprecision(2) << nuevo_interes << endl;


    return 0;

}
