#ifndef JDME2X_API_H
#define JDME2X_API_H

#if (defined _WIN32 && defined JDME2X_DLL)
#ifdef JDME2X_EXPORT
#define JDME2X_API __declspec(dllexport)
#else
#define JDME2X_API __declspec(dllimport)
#endif
#else
#define JDME2X_API
#endif

#endif
