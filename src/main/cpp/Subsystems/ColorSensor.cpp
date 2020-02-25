/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// Cavalier Includes
#include "Subsystems/ColorSensor.h"

// FRC Includes
#include <frc/smartdashboard/smartdashboard.h>


void ColorSensor::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

//  Passes set speed to shooter Spark Max
void ColorSensor::Periodic() {
    frc::Color detectedColor = m_colorSensor.GetColor();

    // Display color as RGB value
    frc::SmartDashboard::PutNumber("Red", detectedColor.red);
    frc::SmartDashboard::PutNumber("Green", detectedColor.green);
    frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
}