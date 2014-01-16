#include "WPILib.h"

class RobotDemo : public SimpleRobot
{
	RobotDrive myRobot;	// robot drive system
	Encoder digEncoder;	// digital encoder
	AnalogChannel ultra;	// ultrasonic

public:
	RobotDemo(void):		// Init in same order declared above
		myRobot(8,1, 2, 9),	// Init RobotDrive in pins 8, 1, 2, 9
		digEncoder(13, 14),	// Init Encoder in pins 13, 14
		ultra(1, 1)		// Init AnalogChannel in module 1, pin 1
	{											
		myRobot.SetExpiration(0.1);
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous(void)
	{
		myRobot.SetSafetyEnabled(false);
		myRobot.Drive(-0.5, 0.0); 	// drive forwards half speed
		Wait(2.0); 			// for 2 seconds
		myRobot.Drive(0.0, 0.0); 	// stop robot
	}
	
	void OperatorControl(void)
	{
		myRobot.SetSafetyEnabled(true);
		digEncoder.Start();
		const double ppsTOrpm = 60.0/250.0;	//Convert from Pos per Second to Rotations per Minute by multiplication (See back of encoder to replace 250 if you need it)
		const float VoltsToIn = 40.0; 		// Convert from volts to cm by multiplication (volts from ultrasonic)
		
		while (IsOperatorControl())
		{
			SmartDashboard::PutNumber("Digital Encoder RPM", digEncoder.GetRate()*ppsTOrpm);
			SmartDashboard::PutNumber("Ultrasonic Distance (Inches)", (double) ultra.GetAverageVoltage()*VoltsToIn);
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

