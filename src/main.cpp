#include <iostream>
#include <unordered_map>
#include <vector>
#include "order_book.h"

int main() {
    std::cout << "Hello world!\n";
    OrderBook book;

    // Add orders to the order book
    book.addOrder({1, {0, -2}, 10, Order::Type::MARKET, Order::Side::BUY});
    std::cout << "After order 1:\n";
    book.printOrders();
    std::cout << std::endl;
    book.addOrder({2, {10100, -2}, 20, Order::Type::LIMIT, Order::Side::SELL});
    std::cout << "After order 2:\n";
    book.printOrders();
    std::cout << std::endl;
    book.addOrder({3, {9900, -2}, 5, Order::Type::LIMIT, Order::Side::SELL});
    std::cout << "After order 3:\n";
    book.printOrders();
    std::cout << std::endl;
    book.addOrder({4, {0, -2}, 15, Order::Type::MARKET, Order::Side::SELL});
    std::cout << "After order 4:\n";
    book.printOrders();
    std::cout << std::endl;
    book.addOrder({5, {10200, -2}, 10, Order::Type::GTC, Order::Side::BUY});
    std::cout << "After order 5:\n";
    book.printOrders();
    std::cout << std::endl;
    book.addOrder({6, {10000, -2}, 8, Order::Type::FOK, Order::Side::SELL});
    std::cout << "After order 6:\n";
    book.printOrders();
    std::cout << std::endl;
    book.addOrder({7, {9900, -2}, 12,  Order::Type::FOK, Order::Side::BUY});
    std::cout << "After order 7:\n";
    book.printOrders();
    std::cout << std::endl;
    book.addOrder({8, {10100, -2}, 8, Order::Type::FOK, Order::Side::BUY});
    std::cout << "After order 8:\n";
    book.printOrders();
    std::cout << std::endl;
}
