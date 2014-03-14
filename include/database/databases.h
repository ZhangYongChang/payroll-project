#ifndef DATABASE_H_
#define DATABASE_H_

#ifdef __GNUC__

#ifdef DATABASELIB
#define DATABASEAPI __attribute__ ((visibility("default")))
#else
#define DATABASEAPI
#endif

#else

#ifdef DATABASELIB
#define DATABASEAPI __declspec(dllexport)
#else
#define DATABASEAPI __declspec(dllimport)
#endif

#endif

#endif