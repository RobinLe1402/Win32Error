#include <cstdio>
#include <fcntl.h>
#include <io.h>
#include <string>

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>



void PrintUsage(const wchar_t *szArgv0);



int wmain(int argc, wchar_t* argv[])
{
	if (argc != 2)
	{
		PrintUsage(argv[0]);
		return 1;
	}

	const wchar_t *szErrorCode = argv[1];

	// convert the string into an integer
	try
	{
		const DWORD dwError = std::stoi(szErrorCode);

		LPWSTR szMessage = nullptr;

		size_t size = FormatMessageW(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			dwError,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPWSTR)&szMessage,
			0,
			NULL
		);

		_setmode(_fileno(stdout), _O_U16TEXT); // make sure unicode is properly output
		std::wprintf(L"%s\n", szMessage);

		LocalFree(szMessage);
	}
	catch (...)
	{
		PrintUsage(argv[0]);
		return 1;
	}

	return 0;
}



void PrintUsage(const wchar_t *szArgv0)
{
	std::printf(
		"Convert a Win32 error code into a readable text.\n"
		"USAGE:\n"
		"%ls ErrorCode"
		"\n"
		"  ErrorCode       A Win32 error code, like the return value of GetLastError().\n",
		szArgv0
	);
}
