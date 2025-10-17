#pragma once
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

struct Price {
    long long mantissa{};
    int exponent{};

    int compare(const Price& rhs) const {
        if (exponent == rhs.exponent) {
            return mantissa < rhs.mantissa ? -1 : mantissa == rhs.mantissa ? 0 : 1;
        }

        if (exponent < rhs.exponent) {
            long long normalizedMantissa = mantissa * static_cast<long long>(std::pow(10, exponent - rhs.exponent));
            return normalizedMantissa < rhs.mantissa ? -1 : normalizedMantissa == rhs.mantissa ? 0 : 1;
        }

        long long normalizedMantissa = rhs.mantissa * static_cast<long long>(std::pow(10, rhs.mantissa - exponent));
        return mantissa < normalizedMantissa ? -1 : mantissa == normalizedMantissa ? 0 : 1;
    }

    bool operator<(const Price& rhs) const {
        return compare(rhs) == -1;
    }
    bool operator<=(const Price& rhs) const {
        return compare(rhs) <= 0;
    }
    bool operator==(const Price& rhs) const {
        return compare(rhs) == 0;
    }
    bool operator>=(const Price& rhs) const {
        return compare(rhs) >= 0;
    }
    bool operator>(const Price& rhs) const {
        return compare(rhs) == 1;
    }
};

struct Order {
    enum class Side { BUY, SELL };
    enum class Type { MARKET, LIMIT, STOP, GTC, FOK };

    int id{};
    Price price;
    int quantity{};
    Type type{};
    Side side{};
};


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
            if (order.side == side) {
                result.push_back(order);
            }
        }
        std::sort(result.begin(), result.end(), [](const Order& a, const Order& b) {
            return a.price < b.price;
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
                  << " at Price: " << m_orders[sellIt->second].price.mantissa << "e" << m_orders[sellIt->second].price.exponent
                  << " for Quantity: " << quantity << '\n';

        m_orders[buyIt->second].quantity -= quantity;
        m_orders[sellIt->second].quantity -= quantity;
    }
};