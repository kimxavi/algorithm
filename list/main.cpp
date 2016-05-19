#include <stdio.h>
#include "arrayList.h"

int main(int argc,char** argv){
try{
	arrayList<int> arr(10);
	for(int i=0; i< 100; i++){
		arr.add(i);
	}

	for(int i=0; i<100; i++){
		if(i != arr.get(i)){
			throw -1; 
		}
	}

}catch( ERROR e ){
	printf("[ERROR] %d\n",e);
}catch(...){
	printf("[ERROR] Unknown\n");
}
	return 0;
}
