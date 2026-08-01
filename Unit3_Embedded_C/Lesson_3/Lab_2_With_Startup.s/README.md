# Lab 2 - Bare-Metal LED Blink with Assembly Startup (STM32F103)

A bare-metal embedded C project targeting the **STM32F103** (ARM Cortex-M3) microcontroller. This is the **assembly startup** variant of Lab 2, using an ARM assembly `.s` file for the vector table and reset handler instead of a C-based startup — with no HAL, no CMSIS, and no vendor libraries.

The firmware blinks the onboard LED (PA13) using direct register manipulation, proving full control over the microcontroller from power-on reset through the interrupt vector table and the main application loop.

---

## 🎥 Demo

<p align="center">
  <a href="https://youtu.be/CR9gibXqalM">
    <img
        src="https://img.youtube.com/vi/CR9gibXqalM/maxresdefault.jpg"
        alt="Project Demo"
        width="900">
  </a>
</p>

<p align="center">
<b>▶ Click the image above to watch the demonstration video.</b>
</p>

---

## Features

- **Bare-metal register access** — no HAL, no CMSIS, no SDK dependencies
- **Assembly-based startup file** — vector table and reset handler written in ARM assembly (`.s`)
- **GNU LD linker script** — full control over FLASH/SRAM memory layout and section placement
- **Toolchain abstraction layer** — `toolchain.mk` isolates all compiler/linker/tool paths and flags
- **Modular Makefile** — separate compilation, linking, and post-processing stages
- **Multiple output formats** — `.elf`, `.bin`, `.hex`
- **Diagnostic reports** — symbol table, disassembly, readelf, ELF info, map file
- **Bit-field register access** — demonstrates union/struct-based ODR manipulation
- **Platform types header** — portable volatile and fixed-width type aliases

---

## Architecture

```mermaid
flowchart TD
    subgraph APP["🚀 Application Layer"]
        A1["📄 src/App.c"]
        A2["GPIO init + LED toggle main loop"]
    end

    subgraph STARTUP["⚙️ Startup Layer (Assembly)"]
        S1["📄 startup/startup.s"]
        S2["Vector table (.vectors)"]
        S3["_reset handler"]
        S4["Branch → main()"]
        S5["ARM assembly — no C runtime init"]
    end

    subgraph LINKER["📦 Linker Script Layer"]
        L1["📄 linker/linkerscript.ld"]
        L2["MEMORY regions"]
        L3["SECTIONS layout"]
        L4[".data stays in FLASH (no SRAM relocation)"]
    end

    subgraph TYPES["🧩 Type Abstraction Layer"]
        T1["📄 inc/Platform_Types.h"]
        T2["Fixed-width types"]
        T3["Volatile types"]
        T4["Booleans"]
    end

    APP --> STARTUP --> LINKER --> TYPES

    style APP fill:#1e40af,stroke:#3b82f6,color:#fff
    style STARTUP fill:#065f46,stroke:#10b981,color:#fff
    style LINKER fill:#92400e,stroke:#f59e0b,color:#fff
    style TYPES fill:#581c87,stroke:#a855f7,color:#fff
```

**Design philosophy:** Each layer has a single responsibility. The assembly startup is minimal — it sets the stack pointer, provides the vector table, and branches to `main()`. No `.data` copy or `.bss` zeroing is performed because the linker script places `.data` directly in FLASH.

---

## 📁 Project Structure

```mermaid
flowchart TD
    A["📁 Lab_2_With_Startup.s"]

    A --> B["📄 README.md"]
    A --> C["📄 makefile"]
    A --> D["📄 toolchain.mk"]

    A --> E["📁 src"]
    E --> E1["📄 App.c"]

    A --> F["📁 inc"]
    F --> F1["📄 Platform_Types.h"]

    A --> G["📁 startup"]
    G --> G1["📄 startup.s"]

    A --> H["📁 linker"]
    H --> H1["📄 linkerscript.ld"]

    A --> I["📁 build"]

    I --> I1["📁 objs"]
    I1 --> I2["📁 src"]
    I2 --> I3["📄 App.o"]

    I1 --> I4["📁 startup"]
    I4 --> I5["📄 startup.o"]

    I --> J["📄 output.elf"]
    I --> K["📄 output.bin"]
    I --> L["📄 output.hex"]
    I --> M["📄 mapfile.map"]
    I --> N["📄 output_readelf.txt"]
    I --> O["📄 output_elf_info.txt"]
    I --> P["📄 output_disassembly.txt"]
    I --> Q["📄 output_symbols.txt"]
```

---

## Build System

### Makefiles

| File | Role |
|------|------|
| `makefile` | Top-level build orchestration. Defines directory variables, source file discovery, build rules for compilation, linking, and post-processing (bin, hex, readelf, disassembly, symbols). Includes `toolchain.mk`. |
| `toolchain.mk` | Toolchain abstraction. Defines tool paths (`CC`, `AS`, `LD`, `CP`, `OD`, `RE`, `NM`) and all compiler/assembler/linker flags. Overridable via environment variables or command-line. |

### Toolchain

The default toolchain is the **ARM GCC bare-metal cross-compiler** (`arm-none-eabi-gcc`), configured in `toolchain.mk`:

```makefile
TOOLCHAIN ?= C:/TOOLCHAINS/ARM_TOOLCHAIN/bin/arm-none-eabi-
```

**Overriding the toolchain** (e.g., for Linux or a different installation path):

```bash
# Linux example
make TOOLCHAIN=/usr/bin/arm-none-eabi-

# Custom path
make TOOLCHAIN=/opt/gcc-arm/bin/arm-none-eabi-
```

### Build Flow

```mermaid
flowchart TD
    subgraph SRC["📄 Source Files"]
        S1["src/App.c"]
        S2["startup/startup.s"]
    end

    subgraph COMP["⚙️ Compilation"]
        C1["gcc -c"]
        C2["as"]
    end

    subgraph OBJ["📦 Object Files"]
        O1["App.o"]
        O2["startup.o"]
    end

    subgraph LINK["🔗 Linking"]
        L1["ld -T linkerscript.ld"]
    end

    subgraph ELF["📦 ELF Output"]
        E1["output.elf"]
    end

    subgraph POST["📤 Post-Processing"]
        P1["objcopy → output.bin"]
        P2["objcopy → output.hex"]
        P3["readelf → readelf.txt"]
        P4["objdump → disassembly.txt"]
        P5["nm → symbols.txt"]
    end

    S1 --> C1 --> O1
    S2 --> C2 --> O2
    O1 --> L1
    O2 --> L1
    L1 --> E1
    E1 --> POST

    style SRC fill:#1e40af,stroke:#3b82f6,color:#fff
    style COMP fill:#065f46,stroke:#10b981,color:#fff
    style OBJ fill:#92400e,stroke:#f59e0b,color:#fff
    style LINK fill:#581c87,stroke:#a855f7,color:#fff
    style ELF fill:#be123c,stroke:#f43f5e,color:#fff
    style POST fill:#1e3a5f,stroke:#60a5fa,color:#fff
```

### Output Folders

| Directory | Contents |
|-----------|----------|
| `build/` | All build artifacts (cleaned by `make clean`) |
| `build/objs/` | Compiled `.o` files, preserving source directory structure |

---

## Supported Toolchains

This project is designed for any `arm-none-eabi-` prefixed GCC toolchain. Detected/supported toolchains:

| Toolchain | Platform | Notes |
|-----------|----------|-------|
| `arm-none-eabi-gcc` (ARM GNU Toolchain) | Windows, Linux, macOS | Default. Install via [Arm Developer](https://developer.arm.com/downloads/-/gnu-rm). |
| `C:/TOOLCHAINS/ARM_TOOLCHAIN/bin/arm-none-eabi-` | Windows | Hardcoded default path; override with `TOOLCHAIN=`. |

The build system uses `gcc` for compilation, `as` for assembly, `ld` for linking, `objcopy` for binary/hex generation, `objdump` for disassembly, `readelf` for ELF inspection, and `nm` for symbol listing.

---

## Build Examples

```bash
# Build with default toolchain
make

# Build with custom toolchain path
make TOOLCHAIN=/usr/local/gcc-arm/bin/arm-none-eabi-

# Clean all build artifacts
make clean

# Build with verbose output (uncomment debug lines in makefile)
make 2>&1 | tee build.log

# Inspect memory layout
cat build/mapfile.map

# Inspect symbols
cat build/output_symbols.txt

# Inspect disassembly
cat build/output_disassembly.txt
```

---

## Generated Files

| File | Format | Purpose |
|------|--------|---------|
| `output.elf` | ELF32 (little-endian ARM) | Executable with debug symbols, sections, and headers. Used for debugging. |
| `output.bin` | Raw binary | Flat binary image for flashing at address `0x08000000`. Produced by `objcopy -O binary`. |
| `output.hex` | Intel HEX | ASCII hex representation for flash programmers (ST-Link, OpenOCD, etc.). Produced by `objcopy -O ihex`. |
| `mapfile.map` | Text | Linker memory map showing section placement, sizes, and symbol addresses. |
| `output_readelf.txt` | Text | Full `readelf -a` output: ELF headers, sections, program headers, symbol table, attributes. |
| `output_elf_info.txt` | Text | `objdump -x` output: program headers, section details, symbol table. |
| `output_disassembly.txt` | Text | `objdump -D` full disassembly of all sections (useful for verifying generated code). |
| `output_symbols.txt` | Text | `nm` symbol table listing all symbols with addresses, types, and names. |

---

## Project Workflow

1. **Write application code** in `src/App.c` — configure registers, implement logic.
2. **Write startup code** in `startup/startup.s` — vector table and reset handler in ARM assembly.
3. **Write linker script** in `linker/linkerscript.ld` — define memory regions and section layout.
4. **Configure types** in `inc/Platform_Types.h` — volatile aliases, fixed-width types.
5. **Run `make`** — compiles all source files, links with the linker script, produces `.elf`, `.bin`, `.hex`, and diagnostic reports.
6. **Flash the binary** — use ST-Link, OpenOCD, or any STM32 programmer to write `output.bin` or `output.hex` to address `0x08000000`.
7. **Verify** — observe LED blinking on PA13, or use `output_disassembly.txt` / `mapfile.map` for static analysis.

---

## 📁 Example Project Structure

```mermaid
flowchart TD
    A["📁 Lab_2_With_Startup.s"]

    A --> B["📄 README.md"]
    A --> C["📄 makefile"]
    A --> D["📄 toolchain.mk"]

    A --> E["📁 src"]
    E --> E1["📄 App.c"]

    A --> F["📁 inc"]
    F --> F1["📄 Platform_Types.h"]

    A --> G["📁 startup"]
    G --> G1["📄 startup.s"]

    A --> H["📁 linker"]
    H --> H1["📄 linkerscript.ld"]

    A --> I["📁 build"]

    I --> I1["📁 objs"]
    I1 --> I2["📁 src"]
    I2 --> I3["📄 App.o"]

    I1 --> I4["📁 startup"]
    I4 --> I5["📄 startup.o"]

    I --> J["📄 output.elf"]
    I --> K["📄 output.bin"]
    I --> L["📄 output.hex"]
    I --> M["📄 mapfile.map"]
    I --> N["📄 output_readelf.txt"]
    I --> O["📄 output_elf_info.txt"]
    I --> P["📄 output_disassembly.txt"]
    I --> Q["📄 output_symbols.txt"]
```

---

## Folder Description

| Folder | Description |
|--------|-------------|
| `src/` | Application source files. Contains `main()` and all application-level logic. Only `App.c` exists currently. |
| `inc/` | Header files. Contains platform-specific type definitions shared across all source files. |
| `startup/` | Startup code. Contains the ARM assembly vector table and reset handler that initializes the stack pointer before calling `main()`. |
| `linker/` | Linker scripts. Contains GNU LD scripts that define the memory map (FLASH, SRAM) and section placement. |
| `build/` | Build output. All generated artifacts (`.o`, `.elf`, `.bin`, `.hex`, reports) are placed here. Cleaned by `make clean`. |
| `build/objs/` | Object files. Mirrors the source directory structure (`src/`, `startup/`). |

---

## Important Source Files

### `src/App.c`

The main application file. Responsibilities:

- **Register definitions** — defines `RCC_BASE`, `GPIOA_BASE`, `RCC_APB2ENR`, and `GPIOA_CHR` as memory-mapped register addresses using pointer dereference macros.
- **Bit-field union** — `R_ODR_t` union with a `pin` struct allowing individual bit access (specifically `P13`) alongside full 32-bit access.
- **Global variables** — `g_vars[3]` (mutable, goes to `.data`) and `g_const_vars[3]` (const, goes to `.rodata`).
- **`main()` function** — enables GPIOA clock via RCC, configures PA13 as push-pull output (2 MHz), then toggles PA13 in an infinite loop with a busy-wait delay.

### `startup/startup.s`

The ARM assembly startup file. Responsibilities:

- **Stack pointer initialization** — hardcodes `0x20001000` as the initial stack pointer (4 KB into SRAM).
- **Interrupt vector table** — placed in `.vectors` section (mapped to address `0x08000000` via the linker script). Contains: initial SP, Reset handler, NMI, HardFault, MemoryManagement, BusFault, UsageFault, SVCall, PendSV, SysTick, and external interrupt handlers. All exception handlers share the same `_vector_handler` label.
- **`_reset` label** — branches to `main()` using `bl main`, then enters an infinite loop (`b .`) if `main()` returns.
- **`_vector_handler` label** — branches to `_reset`, effectively restarting the system on any exception.

### `inc/Platform_Types.h`

Platform abstraction header. Provides:

- Boolean type (`_Bool` → `boolean`) with `TRUE`/`FALSE` macros
- Signed and unsigned fixed-width types (`sint8`–`sint64`, `uint8`–`uint64`)
- `volatile` qualified variants (`vint8_t`–`vint64_t`, `vuint8_t`–`vuint64_t`, `vfloat32_t`, `vdouble64_t`)
- Floating-point aliases (`float32_t`, `double64_t`)

> **Note:** This variant uses `_t` suffixed volatile types (`vuint32_t`) while the C startup variant uses non-suffixed types (`vuint32`). The `App.c` source in this project uses `vuint32_t` to match.

### `linker/linkerscript.ld`

GNU LD linker script. Defines:

- **MEMORY regions** — `flash` at `0x08000000` (128 KB), `sram` at `0x20000000` (20 KB)
- **SECTIONS** — `.text` (vectors + code + rodata → flash), `.data` (initialized data → flash), `.bss` (zero-initialized data → sram)

> **Key difference from C startup variant:** This linker script does **not** export `_E_text`, `_S_data`, `_E_data`, `_S_bss`, `_E_bss`, or `_stack_top` symbols. The `.data` section remains in FLASH (no SRAM copy), and there is no explicit stack reservation via linker symbols.

### `toolchain.mk`

Toolchain configuration file. Defines:

- Tool paths: `CC`, `AS`, `LD`, `CP`, `OD`, `RE`, `NM`
- Compiler flags: `-c -Wall -Wextra -Werror -mcpu=cortex-m3 -g -gdwarf-3 -O0`
- Assembler flags: `-mcpu=cortex-m3 -g -gdwarf-2`
- Linker flags: `-T linkerscript.ld -Map=mapfile.map`
- Binary output flags: `-O binary`, `-O ihex`
- Readelf flags: `-a`

### `makefile`

Top-level build Makefile. Responsibilities:

- Discovers source files via `wildcard` in `src/` and `startup/`
- Computes object file paths preserving directory structure
- Includes `toolchain.mk`
- Builds: compilation → linking → bin/hex/readelf/disassembly/symbols generation
- `clean` target removes entire `build/` directory

---

## Design Decisions

1. **Assembly startup over C startup** — The startup file is written in ARM assembly, providing the most minimal possible startup sequence. No C runtime initialization (`.data` copy, `.bss` zero) is performed. This is ideal for educational purposes and for projects where the linker script places `.data` directly in FLASH.

2. **Shared exception handler** — All fault/exception handlers point to the same `_vector_handler` label, which branches to `_reset`. This provides a simple "restart on fault" behavior. For production code, dedicated handlers with infinite loops would be more appropriate.

3. **Stack pointer hardcoded in assembly** — The initial SP is set to `0x20001000` (4 KB into the 20 KB SRAM) directly in the vector table. This differs from the C startup variant which derives the stack top from linker symbols.

4. **`.data` in FLASH** — The linker script places `.data` in FLASH rather than SRAM. This means initialized global variables are read directly from FLASH, eliminating the need for a `.data` copy routine in the startup code. This is a trade-off: simpler startup but slower variable access.

5. **Toolchain abstraction via `toolchain.mk`** — All toolchain-specific paths and flags are isolated in `toolchain.mk`, making it trivial to switch compilers or platforms without modifying the main `makefile`.

6. **No HAL or CMSIS** — The project uses raw register addresses and pointer dereference macros. This is intentional for educational purposes: it forces understanding of the memory-mapped I/O model and the ARM Cortex-M3 memory map.

7. **Busy-wait delays** — The LED blink uses simple `for` loop delays rather than SysTick or timers. This keeps the focus on GPIO register manipulation and avoids timer interrupt complexity.

---

## Customization

### Adding New Source Files

1. Place `.c` files in `src/` — they are auto-discovered by the Makefile via `wildcard`.
2. Place `.h` files in `inc/`.
3. Include headers in your source: `#include "YourHeader.h"`.
4. Run `make` — no Makefile changes needed.

### Adding New Modules

For multi-file modules (e.g., a UART driver):

1. Create a subdirectory: `src/drivers/`
2. Place source files there: `src/drivers/uart.c`, `src/drivers/uart.h`
3. Add the include path in `toolchain.mk`: `CFLAGS += -I inc/drivers`
4. The Makefile's `wildcard` will pick up all `.c` files in `src/` and its subdirectories.

> **Note:** The current Makefile uses `wildcard $(src_dir)*.c` which only matches files directly in `src/`, not subdirectories. To support subdirectories, change the wildcard to `$(wildcard $(src_dir)**/*.c)` or use `$(shell find $(SRC_DIR) -name '*.c')`.

### Adding New Toolchains

1. Create a new file (e.g., `toolchain_iar.mk` or `toolchain_armcc.mk`).
2. Define the tool paths and flags for the new toolchain.
3. Override the toolchain from the command line: `make -f makefile TOOLCHAIN_IAR=1`

### Adding New Linker Scripts

1. Place the new linker script in `linker/` (e.g., `linkerscript_custom.ld`).
2. Override the linker script via the command line or modify `LDFLAGS` in `toolchain.mk`.

### Adding New Startup Files

The startup directory supports both `.c` and `.s` files. To add a custom assembly startup:

1. Place the `.s` file in `startup/`.
2. The Makefile will compile it using the assembler (`AS`) with `ASFLAGS`.
3. Both C and Assembly startup files are supported simultaneously (the Makefile handles both extensions).

---

## Requirements

### Toolchain

- **ARM GCC Cross-Compiler** (`arm-none-eabi-gcc`): Required for compilation, assembly, and linking.
  - Download: [Arm GNU Toolchain](https://developer.arm.com/downloads/-/gnu-rm)
  - Or install via package manager: `sudo apt install gcc-arm-none-eabi` (Linux)

### Build Utilities

- **GNU Make** — build orchestration
- **GNU Binutils** — `objcopy`, `objdump`, `readelf`, `nm` (included with the toolchain)

### Hardware

- **STM32F103** development board (e.g., Blue Pill, Nucleo, or custom board)
- **ST-Link V2** or compatible SWD programmer for flashing
- LED connected to PA13 (most Blue Pill boards have an onboard LED on this pin)

### Optional

- **OpenOCD** — for command-line flashing: `openocd -f interface/stlink.cfg -f target/stm32f1x.cfg -c "program output.elf verify reset exit"`
- **STM32CubeProgrammer** — GUI-based flashing via `.hex` or `.bin` files

---

## Code Quality Notes

### Bugs and Issues

1. **No `.data` relocation** — The linker script places `.data` in FLASH, meaning initialized global variables (`g_vars`, `g_const_vars`) are stored in FLASH. If the application modifies `g_vars`, the changes will not persist across resets (the original values are in FLASH). This works for the current code since `g_vars` is never written to, but it would be a bug if someone tried to use `g_vars` as mutable storage.

2. **No `.bss` zeroing** — The startup code does not zero the `.bss` section. Uninitialized globals will contain whatever value is in SRAM at boot. This works for the current code but is a latent issue.

3. **Stack pointer not linker-derived** — The stack top is hardcoded to `0x20001000` in the assembly vector table. If the SRAM size or memory layout changes, this value must be manually updated. The C startup variant derives it from the linker script.

4. **`_vector_handler` restarts instead of halting** — On any fault, the handler branches to `_reset`, which re-branches to `main()`. This can mask intermittent faults. A more robust approach would be an infinite loop for fault handlers.

5. **`main()` has unreachable `return 0`** — The `while(1)` loop is infinite, so the `return 0` after the loop can never execute.

6. **Vector table has limited external interrupt entries** — Only 4 external interrupt vectors (indices 16–19) are provided. The STM32F103 has 67 external interrupts (EXTI0 through DMA2_Channel4_3). Any interrupt beyond index 19 will cause a hard fault.

### Bad Practices

- **Magic numbers** — Register addresses (`0x40021000`, `0x40010800`) and offsets (`0x18`, `0x04`, `0x0C`) are raw hex. Using named macros or an SVD-generated header would improve readability.
- **Bit manipulation clarity** — `GPIOA_CHR &= 0xff0fffff; GPIOA_CHR |= 0x00200000;` would benefit from named bit-field definitions for CNFy and MODEy fields.
- **Busy-wait delay** — The `for(uint16 i = 0; i < 10000; i++);` delay is compiler-dependent and will vary with optimization level. A `volatile` loop counter or a timer-based delay would be more reliable.
- **Stack size not linker-controlled** — The 4 KB stack is hardcoded in assembly. Best practice is to define it in the linker script for visibility and easy adjustment.

### Positive Observations

- Clean separation of concerns across files
- Proper use of `volatile` for hardware registers
- Toolchain abstraction is well-implemented
- Diagnostic output generation is thorough
- Minimal startup code — easy to understand and audit
- Bit-field union pattern for GPIO ODR is a common and practical embedded C idiom

---

## Comparison: Assembly Startup vs C Startup

| Aspect | Assembly Startup (this project) | C Startup (Lab_2_With_Startup.c) |
|--------|--------------------------------|----------------------------------|
| Startup language | ARM Assembly (`.s`) | C (`.c`) |
| `.data` relocation | None — stays in FLASH | Copied from FLASH to SRAM |
| `.bss` zeroing | None | Zeroed in SRAM |
| Stack pointer | Hardcoded in assembly (`0x20001000`) | Derived from linker script (`_stack_top`) |
| Linker symbols | Minimal (no section boundary exports) | Exports `_E_text`, `_S_data`, `_E_data`, `_S_bss`, `_E_bss`, `_stack_top` |
| Complexity | Very low — 36 lines of assembly | Moderate — 68 lines of C |
| Fault handling | All faults → restart | All faults → restart (re-init) |
| Use case | Educational, minimal boot | Production-ready startup |

---

## Memory Layout (STM32F103)

```mermaid
block-beta
    columns 2

    block:FLASH:1
        columns 1
        F1["📦 FLASH (128 KB)\n0x08000000"]
        F2["📄 .vectors (76 B)\nInterrupt Vector Table"]
        F3["📄 .text (varies)\nApplication Code"]
        F4["📄 .rodata (3 B)\nConstant Data"]
        F5["📄 .data (3 B)\nInitialized Variables (IN FLASH)"]
        F6["📄 0x0801FFFF"]
    end

    block:SRAM:1
        columns 1
        S1["📦 SRAM (20 KB)\n0x20000000"]
        S2["📄 .bss (0 B)\nZero-initialized Data"]
        S3["📚 stack (4 KB)"]
        S4["📍 _stack_top\n(hardcoded 0x20001000)"]
        S5["📄 0x20004FFF"]
    end

    style FLASH fill:#dc2626,stroke:#ef4444,color:#fff
    style SRAM fill:#2563eb,stroke:#3b82f6,color:#fff
    style F1 fill:#991b1b,stroke:#dc2626,color:#fff
    style F2 fill:#7f1d1d,stroke:#991b1b,color:#fff
    style F3 fill:#7f1d1d,stroke:#991b1b,color:#fff
    style F4 fill:#7f1d1d,stroke:#991b1b,color:#fff
    style F5 fill:#7f1d1d,stroke:#991b1b,color:#fff
    style F6 fill:#7f1d1d,stroke:#991b1b,color:#fff
    style S1 fill:#1e40af,stroke:#2563eb,color:#fff
    style S2 fill:#1e3a5f,stroke:#1e40af,color:#fff
    style S3 fill:#1e3a5f,stroke:#1e40af,color:#fff
    style S4 fill:#1e3a5f,stroke:#1e40af,color:#fff
    style S5 fill:#1e3a5f,stroke:#1e40af,color:#fff
```

| Symbol | Address | Description |
|--------|---------|-------------|
| `_stack_top` | `0x20001000` | Top of stack (hardcoded in assembly, 4 KB into SRAM) |
| `vectors` | `0x08000000` | Start of interrupt vector table |
| `_reset` | `0x0800004C` | Reset handler entry point (after vector table) |
| `main` | `0x08000054` | Application entry point |
| `_vector_handler` | `0x08000058` | Default exception handler (branches to `_reset`) |

> **Note:** Exact addresses depend on the compiled output. Check `build/output_symbols.txt` for definitive values.

---

## Startup Sequence

```mermaid
flowchart TD
    A["🔌 Power-On / Reset"] --> B["📖 CPU reads SP from vectors[0]\n(hardcoded 0x20001000)"]
    B --> C["📖 CPU reads PC from vectors[1]\n→ _reset (0x0800004C)"]
    C --> D

    subgraph RESET["⚙️ _reset (Assembly)"]
        R1["📞 bl main\nbranch to main()"]
        R2["🔁 b .\ninfinite loop (if main returns)"]
        R1 --> R2
    end

    D --> RESET

    R1 --> E

    subgraph MAIN["🚀 main()"]
        M1["🔧 Enable GPIOA clock\n(RCC_APB2ENR |= 1 << 2)"]
        M2["🔧 Configure PA13 as push-pull output\n(GPIOA_CHR)"]
        M3["🔁 Infinite loop: toggle PA13 with delay"]
        M1 --> M2 --> M3
    end

    E --> MAIN

    style A fill:#dc2626,stroke:#ef4444,color:#fff
    style B fill:#1e40af,stroke:#3b82f6,color:#fff
    style C fill:#1e40af,stroke:#3b82f6,color:#fff
    style RESET fill:#065f46,stroke:#10b981,color:#fff
    style MAIN fill:#92400e,stroke:#f59e0b,color:#fff
```

