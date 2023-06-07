#include "queue.h"

void queue::AverageMax() {
	cout << "Æò±Õ : " << sum / 120 << endl;
	sort();
	cout << "ÃÖ°íÄ¡ : " << NofPackets[0] << endl;
}
void queue::Graphtxt(string a) {
	ofstream xx(a);
	int itime = 0;
	while (itime++ < 120) {
		xx << NofPackets[itime] << endl;
	}
	xx.close();
}

void queue::FIFO() {
	int itime = 0, ni, no;
	while (itime++ < 120) {
		Sleep(10);
		ni = rand() % NI; no = rand() % NO;
		if (capacity < v.size() + ni) {
			ni = capacity - v.size();
		}
		for (int i = 0; i < ni; i++) {
			v.push_back(rand() % NI);
		}
		for (int i = 0; i < no; i++) {
			if (v.size() != 0) {
				v.erase(v.begin());
			}
		}
		NofPackets[itime] = v.size();
		sum += NofPackets[itime];
	}
}
void queue::sort() {
	for (int i = 0; i < 119; i++) {
		for (int j = i + 1; j < 120; j++) {
			if (NofPackets[i] < NofPackets[j]) {
				int c = NofPackets[i];
				NofPackets[i] = NofPackets[j];
				NofPackets[j] = c;
			}
		}
	}
}