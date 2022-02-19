#pragma once

#include <iostream>
#include <string>

// File Name (string)
// Image Type (must be one of the following only "PNG", "GIF", or "JPEG")
// Date Created (you can choose how you want to represent a date)
// Size (in MB, stored as a double)
// Author Name (string)
// Image Dimensions (will have width and height)
// Aperture Size (represented as f/# where # is an integer like f/8 or f/22)
// Exposure time (shutter speed, is a fraction of a second like 1/30, or 1/1000)
// ISO value (another integer like 600, or 3000)
// Flash enabled (boolean value)
class Camera_image {
private:
	std::string filename;
	std::string type;
	std::string date;
	double size;
	std::string author_name;
	double width;
	double height;
	int aperture_size_denominator;
	int exposure_time_denominator;
	int iso_value;
	bool flash_enabled;
public:
	Camera_image();
	Camera_image(std::string filename,
		     std::string type,
		     std::string date,
		     double size,
		     std::string author_name,
		     double width,
		     double height,
		     int aperture_size_denominator,
		     int exposure_time_denominator,
		     int iso_value,
		     bool flash_enabled);
	void set_filename(std::string filename);
	std::string get_filename() const;
	void set_type(std::string type);
	std::string get_type() const;
	void set_date(std::string date);
	std::string get_date() const;
	void set_size(double size);
	double get_size() const;
	void set_author_name(std::string name);
	std::string get_author_name() const;
	void set_dimension(double width, double height);
	std::string get_dimension() const;
	void set_aperture_size(int denominator);
	std::string get_aperture_size() const;
	void set_exposure_time(int denominator);
	std::string get_exposure_time() const;
	void set_iso_value(int value);
	int get_iso_value() const;
	void set_flash_enabled(bool enabled);
	bool is_flash_enabled() const;
};

std::ostream& operator<<(std::ostream& out, const Camera_image& image);
