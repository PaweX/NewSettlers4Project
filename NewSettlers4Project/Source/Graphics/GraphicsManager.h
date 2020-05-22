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

#ifndef H_GRAPHICS_MANAGER
#define H_GRAPHICS_MANAGER

#include "sharedefs.h"


class CGameApplication;
class CRenderingMediator;

///////////////////////////////////////////////////////////////////////////////////////////////////
// DESCRIPTION: This class stands between the main game class and other graphics classes. They are
// dependent of this class.
// ------------
// EXTRA INFO: Constructor throws an exception of type 'ExceptionNr' when the instance already exists.
// Method GetInstance() throws an exception of type 'ExceptionNr' when the object is not existing.
// The only one instance of this class is created and deleted by CGameApplication.
///////////////////////////////////////////////////////////////////////////////////////////////////
//// SINGLETON CLASS ////
class CGraphicsManager
{
	// Friend classes
	friend class CRenderingMediator;

private: // Fields
	static CGraphicsManager* instance; // The instance

		// dependent singletons
	static CRenderingMediator* renderingMediator; // The instance of CRenderingMediator

private: // Methods 
	// Friends:
	friend CGameApplication::CGameApplication();
	friend CGameApplication::~CGameApplication();

	CGraphicsManager(); // Constructor
	~CGraphicsManager(); // Destructor
	
public: // Methods
	//static CGraphicsManager* GetInstance();

};


#endif // H_GRAPHICS_MANAGER