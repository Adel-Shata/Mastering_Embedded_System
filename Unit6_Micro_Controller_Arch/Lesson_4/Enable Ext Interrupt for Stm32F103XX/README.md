# Enable External Interrupt for STM32F103XX

## Author

**Eng. Adel Shata**

<a href="https://github.com/Adel-Shata"><img src="https://img.shields.io/badge/-GitHub-181717?logo=github&logoColor=white&style=flat-square" alt="GitHub"></a>
<a href="https://www.linkedin.com/in/adel-shata-a1b9a7376/"><img src="https://img.shields.io/badge/-LinkedIn-0A66C2?logo=linkedin&logoColor=white&style=flat-square" alt="LinkedIn"></a>
<a href="mailto:adel.shata.eng@gmail.com"><img src="https://img.shields.io/badge/-Email-D14836?logo=gmail&logoColor=white&style=flat-square" alt="Email"></a>

---

## Lab Objective

Configure **EXTI0** on the **STM32F103C8** to detect a **rising edge on PA0** (push button) and toggle the LED connected to **PA13** inside the interrupt handler (`EXTI0_IRQHandler`), using register-level programming without any HAL drivers.

### Hardware Setup (Proteus)

- STM32F103C8 microcontroller
- Push button on **PA0** with a 10 kΩ pull-down resistor and a 100 nF debounce capacitor
- LED with a 0.3 kΩ current-limiting resistor on **PA13**
- **NRST** tied to VDD

### Registers Used

| Register | Purpose |
|---|---|
| `RCC_APB2ENR` | Enable the clocks of AFIO and GPIOA |
| `GPIOA_CRH` | Configure PA13 as a general-purpose output |
| `AFIO_EXTICR1` | Map PA0 to EXTI line 0 |
| `EXTI_IMR` | Unmask EXTI line 0 |
| `EXTI_RTSR` | Enable the rising-edge trigger on EXTI line 0 |
| `EXTI_PR` | Clear the pending flag inside the ISR |
| `NVIC_ISER0` | Enable the EXTI0 interrupt (IRQ6) in the NVIC |

### Files

- [`main.c`](main.c) — Register-level implementation of the external interrupt

---

## Proteus Simulation & Code

The push button is connected to PA0, the LED to PA13, and the `EXTI0_IRQHandler` toggles PA13 then clears the EXTI pending flag.

![Proteus schematic with EXTI0_IRQHandler code](Screenshot%202026-11-19%20153151.png)

---

## Simulation Running

After pressing the button, EXTI0 fires and the LED turns on.

![Simulation running - LED on](Screenshot%202026-11-19%20153207.png)

---

## Debugger Verification (Keil)

### 1. Before the Interrupt

EXTI line 0 is unmasked, the rising trigger is enabled (`EXTI_RTSR = 0x1`), and no interrupt is pending yet (`EXTI_PR = 0x0`).

![Keil debug - EXTI0 armed, no pending request](Screenshot%202026-11-19%20153239.png)

### 2. Interrupt Triggered

Pressing the button raises the pending flag of EXTI line 0 (`EXTI_PR = 0x1`) and the CPU enters Handler mode.

![Keil debug - EXTI0 pending flag raised](Screenshot%202026-11-19%20153249.png)

### 3. Inside the ISR

`EXTI0_IRQHandler` toggles PA13 (`GPIOA_ODR = 0x00002000`) and clears the pending flag (`EXTI_PR = 0x0`).

![Keil debug - PA13 toggled and pending flag cleared](Screenshot%202026-11-19%20153308.png)
