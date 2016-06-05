#ifndef __BPLUSTREE_H_
#define __BPLUSTREE_H_ 

#include "Tree.h"
#include "Node.h"
#include "../list/Queue.h"
#include "../list/Stack.h"

template <class K,class V>
class BPlusTree : public Tree<K,V>{
public:
	BPlusTree();
	~BPlusTree();
public:

	int getSize() const{return size;};
	bool isEmpty() const{return size == 0;}; 
	bool insert(const K& key,const V& value);
	void levelOrder();

private:
	void _splitLeaf(pNode p, pNode c);
	void _split(pNode p, pNode c);
	int size;
	pNode root;
};

template <class K,class V>
BPlusTree<K,V>::BPlusTree(){
	size = 0;
	root = new Node<K,V>();
}

template <class K,class V>
BPlusTree<K,V>::~BPlusTree(){
	Queue<pNode> queue;
	queue.push(root->left(0));
	pNode c;

	while( !queue.isEmpty() && (c = queue.pop()) != NULL){
		int i = 0;
		while(c->left(i) != NULL && i < DCOUNT){
			queue.push(c->left(i++));
		}
		delete c;
	}
	delete root;
}

template <class K,class V>
bool BPlusTree<K,V>::insert(const K& key,const V& value){
	pNode p = root;
	pNode c = root->left(0);
	Stack<pNode> stack;
	
	if(p == root && c == NULL){
		c = root->left(0) = new Node<K,V>();
	}else{
		int i;
		while(1){
			stack.push(p);
			for(i = 0; i< c->getSize() && c->key(i) < key;i++);
			if(c->isLeaf()) break;
			p = c;
			c = c->left(i);
		}
	}
	c->insert(new Data<K,V>(key,value));
	size++;
	while(c->isFull()){
		p = stack.pop();
		if(c->isLeaf())
			_splitLeaf(p,c);
		else
			_split(p,c);
		c = p;
	}

	return 0;
}

template <class K,class V>
void BPlusTree<K,V>::levelOrder(){
	Queue<pNode> queue;
	queue.push(root->left(0));
	pNode c;

	while( !queue.isEmpty() && (c = queue.pop()) != NULL){
		c->print();
		int i = 0;
		while(c->left(i) != NULL && i < DCOUNT){
			queue.push(c->left(i++));
		}
	}
	printf("\n\n");
}

template <class K,class V>
void BPlusTree<K,V>::_splitLeaf(pNode p, pNode c){
	if(p == root){
		pNode nNode = new Node<K,V>();
		p->left(0) = nNode;
		p = nNode;
	}
	pNode newNode = new Node<K,V>();
	newNode->insert(c->getData(0), c->left(0), c);
	c->moveLeft(0);

	p ->insert(new Data<K,V>(c->key(0),0), newNode ,c);
}
template <class K,class V>
void BPlusTree<K,V>::_split(pNode p, pNode c){
	if(p == root){
		pNode nNode = new Node<K,V>();
		p->left(0) = nNode;
		p = nNode;
	}

	pNode left = new Node<K,V>();
	for(int i = 0; i < DCOUNT/2;i++){
		left->insert(new Data<K,V>(c->key(i),0), c->left(i), c->right(i));
		c->moveLeft(0);
	}
	p->insert(new Data<K,V>( c->key(0),0),left,c);
	c->moveLeft(0);
}

#endif
