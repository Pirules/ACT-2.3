#include <string>
#include <fstream>
#include "DataStruct.h"

using namespace std;


int main(){
    DataStruct<string> info;
    string input, fecha, mes;
    ifstream archivoIn("bitacora.txt");
    int dia, horas, minutos, segundos, posInicial, posFinal;
    time_t dateI, dateF;
    while(getline(archivoIn,input)){
      info.addLast(input);
    }
    archivoIn.close();
    info.ordenaMerge(&info.head);
    //info.printList();
    

    
    //pedimos al usuario fechas para delimitar la busqueda
    cout<<"Introduce la fecha inicial de la busqueda con el formato de la bitacora:"<<endl;
    getline(cin,fecha); 
    dateI = getFecha(fecha);

    cout<<"Introduce la fecha limite de la busqueda con el formato de la bitacora:"<<endl;
    getline(cin,fecha); 
    dateF = getFecha(fecha);
    cout<<endl;


    //obtenemos la posicion de inicio y de fin de los datos a depsplegar con busqueda binaria
    posInicial = info.binarySearch(dateI);
    posFinal = info.binarySearch(dateF);
    //imprimimos en consola los resultados de la busqueda
    ofstream e ("resultado_busqueda.txt");
    for (int i=posInicial; i<=posFinal;i++){
      info.imprimirAt(i);
      info.guardarAt(i,e);
    } 
    e.close();
    
    //guardamos en archivo la bitacora ordenada
    ofstream o ("bitacora_ordenada.txt");
    info.guardarLista(o);
    o.close();

    return 0;
}