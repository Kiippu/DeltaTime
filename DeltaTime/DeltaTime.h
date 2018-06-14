#pragma once
#ifndef DELTATIME
#define DELTATIME

#include <chrono>

using namespace std::chrono;

class DeltaTime
{

public:
	DeltaTime();
	~DeltaTime();

private:

	double m_deltaTimeStep = 0.016;
	double m_accumulator = 0;
	double m_frameRate = 0;

	high_resolution_clock::time_point m_startingTime;
	high_resolution_clock::time_point m_newTime;
	high_resolution_clock::time_point m_currentTime;
	std::chrono::duration<double, std::milli> m_frameTime;

	high_resolution_clock::time_point Now();

public:

	bool Update();

	double getDeltaTime();
};

#endif // !DELTATIME