#ifndef __LIST_H_
#define __LIST_H_
#include <stdio.h>

template <class T>
class List{
public:
	List(){};
	virtual ~List(){};

public:
	virtual bool add(const T& item) = 0;
	virtual int getSize() const = 0;
	virtual bool isEmpty() const = 0;
	virtual bool contains(const T& item) const = 0;
	virtual void clear() = 0;
	virtual T get(const int index) const = 0;
	virtual T& get(const int index) = 0;
	
/*
	virtual int GetCount() const = 0; 
	virtual bool IsEmpty() const = 0;  
	
	virtual void* InsertBefore(void* pos, const T& newElem) = 0;
	virtual void* InsertNext(void* pos, const T& newElem) = 0;
	
	virtual void* AddHead(const T& newElem) = 0;
	virtual void* AddTail(const T& newElem) = 0; 

	virtual bool IsValid(void* pos) const = 0; 

	virtual T& GetHead() = 0; 
	virtual T GetHead() const = 0; 
	virtual T& GetTail() = 0;
	virtual T GetTail() const = 0;

	virtual T DeleteAt(void* pos) = 0;

	virtual T RemoveHead() = 0; 
	virtual T RemoveTail() = 0;

	virtual void RemoveAll() = 0;

	virtual void* GetHeadPosition() const = 0; 
	virtual T& GetNext(void*& pos) = 0;
	virtual T GetNext(void*& pos) const = 0;

	virtual void* GetTailPosition() const = 0;
	virtual T& GetPrev(void*& pos) = 0;
	virtual T GetPrev(void*& pos) const = 0;

	virtual T& GetAt(void* pos) = 0;
	virtual T GetAt(void* pos) const = 0;
	virtual void SetAt(void* pos, const T& newElem) = 0;

	virtual void* Find(const T& searchValue, void*startAfter = 0) const = 0;
	virtual void* FindReverse(const T& searchValue, void* startFrom = 0) const = 0;
	virtual void* FindIndex(int nIndex) const = 0;	
*/
};
#endif
