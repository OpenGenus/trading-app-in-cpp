# Trading-App

Welcome to the Trading App prototype! This application provides users with real-time data for various company stocks, allowing them to make informed decisions on buying and selling. If the stock price meets the user's criteria, the app will send a signal to buy or sell stocks according to the user's specified limit. Additionally, users can obtain the cost of the stock based on the current price when a signal is sent.

![Screenshot](./output.png)

## Table of Contents
- [Built With](#built-with)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
- [Authors](#authors)
- [Show Your Support](#show-your-support)
- [License](#license)

## Built With

This application is primarily built using C++ STL (Standard Template Library).

## Getting Started

To get started with the Trading App, follow these steps:

1. Download or clone this repository using the following command:
   ```
   git clone https://github.com/Vidhi0229/Trading-App.git
   ```

2. Navigate to the project folder.

3. Compile the application using Visual Studio Code with the following command:
   ```
   g++ -o "output/output file name" main.cpp curl_functions.cpp functions.cpp -lcurl -ljsoncpp
   ```

4. Run the compiled application using the following command:
   ```
   ./output/output file
   ```
5. **Shortcut for running and compiling:**
Alternatively, you can use the shortcut script to simplify the compiling and running process.

Run: ``` ./compile-and-run.sh  ```

### Prerequisites

Before running the Trading App, make sure you have the following prerequisites installed:

- **curl library:** Install the curl library for making HTTP requests.

- **JsonCpp library:** Install the JsonCpp library for JSON parsing and manipulation in C++.

- **API Key:** Sign up at [Twelve Data](https://twelvedata.com/stocks) to obtain your own API key. Place your API key in the `config.json` file.

## Authors 👤

### Vidhi Srivastava

- [GitHub](https://github.com/Vidhi0229)
- [LinkedIn](https://www.linkedin.com/in/vidhisrivastava01/)

## Show Your Support ⭐️⭐️

If you find this project helpful or interesting, please consider giving it a star!

## License 📝

This project is licensed under the [MIT License](https://www.mit.edu/~amini/LICENSE.md), which means you are free to use, modify, and distribute the code as long as you include the appropriate attribution and disclaimer.