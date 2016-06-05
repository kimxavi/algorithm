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
	pData getData(const int i) const{return data[i];};
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
	void moveLeft(int index);
	void moveRight(int index);

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
void Node<K,V>::moveRight(int index){
	for(int i = size;i >index;i--){
		data[i]  = data[i-1];
		right(i) = right(i-1);
		left(i)	 = left(i-1);
	}
	data[index] = NULL;
	left(index) = NULL;
}
template <class K, class V>
void Node<K,V>::moveLeft(int index){
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
	moveRight(i);
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
	 moveLeft(index);
}
#endif
