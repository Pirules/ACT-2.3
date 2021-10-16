#ifndef _NODE_H_
#define _NODE_H_

#include<iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

  template <class T>
  class Node { 
  public: 
      struct tm dateStruct;
      T mes, razon, ip;
      T dia, horas, minutos, segundos;
      time_t date;
      string lineaNodo;
      Node<T>* next;
      Node<T>* prev;
      Node();
      Node(T);
      void setValues(Node<T>* nodo);
      void imprimir();
      void guardar(ofstream &o);
      vector<string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};  
  }; 

  template<class T>
  Node<T>::Node(){
      razon = 0;
      mes = 0;
      ip = 0;
      dia = 0;
      horas = 0;
      minutos = 0;
      segundos = 0;
      date = 0;
      next = NULL;
      prev = NULL;
  }
  template<class T>
  Node<T>::Node(T linea){
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
    next = NULL;
    prev = NULL;
    this->lineaNodo = linea;
  }
  template<class T>
  void Node<T>::setValues(Node<T>* nodo){
    razon = nodo->razon;
    mes = nodo->mes;
    ip = nodo->ip;
    dia = nodo->dia;
    horas = nodo->horas;
    minutos = nodo->minutos;
    segundos = nodo->segundos;
    date = nodo->date;
  }

  
  template<class T>
  void Node<T>::imprimir(){
    cout<<mes<<"";
    cout<<dia<<"";
    cout<<horas<<":";
    cout<<minutos<<":";
    cout<<segundos<<" ";
    cout<<ip<<endl;
    //cout<<razon<<" ";
    //o<<razon<<" "<<endl;
}

  template<class T>
  void Node<T>::guardar(ofstream &o){
    o<<mes<<"";
    o<<dia<<"";
    o<<horas<<":";
    o<<minutos<<":";
    o<<segundos<<" ";
    o<<ip<<endl;
    //o<<razon<<" "<<endl;
}

#endif // _NODE_H_