#include "calcStack.h"
//constructor
Calc :: Calc(string m)
{
  exp=m;
}
//preference evaluator
int Calc::preference(char oprt)
{
  int prefer = 0;
  if(oprt =='+'|| oprt =='-')
     prefer = 1;
  else if(oprt=='*'||oprt == '/')
     prefer=2;
     
  return prefer;
}
//calculate function
int Calc:: operation(char oprt, int a2, int a1)
{
  int res=0;// hold solution 
  switch(oprt)
  {
    case '+':
         res = a1+a2;
         break;
    case '-':
         res = a2-a1;
         break;
    case'*':
        res = a2*a1;
        break;
    case '/':
        if (a1 ==0)
        {
          cout<<"cannot divide by zero"<<endl;
        }
        else
         res=a2/a1;
         break;
    default:
         break;
  }    
  return res;   
}
void Calc::setArg()
{
  int a1 = operands.top();
  operands.pop();

  int a2 = operands.top();
  operands.pop();
  
  char opr = operators.top();
  operators.pop();

  operands.push(operation(opr,a2,a1));
}
void Calc::solve()
{
for (int i = 0; i <exp.length(); i++) //start of for loop
   {
         if (exp[i] == '(')
         {

               operators.push(exp[i]);

         }
         else if (isdigit(exp[i]))
         {

               int value = 0; //holds total digit

              // value = (value * 10) + (exp[i] - '0');   // always sets digit
               value = exp[i]-'0';
              
               while (i < exp.length() && isdigit(exp[i + 1]))  // for numbers that aren't single digits
               {
                     value = (value * 10) + (exp[i + 1] - '0');
                     //value = exp[i+1]-'0';
                     i++;
               }

               operands.push(value);
               

         }
         else if (exp[i] == ')')
         {
               while (!operators.empty() && operators.top() != '(')
               {

                     setArg();  //calculates operations inside (..)

               }

               operators.pop();       //closes by popping ')'

         }
         else if (exp[i] == '-' && (i == 0 || (exp[i - 1] >= '(' && exp[i - 1] <= '/' && exp[i - 1] != ')')))
         {
               while (i < exp.length())
               {
                     if (isdigit(exp[i + 1])) //if char to the right of '-' is a digit
                     {
                           int value = 0;

                           value = (value * 10) + (exp[++i] - '0'); //set value to digit on the right of '-'

                           while ( i < exp.length() && isdigit(exp[i + 1])) // makes sure digit is not a single number
                           {
                                 value = (value * 10) + (exp[i + 1] - '0');

                                 i++;
                           }

                           operands.push(value * -1); //makes value negative
                     }

                        break; //break once digit is pushed
               }
         }
         else
         { /* solves high preference operators first */
               while (!operators.empty() && preference(operators.top()) >= preference(exp[i]))
               {
                     setArg();
               }

               operators.push(exp[i]); //pushes first operator in expression and then lower preference operators
         }
   } // end of for loop

   while (!operators.empty()) // solves remaining low preference operators
   {
         setArg();
   }

   cout << "The result is: " << operands.top() << endl;

   operands.pop(); //pops final result

}