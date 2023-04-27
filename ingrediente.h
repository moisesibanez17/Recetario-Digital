#ifndef INGREDIENTE_H_INCLUDED
#define INGREDIENTE_H_INCLUDED

#include <string>
#include <iostream>

class Ingrediente {
private:
    std::string cantidad;
    std::string nombre;
public:
    Ingrediente();
    Ingrediente(const Ingrediente&);

    std::string getCantidad() const;
    std::string getNombre() const;

    std::string toString() const;

    void setCantidad(const std::string&);
    void setNombre(const std::string&);

    bool operator == (const Ingrediente&) const;
    bool operator != (const Ingrediente&) const;
    bool operator < (const Ingrediente&) const;
    bool operator <= (const Ingrediente&) const;
    bool operator > (const Ingrediente&) const;
    bool operator >= (const Ingrediente&) const;

    Ingrediente& operator = (const Ingrediente&);

    friend std::ostream& operator << (std::ostream&, Ingrediente&);
    friend std::istream& operator >> (std::istream&, Ingrediente&);
};

#endif // INGREDIENTE_HPP_INCLUDED
