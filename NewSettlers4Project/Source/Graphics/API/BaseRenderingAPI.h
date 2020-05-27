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

#ifndef H_BASE_RENDERING_API
#define H_BASE_RENDERING_API

#include "sharedefs.h"


///////////////////////////////////////////////////////////////////////////////////////////////////
// DESCRIPTION: This is a base class of all rendering APIs classes. But this class doesn't create
// any objects (it is PURE VIRTUAL). It is managed by the Rendering Mediator.
// ------------
// EXTRA INFO: Constructor throws an exception of type 'ExceptionNr' when the instance already exists.
// Method GetInstance() throws an exception of type 'ExceptionNr' when the object is not existing.
// The only one instance of all inheriting classes is created and deleted by CRenderingMediator.
///////////////////////////////////////////////////////////////////////////////////////////////////
//// SINGLETON CLASS - but only from inheriting classes ////
//// ONLY ONE OBJECT OF ALL INHERITING CLASSES IS ALLOWED AT ONE TIME ////
class IBaseRenderingAPI
{
	// Friends:
	friend class CRenderingMediator;

protected: // Fields
	static IBaseRenderingAPI* instance; // The only one instance considering all inheriting classes.

	CRenderingMediator* renderingMed; // The Rendering Mediator singleton

	API_Type API_type = API_CURRENT_API;

protected: // Methods 
	IBaseRenderingAPI(); // Constructor
	virtual ~IBaseRenderingAPI() { instance = nullptr; } // Destructor
	
public: // Methods
	static IBaseRenderingAPI* GetInstance();

	API_Type GetAPI_Type() const { return API_type; }

};


#endif // H_BASE_RENDERING_API