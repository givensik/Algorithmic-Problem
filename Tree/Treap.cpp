#include <iostream>
#include <utility>

using namespace std;

class Node
{
public:

	int key;
	int priority, size;
	Node *left, *right;

	Node(const int& _key) : key(_key), priority(rand()),size(1), left(NULL), right(NULL){
	}
	~Node();
	void setLeft(Node *newLeft){left = newLeft; calcSize();}
	void setRight(Node *newRight){left = newRight; calcSize();}
	void calcSize(){
		size = 1;
		if(left) size += left->size;
		if(right) size += right->size;
	}
	
};

Node* insert(Node* root, Node* node){
	if(root == NULL){
		return node;
	}
	if(root->priority < node->priority){
		// split()
	}// root의 priority가 더 크면 -> key값을 비교
	else if(node->key < root->key){
		root->setLeft(insert(root->left, node));
	}else{
		root->setRight(insert(root->right, node));
	}
	
	return root;

}


int main(){

	Node node(1);

	return 0;
}