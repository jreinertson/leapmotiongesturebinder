class LeapEventListener : public Listener {
	public:
	    virtual void onConnect(const Controller&);
	    virtual void onDisconnect(const Controller&);
	    virtual void onFrame(const Controller&);
};

void LeapEventListener::onConnect(const Controller& controller) {
	std::cout << "Connected" << std::endl;
    // Enable gestures, set Config values:
    controller.enableGesture(Gesture::TYPE_SWIPE);
    controller.config().setFloat("Gesture.Swipe.MinLength", 200.0);
    controller.config().save();
}


void LeapEventListener::onDisconnect(const Controller& controller) {
	
}


void LeapEventListener::onFrame(const Controller& controller) {
	
}