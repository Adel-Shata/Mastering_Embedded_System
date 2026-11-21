# Interrupt Controller on ATmega32

## Author

**Eng. Adel Shata**

<a href="https://github.com/Adel-Shata"><img src="https://img.shields.io/badge/-GitHub-181717?logo=github&logoColor=white&style=flat-square" alt="GitHub"></a>
<a href="https://www.linkedin.com/in/adel-shata-a1b9a7376/"><img src="https://img.shields.io/badge/-LinkedIn-0A66C2?logo=linkedin&logoColor=white&style=flat-square" alt="LinkedIn"></a>
<a href="mailto:adel.shata.eng@gmail.com"><img src="https://img.shields.io/badge/-Email-D14836?logo=gmail&logoColor=white&style=flat-square" alt="Email"></a>

---

## Lab Objective

Configure the three external interrupts of the **ATmega32** — **INT0**, **INT1**, and **INT2** — to toggle an LED connected to **PD0** on every trigger, using register-level programming and bare-metal ISRs.

### Interrupt Configuration

| Interrupt | Vector | Pin | Sense Control | Configuration |
|---|---|---|---|---|
| INT0 | `__vector_1` | PD2 | Rising edge | `MCUCR \|= (1 << ISC00) \| (1 << ISC01)` |
| INT1 | `__vector_2` | PD3 | Any logical change | `MCUCR \|= (1 << ISC10)` |
| INT2 | `__vector_3` | PB2 | Falling edge | `MCUCSR &= ~(1 << ISC2)` |

- **PD0** is configured as an output (`DDRD |= (1 << 0)`).
- Global interrupts are enabled with `SREG |= (1 << 7)`.
- All three external interrupts are enabled with `GICR |= (0x7 << 5)`.
- Each ISR toggles the LED (`PORTD ^= (1 << 0)`).

### Registers Used

| Register | Purpose |
|---|---|
| `DDRD` | Configure PD0 as output |
| `MCUCR` | Sense control for INT0 and INT1 |
| `MCUCSR` | Sense control for INT2 |
| `GICR` | Enable INT0, INT1, and INT2 |
| `GIFR` | Interrupt flags |
| `SREG` | Global interrupt enable |

### Files

- [`main.c`](main.c) — Register-level implementation of the interrupt controller

---

## Simulation Demo

Screen recording of the Proteus simulation showing the external interrupts toggling the LED on PD0.

<video src="Screen%20Recording%202026-11-21%20115520.mp4" controls width="800"></video>

[Watch the screen recording](Screen%20Recording%202026-11-21%20115520.mp4)
