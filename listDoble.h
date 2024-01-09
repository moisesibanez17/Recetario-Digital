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
            Node* prev;
            Node* next;

            public:
            Node();
            Node(const T&);

            T getData() const;
            Node* getPrev() const;
            Node* getNext() const;

            void setData(const T&);
            void setPrev(Node*);
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
        void insertSortedData(Node*, const T&);

        void deleteData(Node*);

        Node* getFirstPos() const;
        Node* getLastPos() const;
        Node* getPrevPos(Node*) const;
        Node* getNextPos(Node*) const;

        Node* findData(const T&) const;

        void swapData(Node*, Node*);
        Node* partition(Node*, Node*);
        void quickSort(Node*, Node*);
        void quickSort();

        T retrieve(Node*);

        void readFromDisk(const std::string&);
        void writeToDisk(const std::string&);

        std::string TipotoString(const T&, int cmp(const T&, const T&)) const;
        std::string toString() const;

        void deleteAll();

        ListDoble<T>& operator = (const ListDoble<T>&);
};

///Implementacion

//Nodo
template <class T>
ListDoble<T>::Node::Node() : prev(nullptr), next(nullptr) { }

template <class T>
ListDoble<T>::Node::Node(const T& e) : data(e), prev(nullptr), next(nullptr) { }

template <class T>
T ListDoble<T>::Node::getData() const{
    return data;
}

template <class T>
typename ListDoble<T>::Node* ListDoble<T>::Node::getPrev() const{
    return prev;
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
void ListDoble<T>::Node::setPrev(Node* p){
    prev = p;
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
        if((newNode = new Node(aux->getData())) == nullptr){
            throw Exception("MEmoria no disponible, copyAll");
        }

        if(last == nullptr){
            anchor = newNode;
        }
        else{
            newNode->setPrev(last);

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
        
        if(anchor != nullptr){
            anchor->setPrev(aux);
        }

        anchor = aux;
    }
    else{
        aux->setPrev(p);
        aux->setNext(p->getNext());

        if(p->getNext() != nullptr){
            p->getNext()->setPrev(aux);
        }

        p->setNext(aux);
    }
}

template <class T>
void ListDoble<T>::insertSortedData(Node* p, const T& e) {
    if(p != nullptr && !isValidPos(p)){
        throw Exception("Posicion invalida, insertData");
    }

    Node* aux(new Node(e));

    if(aux == nullptr){
        throw Exception("Memoria no disponible, insertData");
    }

    if (isEmpty() || e < anchor->getData()) {
        aux->setNext(anchor);
        if(anchor != nullptr){
            anchor->setPrev(aux);
        }
        anchor = aux;
    }
    else {
        Node* q = anchor;
        while(q->getNext() != nullptr && q->getNext()->getData() < e) {
            q = q->getNext();
        }
        aux->setPrev(q);
        aux->setNext(q->getNext());
        if(q->getNext() != nullptr){
            q->getNext()->setPrev(aux);
        }
        q->setNext(aux);
    }
}

template <class T>
void ListDoble<T>::deleteData(Node* p){
    if(!isValidPos(p)){
        throw Exception("Posicion invalida, deleteData");
    }

    if(p->getPrev() != nullptr){
        p->getPrev()->setNext(p->getPrev());
    }

    if(p->getNext() != nullptr){
        p->getNext()->setPrev(p->getPrev());
    }

    if(p == anchor){
        anchor = anchor->getNext();
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
    if(!isValidPos(p)){
        return nullptr;
    }

    return p->getPrev();
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
void ListDoble<T>::swapData(Node* p, Node* q){
    T temp = p->getData();
    p->setData(q->getData());
    q->setData(temp);
}

template <class T>
typename ListDoble<T>::Node* ListDoble<T>::partition(Node* left, Node* right){
    T pivot = right->getData();
    Node* i = left->getPrev();

    for (Node* j = left; j != right; j = j->getNext()){
        if (j->getData() <= pivot){
            i = (i == nullptr) ? left : i->getNext();
            swapData(i, j);
        }
    }

    i = (i == nullptr) ? left : i->getNext();
    swapData(i, right);
    return i;
}

template <class T>
void ListDoble<T>::quickSort(Node* left, Node* right){
    if (right != nullptr && left != right && left != right->getNext()){
        Node* pivot = partition(left, right);
        quickSort(left, pivot->getPrev());
        quickSort(pivot->getNext(), right);
    }
}

template <class T>
void ListDoble<T>::quickSort(){
    quickSort(getFirstPos(), getLastPos());
}

template <class T>
T ListDoble<T>::retrieve(Node* p){
    if(!isValidPos(p)){
        throw Exception("Posicion invalida, retrieve");
    }

    return p->getData();
}

template <class T>
std::string ListDoble<T>::TipotoString(const T& e, int cmp(const T&, const T&)) const{
    std::string result;
    Node* aux(anchor->getNext());
    while(aux != anchor){
        if(cmp(e,aux->getData()) == 0){
            result += aux->getData().toString() + "\n";
        }
        aux = aux->getNext();
    }
    return result;
}

template <class T>
std::string ListDoble<T>::toString() const{
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
    T data;
    while (currentNode != nullptr) {
        data = currentNode->getData();
        myFile << data << std::endl;
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