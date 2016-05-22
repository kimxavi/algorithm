#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "LinkedList.h"

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
	}

	delete arr;
	arr = NULL;
}catch( ERROR e ){
	printf("[ERROR] %d\n",e);
}catch(...){
	printf("[ERROR] Unknown\n");
}
}
void segfault_sigaction(int signal, siginfo_t *si, void *arg)
{
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
	return 0;
}
