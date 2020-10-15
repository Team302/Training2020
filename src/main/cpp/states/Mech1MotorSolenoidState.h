
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

#pragma once

#include <memory>

#include <states/Mech1MotorState.h>
#include <states/MechSolenoidState.h>
#include <states/IState.h>

class IMech1IndMotor;
class IMech1Solenoid;
class ControlData;


class Mech1MotorSolenoidState : public IState
{
    public:

        Mech1MotorSolenoidState
        (
            std::shared_ptr<IMech1IndMotor>             motorMech,
            std::shared_ptr<IMech1Solenoid>             solenoidMech,
            ControlData*                                control,
            double                                      target,
            MechanismTargetData::SOLENOID               solState
        );
        Mech1MotorSolenoidState() = delete;
        ~Mech1MotorSolenoidState() = default;

        void Init() override;
        void Run() override;
        bool AtTarget() const override;

    private:

        std::shared_ptr<Mech1MotorState>                    m_motor;
        std::shared_ptr<MechSolenoidState>                  m_solenoid;

};