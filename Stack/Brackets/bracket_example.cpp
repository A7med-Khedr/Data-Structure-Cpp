#include "../stack.h"
#include <iostream>
#include <string>
using namespace std;

bool isBalance(const string& str) {
    Stack<char> stackBrackets;

    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stackBrackets.Push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stackBrackets.IsEmpty()) {
                return false;
            }

            char isSimilar = stackBrackets.Pop();

            if ((ch == ')' && isSimilar != '(') ||
                (ch == '}' && isSimilar != '{') ||
                (ch == ']' && isSimilar != '[')) {
                return false;
            }
        }
    }

    return stackBrackets.IsEmpty();
}


int main() {

	string str_0 = "([]{})";
	string str_1 = "([]{)";
	string str_2 = "(ahmed) {} [khedr";

	cout << "stack status is: " << isBalance(str_0) << "\n";
	cout << "stack status is: " << isBalance(str_1) << "\n";
	cout << "stack status is: " << isBalance(str_2) << "\n";

	return 0;
}
