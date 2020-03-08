/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

// FRC includes
#include <frc/PWMSparkMax.h>

class Shooter {

private:
  // Constants
  static constexpr int kLauncherLeft  = 8; // left
  static constexpr int kLauncherRight = 9; // right

  // Members
  frc::PWMSparkMax m_shooterLeft{kLauncherLeft};
  frc::PWMSparkMax m_shooterRight{kLauncherRight};

 public:
   //Functions
   void InitDefaultCommand();
   void Periodic(bool rawButtonShoot);
};