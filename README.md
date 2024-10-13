# Win32 Error Code To Text Tool

This repo contains the Windows application `Win32Error`, which
translates Win32 error codes (read from `GetLastError()`) to a
human-readable error message.

## Syntax
```
Win32Error.exe <ErrorCode>
```

So a call could look like this:

- `Win32Error.exe 10`
- `Win32Error.exe 1440`
