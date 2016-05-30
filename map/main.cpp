#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "BtreeMap.h"

int main(int argc, char** argv){
	BtreeMap<int,int> map;
	map.put(3,10);
	map.put(2,10);
	map.put(5,10);
	map.put(3,10);
	map.put(3,10);
	map.put(3,10);
	map.put(6,10);
	map.put(8,10);
	map.put(10,10);
	map.put(1,10);
	map.put(6,10);
	map.put(9,10);
	map.put(13,10);
	map.put(3,10);
	map.put(2,10);
	map.put(1,10);
	map.put(5,10);
	map.put(6,10);
	map.levelOrder();
	return 0;
}
