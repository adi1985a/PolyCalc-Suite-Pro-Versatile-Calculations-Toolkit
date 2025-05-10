# Multi-Calculator Program

## Overview
This C++ console application offers a menu-driven interface for various calculations: number comparison (with parity check), function evaluation, geometric calculations (sphere/cone volume, rectangle area), triangle area, and shipping cost. It logs errors to `program_log.txt`, supports cross-platform screen clearing, and ensures robust input validation.

## Features
- **Calculation Functions**:
  - Number Comparison: Compares two integers, checks if X is odd/even.
  - Function Calculation: Evaluates a piecewise function based on x.
  - Geometric Calculations: Computes sphere volume, cone volume, or rectangle area.
  - Triangle Area: Calculates area using two sides and an angle.
  - Shipping Calculator: Determines cost based on package weight and distance.
- **Interface**:
  - `displayMenu`: Shows ASCII menu with options 1–5 and 0 to exit.
  - `displayHeader`: Displays task-specific titles.
  - Prompts for inputs with validation via `getValidNumericInput`.
- **File I/O**:
  - `logMessage`: Logs errors/messages with timestamps to `program_log.txt`.
  - `saveToFile`: Saves calculation results to `calculations.txt` (not used in current code).
- **Utilities**:
  - `clearScreen`: Clears console (`cls` for Windows, `clear` for others).
  - `handleInvalidInput`: Clears invalid input and logs errors.
- **Main Program**:
  - Loops until user selects exit (0).
  - Handles invalid choices and inputs with retries.

## Requirements
- C++ compiler (e.g., g++, clang++) with C++11 or later
- Standard C++ libraries: `<iostream>`, `<cmath>`, `<stdlib.h>`, `<conio.h>`, `<fstream>`, `<string>`, `<limits>`, `<ctime>`
- Operating system: Any supporting a C++ compiler (e.g., Windows, Linux, macOS)
- Write permissions for `program_log.txt` and `calculations.txt`

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Save the provided code as `multi_calculator.cpp`.
3. Compile the program:
   ```bash
   g++ multi_calculator.cpp -o multi_calculator
   ```
4. Run the program:
   ```bash
   ./multi_calculator
   ```

## Usage
1. Compile and run the program using the steps above.
2. **Interface**:
   - Displays a menu with options:
     1. Number Comparison
     2. Function Calculation
     3. Geometric Calculations
     4. Triangle Area
     5. Shipping Calculator
     0. Exit
3. **Input**:
   - Select an option (0–5).
   - Enter numeric inputs (e.g., numbers for comparison, radius for sphere).
   - Invalid inputs trigger retries with error messages.
4. **Output**:
   - Example: Number Comparison shows "X is greater than Y and the number X is odd".
   - Geometric Calculations shows volume/area (e.g., "The volume of your sphere is: 4188.79").
   - Errors logged to `program_log.txt` (e.g., "Invalid input detected").
5. **Actions**:
   - Press any key to continue after results.
   - Select 0 to exit.

## File Structure
- `multi_calculator.cpp`: Main C++ source file with program logic.
- `program_log.txt`: Log file for errors/messages (created/appended).
- `calculations.txt`: Output file for results (not currently used).
- `README.md`: This file, providing project documentation.

## Notes
- Cross-platform support with `#ifdef` for screen clearing; Windows uses `_getch` for keypress.
- `saveToFile` is defined but unused; could be integrated for result storage.
- Input validation via `getValidNumericInput` ensures numeric inputs.
- Extend by adding more calculations, saving results to `calculations.txt`, or GUI support.
- Logs errors to `program_log.txt` with timestamps for debugging.
- No external dependencies beyond standard C++ libraries.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For questions or feedback, open an issue on GitHub or contact the repository owner.