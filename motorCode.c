#pragma config(Sensor, dgtl1,  reverseOn,      sensorDigitalOut)
#pragma config(Sensor, dgtl2,  reverseOff,     sensorDigitalOut)
#pragma config(Sensor, dgtl3,  forkSwitch,     sensorTouch)
#pragma config(Sensor, dgtl4,  armSwitch,      sensorTouch)
#pragma config(Sensor, dgtl5,  wheelEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port2,           topRight,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           fRbR,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           fLbL,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           chainArm,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           bottomRight,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           bottomLeft,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           topLeft,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          intake,        tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

//7 inch cone; 4 inches half height

//void autoStack() {
//	while(autoSwitch == 1) {

//		for(int i=0; i < 5; i++) {
//			motor(armLeft) = 126;
//			motor(armRight) = 126;
//			wait1Msec(200 * i);
//			motor(armLeft) = -126;
//			motor(armRight) = -126;
//			wait1Msec(200 * i);
//		}
//	}
//}

task autonomous()
{


	//lower fork
	//motor[forkLeft] = 120;
	//motor[forkRight] = 120;
	//wait1Msec(1500);
	////stop fork; move forward
	//motor[forkLeft]= 0;
	//motor[forkRight] = 0;
	//motor[fLbL] = 127;
	//motor[fRbR] = 127;
	//wait1Msec(1350);
	////stop moving
	//motor[fRbR] = 0;
	//motor[fLbL] = 0;
	////raise fork
	//motor[forkLeft] = -120;
	//motor[forkRight] = -120;
	//wait1Msec(1600);
	//motor[forkLeft] = 0;
	//motor[forkRight] = 0;
	////back out (reverse)
	//motor[fRbR] = -120;
	//motor[fLbL] = -120;
	//wait1Msec(900);
	////turn robot
	//motor[fRbR] = 120;
	//motor[fLbL] = -80;
	//wait1Msec(650);
	////move foward
	//motor[fRbR] = 120;
	//motor[fLbL] = 120;
	//wait1Msec(500);
	////stop motors; lower forks
	//motor[fRbR] = 120;
	//motor[fLbL] = -80;
	//wait1Msec(450);
	//motor[fRbR] = 120;
	//motor[fLbL] = 80;
	//wait1Msec(800);
	//motor[fLbL] = 0;
	//motor[fRbR] = 0;
	//motor[pusherMotor] = 80;
	//motor[forkLeft] = 120;
	//motor[forkRight] = 120;
	//wait1Msec(1500);
	//motor[fLbL] = -80;
	//motor[fRbR] = -120;
	//motor[forkLeft] = -50;
	//motor[forkRight] = -50;
	//wait1Msec(800);
	////stop motors
	//motor[fLbL] = 0;
	//motor[fRbR] = 0;



	//set up for 10
	/*
	motor[forkLeft] = 80;
	motor[forkRight] = 80;
	wait1Msec(2000);
	motor[forkLeft] = 0;
	motor[forkRight] = 0;
	//bring cone down
	wait1Msec(100);
	motor[fLbL] = -80;
	motor[fRbR] = -120;
	wait1Msec(1000);
	motor[fLbL] = 0;
	motor[fRbR] = 0;
	*/

}

task usercontrol() {
	bool pressed = false;
	int motorSwitch = 1;
	int autoSwitch = 1;

	//int ticks;
	//int revs;
	//int distance;
	////distance to travel is 67

	while(true)	{
		if(vexRT[Btn7L]) {
			if(!pressed) {
				motorSwitch *= -1;
			}
			pressed = true;
			} else {
			pressed = false;
		}
		if(vexRT[Btn7R]) {
			if(!pressed) {
				autoSwitch *= -1;
			}
			pressed = true;
			} else {
			pressed = false;
		}
		//if(autoSwitch) {
		//	autoStack();
		//}
		motor(fRbR) = (vexRT[Ch3] * motorSwitch) + vexRT[Ch4];
		motor(fLbL) = (vexRT[Ch3] * motorSwitch) - vexRT[Ch4];

		motor(lift) = (126 * vexRT[Btn6U]) - (126 * vexRT[Btn6D]);
		motor(chainArm) = (126 * vexRT[Btn8U]) - (126 * vexRT[Btn8D]);
		motor(bottomLeft) = -vexRT[Ch2];
		motor(bottomRight) = -vexRT[Ch2];

		motor(topRight) = -vexRT[Ch2];
		motor(topLeft) = -vexRT[Ch2];

		motor(intake) = 50;
		//(126 * vexRT[Btn7L]) - (126 * vexRT[Btn7R]);

	}
}
