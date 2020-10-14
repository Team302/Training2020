
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

// C++ includes

// FRC includes

// Team302 includes
#include <subsys/IMech.h>

// Third Party includes
#include <pugixml/pugixml.hpp>


/// @class MechansimDefn
/// @brief Create a mechaism from an XML definition
class MechanismDefn
{
    public:
        MechanismDefn() = default;
        virtual ~MechanismDefn() = default;

    	/// @brief  Parse the mechanism element (and it children).  When this is done the mechanism exists 
        ///         that can be retrieved from the factory.
    	/// @return IMech*  pointer to the mechanism or nullptr if there is an error
        IMech* ParseXML
        (
            pugi::xml_node      mechanismNode
        );
};

