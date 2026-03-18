// Indentity Theive fighter (itf) 
// (C) Copyright 2026 Larry B. Daniel Atlanta Ga.
// Optimized by Grok the AI
#include <thread>
#include <chrono>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <csignal>
#include <cmath>
#include <cstring>
#define IDTHIEVE 139
#define TRUTH 66
#define POSITION 173
using namespace std;
using namespace std::chrono;
volatile sig_atomic_t quit = 0;
void sigint(int) { quit = 1; }
int rndresult = 0;
int rnd() {
    asm("jt: rdrand %0; jnc jt" : "=r"(rndresult));
    return rndresult;
}
int reduce(int a) {
    if (a == 0) return 0;
    int root = a % 9;
    return (root == 0) ? 9 : root;
}
volatile int F;
void apply(int a) {
    F = 0; this_thread::sleep_for(milliseconds(1));
    F = a; this_thread::sleep_for(milliseconds(3));
    F = 0; this_thread::sleep_for(milliseconds(1));
}
int A = 0, B = 0, C = 0;
bool quiet=false;
int main(int argc, char** argv) {
    if (argv[1]!=nullptr) {
	if (strcmp(argv[1], "-q")==0) quiet=true;
	if (strcmp(argv[1], "-h")==0) {
		cout << "Usage: -q for no output, -h for help, cntl-c to quit." << endl;
		exit(0);
	}
    }
    signal(SIGINT, sigint);
    if (!quiet) cerr << "itf" << endl;
    auto last_dot = steady_clock::now();
    int hits = 0;
    while (!quit) {
        int r = abs(rnd());
        int n = reduce(r);
        if (n == 1 && A == 0) A = n;
        if (n == 3 && A == 1) B = n;
        if (n == 9 && B == 3) C = n;
        if (duration_cast<seconds>(steady_clock::now() - last_dot).count() >= 1) {
            if (!quiet) cerr << ".";
            last_dot = steady_clock::now();
        }
        if (A == 1 && B == 3 && C == 9) {
            apply(TRUTH);
            apply(POSITION);
            apply(POSITION);
            A = B = C = 0;
            ++hits;
            if (!quiet) cerr << " Hit #" << hits << "!" << endl;
            this_thread::sleep_for(milliseconds(111));
        }
        this_thread::yield();
    }
    if (!quiet) cerr << endl << "Quit. Hits: " << hits << endl;
    return 0;
}