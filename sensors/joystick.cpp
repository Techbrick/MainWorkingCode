#include "WPILib.h"

// This is working code for the joystick sensor.  Check the header file for the proper initializing function.

class RobotDemo : public SimpleRobot
{
	Joystick stick; // only joystick

public:
	RobotDemo(void):		//Init in same order as listed above
		stick(1)
	{
	}

	
	void Autonomous(void)
	{
	}


	void OperatorControl(void)
	{
		while (IsOperatorControl())
		{
			if (stick.GetRawButton(1)) {
				SmartDashboard::PutNumber("Button 1 Pressed", 1);
			} else {
				SmartDashboard::PutNumber("Button 1 Pressed", 0);
			}
			Wait(0.1);
		}
	}
	
	
	/**
	 * Runs during test mode
	 */
	void Test() {
			
	}
};

START_ROBOT_CLASS(RobotDemo);

