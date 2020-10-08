//====================================================================================================================================================
// Copyright 2020 Lake Orion Robotics FIRST Team 302 
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
// OR OTHER DEALINGS IN THE SOFTWARE.
//====================================================================================================================================================

<<<<<<< master
=======

>>>>>>> Creates new Subsystems
// C++ Includes
#include <memory>
#include <string>

// FRC includes

<<<<<<< master

// Team 302 includes
=======
//Team 302 Includes
>>>>>>> Creates new Subsystems
#include <subsys/BallTransfer.h>
#include <subsys/Mech1IndMotor.h>
#include <subsys/MechanismTypes.h>

<<<<<<< master

// Third Party Includes
=======
//Third Party Includes
>>>>>>> Creates new Subsystems


using namespace std;


<<<<<<< master
/// @brief Create the BallTransfer mechanism
/// @param [in] shared_ptr<IDragonMotorController> the motor controller that will run the ball transfer
BallTransfer::BallTransfer
(
    shared_ptr<IDragonMotorController>     motorController
) : Mech1IndMotor( MechanismTypes::MECHANISM_TYPE::BALL_TRANSFER, 
                   string("balltransfer.xml"),
                   string("balltransferNT") ,
                   motorController )
{
}
=======
/// @brief Creates the BallTransfer mechanism
/// @param [in] IDragonMotorController* the motor controller that will run the ball transfer  
BallTransfer::BallTransfer
(
    shared_ptr<IDragonMotorController>     motorController
) : Mech1IndMotor( MechanismTypes::MECHANISM_TYPE::BALL_TRANSFER,
                    string("balltransfer.xml"),
                    string("balltransferNT"),
                    motorController )
{
    
}
    
>>>>>>> Creates new Subsystems
