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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ooooo      ooo                                  .oooooo..o               .       .   oooo                                   ooooo oooooo     oooo 
//`888b.     `8'                                 d8P'    `Y8             .o8     .o8   `888                                   `888'  `888.     .8'  
// 8 `88b.    8   .ooooo.  oooo oooo    ooo      Y88bo.       .ooooo.  .o888oo .o888oo  888   .ooooo.  oooo d8b  .oooo.o       888    `888.   .8'   
// 8   `88b.  8  d88' `88b  `88. `88.  .8'        `"Y8888o.  d88' `88b   888     888    888  d88' `88b `888""8P d88(  "8       888     `888. .8'    
// 8     `88b.8  888ooo888   `88..]88..8'             `"Y88b 888ooo888   888     888    888  888ooo888  888     `"Y88b.        888      `888.8'     
// 8       `888  888    .o    `888'`888'         oo     .d8P 888    .o   888 .   888 .  888  888    .o  888     o.  )88b       888       `888'      
//o8o        `8  `Y8bod8P'     `8'  `8'          8""88888P'  `Y8bod8P'   "888"   "888" o888o `Y8bod8P' d888b    8""888P'      o888o       `8'       
//                                                                                                                                                  
//                                                                                                                                                  
//                                                                                                                                                  
//                                   ooooooooo.                          o8o                         .                                              
//                                   `888   `Y88.                        `"'                       .o8                                              
//                                    888   .d88' oooo d8b  .ooooo.     oooo  .ooooo.   .ooooo.  .o888oo                                            
//                                    888ooo88P'  `888""8P d88' `88b    `888 d88' `88b d88' `"Y8   888                                              
//                                    888          888     888   888     888 888ooo888 888         888                                              
//                                    888          888     888   888     888 888    .o 888   .o8   888 .                                            
//                                   o888o        d888b    `Y8bod8P'     888 `Y8bod8P' `Y8bod8P'   "888"                                            
//                                                                       888                                                                        
//                                                                   .o. 88P                                                                        
//                                                                   `Y888P                                                                         
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// __  __       _                              
//|  \/  |     (_)                             
//| \  / | __ _ _ _ __         ___ _ __  _ __  
//| |\/| |/ _` | | '_ \       / __| '_ \| '_ \ 
//| |  | | (_| | | | | |  _  | (__| |_) | |_) |
//|_|  |_|\__,_|_|_| |_| (_)  \___| .__/| .__/ 
//                                | |   | |    
//                                |_|   |_|    
////////////////////////////////////////////////
                                                                                                    

#include "Messages.h"
#include "GameApplication.h"

#if (defined(_WIN32) || defined(_WIN64)) && !defined(_DEBUG)
#include "windows.h"

int WINAPI WinMain(HINSTANCE inst, HINSTANCE prev, LPSTR cmd, int show)
#else
int main(int argc, char **argv)
#endif
{
	// Try to create the game application and start it
	try
	{
		CGameApplication gameApp;
		gameApp.StartAndRun();
	}
	catch (ExceptionNr exc)
	{
		// Display exception error message
		MESSAGE::Exception(exc, __FILENAME__);
	}

	return 0;
}
