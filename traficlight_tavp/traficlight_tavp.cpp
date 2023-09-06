#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;

typedef enum States { RcGp, REcRp, GcRp, EcRp } States;

void img_tl(int n, States a) {
	if (a == RcGp) {
		cout << "|  RED   |" << endl;
		cout << "|   "<< setw(2) << setfill('0') << n <<"   |" << "|       |" << endl;
		cout << "|        |" << "| GREEN |" << endl;
	}
	if (a == REcRp) {
		cout << "|  RED   |" << endl;
		cout << "| YELLOW |" << "|  RED  |" << endl;
		cout << "|        |" << "|       |" << endl;
	}
	if (a == GcRp) {
		cout << "|        |" << endl;
		cout << "|   " << setw(2) << setfill('0') << n << "   |" << "|  RED  |" << endl;
		cout << "| GREEN  |" << "|       |" << endl;
	}
	if (a == EcRp) {
		cout << "|        |" << endl;
		cout << "| YELLOW |" << "|  RED  |" << endl;
		cout << "|        |" << "|       |" << endl;
	}

}

int main()
{
	using namespace std::this_thread; 
	using namespace std::chrono; 

    system("chcp 1251 > 0");
    States State = RcGp;
	int start = time(NULL);

	while (1) {
		switch (State)
		{
		case RcGp:
			for (int i = 10; i > 0; i--) {
				img_tl(i, State);
				sleep_for(seconds(1));
				system("cls");
			}
			State = REcRp;
			break;

		case REcRp:
			img_tl(0, State);
			sleep_for(seconds(2));
			system("cls");
			State = GcRp;
			break;

		case GcRp:
			for (int i = 10; i > 0; i--) {
				img_tl(i, State);
				sleep_for(seconds(1));
				system("cls");
			}
			State = EcRp;
			break;

		case EcRp:
			img_tl(0, State);
			sleep_for(seconds(2));
			system("cls");
			State = RcGp;
			break;
		}
	}
}



