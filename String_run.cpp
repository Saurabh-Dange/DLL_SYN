 

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
{
	HINSTANCE hinstLib;
	MYPROC ProcAdd;
	BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;
	int flag = 0;
	//char str[MAX_LEN];
	char c;



	char *s = new char[MAX_LEN];
	
	//cin.getline(str, MAX_LEN);
	//ungetc(c, stdin);
	//fgets(s, MAX_LEN, stdin);
	



	// Get a handle to the DLL module.

	hinstLib = LoadLibrary(TEXT("String_runtime.dll"));
	


	// If the handle is valid, try to get the function address.

	if (hinstLib != NULL)
	{
		ProcAdd = (MYPROC)GetProcAddress(hinstLib, "sTring");
		

		// If the function address is valid, call the function.

		if (NULL != ProcAdd)
		{
			fRunTimeLinkSuccess = TRUE;
			
			//while (1)
			//{	
	
			/*	if (turn) 
				{
					while (!mutex);
					mutex = 0; 
				}*/
				//fgets(s, MAX_LEN, stdin);
				(ProcAdd)("Hello Everyone");
				/*turn = 0;
				mutex = 1;*/

				
			//}
			
			
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

	
	hinstLib1 = LoadLibrary(TEXT("String_mul_run.dll"));
	

	// If the handle is valid, try to get the function address.

		if (hinstLib1 != NULL)
		{
		
		ProcAdd1 = (MYPRO)GetProcAddress(hinstLib1, "cube");

		 //If the function address is valid, call the function.

			if (NULL != ProcAdd1)
			{
				fRunTimeLinkSuccess = TRUE;
				
				//while (1)
				//{
					
				/*	if (!turn)
					{
						while (!mutex);
						mutex = 0;
					}*/
				
					(ProcAdd1)(5);
					/*turn = 1;
					mutex = 1;*/
				//}
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
	myhandle = CreateThread(0, 0, pString, 0, 0, &mythreadid); 
	myhandle1 = CreateThread(0, 0, pCube, 0, 0, &mythreadid1); 
	getchar();
	return 0;
}