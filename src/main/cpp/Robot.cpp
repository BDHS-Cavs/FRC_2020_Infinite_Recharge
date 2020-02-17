/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

void Robot::RobotInit() {
   m_joystick.SetTwistChannel(kTwistAxis);
   m_gyro.Calibrate();
}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
}

void Robot::TeleopPeriodic() {
	m_drive.Periodic(m_joystick.GetY(), m_joystick.GetX(), m_joystick.GetTwist(), m_gyro.GetAngle());
   m_elevator.Periodic(m_joystick.GetRawButton(2));
   m_intake.Periodic(m_joystick.GetRawButton(2));
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
