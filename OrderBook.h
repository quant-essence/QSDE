/*
 * nested class can access private members of enclosing class ('OrderBook')
 * but enclosing class can NOT access members of nested class
 * */

#ifndef QSDE_ORDERBOOK_H
#define QSDE_ORDERBOOK_H

#include <iostream>
#include <forward_list>
#include <iomanip>

using namespace std;

class OrderBook
{
    struct OpenOrder
    {
        int order_type, order_id;
        float open_price, stoploss, takeprofit, order_profit;
        tm open_time;
    };

    forward_list<OpenOrder*> open_orders;

public:
    // construct empty order book
    OrderBook();
    // setter
    int OrderOpen(
        int order_type, int order_id,
        float open_price, float stoploss, float takeprofit,
        tm open_time,
        bool report);
    int OrderClose(int order_id, bool report);
    int OrderModify(int order_id);
    int OrderDelete(int order_id);
    int NrOfOpenOrders(int order_type);
    void OrdersPrint();
};

#endif //QSDE_ORDERBOOK_H
