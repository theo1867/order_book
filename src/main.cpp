#include <iostream>
#include <unordered_map>
#include <vector>
#include "order_book.h"

int main() {
    std::cout << "Hello world!\n";
    OrderBook book;

    // Add orders to the order book
    book.addOrder({1, {0, -2}, 10, Order::Type::MARKET, Order::Side::BUY});
    book.addOrder({2, {10100, -2}, 20, Order::Type::LIMIT, Order::Side::SELL});
    book.addOrder({3, {9900, -2}, 5, Order::Type::LIMIT, Order::Side::SELL});
    book.addOrder({4, {0, -2}, 15, Order::Type::MARKET, Order::Side::SELL});
    book.addOrder({5, {10200, -2}, 10, Order::Type::GTC, Order::Side::BUY});
    book.addOrder({6, {10000, -2}, 8, Order::Type::FOK, Order::Side::SELL});
    book.addOrder({7, {9900, -2}, 12,  Order::Type::FOK, Order::Side::BUY});
    book.addOrder({8, {10100, -2}, 8, Order::Type::FOK, Order::Side::BUY});

    std::cout << "Order Book before matching:" << std::endl;
    book.printOrders();

    book.matchOrders();

    // Print the order book after matching
    std::cout << "Order Book after matching:" << std::endl;
    book.printOrders();
}
