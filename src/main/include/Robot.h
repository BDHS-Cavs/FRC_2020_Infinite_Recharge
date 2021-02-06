/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

// Cavalier Includes
#include "Subsystems/ColorWheel.h"
#include "Subsystems/Drive.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Shooter.h"

// FRC Includes
#include <frc/ADXRS450_Gyro.h>
#include <frc/Joystick.h>
#include <frc/TimedRobot.h>

class Robot : public frc::TimedRobot {

 public:
   // Functions
   void RobotInit() override;
   void AutonomousInit() override;
   void AutonomousPeriodic() override;
   void TeleopInit() override;
   void TeleopPeriodic() override;

 private:
   // Constants
   static constexpr int kJoystickPort1 = 0;
   static constexpr int kJoystickPort2 = 1;

   // Twist is on Axis 3 for the Extreme 3D Pro
   // Count starts at 0, so we use #2
   static constexpr int kTwistAxis = 2;

   // Members
   frc::Joystick m_joystick1{kJoystickPort1};
   frc::Joystick m_joystick2{kJoystickPort2};
   //frc::ADXRS450_Gyro m_gyro;
   Drive m_drive;
   Elevator m_elevator;
   Intake m_intake;
   Shooter m_shooter;
   ColorWheel m_colorWheel;
};
