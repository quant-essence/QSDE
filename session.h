/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * session.h
 * Copyright (C) 2015 Quantessence <tim.fass@quantessence.de>
 *
 * orpheus is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * orpheus is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _SESSION_H_
#define _SESSION_H_

using namespace std; //Usind standart libary

//includings
#include <iostream>
#include <string>
#include <time.h>
#include <list>
#include <vector> 


//Order structure
struct Order {
	time_t Open_Time;
	time_t Closing_Time;
	float Open_Price;
	float Closing_Prince;
	float Stoploss;
	float Takeprofit;
	float lot;
	float profit;
};

//main Session Class
// Contains all information and Functions about the current session and orderbook/History
class Session
{
public:
	//Public functions
	Session( void ); //Constructor without argument
	Session(int Session_Number, int Session_Type, int currency_data, int expert_advisor, std::vector<float> parameter); //Constructor with argument
	~Session( void ); //Destructor

	//get functions
	Order get_History_Order(int index); 
	Order get_Open_Order(int index);
	int get_Session_Number();
	int get_Session_Type();
	float High(int index);
	float Low(int index);
	float Open(int index);
	float Close(int Index);
	int* get_Currency_Data();
	float get_Tax();
	int get_Offset();
	float get_balance();

	//set functions
	void set_History_Order(int index, Order order); 
	void add_History_Order(Order order);			//adds order to the History list
	void remove_History_Order(int index);			//removes order from the History list
	void set_Open_Order(int index, Order order);
	void add_Open_Order(Order order);				//adds order to the Open Order List
	void remove_Open_Order(int index);			//removes order from the History list
	void set_Session_Number(int session_number);
	void set_Session_Type(int session_type);
	void set_Currency_Data(int currency_data);
	void set_Tax(float tax);
	void set_Offset(int offset);
	void set_Balance(float balance);
	void add_Balance(float balance);
	
	
	
protected:

private:
	int Session_Number;
	int Session_Type;
	std::vector<Order> Order_Book;
	std::list<Order> Order_History;
	int Currency_Data;
	int Expert_Advisor;
	std::vector<float> Parameter;
	float Tax; //Price of Broker for a trade. Forgot name...
	int Offset;
	float Balance;
	

};

#endif // _SESSION_H_

