#include <iostream>
#include <time.h>
#include <unistd.h>
#include <iomanip>

using namespace std;

int main() {
	int min = 0;
	for (int m = min; m >= 0; m--) {
		for (int s = 5; s >= 0 ; s--) {
			if (m == -1) exit(0);
			cout << '\r' << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s << flush;
			usleep(1000000);
		}
	}
	cout << endl;
}

