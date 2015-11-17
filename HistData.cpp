/*
 * class that loads historic data from a .csv file
 * and constructs a vector of 'Tick' objects to hold the
 * historic data.
 * */

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "HistData.h"

HistData::HistData()
{
    // input
    cout << "Please enter file name of history data:" << endl;
    string file_name;
    cin >> file_name;
    cout << "loading data from: " << file_name << "..." << endl;

    // open file stream
    ifstream file;
    file.open(file_name);
    if(!file.is_open()){
        cout << "   couldn't open: " << file_name << endl;
    }

    // string for the stream to read into
    string line;

    // skip header
    getline(file, line);

    // parse csv line by line - reads new line on '/n' by default
    while(getline(file, line))
    {
        // create a stringstream to hold each line
        stringstream line_s(line);
        string value;

        // std:tm - Structure holding a calendar date and time broken down into its components.
        tm date_time;
        // object needed for unix time conversion...
        time_t unix_time;

        float open, high, low, close;
        int count=0;

        // read every string of line seperated by comma
        while(getline(line_s, value, ','))
        {
            stringstream value_s(value);

            switch(count)
            {
                // get date
                case 0:
                    // get_time reads dateformat from stringstream and returns 'time' as a pointer to a 'tm' object
                    value_s >> get_time(&date_time, "%Y%m%d %H:%M:%S");
                    if(value_s.fail()) {
                        cout << "parsing date failed\n";
                    }
                    count++;
                    break;
                case 1:
                    value_s >> open;
                    count++;
                    break;
                case 2:
                    value_s >> high;
                    count++;
                    break;
                case 3:
                    value_s >> low;
                    count++;
                    break;
                case 4:
                    value_s >> close;
                    count = 0;
                    break;
                default:break;
            }
        }

        // convert date_time to unix_time
        // mktime adjusts datetime to localtime
        //unix_time = mktime(&date_time);
        // timegm adjusts datetime to gmt time (!according to SO timegm portability is limited!)
        unix_time = timegm(&date_time);
        long int unix = unix_time;
        //cout << unix << endl;

        //pointer to Tick struct that goes into array
        Tick* tick = new Tick(date_time, open, high, low, close);
        // add pointer to Tick object to vector of historic prices
        hist_data.push_back(tick);
    }
    file.close();
}

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
/* return pointer to tm object
 * */
tm* HistData::GetTime(size_t index)
{
    return hist_data.at(index)->GetTime();
}

float HistData::GetOpen(size_t index)
{
    return hist_data.at(index)->GetOpen();
}

float HistData::GetHigh(size_t index)
{
    return hist_data.at(index)->GetHigh();
}

float HistData::GetLow(size_t index)
{
    return hist_data.at(index)->GetLow();
}

float HistData::GetClose(size_t index)
{
    return hist_data.at(index)->GetClose();
}

size_t HistData::GetSize()
{
    return hist_data.size();
}