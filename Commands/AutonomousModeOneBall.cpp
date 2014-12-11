#include "AutonomousModeOneBall.h"
#include "LoadCatapultGroup.h"
#include "Commands/WaitCommand.h"
#include "OperatorLowCommand.h"
#include "OperatorHighCommand.h"
#include "OperatorPickup1Command.h"
#include "OperatorPickup2Command.h"
#include "AutonomousPickupCommand.h"
#include "AutonomousDriveCommand.h"
#include "AutonomousCoastCommand.h"
#include "AutonomousLowGearCommand.h"
#include "DriveLaunchReleaseCommand.h"
#include "../Timing.h"

AutonomousModeOneBall::AutonomousModeOneBall()
{
  AddSequential(new AutonomousDriveCommand(1.0f, TURN_CORRECTION, 2.2));// straight line
  AddSequential(new AutonomousDriveCommand(0f, TURN_CORRECTION, 0));//stop
  Wait 1; //wait 1 second
  AddSequential(new AutonomousDriveCommand(1.0f, 1.0f, 2.2));// turn
  AddSequential(new AutonomousDriveCommand(1.0f, TURN_CORRECTION, 2.2));//straight
  AddSequential(new AutonomousDriveCommand(0, TURN_CORRECTION, 0));//stop
  Wait 1;//wait 1 second
  AddSequential(new AutonomousDriveCommand(1.0f, -1.0f, 2.2));//turn other direction
  AddSequential(new AutonomousDriveCommand(1.0f, TURN_CORRECTION, 2.2));//straight
  AddSequential(new AutonomousDriveCommand(0, TURN_CORRECTION, 0));//stop
  wait 1;//wait 1 second
}
