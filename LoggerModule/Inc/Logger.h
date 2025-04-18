#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

#ifndef LOGGER_H
#define LOGGER_H

typedef enum {
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_DEBUG
} log_level_t;

typedef struct logger_config_s{
    bool timestamp;
    bool thread_safe; // to add in the futre
} logger_config_t;

void logger_init(const logger_config_t*);

void logger(log_level_t, const char* tag, const char* format, ...);

#define LOG_INFO(...)  logger(LOG_LEVEL_INFO,  __FILE__, __LINE__, __VA_ARGS__)
#define LOG_WARN(...)  logger(LOG_LEVEL_WARN,  __FILE__, __LINE__, __VA_ARGS__)
#define LOG_ERROR(...) logger(LOG_LEVEL_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define LOG_DEBUG(...) logger(LOG_LEVEL_DEBUG, __FILE__, __LINE__, __VA_ARGS__)


#endif //LOGGER_H
