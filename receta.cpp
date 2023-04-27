#include "receta.h"

using namespace std;

Receta::Receta() { }

Receta::Receta(const Receta& r) : tipo(r.tipo), receta(r.receta), tiempo(r.tiempo),ingrediente(r.ingrediente),procedimiento(r.procedimiento),nombreautor(r.nombreautor) {}

Receta& Receta::operator=(const Receta& r){
    tipo = r.tipo;
    receta = r.receta;
    tiempo = r.tiempo;
    ingrediente = r.ingrediente;
    procedimiento = r.procedimiento;
    nombreautor = r.nombreautor;

    return *this;
}

string Receta::getTipo() const{
    return tipo;
}
string Receta::getReceta() const{
    return receta;
}

string Receta::getTiempo() const{
    return tiempo;
}

string Receta::getIngrediente() const{
    return ingrediente.toString();
}

string Receta::getProcedimiento() const{
    return procedimiento;
}

Name Receta::getNombreAutor() const{
    return nombreautor;
}

string Receta::toString() const{
    string result;

    result+= "Clasificacion: ";
    result+= tipo;
    result+= "\n";
    result+= receta;
    result+= "\n";
    result+= tiempo;
    result+= "min \n\nIngredientes: ";
    result+= ingrediente.toString(); 
    result+= "\nProcedimiento: ";
    result+= procedimiento;
    result+= "\nHecho por: ";
    result+= nombreautor.toString();

    return result;
}

void Receta::setTipo(const std::string& t){
    tipo = t;
}

void Receta::setReceta(const std::string& r){
    receta = r;
}

void Receta::setTiempo(const std::string& t){
    tiempo = t;
}

void Receta::setIngrediente(const ListSimple<Ingrediente>& i){
    ingrediente = i;
}

void Receta::setProcedimiento(const std::string& p){
    procedimiento = p;
}

void Receta::setNombreAutor(const Name& n){
    nombreautor = n;
}
/*
void Receta::agregarIngrediente(ListSimple<Ingrediente>& ListSimpleaIngredientes) {
    Ingrediente ingrediente;
    while (cin >> ingrediente) {
        ListSimpleaIngredientes.push_back(ingrediente);
    }

void Receta::cambiarCantidadIngrediente(string nombre, string nuevaCantidad) {
    int posIngrediente = buscarIngrediente(nombre);
    if (posIngrediente != -1) {
        Ingrediente ingrediente = ingredientes.retrieve(posIngrediente);
        ingrediente.setCantidad(nuevaCantidad);
        ingredientes.deleteData(posIngrediente);
        ingredientes.insertData(posIngrediente, ingrediente);
    }
}

void Receta::eliminarIngrediente(string nombre) {
    int posIngrediente = buscarIngrediente(nombre);
    if (posIngrediente != -1) {
        ingredientes.deleteData(posIngrediente);
    }
}

int Receta::buscarIngrediente(string nombre) {
    int pos = ingredientes.getFirstPos();
    while (pos <= ingredientes.getLastPos()) {
        Ingrediente ingrediente = ingredientes.retrieve(pos);
        if (ingrediente.getNombre() == nombre) {
            return pos;
        }
        pos = ingredientes.getNextPos(pos);
    }
    return -1;
}
*/
bool Receta::operator==(const Receta& r) const {
    return receta == r.receta;
}

bool Receta::operator!=(const Receta& r) const {
    return receta != r.receta;
}

bool Receta::operator<(const Receta& r) const {
    return receta < r.receta;
}

bool Receta::operator<=(const Receta& r) const {
    return receta <= r.receta;
}

bool Receta::operator>(const Receta& r) const {
    return receta > r.receta;
}

bool Receta::operator>=(const Receta& r) const {
    return receta >= r.receta;
}

ostream& operator << (ostream& os, Receta& r){

    os << r.tipo << endl;
    os << r.receta << endl;
    os << r.tiempo << endl;
    os << r.ingrediente.toString() << endl;
    os << r.procedimiento << endl;
    os << r.nombreautor;

    return os;
}

istream& operator >> (istream& is, Receta& r){
    Ingrediente auxIngrediente;
    ListSimple<Ingrediente> auxListSimple;
    std::string auxCantidad;
    char str;

    getline(is, r.tipo);
    getline(is, r.receta);
    getline(is, r.tiempo);

    do{
        is >> auxIngrediente;
        auxCantidad = auxIngrediente.getCantidad();
        str = auxCantidad[auxCantidad.size() - 1]; //Obtener el ultimo caracter de auxCantidad
        auxListSimple.insertData(auxListSimple.getLastPos(), auxIngrediente);
    }while(str != ';');

    r.setIngrediente(auxListSimple);

    getline(is, r.procedimiento);

    is >> r.nombreautor;

    return is;
}