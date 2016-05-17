#include <stdio.h>
#include "arrayList.h"

int main(int argc,char** argv){
	list<int>* list = new arrayList<int>();

	delete list;
	return 0;
}
