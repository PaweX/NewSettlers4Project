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

#ifndef H_GAME_APPLICATION
#define H_GAME_APPLICATION

#include "sharedefs.h"


class CGameSettings;
class CGraphicsManager;

////////////////////////////////////////////////////////////////////////////////////////////////
//  _____                                           _ _           _   _                   _     
// / ____|                        /\               | (_)         | | (_)                 | |    
//| |  __  __ _ _ __ ___   ___   /  \   _ __  _ __ | |_  ___ __ _| |_ _  ___  _ __       | |__  
//| | |_ |/ _` | '_ ` _ \ / _ \ / /\ \ | '_ \| '_ \| | |/ __/ _` | __| |/ _ \| '_ \      | '_ \ 
//| |__| | (_| | | | | | |  __// ____ \| |_) | |_) | | | (_| (_| | |_| | (_) | | | |  _  | | | |
// \_____|\__,_|_| |_| |_|\___/_/    \_\ .__/| .__/|_|_|\___\__,_|\__|_|\___/|_| |_| (_) |_| |_|
//                                     | |   | |                                                
//                                     |_|   |_|                                                
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
// DESCRIPTION: It is a main game class. It rules the whole game (Graphics, Logic etc.).
// ------------
// EXTRA INFO: Constructor throws an exception of type 'ExceptionNr' when the instance already exists.
// Method GetInstance() throws an exception of type 'ExceptionNr' when the object is not existing
///////////////////////////////////////////////////////////////////////////////////////////////////
//// SINGLETON CLASS ////
class CGameApplication
{
private: // Fields
	static CGameApplication* instance; // The instance of this class

	// dependent singletons
	static CGameSettings* gameSettings; // The instance of CGameSettings
	static CGraphicsManager* graphicsManager; // The instance of CGraphicsManager

private: // Methods 

public: // Methods
	CGameApplication(); // Constructor
	~CGameApplication(); // Destructor

	static CGameApplication* GetInstance();
	
	CGameSettings* GetGameSettings() const;

	void StartAndRun();
};


#endif // H_GAME_APPLICATION