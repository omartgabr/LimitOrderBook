#pragma once

#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

/*
This data structure represents an order in a LOB. The struct data type was chosen due to the public nature of LOB + group data in simple manner
*/ 

struct Order {
    int id; // client id
    double price;
    int quantity;   // quantity of equities
    bool isBuy;  // true for buy order, false for sell 

    // Constructor
    Order(int id, double price, int quantity, bool isBuy)
        : id(id), price(price), quantity(quantity), isBuy(isBuy) {}
};


/*
We want a function that compares each Order price, that way we can sort such orders based on price-time priority
*/
struct CompareOrderPrice
{
    // To compare, we can check if one order price is less than the other
    bool operator()(const Order& a, const Order& b) const
    {
        return a.price < b.price;
    }
};

/*
Now that we have a way to place and compare Orders,
we can create the LOB around this data structure and comparator.
It will be of class type to account for private storage of orders

To achieve O(1) constant time complexity, we want to sort orders using a hash table data structure
 Unordered_map are great quickly retrieving and updating orders when IDs are known in O(1) constant time. These elements are stored in a balanced binary search tree.
 Maps help sort both buy and sell orders based on their prices 
*/
class LimitOrderBook
{
private:
    // map client IDs to orders placed
    std::unordered_map<int, Order> ordersById;
    // sorts buy orders in descending order grouped by price
    std::map<double, std::vector<Order>, std::greater<>> buyOrders;
    // 
    std::map<double, std::vector<Order>> sellOrders;

    void executeTradesAtPrice(std::vector<Order>& buyOrdersAtPrice, std::vector<Order>& sellOrdersAtPrice, double price);
    void updateBookAfterTrades(double buyPrice, double sellPrice);

public:
    // we want functions to include add, cancel, and execute orders
    void addOrder(const Order& order);
    void cancelOrder(int OrderId);
    void executeTrades();
};
