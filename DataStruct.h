#ifndef _DATASTRUCT_H_
#define _DATASTRUCT_H_

  #include <climits>
  #include "Node.h"
  #include "Queue.h"

  template <class T>
  class DataStruct {
      private:
        int numElements;

      public:
        Node<T>* head;
        Node<T>* tail;
        DataStruct();
        int loading=0;
        ~DataStruct();
        int getNumElements();
        void printList();
        void addFirst(T value);
        void addLast(T value);
        void addAt(Node <T>* value, int position);
        bool deleteData(T value);
        bool deleteAt(int position);
        Node<T>* getNodo(int position);
        time_t getDate(int position);
        void merge(Node<T>** inicio1, Node<T>** final1, Node<T>** inicio2, Node<T>** final2);
        void ordenaMerge(Node<T>** head);
        void imprimirAt(int position);
        int binarySearch(time_t k);
        void guardarLista(ofstream &o);
        void guardarAt(int position, ofstream &o);

        
      
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
  time_t DataStruct<T>::getDate(int position) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
    }
    else {
      if (position == 0)
        return head->date;
      Node<T> *p = head;
      int index = 0;
      while (p != NULL) {
        if (index == position)
          return p->date;
        index++;
        p = p->next;
      }
    }
    return -1;
  }

  template<class T>
  Node<T>* DataStruct<T>::getNodo(int position) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
    }
    else {
      if (position == 0)
        return head;
      Node<T> *p = head;
      int index = 0;
      while (p != NULL) {
        if (index == position)
          return p;
        index++;
        p = p->next;
      }
    }
  }

  template<class T>
  void DataStruct<T>::imprimirAt(int position){
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
    }
    else {
      if (position == 0)
        head->imprimir();
      Node<T> *p = head;
      int index = 0;
      while (p != NULL) {
        if (index == position)
          p->imprimir();
        index++;
        p = p->next;
      }
    }
  }

  template<class T>
  void DataStruct<T>::guardarAt(int position, ofstream &o){
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
    }
    else {
      if (position == 0)
        head->guardar(o);
      Node<T> *p = head;
      int index = 0;
      while (p != NULL) {
        if (index == position)
          p->guardar(o);
        index++;
        p = p->next;
      }
    }
  }

  template<class T>
  void DataStruct<T>::guardarLista(ofstream &o){
    Node<T> *ptr = head;
    while (ptr != NULL) {
        o << ptr->mes<<"";
        o << ptr->dia<<"";
        o << ptr->horas<<":";
        o << ptr->minutos<<":";
        o << ptr->segundos<<" ";
        o << ptr->ip<<endl;
        ptr = ptr->next;
    }
  }

  template<class T>
  void DataStruct<T>::addAt(Node<T>* value, int position) {
    if (position == 0)
      head->setValues(value);
    Node<T> *p = head;
    int index = 0;
    while (p != NULL) {
      if (index == position)
        p->setValues(value);
      index++;
      p = p->next;
    }
  }



//Algoritmo de ordenamiento por fusion(Merge) Division & Fusion.
template<class T>
void DataStruct<T>::merge(Node<T>** inicio1, Node<T>** final1, Node<T>** inicio2, Node<T>** final2){
    // Making sure that first node of second
    // list is higher.
    Node<T>* temp = NULL;
    if ((*inicio1)->date > (*inicio2)->date) {
        swap(*inicio1, *inicio2);
        swap(*final1, *final2);
    }
 
    // Merging remaining nodes
    Node<T>* astart = *inicio1, *aend = *final1;
    Node<T>* bstart = *inicio2, *bend = *final2;
    Node<T>* bendnext = (*final2)->next;
    while (astart != aend && bstart != bendnext) {
        if (astart->next->date > bstart->date) {
            temp = bstart->next;
            bstart->next = astart->next;
            astart->next = bstart;
            bstart = temp;
        }
        astart = astart->next;
    }
    if (astart == aend)
        astart->next = bstart;
    else
        *final2 = *final1;
}

//Algoritmo de ordenamiento por fusion(Merge) 
//Complejidad temporal O(n log n)
//basada en codigo de https://www.geeksforgeeks.org/iterative-merge-sort-for-linked-list
template<class T>
void DataStruct<T>::ordenaMerge(Node<T>** head){
    if (*head == NULL)
        return;
    Node<T>* inicio1 = NULL, *final1 = NULL;
    Node<T>* inicio2 = NULL, *final2 = NULL;
    Node<T>* prevend = NULL;
    int len = numElements;
 
    for (int gap = 1; gap < len; gap = gap*2) {
        inicio1 = *head;
        while (inicio1) {
 
            // If this is first iteration
            bool isFirstIter = 0;
            if (inicio1 == *head)
                isFirstIter = 1;
 
            // First part for merging
            int counter = gap;
            final1 = inicio1;
            while (--counter && final1->next)
                final1 = final1->next;
 
            // Second part for merging
            inicio2 = final1->next;
            if (!inicio2)
                break;
            counter = gap;
            final2 = inicio2;
            while (--counter && final2->next)
                final2 = final2->next;
 
            // To store for next iteration.
            Node<T> *temp = final2->next;
 
            // Merging two parts.
            merge(&inicio1, &final1, &inicio2, &final2);
 
            // Update head for first iteration, else
            // append after previous list
            if (isFirstIter)
                *head = inicio1;
            else
                prevend->next = inicio1;
 
            prevend = final2;
            inicio1 = temp;
        }
        prevend->next = inicio1;
    }
}

//funcion de busqueda binaria iterativa.
template<class T>
int DataStruct<T>::binarySearch(time_t k) {
  int low = 0;
  int high = this->numElements - 1;
  while (low <= high) {
    int m = low + (high - low) / 2;
    int llave = getDate(m);
    if (this->getDate(m) == k) return m;
    else if (this->getDate(m) > k) 
      high = m - 1;
    else 
      low = m + 1;
  }
  return -1;
}

/*Siento que es posible usar polimorfismo y sobrecarga para reutilizar el codigo que tenemos para la clase datos.
sin tener que volver a escribir todo esto o usar otro metodo.*/
time_t getFecha(string fecha){ 
  int dia, horas, minutos, segundos;
  string mes;
  vector<string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  struct tm dateStruct;
  mes = fecha.substr(0,fecha.find(" "));
  
  dateStruct.tm_sec = stoi(fecha.substr(13,fecha.find(":")));
  dateStruct.tm_min = stoi(fecha.substr(10,fecha.find(":")));
  dateStruct.tm_hour = stoi(fecha.substr(6,fecha.find(":")));
  dateStruct.tm_mday = stoi(fecha.substr(3,fecha.find(" ")));
  dateStruct.tm_isdst = 0;
  for (int i=0; i<meses.size(); i++){
      if (meses[i]==mes)
       dateStruct.tm_mon = i;
  }
  dateStruct.tm_year = 2021 - 1900;
  return mktime(&dateStruct);

}
 
  
#endif // _DATASTRUCT_H_