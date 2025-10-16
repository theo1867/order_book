#include <iostream>
#include <unordered_map>
#include <vector>
#include "order.h"
#include "order_book.h"

int main() {
    std::cout << "Hello world!\n";
    OrderBook book;
    Order order1(1, 0, 10, Order::Type::MARKET, Order::Side::BUY);
    Order order2(2, 101.0, 20, Order::Type::LIMIT, Order::Side::SELL);
    Order order3(3, 99.0, 5, Order::Type::LIMIT, Order::Side::SELL);
    Order order4(4, 0, 15, Order::Type::MARKET, Order::Side::SELL);
    Order order5(5, 102.0, 10, Order::Type::GTC, Order::Side::BUY);
    Order order6(6, 100.0, 8, Order::Type::FOK, Order::Side::SELL);
    Order order7(7, 99.0, 12,  Order::Type::FOK, Order::Side::BUY);
    Order order8(8, 101.0, 8, Order::Type::FOK, Order::Side::BUY);

    // Add orders to the order book
    book.addOrder(order1);
    book.addOrder(order2);
    book.addOrder(order3);
    book.addOrder(order4);
    book.addOrder(order5);
    book.addOrder(order6);
    book.addOrder(order7);
    book.addOrder(order8);

    std::cout << "Order Book before matching:" << std::endl;
    book.printOrders();

    book.matchOrders();

    // Print the order book after matching
    std::cout << "Order Book after matching:" << std::endl;
    book.printOrders();
}
