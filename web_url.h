#pragma once

#include <string>
#include <iostream>

enum class State {
	scheme,
	authority1,
	authority2,
	path,
};

class Web_url {
private:
	std::string url;
	std::string scheme;
	std::string authority;
	std::string path;
public:
	Web_url(std::string url);
	std::string get_url() const;
	std::string get_scheme() const;
	std::string get_authority() const;
	std::string get_path() const;
};

std::ostream& operator<<(std::ostream& out, const Web_url& url);
