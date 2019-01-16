#pragma once
#ifndef DELTATIME
#define DELTATIME

#include <chrono>

using namespace std::chrono;

class DeltaTime
{
public:

	DeltaTime();
	~DeltaTime() {};

private:

	double	m_deltaTimeStep = 10;
	double	m_accumulator = 0;

	double	m_frameRate = 0;
	double	m_frameRateDisplay = 0;
	double	m_frameRateTimer = 0;

	double m_burntCycles = 0;

	double	m_current_dt = 0;
	bool	m_canUpdate;

	high_resolution_clock::time_point			m_startingTime;
	high_resolution_clock::time_point			m_newTime;
	high_resolution_clock::time_point			m_currentTime;
	std::chrono::duration<double, std::milli>	m_frameTime;

	high_resolution_clock::time_point Now();


public:

	double getBurntCycles();

	void CalculateFPS();

	bool const Update();

	double & const getDeltaTime();

	double & const getAccumulator();

	double & const getFrameRate();

	void setStaticDT(double const & newDt);
	double & const getStaticDT();
};

#endif // !DELTATIME