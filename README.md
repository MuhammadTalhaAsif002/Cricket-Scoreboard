
# Cricket Board Simulation Project

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Introduction
This project is a cricket board simulation implemented in C++. It allows users to simulate cricket matches, manage player statistics, and perform various operations related to cricket gameplay. The project provides an interactive experience for users to engage with cricket simulations programmatically.

## Features
- **Player Management**: Create and manage player profiles with attributes like name, type, score, wickets taken, etc.
- **Match Simulation**: Simulate cricket matches with score calculations, overs bowled, and wickets lost.
- **File Operations**: Save and load match data and player statistics from files.
- **Interactive User Interface**: Console-based user interface for interacting with the simulation.

## Prerequisites
- C++ Compiler (e.g., g++)
- Standard C++ Library

## Installation
1. Clone the repository to your local machine:
    ```sh
    git clone <repository-url>
    ```
2. Navigate to the project directory:
    ```sh
    cd cricket-board-simulation
    ```
3. Compile the project using g++:
    ```sh
    g++ -o cricket_simulation OOP\ PROJECT.cpp
    ```

## Usage
1. Run the compiled executable:
    ```sh
    ./cricket_simulation
    ```
2. Follow the on-screen instructions to interact with the cricket simulation.
3. You can manage players, simulate matches, and view statistics through the console interface.

### Main Functions
- `set_player_name(string player_name)`: Set the name of a player.
- `set_type(string type)`: Set the type (e.g., batsman, bowler) of a player.
- `get_player_name()`: Get the name of a player.
- `get_type()`: Get the type of a player.
- `score(int s)`: Update the score of a player.
- `set_score(int s)`: Set the score of a player.
- `get_player_skill()`: Get the skill level of a player.
- `get_score() const`: Get the current score of a player.

## Contributing
Contributions are welcome! Please follow these steps:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes and commit them (`git commit -m 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Create a new Pull Request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements
- Thanks to the C++ community for their continuous support and resources.
- Special thanks to the contributors who helped in making this project possible.
