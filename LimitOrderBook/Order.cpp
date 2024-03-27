
#include <iostream>
#include "Order.h"


/*
* LIMIT ORDER BOOK METHODS IMPLEMENTATION
*/
void LimitOrderBook::executeTradesAtPrice(std::vector<Order>& buyOrdersAtPrice, std::vector<Order>& sellOrdersAtPrice, double price)
{

}

// addOrder
void LimitOrderBook::addOrder(const Order& order)
{
	// We want to add an order to the ordersById map
	ordersById[order.id] = order;

	// determine if order is buy or sell
	if (order.isBuy)
	{
		// add buy order to the buyOrders map
		buyOrders[order.price].push_back(order);
	}
	else
	{
		// Add sell order to the sellOrders map
		sellOrders[order.price].push_back(order);
	}
}

// cancelOrder
void LimitOrderBook::cancelOrder(int orderId)
{
	auto it = ordersById.find(orderId);
	if (it != ordersById.end())
	{
		// remove order from ordersById
		ordersById.erase(it);

		// determine whether the order is Buy or Sell to remove from the corresponding map
		const Order& order = it->second;
		if (order.isBuy)
		{
			for (auto& pair : buyOrders)
			{
				auto& orders = pair.second;
				orders.erase(std::remove_if(orders.begin(), orders.end(), [orderId](const Order& o){return o.id == orderId;}), orders.end());
			}
		}
		else
		{
			for (auto& pair : sellOrders)
			{
				auto& orders = pair.second;
				orders.erase(std::remove_if(orders.begin(), orders.end(), [orderId](const Order& o) {return o.id == orderId; }), orders.end());
			}
		}
	}
	else
	{
		std::cout << "Order with ID " << orderId << " not found." << std::endl;
	}
}

// executeOrder
void LimitOrderBook::executeTrades()
{
	// iterate over buyOrders that is already sorted in descending order of prices
	for (auto it_buy = buyOrders.begin(); it_buy != buyOrders.end(); ++it_buy)
	{
		double buyPrice = it_buy->first;
		auto& buyOrdersAtPrice = it_buy->second;

		// iterate over sellOrders sorted in ascending order of prices
		for (auto it_sell = sellOrders.begin(); it_sell != sellOrders.end(); ++it_sell)
		{
			double sellPrice = it_sell->first;
			auto& sellOrdersAtPrice = it_sell->second;

			// check if there's a match between buy and sell orders
			if (buyPrice = sellPrice)
			{
				executeTradesAtPrice(buyOrdersAtPrice, sellOrdersAtPrice, buyPrice);
				updateOrderBookAfterTrades(buyPrice, sellPrice);
				break;
			}
		}
	}

}
