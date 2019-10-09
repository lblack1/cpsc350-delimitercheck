#ifndef STACKEMPTYEXCEPTION
#define STACKEMPTYEXCEPTION

#include <iostream>

using namespace std;

/* An exception class to be thrown when pop or peek is called on an empty stack.
*/
class StackEmptyException {

  public:
    StackEmptyException();
    StackEmptyException(const string &errMessage);
    string getMessage();

  private:
    string message;

};

#endif
