/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// Cavalier Includes
#include "Subsystems/Spinner.h"


void Spinner::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

void Spinner::Periodic(bool rawButtonArm, bool rawButtonInverted) { 
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