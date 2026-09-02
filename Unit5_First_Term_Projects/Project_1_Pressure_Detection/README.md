# Pressure Controller — Bare-Metal STM32F103C6

## Author

**Eng. Adel Shata**

<a href="https://github.com/Adel-Shata"><img src="https://img.shields.io/badge/-GitHub-181717?logo=github&logoColor=white&style=flat-square" alt="GitHub"></a>
<a href="https://www.linkedin.com/in/adel-shata-a1b9a7376/"><img src="https://img.shields.io/badge/-LinkedIn-0A66C2?logo=linkedin&logoColor=white&style=flat-square" alt="LinkedIn"></a>
<a href="mailto:adel.shata.eng@gmail.com"><img src="https://img.shields.io/badge/-Email-D14836?logo=gmail&logoColor=white&style=flat-square" alt="Email"></a>

---

## Overview

A bare-metal embedded C project targeting an **STM32F103C6** (ARM Cortex-M3) microcontroller, simulated in Proteus VSM. The system monitors cabin pressure and triggers an alarm when a configurable threshold is exceeded, following SysML/UML modelling done in TTool.

The software is decomposed into four independent blocks, each implemented as a separate `.c`/`.h` module with file-scope (`static`) state and explicit interface functions — mirroring the AVATAR/TTool block diagram signals. The project includes a custom linker script and startup file written from scratch (no HAL, no CMSIS).

---

## Case Study

**Scenario:** Monitor aircraft cabin pressure and alert the crew when pressure exceeds safe limits.

| Parameter | Value |
|-----------|-------|
| Target MCU | STM32F103C6 (ARM Cortex-M3) |
| Pressure threshold | 20 bar |
| Alarm duration | 60 seconds |
| Sensor input | GPIOA PA0–PA7 (8-bit DIP-switch bank) |
| Alarm output | PA13 (active-low LED) |

---

## System Architecture

The system is decomposed into four independent blocks, each as a separate `.c`/`.h` module:

| Module | Responsibility | Interface Functions |
|--------|----------------|---------------------|
| `Pressure_Sensor_Driver` | Reads raw pressure from hardware (GPIO) | `pressureSensorInit()`, `pressureSensorRead()` |
| `High_Pressure_Detection` | Compares reading against threshold, raises flag | `highPressureDetectionfsmTick()`, `highPressureDetected()` |
| `Alarm` | Reacts to high-pressure flag, drives alarm for 60s | `alarmfsmTick()` |
| `Alarm_Actuator_Driver` | Reactive actuator driver; turns alarm on/off | `alarmActuatorInit()`, `alarmActuatorOn()`, `alarmActuatorOff()` |

**Communication model:** All blocks communicate through explicit interface functions declared in their headers. There are no shared global variables between blocks — each block's internal state is kept `static` (file-scope only). The system runs a single super-loop that calls each block's tick function synchronously.

### Block Diagram (TTool)

![System Block Diagram](Screen_Shots/Block_Digram.png)

---

## Design Documentation (TTool / SysML / UML)

Full SysML/UML diagrams were produced in TTool and are included below.

### Requirement Diagram

![Requirement Diagram](Screen_Shots/Requirement_Digram.png)

### Use Case Diagram

![Use Case Diagram](Screen_Shots/Use_Case_Digram.png)

### Activity Diagram

![Activity Diagram](Screen_Shots/Activity_Digram.png)

### Sequence Diagram

![Sequence Diagram](Screen_Shots/Sequence_Digram.png)

---

## State Machine Diagrams

Each software block has a corresponding state machine diagram modelled in TTool.

### Pressure Sensor Driver

![State Machine — Pressure Sensor Driver](Screen_Shots/State_Machine_Of_Pressure_Sensor_Driver.png)

| State | Description |
|-------|-------------|
| `PRESSURE_SENSOR_INIT` | Initial state after `pressureSensorInit()` |
| `PRESSURE_SENSOR_IDLE` | Waiting for read request |
| `PRESSURE_SENSOR_READING` | Actively reading pressure value from GPIO |

### High Pressure Detection

![State Machine — High Pressure Detection](Screen_Shots/State_Machine_Of_HIgh_Pressure_Detection.png)

| State | Description |
|-------|-------------|
| `PRESSURE_READING` | Call `pressureSensorRead()` to get current value |
| `PRESSURE_CHECKING` | Compare reading against `HIGH_PRESSURE_THRESHOLD` (20) |
| `PRESSURE_READING_WAITING` | Wait 1 second before next reading cycle |

### Alarm

![State Machine — Alarm](Screen_Shots/State_Machine_Of_Alarm.png)

| State | Description |
|-------|-------------|
| `ALARM_OFF` | Alarm inactive; check `highPressureDetected()` |
| `ALARM_ON` | Alarm active; call `alarmActuatorOn()` |
| `ALARM_WAITING` | Wait 60 seconds (`delay(60000)`) before turning off |

### Alarm Actuator Driver

![State Machine — Alarm Actuator Driver](Screen_Shots/State_Machine_Of_Alarm_Actuator_Driver.png)

| State | Description |
|-------|-------------|
| `ALARM_ACTUATOR_INIT` | Initial state after `alarmActuatorInit()` |
| `ALARM_ACTUATOR_WAITING` | Ready to accept on/off commands |
| `ALARM_ACTUATOR_ON` | Alarm output active (PA13 LOW) |
| `ALARM_ACTUATOR_OFF` | Alarm output inactive (PA13 HIGH) |

---

## Source Code

### `main.c`

![main.c](Screen_Shots/main_c.png)

The entry point. Calls `setup()` to initialize all modules, then runs a super-loop calling `alarmfsmTick()` and `highPressureDetectionfsmTick()` repeatedly.

### Low-Level Driver — `driver.c` / `driver.h`

![driver.c](Screen_Shots/driver_c.png)
![driver.h](Screen_Shots/DRIVER_h.png)

Hardware abstraction layer. Provides:
- `gpioInit()` — configure GPIOA (enable clock, set pin modes)
- `getPressureVal()` — read 8-bit value from GPIOA_IDR
- `setAlarmActuator(int i)` — control PA13 (active-low)
- `delay(int nCount)` — busy-wait delay loop
- Register macros: `SET_BIT`, `RESET_BIT`, `TOGGLE_BIT`, `READ_BIT`

### Pressure Sensor Driver — `Pressure_Sensor_Driver.c` / `.h`

![Pressure_Sensor_Driver.c](Screen_Shots/Pressure_Sensor_Driver_c.png)
![Pressure_Sensor_Driver.h](Screen_Shots/PRESSURE_SENSOR_DRIVER_h.png)

FSM-based driver that reads pressure from hardware. Transitions: `IDLE → READING → getPressureVal() → IDLE`.

### High Pressure Detection — `High_Pressure_Detection.c` / `.h`

![High_Pressure_Detection.c](Screen_Shots/High_Pressure_Detection_c.png)
![High_Pressure_Detection.h](Screen_Shots/HIGH_PRESSURE_DETECTION_h.png)

FSM that reads pressure, compares against threshold (20 bar), and sets the `PRESSURE_HIGH` / `PRESSURE_NOT_HIGH` flag. Includes 1-second delay between readings.

### Alarm — `Alarm.c` / `.h`

![Alarm.c](Screen_Shots/Alarm_c.png)
![Alarm.h](Screen_Shots/ALARM_H.png)

FSM that monitors the high-pressure flag and controls the alarm for 60 seconds. Transitions: `OFF → ON → WAITING (60s) → OFF`.

### Alarm Actuator Driver — `Alarm_Actuator_Driver.c` / `.h`

![Alarm_Actuator_Driver.c](Screen_Shots/Alarm_Actuator_Driver_c.png)
![Alarm_Actuator_Driver.h](Screen_Shots/ALARM_ACTUATOR_DRIVER_h.png)

Reactive driver that controls the physical alarm output. Only accepts commands when in `WAITING` state.

---

## Startup & Linker

### Linker Script — `linkerscript.ld`

![Linker Script](Screen_Shots/Linker.png)

Custom GNU LD linker script defining:
- **FLASH:** `0x08000000`, 128 KB
- **SRAM:** `0x20000000`, 20 KB
- Sections: `.text` (vectors + code + rodata → flash), `.data` (initialized → SRAM, load in flash), `.bss` (zero-initialized → SRAM)
- `_stack_top = . + 1000`

### Startup File — `startup.c` (Page 1)

![Startup — Vector Table](Screen_Shots/StartUp_P1.png)

Custom C-based startup file. Defines the interrupt vector table with weak aliases for all fault handlers (default: reset on any fault).

### Startup File — `startup.c` (Page 2)

![Startup — Reset Handler](Screen_Shots/StartUp_P2.png)

`Reset_Handler()` — copies `.data` from FLASH to SRAM, zeros `.bss`, then calls `main()`.

---

## Build System

This project is built using a custom, reusable Makefile build engine maintained as a separate repository:

**[Universal_Make_Engine](https://github.com/Adel-Shata/Universal_Make_Engine.git)**

Consult the linked repository for full documentation on configuration, usage, and available build options.

---

## Simulation

The project was verified in **Proteus VSM** with a DIP-switch bank simulating the pressure sensor input and an LED simulating the alarm actuator output.

### High Pressure Detected (pressure = 26, threshold = 20)

![Simulation — Alarm ON](Screen_Shots/Proteus.png)

When the pressure reading (26) exceeds the threshold (20):
- `pressureValue` = `PRESSURE_HIGH (1)`
- `alarmState` = `ALARM_WAITING (2)`
- `ALARM_ACTUATOR_STATE` = `ALARM_ACTUATOR_WAITING (2)`
- Alarm LED (D2) is **ON**

### Normal Pressure (pressure = 18, threshold = 20)

![Simulation — Alarm OFF](Screen_Shots/Proteus%20(2).png)

When the pressure reading (18) is below the threshold (20):
- `pressureValue` = `PRESSURE_NOT_HIGH (0)`
- `alarmState` = `ALARM_OFF (0)`
- `ALARM_ACTUATOR_STATE` = `ALARM_ACTUATOR_OFF (0)`
- Alarm LED (D2) is **OFF**

### Debug Watch Variables

| Variable | Module | Description |
|----------|--------|-------------|
| `pressureSensorState` | `Pressure_Sensor_Driver.c` | `PRESSURE_SENSOR_IDLE (0)` / `PRESSURE_SENSOR_READING` |
| `pressureDetectionState` | `High_Pressure_Detection.c` | `PRESSURE_READING (0)` / `PRESSURE_CHECKING (1)` / `PRESSURE_READING_WAITING (2)` |
| `alarmState` | `Alarm.c` | `ALARM_OFF (0)` / `ALARM_ON` / `ALARM_WAITING (2)` |
| `ALARM_ACTUATOR_STATE` | `Alarm_Actuator_Driver.c` | `ALARM_ACTUATOR_OFF (0)` / `ALARM_ACTUATOR_ON` / `ALARM_ACTUATOR_WAITING (2)` |
| `pressure` | `High_Pressure_Detection.c` | Current raw pressure reading |
| `pressureValue` | `High_Pressure_Detection.c` | `PRESSURE_NOT_HIGH (0)` / `PRESSURE_HIGH (1)` |

---

## Repository Structure

```mermaid
flowchart TD
    A["📁 Project_1_Pressure_Detection"]

    A --> B["📄 makefile"]
    A --> C["📄 toolchain.mk"]

    A --> E["📁 src"]
    E --> E1["📄 main.c"]
    E --> E2["📄 High_Pressure_Detection.c"]
    E --> E3["📄 Alarm.c"]
    E --> E4["📁 driver"]
    E4 --> E5["📄 driver.c"]
    E4 --> E6["📄 Pressure_Sensor_Driver.c"]
    E4 --> E7["📄 Alarm_Actuator_Driver.c"]

    A --> F["📁 inc"]
    F --> F1["📄 Platform_Types.h"]
    F --> F2["📄 High_Pressure_Detection.h"]
    F --> F3["📄 Alarm.h"]
    F --> F4["📁 driver"]
    F4 --> F5["📄 driver.h"]
    F4 --> F6["📄 Pressure_Sensor_Driver.h"]
    F4 --> F7["📄 Alarm_Actuator_Driver.h"]

    A --> G["📁 startup"]
    G --> G1["📄 startup.c"]

    A --> H["📁 linker"]
    H --> H1["📄 linkerscript.ld"]

    A --> I["📁 Screen_Shots"]
    I --> I1["UML/SysML diagrams"]
    I --> I2["Code screenshots"]
    I --> I3["Proteus simulation"]

    A --> J["📁 build"]

    style A fill:#1e40af,stroke:#3b82f6,color:#fff
    style E fill:#065f46,stroke:#10b981,color:#fff
    style F fill:#581c87,stroke:#a855f7,color:#fff
    style G fill:#92400e,stroke:#f59e0b,color:#fff
    style H fill:#991b1b,stroke:#f43f5e,color:#fff
    style I fill:#1e3a5f,stroke:#60a5fa,color:#fff
```



