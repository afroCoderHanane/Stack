#include <iostream>
#include <string>
#include "calcStack.h"
#include<algorithm>
using namespace std;

int main() {
  string exp;  //math expression

  do {
         cout << "Type INFIX expression or 'Q' to quit" << endl;
         getline(cin, exp);

         if (exp == "q" || exp == "Q")
            continue;

            //algorithm library, erases every space in string 'exp'
         exp.erase(remove_if(exp.begin(), exp.end(), ::isspace), exp.end());

         Calc expression(exp); //sets user's expression

         expression.solve(); //solves expression

  } while (exp != "q" && exp != "Q"); //stops when user enters 'x'

  cout << "Good bye" << endl;

  return 0;
}