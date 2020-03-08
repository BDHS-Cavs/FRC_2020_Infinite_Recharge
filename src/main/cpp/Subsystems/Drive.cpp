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

void Drive::Periodic(double ySpeed, double xSpeed, double zRotation) {
    // This SHOULD NOT HAVE TO BE DONE!!
    // Every document and API says we should feed the DriveCartesian function as follows:
    //
    // m_robotDrive.DriveCartesian(ySpeed, xSpeed, zRotation, gyroAngle);
    // 
    // but our bot does not respond that way.  We have done the following:
    // reversed the Y and X inputs into the function
    // "flipped" the Y so it's inputs are inverted
    // added a dead zone to the Z so it is less touchy

    double flippedY = (ySpeed * -1.0);
    double z;
    double deadZone = 0.25;

    if (fabs(zRotation) < deadZone)
    {
        z = 0.0;
    }
    else
    {
        z = zRotation;
    };

    m_robotDrive.DriveCartesian(xSpeed, flippedY, z);
}

