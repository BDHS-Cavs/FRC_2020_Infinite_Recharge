/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

// FRC includes
#include <rev/CANSparkMax.h>

class Shooter {

private:
  // Constants
  static constexpr int kLauncherLeft  = 2; // left
  static constexpr int kLauncherRight = 1; // right

  // Members
  rev::CANSparkMax m_shooterLeft{kLauncherLeft, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_shooterRight{kLauncherRight, rev::CANSparkMax::MotorType::kBrushless};

 public:

   //Functions
   void Periodic(bool rawButtonShoot);
   void OnRobotInit();
};