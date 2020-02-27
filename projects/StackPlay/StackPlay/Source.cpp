#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
	return 0;
}

void infixToPostfix(string& str) {

	string result = "";
	Stack s;
	char c;
	char top;

	for (int i = 0; str[i] == '\0'; i++) {
		c = str[i];
		s.getTop(top);

		if ((c == '+' || c == '-') && (top == '*' || top == '/')) {
			while (isempty and (c == '+' || c == '-') && (top == '*' || top == '/'))
			result += top;
			s.pop();
		}
		else if (c == ')') {
			char temp;
			s.pop(temp);

			while (temp != '(') {
				result += temp;
			}
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(') {
			s.push(c);
		}
		else {
			result += c;
		}
		
	}
}