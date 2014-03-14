#ifndef AFFILIATIONS_H_
#define AFFILIATIONS_H_

#ifdef __GNUC__

#ifdef AFFILIATIONSLIB
#define AFFILIATIONSAPI __attribute__ ((visibility("default")))
#else
#define AFFILIATIONSAPI
#endif

#else

#ifdef AFFILIATIONSLIB
#define AFFILIATIONSAPI __declspec(dllexport)
#else
#define AFFILIATIONSAPI __declspec(dllimport)
#endif

#endif

#endif