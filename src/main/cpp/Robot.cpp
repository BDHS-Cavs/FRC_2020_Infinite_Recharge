/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// Cavalier Includes
#include "Robot.h"

void Robot::RobotInit() {
   m_joystick1.SetTwistChannel(kTwistAxis);
   m_gyro.Calibrate();
}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
	m_drive.Periodic(m_joystick1.GetY(), m_joystick1.GetX(), m_joystick1.GetTwist(), m_gyro.GetAngle());
   // TODO: Need to write ability to move elevator and intake both in and out
   m_elevator.Periodic(m_joystick2.GetRawButton(3));
   m_intake.Periodic(m_joystick2.GetRawButton(0));
   m_colorSensor.Periodic();

   // Shooter control from joystick 2
   if (m_joystick2.GetRawButton(5))
   {
      m_shooter.Periodic(0.75);
   }
   else
   {
      m_shooter.Periodic(0.0);
   }
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
