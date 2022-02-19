#include "store.h"

Item::Item(std::string name, long id, double price, int cnt)
{
	this->name = name;
	this->id = id;
	if (price >= 0)
		this->price = price;
	else
		this->price = 0;
	if (this->cnt >= 0)
		this->cnt = cnt;
	else
		this->cnt = 0;
}

void Item::set_name(std::string name)
{
	this->name = name;
}

std::string Item::get_name() const
{
	return name;
}

void Item::set_id(long id)
{
	this->id = id;
}

long Item::get_id() const
{
	return id;
}

void Item::set_price(double price)
{
	if (price > 0) {
		this->price = price;
	}
}

double Item::get_price() const
{
	return price;
}

void Item::set_count(int cnt)
{
	if (cnt >= 0) {
		this->cnt = cnt;
	}
}

int Item::get_count() const
{
	return cnt;
}

std::ostream& operator<<(std::ostream& out, const Item& item)
{
	out << "Name: " << item.get_name()
	    << "Id: " << item.get_id()
	    << "Price: " << item.get_price()
	    << "Quantity in stock: " << item.get_count();
	return out;
}

void Store::add_item(Item item)
{
	items.push_back(item);
}

std::vector<Item> Store::get_items() const
{
	return items;
}

void Store::processOrder(const Order& order)
{
	for (auto& i : items) {
		for (auto& j : order.get_items()) {
			if (i.get_name() == j.get_name()) {
				i.set_count(i.get_count() - j.get_count());
			}
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Store& store)
{
	out << "Store:\n";
	for (Item item : store.get_items()) {
		out << item.get_name() << " x " << item.get_count() << '\n';
	}
	return out;
}

void Order::add_item(Item item)
{
	items.push_back(item);
}

std::vector<Item> Order::get_items() const
{
	return items;
}

double Order::get_total_price() const
{
	double total = 0;
	for (Item item : items) {
		total += item.get_price() * item.get_count();
	}
	return total;
}
