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
   this->ProcessSensor(rawButtonStartSpinning);
}

void ColorWheel::ProcessArm(bool rawButtonArm, bool rawButtonInverted) {
    if (rawButtonArm)
    {
        m_spinnerArm.SetInverted(false);
        m_spinnerArm.Set(0.5);
        std::cout << " Spinner Arm Raise Speed" << m_spinnerArm.Get() << "\n";
    }
    else if (rawButtonInverted)
    {
        m_spinnerArm.SetInverted(true);
        m_spinnerArm.Set(0.5);
        std::cout << " Spinner Arm Lower Speed" << m_spinnerArm.Get() << "\n";
    }
    else
    {
        m_spinnerArm.SetInverted(false);
        m_spinnerArm.Set(0.0);
    }
}

void ColorWheel::ProcessSensor(bool startSpinning) {
    double confidence = 0.0;
    std::string colorString;
    frc::Color detectedColor = m_colorSensor.GetColor();
    //frc::Color matchedColor  = m_colorMatcher.MatchClosestColor(detectedColor, confidence);
    uint32_t proximity       = m_colorSensor.GetProximity();

    // Display color as "normalized" value
    frc::SmartDashboard::PutNumber(kRedColor, detectedColor.red);
    frc::SmartDashboard::PutNumber(kGreenColor, detectedColor.green);
    frc::SmartDashboard::PutNumber(kBlueColor, detectedColor.blue);
    frc::SmartDashboard::PutNumber(kColorConfidence, confidence);

    // Display "Detected Color"
    frc::SmartDashboard::PutString("Detected Color", colorString);

    // Display proximity
    frc::SmartDashboard::PutNumber("Proximity", proximity);

    // Start to process 
    this->UpdateColorSensorValues(startSpinning); 
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

void ColorWheel::Spin(bool startSpinning)
{
    m_countColors = startSpinning;
    if (startSpinning)
    {
        SetSpinWheelMotorSpeed(1.0);
        std::cout << " Spinner Wheel Spin Speed" << m_spinnerWheel.Get() << "\n";
    }
    else
    {
        SetSpinWheelMotorSpeed(0.0);
    }
}

void ColorWheel::SpinToColor()
{
    // TODO: Why is this called twice?
    // Once in SpinToColor()
    // Again in UpdateColorSensorValues()
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

void ColorWheel::UpdateColorSensorValues(bool startSpinning)
{
    frc::Color detectedColor = m_colorSensor.GetColor();
    double confidence = 0.0;
    frc::Color matchedColor = m_colorMatcher.MatchClosestColor(detectedColor, confidence);

    this->Spin(startSpinning);

    if (m_countColors)
    {
        std::cout << "m_colorCount is " << m_colorCount << " \n";
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
            this->Spin(false);
        }
    }

    //if (!(m_spinToColor == kBlack))
    //{
    //    // process spinning to specific color
    //    if (m_spinToColor == matchedColor)
    //    {
    //        m_spinToColor = kBlack;
    //        this->SetSpinWheelMotorSpeed(0);
    //    }
    //    else
    //    {
    //        this->SetSpinWheelMotorSpeed(m_spinSpeed * 0.5);
    //    }
    //}

    //// when counting is disabled reset counter
    //if (!m_countColors && m_colorCount >= 0)
    //{
    //    m_colorCount = -1;
    //    m_lastColor = kBlack;
    //}

    frc::SmartDashboard::PutString(kDetectedColor, ColorName(matchedColor));
    frc::SmartDashboard::PutNumber(kColorsCounted, m_colorCount);

    m_debugEnable = frc::SmartDashboard::GetBoolean(kDebug, false);

    if(m_debugEnable)
    {
        m_countColors = frc::SmartDashboard::GetBoolean(kCountColors, false);
        m_countedColor = GetColorFromName(
            frc::SmartDashboard::GetString(kColorToCount, ColorName(m_countedColor)));

        m_spinSpeed = frc::SmartDashboard::GetNumber(kSpinSpeed, kSpinSpeedDefault);
    }

    // TODO: Why is this called twice?
    // Once in SpinToColor()
    // Again in UpdateColorSensorValues()
    this->SetTargetColorFromGameData();
}