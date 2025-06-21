#include <iostream>
using namespace std;
#include "stack.h"

int main()
{
    Stack<int> My_Stack;
    My_Stack.Push(1);
    My_Stack.Push(2);
    My_Stack.Push(3);
    My_Stack.Push(4);
    
    My_Stack.pop();
    My_Stack.pop();
    My_Stack.pop();
    
    My_Stack.Display();
    
    My_Stack.Print_Top();
    
    cout << "Stack Size: " << My_Stack.Get_Size() << "\n";
    
    return 0;
}
