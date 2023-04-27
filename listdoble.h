#ifndef ListDoble_H_INCLUDED
#define ListDoble_H_INCLUDED

#include <exception>
#include <string>
#include <fstream>

///Definicion
template <class T>
class ListDoble {
    private:
        class Node {
            private:
            T data;
            Node* next;

            public:
            Node();
            Node(const T&);

            T getData() const;
            Node* getNext() const;

            void setData(const T&);
            void setNext(Node*); 
        };

        Node* anchor;

        bool isValidPos(Node*) const;

        void copyAll(const ListDoble<T>&);

    public:
        typedef Node* Position;

        class Exception : public std::exception{
        private:
            std::string msg;

        public: 
            explicit Exception(const char* message) : msg(message) {}
            explicit Exception(const std::string& message) : msg(message) {}
            virtual ~Exception() throw () {}
            virtual const char* what() const throw () {
                return msg.c_str();
            }

    };

        ListDoble();
        ListDoble(const ListDoble<T>&);

        ~ListDoble();

        bool isEmpty() const;

        void insertData(Node*, const T&);

        void deleteData(Node*);

        Node* getFirstPos() const;
        Node* getLastPos() const;
        Node* getPrevPos(Node*) const;
        Node* getNextPos(Node*) const;

        Node* findData(const T&) const;

        void Sort();

        T retrieve(Node*) const;

        void readFromDisk(const std::string&);
        void writeToDisk(const std::string&);

        std::string toString() const;

        void deleteAll();

        ListDoble<T>& operator = (const ListDoble<T>&);
};

///Implementacion

//Nodo
template <class T>
ListDoble<T>::Node::Node() : next(nullptr) { }

template <class T>
ListDoble<T>::Node::Node(const T& e) : data(e), next(nullptr) { }

template <class T>
T ListDoble<T>::Node::getData() const{
    return data;
}

template <class T>
typename ListDoble<T>::Node* ListDoble<T>::Node::getNext() const{
    return next;
}

template <class T>
void ListDoble<T>::Node::setData(const T& e){
    data = e;
}

template <class T>
void ListDoble<T>::Node::setNext(Node* p){
    next = p;
}

//ListDoblea

template <class T>
void ListDoble<T>::copyAll(const ListDoble<T>& l){
    Node* aux(l.anchor);
    Node* last(nullptr);
    Node* newNode;

    while(aux != nullptr){
        newNode = new Node(aux->getData());

        if(last == nullptr){
            anchor = newNode;
        }
        else{
            last->setNext(newNode);
        }

        last = newNode;

        aux = aux->getNext();
    }
}

template <class T>
bool ListDoble<T>::isValidPos(Node* p) const{
    Node* aux(anchor);

    while(aux != nullptr){
        if(aux == p){
            return true;
        }
    
    aux = aux->getNext();
    }

    return false;
}

template <class T>
ListDoble<T>::ListDoble() : anchor(nullptr) { }

template <class T>
ListDoble<T>::ListDoble(const ListDoble<T>& l) : anchor(nullptr) {
    copyAll(l);
} 

template <class T>
ListDoble<T>::~ListDoble() {
    deleteAll();
}

template <class T>
bool ListDoble<T>::isEmpty() const{
    return anchor == nullptr;
}

template <class T>
void ListDoble<T>::insertData(Node* p, const T& e) {
    if(p != nullptr && !isValidPos(p)){
        throw Exception("Posicion invalida, insertData");
    }

    Node* aux(new Node(e));

    if(aux == nullptr){
        throw Exception("Memoria no disponible, insertData");
    }

    if(p == nullptr) {
        aux->setNext(anchor);
        anchor=aux;
    }
    else{
        aux->setNext(p->getNext());
        p->setNext(aux);
    }
}

template <class T>
void ListDoble<T>::deleteData(Node* p){
    if(!isValidPos(p)){
        throw Exception("Posicion invalida, deleteData");
    }

    if(p == anchor){
        anchor == anchor->getNext();
    }
    else{
        getPrevPos(p)->setNext(p->getNext());
    }

    delete p;
}

template <class T>
typename ListDoble<T>::Node* ListDoble<T>::getFirstPos() const{
    return anchor;
}

template <class T>
typename ListDoble<T>::Node* ListDoble<T>::getLastPos() const{
    if(isEmpty()){
        return nullptr;
    }

    Node* aux(anchor);
    while(aux->getNext() != nullptr){
        aux = aux->getNext();
        }
    return aux;
} 

template <class T>
typename ListDoble<T>::Node* ListDoble<T>::getPrevPos(Node* p) const {
    if(p == anchor){
        return nullptr;
    }

    Node* aux(anchor);

    while(aux != nullptr && aux->getNext() != p){
        aux = aux->getNext();
        }
    return aux;
} 

template <class T>
typename ListDoble<T>::Node* ListDoble<T>::getNextPos(Node* p) const {
    if(!isValidPos(p)){
        return nullptr;
    }

    return p->getNext();
}

template <class T>
typename ListDoble<T>::Node* ListDoble<T>::findData(const T& e) const {
    Node* aux(anchor);

    while(aux != nullptr && aux->getData() != e){
        aux = aux->getNext();
    }

    return aux;
}

template <class T>
void ListDoble<T>::Sort() {
    if (isEmpty() || anchor->getNext() == nullptr) {
        return;
    }

    bool swapped;
    Node* current;
    Node* previous = nullptr;

    do {
        swapped = false;
        current = anchor;

        while (current->getNext() != previous) {
            if (current->getData() > current->getNext()->getData()) {
                T tempData = current->getData();
                current->setData(current->getNext()->getData());
                current->getNext()->setData(tempData);
                swapped = true;
            }
            current = current->getNext();
        }
        previous = current;

    } while (swapped);
}

template <class T>
T ListDoble<T>::retrieve(Node* p) const{
    if(!isValidPos(p)){
        throw Exception("Posicion invalida, retrieve");
    }

    return p->getData();
}

template <class T>
std::string ListDoble<T>::toString() const {
    Node* aux(anchor);
    std::string result;

    while(aux != nullptr){
        result+=aux->getData().toString() + "\n";

        aux = aux->getNext();
    }

    return result;
}

template <class T>
void ListDoble<T>::readFromDisk(const std::string& fileName) {
    std::ifstream myFile;
    T myData;

    myFile.open(fileName);

    if (!myFile.is_open()) {
        throw Exception("No se pudo abrir el archivo para lectura");
    }

    // Eliminar todos los elementos antes de cargar desde el archivo
    deleteAll();

    Node* lastNode = nullptr;

    while (myFile >> myData) {
        Node* newNode = new Node(myData);
        if (anchor == nullptr) {
            anchor = newNode;
        } else {
            lastNode->setNext(newNode);
        }
        lastNode = newNode;
    }

    myFile.close();
}

template <class T>
void ListDoble<T>::writeToDisk(const std::string& fileName) {
    std::ofstream myFile;

    myFile.open(fileName, std::ios_base::trunc);

    if (!myFile.is_open()) {
        throw Exception("No se pudo abrir el archivo para escritura");
    }

    Node* currentNode = anchor;
    while (currentNode != nullptr) {
        myFile << currentNode->getData() << std::endl;
        currentNode = currentNode->getNext();
    }

    myFile.close();
}


template <class T>
void ListDoble<T>::deleteAll() {
    Node* aux;

    while(anchor != nullptr) {
        aux = anchor;

        anchor = anchor->getNext();

        delete aux;
    }
}

template <class T>
ListDoble<T>& ListDoble<T>::operator = (const ListDoble<T>& l){
    deleteAll();

    copyAll(l);

    return *this;
}

#endif