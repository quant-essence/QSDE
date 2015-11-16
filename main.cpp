#include <iostream>
#include <iomanip>
#include "HistData.h"

using namespace std;

int main()
{
    // create pointer to HistData Object that loads historic prices on construction
    HistData* data = new HistData();

    cout << "nr of objects in hist_data: " << data->GetSize() << endl;
    cout << "sizeof(data):" << sizeof(data) << endl;
    cout << endl;

    // test: print object values
    for(size_t i=0; i<data->GetSize(); i++)
    {
        cout << put_time(data->GetTime(i), "%F %T") << " "
        << data->GetOpen(i) << " "
        << data->GetHigh(i) << " "
        << data->GetLow(i) << " "
        << data->GetClose(i) << endl;
    }

    // free memory of object
    delete(data);

    return 0;
}