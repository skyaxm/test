#ifndef __test_level_h
#define __test_level_h

#include "zlog.h"

enum {
    ZLOG_LEVEL_TRACE = 10,
};

#define zlog_trace(cat, format, ...) \
        zlog(cat, __FILE__, sizeof(__FILE__)-1, \
        __func__, sizeof(__func__)-1, __LINE__, \
        ZLOG_LEVEL_TRACE, format, ## __VA_ARGS__)
#endif
