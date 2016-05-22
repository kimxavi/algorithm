#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

template <class T>
void test(List<T>* arr){
try{
	for(int i=0; i< 100; i++){
		arr->add(i);
	}
	for(int i=0; i<100; i++){
		if(i != arr->get(i)){
			throw -1; 
		}
//		printf("%d\n",arr->get(i));
	}

	delete arr;
	arr = NULL;
}catch( ERROR e ){
	delete arr;
	printf("[ERROR] %d\n",e);
}catch(...){
	delete arr;
	printf("[ERROR] Unknown\n");
}
}
void testStack(Stack<int>* stack){
try{
	int testSize = 10;
	for(int i=0; i<testSize; i++){
		stack->push(i);
//		printf("%d\n",i);
	}
	for(int i = testSize -1 ;i >=0;i--){
		int value = stack->pop();
		if(i != value){ 
			throw -1;
		}
//		printf("%d\n", value);
	}
	delete stack;
}catch( ERROR e ){
	delete stack;
	printf("[ERROR] %d\n",e);
}catch(...){
	delete stack;
	printf("[ERROR] Unknown\n");
}
}
void testQueue(Queue<int>* queue){
try{
	int testSize = 10;
	for(int i=0; i< testSize; i++){
		queue->push(i);
//		printf("%d\n", i);
	}
	for(int i = 0 ;i < testSize;i++){
		int value = queue->pop();
		if(i != value){ 
			throw -1;
		}
//		printf("%d\n", value);
	}
	delete queue;
}catch( ERROR e ){
	delete queue;
	printf("[ERROR] %d\n",e);
}catch(...){
	delete queue;
	printf("[ERROR] Unknown\n");
}
}
void segfault_sigaction(int signal, siginfo_t *si, void *arg){
	printf("Caught segfault at address %p\n", si->si_addr);
	exit(0);
}
int main(int argc,char** argv){
	//S: catch segmentation fault
	struct sigaction sa;

	memset(&sa, 0, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = segfault_sigaction;
	sa.sa_flags   = SA_SIGINFO;

	sigaction(SIGSEGV, &sa, NULL);
	//E: catch segmentation fault

	test(new ArrayList<int>());
	test(new LinkedList<int>());
	testStack(new Stack<int>());
	testQueue(new Queue<int>());
	return 0;
}
