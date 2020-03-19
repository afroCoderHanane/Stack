#pragma once
#include<iostream>
#include <stack>
#include <string>
using namespace std;

class Calc
{
  private:
          stack<char>operators;
          stack<int>operands;
          string exp;
  protected:
          void setArg();
          int operation(char, int , int);
  public:
          Calc(string);
          int preference(char );
          void solve();
  
};
