# Physical Values Calculator

## Overview
This C++ console application, created by Adrian Lesniak, provides a menu-driven interface for physics calculations: velocity, force, kinetic/potential energy, final velocity with air resistance, and date-based calculations using constants (π, golden ratio, Fibonacci, speed of light). It supports cross-platform colored output, logs errors to `physics_calc.log`, and saves results to `calculations.txt`.

## Features
- **Calculation Functions**:
  - `velocity`: Computes speed (v = d/t).
  - `force`: Calculates force (F = ma).
  - `kineticEnergy`: Computes kinetic energy (Ek = ½mv²).
  - `potentialEnergy`: Calculates potential energy (Ep = mgh, g = 9.81 m/s²).
  - `finalVelocityWithAirResistance`: Computes velocity considering air drag.
  - `calculation_date`: Multiplies a date by constants (π, golden ratio, Fibonacci, E=mc²).
- **Interface**:
  - `displayHeader`: Shows program title, author, and features.
  - `displayMenu`: Lists options 1–6 and 0 to exit.
  - Colored output (yellow, cyan, magenta) with Windows (`<windows.h>`) or ANSI codes.
- **Logger Class**:
  - Logs errors/messages with timestamps to `physics_calc.log`.
- **File I/O**:
  - `saveResult`: Saves calculation results to `calculations.txt`.
- **Utilities**:
  - `setColor`: Sets console text color (cross-platform).
  - `waitForKeypress`: Pauses for user input to return to menu.
- **Main Program**:
  - Loops until user selects exit (0).
  - Handles invalid inputs with exceptions and retries.

## Requirements
- C++ compiler (e.g., g++, clang++) with C++11 or later
- Standard C++ libraries: `<iostream>`, `<iomanip>`, `<cmath>`, `<fstream>`, `<string>`, `<ctime>`, `<limits>`
- Windows OS (optional, for `<windows.h>` console colors) or any OS with ANSI-compatible terminal
- Write permissions for `physics_calc.log` and `calculations.txt`

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Save the provided code as `physics_calculator.cpp`.
3. Compile the program:
   ```bash
   g++ physics_calculator.cpp -o physics_calculator
   ```
4. Run the program:
   ```bash
   ./physics_calculator
   ```

## Usage
1. Compile and run the program using the steps above.
2. **Interface**:
   - Displays header with program features and menu options:
     1. Calculate Velocity
     2. Calculate Force
     3. Calculate Kinetic Energy
     4. Calculate Potential Energy
     5. Calculate Final Velocity with Air Resistance
     6. Date Calculations
     0. Exit
3. **Input**:
   - Select 0–6 to choose a tool.
   - Enter required values (e.g., distance/time for velocity, date for calculations).
   - Invalid inputs trigger error messages and retries.
4. **Output**:
   - Velocity: Speed in m/s (e.g., "Velocity: 5.0 m/s").
   - Force: Force in N (e.g., "Force: 10.0 N").
   - Kinetic Energy: Energy in J (e.g., "Kinetic Energy: 50.0 J").
   - Potential Energy: Energy in J (e.g., "Potential Energy: 98.1 J").
   - Final Velocity: Velocity in m/s (e.g., "Final Velocity: 4.2 m/s").
   - Date Calculations: Date multiplied by constants (e.g., "Date * PI: 6283.0").
   - Results saved to `calculations.txt`; errors logged to `physics_calc.log`.
5. **Actions**:
   - Press Enter to return to menu after each calculation.
   - Select 0 to exit.

## File Structure
- `physics_calculator.cpp`: Main C++ source file with program logic.
- `physics_calc.log`: Log file for errors/messages (created/appended).
- `calculations.txt`: Output file for calculation results (created/appended).
- `README.md`: This file, providing project documentation.

## Notes
- Cross-platform color support with `#ifdef _WIN32` for Windows and ANSI codes for other OS.
- Includes commented code for future expansion (e.g., I Ching patterns, quantum physics).
- Constants defined for physics (e.g., π, golden ratio, speed of light, Fibonacci).
- Input validation handles non-numeric inputs via exceptions.
- Extend by adding more physics calculations, GUI, or enhanced logging.
- Ensure write permissions for `physics_calc.log` and `calculations.txt`.
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