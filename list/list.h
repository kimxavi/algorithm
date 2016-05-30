#ifndef __LIST_H_
#define __LIST_H_
#include <stdio.h>

enum ERROR{
	OutOfBoundError = 20,
	MemoryAllocError
};

template <class T>
class List{
public:
	List(){};
	virtual ~List(){};

public:
	virtual bool add(const T& item) = 0;
	virtual bool add(const int index, const T& item) = 0;
	virtual int getSize() const = 0;
	virtual bool isEmpty() const = 0;
	virtual bool contains(const T& item) const = 0;
	virtual void clear() = 0;
	virtual T get(const int index) const = 0;
	virtual T& get(const int index) = 0;
	virtual T remove(const int index) = 0;
};
#endif
