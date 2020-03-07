/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

// Cavalier Includes
#include "Subsystems/Shooter.h"


void Shooter::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

//  Passes set speed to shooter Spark Max
void Shooter::Periodic(bool rawButtonShoot) {
   if (rawButtonShoot)
   {
       m_shooter.Set(0.75);
   }
   else
   {
       m_shooter.StopMotor();
   }
}