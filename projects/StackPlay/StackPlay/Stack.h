#ifndef __STACK_H
#define __STACK_H

using namespace std;

class Stack {
public:
	Stack();
	~Stack();
	bool isEmpty() const;
	bool push(char c);
	bool pop();
	bool pop(char& c);
	bool getTop(char& c) const;
};
#endif