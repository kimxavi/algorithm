#ifndef __BTREEMAP_H_ 
#define __BTREEMAP_H_

#include "Map.h"

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

private:
	int size;
};

template <class K,class V>
BtreeMap<K,V>::BtreeMap(){
}

template <class K,class V>
BtreeMap<K,V>::~BtreeMap(){
}

template <class K,class V>
V BtreeMap<K,V>::get(const K& key) {
	return 0; 
}
template <class K,class V>
V BtreeMap<K,V>::put(const K& key,const V& value){
	return 0;
}

#endif
