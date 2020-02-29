/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

// FRC includes
#include <frc/Spark.h>

class Spinner {

private:
  // Constants
  static constexpr int kspinnerArmPort   = 5;
  static constexpr int kspinnerWheelPort = 8;

  // Members
  frc::Spark m_spinnerArm{kspinnerArmPort};
  frc::Spark m_spinnerWheel{kspinnerWheelPort};

public:

  // Functions
  void InitDefaultCommand();
	void Periodic(bool rawButtonArm, bool rawButtonInverted);
};