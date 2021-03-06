/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// Cavalier Includes
#include "Robot.h"

void Robot::RobotInit() {
   m_colorWheel.OnRobotInit();
   m_shooter.OnRobotInit();
   m_joystick1.SetTwistChannel(kTwistAxis);
}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
   // Joystick 1 = Drive, Joystick 2 = Non-Drive Controls
   m_colorWheel.Periodic(m_joystick2.GetRawButton(7), m_joystick2.GetRawButton(8), m_joystick2.GetRawButtonPressed(9));
	m_drive.Periodic(m_joystick1.GetY(), m_joystick1.GetX(), m_joystick1.GetTwist());
   m_elevator.Periodic(m_joystick2.GetRawButton(1), m_joystick2.GetRawButton(3));
   m_intake.Periodic(m_joystick2.GetRawButton(1), m_joystick2.GetRawButton(3));
   m_shooter.Periodic(m_joystick2.GetRawButton(5));
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
