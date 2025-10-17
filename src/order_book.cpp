#include "order_book.h"

void OrderBook::addOrder(const Order& order) {
    m_orders.push_back(order);
    m_orderMap[order.id] = m_orders.size() - 1;
    matchOrders();
}

void OrderBook::cancelOrder(const int id) {
    auto it = m_orderMap.find(id);
    if (it == m_orderMap.end()) {
        std::cout << "Cancelling order failed: order id not found!\n";
        return;
    }

    m_orders.erase(m_orders.begin() + m_orderMap[id]);
    m_orderMap.erase(it);
    matchOrders();
}

void OrderBook::printOrders() {
    for (auto& order : m_orders) {
            std::cout << "Order ID: " << order.id
              << ", Price: " << order.price.mantissa << "e" << order.price.exponent
              << ", Type: " << static_cast<int>(order.type)
              << ", Side: " << (order.side == Order::Side::BUY ? "Buy" : "Sell")
              << ", Quantity: " << order.quantity
              << '\n';
    }
}