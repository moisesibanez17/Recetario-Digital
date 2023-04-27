#include "ingrediente.h"

using namespace std;

Ingrediente::Ingrediente() {}

Ingrediente::Ingrediente(const Ingrediente& i) : cantidad(i.cantidad), nombre(i.nombre) { }

Ingrediente& Ingrediente::operator=(const Ingrediente& i){
    cantidad = i.cantidad;
    nombre = i.nombre;

    return *this;
}

string Ingrediente::getCantidad() const{
    return cantidad;
}

string Ingrediente::getNombre() const {
    return nombre;
}

string Ingrediente::toString() const {
    return "- " + nombre;
}

void Ingrediente::setCantidad(const string& n){
    cantidad=n;
}

void Ingrediente::setNombre(const string& n){
    nombre=n;
}

bool Ingrediente::operator==(const Ingrediente& i) const {
    return nombre == i.nombre;
}

bool Ingrediente::operator!=(const Ingrediente& i) const {
    return nombre != i.nombre;
}

bool Ingrediente::operator<(const Ingrediente& i) const {
    return nombre < i.nombre;
}

bool Ingrediente::operator<=(const Ingrediente& i) const {
    return nombre <= i.nombre;
}

bool Ingrediente::operator>(const Ingrediente& i) const {
    return nombre > i.nombre;
}

bool Ingrediente::operator>=(const Ingrediente& i) const {
    return nombre >= i.nombre;
}

ostream& operator << (ostream& os, Ingrediente& i){
    os << i.nombre << " - " << i.cantidad;

    return os;
}

istream& operator >> (istream& is, Ingrediente& i){

    getline(is,i.nombre,'-');  
    getline(is,i.cantidad);
    
    return is;
}

