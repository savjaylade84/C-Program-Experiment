#define IOSTREAM 
//"IOstream.h"
#define STDIO 
#define NCURSES
#define ASSERT
#define STDBOOL
#define import(x)

#ifdef IOSTREAM
#include "IOstream.h"
#endif

#ifdef STDIO
#include <stdio.h>
#endif

#ifdef NCURSES
#include <ncurses.h>
#endif

#ifdef ASSERT
#include <assert.h>
#endif

#ifdef STDBOOL
#include <stdbool.h>
#endif

  