# Limit Order Book

This project implements a Limit Order Book (LOB) in C++. The Limit Order Book is a data structure used in financial markets to keep track of buy and sell orders. It maintains a list of orders with their respective prices and quantities, allowing for efficient matching of buy and sell orders.

## Features

- **Add Orders:** Add new orders to the order book with specified details such as ID, price, quantity, and type (buy/sell).
  
- **Cancel Orders:** Cancel existing orders by their ID, removing them from the order book.

- **Execute Trades:** Execute trades between buy and sell orders based on price-time priority, updating the order book accordingly.

## Technologies Used

- **C++:** The project is implemented in C++ programming language, leveraging its efficiency and flexibility.
  
## Usage

To use the Limit Order Book:

1. Include the `Order.h` header file in your C++ project.
2. Instantiate a `LimitOrderBook` object.
3. Use the provided methods (`addOrder`, `cancelOrder`, `executeTrades`) to manage orders in the order book.
