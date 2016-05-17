#ifndef __ARRAYLIST_H_
#define __ARRAYLIST_H_
#include <stdio.h>
#include "list.h"

template <class T>
class arrayList : public list<T>{
public:
	arrayList(){
		_init();
	};
	arrayList(int _capacity){
		_init(_capacity);
	};
	~arrayList(){
		_clear();
	};

private:
	void _init(int _capacity = 1024){
		array = new T[_capacity]; 
		capacity	= _capacity;
		count		= 0;
	};
	void _clear(void){
		if(array != NULL)
			delete [] array;
		array		= NULL;
		capacity	= 0;
		count		= 0;
	};
	
	int GetCount() const{return count;}; 
	bool IsEmpty() const{return count == 0;};
	
	void* InsertBefore(void* pos, const T& newElem){
		return NULL;
	};
	void* InsertNext(void* pos, const T& newElem){
		return NULL;
	};

private:
	T* array;
	int capacity;
	int count;
};
#endif
