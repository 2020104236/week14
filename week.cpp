#include "queue.h"

int main() { 
	ofstream yy("Graph.txt");
	if (!yy) return 666;
	for (int i = 0; i < 30; i++){
		queue q(30, 30 + i);
		q.FIFO();
		yy << float(q.NI)/float(q.NO)<< "  " << (q.sum/120) * 100 / q.capacity << endl;
	}
	yy.close();
	return 123;
}
