/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// Cavalier Includes
#include "Subsystems/Intake.h"

// FRC Includes
#include <frc/smartdashboard/SmartDashboard.h>

//  Passes joysick values to the intake Sparks 
void Intake::Periodic(bool rawButton1, bool rawButton3) {
    // Spin the Intake in or out
    if (rawButton1)
    {
        m_intakeMotor.Set(1.0);
    }
    else if (rawButton3)
    {
        m_intakeMotor.Set(-1.0);
    }
    else
    {
        m_intakeMotor.Set(0.0);
    };

    frc::SmartDashboard::PutNumber("Intake Motor Speed", m_intakeMotor.Get());
}
