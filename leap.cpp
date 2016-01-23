#include <iostream>
#include "Leap.h"

using namespace Leap;

class LeapEventListener : public Listener {
	public:
		virtual void onInit(const Controller&);
	    virtual void onConnect(const Controller&);
	    virtual void onDisconnect(const Controller&);
	    virtual void onFrame(const Controller&);

};

void LeapEventListener::onInit(const Controller& controller) {
  std::cout << "Initialized" << std::endl;
}


void LeapEventListener::onConnect(const Controller& controller) {
	std::cout << "Connected" << std::endl;
    // Enable gestures, set Config values:
    controller.enableGesture(Gesture::TYPE_SWIPE);
    controller.enableGesture(Gesture::TYPE_INVALID);
    controller.enableGesture(Gesture::TYPE_CIRCLE);
    controller.enableGesture(Gesture::TYPE_SCREEN_TAP);
    controller.enableGesture(Gesture::TYPE_KEY_TAP);
    
    // controller.config().setFloat("Gesture.Swipe.MinLength", 200.0);
    // controller.config().setFloat("Gesture.Circle.MinRadius", );
    // controller.config().save();
}


void LeapEventListener::onDisconnect(const Controller& controller) {
    std::cout << "Disconnected" << std::endl;
}


void LeapEventListener::onFrame(const Controller& controller) {
	std::cout << "New frame available" << std::endl;
    Leap::Frame frame = controller.frame();
}


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