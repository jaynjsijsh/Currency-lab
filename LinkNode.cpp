/*
* Lab 3
* Harmony Trinh and Jayne Tan
* The purpose of this lab is to implement and demonstrate link-based ADTs to store Currency objects and perform different operations on these data structures
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include "Dollar.cpp"

class LinkNode {
private:
	Currency* data;
	LinkNode* next;

public:
	LinkNode() {
		data = nullptr;
		next = nullptr;
	}
	LinkNode(Currency* currncy) {
		data = currncy;
		next = nullptr;
	}
	Currency* getData() const {
		return data;
	}
	LinkNode* getNext() const {
		return next;
	}
	void setNext(LinkNode* nextNode) {
		next = nextNode;
	}
};