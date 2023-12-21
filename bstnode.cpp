
#include <iostream>
#include <string>
#include <cmath>
#include "Dollar.cpp"
class BSTNode {
	public:
		Dollar data;
		BSTNode* left;
		BSTNode* right;

		BSTNode(const Dollar& d) {
			data = d;
			left = nullptr;
			right = nullptr;
		}
		Dollar getData() const {
			return data;
		}
		BSTNode* getLeft() const {
			return left;
		}
		BSTNode* getRight() const {
			return right;
		}
		void setLeft(BSTNode* leftNode) {
			left = leftNode;
		}
		void setRight(BSTNode* rightNode) {
			right = rightNode;
		}
	};