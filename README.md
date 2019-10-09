# cpsc350-delimitercheck
A stack-based delimiter checker.

Lloyd Black
2295968
CPSC350, Section 2
Rene German

An array-based stack implementation and program to read files and check delimiters (parentheses, curly braces, and square brackets) are properly closed (accounting for comments, string literals, and characters).

1. Source Files - main.cpp, GenStack.h, StackEmptyException.h, StackEmptyException.cpp, DelimiterChecker.h, DelimiterChecker.cpp

2. Issues/Limitations - Can only detect one delimiter error per file.

3. Resources - cplusplus.com/reference, stackoverflow, tutorialspoint, CPSC350 lecture notes, and Data Structures and Algorithms in C (by Goodrich, Tamassia, and Mount).

4. Description of Program
  Stack implementation: An array-based stack that defaults to 128 elements and doubles as necessary. Throws a StackEmptyException if pop() or peek() is called on an empty stack. Contains standard push(), pop(), and peek() methods, as well as printStack(), isEmpty(), and isFull().
  DelimiterChecker: Reads in any number of files as command line arguments and checks each for delimiter correctness, outputting results to console. If run improperly, prints a small help message.

5. After compiling - $ ./YOUROUTFILE.out [FILES]
