#ifndef __STACK_H_
#define __STACK_H_
#endif

#include "ArrayList.h"
#include "LinkedList.h"

template <class T>
class Stack{
public:
	Stack(){
		//stack = new ArrayList<T>();
		stack = new LinkedList<T>();
	};
	~Stack(){
		delete stack;
	};

	T pop(){
		return stack->remove(stack->getSize() - 1);
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
