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
#ifndef H_MESSAGES
#define H_MESSAGES
#ifdef _WIN32
#include <windows.h>
#endif
#include <string.h>
#include "sharedefs.h"

#ifdef _WIN32
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#else
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DESCRIPTION: Class for displaying error, warning and debug messages.
// This class contains of static fields and methods and doesn't create any objects.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class MESSAGE
{
private:
#ifdef _WIN32
	static HANDLE hConsole;
	static HANDLE GetWindowsConsole();
#endif

	//static bool bUseInGameConsole;

private:
	// This structure is containing text messages for exceptions.
	struct ExceptionMessages
	{
		const char* excMessagesArray[except_COUNT];

		// Constructor
		constexpr ExceptionMessages() : excMessagesArray()
		{
			excMessagesArray[except_UNKNOWN_EXCEPTION]					= "Unknown exception!";
			excMessagesArray[except_GAME_APP_ALREADY_EXISTS]			= "CGameApplication instance already existing!";
			excMessagesArray[except_GAME_APP_NOT_CREATED]				= "CGameApplication instance not existing!";
			excMessagesArray[except_GRAPHICS_MANAGER_ALREADY_EXISTS]	= "CGraphicsManager instance already existing!";
			excMessagesArray[except_GRAPHICS_MANAGER_NOT_CREATED]		= "CGraphicsManager instance not existing!";
		}


		const char* GetExcText(unsigned &index) const
		{
			return excMessagesArray[index];
		}
	};

	static const ExceptionMessages excMessages;

public: // Fields


public:
	static const char* GetExceptionMsg(unsigned msgIndex) { return excMessages.GetExcText(msgIndex); }

	static void Normal(ExceptionNr excIndex, const char* cppFileName = "");
	static void Normal(const char* msgString, const char* cppFileName = "", ...);
	static void Info(ExceptionNr excIndex, const char* cppFileName = "");
	static void Info(const char* msgString, const char* cppFileName = "", ...);
	static void Warning(ExceptionNr excIndex, const char* cppFileName = "");
	static void Warning(const char* warnString, const char* cppFileName = "", ...);
	static void Error(ExceptionNr excIndex, const char* cppFileName = "");
	static void Error(const char* errorString, const char* cppFileName = "", ...);
	static void Exception(ExceptionNr excIndex, const char* cppFileName = "");
	static void Exception(const char* errorString, const char* cppFileName = "", ...);
};


#endif // H_MESSAGES