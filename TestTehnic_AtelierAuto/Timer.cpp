#include "Timer.h"

Timer::Timer() {
	running = false;
}

void Timer::start() {
	begin = std::chrono::system_clock::now();

	running = true;
}

void Timer::stop() {
	running = false;
}

int Timer::getDuration() const {
	std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();

	return std::chrono::duration_cast<std::chrono::seconds>(currentTime - begin).count();
}

bool Timer::isRunning() const {
	return running;
}