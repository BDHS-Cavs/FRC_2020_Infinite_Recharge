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
#include <frc/DriverStation.h>

// Standard Library Includes
#include "math.h"

void ColorWheel::OnRobotInit() {
    m_colorMatcher.AddColorMatch(kBlueTarget);
    m_colorMatcher.AddColorMatch(kGreenTarget);
    m_colorMatcher.AddColorMatch(kRedTarget);
    m_colorMatcher.AddColorMatch(kYellowTarget);
}

void ColorWheel::Periodic(bool rawButtonArm, bool rawButtonInverted, bool rawButtonStartSpinning) {
   this->ProcessArm(rawButtonArm,rawButtonInverted);
   this->UpdateToggle(rawButtonStartSpinning);
   this->ProcessSensor();
}

void ColorWheel::ProcessArm(bool rawButtonArm, bool rawButtonInverted) {
    if (rawButtonArm)
    {
        m_spinnerArm.SetInverted(false);
        m_spinnerArm.Set(0.5);
    }
    else if (rawButtonInverted)
    {
        m_spinnerArm.SetInverted(true);
        m_spinnerArm.Set(0.5);
    }
    else
    {
        m_spinnerArm.SetInverted(false);
        m_spinnerArm.Set(0.0);
    }

    // Display Spinner Arm Speed
    frc::SmartDashboard::PutNumber(kSpinArmSpeed, m_spinnerArm.Get());
}

void ColorWheel::ProcessSensor() {
    // Set up for Smart Dashboard display & Processing
    double confidence = 0.0;
    std::string colorString;
    uint32_t proximity       = m_colorSensor.GetProximity();
    frc::Color detectedColor = m_colorSensor.GetColor();
    frc::Color matchedColor  = m_colorMatcher.MatchClosestColor(detectedColor, confidence);

    // Display color as "normalized" value
    frc::SmartDashboard::PutNumber(kRedColor, detectedColor.red);
    frc::SmartDashboard::PutNumber(kGreenColor, detectedColor.green);
    frc::SmartDashboard::PutNumber(kBlueColor, detectedColor.blue);
    frc::SmartDashboard::PutNumber(kColorConfidence, confidence);

    // Display "Detected Color"
    frc::SmartDashboard::PutString(kDetectedColor, colorString);

    // Display proximity
    frc::SmartDashboard::PutNumber(kProximity, proximity);

    // Display color count
    frc::SmartDashboard::PutNumber(kColorsCounted, m_colorCount);

    // Display matched color 
    frc::SmartDashboard::PutString(kMatchedColor, ColorName(matchedColor));

    // Display spin "enabled"
    frc::SmartDashboard::PutBoolean(kTogglePressed, m_togglePressed);

    this->Spin();

    if (m_countColors)
    {
        // process spinning specific number of times 
        if(m_colorCount < 0)
        {
            m_colorCount = 0;
        }

        if (m_lastColor == m_countedColor && !(m_lastColor == matchedColor))
        {
            m_colorCount++;
        }
        m_lastColor = matchedColor;

        // stop after about 3 1/2 revolution (2 color counts per revolution)
        if (m_colorCount >= 7)
        {
            m_togglePressed = false;
        }
    }

    if (!(m_spinToColor == kBlack))
    {
        // process spinning to specific color
        if (m_spinToColor == matchedColor)
        {
            m_spinToColor = kBlack;
            this->SetSpinWheelMotorSpeed(0);
        }
        else
        {
            this->SetSpinWheelMotorSpeed(m_spinSpeed * 0.5);
        }
    }

    // when counting is disabled reset counter
    if (!m_countColors && m_colorCount >= 0)
    {
        m_colorCount = -1;
        m_lastColor = kBlack;
    }

    this->SetTargetColorFromGameData();
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

void ColorWheel::Spin()
{
    if (m_togglePressed)
    {
        SetSpinWheelMotorSpeed(1.0);
        m_countColors = true;
    }
    else
    {
        SetSpinWheelMotorSpeed(0.0);
        m_countColors = false;
    }

    // Display Spinner Wheel Speed
    frc::SmartDashboard::PutNumber(kSpinWheelSpeed, m_spinnerWheel.Get());
}

void ColorWheel::SpinToColor()
{
    this->SetTargetColorFromGameData();

    if (m_gameDataTargetColor == kBlack)
    {
        // Exit out
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
    m_gameDataTargetColor = GetColorFromName(frc::DriverStation::GetInstance().GetGameSpecificMessage());
    std::string colorName;
    m_gameDataTargetColor = GetColorFromName(colorName);
    frc::SmartDashboard::PutString(kGameDataColor, ColorName(m_gameDataTargetColor));
}

void ColorWheel::UpdateToggle(bool rawButtonStartSpinning)
{
    if (rawButtonStartSpinning)
    {
        if (!m_togglePressed)
        {
            m_togglePressed = true;
        }
        else
        {
            m_togglePressed = false;
        }
    }
}