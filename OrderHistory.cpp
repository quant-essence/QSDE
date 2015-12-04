/*
 * hold & access all the orders that where triggered & closed in a linked list
 * */

#include "OrderHistory.h"
#include "OrderBook.h"

OrderHistory::OrderHistory()
{
    cout << "constructed: OrderHistory()" << endl;
}

bool OrderHistory::OrderAddToHist(
        int order_type, int order_id,
        float open_price, float stoploss, float takeprofit, float order_profit,
        tm *open_time, tm *close_time, bool report)
{
    return false;
}
