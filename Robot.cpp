// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

//CODE WRITTED BY RAYAN.B
#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom1, kAutoNameCustom1);
  m_chooser.AddOption(kAutoNameCustom2, kAutoNameCustom2);
  m_chooser.AddOption(kAutoNameCustom3, kAutoNameCustom3);
  m_chooser.AddOption(kAutoNameCustom4, kAutoNameCustom4);
  m_chooser.AddOption(kAutoNameCustom5, kAutoNameCustom5);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}


void Robot::RobotPeriodic() {

frc::SmartDashboard::PutNumber("ia: ", ia); 
frc::SmartDashboard::PutNumber("it: ", it); 

frc::SmartDashboard::PutBoolean("LB : ", leftbump); 
frc::SmartDashboard::PutBoolean("RB : ", rightbump);

frc::SmartDashboard::PutBoolean("bA :", bA);
frc::SmartDashboard::PutBoolean("bB :", bB);
frc::SmartDashboard::PutBoolean("bX :", bX);
frc::SmartDashboard::PutBoolean("bY :", bY);

frc::SmartDashboard::PutNumber("left x : ", left_x);
frc::SmartDashboard::PutNumber("left y : ", left_x);
frc::SmartDashboard::PutNumber("right x : ", right_x);
frc::SmartDashboard::PutNumber("right y : ", right_y);
}


void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom1) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }

 ia =0;
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom1) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }

  
  
   ia++;
}

void Robot::TeleopInit() {
  it = 0;
  
  }

void Robot::TeleopPeriodic() { 
  it++;

  leftbump = xbox.GetBumper(frc::GenericHID::kLeftHand);
  rightbump = xbox.GetBumper(frc::GenericHID::kRightHand);

  bA = xbox.GetAButton();
  bB = xbox.GetBButton();
  bX = xbox.GetXButton();
  bY = xbox.GetYButton();
  
  left_x = xbox.GetX(frc::GenericHID::kLeftHand);
  left_y = xbox.GetY(frc::GenericHID::kLeftHand);

  right_x = xbox.GetX(frc::GenericHID::kRightHand);
  right_y = xbox.GetY(frc::GenericHID::kRightHand);
  }

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
