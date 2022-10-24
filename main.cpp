#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<vector>


using namespace std;

/*Terminales de ómnibus
La información de las terminales estará dada en un archivo de texto terminales.txt que deberá
leerse al iniciar la aplicación.
En cada línea del archivo estará la información de la terminal, separada por espacios:
codigo nombre ciudad pais superficie #cantidad_terminales #destinos_nacionales
#destinos_internacionales
El código son tres letras que identifica a cada terminal. Por ejemplo, RET es la terminal de
Retiro, COR es la teminal de Córdoba capital.
La superficie es un número flotante que indica los km2. Los últimos tres datos son números
enteros con las cantidades correspondientes.
Ejemplo:
RET Terminal de Retiro Argentina 34.75 4 12 46
COR Terminal de Córdoba Argentina 14 9 87 69
Se debe mostrar un menú en el cual se pueda:
- consultar por una terminal en particular
- dar de alta una nueva terminal
- dar de baja a alguna
- mostrar todas las terminales (ordenados por los distintos datos)
Consideraciones
- El archivo está bien formado.
- La implementación debe utilizar una tabla de hashing.
- La función de hashing a utilizar debe lograr una buena dispersión.
*/

void mostrarDatos();
void opciones();
int numero;
int main() {
    opciones();
    return 0;

}

void mostrarDatos(){
    string line;
    vector<string> lines;
    ifstream myfile ("c:/users/joel/documents/github/algoritmos/tpfinalalgoritmos/terminales.txt", ios::in);
    if (myfile.is_open()){
        while(getline(myfile,line)){
            lines.push_back(line);
        }
        myfile.close();
    }
    else cout<<"No se puede abrir el archivo";

    for(int i=0; i<lines.size(); ++i){
        cout<<lines[i]<<'\n';
    }
}

void agregarTerminal(){
    ofstream myfile;
    myfile.open("c:/users/joel/documents/github/algoritmos/tpfinalalgoritmos/terminales.txt", ios::app);
    string codigo, nombre, ciudad, pais;
    float superficie;
    int cantidadTerminales, destinosNacionales, destinosInternacionales;
    cout<<"Ingrese el codigo de la terminal: ";
    cin>>codigo;
    cout<<"Ingrese el nombre de la terminal: ";
    cin>>nombre;
    cout<<"Ingrese la ciudad de la terminal: ";
    cin>>ciudad;
    cout<<"Ingrese el pais de la terminal: ";
    cin>>pais;
    cout<<"Ingrese la superficie de la terminal: ";
    cin>>superficie;
    cout<<"Ingrese la cantidad de terminales de la terminal: ";
    cin>>cantidadTerminales;
    cout<<"Ingrese la cantidad de destinos nacionales de la terminal: ";
    cin>>destinosNacionales;
    cout<<"Ingrese la cantidad de destinos internacionales de la terminal: ";
    cin>>destinosInternacionales;
    myfile<<codigo<<" "<<nombre<<" "<<ciudad<<" "<<pais<<" "<<superficie<<" "<<cantidadTerminales<<" "<<destinosNacionales<<" "<<destinosInternacionales<<endl;
    myfile.close();
}

void opciones(){
    cout << "\n\nMenu de Opciones" << endl;
    cout << "1. Mostrar todas las terminales" << endl;
    cout << "2. Agregar una terminal" << endl;
    cout << "3. Salir" << endl;


    cout<<"Ingrese un numero entre 1 y 5 segun desee: ";
    cin>>numero;


    switch(numero){
        case 1:
            mostrarDatos(); break;
        case 2:
            agregarTerminal(); break;
        case 3:
            cout<<"Adios"; break;

        default:
            cout<<"Opcion incorrecta";
            opciones();
    }
}