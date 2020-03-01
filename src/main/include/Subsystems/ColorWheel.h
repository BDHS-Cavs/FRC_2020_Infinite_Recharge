/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

// FRC includes
#include <frc/Spark.h>

// Rev Robotics includes
#include <rev/ColorMatch.h>
#include <rev/ColorSensorV3.h>

class ColorWheel {

private:
  // Constants
  static constexpr auto kI2cPort = frc::I2C::Port::kOnboard;
  static constexpr int kspinnerArmPort   = 5;
  static constexpr int kspinnerWheelPort = 8;

  static constexpr frc::Color kBlueTarget   = frc::Color(0.143, 0.427, 0.429);
  static constexpr frc::Color kGreenTarget  = frc::Color(0.197, 0.561, 0.240);
  static constexpr frc::Color kRedTarget    = frc::Color(0.561, 0.232, 0.114);
  static constexpr frc::Color kYellowTarget = frc::Color(0.361, 0.524, 0.113);

  // Members
  frc::Spark m_spinnerArm{kspinnerArmPort};
  frc::Spark m_spinnerWheel{kspinnerWheelPort};
  rev::ColorSensorV3 m_colorSensor{kI2cPort};
  rev::ColorMatch m_colorMatcher;

public:

  // Functions
  void OnRobotInit();
	void Periodic(bool rawButtonArm, bool rawButtonInverted);
	void ProcessArm(bool rawButtonArm, bool rawButtonInverted);
	void ProcessSensor();
};