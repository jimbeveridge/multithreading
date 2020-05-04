/*
 * MtVerify.h
 *
 * Error handling for applications in
 * "Multithreading Applications in Win32"
 *
 * The function PrintError() is marked as __inline so that it can be
 * included from one or more C or C++ files without multiple definition
 * errors. For the examples in this book, this works fine.
 * To use the PrintError() in an application, it should be taken out,
 * placed in its own source file, and the "__inline" declaration removed
 * so the function will be globally available.
 */

#pragma once

#include <crtdbg.h>
#include <tchar.h>
#define MTASSERT(a) _ASSERTE(a)


#define MTVERIFY(a) if (!(a)) PrintError(#a, __FILE__, __LINE__, GetLastError())

__inline void PrintError(LPSTR linedesc, LPSTR filename, int lineno, DWORD errnum)
{
	LPTSTR lpBuffer = 0;
	TCHAR errbuf[256];
#ifdef _WINDOWS
	TCHAR modulename[MAX_PATH];
#else // _WINDOWS
	DWORD numread;
#endif // _WINDOWS

	FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER
			| FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		errnum,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpBuffer,
		0,
		NULL );

	_sntprintf_s(errbuf, sizeof(errbuf), _TRUNCATE, _T("\nThe following call failed at line %d in %hs:\n\n")
               _T("    %hs\n\nReason: %s\n"), lineno, filename, linedesc, lpBuffer);
#ifndef _WINDOWS
	WriteFile(GetStdHandle(STD_ERROR_HANDLE), errbuf, _tcslen(errbuf), &numread, FALSE );
	Sleep(3000);
#else
	GetModuleFileName(NULL, modulename, MAX_PATH);
	MessageBox(NULL, errbuf, modulename, MB_ICONWARNING|MB_OK|MB_TASKMODAL|MB_SETFOREGROUND);
#endif
	LocalFree(lpBuffer);
	exit(EXIT_FAILURE);
}
