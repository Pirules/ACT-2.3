#ifndef _DATASTRUCT_H_
#define _DATASTRUCT_H_

  #include <climits>
  #include "Node.h"

  template <class T>
  class DataStruct {
      private:
        Node<T>* head;
        Node<T>* tail;
        int numElements;

      public:
        DataStruct();
        ~DataStruct();
        int getNumElements();
        void printList();
        void addFirst(T value);
        void addLast(T value);
        bool deleteData(T value);
        bool deleteAt(int position);
        T getData(int position);

        
      
  };

  template<class T>
  DataStruct<T>::DataStruct() {
      //std::cout << "--->Creando una lista vacia " << this << std::endl;
      head = NULL;
      tail = NULL;
      numElements = 0;
  }
  
  template<class T>
  DataStruct<T>::~DataStruct() {
    //std::cout << "--->Liberando memoria de la lista " << this << std::endl;
    Node<T> *p, *q;
    p = head;
    while (p != NULL) {
      q = p->next;
      delete p;
      p = q;
    }
    head = NULL;
    tail = NULL;
    numElements = 0;
  }
 
  template<class T>
  int DataStruct<T>::getNumElements() {
    return numElements;
  }
  template<class T>
  void DataStruct<T>::printList() {
    Node<T> *ptr = head;
    while (ptr != NULL) {
        std::cout << ptr->mes<<"";
        std::cout << ptr->dia<<"";
        std::cout << ptr->horas<<":";
        std::cout << ptr->minutos<<":";
        std::cout << ptr->segundos<<" ";
        std::cout << ptr->ip<<endl;
        ptr = ptr->next;
    }
    std::cout << std::endl;
  }

  template<class T>
  void DataStruct<T>::addFirst(T value) {
    Node<T> *newNode = new Node<T>(value);
    // Si la lista esta vacia 
    if (head == NULL) {
      head = newNode;
      tail = newNode;
    }
    else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    numElements++;
  }
  
  template<class T>
  void DataStruct<T>::addLast(T value) {
    // La lista esta vacia
    if (head == NULL) {
      addFirst(value);
    }
    else {
      Node<T> *newNode = new Node<T>(value);
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
      numElements++;
    }    
  }
  
  template<class T>
  bool DataStruct<T>::deleteData(T value) {
    Node<T> *p, *q;
    p = head;
    q = NULL;
    // Si la lista esta vacia 
    if (p == NULL) {
      return false;
    }
    else {
      // buscar value en la lista
      while (p != NULL && p->data != value) {
        q = p;
        p = p->next;
      }
      // Si no existe value en la lista
      if (p == NULL)
        return false;
      // Si debe borrarse el primer elemento
      if (p->prev == NULL) {
        head = p->next;
        if (head != NULL)
          head->prev = NULL;
      }
      else if (p->next == NULL) { 
        // Si debe borrarse el último elemento
        q->next = NULL;
        tail = q;
      }
      else {
        // Cualquier otro elemento entre la lista 
        q->next = p->next;
        p->next->prev = q;
      }
      delete p;
      numElements--;
      return true;
    }
  }

  template<class T>
  bool DataStruct<T>::deleteAt(int position) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
      return false;
    }
    else if (position == 0) { // Si debe borrarse el primer elemento
      Node<T> *p = head;
      // Si la lista contiene solo un nodo
      if (head != NULL && head->next == NULL) {
        head = NULL;
        tail = NULL;  
      }
      else {
        head = p->next;
        head->prev = NULL;
      }
      delete p;
      numElements--;
      return true; 
    }
    else { 
      Node<T> *p = head, *q = NULL;
      int index = 0;
      while (index != position) {
        q = p;
        p = p->next;
        index++;
      }
      // Si debe borrarse el último elemento
      if (p->next == NULL) {
        q->next = NULL;
        tail = q;
      }
      else { // Cualquier otro elemento entre la lista 
        q->next = p->next;
        p->next->prev = q;
      }
      delete p;
      numElements--;
      return true;
    }
  }
  
  template<class T>
  T DataStruct<T>::getData(int position) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
      return -1;
    }
    else {
      if (position == 0)
        return head->data;
      Node<T> *p = head;
      int index = 0;
      while (p != NULL) {
        if (index == position)
          return p->data;
        index++;
        p = p->next;
      }
      return -1;
    }
  }
  
#endif // _DATASTRUCT_H_