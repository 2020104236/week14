#include "queue.h"

void queue::Analysis() {
	cout << "평균 : " << sum / 120 << " ("
		<<(sum/120)*100/capacity<<" % )" << endl;
	cout << "손실 : " << lost << endl;
	Sort();
	cout << "최대치 : " << NofPackets[0] << endl;
}
void queue::Graphtxt(string a) {
	ofstream xx(a);
	if (!xx) cout << "Can't make " << a << endl;
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
			lost += v.size() + ni - capacity;
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
void queue::Sort() {
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
