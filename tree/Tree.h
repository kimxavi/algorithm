#ifndef __TREE_H_
#define __TREE_H_ 
#include <stdio.h>

template <class K,class V>
class Tree{
public:

	virtual int getSize() const = 0;
	virtual bool isEmpty() const = 0;
	virtual bool insert(const K& key,const V& value)=0;
};

#endif
