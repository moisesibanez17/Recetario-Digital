#ifndef NAME_H_INCLUDED
#define NAME_H_INCLUDED

#include <iostream>
#include <string>

class Name {
private:
    std::string last;
    std::string first;

public:
    Name();
    Name(const Name&);

    std::string getLast() const;
    std::string getFirst() const;

    std::string toString() const;

    void setLast(const std::string&);
    void setFirst(const std::string&);

    bool operator == (const Name&) const;
    bool operator != (const Name&) const;
    bool operator < (const Name&) const;
    bool operator <= (const Name&) const;
    bool operator > (const Name&) const;
    bool operator >= (const Name&) const;

    Name& operator = (const Name&);

    friend std::ostream& operator << (std::ostream&, Name&);
    friend std::istream& operator >> (std::istream&, Name&);
};

#endif