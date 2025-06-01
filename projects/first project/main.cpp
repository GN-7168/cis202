/* 
    File: main.cpp 
    Description: 11.1 Lambda functions and a Pizza Order Sorter
    Author: Gregory Newland
    Email: gregorn7168@student.vvc.edu
    Course#: cis202
    Section#: 30001
    Date: 20250601
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct PizzaOrder {
    std::string name;
    int size;
};

int main() {
    std::vector<PizzaOrder> orders = {
        {"Alice", 12}, {"Bob", 16}, {"Charlie", 10}, {"Diana", 14}
    };

    std::cout << "Original Pizza Orders:\n";
    for (const auto& order : orders)
        std::cout << order.name << " " << order.size << " inches\n";
    std::cout << "\n";

    std::sort(orders.begin(), orders.end(), [](const PizzaOrder& a, const PizzaOrder& b) {
        return a.size < b.size;
    });

    std::cout << "Sorted by Size (Ascending):\n";
    for (const auto& order : orders)
        std::cout << order.name << " " << order.size << " inches\n";
    std::cout << "\n";

    std::sort(orders.begin(), orders.end(), [](const PizzaOrder& a, const PizzaOrder& b) {
        return a.name < b.name;
    });

    std::cout << "Sorted by Name (Alphabetical):\n";
    for (const auto& order : orders)
        std::cout << order.name << " " << order.size << " inches\n";
    std::cout << "\n";

    struct PizzaOrderWithPrice {
        std::string name;
        int size;
        double price;
    };

    std::vector<PizzaOrderWithPrice> pricedOrders = {
        {"Alice", 12, 11.99},
        {"Bob", 16, 15.49},
        {"Charlie", 10, 9.99},
        {"Diana", 14, 13.75}
    };

    std::sort(pricedOrders.begin(), pricedOrders.end(), [](const PizzaOrderWithPrice& a, const PizzaOrderWithPrice& b) {
        return a.price < b.price;
    });

    auto printOrdersWithPrice = [](const std::vector<PizzaOrderWithPrice>& orders) {
        for (const auto& order : orders)
            std::cout << order.name << " " << order.size << " inches $" << order.price << "\n";
    };

    std::cout << "Sorted by Price (Ascending):\n";
    printOrdersWithPrice(pricedOrders);

    return 0;
}
