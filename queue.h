#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <fstream>

using namespace std;
class queue {
public:
	queue() :NI(60), NO(70), capacity(120), sum(0) { NofPackets = new int[120]; }
	int NI, NO, capacity, * NofPackets; float sum; vector<int> v;
	void Graphtxt(string);
	void FIFO();
	void sort();
	void AverageMax();
};