#ifndef DOMAIN_H_
#define DOMAIN_H_

#ifdef __GNUC__

#ifdef CORELIB
#define COREAPI __attribute__ ((visibility("default")))
#else
#define COREAPI
#endif

#else

#ifdef CORELIB
#define COREAPI __declspec(dllexport)
#else
#define COREAPI __declspec(dllimport)
#endif

#endif

#endif