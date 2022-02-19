#include "web_url.h"

Web_url::Web_url(std::string url)
{
	this->url = url;
	State state = State::scheme;
	for (auto &ch : this->url) {
		if (state == State::scheme) {
			if (ch == '/') {
				state = State::authority1;
				authority += ch;
			} else {
				scheme += ch;
			}
		} else if (state == State::authority1) {
			state = State::authority2;
			authority += ch;
		} else if (state == State::authority2) {
			if (ch == '/') {
				state = State::path;
				path += ch;
			} else {
				authority += ch;
			}
		} else if (state == State::path) {
			path += ch;
		}
	}
}

std::string Web_url::get_url () const
{
	return scheme + authority + path;
}

std::string Web_url::get_scheme() const
{
	return scheme;
}

std::string Web_url::get_authority() const
{
	return authority;
}

std::string Web_url::get_path() const
{
	return path;
}

std::ostream& operator<<(std::ostream& out, const Web_url& url)
{
	out << "url = " << url.get_url() << '\n'
	    << "scheme = " << url.get_scheme() << '\n'
	    << "authority = " << url.get_authority() << '\n'
	    << "path = " << url.get_path() << '\n';
	return out;
}
