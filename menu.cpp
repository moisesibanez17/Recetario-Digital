#include "menu.h"

using namespace std;

Menu::Menu(ListDoble<Receta> &myListReceta){
    userInterface(myListReceta);
}

void Menu::userInterface(ListDoble<Receta> &myListReceta){
    Receta myReceta;
    Ingrediente myIngrediente;
    ListSimple<Ingrediente> Aux;
    Name myName;
    string myStr, nose = "S";
    bool z = true;
    ListDoble<Receta>::Position pos;
    int o;


    cout << "Leyendo del disco";
    myListReceta.readFromDisk("Receta.txt");

    while(z == true){
        system("cls");
        cout <<"--------------------------------------------------------------" <<endl;
        cout <<"|                                                            |" << endl;
        cout <<"|                            MENU                            |" << endl;
        cout <<"|                                                            |" << endl;
        cout <<"|        1.-  Mostrar recetas                                |"<<endl;
        cout <<"|        2.-  Mostrar recetas por categoria                  |"<<endl;
        cout <<"|        3.-  Insertar receta                                |"<<endl;
        cout <<"|        4.-  Buscar receta                                  |"<<endl;
        cout <<"|        5.-  Eliminar receta                                |"<<endl;
        cout <<"|        6.-  Eliminar todas las recetas                     |"<<endl;
        cout <<"|        7.-  Ordenar recetas                                |"<<endl;
        cout <<"|        8.-  Agregar un ingrediente de una receta           |"<<endl;
        cout <<"|        9.-  Eliminar un ingrediente de una receta          |"<<endl;
        cout <<"|       10.- Eliminar todos los ingredientes de una receta   |"<<endl;
        cout <<"|       11.- Modificar la cantidad de un ingrediente         |"<<endl;
        cout <<"|       12.- Modificar el procedimiento de una receta        |"<<endl;  
        cout <<"|       13.- Escribir al disco                               |"<<endl;
        cout <<"|       14.- Leer del disco                                  |"<<endl;        
        cout <<"|        0.- Salir                                           |"<<endl;
        cout <<"|                                                            |"<<endl;
        cout <<"--------------------------------------------------------------"<<endl;
        cout <<"Selecciona una opcion: ";
        cin >> o;
        cin.ignore();

        switch(o){
            case 1:{
                system("cls");
                cout << "-------------------------------------------" << endl;      
                cout << "|              Mostrar recetas             |" << endl;
                cout << "-------------------------------------------" << endl;    
                cout << myListReceta.toString();
                cout<<"Presiona cualquier tecla para continuar" <<endl;
                cin.get();
            break;
            }
            case 2:{
                ListDoble<Receta> Cat;
                Receta auxReceta;
                int sel;
                string Categoria, auxCategoria;
                ListDoble<Receta>::Position aux(myListReceta.getFirstPos());
                system("cls");
                cout << "-------------------------------------------" << endl;      
                cout << "|      Mostrar recetas por categoria       |" << endl;
                cout << "-------------------------------------------" << endl;
                cout << "Categoria" << endl;
                cout << "- Desayuno\n- Comida\n- Cena\n- Navideño\nEscribe una opcion: ";
                cin >> Categoria;
                do{
                    auxReceta = myListReceta.retrieve(aux);
                    auxCategoria = auxReceta.getTipo();
                    if(auxCategoria.compare(Categoria) == 0){
                        cout << "Paso 2" << endl;
                        Cat.insertData(Cat.getLastPos(),auxReceta);
                    }
                    aux = aux->getNext();
                }while(aux != nullptr);
                cout << Cat.toString();
                system("pause");
            break;
            }
            case 3:{
                system("cls");
                cout << "-------------------------------------------" << endl;      
                cout << "|            Insertar Receta               |" << endl;
                cout << "-------------------------------------------" << endl;
                cout << "Tipo: ";
                getline(cin, myStr);
                myReceta.setTipo(myStr);

                cout << "Nombre de la receta: ";
                getline(cin, myStr);
                myReceta.setReceta(myStr);

                cout << "Tiempo: ";
                getline(cin, myStr);
                myReceta.setTiempo(myStr);

                do{
                    cout << "Cantidad del ingrediente: ";
                    getline(cin, myStr);
                    myIngrediente.setCantidad(myStr);

                    cout << "Nombre del ingrediente: ";
                    getline(cin, myStr);
                    myIngrediente.setNombre(myStr);

                    Aux.insertData(Aux.getLastPos(), myIngrediente);

                    cout << "Deseas agregar otro ingrediente: (S/N)";
                    getline(cin, nose);
                } while(nose == "S");
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

                myListReceta.insertData(myListReceta.getLastPos(), myReceta);
                cout<<"Presiona cualquier tecla para continuar" <<endl;
                cin.get();
            break;
            }
            case 4:{
                system("cls");
                cout << "-------------------------------------------" << endl;      
                cout << "|              Buscar Receta               |" << endl;
                cout << "-------------------------------------------" << endl;
                cout << "Nombre a buscar: ";
                getline(cin, myStr);
                myReceta.setReceta(myStr);
                pos = myListReceta.findData(myReceta);
                cout << "La receta con el nombre " << myStr << " ";
                if(pos == nullptr){
                    cout << "No se encuentra en la Lista";
                }
                else{
                    cout << "Se encuentra en la posicion " << pos << " de la Lista";
                    cout << endl << endl;
                    cout << "Registro encontrado: "  << endl;
                    cout << myListReceta.retrieve(pos).toString() << endl;
                    cout<<"Presiona cualquier tecla para continuar" <<endl;
                    cin.get();
                }
            break;
            }
            case 5:{ 
                system("cls");
                cout << "-------------------------------------------" << endl;      
                cout << "|            Eliminar Receta               |" << endl;
                cout << "-------------------------------------------" << endl;
                cout << "Nombre de la receta a eliminar: ";
                getline(cin, myStr);
                myReceta.setReceta(myStr);
                pos = myListReceta.findData(myReceta);
                cout << "La receta con el nombre " << myStr << " ";
                if(!pos){
                    cout << "No se encuentra en la ListDoblea";
                }
                else{
                    cout << "Se encuentra en la posicion " << pos << " de la ListDoblea";
                    cout << "Registro eliminado: ";
                    cout << myListReceta.retrieve(pos).toString() << endl;
                    cout << "Eliminadolo..." << endl;
                    myListReceta.deleteData(pos);
                    cout<<"Presiona cualquier tecla para continuar" <<endl;
                    cin.get();
                    }
            break;
            }
            case 6:{
                system("cls");
                cout << "-------------------------------------------" << endl;      
                cout << "|       Eliminar todas las Recetas         |" << endl;
                cout << "-------------------------------------------" << endl;
                myListReceta.deleteAll();
                cout << "Recetario eliminado" <<endl;
                cout<<"Presiona cualquier tecla para continuar" <<endl;
                cin.get();
            break;
            }
            case 7:{
                system("cls");
                cout << "-------------------------------------------" << endl;      
                cout << "|            Ordenar Receta                |" << endl;
                cout << "-------------------------------------------" << endl;
                myListReceta.quickSort();
                cout << "Recetas ordenadas" <<endl;
                cout<<"Presiona cualquier tecla para continuar" <<endl;
                cin.get();
            break;
            }
            case 8:{
                system("cls");
                cout << "-------------------------------------------" << endl;      
                cout << "|          Agregar Ingrediente             |" << endl;
                cout << "-------------------------------------------" << endl;
                cout << "Nombre de la receta: ";
                getline(cin, myStr);
                myReceta.setReceta(myStr);
                pos = myListReceta.findData(myReceta);

                cout << "Cantidad del ingrediente a agregar: " << endl;
                getline(cin,myStr);
                myIngrediente.setCantidad(myStr);
                cout << "Nombre del ingrediente a agregar: " << endl;
                getline(cin,myStr);
                myIngrediente.setNombre(myStr);

                myReceta = myListReceta.retrieve(pos);
                myReceta.addIngrediente(myIngrediente);

                cout << "Receta actualizada:" <<endl;
                cout << myReceta.toString();
                
                myListReceta.deleteData(pos);
                pos = myListReceta.getLastPos();
                myListReceta.insertSortedData(pos, myReceta);
                
                cout << "\nIngrediente agregado" << endl;
                cout<<"Presiona cualquier tecla para continuar" <<endl;
                cin.get();
            break;
            }
            case 9:{
                system("cls");
                cout << "-------------------------------------------" << endl;      
                cout << "|          Eliminar Ingrediente            |" << endl;
                cout << "-------------------------------------------" << endl;
                cout << "Nombre de la receta: ";
                getline(cin, myStr);
                myReceta.setReceta(myStr);
                pos = myListReceta.findData(myReceta);

                cout << "Nombre del ingrediente a eliminar: " << endl;
                getline(cin,myStr);
                myIngrediente.setNombre(myStr);

                myReceta = myListReceta.retrieve(pos);
                myReceta.deleteIngrediente(myIngrediente);

                cout << "Receta actualizada:" <<endl;
                cout << myReceta.toString();

                myListReceta.deleteData(pos);
                pos = myListReceta.getLastPos();
                myListReceta.insertSortedData(pos, myReceta);

                cout << "\nIngrediente eliminado" << endl;
                cout<<"Presiona cualquier tecla para continuar" <<endl;
                cin.get();
            break;
            }
            case 10:{
                system("cls");
                cout << "-------------------------------------------" << endl;      
                cout << "|    Eliminar todos los Ingredientes       |" << endl;
                cout << "-------------------------------------------" << endl;
                cout << "Nombre de la receta: ";
                getline(cin, myStr);
                myReceta.setReceta(myStr);
                pos = myListReceta.findData(myReceta);

                myReceta = myListReceta.retrieve(pos);
                myReceta.deleteAllIngrediente();

                cout << "Receta actualizada:" <<endl;
                cout << myReceta.toString();

                myListReceta.deleteData(pos);
                pos = myListReceta.getLastPos();
                myListReceta.insertSortedData(pos, myReceta);

                cout << "\nIngredientes eliminados" << endl;
                cout<<"Presiona cualquier tecla para continuar" <<endl;
                cin.get();
            break;
            }
            case 11:{
                system("cls");
                cout << "-------------------------------------------" << endl;      
                cout << "|    Modificar cantidad de Ingrediente     |" << endl;
                cout << "-------------------------------------------" << endl;
                cout << "Nombre de la receta: ";
                getline(cin, myStr);
                myReceta.setReceta(myStr);
                pos = myListReceta.findData(myReceta);
                cout << "Nombre del ingrediente a eliminar: " << endl;
                getline(cin,myStr);
                myIngrediente.setNombre(myStr);
                cout << "Nueva cantidad del ingrediente: " << endl;
                getline(cin,myStr);

                myReceta = myListReceta.retrieve(pos);
                myReceta.changeCantidadIngrediente(myIngrediente,myStr);

                cout << "Receta actualizada:" <<endl;
                cout << myReceta.toString();

                myListReceta.deleteData(pos);
                pos = myListReceta.getLastPos();
                myListReceta.insertSortedData(pos, myReceta);

                cout << "\nIngrediente actualizado" << endl;
                cout<<"Presiona cualquier tecla para continuar" <<endl;
                cin.get();
            break;
            }
            case 12:{
                system("cls");
                cout << "-------------------------------------------" << endl;      
                cout << "| Modificar procedimienot de una Receta    |" << endl;
                cout << "-------------------------------------------" << endl;
                cout << "Nombre de la receta: ";
                getline(cin, myStr);
                myReceta.setReceta(myStr);
                pos = myListReceta.findData(myReceta);
                cout << "Nueva procedimiento: " << endl;
                getline(cin,myStr);

                myReceta = myListReceta.retrieve(pos);
                myReceta.setProcedimiento(myStr);

                cout << "Receta actualizada:" <<endl;
                cout << myReceta.toString();

                myListReceta.deleteData(pos);
                pos = myListReceta.getLastPos();
                myListReceta.insertSortedData(pos, myReceta);

                cout << "\nProcedimiento actualizado" << endl;
                cout<<"Presiona cualquier tecla para continuar" <<endl;
                cin.get();
            break;
            }
            case 13:{
                system("cls");
                cout << "-------------------------------------------" << endl;      
                cout << "|           Escribir al Disco              |" << endl;
                cout << "-------------------------------------------" << endl;
                cout << "Escribiendo al disco... \n";
                myListReceta.writeToDisk("RecetaNueva.txt");
                cout << "Proceso realizado con exito" << endl;
                cout<<"Presiona cualquier tecla para continuar" <<endl;
                cin.get();
            break;
            }
            case 14:{
                system("cls");
                cout << "-------------------------------------------" << endl;      
                cout << "|              Leer del Disco              |" << endl;
                cout << "-------------------------------------------" << endl;
                cout << "Leyendo del disco... \n";
                myListReceta.readFromDisk("Receta.txt");
                cout << "Proceso realizado con exito" << endl;
                cout<<"Presiona cualquier tecla para continuar" <<endl;
                cin.get();
            break;
            }
            case 0:{
                z = false;
            }

        }
    }
    cout << "Fin del programa" << endl;
    cin.get();
}

