#include <ostream>
#include <iostream>
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
  static const int MINSIZE = 2;
  // tamaño minimo del array, debe inicializarse a 2

 public:
  // miembros públicos, incluidos los heredados de List<T>
  ListArray(){
  // Constructor
    arr = new T[MINSIZE];
    max = MINSIZE;
    n = 0;
  }
  ~ListArray(){
  // Destrctor
    max = 0;
    n = 0;
    delete[] arr;
  }
  T operator[](int pos){
  // devuelve elemento de la posicion pos
    if(pos < 0 || pos >= n){
      throw std::out_of_range("Posición inválida\n"); 
    }
    return arr[pos];
  }
  friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
    out << "List => [\n";
      for(int i = 0; i < list.n; i++){
	out << "  " << list.arr[i] << "\n";
      }
      out << "]";
      return out;
  }
  void resize(int new_size){
    // redimensionar el array
    if(new_size >= MINSIZE){
      T *newArr = new T[new_size];
      // se crea el nuevo array con new_size de espacio
      for(int i = 0; i < std::min(n, new_size); i++){
	newArr[i] = arr[i];
	// se copian los elementos
      }
      delete[] arr;
      // se elimina el array anterior
      this->arr = newArr;
      // cambio de puntero
      max = new_size;
      if(new_size < n) n = new_size;
      // cambio de nº de elementos si el nuevo tamaño es menor
    }
  }
  void insert(int pos, T e) override{
    // inserta elemento e en la posicion pos
    if(pos >= 0 && pos <= n){
      if(n == max){
	resize(max + 1);
      }
      for(int i = n; i > pos; i--){
	//std::cout << n << "elementos\n";
	arr[i] = arr[i - 1];
      }
      arr[pos] = e;
      n++;
    }else{
      throw std::out_of_range("Posición inválida\n");
    }
  }
  void append(T e) override{
    // inserta elemento e en la ultima posicion
    if(n == max){
      resize(max + 1);
    }
    arr[n] = e;
    n++;
  }
  void prepend(T e) override{
    // inserta elemento e en la primera posicion
    if(n == 0){
      // si array vacio
      arr[0] = e;
    }else{
      // si no está vacío
      if(n == max){
	resize(max + 1);
      }
      for(int i = n; i > 0; i--){
	arr[i] = arr[i - 1];
	// se desplaza todo el array una casilla a la derecha
      }
      arr[0] = e;
      n++;
    }
  }
  T remove(int pos) override{
  // elimina y devuelve elemento de la posicion pos, si no existe lanza "std::out_of_range"
    if(pos >= 0 && pos < n){
      T elemR = arr[pos];
      for(int i = pos; i < n; i++){
	arr[i] = arr[i + 1];
      }
      n--;
      return elemR;
    }else{
      throw std::out_of_range("Posición inválida\n");
    }
  }
  T get(int pos) override{
  // devuelve valor posicion pos, si no existe lanza "std::out_of_range"
    if(pos >= 0 && pos < n){
      return arr[pos]; 
    }
    throw std::out_of_range("Posición inválida\n");
  }
  
  int search(T e) override{
  // devuelve posicion de la primera ocurrencia del elemento e, sino existe devuelve -1
    int pos;
    for(pos = 0; pos < n; pos++){
      if(arr[pos] == e) return pos;
    }
    return -1;
  }
  bool empty() override{
  // indica si esta vacía
    if(n == 0) return 1;
    else return 0;
  }
  int size() override{
  // devuelve el número de elementos que hay en la lista
    return n;
  }
};
