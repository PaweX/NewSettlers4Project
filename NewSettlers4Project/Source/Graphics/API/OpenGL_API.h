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

#ifndef H_OPENGL_API
#define H_OPENGL_API

#include "sharedefs.h"


class IBaseRenderingAPI;

///////////////////////////////////////////////////////////////////////////////////////////////////
// DESCRIPTION: Class for OpenGL API, it translates rendering functions for OpenGL.
// ------------
// EXTRA INFO: See CBaseRendering
///////////////////////////////////////////////////////////////////////////////////////////////////
//// SINGLETON CLASS - see CBaseRendering ////
//// ONLY ONE OBJECT OF ALL INHERITING CLASSES IS ALLOWED AT ONE TIME ////
class COpenGL_API : public IBaseRenderingAPI
{
	// Friends:
	friend class CRenderingMediator;

private: // Fields

protected: // Methods 
	COpenGL_API(); // Constructor
	//virtual ~COpenGL_API(); // Destructor
	
public: // Methods

};


#endif // H_OPENGL_API