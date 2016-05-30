#ifndef __MAP_H_
#define __MAP_H_
#include <stdio.h>

template <class K,class V>
class Map{
public:

	virtual int getSize() const = 0;
	virtual bool isEmpty() const = 0;
	virtual V get(const K& key) = 0;
	virtual V put(const K& key,const V& value) = 0;
};

#endif
