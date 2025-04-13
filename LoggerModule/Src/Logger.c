#include "../Inc/Logger.h"

void logger_init(){

}

void logger(log_level_t level, const char* tag, const char* format, ...){
    va_list args;

    const char *level_str;

    switch (level) {
        case LOG_LEVEL_INFO:
            level_str = "INFO";
        break;
        case LOG_LEVEL_WARN:
            level_str = "WARN";
        break;
        case LOG_LEVEL_ERROR:
            level_str = "ERROR";
        break;
        case LOG_LEVEL_DEBUG:
            level_str = "DEBUG";
        break;
        default:
            level_str = "UNKNOWN";
        break;
    }

    printf("[%s][%s] ", level_str, tag);

    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf("\n");
}
