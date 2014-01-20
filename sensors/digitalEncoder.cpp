#include "WPILib.h"

/**
 * This is working code for a digital encoder.
 */ 
class RobotDemo : public SimpleRobot
{
	Encoder digEncoder;

public:
	RobotDemo(void):
		digEncoder(13, 14)
	{											
		digEncoder.SetDistancePerPulse( (6.0*3.14159)/250.0 );	// Set the distance per pulse (or position) of the encoder
																// to (wheel circumference)/(number of pulses per revolution).
																// This is required to use digEncoder.GetDistance() (and get the correct distance).
	}

	void Autonomous(void)
	{
	
	}

	
	void OperatorControl(void)
	{
		digEncoder.Start();
		digEncoder.Reset();		// Reset the distance measured.

		const double ppsTOrpm = 60.0/250.0;   // Convert from Pos per Second to Rotations per Minute by multiplication
                                              // (See the second number on the back of the encoder to replace 250 for different encoders)
      
		while (IsOperatorControl())
		{
			SmartDashboard::PutNumber("Digital Encoder RPM", abs(digEncoder.GetRate()*ppsTOrpm));	// Put the RPM on SmartDashboard
			SmartDashboard::PutNumber("Digital Encoder Distance", digEncoder.GetDistance());		// See the SetDistancePerPulse function in RobotDemo's init

			Wait(0.1);
		}
		digEncoder.Stop();		// Stop the digital encoder
	}
	
	
	/**
	 * Runs during test mode
	 */
	void Test() {
		
	}	

};

START_ROBOT_CLASS(RobotDemo);

