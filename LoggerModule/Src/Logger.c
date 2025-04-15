#include "../Inc/Logger.h"

static bool prv_ts = 0;

void logger_init(const logger_config_t* config){
    if (config->timestamp){
        prv_ts = 1;
    }
}

void logger(log_level_t level, const char* tag, const char* format, ...){
    va_list args;

    const char *level_str = NULL;

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

    if (prv_ts){
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        printf("[%s] [%s] [%02d:%02d:%02d] ", level_str, tag, t->tm_hour, t->tm_min, t->tm_sec);

    } else {
        printf("[%s] [%s] ", level_str, tag);
    }


    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf("\n");
}
