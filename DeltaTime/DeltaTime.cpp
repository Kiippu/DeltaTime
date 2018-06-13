#include "DeltaTime.h"


DeltaTime::DeltaTime()
{
	m_currentTime = Now();
}


DeltaTime::~DeltaTime()
{
}

high_resolution_clock::time_point DeltaTime::Now()
{
	return std::chrono::high_resolution_clock::now();
}

void DeltaTime::Update()
{
	m_newTime = Now();
	m_frameTime = m_currentTime - m_newTime;
	m_currentTime = m_newTime;

	

}

double DeltaTime::getDeltaTime()
{
	return 0.0;
}
