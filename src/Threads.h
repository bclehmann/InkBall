
#ifndef INKBALL_THREADS_H
#define INKBALL_THREADS_H

#ifdef _WIN32

#define _WIN32_WINNT 0x0501
#include "mingw/mingw.thread.h"

#else

#include <thread>

#endif

#endif //INKBALL_THREADS_H
