#include "DelimiterChecker.h"
#include "GenStack.h"
#include "StackEmptyException.h"
#include <iostream>

using namespace std;

/* Main method. Checks delimiters on all command line arguments, or explains usage.
*/
int main(int argc, char** argv) {
  if (argc == 1 || tolower(argv[1][0]) == 'h') {
    cout << "Usage: $ DelimCheck.out [FILES]" << endl;
    cout << "Where [FILES] is any number of space-separated file locations to be checked." << endl;
  } else {
    for (int i = 1; i < argc; ++i) {
      if (DelimiterChecker::check(argv[i])) {
        cout << argv[i] << ": Good delimiters" << endl;
      }
    }
  }
}
