#include "WPILib.h"

// This is working code for the digital encoder. Change the pin numbers to match your robot's config.

class RobotDemo : public SimpleRobot
{
	Encoder digEncoder;

public:
	RobotDemo(void):
		digEncoder(13, 14)	// Pin numbers 13 and 14
	{											
	}

	void Autonomous(void)
	{
	}


	void OperatorControl(void)
	{
		digEncoder.Start();
		const double ppsTOrpm = 60.0/250.0;	//This converts from Pos per Second to Rotations per Minute (See second number on back of encoder to replace 250 if you need it)
		
		while (IsOperatorControl())
		{
			SmartDashboard::PutNumber("Digital Encoder RPM", digEncoder.GetRate()*ppsTOrpm);
			Wait(0.1);
		}
		digEncoder.Stop();
	}
	
	
	/**
	 * Runs during test mode
	 */
	void Test() {
			
	}
};

START_ROBOT_CLASS(RobotDemo);

