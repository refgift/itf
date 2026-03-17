// (C) Copyright 2024 Larry B. Daniel
// Reduce, given a number will reduce it to a digit.
#include <stdlib.h>
#include <stdio.h>

int reduce(int a) {
	if (a == 0) return 0;
	int root = a % 9;
	return (root == 0) ? 9 : root;
}

int tmain(int argc, char** argv) {
	if (argv[1]==nullptr) exit(-1);
	printf("%s, %d\n", argv[1], reduce(atoi(argv[1])));
	return 0;
}
		
	
