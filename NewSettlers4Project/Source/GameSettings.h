#pragma once
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

#ifndef H_GAME_SETTINGS
#define H_GAME_SETTINGS

#include "sharedefs.h"


#define GAME_SETTINGS_FILE "Config/GameSettings.cfg"

/////////////////////////////////////////////////////////////////////////////////
//  _____                       _____      _   _   _                       _     
// / ____|                     / ____|    | | | | (_)                     | |    
//| |  __  __ _ _ __ ___   ___| (___   ___| |_| |_ _ _ __   __ _ ___      | |__  
//| | |_ |/ _` | '_ ` _ \ / _ \\___ \ / _ \ __| __| | '_ \ / _` / __|     | '_ \ 
//| |__| | (_| | | | | | |  __/____) |  __/ |_| |_| | | | | (_| \__ \  _  | | | |
// \_____|\__,_|_| |_| |_|\___|_____/ \___|\__|\__|_|_| |_|\__, |___/ (_) |_| |_|
//                                                          __/ |                
//                                                         |___/                 
/////////////////////////////////////////////////////////////////////////////////
// DESCRIPTION: This is a class containing all settings of the game (graphics, keys etc.).
// ------------
// EXTRA INFO: Constructor throws an exception of type 'ExceptionNr' when the instance already exists.
// Method GetInstance() throws an exception of type 'ExceptionNr' when the object is not existing.
// The only one instance of all inheriting classes is created and deleted by CGameApplication.
///////////////////////////////////////////////////////////////////////////////////////////////////
//// SINGLETON CLASS - managed by CGameApplication ////
class CGameSettings
{
	// Friends:
	friend class CGameApplication;


private: // Fields

	//// GRAPHICS SETTINGS ////
	struct GraphicsSettings
	{
		API_Type currentAPI = API_OpenGl;

		struct Resolution
		{
			unsigned width = 0; // window width
			unsigned height = 0; // window height

			void operator()(unsigned w, unsigned h) { width = w; height = h; }
		};
		Resolution resolution; // Window resolution

#ifdef _DEBUG
		bool isFullScreen = false;
#else
		bool isFullScreen = true;
#endif
	};

	//// SOUND SETTINGS ////
	struct SoundSettings
	{

	};

	//// UI SETTINGS ////
	struct UISettings // keyboard, mouse etc.
	{

	};

	//// COMMON SETTINGS ////
	struct CommonSettings // common game settings, basically everything else
	{

	};


private: // Methods 
	CGameSettings(); // Constructor
	~CGameSettings(); // Destructor

	void LoadSettingsFromTheFile() const; // Loads settings from the game settings file - if it exists
	void SaveSettingsToTheFile(); // Save settings to the game settings file


public: // Fields
	GraphicsSettings graphics;
	SoundSettings sound;
	UISettings UI; // keyboard, mouse etc.
	CommonSettings common; // common game settings, basically everything else


public: // Methods

};


#endif // H_GAME_SETTINGS