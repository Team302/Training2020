
//====================================================================================================================================================
/// Copyright 2019 Lake Orion Robotics FIRST Team 302
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

//========================================================================================================
/// MechanismFactory.h
//========================================================================================================
///
/// File Description:
///     This controls the creation of mechanisms/subsystems
///
//========================================================================================================

#pragma once

// C++ Includes
#include <map>
#include <memory>

// FRC includes

// Team 302 includes
#include <subsys/IMechanism.h>
#include <subsys/MechanismTypes.h>
#include <hw/interfaces/IDragonMotorController.h>
#include <hw/usages/IDragonMotorControllerMap.h>
#include <hw/usages/AnalogInputMap.h>
#include <hw/usages/DigitalInputMap.h>
#include <hw/usages/DragonSolenoidMap.h>
#include <hw/usages/ServoMap.h>
#include <hw/DragonSolenoid.h>
#include <hw/DragonServo.h>
#include <hw/DragonAnalogInput.h>
#include <hw/DragonDigitalInput.h>
#include <subsys/Intake.h>
#include <subsys/HumanPlayerFlap.h>
#include <subsys/BallTransfer.h>
#include <subsys/ControlPanel.h>
#include <rev/ColorSensorV3.h>
#include <subsys/ShooterHood.h>



// Third Party Includes


class MechanismFactory
{
	public:

		static MechanismFactory* GetMechanismFactory();


		//=====================================================================================
		/// Method:         GetIMechanism
		/// Description:    Find or create the requested mechanism
		/// Returns:        IMechanism*     pointer to the mechanism or nullptr if mechanism 
		///                                 doesn't exist and cannot be created.
		//=====================================================================================
		IMechanism* GetIMechanism
		(
			MechanismTypes::MECHANISM_TYPE			type		// <I> - manipulator type
		);

		//=====================================================================================
		/// Method:         CreateIMechanism
		/// Description:    Find or create the requested mechanism
		/// Returns:        IMechanism*     pointer to the mechanism or nullptr if mechanism 
		///                                 doesn't exist and cannot be created.
		//=====================================================================================
		IMechanism*  CreateIMechanism
		(
			MechanismTypes::MECHANISM_TYPE			type,
			const IDragonMotorControllerMap&        motorControllers,   // <I> - Motor Controllers
			const DragonSolenoidMap&                solenoids,
			const ServoMap&						    servos,
			const DigitalInputMap&					digitalInputs,
			const AnalogInputMap&                   analogInputs,
			rev::ColorSensorV3*                     colorSensor
		);

	private:
		std::shared_ptr<IDragonMotorController> GetMotorController
		(
			const IDragonMotorControllerMap&				motorControllers,
			MotorControllerUsage::MOTOR_CONTROLLER_USAGE	usage
		);
		std::shared_ptr<DragonSolenoid> GetSolenoid
		(
			const DragonSolenoidMap&						solenoids,
			SolenoidUsage::SOLENOID_USAGE					usage
		);
		std::shared_ptr<DragonServo> GetServo
		(
			const ServoMap&									servos,
			ServoUsage::SERVO_USAGE							usage
		);
		std::shared_ptr<DragonDigitalInput> GetDigitalInput
		(
			const DigitalInputMap&							digitaInputs,
			DigitalInputUsage::DIGITAL_SENSOR_USAGE			usage
		);
		std::shared_ptr<DragonAnalogInput> GetAnalogInput
		(
			const AnalogInputMap&							analogInputs,
			AnalogInputUsage::ANALOG_SENSOR_USAGE			usage
		);

		MechanismFactory() = default;
		virtual ~MechanismFactory() = default;

		static MechanismFactory*	m_mechanismFactory;

		std::map<MechanismTypes::MECHANISM_TYPE, IMechanism*> m_mechanisms;

};