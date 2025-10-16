#include <iostream>
#include "order.h"

Order::Order(int id, double price, int quantity, Order::Type type, Order::Side side)
    : m_id(id), m_price(price), m_quantity(quantity), m_type(type), m_side(side) {}

int Order::getId() const {
    return m_id;
}

double Order::getPrice() const {
    return m_price;
}

Order::Type Order::getType() const {
    return m_type;
}

Order::Side Order::getSide() const {
    return m_side;
}

int Order::getQuantity() const {
    return m_quantity;
}

void Order::setQuantity(int quantity) {
    m_quantity = quantity;
}

void Order::printOrder() {
    std::cout << "Order ID: " << m_id
              << ", Price: " << m_price
              << ", Type: " << static_cast<int>(m_type)
              << ", Side: " << (m_side == Order::BUY ? "Buy" : "Sell")
              << ", Quantity: " << m_quantity
              << '\n';
}