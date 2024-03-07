#include "ctime.hpp"
#include <iostream>

using namespace std;
//Конструкторы
CTime::CTime(int hours, int minutes, int seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
	this->convert();
}
CTime::CTime(const CTime *t) : CTime(t->hours, t->minutes, t->seconds) {}
CTime::CTime() : CTime(0, 0, 0) {}

//Функции
void CTime::output() const{
	cout << this->hours << ":" << this->minutes << ":" << this->seconds;
}

Status CTime::check() const {
	Status state = Successful;
	if ((this->seconds > 60 || this->seconds < 1) ||
		(this->minutes > 60 || this->minutes < 1) ||
		(this->hours > 24 || this->hours < 1))
		state = Error;
	return state;
}


void CTime::input() {
	char colon;
	cout << endl << "Write the time(dd:mm:yy): ";
	cin >> this->hours >> colon
		>> this->minutes >> colon
		>> this->seconds;
	cout << "Successfully read: ";
	this->convert();
	this->output();
	cout << endl;
}


void CTime::set_values(int hours, int minutes, int seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
	cout << endl << "Successfully set: ";
	this->convert();
	this->output();
	cout << endl;
}

Status CTime::convert() {
	Status state = Successful;
	while (true) {
		if (this->seconds > 60) {
			this->seconds -= 60;
			this->minutes++;
			continue;
		}
		else if (this->minutes > 60) {
			this->minutes -= 60;
			this->hours++;
			continue;
		}
		else if (this->hours > 24) {
			this->hours -= 24;
			state = Warning;
		}
		else
			break;
	}
	return state;
}

void CTime::add_hours(int hours) {
	this->hours += hours;
	cout << endl << "Succeadd_secondsssfully added hours: ";
	this->convert();
	this->output();
	cout << endl;
}

void CTime::add_minutes(int minutes) {
	this->minutes += minutes;
	cout << endl << "Successfully added minutes: ";
	this->convert();
	this->output();
	cout << endl;
}

void CTime::add_seconds(int seconds) {
	this->seconds += seconds;
	cout << endl << "Successfully added minutes: ";
	this->convert();
	this->output();
	cout << endl;
}

Status CTime::assign(CTime* t) const{
	Status state = Successful;
	if (t == nullptr)
		state = Error;
	else {
		t->hours = this->hours;
		t->minutes = this->minutes;
		t->seconds = this->seconds;
	}
	return state;
}

void CTime::compare(const CTime *t) const {
	int secs1 = 0, secs2 = 0;
	secs1 += this->seconds;
	secs1 += this->minutes * 60;
	secs1 += this->hours * 60 * 60;

	secs2 += t->seconds;
	secs2 += t->minutes * 60;
	secs2 += t->hours * 60 * 60;

	if (secs1 > secs2) {
		cout << endl;
		this->output();
		cout << " is bigger than ";
		t->output();
	}
	if (secs1 < secs2)
	{
		cout << endl;
		t->output();
		cout << " is bigger than ";
		this->output();
	}
	if (secs1 == secs2)
		cout << endl << "The time is equal";
	cout << endl;

}