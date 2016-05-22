#ifndef __LINKEDLIST_H_
#define __LINKEDLIST_H_
#include "List.h"



template <class T>
class LinkedList : public List<T>{
public:
	LinkedList(){
		headNode = new Node();
		tailNode = new Node();

		headNode->right = tailNode;
		tailNode->right = headNode;
		size = 0;
	};
	~LinkedList(){
		clear();

		delete headNode;
		delete tailNode;
	};
	bool add(const T& item){
		Node* n = headNode;
		while(n->right != tailNode){
			n = n->right; 
		}
		Node* newNode = new Node(item, n->right);
		n->right = newNode;
		size++;
		return true;
	};
	int getSize() const{return size;};
	bool isEmpty() const{
		return size <= 0;
	};
	bool contains(const T& item) const{
		Node* currentNode = headNode;
		while( (currentNode = currentNode->right) != tailNode){
			if(currentNode->data == item){
				return true;
			}
		}
		return false;
	};

	void clear(){
		Node* currentNode = headNode->right;
		Node* nextNode = NULL; 
		while(size--){
			nextNode = currentNode->right;
			delete currentNode;
			currentNode = NULL;
			currentNode = nextNode;
		}
		size = 0;
	};
	T get(const int index) const{
		_indexCheck(index);
		Node* n = headNode->right;
		for(int i=0; i< index;i++){
			n = n->right;
		}
		return n->data;
	};
	T& get(const int index){
		_indexCheck(index);
		Node* n = headNode->right;
		for(int i=0; i< index;i++){
			n = n->right;
		}
		return n->data;
	};
private:
	bool _indexCheck(const int index) const {
		if(index < 0 || index > size )
			throw OutOfBoundError; 
		return false;
	};
	struct Node{
		T data;
		Node* right;
		Node(){
			right = NULL;
		};
		Node(T _data){
			right = NULL;
			data  = _data;
		};
		Node(T _data,Node* _right){
			right = _right;
			data  = _data;
		};
		~Node(){
			right = NULL;
		};
	};

	Node* headNode;
	Node* tailNode;

	int size;
};

#endif
