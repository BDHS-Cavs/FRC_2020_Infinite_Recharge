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
  const double kSpinSpeedDefault = 0.5;

  static constexpr frc::Color kBlack        = frc::Color(0, 0, 0);
  static constexpr frc::Color kBlueTarget   = frc::Color(0.143, 0.427, 0.429);
  static constexpr frc::Color kGreenTarget  = frc::Color(0.197, 0.561, 0.240);
  static constexpr frc::Color kRedTarget    = frc::Color(0.561, 0.232, 0.114);
  static constexpr frc::Color kYellowTarget = frc::Color(0.361, 0.524, 0.113);

  // Members
  rev::ColorSensorV3 m_colorSensor{kI2cPort};
  rev::ColorMatch    m_colorMatcher;
  frc::Spark         m_spinnerArm{kspinnerArmPort};
  frc::Spark         m_spinnerWheel{kspinnerWheelPort};
  frc::Color         m_countedColor = kGreenTarget;
  frc::Color         m_spinToColor = kBlack;
  frc::Color         m_gameDataTargetColor = kBlack;
  frc::Color         m_lastColor = kBlack;
  bool               m_countColors = false;
  bool               m_debugEnable = false;
  int                m_colorCount = -1;
  double             m_spinSpeed = kSpinSpeedDefault;

  // Smart Dashboard
  const std::string kCW = "CW/";
  const std::string kDebug = kCW + "Debug";
  const std::string kCountColors = kCW + "Count Colors";
  const std::string kColorToCount = kCW + "Color To Count";
  const std::string kColorsCounted = kCW + "Colors Counted";
  const std::string kDetectedColor = kCW + "Detected Color";
  const std::string kGameDataColor = kCW + "Game Data Color";
  const std::string kRedColor = kCW + "Red Color";
  const std::string kGreenColor = kCW + "Green Color";
  const std::string kBlueColor = kCW + "Blue Color";
  const std::string kColorConfidence = kCW + "Color Confidence";
  const std::string kSpinSpeed = kCW + "Spin Speed";

public:

  // Functions
  std::string ColorName(frc::Color matchedColor) const;
  frc::Color GetColorFromName(std::string colorName) const;
  bool IsSpinning() const;
  void OnRobotInit();
	void Periodic(bool rawButtonArm, bool rawButtonInverted);
	void ProcessArm(bool rawButtonArm, bool rawButtonInverted);
	void ProcessSensor();
  void SetSpinWheelMotorSpeed(double speed);
  void SetTargetColorFromGameData();
  void Spin(bool start);
  void SpinToColor();
  void UpdateColorSensorValues();
};