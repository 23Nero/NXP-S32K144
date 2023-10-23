# S32K144 Peripheral Configuration Library

This repository contains a comprehensive library for configuring and controlling the peripherals of the NXP S32K144 microcontroller. The library provides essential configuration functions for GPIO, clocking, interrupt handling, LPIT, and LPUART modules. It is intended for use with the S32K144 development board, offering a convenient way to set up and control hardware interfaces.

## Table of Contents

- [Introduction](#introduction)
- [Library Features](#library-features)
- [Getting Started](#getting-started)

## Introduction

The S32K144 Peripheral Configuration Library is designed to simplify the setup and utilization of essential microcontroller peripherals. It includes support for the following peripherals:

- GPIO Configuration
- Clock Configuration
- Interrupt Handling
- Low Power Periodic Interrupt Timer (LPIT)
- Low Power UART (LPUART)

The library is designed for use with the NXP S32K144 development board but can be adapted for other platforms as well. It aims to accelerate the development process by providing a straightforward and reliable way to configure and control these peripherals.

## Library Features

- **GPIO Configuration:**
  - Initialize GPIO pins as inputs or outputs.
  - Read and write data to GPIO pins.

- **Clock Configuration:**
  - Configure system clocks and PLL settings.
  - Ensure precise clocking for microcontroller operation.

- **Interrupt Handling:**
  - Register custom interrupt handlers.
  - Manage and respond to peripheral interrupts.

- **LPIT (Low Power Periodic Interrupt Timer):**
  - Initialize LPIT for timer-based operations.
  - Schedule periodic events using LPIT timers.

- **LPUART (Low Power UART):**
  - Configure LPUART for serial communication.
  - Transmit and receive data over UART.

## Getting Started

To get started with the library, you should:

1. Clone or download this repository to your local development environment.
2. Include the library in your project and link it with your code.
3. Refer to the documentation and examples provided to configure and use the desired peripherals.
