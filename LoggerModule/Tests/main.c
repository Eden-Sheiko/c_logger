#include "../Inc/Logger.h"

static const char* Tag = "LINUX";

int main(void) {
    logger_init();

    // === Basic test for each level ===
    logger(LOG_LEVEL_INFO,  "SYS",    "System started successfully");
    logger(LOG_LEVEL_WARN,  "MEM",    "Memory usage is high: %d%%", 85);
    logger(LOG_LEVEL_ERROR, "SENSOR", "Failed to read from sensor ID %d", 3);
    logger(LOG_LEVEL_DEBUG, "NET",    "Packet count: %d, dropped: %d", 1024, 12);

    // === Edge test: unknown level ===
    logger(999, "MISC", "Unknown log level test");

    // === Empty tag and message ===
    logger(LOG_LEVEL_INFO, "", "");

    return 0;

}