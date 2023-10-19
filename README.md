# Trading-App

Welcome to the Trading App prototype! This application provides users with real-time data for various company stocks, allowing them to make informed decisions on buying and selling. If the stock price meets the user's criteria, the app will send a signal to buy or sell stocks according to the user's specified limit. Additionally, users can obtain the cost of the stock based on the current price when a signal is sent.

[Documentation on building Trading App in C++](https://iq.opengenus.org/trading-application-in-cpp/) step by step. This tool has been developed by OG intern Vidhi Srivastava.

![Screenshot](./output.png)

## Table of Contents
- [Purpose of Implementation](#Purpose-of-Implementation)
- [Project Implementation](#Project-Implementation)
   - [Project Structure](#Project-Structure)
- [Built With](#built-with)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
- [Authors](#authors)
- [Show Your Support](#show-your-support)

## Purpose of Implementation
The purpose of implementing the Trading App is to offer users a powerful tool that facilitates real-time stock trading decisions. This application is designed to empower users with the following key functionalities:

- Real-time Data Monitoring: The app continuously tracks stock prices in real-time, ensuring users have access to up-to-the-minute market information.

- Signal Generation: Based on user-defined criteria, the app generates signals to either buy or sell stocks when specific conditions are met. This feature assists users in making timely trading decisions.

- Cost Calculation: Users can easily determine the cost of stocks at the moment when a signal is generated, aiding them in assessing potential profit or loss.


## Project Implementation

This section provides an overview of the implementation of the trading application and how the source code is organized.

### Project Structure

The trading application is organized into several files, each serving a specific purpose. Here's an overview of the project structure:

- **`curl_functions.hpp` and `curl_functions.cpp`:** These files contain functions for making HTTP requests to fetch stock data from an external API. Specifically, they include:
  - `get_price(const string& ticker_symbol, const string& api)`: Retrieves the price of a stock.
  - `get_stock_quote(const string& ticker_symbol, const string& api)`: Retrieves detailed stock information.

- **`functions.hpp` and `functions.cpp`:** These files define functions related to the trading logic of the application, including:
  - `ProfitLoss(float open, float close, string name)`: Calculates and displays the profit or loss percentage for a stock.
  - `wantTransact(string ans, int amount, float price)`: Handles user input for buying or selling stock and calculates the cost.
  - `print_data(string name, string exchange, string currency, float open, float high, float low, float close, float volume, float change, float price)`: Prints detailed stock information.
  - `Sendsignal(float price, float high, float low, string ans, int amount)`: Determines whether to send a buying or selling signal based on stock price.

- **`main.cpp`:** The main entry point of the application, where user interactions and the core logic of the program are implemented. This file:
  - Prompts the user for a ticker symbol.
  - Reads the API key from the `config.json` file.
  - Makes use of functions from other files to fetch stock data and perform trading-related tasks.
  - Can be customized to add additional trading strategies and features.

- **`config.json`:** This JSON configuration file stores sensitive information, such as the API key required to access external data sources. It's crucial for maintaining security and allows for easy configuration without modifying the code.


## Built With

This application is primarily built using C++ STL (Standard Template Library).

## Getting Started

To get started with the Trading App, follow these steps:

1. Download or clone this repository using the following command:
   ```
   git clone https://github.com/OpenGenus/trading-app-in-cpp.git
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

- **API Key:** Sign up at Twelve Data to obtain your own API key. Place your API key in the `config.json` file.

## Authors 👤

### Vidhi Srivastava

- [GitHub](https://github.com/Vidhi0229)
- [LinkedIn](https://www.linkedin.com/in/vidhisrivastava01/)

## Show Your Support ⭐️⭐️

If you find this project helpful or interesting, please consider giving it a star!

