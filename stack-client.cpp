//Program to demonstrate use of the Stack template class.
#include <iostream>
#include "stack.h"
#include "stack.cpp"
using std::cin;
using std::cout;
using std::endl;
using StackSavitch::Stack;

int main( )
{
   char next, ans;

   do
   {
      Stack<char> s;
      cout << "Enter a line of text:\n";
      cin.get(next);
      while (next != '\n')
      {
         s.push(next);
         cin.get(next);
      }

      cout << "Written backward that is:\n";
      while ( ! s.isEmpty( ) )
         cout << s.pop( );
      cout << endl;

      cout << "Again?(y/n): ";
      cin >> ans;
      cin.ignore(10000, '\n');
   }while (ans != 'n' && ans != 'N');
   Stack<char> testException;
   try {
      testException.pop();
   }
   catch (StackSavitch::pop_empty_stack_exception) {
      cout << "Stack empty! pop_empty_stack_exception error!";
   }

   return 0;
}

/* Output:

 Enter a line of text:
 Hello
 Written backward that is:
 olleH
 Again?(y/n): n
 Stack empty! pop_empty_stack_exception error!

*/