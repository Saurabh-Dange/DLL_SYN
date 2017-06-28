

#include "stdafx.h"
#include<iostream>
#include <windows.h>

#define EOF (-1)

#ifdef __cplusplus    
extern "C" {          
#endif
	using namespace std;

	__declspec(dllexport) int __cdecl sTring(char *myString)
	{
		
		HANDLE hConout;
		int count = 0;
		//cout << "there1";

		// Get a handle to the console output device.

		hConout = CreateFileW(L"CONOUT$",
			GENERIC_WRITE,
			FILE_SHARE_WRITE,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL);
		//cout << "there2";

		if (INVALID_HANDLE_VALUE == hConout)
			return EOF;

		cout << "Thread 1 \n";
		cout << "Your string is \n";
		//cout << "there3";

		while (*myString != L'\0')
		{
			
			std::cout<<*myString;
			myString++;
			count++;
			
			


		}
		//cout << "there4";
		cout<<"\nLength of your string is " << count-1<<"\n";
		//cout << "there5";
		return 1;
	}

#ifdef __cplusplus
}
#endif
