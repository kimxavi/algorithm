#ifndef __NODE_H_
#define __NODE_H_

#define DCOUNT (3)
#define NCOUNT (DCOUNT+1)

#define pData Data<K,V>*
#define pNode Node<K,V>*
template <class K, class V>
struct Data{
	K key;
	V value;
	Data(){};
	~Data(){};
	Data(const K& k, const V& v){
		key = k;
		value = v;
	};
};

template <class K, class V>
class Node{
public:
	Node();
	~Node();
	K key(const int i) const{return data[i]->key;};
	K& key(const int i){return data[i]->key;};
	Node* left(const int i)const{return child[i];};
	Node*& left(const int i){return child[i];};
	Node* right(const int i)const{return child[i+1];};
	Node*& right(const int i){return child[i+1];};

	int getSize(){return size;};
	bool isLeaf(){return left(0) == NULL;};
	bool isFull(){return size == DCOUNT;};
	void insert(pData _data, Node* _left = NULL, Node* _right = NULL);
	void remove(int index, pData& _data, Node*& _left);
	pNode splitFirst();
	void splitNode(pNode p);
	void print();

private:
	void _moveRight(int index);
	void _moveLeft(int index);

private:
	Node** child;
	pData* data;
	int size;
};
template <class K, class V>
Node<K,V>::Node(){
	data	= new pData[DCOUNT];
	child	= new Node*[NCOUNT];
	for(int i=0; i<DCOUNT;i++)
		data[i] = NULL;
	for(int i=0; i<NCOUNT;i++)
		child[i] = NULL;
	size = 0;
};
template <class K, class V>
Node<K,V>::~Node(){
	delete [] child;
	for(int i = 0; i<size;i++)
		delete data[i];
	delete [] data;
};
template <class K, class V>
void Node<K,V>::_moveRight(int index){
	for(int i = size;i >index;i--){
		data[i]  = data[i-1];
		right(i) = right(i-1);
		left(i)	 = left(i-1);
	}
	data[index] = NULL;
	left(index) = NULL;
}
template <class K, class V>
void Node<K,V>::_moveLeft(int index){
	for(int i =index;i <size-1;i++){
		data[i]  = data[i+1];
		left(i)	 = left(i+1);
		right(i) = right(i+1);
	}
	data[size-1] = NULL;
	right(size-1) = NULL;
	size--;
}

template <class K, class V>
void Node<K,V>::insert(pData _data, Node* _left, Node* _right){
	int i = size;
	while(i >0 && key(i-1) >= _data->key) i--;
	_moveRight(i);
	data[i]  = _data;
	left(i)  = _left;
	right(i) = _right;
	size++;
}
template <class K, class V>
void Node<K,V>::print(){
	printf("size: %d  ",size);
	for(int i =0; i <size;i++)
		printf("%d ",key(i));
	printf("\n");
}
template <class K, class V>
void Node<K,V>::remove(int index, pData& _data, Node*& _left){
	 _data = data[index];
	 _left = left(index); 
	 _moveLeft(index);
}
template <class K, class V>
pNode Node<K,V>::splitFirst(){
	 pNode newNode = new Node<K,V>();
	 newNode->insert(data[0], left(0), this);
	 _moveLeft(0);
	 return newNode;
}
template <class K, class V>
void Node<K,V>::splitNode(pNode p){
	pNode left = new Node<K,V>();
	for(int i = 0; i < DCOUNT/2;i++){
		left->insert(new Data<K,V>(key(i),0), this->left(i), this->right(i));
		_moveLeft(0);
	}
	p->insert(new Data<K,V>( key(0),0),left,this);
	_moveLeft(0);
}
#endif
