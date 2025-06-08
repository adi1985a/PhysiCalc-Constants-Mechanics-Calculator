# 🔬🌌 PhysiCalc Pro: Universal Constants & Mechanics Calculator ⚙️
_A C++ console application for performing essential physics calculations and exploring mathematical constants, featuring cross-platform colored output, logging, and results persistence._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B%2011%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows | Linux | macOS](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)]()

## 📋 Table of Contents
1.  [Overview](#-overview)
2.  [Key Features & Calculations](#-key-features--calculations)
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

**PhysiCalc Pro**, developed by Adrian Lesniak, is a versatile C++ console application designed to perform a range of fundamental physics calculations and engage with intriguing mathematical constants. Users can compute velocity, force, kinetic and potential energy, and even final velocity considering air resistance. A unique feature involves "date-based calculations" where a numerical representation of a date is multiplied by constants like π (Pi), φ (the golden ratio), a Fibonacci number, and a factor related to E=mc² (speed of light). The program boasts a user-friendly, menu-driven interface with **cross-platform colored output** (using Windows API or ANSI escape codes), robust error logging to `physics_calc.log`, and saves all successful calculation results to `calculations.txt`.

![Demo GIF](screenshots/1.gif)

## ✨ Key Features & Calculations

*   ⚙️ **Core Physics Calculations**:
    *   `velocity`: Computes speed (v = d/t) given distance and time.
    *   `force`: Calculates force (F = ma) given mass and acceleration.
    *   `kineticEnergy`: Computes kinetic energy (Ek = ½mv²) given mass and velocity.
    *   `potentialEnergy`: Calculates gravitational potential energy (Ep = mgh, using g = 9.81 m/s²) given mass and height.
    *   `finalVelocityWithAirResistance`: Estimates the final velocity of an object considering air drag (likely using a simplified model or specific formula inputs).
*   📅 **Mathematical Constant Explorations**:
    *   `calculation_date`: Takes a numerical representation of a date (e.g., YYYYMMDD) and multiplies it by:
        *   π (Pi ≈ 3.14159)
        *   φ (Golden Ratio ≈ 1.61803)
        *   A specific Fibonacci number
        *   A factor related to the speed of light (c, as in E=mc²)
*   🖥️ **Interactive Console Interface**:
    *   `displayHeader`: Shows a clear program title, author credit, and a summary of available features.
    *   `displayMenu`: Provides a simple, numbered menu with options for each calculation and an exit option.
    *   **Cross-Platform Colored Output**: Utilizes Windows-specific calls (`<windows.h>`) or standard ANSI escape codes to provide colored text (yellow, cyan, magenta, etc.) for enhanced UI on compatible terminals.
*   ✍️ **Logging & File I/O**:
    *   **Logger Class**: A dedicated class for logging errors and potentially informational messages with timestamps to `physics_calc.log`.
    *   `saveResult`: Saves the details and results of each successful calculation to `calculations.txt` for persistence and review.
*   🛠️ **Utility Functions**:
    *   `setColor`: A cross-platform compatible function to set console text color.
    *   `waitForKeyPress`: Pauses program execution, prompting the user to press a key before returning to the main menu.
*   ⚙️ **Robust Operation**:
    *   The main program loop continues until the user chooses to exit (option 0).
    *   Handles invalid user inputs (e.g., non-numeric values when numbers are expected) gracefully using C++ exceptions and retry prompts.

## 🖼️ Screenshots

_Screenshots showcasing the main menu, input prompts for various physics calculations, example outputs, the date calculation feature, and snippets from `calculations.txt` and `physics_calc.log`._

<p align="center">
  <img src="screenshots\1.jpg" width="300"/>
  <img src="screenshots\2.jpg" width="300"/>
  <img src="screenshots\3.jpg" width="300"/>
  <img src="screenshots\4.jpg" width="300"/>
  <img src="screenshots\5.jpg" width="300"/>
  <img src="screenshots\6.jpg" width="300"/>
  <img src="screenshots\7.jpg" width="300"/>
  <img src="screenshots\8.jpg" width="300"/>
</p>


## ⚙️ System Requirements

*   **Operating System**: Windows (for optional, enhanced console colors via `<windows.h>`) or any OS with an ANSI-compatible terminal (Linux, macOS) for basic color support.
*   **C++ Compiler**: A C++ compiler supporting C++11 or later (e.g., g++, clang++, MSVC).
*   **Standard C++ Libraries**: `<iostream>`, `<iomanip>`, `<cmath>`, `<fstream>`, `<string>`, `<vector>`, `<ctime>`, `<limits>`, `<stdexcept>` (for exception handling).
*   **Write Permissions**: The application needs write permissions in its execution directory to create/modify `physics_calc.log` and `calculations.txt`.

## 🛠️ Installation and Setup

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
    (Replace `<repository-url>` and `<repository-directory>` with your specific details)

2.  **Save Main Code**:
    Ensure your main program logic (including the `Logger` class, calculation functions, UI functions, and `main()`) is saved as `physics_calculator.cpp` (or your chosen main file name) in the project directory. *(The description implies most logic, including helper classes like Logger, might be within a single `.cpp` file or managed through minimal internal headers not requiring separate user provision).*

3.  **Compile the Program**:
    Open a terminal (Command Prompt, PowerShell, Bash, etc.) in the project directory.
    **Example using g++ (works on Windows with MinGW, Linux, macOS):**
    ```bash
    g++ physics_calculator.cpp -o physics_calculator -std=c++11
    ```
    *(Add `-static-libgcc -static-libstdc++` on Windows with MinGW if desired for standalone executables. Add optimization flags like `-O2` for release builds if needed).*

4.  **Run the Program**:
    *   On Windows: `.\physics_calculator.exe` or `physics_calculator.exe`
    *   On Linux/macOS: `./physics_calculator` (ensure execute permissions: `chmod +x physics_calculator`)

## 💡 Usage Guide

1.  Compile and run `physics_calculator` as detailed above.
2.  **Interface**:
    *   The program will display a header with its features and then the main menu:
        1.  Calculate Velocity
        2.  Calculate Force
        3.  Calculate Kinetic Energy
        4.  Calculate Potential Energy
        5.  Calculate Final Velocity with Air Resistance
        6.  Date Calculations with Constants
        0.  Exit
3.  **Input**:
    *   Select a menu option (0–6) by typing the number and pressing Enter.
    *   **For Physics Calculations (Options 1–5)**: You will be prompted to enter the required numerical values (e.g., distance and time for velocity; mass and acceleration for force; mass, height for potential energy; details for air resistance; etc.).
    *   **For Date Calculations (Option 6)**: You will be prompted to enter a date (likely as a single number, e.g., YYYYMMDD or just a numerical value to be used in calculations).
    *   Invalid inputs (e.g., non-numeric characters when numbers are expected, or values that don't make sense for the calculation) will trigger an error message, log the error, and prompt for re-entry.
4.  **Output**:
    *   **Velocity**: Displays speed in m/s (e.g., "Velocity: 5.00 m/s").
    *   **Force**: Shows force in Newtons (N) (e.g., "Force: 10.00 N").
    *   **Kinetic Energy**: Outputs energy in Joules (J) (e.g., "Kinetic Energy: 50.00 J").
    *   **Potential Energy**: Displays energy in Joules (J) (e.g., "Potential Energy: 98.10 J").
    *   **Final Velocity (with Air Resistance)**: Shows the calculated velocity in m/s.
    *   **Date Calculations**: Displays the results of multiplying the input date value by π, golden ratio, Fibonacci number, and speed of light factor (e.g., "Date * PI: 6283.18").
    *   All successful calculation results are saved to `calculations.txt`.
    *   Errors are logged to `physics_calc.log`.
5.  **Actions**:
    *   After each calculation and display of results, you will be prompted to press Enter to return to the main menu.
    *   Select option `0` from the main menu to exit the application.

## 🗂️ File Structure & Data Persistence

*   `physics_calculator.cpp`: The main C++ source file containing all program logic, including calculation functions, UI management, the `Logger` class (or its instance), and file handling.
*   `physics_calc.log`: A plain text file where error messages and potentially other informational logs are recorded with timestamps. Created or appended to.
*   `calculations.txt`: A plain text file that stores a record of all successful calculations, including the input parameters and the computed result, along with a timestamp. Created or appended to.
*   `README.md`: This documentation file.

## 📝 Technical Notes

*   **Cross-Platform Color**: Implements conditional compilation (`#ifdef _WIN32`) to use Windows-specific console API (`SetConsoleTextAttribute`) for colors on Windows, and standard ANSI escape codes for color support on other ANSI-compatible terminals (Linux, macOS).
*   **Constants**: Defines and uses physical and mathematical constants like g (acceleration due to gravity), π (Pi), φ (golden ratio), a Fibonacci number, and c (speed of light).
*   **Input Validation**: Employs C++ exception handling (`try-catch` blocks for `std::invalid_argument`, `std::out_of_range`) and stream state checks (`std::cin.fail()`) to manage non-numeric or inappropriate inputs.
*   **Timestamping**: Uses C++ `<ctime>` library to generate and format timestamps for log entries and saved calculation results.
*   **Commented Code for Expansion**: The description notes commented-out code for potential future features (e.g., I Ching patterns, quantum physics), indicating areas for further development.

## 🤝 Contributing

Contributions to **PhysiCalc Pro** are highly encouraged! If you have ideas for adding more physics calculations, refining existing formulas, improving the cross-platform support, enhancing the user interface, or implementing graphical output:

1.  Fork the repository.
2.  Create a new branch for your feature (`git checkout -b feature/YourPhysicsIdea`).
3.  Make your changes and commit them (`git commit -m 'Feature: Implement YourPhysicsIdea'`).
4.  Push to the branch (`git push origin feature/YourPhysicsIdea`).
5.  Open a Pull Request.

Please ensure your code is well-commented and adheres to good C++ practices.

## 📃 License

This project is licensed under the **MIT License**.
(If you have a `LICENSE` file in your repository, refer to it: `See the LICENSE file for details.`)

## 📧 Contact

Created by **Adrian Lesniak**.
For questions, feedback, or issues, please open an issue on the GitHub repository or contact the repository owner.

---
🌌 _Exploring the laws of nature and the elegance of mathematics, one calculation at a time._
