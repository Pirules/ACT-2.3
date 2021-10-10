#include "Datos.h"

using namespace std;

datos::datos(){
}
//todo: cambia todo a strings pon stois en el datastruct
datos::datos(string linea){
    /*Utilizamos substr para subdividir la linea que recibimos del archivo
       y asi guardar nuestaras variables.*/ 
    this->mes = linea.substr(0,linea.find(" "));
    this->dia = linea.substr(3,linea.find(" "));
    this->horas = linea.substr(6,3);
    this->minutos = linea.substr(10,2);
    this->segundos = linea.substr(13,2);
    this->ip = linea.substr(16);
    //this->razon = linea.substr(34);
    
    //Guardamos tiempos en dataStruct
    dateStruct.tm_sec = stoi(linea.substr(13,linea.find(":")));
    dateStruct.tm_min = stoi(linea.substr(10,linea.find(":")));
    dateStruct.tm_hour = stoi(linea.substr(6,linea.find(":")));
    dateStruct.tm_mday = stoi(linea.substr(3,linea.find(" ")));
    dateStruct.tm_isdst = 0;
    for (int i=0; i<meses.size(); i++){
        if (meses[i]==mes)
         dateStruct.tm_mon = i;
    }
    dateStruct.tm_year = 2021 - 1900;
    this->date = mktime(&dateStruct);
    //cout<<this->date<<endl;
}
//funcion para imprimir y guardar en archivo
void datos::imprimir(){
    cout<<mes<<"";
    cout<<dia<<"";
    cout<<horas<<":";
    cout<<minutos<<":";
    cout<<segundos<<" ";
    cout<<ip;
    //cout<<razon<<" ";
    //o<<razon<<" "<<endl;
}
//funcion para guardar bitacora en archivo de texto
void datos::imprimirtxt(ofstream &o){
    //cout<<razon<<" ";
    o<<mes<<"";
    o<<dia<<"";
    o<<horas<<":";
    o<<minutos<<":";
    o<<segundos<<" ";
    o<<ip<<endl;
    //o<<razon<<" "<<endl;
}

int datos::getDate(){
    return this->date;
}

bool datos::operator==(const datos &other) {
  return this->date == other.date;
}

bool datos::operator==(const time_t &other) {
  return this->date == other;
}

bool datos::operator!=(const datos &other) {
  return this->date != other.date;
}

bool datos::operator>(const datos &other) {
  return this->date > other.date;
}

bool datos::operator<(const datos &other) {
  return this->date < other.date;
}

bool datos::operator>(const time_t &other) {
  return this->date > other;
}

bool datos::operator<=(const datos &other) {
  return this->date <= other.date;
}