

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
		

		// Get a handle to the console output device.

		hConout = CreateFileW(L"CONOUT$",
			GENERIC_WRITE,
			FILE_SHARE_WRITE,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL);

		if (INVALID_HANDLE_VALUE == hConout)
			return EOF;

		
		cout << "Your string is \n";

		while (*myString != L'\0')
		{
			
			std::cout<<*myString;
			myString++;
			count++;
			//cout << count;
			


		}
		
		cout<<"\nLength of your string is " << count<<"\n";

		return 1;
	}

#ifdef __cplusplus
}
#endif
