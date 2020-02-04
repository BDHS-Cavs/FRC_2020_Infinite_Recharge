/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

// FRC includes
#include <frc/drive/MecanumDrive.h>
#include <frc/PWMVictorSPX.h>

class Drive {
private:
  static constexpr int kFrontLeftChannel  = 0;
  static constexpr int kRearLeftChannel   = 1;
  static constexpr int kFrontRightChannel = 2;
  static constexpr int kRearRightChannel  = 3;

  frc::PWMVictorSPX m_leftFront{kFrontLeftChannel};
  frc::PWMVictorSPX m_leftRear{kRearLeftChannel};
  frc::PWMVictorSPX m_rightFront{kFrontRightChannel};
  frc::PWMVictorSPX m_rightRear{kRearRightChannel};
  frc::MecanumDrive m_robotDrive{m_leftFront, m_leftRear, m_rightFront,
                                 m_rightRear};
public:

	void InitDefaultCommand();
	void Periodic();
};