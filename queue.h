#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <fstream>

using namespace std;
class queue {
public:
	queue() {}
	queue(int x, int y) :capacity(120), sum(0), lost(0)
	{
		NI = x; NO = y; NofPackets = new int[120];
	}
	int NI, NO, capacity, * NofPackets,lost; float sum; vector<int> v;
	void Graphtxt(string);
	void FIFO();
	void Sort();
	void Analysis();
};
