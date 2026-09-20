#include <iostream>
#include <string>

using namespace std;

class Persona {
protected:
    string nombre;
    int edad;
public:
    Persona(string nom, int ed) : nombre(nom), edad(ed) {}
    virtual ~Persona() {}

    virtual void mostrarDatos() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }

    virtual void trabajar() const = 0;
};

class Arquitecto : public Persona {
private:
    int proyectos;
public:
    Arquitecto(string nom, int ed, int proy) 
        : Persona(nom, ed), proyectos(proy) {}

    void trabajar() const override {
        cout << nombre << " esta diseñando planos para sus " << proyectos << " proyectos a cargo" << endl;
    }
};

class Doctor : public Persona {
private:
    string hospital;
public:
    Doctor(string nom, int ed, string hosp) 
        : Persona(nom, ed), hospital(hosp) {}

    void trabajar() const override {
        cout << nombre << " esta atendiendo pacientes en el hospital " << hospital << endl;
    }
};

class Enfermera : public Persona {
private:
    string turno;
public:
    Enfermera(string nom, int ed, string tur) 
        : Persona(nom, ed), turno(tur) {}

    void trabajar() const override {
        cout << nombre << " esta cuidando pacientes en el turno de la " << turno << endl;
    }
};

class Bombero : public Persona {
private:
    int estacion;
public:
    Bombero(string nom, int ed, int est) 
        : Persona(nom, ed), estacion(est) {}

    void trabajar() const override {
        cout << nombre << " esta de guardia apagando incendios en la estacion numero " << estacion << endl;
    }
};

int main() {
    Persona* personas[4];

    personas[0] = new Arquitecto("Carlos", 40, 5);
    personas[1] = new Doctor("Elena", 35, "Central");
    personas[2] = new Enfermera("Lucia", 28, "manana");
    personas[3] = new Bombero("Marcos", 32, 12);

    for (int i = 0; i < 4; i++) {
        personas[i]->mostrarDatos();
        personas[i]->trabajar();
        cout << endl;
        delete personas[i];
    }

    return 0;
}
