#include <iostream>
#include <string>

using namespace std;

class CepaDelta {
protected:
    int contagioDelta;
    string sintomaDelta;
public:
    CepaDelta(int cDelta, string sDelta) {
        contagioDelta = cDelta;
        sintomaDelta = sDelta;
    }

    void mostrarDelta() {
        cout << "Nivel de contagio Delta: " << contagioDelta << "/10" << endl;
        cout << "Sintoma principal Delta: " << sintomaDelta << endl;
    }
};

class CepaOmicron {
protected:
    int contagioOmicron;
    string sintomaOmicron;
public:
    CepaOmicron(int cOmicron, string sOmicron) {
        contagioOmicron = cOmicron;
        sintomaOmicron = sOmicron;
    }

    void mostrarOmicron() {
        cout << "Nivel de contagio Omicron: " << contagioOmicron << "/10" << endl;
        cout << "Sintoma principal Omicron: " << sintomaOmicron << endl;
    }
};

class CepaHibrida : public CepaDelta, public CepaOmicron {
private:
    string nombreHibrido;
    string paisOrigen;
public:
    CepaHibrida(string nom, string pais, int cDelta, string sDelta, int cOmicron, string sOmicron)
        : CepaDelta(cDelta, sDelta), CepaOmicron(cOmicron, sOmicron) {
        nombreHibrido = nom;
        paisOrigen = pais;
    }

    void mostrarDatosCompletos() {
        cout << "--- Datos de la Cepa Hibrida ---" << endl;
        cout << "Nombre: " << nombreHibrido << endl;
        cout << "Detectada en: " << paisOrigen << endl;
        cout << "\nRasgos heredados de Delta:" << endl;
        mostrarDelta();
        cout << "\nRasgos heredados de Omicron:" << endl;
        mostrarOmicron();
    }
};

int main() {
    CepaHibrida deltacron("Deltacron", "Francia", 8, "Dificultad respiratoria", 9, "Dolor de garganta");

    deltacron.mostrarDatosCompletos();

    return 0;
}
