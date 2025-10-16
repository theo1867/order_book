#pragma once
#include <iostream>

class Order {
public:
    enum Side {
        BUY,
        SELL
    };

    enum Type {
        MARKET,
        LIMIT,
        STOP,
        GTC,
        FOK
    };

    Order(int id, double price, int quantity, Type type, Side side);
    int getId() const;
    double getPrice() const;
    Type getType() const;
    Side getSide() const;
    int getQuantity() const;
    void setQuantity(int quantity);
    void printOrder();

private:
    int m_id;
    double m_price;
    Type m_type;
    Side m_side;
    int m_quantity;
};