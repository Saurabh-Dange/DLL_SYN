#include "stdafx.h"
#include<iostream>
#include <windows.h>

#define EOF (-1)

#ifdef __cplusplus    
extern "C" {
#endif
	using namespace std;

	__declspec(dllexport) int __cdecl cube(int n)
	{

		HANDLE hConout;
		int cub=0;


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

		cout << "Thread 2 \n";
		cout << "Your sequence is \n";
		while (n!=0)
		{
			cub = n*n*n;
			std::cout << cub<<"\n";
			
			n--;
			

		}

		

		return 1;
	}

#ifdef __cplusplus
}
#endif
