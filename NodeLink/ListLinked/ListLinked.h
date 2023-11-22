#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T> class ListLinked : public List<T>{
private:
  Node<T>* first;
  // puntero al primer nodo
  int n;
  // nº de elementos que contiene la lista
public:
  ListLinked(){
    first = nullptr;
    n = 0;
  }
  // CONSTRUCTOR, inicia los dos atributos de instancia (first y nullptr)
  ~ListLinked(){
    
    Node<T> *aux = first->next;
    Node<T> *auxNext = aux->next;
    for(int i = 0; i < n; i++){
      delete aux;
      first->next = auxNext;
      auxNext = auxNext->next;
    }
    n = 0;
    
  }
  // DESTRCTOR
  T operator[](int pos){
    /*
    Node<T> *aux = first->next;
    if(pos >=0 && pos < n){
      int i = 0;
      while(i < pos){
	aux = aux->next;
	i++;
      }
      return aux->data;
    }else
      throw std::out_of_range("Posición inválida\n");
    */
  }
  // devuelve elemento situado en la posicion pos, si no esta -> out_of_range
  friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
    /*
    out << "List => [\n";
    Node<T> *aux = list.first->next;
    do{
      out << aux->data << std::endl;
      aux = aux->next;
    }while(aux->next != nullptr);
    out << "]";
    return out;
    */
  }
  
  void insert(int pos, T e) override{
    // CAMBIAR
    // inserta elemento e en la posicion pos
    if(pos == 0) prepend(e);
    else if(pos == n) append(e);
    else if(pos >= 1 && pos < n){
      Node<T> *auxNode = first->next;
      Node<T> *prevAuxNode = first;
      // auxNode recorre los nodos hasta la pos deseada (1 por encima)
      // auxNodePrev va detras de el
      for(int i = 0; i < pos; i++){
	auxNode = auxNode->next;
	prevAuxNode = prevAuxNode->next;
      }
      n++;
      prevAuxNode->next = new Node(e, auxNode);
    }else{
      throw std::out_of_range("Posición inválida\n");
    }
  }
  void append(T e) override{
    // CAMBIAR
    // inserta elemento e en la ultima posicion
    Node<T> *auxNode = first->next;
    while(auxNode->next != nullptr){
      auxNode = auxNode->next;
    }
    auxNode->next = new Node(e);
    n++;
  }
  void prepend(T e) override{
    // CAMBIAR
    // inserta elemento e en la primera posicion
    if(n == 0){
      first->next = new Node(e);
      // crea nuevo nodo que apunta a nullptr
      n++;
    }else{
      Node<T> *auxNode = first->next;
      // crea nodo auxiliar que apunta al sig de first
      first->next = new Node(e, auxNode);
      // sustituye el next del first por el nuevo nodo, cuyo next es el nodo auxiliar
      n++;
    }
    
  }
  T remove(int pos) override{
    // CAMBIAR
    // elimina y devuelve elemento de la posicion pos, si no existe lanza "std::out_of_range"
    Node<T> *auxNode = first->next;
    Node<T> *prevAuxNode = first;
    // auxNode recorre los nodos hasta la pos deseada (1 por encima)
    // auxNodePrev va detras de el
    for(int i = 0; i < pos; i++){
      auxNode = auxNode->next;
      prevAuxNode = prevAuxNode->next;
    }
    delete prevAuxNode;
    prevAuxNode->next = auxNode;
    n--;
  }
  T get(int pos) override{
    // CAMBIAR
    // devuelve valor posicion pos, si no existe lanza "std::out_of_range"
    Node<T> *aux = first->next;
    if(pos >=0 && pos < n){
      int i = 0;
      while(i < pos){
	aux = aux->next;
	i++;
      }
      return aux->data;
    }else
      throw std::out_of_range("Posición inválida\n");
  }
  
  int search(T e) override{
    // CAMBIAR
    // devuelve posicion de la primera ocurrencia del elemento e, sino existe devuelve -1
    int pos = 0;
    Node<T> *aux = first->next;
    while(aux != nullptr){
      aux = aux->next;
      if(aux->data == e) return pos;
      pos ++;
    }
    return -1;
  }
  bool empty() override{
    // CAMBIAR
    // indica si esta vacía
    if(n == 0) return 1;
    else return 0;
  }
  int size() override{
    // CAMBIAR
    // devuelve el número de elementos que hay en la lista
    return n;
  }
  
  
};
