#include "../Inc/Logger.h"

static bool prv_ts = 0;

static bool prv_safe = 0;

static pthread_mutex_t logger_mutex;

my_module_error_t logger_init(const logger_config_t* config){
    if (config->timestamp){
        prv_ts = 1;
    }
    if (config->thread_safe){
      	prv_safe = 1;
        if (pthread_mutex_init(&logger_mutex, NULL) != 0){
          return LOGGER_ERROR_NOMEM;
        }
    }
    return LOGGER_ERROR_OK;
}

void logger(log_level_t level, const char* tag, const char* format, ...){
	if (prv_safe) {
        pthread_mutex_lock(&logger_mutex);
    }

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

    if (prv_safe) {
        pthread_mutex_unlock(&logger_mutex);
    }
}
