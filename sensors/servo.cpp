#include "WPILib.h"

/*
 * This is working code for a servo.  We had issues at first until we found we needed to short out
 * the pwm pins next to the servo's pins.
 */ 
class RobotDemo : public SimpleRobot
{
	Servo servo;

public:
	RobotDemo(void):
		servo(5)
	{											

	}

	void Autonomous(void)
	{
		
	}
	
	/**
	 * Servo code with SmartDashboard
	 */
	void OperatorControl(void)
	{
		servo.SetAngle(0.0);
		SmartDashboard::PutNumber("Servo angle", (double) servo.GetAngle());

		while (IsOperatorControl())
		{
			servo.SetAngle(SmartDashboard::GetNumber("Servo angle"));				// Set angle to angle inputted on SmartDashboard
			SmartDashboard::PutNumber("Servo angle", (double) servo.GetAngle());	// Update the servo angle on SmartDashboard

			Wait(0.1);		// Pause for 0.1 seconds
		}
	}
	
	
	/**
	 * Runs during test mode
	 */
	void Test() {
			
	}
};

START_ROBOT_CLASS(RobotDemo);

