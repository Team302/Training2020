
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

#pragma once

//========================================================================================================
/// @interface IMech
/// @brief     This is the interface for mechanisms regardless of what control items are available.
//========================================================================================================

// C++ Includes
#include <memory>
#include <string>

// FRC includes

// Team 302 includes
#include <subsys/MechanismTypes.h>

// Third Party Includes

class IMech1Solenoid;
class IMech1Servo;

///	 @interface IMech
///  @brief	    Interface for subsystems
class IMech
{
	public:

        enum MechComponents
        {
	    SINGLE_IND_MOTOR,
            TWO_IND_MOTORS,
            SINGLE_IND_MOTOR_WITH_SOLENOID,
            TWO_IND_MOTORS_WITH_SOLENOID,
            SINGLE_IND_MOTOR_WITH_SERVO,
            TWO_IND_MOTORS_WITH_SERVO,
            SINGLE_IND_MOTOR_WITH_SOLENOID_AND_SERVO,
            TWO_IND_MOTORS_WITH_SOLENOID_AND_SERVO
        };

        /// @brief          Indicates the type of mechanism this is
        /// @return         MechanismTypes::MECHANISM_TYPE
        virtual MechanismTypes::MECHANISM_TYPE GetType() const = 0;

        /// @brief indicate the file used to get the control parameters from
        /// @return std::string the name of the file 
        virtual std::string GetControlFileName() const = 0;

        /// @brief indicate the Network Table name used to setting tracking parameters
        /// @return std::string the name of the network table 
        virtual std::string GetNetworkTableName() const = 0;
        
	    IMech() = default;
	    virtual ~IMech() = default;

        /// @brief indicate what type of components this mechanism has
        /// @return MechComponents basic mechansim definition
        virtual MechComponents GetMechComponents() const = 0;

        /// @brief Add a solenoid to this mechanism 
        virtual void SetSolenoid
        (
            std::unique_ptr<IMech1Solenoid>     solenoidMech
        ) = 0;

        /// @brief Add a servo to this mechanism
        virtual void SetServo
        (
            std::unique_ptr<IMech1Servo>        servoMech
        ) = 0;

        /// @brief update the output to the mechanism using the current controller and target value(s)
        /// @return void 
        virtual void Update() = 0;
};



