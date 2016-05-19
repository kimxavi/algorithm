#ifndef __ARRAYLIST_H_
#define __ARRAYLIST_H_
#include <stdio.h>
#include "list.h"
	
enum ERROR{
	OutOfBoundError = 20,
	MemoryAllocError
};

template <class T>
class arrayList : public list<T>{
public:
	arrayList(){
		_init(1024);
	};
	arrayList(int _capacity){
		_init(_capacity);
	};
	~arrayList(){
		clear();
	};
	bool add(const T& item){
		if(size >= capacity){
			int newCapacity = capacity << 1;
			T* tmpArray = new T[newCapacity];
			if(tmpArray == NULL)
				throw MemoryAllocError;
			for(int i =0; i<size; i++){
				tmpArray[i] = array[i]; 
			}
			delete [] array;
			array = NULL;
			array = tmpArray;
			capacity = newCapacity;
		}
		array[size] = item;
		size++;
		return false;
	};
	int getSize() const{return size;};
	T get(const int index) const{
		_indexCheck(index);
		return array[index];
	};
	T& get(const int index){
		_indexCheck(index); 
		return array[index];
	};
	bool isEmpty() const{
		return size <= 0;
	};
	bool contains() const{
		return false;
	};
	void clear() {
		if(array != NULL)
			delete [] array;
		array = NULL;
		capacity = 0;
		size = 0;
	};

private:
	void _init(const int _capacity){
		capacity = _capacity;
		array = new T[capacity];
		if(array == NULL)
			throw MemoryAllocError;
		size = 0;
	};
	bool _indexCheck(const int index) const {
		if(index < 0 || index > size )
			throw OutOfBoundError; 
		return false;
	};
private:
	T* array;
	int capacity;
	int size;
};
#endif
