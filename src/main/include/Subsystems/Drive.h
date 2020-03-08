/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

// FRC includes
#include <frc/drive/MecanumDrive.h>
#include <frc/Spark.h>

class Drive {

private:
  // Constants
  static constexpr int kFrontLeftChannel  = 2;
  static constexpr int kRearLeftChannel   = 0;
  static constexpr int kFrontRightChannel = 3;
  static constexpr int kRearRightChannel  = 1;

  // Members
  frc::Spark m_leftFront{kFrontLeftChannel};
  frc::Spark m_leftRear{kRearLeftChannel};
  frc::Spark m_rightFront{kFrontRightChannel};
  frc::Spark m_rightRear{kRearRightChannel};
  frc::MecanumDrive m_robotDrive{m_leftFront, m_leftRear, m_rightFront,
                                 m_rightRear};
public:

  // Functions
	void Periodic(double ySpeed, double xSpeed, double zRotation);
};