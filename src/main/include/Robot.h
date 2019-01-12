/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include "ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h"
#include <frc/SpeedControllerGroup.h>
#include <frc/Drive/DifferentialDrive.h>
#include <frc/XboxController.h>
#include <frc/Spark.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  ctre::phoenix::motorcontrol::can::WPI_TalonSRX m_left1 {1};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX m_left2 {2};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX m_right1 {3};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX m_right2 {4};

  frc::SpeedControllerGroup m_left { m_left1, m_left2 };
  frc::SpeedControllerGroup m_right { m_right1, m_right2 };

  frc::DifferentialDrive m_tankDrive { m_left, m_right };

  frc::XboxController m_driverJoystick {0};

  frc::Spark m_climbLeft {0};
  frc::Spark m_climbRight {1};
};
