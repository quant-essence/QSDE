//
// Created by ole on 19.11.15.
//

#ifndef QSDE_ORDERHISTORY_H
#define QSDE_ORDERHISTORY_H

#include <time.h>
#include "OrderBook.h"

class OrderHistory
{
    /*
     *
     * */
    struct ClosedOrder
    {
        int order_type, order_id;
        float open_price, stoploss, takeprofit, order_profit;
        tm* open_time, close_time;
    };

    forward_list<ClosedOrder*> order_history;

public:
    // setter
    int OrderHistory();

    //
    bool OrderAddToHist(int order_type, int order_id,
                        float open_price, float stoploss, float takeprofit, float order_profit,
                        tm* open_time, tm* close_time,
                        bool report);
};


#endif //QSDE_ORDERHISTORY_H
