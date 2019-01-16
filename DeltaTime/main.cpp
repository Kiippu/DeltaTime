#include "DeltaTime.h"
#include <memory>
#include <iostream>
#include <chrono>
#include <thread>

int main() {

	using namespace std;


	std::shared_ptr<DeltaTime> dt = std::make_shared<DeltaTime>();
	dt->setStaticDT(16);

	while (true)
	{
		while (dt->Update())
		{


			std::cout << " DeltaTiem: " << dt->getDeltaTime() << " - FPS: " << dt->getFrameRate() << " - burnt " << dt->getBurntCycles() << std::endl;


			//std::this_thread::sleep_for(0.001s);

		}
	}



	return 0;
}