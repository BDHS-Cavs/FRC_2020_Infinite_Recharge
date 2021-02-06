/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// Cavalier Includes
#include "Subsystems/Shooter.h"

// FRC Includes
#include <frc/smartdashboard/SmartDashboard.h>

void Shooter::OnRobotInit() {
    m_shooterLeft.SetInverted(true);
}

//  Passes set speed to shooter Spark Max
void Shooter::Periodic(bool rawButtonShoot) {
   if (rawButtonShoot)
   {
       m_shooterLeft.Set(0.75);
       m_shooterRight.Set(0.75);
   }
   else
   {
       m_shooterLeft.StopMotor();
       m_shooterRight.StopMotor();
   }

    frc::SmartDashboard::PutNumber("Shooter Left Motor Speed", m_shooterLeft.Get());
    frc::SmartDashboard::PutNumber("Shooter Right Motor Speed", m_shooterRight.Get());
}