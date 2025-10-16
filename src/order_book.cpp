#include "order_book.h"

void OrderBook::addOrder(const Order& order) {
    m_orders.push_back(order);
    m_orderMap[order.getId()] = m_orders.size() - 1;
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
            if (buyOrder.getPrice() >= sellOrder.getPrice()) {
                int fillQty = std::min(buyOrder.getQuantity(), sellOrder.getQuantity());
                executeOrder(buyOrder.getId(), sellOrder.getId(), fillQty);
                buyOrder.setQuantity(buyOrder.getQuantity() - fillQty);
                sellOrder.setQuantity(sellOrder.getQuantity() - fillQty);
                if (buyOrder.getQuantity() == 0) {
                    break;
                }
            }
        }
    }
}

void OrderBook::printOrders() {
    for (auto& order : m_orders) {
        order.printOrder();
    }
}