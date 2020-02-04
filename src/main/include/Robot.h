/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "frc/TimedRobot.h"
#include "frc/livewindow/LiveWindow.h"
#include "frc/smartdashboard/SendableChooser.h"

#include "Subsystems/Drive.h"

class Robot : public frc::TimedRobot {
 public:
   frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
   Drive drive;
   void RobotInit() override;

   void AutonomousInit() override;
   void AutonomousPeriodic() override;

   void TeleopInit() override;
   void TeleopPeriodic() override;
};
