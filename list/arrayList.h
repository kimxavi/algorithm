#ifndef __ARRAYLIST_H_
#define __ARRAYLIST_H_
#include "List.h"
	
enum ERROR{
	OutOfBoundError = 20,
	MemoryAllocError
};

#define DEFAULT_SIZE (1024)

template <class T>
class ArrayList : public List<T>{
public:
	ArrayList(){
		_init(DEFAULT_SIZE);
	};
	ArrayList(int _capacity){
		_init(_capacity);
	};
	~ArrayList(){
		clear();
		delete [] array;
	};
	bool add(const T& item){
		return add(size,item);
	};

	bool add(const int index, const T& item){
		if(size >= capacity){
			int newCapacity = capacity << 1;
			T** tmpArray = new T*[newCapacity];
			if(tmpArray == NULL)
				throw MemoryAllocError;
			for(int i =0; i<newCapacity; i++){
				if(i >= capacity){
					tmpArray[i] = NULL;
					continue;
				}
				tmpArray[i] = array[i]; 
				delete array[i];
			}
			delete [] array;
			array = NULL;
			array = tmpArray;
			capacity = newCapacity;
		}
		array[index] = new T;
		*array[index] = item;
		size++;
		return true;
		
	};

	int getSize() const{return size;};
	T get(const int index) const{
		_indexCheck(index);
		return *array[index];
	};
	T& get(const int index){
		_indexCheck(index); 
		return *array[index];
	};
	bool isEmpty() const{
		return size <= 0;
	};
	bool contains(const T& item) const{
		for(int i=0; i<size;i++){
			if(*array[i] == item){
				return true;
			}
		}
		return false;
	};
	void clear() {
		for(int i=0;i<capacity;i++){
			delete array[i];
		}
		size = 0;
	};
	T remove(const int index){
		_indexCheck(index); 
		T val = *array[index];
		delete array[index];
		array[index] = NULL;
		for(int i=index;i<size;i++){
			array[i]=array[i+1];
		}
		array[size] = NULL;
		size--;
		return val;
	};

private:
	void _init(const int _capacity){
		capacity = _capacity;
		array = new T*[capacity];
		if(array == NULL)
			throw MemoryAllocError;
		for(int i= 0; i< capacity; i++){
			array[i] = NULL;
		}
		size = 0;
	};
	bool _indexCheck(const int index) const {
		if(index < 0 || index >= size )
			throw OutOfBoundError; 
		return false;
	};
private:
	T** array;
	int capacity;
	int size;
};
#endif
