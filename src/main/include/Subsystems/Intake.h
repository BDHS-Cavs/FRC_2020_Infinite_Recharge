/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

// FRC includes
#include <frc/Spark.h>

class Intake {

private:
  // Constants
  static constexpr int kBeaterBar  = 7;
  static constexpr int kRaiseLower = 8;

  // Members
  frc::Spark m_intakeMotor{kBeaterBar};
  frc::Spark m_intakeRaiseLower{kRaiseLower};

public:

  // Functions
  void InitDefaultCommand();
	void Periodic(bool rawButton1, bool rawButton3, bool rawButton2, bool rawButton4);
};