#define _CRT_SECURE_NO_WARNINGS
#include "DeltaTime.h"

DeltaTime::DeltaTime() {
	m_currentTime = Now();

}

// helper to get now time
high_resolution_clock::time_point DeltaTime::Now()
{
	return std::chrono::high_resolution_clock::now();
}

// counts the nmber of wasted cycles to get to desired FPS
double DeltaTime::getBurntCycles()
{
	double x = m_burntCycles;
	m_burntCycles = 0;
	return x;
}

// calculates the FPS 
void DeltaTime::CalculateFPS()
{
	long i = m_current_dt - m_frameRateTimer;
	if (i > 1000.0)
	{
		m_frameRateDisplay = m_frameRate;
		m_frameRate = 0;
		m_frameRateTimer = m_current_dt;
	}
	//m_frameRate++;
}

// main update loop to regulate iteration of full game loop.
bool const DeltaTime::Update()
{
	//set trigger to stop gameloop
	m_canUpdate = false;
	// get current time
	m_newTime = Now();
	// find time passed
	m_frameTime = m_newTime - m_currentTime;
	// trading new time for later frames
	m_currentTime = m_newTime;
	// add current time passed to 
	m_accumulator += m_frameTime.count();

	// build passed delta and left over delta time
	while (m_accumulator > m_deltaTimeStep) {
		m_canUpdate = true;
		m_current_dt += m_deltaTimeStep;
		m_accumulator -= m_deltaTimeStep;
	}

	//get FPS calculations
	CalculateFPS();

	// add delta time plus extra physics time passed
	//m_current_dt += m_deltaTimeStep * (m_accumulator/m_deltaTimeStep);

	// return true if deltaTime has passed
	if(m_canUpdate) {
		m_frameRate++;
		return true;
	}

	// a wasted update ++
	m_burntCycles++;

	// pass false if no delta time passed -> burnt time
	return false;
}

double & const DeltaTime::getDeltaTime()
{
	return m_current_dt;
}

double & const DeltaTime::getAccumulator()
{
	return m_accumulator;
}

double & const DeltaTime::getFrameRate()
{
	return m_frameRateDisplay;
}

void DeltaTime::setStaticDT(double const & newDt)
{
	m_deltaTimeStep = newDt;
}

double & const DeltaTime::getStaticDT()
{
	return m_deltaTimeStep;
}
