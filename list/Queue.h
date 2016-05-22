#ifndef __QUEUE_H_
#define __QUEUE_H_
#include "ArrayList.h"
#include "LinkedList.h"
template <class T>
class Queue{
public:
	Queue(){
		//stack = new ArrayList<T>();
		stack = new LinkedList<T>();
	};
	~Queue(){
	};
	T pop(){
		return stack->remove(0);
	};
	void push(const T& item){
		stack->add(item);
	};
	bool isEmpty() const{
		return stack->isEmpty();
	};
private:
	List<T>* stack;
};
#endif
