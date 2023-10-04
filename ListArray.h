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
    
};
