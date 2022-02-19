#include <iostream>
#include <string>

#include "web_url.h"
#include "camera_image.h"
#include "store.h"

void run_section_a();
void run_section_b();
void run_section_c();

int main()
{
	std::cout << "Section A\n";
	std::cout << "=========\n";
	run_section_a();
	std::cout << "\nSection B\n";
	std::cout << "=========\n";
	run_section_b();
	std::cout << "\nSection C\n";
	std::cout << "=========\n";
	run_section_c();
	return 0;
}

void run_section_a()
{
	Web_url url {"https://example.com/about-us/"};
	std::cout << "url = " << url.get_url() << '\n';
	std::cout << "scheme = " << url.get_scheme() << '\n';
	std::cout << "authority = " << url.get_authority() << '\n';
	std::cout << "path = " << url.get_path() << '\n';
	std::cout << url;
}

void run_section_b()
{
	Camera_image image;
	std::cout << image;
	Camera_image image2 {
		"mountains",
		"JPEG",
		"2022-01-01",
		1.5,
		"Khang",
		200,
		300,
		8,
		30,
		600,
		true,
	};
	std::cout << '\n';
	std::cout << image2;
	Camera_image image3 {
		"cats",
		"SVG",
		"2022-01-05",
		1.5,
		"Khang",
		-200,
		-300,
		0,
		-30,
		600,
		false,
	};
	std::cout << '\n';
	std::cout << image3;
}

// Add a function called `processOrder` to the _store_ class that takes a const reference to an _order_ object. This function should remove all the items in the order from the store. For example, if I have a store with 5 books and 3 colored pencils and an order for 2 books and 1 colored pencil. The result of this function should be that the store now contains 3 books and 2 colored pencils.
void run_section_c()
{
	Item book {"Book", 1, 25, 5};
	Item colored_pencils {"Colored pencils", 2, 5, 3};
	Store store;
	Item book_in_order {"Book", 1, 25, 2};
	Item colored_pencils_in_order {"Colored pencils", 2, 5, 1};
	Order order;
	store.add_item(book);
	store.add_item(colored_pencils);
	order.add_item(book_in_order);
	order.add_item(colored_pencils_in_order);
	std::cout << store;
	store.processOrder(order);
	std::cout << "After processing the order:\n";
	std::cout << store;
	std::cout << "\nTotal price:" << order.get_total_price() << '\n';
}
