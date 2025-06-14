/*
** Developer : Don Dang
** Date      : 06/13/25
** Class     : C++ Intermediate
** Assignment: Hunt the Wumpus: Assignment 4
** Due Date  : 06/20/25
** Subject   : C++ STL Functions
** Purpose   :
    - Adding a user interface: a console application that accepts user inputs and calls into the game to make moves.
    - Need to add printouts of the text expected when different events happen in the game.
    - A new class, UserNotification, needs to be added.
    - Define a set of possible events with an enumeration, and then support registering callback functions for when those events trigger.
      See the specification for the set of events
    - Insert triggering the events at appropriate pints in the code. E.g. when the Hunters enters the cave, report the caves connected, and report the neighboring caves,
      or when the bat picks up the Hunter.

** Unit Test :
    - Verify that the appropriate registered callback is triggered for a game operation.
    - The provided code is untested (you are given Assignment 3 Solution with some small modifications, which don't even compile for thi code).

   

** Note      :
    - When this assignment is complete, you should be able to play Hunt the Wumpus by entering "move <cave number>" 
      or "shoot<cave number> <cave number> <cave number>" (for arrow flight paths).
      

** Date        Developer     Activities
   06/13/25    Don D         Start working on unit test
*/


#include "TestHarness.h"

int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);

    return 0;
}
