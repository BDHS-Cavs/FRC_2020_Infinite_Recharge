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
  static constexpr int kLauncher = 9;

  // Members
  frc::PWMSparkMax m_shooter{kLauncher};

 public:
   //Functions
   void InitDefaultCommand();
   void Periodic(double speedInput);
};