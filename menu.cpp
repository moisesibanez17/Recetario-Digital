#include "menu.h"

using namespace std;

Menu::Menu(ListDoble<Receta> &myListReceta){
    userInterface(myListReceta);
}

void Menu::userInterface(ListDoble<Receta> &myListReceta){
    Receta myReceta;
    Ingrediente myIngrediente;
    ListSimple<Ingrediente> myListIngrediente;
    Name myName;
    string myStr;
    bool z = true;
    ListDoble<Receta>::Position pos;
    int o;


    cout << "Leyendo del disco";
    myListReceta.readFromDisk("Receta.txt");

    while(z == true){
        system("cls");
        cout <<"--------Menu--------\n\n";
        cout <<"1.- Mostrar recetas"<<endl;
        cout <<"2.- Mostrar recetas por categoria"<<endl;
        cout <<"3.- Insertar receta"<<endl;
        cout <<"4.- Buscar receta"<<endl;
        cout <<"5.- Eliminar receta"<<endl;
        cout <<"6.- Eliminar todas las recetas"<<endl;
        cout <<"7.- Ordenar recetas"<<endl;
        cout <<"6.- Salir"<<endl;
        cout <<"Selecciona una opcion: ";
        cin >> o;
        cin.ignore();

        switch(o){
            case 1: 
                system("cls");
                cout << "______Mostrar Recetas______" << endl;
                cout << "Contenido de la Lista: " << endl;             
                    myListReceta.toString();
                    myListIngrediente.toString();
                    system("pause");
            break;
            /*
            case 2:
                
            case 3:
                system("cls");
                cout << "_______Insertar Receta______" << endl;
                cout << "Tipo: ";
                getline(cin, myStr);
                myReceta.setTipo(myStr);

                cout << "Nombre de la receta: ";
                getline(cin, myStr);
                myReceta.setReceta(myStr);

                cout << "Tiempo: ";
                getline(cin, myStr);
                myReceta.setTiempo(myStr);

                cout << "Cantidad del ingrediente: ";
                getline(cin, myStr);
                myIngrediente.setCantidad(myStr);

                cout << "Nombre del ingrediente: ";
                getline(cin, myStr);
                myIngrediente.setNombre(myStr);

                Aux.insertData(Aux.getLastPos(), myIngrediente);

                myReceta.setIngrediente(Aux);

                cout << "Procedimiento: ";
                getline(cin, myStr);
                myReceta.setProcedimiento(myStr);

                cout << "Apellido: ";
                getline(cin, myStr);
                myName.setLast(myStr);

                cout << "Nombre(s): ";
                getline(cin,  myStr);
                myName.setFirst(myStr);

                myReceta.setNombreAutor(myName);

                myListDoble.insertData(myListDoble.getLastPos(), myReceta);
            break;
            case 4:
                system("cls");
                cout << "______Buscar Receta______" << endl;
                cout << "Nombre a buscar: ";
                getline(cin, myStr);
                pos = myListDoble.findData(myReceta);
                cout << "La receta con el nombre " << myStr << " ";
                if(pos == nullptr){
                    cout << "No se encuentra en la ListDoblea";
                }
                else{
                    cout << "Se encuentra en la posicion " << pos << " de la ListDoblea";
                    cout << endl << endl;
                    cout << "Registro encontrado: "  << endl;
                    cout << myListDoble.retrieve(pos).toString() << endl;
                    cout<<"Enter para continuar" <<endl;
                    cin.get();
                }
            break;
            case 5: 
                system("cls");
                cout << "_______Eliminar Receta______" << endl;
                cout << "Nombre de la receta a eliminar: ";
                getline(cin, myStr);
                pos = myListDoble.findData(myReceta);
                cout << "La receta con el nombre " << myStr << " ";
                if(!pos){
                    cout << "No se encuentra en la ListDoblea";
                }
                else{
                    cout << "Se encuentra en la posicion " << pos << " de la ListDoblea";
                    cout << "Registro eliminado: ";
                    cout << myListDoble.retrieve(pos).toString() << endl;
                    cout << "Eliminadolo..." << endl;
                    myListDoble.deleteData(pos);
                    cout<<"Enter para continuar" <<endl;
                    cin.get();
                    }
            break;
            case 6:
                system("cls");
                cout << "_____Eliminar todas las recetas______" << endl;
                myListDoble.deleteAll();
                cout << "Recetario eliminado" <<endl;
                cout<<"Enter para continuar" <<endl;
                cin.get();
            break;
            case 7:
                system("cls");
                cout << "_______Ordenar recetas_________" << endl;
                myListDoble.Sort();
                cout << "Recetas ordenadas" <<endl;
                cout<<"Enter para continuar" <<endl;
                cin.get();
            break; */
        }

   }
    cout<<"Fin del programa" <<endl;
    cin.get();
}

