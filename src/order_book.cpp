#include "order_book.h"

void OrderBook::addOrder(const Order& order) {
    m_orders.push_back(order);
    m_orderMap[order.id] = m_orders.size() - 1;
}

void OrderBook::cancelOrder(const int id) {
    auto it = m_orderMap.find(id);
    if (it == m_orderMap.end()) {
        std::cout << "Cancelling order failed: order id not found!\n";
        return;
    }

    m_orders.erase(m_orders.begin() + m_orderMap[id]);
    m_orderMap.erase(it);
}

void OrderBook::matchOrders() {
    auto buyOrders = getOrdersBySide(Order::Side::BUY);
    auto sellOrders = getOrdersBySide(Order::Side::SELL);
    for (auto& buyOrder : buyOrders) {
        for (auto& sellOrder : sellOrders) {
            if (buyOrder.price >= sellOrder.price) {
                int fillQty = std::min(buyOrder.quantity, sellOrder.quantity);
                executeOrder(buyOrder.id, sellOrder.id, fillQty);
                buyOrder.quantity -= fillQty;
                sellOrder.quantity -= fillQty;
                if (buyOrder.quantity == 0) {
                    break;
                }
            }
        }
    }
}

void OrderBook::printOrders() {
    for (auto& order : m_orders) {
            std::cout << "Order ID: " << order.id
              << ", Price: " << order.price
              << ", Type: " << static_cast<int>(order.type)
              << ", Side: " << (order.side == Order::Side::BUY ? "Buy" : "Sell")
              << ", Quantity: " << order.quantity
              << '\n';
    }
}