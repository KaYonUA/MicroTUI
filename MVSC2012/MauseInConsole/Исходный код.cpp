#if       _WIN32_WINNT < 0x0500
  #undef  _WIN32_WINNT
  #define _WIN32_WINNT   0x0502
#endif

#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;



//int main()
//{
//	cout<<"Blad Blad VLaf";
//	HANDLE hStdout, hNewScreenBuffer; 
//    SMALL_RECT srctReadRect; 
//    SMALL_RECT srctWriteRect; 
//    CHAR_INFO chiBuffer[160]; // [2][80]; 
//    COORD coordBufSize; 
//    COORD coordBufCoord; 
//    BOOL fSuccess; 
//
//	chiBuffer[0].Char.UnicodeChar = L'f';
// 
//    // Get a handle to the STDOUT screen buffer to copy from and 
//    // create a new screen buffer to copy to. 
// 
//    hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
//    hNewScreenBuffer = CreateConsoleScreenBuffer( 
//       GENERIC_READ |           // read/write access 
//       GENERIC_WRITE, 
//       FILE_SHARE_READ | 
//       FILE_SHARE_WRITE,        // shared 
//       NULL,                    // default security attributes 
//       CONSOLE_TEXTMODE_BUFFER, // must be TEXTMODE 
//       NULL);                   // reserved; must be NULL 
//    if (hStdout == INVALID_HANDLE_VALUE || 
//            hNewScreenBuffer == INVALID_HANDLE_VALUE) 
//    {
//        printf("CreateConsoleScreenBuffer failed - (%d)\n", GetLastError()); 
//        return 1;
//    }
// 
//    // Make the new screen buffer the active screen buffer. 
// 
//    if (! SetConsoleActiveScreenBuffer(hNewScreenBuffer) ) 
//    {
//        printf("SetConsoleActiveScreenBuffer failed - (%d)\n", GetLastError()); 
//        return 1;
//    }
// 
//    // Set the source rectangle. 
// 
//    srctReadRect.Top = 0;    // top left: row 0, col 0 
//    srctReadRect.Left = 0; 
//    srctReadRect.Bottom = 1; // bot. right: row 1, col 79 
//    srctReadRect.Right = 79; 
// 
//    // The temporary buffer size is 2 rows x 80 columns. 
// 
//    coordBufSize.Y = 2; 
//    coordBufSize.X = 80; 
// 
//    // The top left destination cell of the temporary buffer is 
//    // row 0, col 0. 
// 
//    coordBufCoord.X = 0; 
//    coordBufCoord.Y = 0; 
// 
//    // Copy the block from the screen buffer to the temp. buffer. 
// 
//    fSuccess = ReadConsoleOutput( 
//       hStdout,        // screen buffer to read from 
//       chiBuffer,      // buffer to copy into 
//       coordBufSize,   // col-row size of chiBuffer 
//       coordBufCoord,  // top left dest. cell in chiBuffer 
//       &srctReadRect); // screen buffer source rectangle 
//    if (! fSuccess) 
//    {
//        printf("ReadConsoleOutput failed - (%d)\n", GetLastError()); 
//        return 1;
//    }
// 
//    // Set the destination rectangle. 
// 
//    srctWriteRect.Top = 2;    // top lt: row 10, col 0 
//    srctWriteRect.Left = 0; 
//    srctWriteRect.Bottom = 11; // bot. rt: row 11, col 79 
//    srctWriteRect.Right = 79; 
// 
//    // Copy from the temporary buffer to the new screen buffer. 
// 
//    fSuccess = WriteConsoleOutput( 
//        hNewScreenBuffer, // screen buffer to write to 
//        chiBuffer,        // buffer to copy from 
//        coordBufSize,     // col-row size of chiBuffer 
//        coordBufCoord,    // top left src cell in chiBuffer 
//        &srctWriteRect);  // dest. screen buffer rectangle 
//    if (! fSuccess) 
//    {
//        printf("WriteConsoleOutput failed - (%d)\n", GetLastError()); 
//        return 1;
//    }
//    Sleep(5000); 
// 
//    // Restore the original active screen buffer. 
// 
//    if (! SetConsoleActiveScreenBuffer(hStdout)) 
//    {
//        printf("SetConsoleActiveScreenBuffer failed - (%d)\n", GetLastError()); 
//        return 1;
//    }
	//WriteConsoleOutputAttribute(unactive,color,6,gf,NULL);
	///SetConsoleActiveScreenBuffer(unactive);


	/*static HANDLE _ConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
	DWORD cNumRead, fdwMode, fdwSaveOldMode, i; 
    INPUT_RECORD irInBuf[128];
	GetConsoleMode(hStdin, &fdwSaveOldMode)  ;     
    fdwMode = fdwSaveOldMode | ENABLE_MOUSE_INPUT; 
    SetConsoleMode(hStdin, fdwMode)  ;    
	COORD r = {30,15};*/

	//while(true)
	//{
 //   ReadConsoleInput(  hStdin,   irInBuf,  250,    &cNumRead) ;   
 //   for (i = 0; i < cNumRead; i++) 
 //   {
 //       if (irInBuf[i].EventType==MOUSE_EVENT) 
 //       {                    
 //           switch (irInBuf[i].Event.MouseEvent.dwEventFlags)
 //           {
	//		case MOUSE_MOVED:
	//			r.X = irInBuf[i].Event.MouseEvent.dwMousePosition.X;
	//			r.Y = irInBuf[i].Event.MouseEvent.dwMousePosition.Y;
	//			if (irInBuf[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
	//				WriteConsoleOutputCharacter(_ConsoleOut,(PCWSTR)"+",1,r,NULL);
	//			if (irInBuf[i].Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)
	//				WriteConsoleOutputCharacter(_ConsoleOut,(PCWSTR)" ",1,r,NULL);
	//			//cout<<"Move"<<endl;
 //               break;
 //           case DOUBLE_CLICK: cout<<"Double Click"<<endl;
 //               break;
 //           case MOUSE_WHEELED: cout<<"Wheel"<<endl;
 //               break;
 //           default: 
	//			if (irInBuf[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
	//			{
	//			  symbol = '+';
	//			}
	//			else
 //
	//			if (irInBuf[i].Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)
	//			{
	//				cout << "RIGHT BUTTON" << endl;
	//			}else
	//				symbol = ' ';
	//			
 //               break;   
 //               
 //           }
	//		 if (irInBuf[i].EventType==KEY_EVENT) 
 //           {  
	//			switch (irInBuf[i].Event.KeyEvent.bKeyDown)
 //               {
	//			case SHIFT_PRESSED:
	//				cout<<"Shift"<<endl;
	//				break;
	//			}
	//		}
 //       } 
	//}
	//
	///*cout<<"Window Cords "<<size.WindX<< "x"<<size.WindY <<endl;
	//cout<<"Window size "<<size.WindW<<" "<<size.WindH<<endl;
	//cout<<"Console Cords "<<size.ClientX<<"x"<<size.ClientY<<endl;
	//cout<<"Console size "<<size.ClientW<<" "<<size.ClientH<<endl;
	//cout<<"Head size "<< size.Head<<endl;
	//cout<<"Border size "<<size.Border<<endl;
	//cout<<"Local cursor "<<mouse.x - size.ClientX<<" "<<mouse.y - size.ClientY<<endl;
	//cout<<"Font size "<<12<<endl;
	//cout<<"mouse coord in symbols "<<(mouse.x - size.ClientX) / on_pix_W<<" "<<(mouse.y - size.ClientY) / on_pic_H<<endl;*/
	////SetConsoleCursorPosition(_ConsoleOut,pos);
	////cout<< "X";
	///*pos.X = 0;
	//pos.Y = 0;
	//SetConsoleCursorPosition(_ConsoleOut,pos);*/
	//}
 //  