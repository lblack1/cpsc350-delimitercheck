#ifndef GENSTACK
#define GENSTACK

#include "StackEmptyException.h"
#include <iostream>

using namespace std;

/* A template class for an array-based stack.
*/
template <class T>
class GenStack {

  public:

    /* Default Constructor, defaults to an array of size 128.
    */
    GenStack() {
      top = -1;
      size = 128;
      array = new T[128];
    }

    /* Overloaded Constructor.
    * Parameter int maxSize: size to set first array
    */
    GenStack(int maxSize) {
      top = -1;
      size = maxSize;
      array = new T[maxSize];
    }

    /* Destructor, deallocates array.
    */
    ~GenStack() {
      delete[] array;
    }


    /* Adds element to end of array (top of stack). Doubles array size if array is full.
    * Parameter T d: an element of type T to be added to the stack.
    */
    void push(T d){

      if (this->isFull()) {
        T* temp = array;
        array = new T[size*2];
        for (int i = 0; i < size; ++i) {
          array[i] = temp[i];
        }
        size *= 2;
        temp = NULL;
        delete temp;
      }

      array[++top] = d;

    }

    /* Removes the element on the top of the stack. Throws a StackEmptyException if the stack is empty.
    * Returns whatever data was stored on top of stack.
    */
    T pop() {
      T data;
      if (this->isEmpty()) {
        throw StackEmptyException("Stack Empty");
      } else {
        data = array[top--];
      }
      return data;
    }

    /* Shows the element on the top of the stack. Throws a StackEmptyException if the stack is empty.
    * Returns whatever data is stored on top of stack.
    */
    T peek() {
      T data;
      if (this->isEmpty()) {
        throw StackEmptyException("Stack Empty");
      } else {
        data = array[top];
      }
      return data;
    }


    /* Prints a comma separated list of the elements in the stack in FIFO order.
    */
    void printStack() {
      for (int i = top; i > 0; --i) {
        cout << array[i] << ", ";
      }
      cout << array[0] << endl;
    }

    /* Checks if the stack is empty.
    * Returns true if stack is empty, false otherwise.
    */
    bool isEmpty() {
      return (top == -1);
    }

    /* Checks if the stack is full.
    * Returns true if stack is full, false otherwise.
    */
    bool isFull() {
      return (top == size-1);
    }

  private:
    int top;
    int size;
    T* array;

};

#endif
