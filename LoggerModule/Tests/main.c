#include "../Inc/Logger.h"

static const char* Tag = "LINUX";

int main(void) {
    int a = 5;
    logger(LOG_LEVEL_INFO,Tag,"%d",a);

}