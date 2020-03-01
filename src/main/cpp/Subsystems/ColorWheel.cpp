/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// Cavalier Includes
#include "Subsystems/ColorWheel.h"

// FRC Includes
#include <frc/smartdashboard/smartdashboard.h>

// std Includes
#include "math.h"

void ColorWheel::Periodic(bool rawButtonArm, bool rawButtonInverted) {
   this->ProcessArm(rawButtonArm,rawButtonInverted);
   this->ProcessSensor();
}

void ColorWheel::ProcessArm(bool rawButtonArm, bool rawButtonInverted) {
    if (rawButtonArm)
    {
        m_spinnerArm.SetInverted(false);
        m_spinnerArm.SetSpeed(0.5);
    }
    else if (rawButtonInverted)
    {
        m_spinnerArm.SetInverted(true);
        m_spinnerArm.SetSpeed(0.4);
    }
    else
    {
        m_spinnerArm.SetInverted(false);
        m_spinnerArm.SetSpeed(0.0);
    }
}

void ColorWheel::ProcessSensor() {
    frc::Color detectedColor = m_colorSensor.GetColor();

    // Display color as RGB value
    frc::SmartDashboard::PutNumber("Red", (nearbyint(detectedColor.red * 255)));
    frc::SmartDashboard::PutNumber("Green", (nearbyint(detectedColor.green * 255)));
    frc::SmartDashboard::PutNumber("Blue", (nearbyint(detectedColor.blue * 255)));
}
