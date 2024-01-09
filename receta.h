#ifndef RECETA_H_INCLUDED
#define RECETA_H_INCLUDED

#include <string>
#include <iostream>

#include "ingrediente.h"
#include "ListSimple.h"
#include "name.h"

class Receta{
private:
    std::string tipo;
    std::string receta;
    std::string tiempo;
    ListSimple<Ingrediente> ingrediente;
    std::string procedimiento;
    Name nombreautor;

public:
    Receta();
    Receta(const Receta&);

    std::string getTipo() const;
    std::string getReceta() const;
    std::string getTiempo() const;
    std::string getIngrediente() const;
    std::string getProcedimiento() const;
    Name getNombreAutor() const;

    std::string toString() const;

    void setTipo(const std::string&);
    void setReceta(const std::string&);
    void setTiempo(const std::string&);
    void setIngrediente(const ListSimple<Ingrediente>&);
    void setProcedimiento(const std::string&);
    void setNombreAutor(const Name&);

    void addIngrediente(const Ingrediente&);
    void deleteIngrediente(const Ingrediente&);
    void deleteAllIngrediente();
    void changeCantidadIngrediente(const Ingrediente&, std::string);

    bool operator == (const Receta&) const;
    bool operator != (const Receta&) const;
    bool operator < (const Receta&) const;
    bool operator <= (const Receta&) const;
    bool operator > (const Receta&) const;
    bool operator >= (const Receta&) const;

    Receta& operator = (const Receta&);

    friend std::ostream& operator << (std::ostream&, Receta&);
    friend std::istream& operator >> (std::istream&, Receta&);
};
#endif // Receta_HPP_INCLUDED
