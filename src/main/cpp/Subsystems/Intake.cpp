/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// Cavalier Includes
#include "Subsystems/Intake.h"


void Intake::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

//  Passes joysick values to the intake spark
void Intake::Periodic(bool rawButton0, bool rawButton2) {
    if (rawButton0)
    {
        m_intakeMotor.SetSpeed(0.75);
    }
    else
    {
        m_intakeMotor.SetSpeed(-0.75);
    };
}


