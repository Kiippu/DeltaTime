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

	double m_deltaTimeStep = 0.01;
	double m_sccumulator = 0.0;

	high_resolution_clock::time_point m_startingTime;
	high_resolution_clock::time_point m_newTime;
	high_resolution_clock::time_point m_currentTime;
	high_resolution_clock::duration m_frameTime;

	high_resolution_clock::time_point Now();

public:

	void Update();

	double getDeltaTime();
};

#endif // !DELTATIME