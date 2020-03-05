/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// Cavalier Includes
#include "Subsystems/Elevator.h"

// FRC Includes
#include <frc/smartdashboard/SmartDashboard.h>

void Elevator::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    //SetDefaultCommand(new MySpecialCommand());
}

//  Passes joysick values to the elevator spark
void Elevator::Periodic(bool rawButton1, bool rawButton3) {
    if (rawButton1)
    {
        m_liftMotor.Set(0.5);

        std::cout << " Elevator Forward Motor Speed" << m_liftMotor.Get() << "\n";
    }
    else if (rawButton3)
    {
        m_liftMotor.Set(-0.5);

        std::cout << " Elevator Backward Motor Speed" << m_liftMotor.Get() << "\n";
    }
    else
    {
        m_liftMotor.Set(0.0);
    };

    frc::SmartDashboard::PutNumber("Elevator Motor Speed", m_liftMotor.Get());
}

