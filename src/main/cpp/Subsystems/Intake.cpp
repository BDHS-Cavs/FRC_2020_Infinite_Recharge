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

void Intake::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

//  Passes joysick values to the intake Sparks 
void Intake::Periodic(bool rawButton1, bool rawButton3, bool rawButton2, bool rawButton4) {
    // Spin the Intake in or out
    if (rawButton1)
    {
        m_intakeMotor.Set(1.0);

        std::cout << " Intake Motor Speed" << m_intakeMotor.Get() << "\n";
    }
    else if (rawButton3)
    {
        m_intakeMotor.Set(-1.0);
    }
    else
    {
        m_intakeMotor.Set(0.0);
    };

    // Raise and lower the Intake bar
    if (rawButton2)
    {
        m_intakeRaiseLower.Set(0.3);

        std::cout << " Intake Raise Speed" << m_intakeRaiseLower.Get() << "\n";
    }
    else if (rawButton4)
    {
        m_intakeRaiseLower.Set(-0.3);

        std::cout << " Intake Lower Speed" << m_intakeRaiseLower.Get() << "\n";
    }
    else
    {
        m_intakeRaiseLower.Set(0.0);
    };

    frc::SmartDashboard::PutNumber("Intake Motor Speed", m_intakeMotor.Get());
}
