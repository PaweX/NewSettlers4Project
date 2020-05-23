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

#ifndef H_SHAREDEFS
#define H_SHAREDEFS

///////////////////////////////////////////////////////////////////////////////////////////////////
// DESCRIPTION: Here are all shared definitions for all the classes
///////////////////////////////////////////////////////////////////////////////////////////////////

const enum ExceptionNr
{
	except_UNKNOWN_EXCEPTION = 0,

	except_GAME_APP_ALREADY_EXISTS = 1,
	except_GAME_APP_NOT_CREATED,
	except_GRAPHICS_MANAGER_ALREADY_EXISTS,
	except_GRAPHICS_MANAGER_NOT_CREATED,
	except_RENDERING_MEDIATOR_ALREADY_EXISTS,
	except_RENDERING_MEDIATOR_NOT_CREATED,
	except_A_RENDERING_API_ALREADY_EXISTS,
	except_A_RENDERING_API_NOT_CREATED,
	except_GAME_SETTINGS_ALREADY_EXISTS,
	except_GAME_SETTINGS_NOT_CREATED,

	except_COUNT // must be last
};

const enum API_Type
{
	API_CURRENT_API,

	API_OpenGl,
	API_Vulkan,
	API_DirectX
};


#endif // H_SHAREDEFS