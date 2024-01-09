#include "receta.h"

using namespace std;

Receta::Receta() { }

Receta::Receta(const Receta& r) : tipo(r.tipo), receta(r.receta), tiempo(r.tiempo), ingrediente(r.ingrediente),procedimiento(r.procedimiento),nombreautor(r.nombreautor) {}

Receta& Receta::operator=(const Receta& r){
    tipo = r.tipo;
    receta = r.receta;
    tiempo = r.tiempo;
    ingrediente = r.ingrediente;
    procedimiento = r.procedimiento;
    nombreautor = r.
    nombreautor;

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

    result+= "\n_______________________________________________________________________________________________________________________\n";
    result+= "Clasificacion: ";
    result+= tipo;
    result+= "\n";
    result+= receta;
    result+= "\n";
    result+= tiempo;
    result+= " min \n\nIngredientes:\n";
    result+= ingrediente.toString(); 
    result+= "\nProcedimiento: ";
    result+= procedimiento;
    result+= "\n\n\nHecho por: ";
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
    std::string auxCantidad,auxNombre;
    std::string str;

    getline(is, r.tipo);
    getline(is, r.receta);
    getline(is, r.tiempo);

    do{
        is >> auxIngrediente;
        auxListSimple.insertData(auxListSimple.getLastPos(), auxIngrediente);
        getline(is, str);
    }while(str == "S");

    r.setIngrediente(auxListSimple);

    getline(is, r.procedimiento);

    is >> r.nombreautor;

    return is;
}

void Receta::addIngrediente(const Ingrediente& i) {
    ListSimple<Ingrediente>::Position last;
    last = ingrediente.getLastPos();
    ingrediente.insertSortedData(last, i);
}

void Receta::deleteIngrediente(const Ingrediente& i){
    ListSimple<Ingrediente>::Position pos;
    pos = ingrediente.findData(i);
    ingrediente.deleteData(pos);
}

void Receta::deleteAllIngrediente(){
    ingrediente.deleteAll();
}

void Receta::changeCantidadIngrediente(const Ingrediente& i, string nuevaCantidad) {
    ListSimple<Ingrediente>::Position pos;
    std::string auxNombre;
    Ingrediente aux;
    pos = ingrediente.findData(i);
    auxNombre = ingrediente.retrieve(pos).getNombre();
    aux.setCantidad(nuevaCantidad);
    aux.setNombre(auxNombre);
    
    ingrediente.deleteData(pos);
    ingrediente.insertSortedData(ingrediente.getLastPos(),aux);
}





