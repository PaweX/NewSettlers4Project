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
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//  _____                                           _ _           _   _                                    
// / ____|                        /\               | (_)         | | (_)                                   
//| |  __  __ _ _ __ ___   ___   /  \   _ __  _ __ | |_  ___ __ _| |_ _  ___  _ __         ___ _ __  _ __  
//| | |_ |/ _` | '_ ` _ \ / _ \ / /\ \ | '_ \| '_ \| | |/ __/ _` | __| |/ _ \| '_ \       / __| '_ \| '_ \ 
//| |__| | (_| | | | | | |  __// ____ \| |_) | |_) | | | (_| (_| | |_| | (_) | | | |  _  | (__| |_) | |_) |
// \_____|\__,_|_| |_| |_|\___/_/    \_\ .__/| .__/|_|_|\___\__,_|\__|_|\___/|_| |_| (_)  \___| .__/| .__/ 
//                                     | |   | |                                              | |   | |    
//                                     |_|   |_|                                              |_|   |_|    
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Messages.h"
#include "GameApplication.h"
#include "GameSettings.h"
#include "GraphicsManager.h"


//----------------------------------------------------------------
CGameApplication* CGameApplication::instance = nullptr;
CGameSettings* CGameApplication::gameSettings = nullptr;
CGraphicsManager* CGameApplication::graphicsManager = nullptr;


//----------------------------------------------------------------
// CONSTRUCTOR
//----------------------------------------------------------------
CGameApplication::CGameApplication()
{
	// Check if the instance is null and save it.
	if (instance != nullptr)
		throw except_GAME_APP_ALREADY_EXISTS;
	else
		instance = this;


	// Try to create dependent objects
	try
	{
		// Create Game Settings - MUST BE FIRST!
		if (gameSettings != nullptr) // Check if the instance is null
			throw except_GAME_SETTINGS_ALREADY_EXISTS;
		else
			gameSettings = new CGameSettings();


		// Create Graphics Manager
		graphicsManager = new CGraphicsManager();
	}
	catch (ExceptionNr exc)
	{
		// Display exception error message
		MESSAGE::Exception(exc, __FILENAME__);
	}
}
//----------------------------------------------------------------

//----------------------------------------------------------------
// DESTRUCTOR
//----------------------------------------------------------------
CGameApplication::~CGameApplication()
{
	// Remove Graphics Manager
	if (graphicsManager != nullptr)
		delete graphicsManager;

	// Save Game Settings to the file and remove the instance
	if (gameSettings != nullptr)
	{
		gameSettings->SaveSettingsToTheFile();
		delete gameSettings;
	}


	// At the end clear pointer of this instance
	instance = nullptr;
}
//----------------------------------------------------------------


//----------------------------------------------------------------
// Public Methods
//----------------------------------------------------------------

// GetInstance method
CGameApplication* CGameApplication::GetInstance()
{
	if (instance == nullptr)
		throw except_GAME_APP_NOT_CREATED;
	else
		return CGameApplication::instance;
}
//----------------------------------------------------------------

// Get instance of CGameSettings. Throws exception of type 'ExceptionNr' if the instance is not existing.
CGameSettings* CGameApplication::GetGameSettings() const
{
	if (gameSettings == nullptr)
		throw except_GAME_SETTINGS_NOT_CREATED;
	else
		return gameSettings;
}
//----------------------------------------------------------------


// Start and Run method
void CGameApplication::StartAndRun()
{

}
//----------------------------------------------------------------