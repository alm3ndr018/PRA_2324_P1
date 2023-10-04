#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

 private:
  // atributos
  T* arr;
  // puntero al inicio del array
  int max;
  // tamaño actual del array, puede alterarse
  int n;
  // numero de elemtos que tiene la lista
  static const int MINSIZE;
  // tamaño minimo del array, debe inicializarse a 2

 public:
  // miembros públicos, incluidos los heredados de List<T>
  ListArray();
  // Constructor
  ~ListArray();
  // Destrctor
  T operator[](int pos);
  // devuelve elemento de la posicion pos
  friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);
  void resize(int new_size);
  // redimensionar el array
  
};
