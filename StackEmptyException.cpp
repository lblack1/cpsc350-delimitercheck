#include "StackEmptyException.h"
#include <iostream>

using namespace std;

/* Defualt Constructor for a StackEmptyException.
*/
StackEmptyException::StackEmptyException() {
  message = "Stack empty.";
}

/* Constructor for a StackEmptyException.
* Parameter string& errMessage: The message to be saved with the exception.
*/
StackEmptyException::StackEmptyException(const string &errMessage) {
  message = errMessage;
}

/* A method to return the Exception's message.
* Returns the exception's method.
*/
string StackEmptyException::getMessage() {
  return message;
}
