#include <ostream>

template <typename T>

class List{
 public:
  //métodos
  virtual void insert(int pos, T e) = 0;
  // inserta elemento e en la posicion pos
  virtual void append(T e) = 0;
  // inserta elemento e en la ultima posicion
  virtual void prepend(T e) = 0;
  // inserta elemento e en la primera posicion
  virtual T remove(int pos) = 0;
  // elimina y devuelve elemento de la posicion pos, si no existe lanza "std::out_of_range"
  virtual T get(int pos) = 0;
  // devuelve valor posicion pos, si no existe lanza "std::out_of_range"
  virtual int search(T e) = 0;
  // devuelve posicion de la primera ocurrencia del elemento e, sino existe devuelve -1
  virtual bool empty() = 0;
  // indica si esta vacía
  virtual int size() = 0;
  // devuelve el número de elementos que hay en la listaº
};

/* 
SON TODO VIRTUAL PORQUE SON FUNCIONES ABSTRACTAS
Y LUEGO, SE IGUALA A 0 PORQUE SON PURAS
*/
