#include <iostream>
#include "Leap.h"
#include "listener.h"

using namespace Leap;

int main(int argc, char ** argv) {
	Controller controller;
	LeapEventListener listener;

	controller.addListener(listener);

	// Keep process until enter
	std::cout << "Press Enter to quit..." << std::endl;
    std::cin.get();

	controller.removeListener(listener);

	return 0;
}