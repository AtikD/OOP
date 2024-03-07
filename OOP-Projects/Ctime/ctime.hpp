#pragma once

enum Status { Successful = 0, Warning, Error };

class CTime {
	int hours;
	int minutes;
	int seconds;

public:
	CTime(int hours, int minutes, int seconds);
	CTime(const CTime *t);
	CTime();

	Status assign(CTime* t) const;
	void input();
	void add_minutes(int minutes);
	void add_seconds(int seconds);
	void add_hours(int hours);
	void output() const;	
	void set_values(int hours, int minutes, int seconds);
	void compare(const CTime* t) const;

private:
	Status check() const;
	Status convert();
};

