 

#include "stdafx.h"
#include <windows.h> 
#include <stdio.h> 
#include <iostream>
#include <process.h> 
#include <string.h>

#define MAX_LEN 50

using namespace std;
static int mutex = 1;
static int turn = 1;

typedef int(__cdecl *MYPROC)(char*);
typedef int(__cdecl *MYPRO)(int);


DWORD WINAPI pString(__in LPVOID lpParameter)
//void pString()
{
	HINSTANCE hinstLib;
	MYPROC ProcAdd;
	BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;
	int flag = 0;
	//char *s = new char[MAX_LEN];
	//cout << "here3";

	
	
	
	// Get a handle to the DLL module.

	hinstLib = LoadLibrary(TEXT("String_runtime.dll"));
	
	//cout << "here1";

	// If the handle is valid, try to get the function address.

	if (hinstLib != NULL)
	{
		ProcAdd = (MYPROC)GetProcAddress(hinstLib, "sTring");
		

		// If the function address is valid, call the function.

		if (NULL != ProcAdd)
		{
			fRunTimeLinkSuccess = TRUE;
		//	fgets(s, MAX_LEN, stdin);
			//cout << "here4";

			
		    while (!mutex);
			if (turn&&mutex)
			{

				mutex = 0;
				if ((ProcAdd)("Hello Everyone"))

				{
					turn = 0;
					mutex = 1;
				}

				//cout << "here6";
			}

							
		}
		// Free the DLL module.
		
		fFreeResult = FreeLibrary(hinstLib);
	}

	// If unable to call the DLL function,print this
	if (!fRunTimeLinkSuccess)
		printf("Call To Message Failed");

	return 0;


}


	DWORD WINAPI pCube(__in LPVOID lpParameter)
	{
		HINSTANCE hinstLib1;

		MYPRO ProcAdd1;
		BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;
		int flag = 0;
		//int k;

		 //Get a handle to the DLL module.
		//cout << "here7";

		hinstLib1 = LoadLibrary(TEXT("String_mul_run.dll"));


		// If the handle is valid, try to get the function address.

		if (hinstLib1 != NULL)
		{
			//cout << "here8";
			ProcAdd1 = (MYPRO)GetProcAddress(hinstLib1, "cube");

			//If the function address is valid, call the function.

			if (NULL != ProcAdd1)
			{
				//cout << "here9";
				fRunTimeLinkSuccess = TRUE;


				while (!mutex);
				if ((turn==0)&&mutex)
				{
					//cout << "here10";
					(ProcAdd1)(5);
					turn = 1;
					mutex = 0;
					//cout << "here11";
				}



			}
			// Free the DLL module.

			fFreeResult = FreeLibrary(hinstLib1);
		}
	

	// If unable to call the DLL function,print this
	if (!fRunTimeLinkSuccess)
		printf("Call To Message Failed");
	
	return 0;
	}

int main(int argc, char* argv[])
{	

	HANDLE myhandle,myhandle1; 
	DWORD mythreadid,mythreadid1; 
	myhandle = CreateThread(0, 64, pString, 0, 0, &mythreadid); 
	//cout << "here2";
	myhandle1 = CreateThread(0, 0, pCube, 0, 0, &mythreadid1); 
	//cout << "here5";
	getchar();
	//pString();
	
	return 0;
}
