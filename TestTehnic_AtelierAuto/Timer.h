#ifndef TIMER_H
#define TIMER_H

#include <chrono>

// clasa Timer folosita pentru a cronometra fiecare angajat
class Timer {

private:

	std::chrono::system_clock::time_point begin;

	bool running;
public:
	Timer();

	void start();
	void stop();
	/*void reset();*/

	int getDuration() const;

	bool isRunning() const;
};

#endif