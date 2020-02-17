/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

// FRC includes
#include <frc/Spark.h>

class Elevator {
private:
  static constexpr int kLiftMech = 6;
 
  frc::Spark m_liftMotor{kLiftMech};
public:

	void InitDefaultCommand();
	void Periodic(double rawButton);
};