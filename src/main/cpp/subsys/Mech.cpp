//====================================================================================================================================================
// Copyright 2019 Lake Orion Robotics FIRST Team 302
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

// C++ Includes
#include <string>

// FRC includes

// Team 302 includes
#include <subsys/Mech.h>
#include <subsys/MechanismTypes.h>
#include <utils/Logger.h>
// Third Party Includes


using namespace std;

/// @brief create the general mechanism
/// @param [in] MechanismTypes::MECHANISM_TYPE the type of mechansim
/// @param [in] std::string the name of the file that will set control parameters for this mechanism
/// @param [in] std::string the name of the network table for logging information
/// @param [in] IMech::MechType components defining the mechanism
Mech::Mech
(
    MechanismTypes::MECHANISM_TYPE  type,
    std::string                     controlFileName,
    std::string                     networkTableName,
    IMech::MechComponents           components
) : IMech(), 
    m_type( type ),
    m_controlFile( controlFileName ),
    m_ntName( networkTableName ),
    m_components( components )
{
    if ( controlFileName.empty() )
    {
        Logger::GetLogger()->LogError( string( "Mech" ), string( "control file name is not specified" ) );
    }

    if ( networkTableName.empty() )
    {
        Logger::GetLogger()->LogError( string( "Mech" ), string( "network table name is not specified" ) );
    }

}


/// @brief          Indicates the type of mechanism this is
/// @return         MechanismTypes::MECHANISM_TYPE
MechanismTypes::MECHANISM_TYPE Mech::GetType() const 
{
    return m_type;
}

/// @brief indicate the file used to get the control parameters from
/// @return std::string the name of the file 
std::string Mech::GetControlFileName() const 
{
    return m_controlFile;
}


/// @brief indicate the network table name used to for logging parameters
/// @return std::string the name of the network table 
std::string Mech::GetNetworkTableName() const 
{
    return m_ntName;
}

/// @brief indicate what type of components this mechanism has
/// @return MechComponents basic mechansim definition
IMech::MechComponents Mech::GetMechComponents() const
{
    return m_components;
}


/// @brief indicate that this mechanism has a solenoid
void Mech::SetHasSolenoid()
{
    switch (m_components)
    {
        case IMech::MechComponents::SINGLE_IND_MOTOR:
            m_components = IMech::MechComponents::SINGLE_IND_MOTOR_WITH_SOLENOID;
            break;
        case IMech::MechComponents::SINGLE_IND_MOTOR_WITH_SERVO:
            m_components  = IMech::MechComponents::SINGLE_IND_MOTOR_WITH_SOLENOID_AND_SERVO;
            break;
        case IMech::MechComponents::TWO_IND_MOTORS:
            m_components = IMech::MechComponents::TWO_IND_MOTORS_WITH_SOLENOID;
            break;
        case IMech::MechComponents::TWO_IND_MOTORS_WITH_SERVO:
            m_components = IMech::MechComponents::TWO_IND_MOTORS_WITH_SOLENOID_AND_SERVO;
            break;
        default:
            Logger::GetLogger()->LogError( string( "Mech" ), string( "Invalid option found in SetHasSolenoid" ) );
            break;
    }
}

/// @brief indicate that this mechanism has a servo
void Mech::SetHasServo() 
{
    switch (m_components)
    {
        case IMech::MechComponents::SINGLE_IND_MOTOR:
            m_components = IMech::MechComponents::SINGLE_IND_MOTOR_WITH_SERVO;
            break;
        case IMech::MechComponents::SINGLE_IND_MOTOR_WITH_SOLENOID:
            m_components  = IMech::MechComponents::SINGLE_IND_MOTOR_WITH_SOLENOID_AND_SERVO;
            break;
        case IMech::MechComponents::TWO_IND_MOTORS:
            m_components = IMech::MechComponents::TWO_IND_MOTORS_WITH_SERVO;
            break;
        case IMech::MechComponents::TWO_IND_MOTORS_WITH_SOLENOID:
            m_components = IMech::MechComponents::TWO_IND_MOTORS_WITH_SOLENOID_AND_SERVO;
            break;
        default:
            Logger::GetLogger()->LogError( string( "Mech" ), string( "Invalid option found in SetHasServo" ) );
            break;
    }
}

void Mech::Update()
{

}

