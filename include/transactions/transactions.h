#ifndef TRANSACTIONS_H_
#define TRANSACTIONS_H_

#ifdef __GNUC__

#ifdef TRANSACTIONSLIB
#define TRANSACTIONSAPI __attribute__ ((visibility("default")))
#else
#define TRANSACTIONSAPI
#endif

#else

#ifdef TRANSACTIONSLIB
#define TRANSACTIONSAPI __declspec(dllexport)
#else
#define TRANSACTIONSAPI __declspec(dllimport)
#endif

#endif

#endif
