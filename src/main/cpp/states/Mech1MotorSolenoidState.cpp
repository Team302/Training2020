
//====================================================================================================================================================
/// Copyright 2020 Lake Orion Robotics FIRST Team 302 
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
/// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
/// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
/// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
/// OR OTHER DEALINGS IN THE SOFTWARE.
//====================================================================================================================================================

// C++ Includes
#include <memory>
#include <utility>

// FRC includes

// Team 302 includes
#include <states/IState.h>
#include <states/Mech1MotorSolenoidState.h>
#include <states/Mech1MotorState.h>
#include <states/MechSolenoidState.h>
#include <controllers/ControlData.h>
#include <controllers/MechanismTargetData.h>
#include <subsys/IMech1IndMotor.h>
#include <utils/Logger.h>

#include <gamepad/TeleopControl.h>

// Third Party Includes

using namespace std;

/// @class Mech1MotorSolenoidState
/// @brief information about the control (open loop, closed loop position, closed loop velocity, etc.) for a mechanism state
Mech1MotorSolenoidState::Mech1MotorSolenoidState
(
    std::shared_ptr<IMech1IndMotor>             motorMech,
    std::shared_ptr<IMech1Solenoid>             solenoidMech,    
    ControlData*                                control,
    double                                      target,
    MechanismTargetData::SOLENOID               solState
) : IState(),
    m_motor( make_shared<Mech1MotorState>(motorMech, control, target)),
    m_solenoid(make_shared<MechSolenoidState>(solenoidMech, solState))
{    
}

void Mech1MotorSolenoidState::Init()
{
    if ( m_motor.get() != nullptr )
    {
        m_motor.get()->Init();
    }
    if ( m_solenoid.get() != nullptr )
    {
        m_solenoid.get()->Init();
    }
}


void Mech1MotorSolenoidState::Run()           
{
    if ( m_motor.get() != nullptr )
    {
        m_motor.get()->Run();
    }
    if ( m_solenoid.get() != nullptr )
    {
        m_solenoid.get()->Run();
    }
}

bool Mech1MotorSolenoidState::AtTarget() const
{
    return m_motor.get() != nullptr ? m_motor.get()->AtTarget() : true;
}

