
---

# UART-COMMAND-WITH-AND-WITHOUT-RETARGET-I-O

## Overview

**UART-COMMAND-WITH-AND-WITHOUT-RETARGET-I-O** is an embedded C project that demonstrates two approaches to handling UART (Universal Asynchronous Receiver/Transmitter) communication in embedded systems:

1. **Without Retargeting I/O:** Directly using low-level UART APIs for sending and receiving data.
2. **With Retargeting I/O:** Redirecting standard input/output functions (`printf`, `scanf`, etc.) to UART, allowing for more straightforward code using standard C I/O functions.

This project is developed using **ModusToolbox** and is tailored for Infineon PSoC™ microcontrollers but can be adapted to other platforms with UART support.

---

## Features

- **Dual Implementation:**
  - `main_Without_retarget_io.c`: Demonstrates UART communication using direct API calls.
  - `main_with_retarget_io.c`: Shows how to retarget standard I/O functions to UART.

- **Command Handling:**
  - Receives commands over UART and performs corresponding actions.
  - Echoes received commands for verification.

- **Educational Insight:**
  - Highlights the differences between using direct UART APIs and retargeted I/O functions.
  - Serves as a learning tool for understanding UART communication in embedded systems.

---

## Project Structure

| File                        | Description                                                  |
|-----------------------------|--------------------------------------------------------------|
| `main_Without_retarget_io.c`| UART communication using direct API calls.                   |
| `main_with_retarget_io.c`   | UART communication using retargeted standard I/O functions.  |
| `README.md`                 | Project overview and instructions.                           |

---

## Requirements

- **Hardware:**
  - Infineon PSoC™ microcontroller development board (e.g., CY8CKIT-062-BLE).
  - USB cable for programming and UART communication.

- **Software:**
  - [ModusToolbox](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/) installed on your development machine.
  - Serial terminal application (e.g., PuTTY, Tera Term) for UART communication.

---

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/ViralPatel-19/UART-COMMAND-WITH-AND-WITHOUT-RETARGET-I-O.git
```

### 2. Open the Project in ModusToolbox

- Launch **ModusToolbox**.
- Click on **"Import Application"**.
- Navigate to the cloned repository and select the project.

### 3. Build and Program

- Choose the desired source file (`main_Without_retarget_io.c` or `main_with_retarget_io.c`) by setting it as the main application file.
- Build the project.
- Connect your development board via USB.
- Program the board using the **"Program"** option.

### 4. Set Up UART Communication

- Open your serial terminal application.
- Configure the serial port with the following settings:
  - **Baud Rate:** 115200
  - **Data Bits:** 8
  - **Parity:** None
  - **Stop Bits:** 1
  - **Flow Control:** None

### 5. Interact with the Application

- Type commands into the serial terminal.
- Observe the responses from the microcontroller, which will vary depending on whether retargeted I/O is used.

---

## Understanding Retargeting I/O

Retargeting I/O involves redirecting standard C library input/output functions to use hardware peripherals like UART. This allows developers to use familiar functions like `printf` and `scanf` for UART communication.

In this project:

- **Without Retargeting I/O:**
  - UART communication is handled using specific API functions provided by the hardware abstraction layer.
  - Offers more control but requires more code for formatting and handling data.

- **With Retargeting I/O:**
  - Standard I/O functions are redirected to UART using retargeting techniques.
  - Simplifies code by allowing the use of `printf` for output and `scanf` for input.
  - Requires setting up retargeting functions, such as redefining `fputc` and `fgetc`, to direct output and input to UART.

For more information on retargeting I/O in embedded systems, refer to the [Infineon Retarget I/O Library](https://github.com/Infineon/retarget-io).

---

## License

This project is open-source and available for educational and personal development use. Please refer to the `LICENSE` file for more information.

---

## Acknowledgments

- **Developed by:** Viral Patel
- **Tools Used:** ModusToolbox, Infineon PSoC™ microcontrollers.

---

Feel free to contribute to this project by submitting issues or pull requests. Your feedback and improvements are welcome!

--- 
