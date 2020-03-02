/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// Cavalier Includes
#include "Subsystems/Drive.h"

// FRC Includes
#include <frc/smartdashboard/SmartDashboard.h>

void Drive::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

void Drive::Periodic(double ySpeed, double xSpeed, double zRotation, double gyroAngle) {
    m_robotDrive.DriveCartesian(ySpeed, xSpeed, zRotation, gyroAngle);

    frc::SmartDashboard::PutNumber("Gyro Angle", gyroAngle);
}

