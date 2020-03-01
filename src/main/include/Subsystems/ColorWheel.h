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
#include <rev/ColorSensorV3.h>

class ColorWheel {

private:
  // Constants
  static constexpr auto kI2cPort = frc::I2C::Port::kOnboard;
  static constexpr int kspinnerArmPort   = 5;
  static constexpr int kspinnerWheelPort = 8;

  // Members
  frc::Spark m_spinnerArm{kspinnerArmPort};
  frc::Spark m_spinnerWheel{kspinnerWheelPort};
  rev::ColorSensorV3 m_colorSensor{kI2cPort};
public:

  // Functions
	void Periodic(bool rawButtonArm, bool rawButtonInverted);
	void ProcessArm(bool rawButtonArm, bool rawButtonInverted);
	void ProcessSensor();
};