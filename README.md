# C Logger Module – Version 1.0

A lightweight and modular C logging utility built for portability and simplicity.  
Supports multiple log levels and custom tags, making it easy to trace messages across your system.

---

## Features – v1.0

- Log levels: `INFO`, `WARN`, `ERROR`, `DEBUG`
- Tag support: Identify source of log (e.g., `SENSOR`, `NET`, `SYS`)
- Variadic argument support (`printf`-style formatting)
- Clean and reusable design
- Pure C, no external dependencies

---

## Example Output

```text
[INFO][SYS] System initialized
[WARN][BATTERY] Low battery: 20%
[ERROR][SENSOR] Failed to read sensor ID 4
[DEBUG][NET] Packet count: 1024, dropped: 3
[UNKNOWN][MISC] Unknown log level test
```

---

## Usage

### Include in your project:

```c
#include "Logger.h"
```

### Initialize logger (currently a placeholder):

```c
logger_init();
```

### Log messages:

```c
logger(LOG_LEVEL_INFO,  "SYS",    "System started");
logger(LOG_LEVEL_WARN,  "MEM",    "Memory usage: %d%%", 85);
logger(LOG_LEVEL_ERROR, "I2C",    "Bus error on address %s", "0x48");
logger(LOG_LEVEL_DEBUG, "NET",    "Ping response time: %dms", 27);
```

---

## Folder Structure

```
LoggerModule/
├── Build/        # Makefile for building
├── Inc/          # Logger.h (public interface)
├── Src/          # Logger.c (implementation)
├── Tests/        # main.c (test/demo)
├── README.md     # This file
├── LICENSE
```

---

## Build Instructions

From inside the `LoggerModule/Build` directory:

```bash
make            # Compiles logger.c + main.c → logger_test
./logger_test   # Run the example
make clean      # Remove compiled binary
```

---

## Roadmap – Coming in v2.x

Planned improvements for upcoming versions:

- Thread-safe logging (using `pthread_mutex` or platform-specific locks)
- Color-coded logs (ANSI escape codes for terminal readability)
- File logging support (`logfile.log`)
- Embedded-friendly mode (UART output, printf-less version)
- Unit test support (capture output, validate logs)
- Build modes (`DEBUG`, `RELEASE`)

---

## License

MIT License – use it freely in commercial or open source projects.  
See the `LICENSE` file for details.

---

## Author

Made by Eden  
Feedback, PRs, and improvements are welcome!

