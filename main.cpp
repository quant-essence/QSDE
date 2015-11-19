#include <iostream>
#include <iomanip>
#include "HistData.h"
#include "OrderBook.h"

using namespace std;

int main()
{
    /*
     * LOAD HIST DATA
     */

    // create pointer to HistData Object that loads historic prices on construction
    HistData* data = new HistData();

    // Info
    /*
    cout << "nr of objects in hist_data: " << data->GetSize() << endl;
    cout << "sizeof(data):" << sizeof(data) << endl;
    cout << endl;*/

    // Test: print first 10 object values
    for(size_t i=0; i<5; i++)
    {
        cout << put_time(data->GetTime(i), "%F %T") << " "
        << data->GetOpen(i) << " "
        << data->GetHigh(i) << " "
        << data->GetLow(i) << " "
        << data->GetClose(i) << endl;
    }

    /*
     * SETUP ENVIRONMENT
     * */
    // create OrderBook for open orders
    OrderBook* order_book = new OrderBook();

    // TEST
    order_book->OrderOpen(1,123,1.34,1.33,1.35,data->GetTime(0),true);
    order_book->OrdersPrint(-1);
    order_book->OrderModify(123,1.33,1.32,1.34,true);
    order_book->OrdersPrint(123);
    order_book->OrderClose(123,true);
    order_book->OrdersPrint(0);



    // free memory of objects
    delete(data);
    delete(order_book);

    return 0;
}