/*
 * class that implements the order book to hold information about
 * open / pending orders and offers methods to create, delete or
 * modify 'OpenOrder' objects.
 * */


#include "OrderBook.h"

OrderBook::OrderBook() {}

int OrderBook::OrderOpen(int order_type, int order_id,
                         float open_price, float stoploss, float takeprofit,
                         tm open_time,
                         bool report)
{
    // create new order
    //OpenOrder* open_order = new OpenOrder();
    OpenOrder* open_order;
    open_order->order_type = order_type;
    open_order->order_id = order_id;
    open_order->open_price = open_price;
    open_order->stoploss = stoploss;
    open_order->takeprofit = takeprofit;
    open_order->order_profit = 0;
    open_order->open_time = open_time;

    // add open_order as first element in list
    open_orders.push_front(open_order);

    if(report)
        cout << "OrderOpen(): added order#" << order_id << endl;

    //
    return order_id;
}

int OrderBook::OrderModify(int order_id)
{
    return order_id;
}

int OrderBook::OrderClose(int order_id, bool report)
{
    if(report && open_orders.empty())
        cout << "OrderClose(): no open orders in OrderBook" << endl;

    // iterate list
    forward_list<OrderBook::OpenOrder*>:: iterator iterator1;

    for(iterator1 = open_orders.begin();
    iterator1 != open_orders.end();
    iterator1++)
    {
        cout << (*iterator1)->order_id << endl;
        if((*iterator1)->order_id == order_id)
        {
            try{
                open_orders.remove(*iterator1);
                cout << "OrderClose(): closed order" << order_id << endl;
            }
            catch (int e){
                cout << "*** Error deleting from position " << order_id << " ***" << endl;
            }

            /*
            open_orders.remove(*iterator1);
            if(report)
                cout << "OrderClose(): closed order" << order_id << endl;*/
        }
        //cout << "closed order" << order_id << endl;
    }

    return order_id;
}

int OrderBook::OrderDelete(int order_id)
{
    // iterate list

    return order_id;
}

int OrderBook::NrOfOpenOrders(int order_type)
{
    if(open_orders.empty())
        return 0;

    // for performance reasons the forward list does not keep track of its size
    // size can be obtained by the difference between begin & end
    forward_list<OrderBook::OpenOrder*>::iterator first = open_orders.begin();
    //forward_list<OrderBook::OpenOrder*>::iterator last = open_orders.end();
    forward_list<OpenOrder*>::iterator last = open_orders.end();
    return (int) distance(first,last);
}

void OrderBook::OrdersPrint()
{
    if(open_orders.empty())
        cout << "OrdersPrint(): no open orders found" << endl;

    // iterate list
    forward_list<OrderBook::OpenOrder*>:: iterator iterator1;

    for(iterator1 = open_orders.begin();
        iterator1 != open_orders.end();
        iterator1++)
    {
        cout << "OrdersPrint(): order_id = " << (*iterator1)->order_id << endl;
    }
}
