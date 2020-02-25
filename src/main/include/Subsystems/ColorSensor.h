/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

// Rev Robotics includes
#include <rev/ColorSensorV3.h>

class ColorSensor {

private:
  // Constants
  static constexpr auto kI2cPort = frc::I2C::Port::kOnboard;

  // Members
  rev::ColorSensorV3 m_colorSensor{kI2cPort};
 public:
 
   // Functions
   void InitDefaultCommand();
   void Periodic();
};