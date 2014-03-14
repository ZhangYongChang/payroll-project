#ifndef SCHEDULES_H_
#define SCHEDULES_H_

#ifdef __GNUC__

#ifdef SCHEDULESLIB
#define SCHEDULESAPI __attribute__ ((visibility("default")))
#else
#define SCHEDULESAPI
#endif

#else

#ifdef SCHEDULESLIB
#define SCHEDULESAPI __declspec(dllexport)
#else
#define SCHEDULESAPI __declspec(dllimport)
#endif

#endif

#endif