/////////////////////////////////////////////////////////////////
//////////////////// New Settlers IV Project ////////////////////
/////////////////////////////////////////////////////////////////
/*******************************************************************************
* Copyright (c) 2020 Pawe³ Czapliñski
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
*******************************************************************************/
////////////////////////////////////////////////////////////////////////////////////////////
//  _____                       _____      _   _   _                                        
// / ____|                     / ____|    | | | | (_)                                       
//| |  __  __ _ _ __ ___   ___| (___   ___| |_| |_ _ _ __   __ _ ___        ___ _ __  _ __  
//| | |_ |/ _` | '_ ` _ \ / _ \\___ \ / _ \ __| __| | '_ \ / _` / __|      / __| '_ \| '_ \ 
//| |__| | (_| | | | | | |  __/____) |  __/ |_| |_| | | | | (_| \__ \  _  | (__| |_) | |_) |
// \_____|\__,_|_| |_| |_|\___|_____/ \___|\__|\__|_|_| |_|\__, |___/ (_)  \___| .__/| .__/ 
//                                                          __/ |              | |   | |    
//                                                         |___/               |_|   |_|    
////////////////////////////////////////////////////////////////////////////////////////////

#include "Messages.h"
#include "GameSettings.h"

//----------------------------------------------------------------


//----------------------------------------------------------------
// CONSTRUCTOR
//----------------------------------------------------------------
CGameSettings::CGameSettings()
{
	// INFO: Checking if the instance is null is done in CGameApplication

	// Load settings - must be last
	LoadSettingsFromTheFile();
}
//----------------------------------------------------------------

//----------------------------------------------------------------
// DESTRUCTOR
//----------------------------------------------------------------
CGameSettings::~CGameSettings()
{
}
//----------------------------------------------------------------


//----------------------------------------------------------------
// Private Methods
//----------------------------------------------------------------


// Loads settings from the game settings file - if it exists
void CGameSettings::LoadSettingsFromTheFile() const
{
	
}
//----------------------------------------------------------------

// Saves settings to the game settings file
void CGameSettings::SaveSettingsToTheFile()
{

}
//----------------------------------------------------------------


//----------------------------------------------------------------
// Public Methods
//----------------------------------------------------------------



//----------------------------------------------------------------