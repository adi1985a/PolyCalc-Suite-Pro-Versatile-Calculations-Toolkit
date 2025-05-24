# 🛠️🔢 PolyCalc Suite Pro: Versatile Calculations Toolkit 📐
_A C++ console application offering a diverse range of calculators: number comparison, function evaluation, geometry, triangle area, and shipping costs, with cross-platform features._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B%2011%2B-blue.svg)](https://isocpp.org/)
[![Platform: Cross-platform](https://img.shields.io/badge/Platform-Cross--platform-lightgrey.svg)]()

## 📋 Table of Contents
1.  [Overview](#-overview)
2.  [Key Features & Calculation Tools](#-key-features--calculation-tools)
3.  [Screenshots](#-screenshots)
4.  [System Requirements](#-system-requirements)
5.  [Installation and Setup](#️-installation-and-setup)
6.  [Usage Guide](#️-usage-guide)
7.  [File Structure & Data Persistence](#-file-structure--data-persistence)
8.  [Technical Notes](#-technical-notes)
9.  [Contributing](#-contributing)
10. [License](#-license)
11. [Contact](#-contact)

## 📄 Overview

**PolyCalc Suite Pro**, developed by Adrian Lesniak, is a multifaceted C++ console application designed as a versatile toolkit for various common calculations. It features a user-friendly, menu-driven interface that provides access to: a number comparison tool (with parity check); a piecewise function evaluator; geometric calculators for sphere volume, cone volume, and rectangle area; a triangle area calculator (using two sides and an included angle); and a basic shipping cost estimator. The program emphasizes a clean user experience with **cross-platform screen clearing**, robust input validation, and diligent error/message logging to `program_log.txt`. While a function to save results to `calculations.txt` is defined, its current use in the main workflow is noted as pending.

## ✨ Key Features & Calculation Tools

The application offers a suite of distinct calculation modules:

1.  ⚖️ **Number Comparison Tool**:
    *   Compares two integers (X and Y) entered by the user.
    *   Determines if X is greater than, less than, or equal to Y.
    *   Checks and reports if X is an odd or even number.
2.  📉 **Function Calculator**:
    *   Evaluates a predefined piecewise mathematical function based on a user-inputted value for `x`.
    *   (The specific function definition should be clear in the code, e.g., different formulas for different ranges of `x`).
3.  📐 **Geometric Calculations**:
    *   Offers a sub-menu to choose between calculating:
        *   **Sphere Volume**: V = (4/3)πr³
        *   **Cone Volume**: V = (1/3)πr²h
        *   **Rectangle Area**: A = width × height
    *   Prompts for necessary dimensions (radius, height, width).
4.  <0xF0><0x9F><0xAA><0xB ट्रायंगल_Area** (Triangle Area Calculator):
    *   Calculates the area of a triangle given the lengths of two sides and the measure of the included angle (in degrees).
    *   Uses the formula: Area = 0.5 × side1 × side2 × sin(angle).
5.  🚚 **Shipping Cost Calculator**:
    *   Determines the shipping cost based on user inputs for package weight and shipping distance.
    *   (The specific cost calculation formula/logic needs to be defined in the code).

### Common Features:
*   🖥️ **Interactive Console Interface**:
    *   `displayMenu`: Presents an ASCII-styled main menu with options 1–5 for tools and 0 to exit.
    *   `displayHeader`: Shows task-specific titles to orient the user within each calculator module.
    *   **User Prompts**: Clear prompts for all required inputs, with validation managed by `getValidNumericInput`.
*   ✍️ **Logging & File I/O**:
    *   `logMessage`: A dedicated function to log errors and informational messages with timestamps to `program_log.txt`.
    *   `saveToFile`: A function is defined to save calculation results to `calculations.txt`, though its current integration for all tools might be limited or a placeholder for future use.
*   🛠️ **Utility Functions**:
    *   `clearScreen`: Clears the console window using platform-specific commands (`cls` for Windows, `clear` for Linux/macOS).
    *   `handleInvalidInput`: Manages invalid user input by clearing stream error flags, ignoring residual input, and logging the error.
*   ⚙️ **Robust Operation**:
    *   The main program loop continues until the user selects the exit option (0).
    *   Handles invalid menu choices and incorrect data inputs with retries and error messages.

## 🖼️ Screenshots

**Coming soon!**

_This section will be updated with screenshots showcasing the main menu, input/output for each of the five calculation tools, and examples from `program_log.txt` (and `calculations.txt` if fully utilized)._

## ⚙️ System Requirements

*   **Operating System**: Any OS supporting a C++11 (or later) compiler (e.g., Windows, Linux, macOS). Windows is required for `_getch` if used for "press any key" prompts beyond standard input.
*   **C++ Compiler**: A C++ compiler supporting C++11 or later (e.g., g++, clang++, MSVC).
*   **Standard C++ Libraries**: `<iostream>`, `<iomanip>`, `<cmath>`, `<stdlib.h>` (or `<cstdlib>`), `<conio.h>` (Windows-specific, for `_getch`), `<fstream>`, `<string>`, `<vector>`, `<limits>`, `<ctime>`.
*   **Write Permissions**: The application needs write permissions in its execution directory to create/modify `program_log.txt` and `calculations.txt`.

## 🛠️ Installation and Setup

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
    (Replace `<repository-url>` and `<repository-directory>` with your specific details)

2.  **Save Main Code**:
    Ensure your main program logic (including all calculation functions, UI functions, logging, and `main()`) is saved as `multi_calculator.cpp` (or your chosen main file name) in the project directory. *(The description implies a single-file structure for the core logic, with utility functions potentially also within this file if no separate utility header is mandated by the actual code for this project).*

3.  **Compile the Program**:
    Open a terminal (Command Prompt, PowerShell, Bash, etc.) in the project directory.
    **Example using g++ (works on Windows with MinGW, Linux, macOS):**
    ```bash
    g++ multi_calculator.cpp -o multi_calculator -std=c++11
    ```
    *(Add `-static-libgcc -static-libstdc++` on Windows with MinGW if desired for standalone executables. Add optimization flags like `-O2` for release builds if needed).*

4.  **Run the Program**:
    *   On Windows: `.\multi_calculator.exe` or `multi_calculator.exe`
    *   On Linux/macOS: `./multi_calculator` (ensure execute permissions: `chmod +x multi_calculator`)

## 💡 Usage Guide

1.  Compile and run `multi_calculator` as detailed above.
2.  **Interface**:
    *   The program will display a main menu with the following options:
        1.  Number Comparison
        2.  Function Calculation
        3.  Geometric Calculations (Sphere, Cone, Rectangle)
        4.  Triangle Area
        5.  Shipping Calculator
        0.  Exit
3.  **Input**:
    *   Select a menu option (0–5) by typing the number and pressing Enter.
    *   For each selected tool, you will be prompted to enter the necessary numeric inputs (e.g., two numbers for comparison; `x` for function; radius, height, width for geometric shapes; two sides and an angle for triangle; weight and distance for shipping).
    *   Invalid inputs (e.g., non-numeric characters, negative dimensions where positive are expected) will trigger an error message (logged to `program_log.txt`) and prompt for re-entry.
4.  **Output**:
    *   **Number Comparison**: Displays the comparison result and parity of X (e.g., "X (10) is greater than Y (5) and the number X is even").
    *   **Function Calculation**: Shows the calculated value of `y` for the given `x`.
    *   **Geometric Calculations**: Outputs the calculated volume or area (e.g., "The volume of your sphere is: 4188.79 cubic units").
    *   **Triangle Area**: Displays the computed area of the triangle.
    *   **Shipping Calculator**: Shows the estimated shipping cost.
    *   Errors encountered during operations are logged to `program_log.txt`.
    *   *(Note: While `saveToFile` for `calculations.txt` is defined, its active use for all results is marked as not currently implemented in the description).*
5.  **Actions**:
    *   After each calculation and display of results, you will typically be prompted to press any key (or Enter) to continue and return to the main menu.
    *   Select option `0` from the main menu to exit the application.

## 🗂️ File Structure & Data Persistence

*   `multi_calculator.cpp`: The main C++ source file containing all program logic, including the implementations for each calculation tool, UI management, input validation, and error logging.
*   `program_log.txt`: A plain text file where error messages and potentially other informational logs are recorded with timestamps. This file is created or appended to.
*   `calculations.txt`: A plain text file intended for storing results of calculations. Its current usage by all tools might be limited or pending full implementation, as per the description. This file is created or appended to.
*   `README.md`: This documentation file.

## 📝 Technical Notes

*   **Cross-Platform Considerations**: The program aims for cross-platform compatibility for screen clearing (`#ifdef _WIN32` for `system("cls")` vs. `system("clear")`). Keypress handling via `_getch()` is Windows-specific; standard `std::cin.get()` or more complex terminal I/O would be needed for similar behavior on other OSes for "press any key" prompts if strict non-buffered input is desired beyond simple Enter presses. Color support also uses conditional compilation for Windows API vs. ANSI codes.
*   **`saveToFile` Functionality**: The `saveToFile` function is defined but noted as "not used in current code" for saving all results. This is a clear area for enhancement to make `calculations.txt` more comprehensive.
*   **Input Validation**: The `getValidNumericInput` function, along with `handleInvalidInput`, is crucial for robustly handling user input, ensuring only valid numeric data is processed by the calculation functions and logging errors otherwise.
*   **Timestamping**: The `logMessage` function includes timestamps for better traceability of errors and events.
*   **Modularity**: Although likely in a single `.cpp` file, the distinct functions for each calculator tool, UI elements, and utilities like logging and input validation indicate a good degree of logical modularity.

## 🤝 Contributing

Contributions to **PolyCalc Suite Pro** are highly encouraged! If you have ideas for adding new calculation tools (e.g., more advanced physics, financial calculators), implementing the `saveToFile` functionality more broadly, enhancing cross-platform UI/UX, or developing a GUI:

1.  Fork the repository.
2.  Create a new branch for your feature (`git checkout -b feature/YourCalculatorIdea`).
3.  Make your changes and commit them (`git commit -m 'Feature: Implement YourCalculatorIdea'`).
4.  Push to the branch (`git push origin feature/YourCalculatorIdea`).
5.  Open a Pull Request.

Please ensure your code is well-commented and adheres to good C++ practices.

## 📃 License

This project is licensed under the **MIT License**.
(If you have a `LICENSE` file in your repository, refer to it: `See the LICENSE file for details.`)

## 📧 Contact

Created by **Adrian Lesniak**.
For questions, feedback, or issues, please open an issue on the GitHub repository or contact the repository owner.

---
✨ _Your versatile console companion for a multitude of calculations!_
