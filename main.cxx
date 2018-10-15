/*
 * main.cxx
 * 
 * Copyright 2018 Mason Fisher <mason@extDrive>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include "Wk_ch5-7.cpp"
#include "customerType.h"
using namespace std;

void retMovie(customerType cust, VideoList store, string rentItem)
void rentMovie(customerType cust, VideoList store);

int main(int argc, char **argv)
{
	VideoList list;
	list.insert("Fast and Furious");
	while(int i=0 <2){
		list.incCount("Fast and Furious");
		i++
		}
	list.printInStore();
	
	return 0;
}

void rentMovie(customerType cust, VideoList store, string rentItem){
	store.decCount(rentItem);
	cust.rentVideo(rentItem);
	
}

void retMovie(customerType cust, VideoList store, string rentItem){
	store.incCount(rentItem);
	cust.returnVideo(rentItem);
	
}
