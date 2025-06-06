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

**PolyCalc Suite Pro** is a C++ console application by Adrian Lesniak, designed as a versatile toolkit for various calculations. It features a menu-driven interface for: number comparison (with parity check), a piecewise function evaluator, geometric calculators (sphere volume, cone volume, rectangle area), triangle area (using two sides and an angle), and a shipping cost estimator. The program supports cross-platform screen clearing, robust input validation, and logs errors/messages to `program_log.txt`. Calculation results are saved to `calculations.txt`.

![Demo GIF](screenshots/1.gif)

## ✨ Key Features & Calculation Tools

The application offers these calculation modules:

1.  ⚖️ **Number Comparison Tool**:
    *   Compares two integers (X and Y).
    *   Determines if X is greater than, less than, or equal to Y.
    *   Checks and reports if X is odd or even.
2.  📉 **Function Calculator**:
    *   Evaluates a piecewise mathematical function based on user input `x`:
        - If `x <= -10` or `x >= 0`: `y = -2 * x`
        - If `x < 0`: `y = (2/3)x² + 0.5x`
        - If `x <= π`: `y = 1/(sin(x) + 2)`
        - Otherwise: error message
3.  📐 **Geometric Calculations**:
    *   Sub-menu for:
        *   **Sphere Volume**: V = (4/3)πr³
        *   **Cone Volume**: V = (1/3)πr²h
        *   **Rectangle Area**: A = a × b
4.  🔺 **Triangle Area Calculator**:
    *   Calculates area given two sides and the included angle (degrees).
    *   Formula: Area = 0.5 × a × b × sin(angle)
5.  🚚 **Shipping Cost Calculator**:
    *   Calculates shipping cost based on weight and distance:
        - ≤2kg: 1.1 per 100km
        - ≤6kg: 2.2 per 100km
        - <10kg: 3.7 per 100km
        - ≤20kg: 4.8 per 100km
        - >20kg: not accepted

### Common Features:
*   🖥️ **Interactive Console Interface**:
    *   `displayMenu`: ASCII-styled menu with options 1–5 and 0 to exit.
    *   `displayHeader`: Task-specific titles.
    *   **User Prompts**: All inputs validated by `getValidNumericInput`.
*   ✍️ **Logging & File I/O**:
    *   `logMessage`: Logs errors/messages with timestamps to `program_log.txt`.
    *   `saveToFile`: Saves calculation results to `calculations.txt`.
*   🛠️ **Utility Functions**:
    *   `clearScreen`: Clears console (`cls` for Windows, `clear` for others).
    *   `handleInvalidInput`: Handles invalid input, clears stream, logs error.
*   ⚙️ **Robust Operation**:
    *   Main loop continues until user selects exit (0).
    *   Handles invalid choices and inputs with retries and error messages.

## 🖼️ Screenshots

_Screenshots of the main menu, calculation tools, and log/output files._

<p align="center">
  <img src="screenshots\1.jpg" width="300"/>
  <img src="screenshots\2.jpg" width="300"/>
  <img src="screenshots\3.jpg" width="300"/>
  <img src="screenshots\4.jpg" width="300"/>
  <img src="screenshots\5.jpg" width="300"/>
  <img src="screenshots\6.jpg" width="300"/>
</p>

## ⚙️ System Requirements

*   **Operating System**: Any OS with a C++11+ compiler (Windows, Linux, macOS). Windows required for `_getch` keypress.
*   **C++ Compiler**: C++11 or later (g++, clang++, MSVC).
*   **Standard Libraries**: `<iostream>`, `<cmath>`, `<cstdlib>`, `<conio.h>`, `<fstream>`, `<string>`, `<limits>`, `<ctime>`.
*   **Write Permissions**: For `program_log.txt` and `calculations.txt`.

## 🛠️ Installation and Setup

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
2.  **Save Main Code**:
    Ensure your main program is saved as `main.cpp` in the project directory.

3.  **Compile the Program**:
    ```bash
    g++ main.cpp -o polycalc -std=c++11
    ```
    *(On Windows, use MinGW or similar; on Linux/macOS, ensure g++ is installed.)*

4.  **Run the Program**:
    *   On Windows: `polycalc.exe`
    *   On Linux/macOS: `./polycalc`

## 💡 Usage Guide

1.  Compile and run as above.
2.  **Interface**:
    *   Menu options:
        1.  Number Comparison
        2.  Function Calculation
        3.  Geometric Calculations
        4.  Triangle Area
        5.  Shipping Calculator
        0.  Exit
3.  **Input**:
    *   Select an option (0–5).
    *   Enter required numeric inputs for each tool.
    *   Invalid inputs trigger error messages and retries.
4.  **Output**:
    *   Results are displayed for each calculation.
    *   Errors are logged to [program_log.txt](http://_vscodecontentref_/0).
    *   Calculation results are saved to `calculations.txt`.
5.  **Actions**:
    *   After each calculation, press any key to continue.
    *   Select 0 to exit.

## 🗂️ File Structure & Data Persistence

*   [main.cpp](http://_vscodecontentref_/1): Main C++ source file with all logic.
*   [program_log.txt](http://_vscodecontentref_/2): Logs errors/messages with timestamps.
*   `calculations.txt`: Stores calculation results.
*   [README.markdown](http://_vscodecontentref_/3): This documentation file.

## 📝 Technical Notes

*   **Cross-Platform**: Uses [system("cls")](http://_vscodecontentref_/4) or [system("clear")](http://_vscodecontentref_/5) for screen clearing. [_getch()](http://_vscodecontentref_/6) is Windows-specific for keypress.
*   **Input Validation**: [getValidNumericInput](http://_vscodecontentref_/7) ensures only valid numeric input is accepted.
*   **Logging**: [logMessage](http://_vscodecontentref_/8) includes timestamps for traceability.
*   **Result Saving**: All calculation results are saved to `calculations.txt`.

## 🤝 Contributing

Contributions are welcome! To contribute:

1.  Fork the repository.
2.  Create a new branch (`git checkout -b feature-branch`).
3.  Make changes and commit (`git commit -m "Add feature"`).
4.  Push to the branch (`git push origin feature-branch`).
5.  Open a pull request.

Please ensure your code is well-commented and follows good C++ practices.

## 📃 License

This project is licensed under the **MIT License**.  
See the [LICENSE](http://_vscodecontentref_/9) file for details.

## 📧 Contact

Created by **Adrian Lesniak**.  
For questions or feedback, open an issue on GitHub or contact the repository owner.

---
✨ _Your versatile console companion for a multitude of calculations!_
