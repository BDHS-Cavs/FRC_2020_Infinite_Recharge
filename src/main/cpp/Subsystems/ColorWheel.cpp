/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// Cavalier Includes
#include "Subsystems/ColorWheel.h"

// FRC Includes
#include <frc/smartdashboard/SmartDashboard.h>

// Standard Library Includes
#include "math.h"

void ColorWheel::OnRobotInit() {
    m_colorMatcher.AddColorMatch(kBlueTarget);
    m_colorMatcher.AddColorMatch(kGreenTarget);
    m_colorMatcher.AddColorMatch(kRedTarget);
    m_colorMatcher.AddColorMatch(kYellowTarget);
}

void ColorWheel::Periodic(bool rawButtonArm, bool rawButtonInverted) {
   this->ProcessArm(rawButtonArm,rawButtonInverted);
   this->ProcessSensor();
}

void ColorWheel::ProcessArm(bool rawButtonArm, bool rawButtonInverted) {
    if (rawButtonArm)
    {
        m_spinnerArm.SetInverted(false);
        m_spinnerArm.SetSpeed(0.3);
    }
    else if (rawButtonInverted)
    {
        m_spinnerArm.SetInverted(true);
        m_spinnerArm.SetSpeed(0.2);
    }
    else
    {
        m_spinnerArm.SetInverted(false);
        m_spinnerArm.SetSpeed(0.0);
    }
}

void ColorWheel::ProcessSensor() {
    double confidence = 0.0;
    std::string colorString;
    frc::Color detectedColor = m_colorSensor.GetColor();
    frc::Color matchedColor  = m_colorMatcher.MatchClosestColor(detectedColor, confidence);
    uint32_t proximity       = m_colorSensor.GetProximity();

    if (matchedColor == kBlueTarget) {
      colorString = "Blue";
    } else if (matchedColor == kRedTarget) {
      colorString = "Red";
    } else if (matchedColor == kGreenTarget) {
      colorString = "Green";
    } else if (matchedColor == kYellowTarget) {
      colorString = "Yellow";
    } else {
      colorString = "Unknown";
    }

    // Display color as "normalized" value
    frc::SmartDashboard::PutNumber("Red", detectedColor.red);
    frc::SmartDashboard::PutNumber("Green", detectedColor.green);
    frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
    frc::SmartDashboard::PutNumber("Confidence", confidence);

    // Display "Detected Color"
    frc::SmartDashboard::PutString("Detected Color", colorString);

    // Display proximity
    frc::SmartDashboard::PutNumber("Proximity", proximity);
}

std::string ColorWheel::ColorName(frc::Color matchedColor) const
{
    if (matchedColor == kBlueTarget)
        return "Blue";
    if (matchedColor == kGreenTarget)
        return "Green";
    if (matchedColor == kRedTarget)
        return "Red";
    if (matchedColor == kYellowTarget)
        return "Yellow";
    if (matchedColor == kBlack)
        return "Black";

    return "Unknown";
}

frc::Color ColorWheel::GetColorFromName(std::string colorName) const
{
    if(colorName.length() > 0)
    {
        switch (toupper(colorName[0]))
        {
        case 'B':
            return kBlueTarget;
        case 'G':
            return kGreenTarget;
        case 'R':
            return kRedTarget;
        case 'Y':
            return kYellowTarget;
        }
    }
    
    return kBlack;
}

bool ColorWheel::IsSpinning() const
{
    return m_colorCount >= 0 || !(m_spinToColor == kBlack);
}

void ColorWheel::SetSpinWheelMotorSpeed(double speed)
{
    m_spinnerWheel.Set(speed);
}

void ColorWheel::Spin(bool start)
{
    m_countColors = start;
    if (start)
    {
        SetSpinWheelMotorSpeed(0.5);
    }
    else
    {
        SetSpinWheelMotorSpeed(0.0);
    }
}

void ColorWheel::SpinToColor()
{
    SetTargetColorFromGameData();

    if (m_gameDataTargetColor == kBlack)
    {
        return;
    }

    if (m_gameDataTargetColor == kBlueTarget)
    {
        m_spinToColor = kRedTarget;
    }
    else if (m_gameDataTargetColor == kRedTarget)
    {
        m_spinToColor = kBlueTarget;
    }
    else if (m_gameDataTargetColor == kGreenTarget)
    {
        m_spinToColor = kYellowTarget;
    }
    else if (m_gameDataTargetColor == kYellowTarget)
    {
        m_spinToColor = kGreenTarget;
    }
}

void ColorWheel::SetTargetColorFromGameData()
{
    // ToDo: How to get this message?
    //m_gameDataTargetColor = GetColorFromName(frc::DriverStation::GetInstance().GetGameSpecificMessage());
    std::string colorName;
    m_gameDataTargetColor = GetColorFromName(colorName);
    frc::SmartDashboard::PutString(kGameDataColor, ColorName(m_gameDataTargetColor));
}