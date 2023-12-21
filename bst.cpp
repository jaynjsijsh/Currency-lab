/*
Lab 4
Jayne Tan and Harmony Trinh
The purpose of this lab is to utilize different types of traversal methods within
a binary search tree.
*/
#include <iostream>
#include <string>
#include <cmath>
#include "Dollar.cpp"

class BST {
private:
    std::ostream* os;

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


	BSTNode* root;
	//Pre: node- pointer to BSTNode
	//	   d- reference to a Dollar object that will be inserted into BST
	//Post: Dollar object d is inserted into BST rotted at the node
	//Return:
	void insertHelper(BSTNode*& node, const Dollar& d) {
		if (!node) {
			node = new BSTNode(d);
			return;
		}
		if (d.isGreater(node->data)) {
			insertHelper(node->right, d);
		}
		else {
			insertHelper(node->left, d);
		}
	}
	//Pre: node- pointer to BSTNode
	//	   d- reference to a Dollar object that will be searched in BST
	//Post: pointer to the node containing Dollar object d is returned if found, or null pointer is returned if not found
	//Return: BSTNode*- points to the node containing Dollar object d if found or nullptr if not found
	BSTNode* searchHelper(BSTNode* node, const Dollar& d) const {
		if (!node || d.isEqual(node->data)) {
			return node;
		}
		if (d.isGreater(node->data)) {
			return searchHelper(node->right, d);
		}
		else {
			return searchHelper(node->left, d);
		}
	}
	//Pre: node- pointer to BSTNode
	//Post: pointer to the minimum node in the BST is found 
	//Return: BSTNode*- points to the minimum node in the BST or nullptr if empty
	BSTNode* min(BSTNode* node) const {
		if (!node) {
			return nullptr;
		}
		while (node->left) {
			node = node->left;
		}
		return node;
	}
	//Pre: node- pointer to BSTNode
	//	   d- reference to Dollar  that needs to be deleted from BST
	//Post: node containing Dollar object equal to d is deleted
	//Return: BSTNode*- pointer to the root node of the modified BST after deletion
	BSTNode* deleteNode(BSTNode* node, const Dollar& d) {
		if (!node)
			return node;

		if (d.isGreater(node->data))
			node->right = deleteNode(node->right, d);
		else if (d.isGreater(node->data))
			node->left = deleteNode(node->left, d);
		else {
			if (!node->left) {
				BSTNode* temp = node->right;
				delete node;
				return temp;
			}
			else if (!node->right) {
				BSTNode* temp = node->left;
				delete node;
				return temp;
			}

			BSTNode* temp = min(node->right);
			node->data = temp->data;
			node->right = deleteNode(node->right, temp->data);
		}
		return node;
	}

	//Pre: node: pointer to BSTNode
	//Post: length of the BST rooted at node is calculated
	//Return: int- the length of the BST or 0 if empty
    int getTreeLength(BSTNode* node) const{
        if(node){
            int leftLength = getTreeLength(node->left), rightLength = getTreeLength(node->right);
            if(leftLength > rightLength) return (leftLength + 1);
            else return (rightLength + 1);
        }
        return 0;
    }
	//Pre: node-pointer to BSTNode
	//     lvl- integer, the current level of the traversal
	//Post: breadth first traversal at the node is performed, data of nodes at lvl is printed
	//Return: 
    void breadthFirstTraversalHelper(BSTNode* node, int lvl) const{
        if(node){
            if(lvl == 1){
                node->data.print(*os);
            }else{
                breadthFirstTraversalHelper(node->left, lvl - 1);
                breadthFirstTraversalHelper(node->right, lvl - 1);
            }
        }
    }
	//Pre: node- pointer to BSTNode
	//Post: in order traversal at node is performed, data of each node is printed in ascending order
	//Return: 
	void inOrderTraversalHelper(BSTNode* node) const {
		if (node) {
			inOrderTraversalHelper(node->left);
			node->data.print(*os);
			inOrderTraversalHelper(node->right);
		}
	}
	//Pre: node- pointer to BSTNode
	//Post: pre order traversal at node is performed, data of each node is printed in order of curren node, left child, right child
	//Return:
	void preOrderTraversalHelper(BSTNode* node) const {
		if (node) {
			node->data.print(*os);
			preOrderTraversalHelper(node->left);
			preOrderTraversalHelper(node->right);
		}
	}
	//Pre: node- pointer to BSTNode
	//Post: post order traversal is performed, data of each node is printed in order of left child, right child, current node
	//Return:
	void postOrderTraversalHelper(BSTNode* node) const {
		if (node) {
			postOrderTraversalHelper(node->left);
			postOrderTraversalHelper(node->right);
			node->data.print(*os);
		}
	}
	//Pre: node- pointer to BSTNode
	//Post: number of nodes counted or 0 if empty
	//Return: int- number of nodes in BST
	int countNodes(BSTNode* node) const {
		if (!node) {
			return 0;
		}
		return 1 + countNodes(node->left) + countNodes(node->right);
	}
	//Pre: node- pointer to BSTNode
	//Post: BST is deleted
	//Return:
	void deleteTree(BSTNode* node) {
		if (node) {
			deleteTree(node->left);
			deleteTree(node->right);
			delete node;
		}
	}
public:
	BST() {
		root = nullptr;
        os = &std::cout;
	}
	~BST() {
		deleteTree(root);
	}
    void setOuputStream(std::ostream& a_os){
        os = &a_os;
    }
	//Pre: d- reference to a Dollar object that will be inserted into BST
	//Post: Dollar object d inserted
	//Return:
	void insert(const Dollar& d) {
		insertHelper(root, d);
	}
	//Pre: d- reference to a Dollar object that will be inserted into BST
	//Post: Dollar object d is found
	//Return: BSTNode*- pointer to node containing Dollar object d 
	BSTNode* search(const Dollar& d) const {
		return searchHelper(root, d);
	}
	//Pre: d- reference to Dollar object that will be removed
	//Post: node containing Dollar object d is removed
	//Return:
	void remove(const Dollar& d) {
		root = deleteNode(root, d);
	}
	//Pre:
	//Post: breadth first traversal is performed
	//Return:
	void inOrderTraversal() const {
		inOrderTraversalHelper(root);
	}
	//Pre:
	//Post: in order traversal is performed
	//Return:
	void preOrderTraversal() const {
		preOrderTraversalHelper(root);
	}
	//Pre:
	//Post: pre order traversal is performed
	//Return:
	void postOrderTraversal() const {
		postOrderTraversalHelper(root);
	}
	//Pre:
	//Post: post order traversal is performed
	//Return:
	BSTNode* getRoot() const {
		return root;
	}
	//Pre:
	//Post: BST is checked to see if it is empty or not
	//Return: bool- true if empty, false if not empty
	bool isEmpty() const { return root == nullptr; }
	int count() const {
		return countNodes(root);
	}
	//Pre:
	//Post: number of nodes in BST are counted
	//Return: int- the number of nodes
    void breadthFirstTraversal () const { 
        int l = getTreeLength(root);
        for(int i = 1; i <= l; i++) breadthFirstTraversalHelper(root, i);
    }

	void print() const {

		*os << "Breadth-First Traversal: ";
		breadthFirstTraversal();
		*os << std::endl << std::endl;

		*os << "In-Order Traversal: ";
		inOrderTraversal();
		*os << std::endl << std::endl;

		*os << "Pre-Order Traversal: ";
		preOrderTraversal();
		*os << std::endl << std::endl;

		*os << "Post-Order Traversal: ";
		postOrderTraversal();
		*os << std::endl << std::endl;

		if (isEmpty()) {
			*os << "BST is empty." << std::endl;
			std::cout << "BST is empty." << std::endl;			
            return;
		}
		
	}
};
