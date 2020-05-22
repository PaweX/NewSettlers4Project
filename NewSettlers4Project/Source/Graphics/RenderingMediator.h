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

#ifndef H_RENDERING_MEDIATOR
#define H_RENDERING_MEDIATOR

#include "sharedefs.h"


class CGraphicsManager;
class CBaseRenderingAPI;

///////////////////////////////////////////////////////////////////////////////////////////////////
// DESCRIPTION: This class is translating common rendering functions to a loaded API. It stands
// between program and loaded API. It is responsible for talking to an API that is currently
// loaded. Before this class the program is not bothered and doesn't know which API is used.
// ------------
// EXTRA INFO: Constructor throws an exception of type 'ExceptionNr' when the instance already exists.
// Method GetInstance() throws an exception of type 'ExceptionNr' when the object is not existing.
// The only one instance of this class is created and deleted by CGraphicsManager.
///////////////////////////////////////////////////////////////////////////////////////////////////
//// SINGLETON CLASS ////
class CRenderingMediator
{
private: // Fields
	static CRenderingMediator* instance; // The instance

	// dependent singletons
	static CBaseRenderingAPI* renderingAPI; // The instance of the current Rendering API class

private: // Methods 
	// Friends:
	friend CGraphicsManager::CGraphicsManager();
	friend CGraphicsManager::~CGraphicsManager();

	CRenderingMediator(); // Constructor
	~CRenderingMediator(); // Destructor

	
	void CreateRenderingAPI(API_Type apiType = API_CURRENT_API);
	void RemoveRenderingAPI();

public: // Methods
	//static CRenderingMediator* GetInstance();

	void ChangeRenderingAPI(API_Type apiType); // Removes current API and creates new one
};


#endif // H_RENDERING_MEDIATOR