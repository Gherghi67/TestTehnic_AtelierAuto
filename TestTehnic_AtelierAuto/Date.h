#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
	int day;
	int month;
	int year;

public:
	Date();
	Date(int day, int month, int year);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void printDate() const;
};

#endif