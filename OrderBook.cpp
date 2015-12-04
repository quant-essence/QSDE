/*
 * class that implements the order book to hold information about
 * open / pending orders and offers methods to create, delete or
 * modify 'OpenOrder' objects.
 * */

#include "OrderBook.h"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
OrderBook::OrderBook()
{
    cout << "constructed: OrderBook()" << endl;
}

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
int OrderBook::OrderOpen(int order_type, int order_id,
                         float open_price, float stoploss, float takeprofit,
                         tm* open_time,
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
    //order_book.push_front(open_order);
    try{
        order_book.push_front(open_order);
        if(report)
            cout << "OrderOpen(): opened order: " << order_id << endl;
    }
    catch(const bad_alloc& ba){
        cout << "*** Error opening order: " << order_id << " - bad allocation: " << ba.what() << " ***" << endl;
    }
    catch(exception &e) {
        cout << "*** Error opening order: " << order_id << " - unhandled exception: " << e.what() << " ***" << endl;
    }
    catch(...){
        cout << "*** Error opening order: " << order_id << " - unknown execption" << endl;
    }
    //
    return order_id;
}

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
int OrderBook::OrderModify(int order_id, float open_price, float stoploss, float takeprofit, bool report)
{
    if(order_book.empty()){
        if(report)
            cout << "OrderModify(): no open orders found" << endl;
        return (-1);
    }

    // iterate list
    forward_list<OrderBook::OpenOrder*>:: iterator i;

    for(i = order_book.begin(); i != order_book.end(); ++i)
    {
        if((*i)->order_id == order_id)
        {
            if(open_price!=0)
            {
                (*i)->open_price = open_price;
                if(report)
                    cout<<"OrderModify(): changed open_price:"<<open_price<<" of order#"<<order_id<<endl;
            }
            if(stoploss!=0)
            {
                (*i)->stoploss = stoploss;
                if(report)
                    cout<<"OrderModify(): changed stoploss:"<<stoploss<<" of order#"<<order_id<<endl;
            }
            if(takeprofit!=0)
            {
                (*i)->takeprofit = takeprofit;
                if(report)
                    cout<<"OrderModify(): changed takeprofit:"<<takeprofit<<" of order#"<<order_id<<endl;
            }
        }

    }
    return order_id;
}

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
int OrderBook::OrderClose(int order_id, bool report)
{
    if(order_book.empty())
    {
        if(report)
            cout << "OrderClose(): no open orders in OrderBook" << endl;
        return -1;
    }

    // iterate list
    forward_list<OrderBook::OpenOrder*>:: iterator i;
    for(i=order_book.begin(); i!=order_book.end(); ++i)
    {
        if((*i)->order_id == order_id)
        {
            // .remove() doesnt throw execptions
            order_book.remove(*i);
            if(report)
                cout << "OrderClose(): closed order" << order_id << endl;
            break;
        }
    }
    return order_id;
}

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
int OrderBook::OrderDelete(int order_id)
{
    // iterate list
    return order_id;
}

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
int OrderBook::NrOfOpenOrders(int order_type)
{
    if(order_book.empty())
        return (-1);

    int count=0;

    // count all orders
    if(order_type<0)
    {
        // for performance reasons the forward list does not keep track of its size
        // size can be obtained by the difference between begin & end
        forward_list<OrderBook::OpenOrder *>::iterator first = order_book.begin();
        forward_list<OpenOrder *>::iterator last = order_book.end();
        count = (int) distance(first, last);
    }
    else
    {
        forward_list<OrderBook::OpenOrder*>:: iterator i;
        for(i=order_book.begin(); i!=order_book.end(); i++)
        {
            if((*i)->order_type==order_type)
                count++;
        }
    }
    return count;
}

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
void OrderBook::OrdersPrint(int order_id)
{
    if(order_book.empty())
        cout << "OrdersPrint(): no open orders found" << endl;

    // print all orders
    if(order_id<0)
    {
        // iterate list
        forward_list<OrderBook::OpenOrder*>:: iterator i;
        for(i=order_book.begin(); i!=order_book.end(); ++i)
        {
            cout << "OrdersPrint(all): " << endl <<
            "order_id = "<<(*i)->order_id << endl <<
            "order_type = "<<(*i)->order_type << endl <<
            "open_time = "<<put_time((*i)->open_time, "%F %T")<< endl <<
            "open_price = "<<(*i)->open_price<< endl <<
            "stoploss = "<<(*i)->stoploss<< endl <<
            "takeprofit = "<<(*i)->takeprofit<< endl <<
            "open_price = "<<(*i)->open_price << endl;
        }
    }
    else
    {
        forward_list<OpenOrder*>:: iterator i = order_book.begin();
        while(i!=order_book.end())
        {
            if((*i)->order_id==order_id)
            {
                cout << "OrdersPrint("<<order_id<<"): " << endl <<
                "order_id = "<<(*i)->order_id << endl <<
                "order_type = "<<(*i)->order_type << endl <<
                "open_time = "<<put_time((*i)->open_time, "%F %T")<< endl <<
                "open_price = "<<(*i)->open_price<< endl <<
                "stoploss = "<<(*i)->stoploss<< endl <<
                "takeprofit = "<<(*i)->takeprofit<< endl <<
                "open_price = "<<(*i)->open_price << endl;
            }
            ++i;
        }
    }
}

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
/*
 * TODO: diese Funktion soll automatisch erkennen ob bei offenen/pending Buy/Sell Orders:
 * - der TP/SL ausgelöst wurde
 * - geschlossene orders in die OrderHistory überführt und aus dem OrderBook gelöscht werden
 * - der open_price von pending Orders ausgelöst wurde, so dass diese geöffnet werden
 * - FRAGE: wäre es besser, wenn das OrderHistory Object global wäre, so dass kein pointer übergeben werden muss?
 * */
int OrderBook::OrderControl(OrderHistory* orderHistory, Tick* tick, bool report)
{
    if(order_book.empty())
    {
        if(report)
            cout << "OrderControl(): no open orders found" << endl;
        return (0);
    }

    int count=0;
    forward_list<OpenOrder*>:: iterator i = order_book.begin();
    while(i!=order_book.end())
    {
        // BUY ORDERS
        // open order
        if((*i)->order_type == 0)
        {
            if((*i)->takeprofit!=0 && tick->GetHigh() >= (*i)->takeprofit)
            {
                orderHistory->OrderAddToHist(
                        (*i)->order_type, (*i)->order_id,
                        (*i)->open_price, (*i)->stoploss, (*i)->takeprofit, (*i)->order_profit,
                        (*i)->open_time, tick->GetTime(), report);
                if(report)
                    cout << "OrderControl(): closed BuyOrder #" << (*i)->order_id << " by TP " << endl;
            }
            if((*i)->stoploss != 0 && tick->GetLow() <= (*i)->stoploss)
            {
                orderHistory->OrderAddToHist(
                        (*i)->order_type, (*i)->order_id,
                        (*i)->open_price, (*i)->stoploss, (*i)->takeprofit,
                        (*i)->open_time, tick->GetTime(), report);
                if(report)
                    cout << "OrderControl(): closed BuyOrder #" << (*i)->order_id << " by SL " << endl;
            }

        }
        // stop order
        if((*i)->order_type == 2)
        {

        }
        // pending order
        if((*i)->order_type == 4)
        {

        }

        // SELL ORDERS
        if((*i)->order_type == 1)
        {

        }
        if((*i)->order_type == 3)
        {

        }
        if((*i)->order_type == 5)
        {

        }
        ++i;
    }
}
