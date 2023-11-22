#include <ostream>

template <typename T> class Node{
public:
  T data;
  // elemento almacenado
  Node<T>* next;
  // puntero nodo sig

public:
  Node(T data){
    // CONSTRUCTOR PRIMERO
    this->data = data;
    next = nullptr;
  }
  Node(T data, Node<T>* next){
    // CONSTRUCTOR NO PRIMERO
    this->data = data;
    this->next = next;
  }
  friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
    out << node.data;
    return out;
  }
};
  
  
