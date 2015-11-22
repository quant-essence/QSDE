/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * session.cc
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

#include "session.h"

Session::Session( void ) //Constructor without argument
{
	//creates minimal necesarry variables
	//to be done
}


Session::Session(int Session_Number, int Session_Type, int currency_data, int expert_advisor, std::vector<float> parameter) //Constructor with argument
{
	// Fills vaiables on creation
	//to be done
}


Session::~Session( void ) //Destructor
{
	//handels necessary task upon destruktion of Session
}



//get functions----------------------------------------------------------------------------------+
Order Session::get_History_Order(int index) 
{
	//gets specefic order from the History_Order List at index 
	//to be done
}


Order Session::get_Open_Order(int index)
{
	//gets specefic order from the Open_Order List at index 
	//to be done
}


int Session::get_Session_Number()
{
	//gets session number
	return Session_Number;
}


int Session::get_Session_Type()
{
	//gets session Type
	return Session_Type;
}


float Session::High(int index)
{
	//gets High value from index Posiion in currency data at index
	//to be done
}


float Session::Low(int index)
{
	//gets High value from index Posiion in currency data at index
	//to be done
}


float Session::Open(int index)
{
	//gets High value from index Posiion in currency data at index
	//to be done
}


float Session::Close(int Index)
{
	//gets High value from index Posiion in currency data at index
	//to be done
}


int* Session::get_Currency_Data()
{
	//return handle to curreny data
	return Currency_Data;
}


float Session::get_Tax()
{
	//returns tax
	return Tax;
}


int Session::get_Offset()
{
	//gets offset
	return Offset;
}


float Session::get_Balance()
{
	// gets current Balance
	return Balance;
}



	//set functions-------------------------------------------------------------------------------------+
void Session::set_History_Order(int index, Order order)
{
	// overwrites specefic order at index in History Order List
	//to be done
}


void Session::add_History_Order(Order order)			//adds order to the History list
{
	//adds Order at the Beginning of History Order List
	Order_History.push_front(order);
}


void Session::remove_History_Order(int index)			//removes order from the History list
{
	// removes Order at index from History Order List
	Order_History.erase(index);
}


void Session::set_Open_Order(int index, Order order)
{
	// Overwrites order at index from Open Order List
	//to be done
}


void Session::add_Open_Order(Order order)				//adds order to the Open Order List
{
	//adds Order at the Beginning of Open Order order list
	Order_Book.push_front(order);
}


void Session::remove_Open_Order(int index)				//removes order from the History list
{
	//removes order at index from Open Order list
	Order_Book.erase(index);
}


void Session::set_Session_Number(int session_number)
{
	//Sets the Session_Number
	Session_Number=session_number;
}


void Session::set_Session_Type(int session_type)
{
	//sets Session Type
	Session_Type=session_type;
}


void Session::set_Currency_Data(int currency_data)
{
	//sets curency data pointer
	Currency_Data=currency_data;
}


void Session::set_Tax(float tax)
{
	//sets Tax
	Tax=tax;
}

void Session::set_Offset(int offset)
{
	//sets Offset
	Offset=offset;
}


void Session::set_Balance(float balance)
{
	//sets Balance
	Balance=balance;
}

void Session::add_Balance(float profit)
{
	Balance=Balance+profit;
}




