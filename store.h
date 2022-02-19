#pragma once

#include <iostream>
#include <string>
#include <vector>

class Item
{
private:
	std::string name;
	long id;
	double price;
	int cnt;
public:
	Item(std::string name, long id, double price, int cnt);
	void set_name(std::string name);
	std::string get_name() const;
	void set_id(long id);
	long get_id() const;
	void set_price(double price);
	double get_price() const;
	void set_count(int cnt);
	int get_count() const;
};

std::ostream& operator<<(std::ostream& out, const Item& item);

class Order
{
private:
	std::vector<Item> items;
public:
	void add_item(Item item);
	std::vector<Item> get_items() const;
	double get_total_price() const;
};

class Store
{
private:
	std::vector<Item> items;
public:
	void add_item(Item item);
	std::vector<Item> get_items() const;
	void processOrder(const Order& order);
};

std::ostream& operator<<(std::ostream& out, const Store& store);
