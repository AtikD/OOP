#pragma once

class CTime {
	int _hours;
	int _minutes;
	int _seconds;

public:
	CTime();
	CTime(int hours, int minutes, int seconds);
	CTime(const CTime &t);
};