#ifndef METHODS_H_
#define METHODS_H_

#ifdef __GNUC__

#ifdef METHODLIB
#define METHODAPI __attribute__ ((visibility("default")))
#else
#define METHODAPI
#endif

#else

#ifdef METHODLIB
#define METHODAPI __declspec(dllexport)
#else
#define METHODAPI __declspec(dllimport)
#endif

#endif

#endif