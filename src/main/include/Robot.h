/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

// FRC includes
#include <frc/ADXRS450_Gyro.h>
#include <frc/Joystick.h>
#include <frc/TimedRobot.h>

// Cavalier includes
#include "Subsystems/Drive.h"

class Robot : public frc::TimedRobot {
 public:
   void RobotInit() override;

   void AutonomousInit() override;
   void AutonomousPeriodic() override;

   void TeleopInit() override;
   void TeleopPeriodic() override;

 private:
   static constexpr int kJoystickPort = 0;

   // Twist is on Axis 3 for the Extreme 3D Pro
   // Count starts at 0, so we use #2
   static constexpr int kTwistAxis = 2;

   frc::Joystick m_joystick{kJoystickPort};
   frc::ADXRS450_Gyro m_gyro;
   Drive m_drive;
};
