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

#include <stdarg.h> 
#include <stdio.h>
#include "Messages.h"


//----------------------------------------------------------------
//----------------------------------------------------------------
// Initialize variables
//----------------------------------------------------------------
//----------------------------------------------------------------
#ifdef _WIN32
HANDLE MESSAGE::hConsole = nullptr;
#endif
std::mutex MESSAGE::mtx;
//bool MESSAGE::bUseInGameConsole = false;


constexpr MESSAGE::ExceptionMessages MESSAGE::excMessages = MESSAGE::ExceptionMessages();


//----------------------------------------------------------------
//----------------------------------------------------------------
// Private methods
//----------------------------------------------------------------
//----------------------------------------------------------------
#ifdef _WIN32
HANDLE MESSAGE::GetWindowsConsole()
{
	if (hConsole == nullptr)
		return hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	else
		return hConsole;
}
#endif
//----------------------------------------------------------------

//----------------------------------------------------------------
//----------------------------------------------------------------
// Public methods
//----------------------------------------------------------------
//----------------------------------------------------------------
void MESSAGE::Normal(ExceptionNr excIndex, const char* cppFileName, const char* lineNumberText)
{
	Normal(GetExceptionMsg(excIndex));
}

void MESSAGE::Normal(const char* msgString, const char* cppFileName, const char* lineNumberText, ...)
{
	mtx.lock(); // Lock it for the thread

	va_list args;
	va_start(args, msgString);

	const char* threadName = GetThreadName();
	if (threadName != "")
		printf("[%s]: ", threadName);

	//printf("[Message]: ");

	if (cppFileName != "")
		printf("[File %s]: ", cppFileName);
	if (lineNumberText != "")
		printf("[Line %s]: ", lineNumberText);

	vprintf(msgString, args);
	printf("\n");

	va_end(args);

	mtx.unlock(); // Unlock it
}
//----------------------------------------------------------------

void MESSAGE::Info(ExceptionNr excIndex, const char* cppFileName, const char* lineNumberText)
{
	Info(GetExceptionMsg(excIndex));
}

void MESSAGE::Info(const char* infoString, const char* cppFileName, const char* lineNumberText, ...)
{
	mtx.lock(); // Lock it for the thread

	va_list args;
	va_start(args, infoString);

#ifndef _WIN32
	printf("\033[0;34m"); // blue color
#else
	SetConsoleTextAttribute(GetWindowsConsole(), 9); // set color to blue in Windows console
#endif // ! _WIN32

	const char* threadName = GetThreadName();
	if (threadName != "")
		printf("[%s]: ", threadName);

	//printf("[INFORMATION]: ");

	if (cppFileName != "")
		printf("[File %s]: ", cppFileName);
	if (lineNumberText != "")
		printf("[Line %s]: ", lineNumberText);

	vprintf(infoString, args);
	printf("\n");

#ifndef _WIN32
	printf("\033[0m;"); // normal color
#else
	SetConsoleTextAttribute(GetWindowsConsole(), 7); // set color back to white in Windows console
#endif // ! _WIN32

	va_end(args);

	mtx.unlock(); // Unlock it
}
//----------------------------------------------------------------

void MESSAGE::Warning(ExceptionNr excIndex, const char* cppFileName, const char* lineNumberText)
{
	Warning(GetExceptionMsg(excIndex));
}

void MESSAGE::Warning(const char* warnString, const char* cppFileName, const char* lineNumberText, ...)
{
	mtx.lock(); // Lock it for the thread

	va_list args;
	va_start(args, warnString);

#ifndef _WIN32
	printf("\033[1;33m"); // yellow color
#else
	SetConsoleTextAttribute(GetWindowsConsole(), 14); // set color to yellow in Windows console
#endif // ! _WIN32

	const char* threadName = GetThreadName();
	if (threadName != "")
		printf("[%s]: ", threadName);

	printf("[WARNING]: ");

	if (cppFileName != "")
		printf("[File %s]: ", cppFileName);
	if (lineNumberText != "")
		printf("[Line %s]: ", lineNumberText);

	vprintf(warnString, args);
	printf("\n");

#ifndef _WIN32
	printf("\033[0m;"); // normal color
#else
	SetConsoleTextAttribute(GetWindowsConsole(), 7); // set color back to white in Windows console
#endif // ! _WIN32

	va_end(args);

	mtx.unlock(); // Unlock it
}
//----------------------------------------------------------------

void MESSAGE::Error(ExceptionNr excIndex, const char* cppFileName, const char* lineNumberText)
{
	Error(GetExceptionMsg(excIndex), cppFileName);
}

void MESSAGE::Error(const char* errorString, const char* cppFileName, const char* lineNumberText, ...)
{
	mtx.lock(); // Lock it for the thread

	va_list args;
	va_start(args, errorString);

#ifndef _WIN32
	printf("\033[1;31m"); // red color
#else
	SetConsoleTextAttribute(GetWindowsConsole(), 12); // set color to red in Windows console
#endif // ! _WIN32

	const char* threadName = GetThreadName();
	if (threadName != "")
		printf("[%s]: ", threadName);

	printf("[ERROR]: ");

	if (cppFileName != "")
		printf("[File %s]: ", cppFileName);
	if (lineNumberText != "")
		printf("[Line %s]: ", lineNumberText);

	vprintf(errorString, args);
	printf("\n");

#ifndef _WIN32
	printf("\033[0m;"); // normal color
#else
	SetConsoleTextAttribute(GetWindowsConsole(), 7); // set color back to white in Windows console
#endif // ! _WIN32

	va_end(args);

	mtx.unlock(); // Unlock it
}
//----------------------------------------------------------------

void MESSAGE::Exception(ExceptionNr excIndex, const char* cppFileName, const char* lineNumberText)
{
	Exception(GetExceptionMsg(excIndex), cppFileName);
}

void MESSAGE::Exception(const char* exceptionString, const char* cppFileName, const char* lineNumberText, ...)
{
	mtx.lock(); // Lock it for the thread

	va_list args;
	va_start(args, exceptionString);

#ifndef _WIN32
	printf("\033[1;37;41m"); // white color on red background
#else
	SetConsoleTextAttribute(GetWindowsConsole(), 207); // set color to white on red background in Windows console
#endif // ! _WIN32

	const char* threadName = GetThreadName();
	if (threadName != "")
		printf("[%s]: ", threadName);

	printf("[EXCEPTION]: ");

	if (cppFileName != "")
		printf("[Caught in %s]: ", cppFileName);
	if (lineNumberText != "")
		printf("[Line %s]: ", lineNumberText);

	vprintf(exceptionString, args);
	printf("\n");

#ifndef _WIN32
	printf("\033[0m;"); // normal color
#else
	SetConsoleTextAttribute(GetWindowsConsole(), 7); // set color back to white in Windows console
#endif // ! _WIN32

	va_end(args);

	mtx.unlock(); // Unlock it
}
//----------------------------------------------------------------