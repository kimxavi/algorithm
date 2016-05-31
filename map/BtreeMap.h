#ifndef __BTREEMAP_H_ 
#define __BTREEMAP_H_

#include "Map.h"
#include "Node.h"
#include "../list/Queue.h"
#include "../list/Stack.h"

template <class K,class V>
class BtreeMap : public Map<K,V>{
public:
	BtreeMap();
	~BtreeMap();
public:

	int getSize() const{return size;};
	bool isEmpty() const{return size == 0;}; 
	V get(const K& key) ; 
	V put(const K& key,const V& value);
	void levelOrder();

private:
	void _splitLeaf(pNode p, pNode c);
	void _split(pNode p, pNode c);
	int size;
	pNode root;
};

template <class K,class V>
BtreeMap<K,V>::BtreeMap(){
	size = 0;
	root = new Node<K,V>();
}

template <class K,class V>
BtreeMap<K,V>::~BtreeMap(){
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
V BtreeMap<K,V>::get(const K& key) {

	return 0;	
}
template <class K,class V>
V BtreeMap<K,V>::put(const K& key,const V& value){
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
void BtreeMap<K,V>::levelOrder(){
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
void BtreeMap<K,V>::_splitLeaf(pNode p, pNode c){
	if(p == root){
		pNode nNode = new Node<K,V>();
		p->left(0) = nNode;
		p = nNode;
	}
	pNode left= c->splitFirst();
	p ->insert(new Data<K,V>(c->key(0),0), left,c);
}
template <class K,class V>
void BtreeMap<K,V>::_split(pNode p, pNode c){
	if(p == root){
		pNode nNode = new Node<K,V>();
		p->left(0) = nNode;
		p = nNode;
	}
	c->splitNode(p);
}

#endif
