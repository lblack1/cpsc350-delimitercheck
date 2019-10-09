#include "DelimiterChecker.h"
#include "GenStack.h"
#include "StackEmptyException.h"
#include <iostream>
#include <fstream>

using namespace std;

/* A method that iterates through a file checks that delimiters (parentheses, curly braces, and brackets) are properly sorted. Ignores quotes and comments.
* Parameter string& filename: The name of the file to check for delimiter correctness.
* Returns bool: true if delimiters are correct, false if there's an error.
*/
bool DelimiterChecker::check(const string& filename) {

  GenStack<char> delimstack;
  int linenum = 1;
  string filen = filename;

  ifstream ifile;
  ifile.open(filen);
  if (!ifile) {
    cout << filen << " is not a valid file name. Please try again or type help." << endl;
    return false;
  }

  string templine;
  bool q = false;
  bool c = false;
  bool mc = false;
  while (getline(ifile, templine)) {
    for (int i = 0; i < templine.length(); ++i) {
      switch (templine[i]) {
        case '/':
          if (templine[i+1] == '/' && !mc) {
            c = true;
          } else if (templine[i+1] == '*' && !mc) {
            mc = true;
          } else if (templine[i-1] == '*' && mc) {
            mc = false;
          } else {
            continue;
          }
          break;
        case '\'':
        case '"':
          if (!q && !mc) {
            q = true;
            delimstack.push(templine[i]);
          } else if (!mc && templine[i] == delimstack.peek()) {
            if (templine[i-1] == '\\' && templine[i-2] != '\\') { // Detects and ignores escape characters
              continue;
            } else {
              q = false;
              delimstack.pop();
            }
          }
          break;
        case '{':
        case '[':
        case '(':
          if (!q && !mc) {
            delimstack.push(templine[i]);
          }
          break;
        case '}':
        case ']':
          if (!q && !mc) {
            try {
              if (templine[i] == (char)(delimstack.peek()+2)) { // Checks that delimiters match their corresponding open versions.
                delimstack.pop();
                continue;
              } else {
                printError(filename, linenum, delimstack.peek(), templine[i]);
                return false;
              }
            } catch (StackEmptyException e) {
              printError(filename, linenum, templine[i]);
              return false;
            }
          }
          break;
        case ')':
          if (!q && !mc) {
            try {
              if (templine[i] == (char)(delimstack.peek()+1)) { // Separate from above two close delimiters due to ASCII.
                delimstack.pop();
                continue;
              } else {
                printError(filename, linenum, delimstack.peek(), templine[i]);
                return false;
              }
            } catch (StackEmptyException e) {
              printError(filename, linenum, templine[i]);
              return false;
            }
          }
          break;
        default:
          continue;
      }
      if (c) {
        c = false;
        break;
      }
    }
    linenum++;
  }

  if (delimstack.isEmpty()) {
    return true;
  } else {
    delimstack.printStack();
    printError(filename, linenum, delimstack.pop(), 'a');
    return false;
  }

}

/* A method that prints the delimiter error and where it was found.
* Parameter string& filename: the name of the file being read
* Parameter int l: the line where the error was found
* Parameter char e: the delimiter that was expected to be found
* Parameter char f: the erroneous delimiter that was found, or 'a' if the file has ended with delimiters left unclosed
*/
void DelimiterChecker::printError(const string& filename, int l, char e, char f) {
  cout << "In " << filename;
  if (f != 'a') {
    printf(", line %d: expected %e, found %f.\n", l, e, f);
  } else {
    printf(", reached end of file, expected %e.\n", e);
  }
}

/* A method that prints the delimiter error and where it was found. Used for unexpected close delimiters.
* Parameter string& filename: the name of the file being read
* Parameter int l: the line where the error was found
* Parameter char f: the erroneous delimiter that was found
*/
void DelimiterChecker::printError(const string& filename, int l, char f) {
  cout << "In " << filename;
  printf(", line %d: unexpected %c.\n", l, f);
}
