#include <iostream>
#include <time.h>
#include <unistd.h>
#include <iomanip>
#include <ctime>

using namespace std;

void wait(short seconds) {
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait);
}

void Timer() {
	int min = 0;
	for (short m = min; m >= 0; m--) {
		for (short s = 5; s >= 0 ; s--) {
			if (m == -1) exit(0);
		cout << '\r' << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s << flush;
			//usleep(1000000);
			//cout << m << ':' << s;
			wait(1);
			//system("CLS");
		}
		//wait(60);
	}
}


/*int main() {
	Timer();
	cin.ignore();
	return 0;
}*/
