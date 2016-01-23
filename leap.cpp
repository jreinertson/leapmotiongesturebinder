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
    controller.enableGesture(Gesture::TYPE_INVALID, false);
    controller.enableGesture(Gesture::TYPE_CIRCLE);
    // controller.enableGesture(Gesture::TYPE_SCREEN_TAP);
    controller.enableGesture(Gesture::TYPE_KEY_TAP);

    controller.config().setFloat("Gesture.Circle.MinRadius", 100);
    controller.config().setFloat("Gesture.Circle.MinArc", 30);
    controller.config().setFloat("Gesture.Swipe.MinLength", 200);
    // controller.config().setFloat("Gesture.KeyTap.Min")

    controller.config().save();
}


void LeapEventListener::onDisconnect(const Controller& controller) {
    std::cout << "Disconnected" << std::endl;
}

void handleSwipe(){
	std::cout << "Swipe" << std::endl;
}

void handleTap(){
	std::cout << "TAP" << std::endl;
}

void handleCircle(){
	std::cout << "Circle" << std::endl;
}


void LeapEventListener::onFrame(const Controller& controller) {
    Leap::Frame frame = controller.frame();

    Leap::GestureList gestures = frame.gestures();
	for(Leap::GestureList::const_iterator gl = gestures.begin(); gl != frame.gestures().end(); gl++){
	    switch ((*gl).type()) {
	        case Leap::Gesture::TYPE_CIRCLE:
	            //Handle circle gestures
	        	handleCircle();
	            break;
	        case Leap::Gesture::TYPE_KEY_TAP:
	        	//Handle key tap gestures
	        	handleTap();
	            break;
	        case Leap::Gesture::TYPE_SWIPE:
	            //Handle swipe gestures
	        	handleSwipe();
	            break;
	        default:
	            //Handle unrecognized gestures
	        	std::cout << "Invalid" << std::endl;
	            break;
    	}
    }

}

int main() {
	Controller controller;
	LeapEventListener listener;

	char filename[] = "read.tmp";
	// if (int fifo = mkfifo(filename, S_IRWXU) != 0) {

	// }

	controller.addListener(listener);

	// Keep process until enter
	std::cout << "Press Enter to quit..." << std::endl;
    std::cin.get();

	controller.removeListener(listener);

	return 0;
}