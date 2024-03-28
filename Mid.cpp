#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Reservation {
public:
	string customer_name;
	int time_slot;
	int no_of_customers;

	Reservation(string name, int slot, int total)
		: customer_name(name), time_slot(slot), no_of_customers(total){}
};

class Restaurant {
private:
	map<int, bool> time_slots;
	vector<Reservation> reservations;;
public:
	Restaurant() {
		for (int i = 17; i <= 23; ++i) {
			time_slots[i] = true;
		}
	}
	void available_time_slots() {
		cout << "available time slots: " << endl;
		for (const auto& slot : time_slots) {
			if (slot.second) {
				cout << slot.first << "00 hrs " << endl;
			}
		}
	}
	void make_reservation(const string& name, int time, int size) {
		if (time_slots.find(time) != time_slots.end() && time_slots[time]) {
			reservations.emplace_back(name, time, size);
			time_slots[time] = false;
			cout << "Reservation Confirmed For *" << name << "* at *" << time << "00 hrs* for *" << size << "* people." << endl;

		}
		else {
			cout << "sorry! timeslots are all booked, pls choose a different time" << endl;

		}
	}

};

int main()
{
	Restaurant Scores;
	int choice = 0;
	while (choice != 3) {
		cout << "\n----Scores Reservation System----\n";
		cout << "Options: \n";
		cout << "1. View available time slots\n";
		cout << "2. Make a reservation\n";
		cout << "3. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		
		if (choice == 1) {
			cout << "**********" << endl;
			Scores.available_time_slots();
			cout << "**********" << endl;
		}
		else if (choice == 2) {
			string name;
			int time, size;
			cout << "Enter your name\n";
			cin >> name;
			cout << "Enter preferred time slot (17 - 23) \n";
			cin >> time;
			cout << "Enter the total no. of people\n";
			cin >> size;
			Scores.make_reservation(name, time, size);
		}
		else if (choice == 3) {
			cout << "exiting program" << endl;
			return 1;
		}
		else {
			cout << "invalid input!" << endl;
		}
	}
	return 0;
}

