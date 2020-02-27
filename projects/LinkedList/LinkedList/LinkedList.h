#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

typedef int itemType;

class LinkedList {
public:
	LinkedList();
	//LinkedList(const LinkedList& l);
	//~LinkedList();
	//bool isEmpty() const;
	int getLenght() const;
	void add(itemType item);
	bool insert(int index, itemType item);
	//bool remove(itemType item);
	itemType get(int index) const;

private:
	struct Node {
		itemType item;
		Node* next;
	};

	Node* head;
	int size;
};
#endif // !__LINKEDLIST_H

