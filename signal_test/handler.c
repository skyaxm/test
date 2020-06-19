#include "handler.h"

void sig_handler(int signum)
{
    switch(signum) {
        case SIGINT:
        case SIGKILL:
        case SIGQUIT:
        case SIGABRT:
        case SIGTRAP:
        case SIGTERM:
            break;
        case SIGHUP:
            break;
        default:
    }
}

void sig_init()
{
    signal(SIGINT, sig_handler);
}
