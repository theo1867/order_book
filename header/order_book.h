#pragma once
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "order.h"

class OrderBook {
public:
    void addOrder(const Order& order);
    void cancelOrder(const int orderId);
    void matchOrders();
    void printOrders();

private:
    std::vector<Order> m_orders;
    std::unordered_map<int, size_t> m_orderMap;

    std::vector<Order> getOrdersBySide(Order::Side side) {
        std::vector<Order> result;
        for (auto& order: m_orders) {
            if (order.getSide() == side) {
                result.push_back(order);
            }
        }
        std::sort(result.begin(), result.end(), [](const Order& a, const Order& b) {
            return a.getPrice() < b.getPrice();
        });
        return result;
    }

    void executeOrder(int buyOrderId, int sellOrderId, int quantity) {
        auto buyIt = m_orderMap.find(buyOrderId);
        if (buyIt == m_orderMap.end()) {
            std::cout << "Error: cannot find buy order to execute\n";
            return;
        }

        auto sellIt = m_orderMap.find(sellOrderId);
        if (sellIt == m_orderMap.end()) {
            std::cout << "Error: cannot find sell order to execute\n";
            return;
        }

        std::cout << "Buy Order ID: " 
                  << buyOrderId
                  << " with Sell Order ID: " << sellOrderId
                  << " at Price: " << std::fixed << std::setprecision(2) << m_orders[sellIt->second].getPrice()
                  << " for Quantity: " << quantity << '\n';

        m_orders[buyIt->second].setQuantity(m_orders[buyIt->second].getQuantity() - quantity);
        m_orders[sellIt->second].setQuantity(m_orders[sellIt->second].getQuantity() - quantity);
    }
};