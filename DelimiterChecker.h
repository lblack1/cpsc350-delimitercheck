#ifndef DELIMITERCHECKER
#define DELIMITERCHECKER

#include "GenStack.h"
#include "StackEmptyException.h"
#include <iostream>

using namespace std;

/* A class for checking if files are delimited correctly. Methods meant to be called statically.
*/
class DelimiterChecker {

  public:
    static bool check(const string& filename);

  private:
    static void printError(const string& filename, int l, char e, char f);
    static void printError(const string& filename, int l, char f);

};

#endif
