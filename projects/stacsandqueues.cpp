#include <iostream>
using namespace std;

bool isPalindrome(string str) {
	
	Stack s;
	Queue q;
	int i;
	
	for (i = 0; str[i] != '\0'; i++) {
		s.push(str[i]);
		q.enqueue(str[i];
	}
	
	char c1;
	char c2;
	
	for (int j = 0; j <= i; j++) {
		s.pop(c1);
		q.dequeue(c2);
		
		if (c1 != c2) {
			return false;
		}
	}
	
	return true;
}