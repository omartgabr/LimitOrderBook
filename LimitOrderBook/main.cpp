// LimitOrderBook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>
#include "Order.h"

int main() {
    // Create a LimitOrderBook instance
    LimitOrderBook orderBook;

    // Add some sample orders to the order book
    orderBook.addOrder(Order(1, 100.0, 10, true));   // Buy order: ID 1, Price 100.0, Quantity 10
    orderBook.addOrder(Order(2, 105.0, 15, true));   // Buy order: ID 2, Price 105.0, Quantity 15
    orderBook.addOrder(Order(3, 110.0, 20, false));  // Sell order: ID 3, Price 110.0, Quantity 20
    orderBook.addOrder(Order(4, 108.0, 12, false));  // Sell order: ID 4, Price 108.0, Quantity 12

    // Execute trades between buy and sell orders in the order book
    //orderBook.executeTrades();

    return 0;
}