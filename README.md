# STM32F411CEU6 Black Pill Baremetal Workspace

A collection of bare-metal example projects for the STM32F411CEU6 “Black Pill” development board. Each folder illustrates a low-level peripheral demonstration written in C and Assembly (Makefile-based build), without using any HAL or RTOS.

## Repository Contents

- **.vscode/**
VS Code C/C++ properties and debug configuration files.
- **0_led_toggle_addr/**
LED toggle using direct register addresses and pointer structs.
- **1_led_toggle_addr_struct/**
LED toggle via a user-defined GPIO configuration struct.
- **2_gpio_output/**
GPIO basic output toggle implementation.
- **3_gpio_bsrr/**
GPIO control using the BSRR register for atomic pin set/reset.
- **4_gpio_output/**
Alternate GPIO output example (duplicate of “2_gpio_output” structure).
- **5_uart_tx/**
UART transmit only example (USART2 at 115200 baud).
- **6_uart_printf/**
Retargeted `printf` over UART with minimal syscall stub.
- **7_uart_modular/**
Modularized UART driver example (separate `uart.h`/`uart.c`).
- **8_uart_rx/**
UART receive and echo example.
- **9_adc_single_conversion/**
Single-conversion ADC reading with polling.
- **10_adc_continous_conversion/**
Continuous ADC conversion with DMA disabled (polling).
- **11_Systick_delay/**
SysTick-based millisecond delay implementation.
- **12_Timers/**
Timer-based PWM (TIM2) and periodic interrupts (TIM3) demos.
- **13_Output_Compare/**
Timer output-compare mode example (TIM2).
- **14_output_capture/**
Timer input-capture mode example (TIM3).
- **15_input_interrupt/**
External interrupt (EXTI) configuration for user button.


## Prerequisites

- GNU Arm Embedded Toolchain (`arm-none-eabi-gcc`, `make`)
- OpenOCD (for flashing via ST-Link)
- `make` and Unix-style shell (Linux, macOS, WSL)
- ST-Link/V2-compatible programmer


## Building

1. Install prerequisites.
2. Open a terminal in the repository root.
3. Enter the example folder, e.g.:

```sh
cd 5_uart_tx
```

4. Build the project:

```sh
make
```

5. This produces `build/main.elf` and `build/main.bin`.

## Flashing

Using OpenOCD and an ST-Link adapter:

```sh
openocd -f interface/stlink.cfg -f target/stm32f4x.cfg \
    -c "program build/main.bin verify reset exit"
```


## Usage

- Each example’s `main.c` includes comments describing the peripheral configuration.
- To run a different demo, navigate to its folder, rebuild, and flash as above.
- Use a serial terminal (115200 baud, 8 N 1) for UART demos.
- Observe LED toggles, PWM outputs, ADC values, or input interrupts per demo.


## Adding New Examples

1. Create a new folder with a numerical prefix to order it (e.g., `16_new_demo`).
2. Add `Inc/` and `Src/` subfolders, a `Makefile`, and your source files.
3. Update your `Makefile` to point to `startup_stm32f411xe.s` and CMSIS include paths.
4. Test build and flashing before submitting a pull request.

_All examples target the STM32F411CEU6 on the “Black Pill” board, illustrating direct register access and minimal runtime overhead for educational and prototyping purposes._

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


