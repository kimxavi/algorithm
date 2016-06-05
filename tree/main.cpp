#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "BPlusTree.h"

int main(int argc, char** argv){
	BPlusTree<int,int> map;
	map.insert(3,1);
	map.insert(2,2);
	map.insert(5,3);
	map.insert(3,4);
	map.insert(3,5);
	map.insert(3,6);
	map.insert(6,7);
	map.insert(8,8);
	map.insert(10,9);
	map.insert(1,10);
	map.insert(6,11);
	map.insert(9,12);
	map.insert(13,13);
	map.insert(3,14);
	map.levelOrder();
	map.insert(2,15);
	map.insert(1,16);
	map.insert(5,17);
	map.insert(6,18);
	return 0;
}
