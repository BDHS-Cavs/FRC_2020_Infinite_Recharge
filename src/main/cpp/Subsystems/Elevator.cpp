/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// Cavalier Includes
#include "Subsystems/Elevator.h"


void Elevator::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

//  Passes joysick values to the elevator spark
void Elevator::Periodic(bool rawButton0, bool rawbutton2) {
    if (rawButton0)
    {
        m_liftMotor.SetSpeed(1.0);
    }
    else
    {
        m_liftMotor.SetSpeed(-1.0);
    };
}

