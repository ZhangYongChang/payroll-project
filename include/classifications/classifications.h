#ifndef CLASSIFICATIONS_H_
#define CLASSIFICATIONS_H_

#ifdef __GNUC__

#ifdef CLASSIFICATIONSLIB
#define CLASSIFICATIONSAPI __attribute__ ((visibility("default")))
#else
#define CLASSIFICATIONSAPI
#endif

#else

#ifdef CLASSIFICATIONSLIB
#define CLASSIFICATIONSAPI __declspec(dllexport)
#else
#define CLASSIFICATIONSAPI __declspec(dllimport)
#endif

#endif

#endif