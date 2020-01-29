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
#include <map>
#include <memory>

// FRC includes

// Team 302 includes
#include <controllers/IState.h>
#include <controllers/impeller/ImpellerStateMgr.h>
#include <xmlmechdata/StateDataDefn.h>
#include <controllers/MechanismTargetData.h>
#include <utils/Logger.h>
#include <gamepad/TeleopControl.h>
#include <controllers/impeller/ImpellerOff.h>
#include <controllers/impeller/ImpellerOn.h>
#include <controllers/impeller/ImpellerAgitate.h>


// Third Party Includes

using namespace std;

/// @brief    initialize the state manager, parse the configuration file and create the states.
ImpellerStateMgr::ImpellerStateMgr() : m_stateMap(),
                                       m_currentState()
{
    // Parse the configuration file 
    auto stateXML = make_unique<StateDataDefn>();
    vector<MechanismTargetData*> targetData = stateXML.get()->ParseXML( MechanismTypes::MECHANISM_TYPE::IMPELLER );

    // initialize the xml string to state map
    map<string, IMPELLER_STATE> stateMap;
    stateMap["IMPELLEROFF"] = IMPELLER_STATE::OFF;
    stateMap["IMPELLERON"]  = IMPELLER_STATE::ON;
    stateMap["IMPELLERAGITATE"] = IMPELLER_STATE::AGITATE;

    // create the states passing the configuration data
    for ( auto td: targetData )
    {
        auto stateString = td->GetStateString();
        auto stateItr = stateMap.find( stateString );
        if ( stateItr != stateMap.end() )
        {
            auto stateEnum = stateItr->second;
            auto stateIt = m_stateMap.find( stateEnum );
            if ( stateIt == m_stateMap.end() )
            {
                auto controlData = td->GetController();
                auto target = td->GetTarget();

                switch ( stateEnum )
                {
                    case IMPELLER_STATE::ON:
                    {   // todo update the constructor take in controlData and target
                        auto thisState = new ImpellerOn();
                        m_stateMap[IMPELLER_STATE::ON] = thisState;
                        m_currentState = thisState;
                        m_currentStateEnum = stateEnum;
                        m_currentState->Init();
                    }
                    break;

                    case IMPELLER_STATE::OFF:
                    {   // todo update the constructor take in controlData and target
                        auto thisState = new ImpellerOff();
                        m_stateMap[IMPELLER_STATE::OFF] = thisState;
                    }
                    break;

                    case IMPELLER_STATE::AGITATE:
                    {   // todo update the constructor take in controlData and target
                        auto thisState = new ImpellerAgitate();
                        m_stateMap[IMPELLER_STATE::AGITATE] = thisState;
                    }
                    break;

                    default:
                    {
                        Logger::GetLogger()->LogError( string("ImpellerStateMgr::ImpellerStateMgr"), string("unknown state"));
                    }
                    break;
                }
            }
            Logger::GetLogger()->LogError( string("ImpellerStateMgr::ImpellerStateMgr"), string("multiple mechanism state info for state"));
        }
        else
        {
            Logger::GetLogger()->LogError( string("ImpellerStateMgr::ImpellerStateMgr"), string("state not found"));
        }
    }
}

/// @brief  run the current state
/// @return void
void ImpellerStateMgr::RunCurrentState()
{
    // process teleop/manual interrupts
    auto controller = TeleopControl::GetInstance();
    if ( controller != nullptr )
    {
        if ( controller->IsButtonPressed( TeleopControl::FUNCTION_IDENTIFIER::IMPELLER_SPIN ) && 
             m_currentStateEnum != IMPELLER_STATE::ON )
        {
            SetCurrentState( IMPELLER_STATE::ON, false );
        }
        else if ( controller->IsButtonPressed( TeleopControl::FUNCTION_IDENTIFIER::IMPELLER_STOP ) &&
                  m_currentStateEnum != IMPELLER_STATE::OFF )
        {
            SetCurrentState( IMPELLER_STATE::OFF, false );
        }
        else if ( controller->IsButtonPressed( TeleopControl::FUNCTION_IDENTIFIER::IMPELLER_AGITATE ) &&
                  m_currentStateEnum != IMPELLER_STATE::AGITATE )
        {
            SetCurrentState( IMPELLER_STATE::AGITATE, false );
        }
    }

    // run the current state
    if ( m_currentState != nullptr )
    {
        m_currentState->Run();
    }

}

/// @brief  set the current state, initialize it and run it
/// @return void
void ImpellerStateMgr::SetCurrentState
(
    IMPELLER_STATE  stateEnum,
    bool            run
)
{
    auto itr = m_stateMap.find( stateEnum );
    if ( itr != m_stateMap.end() )
    {
        auto state = itr->second;
        if ( state != m_currentState )
        {
            m_currentState = state;
            m_currentStateEnum = stateEnum;
            m_currentState->Init();
            if ( run )
            {
                m_currentState->Run();
            }
        }
    }
}

