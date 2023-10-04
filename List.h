#include <iostream>
using namespace std;

public abstract class List{
 public:
  //métodos
  void insert(int pos, T e);
  // inserta elemento e en la posicion pos
  void append(T e);
  // inserta elemento e en la ultima posicion
  void prepend(T e);
  // inserta elemento e en la primera posicion
  T remove(int pos);
  // elimina y devuelve elemento de la posicion pos, si no existe lanza "std::out_of_range"
  T get(int pos);
  // devuelve valor posicion pos, si no existe lanza "std::out_of_range"
  int search(T e);
  // devuelve posicion de la primera ocurrencia del elemento e, sino existe devuelve -1
  bool empty();
  // indica si esta vacía
  int size();
  // devuelve el número de elementos que hay en la lista

};
