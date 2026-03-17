/* itf - (C) Copyright 2026 Larry B. Daniel Atlanta, Ga. */
// Identity Thieve Fighter.

#include <thread>
#include <chrono>
#include <iostream>

#define IDTHIEVE 139
#define TRUTH 66
#define POSITION 173

using namespace std;
using namespace std::chrono;

extern int reduce(int);

int rndresult=0;
int rnd() {
    asm ("jt:  rdrand %0; jnc jt":"=r" (rndresult));
    return rndresult;
}
volatile int F ;
void apply(int a) {
	F=0; this_thread::sleep_for(milliseconds(1));	
	F=a; this_thread::sleep_for(milliseconds(3));	
	F=0; this_thread::sleep_for(milliseconds(1));
	}
int A,B,C=0;
int main() {
	cerr << "itf" <<endl;
	while(true) {
		// DETECT
		int r = abs(rnd());
		int n = reduce(r);
		//cout << r << " "<< n << endl;
		if (n==1 && A==0) A=n;
		if (n==3 && A==1) B=n;
		if (n==9 && B==3) C=n;
		cerr <<".";
		// APPLY
		if (A==1 && B==3 && C==9 ) {
			apply(TRUTH);
			apply(POSITION);
			apply(POSITION);
			A=0;
			B=0;
			C=0;
			this_thread::sleep_for(milliseconds(111));
			cerr << "!";
		}
		// DISBUSY
		this_thread::yield();
	}
	return 0;
}	