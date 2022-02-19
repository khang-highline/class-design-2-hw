#include "camera_image.h"

Camera_image::Camera_image()
{
	filename = "";
	type = "PNG";
	date = "";
	size = 0;
	author_name = "";
	width = 100;
	height = 100;
	aperture_size_denominator = 8;
	exposure_time_denominator = 30;
	iso_value = 600;
	flash_enabled = false;
}

Camera_image::Camera_image(std::string filename,
                           std::string type,
                           std::string date,
                           double size,
                           std::string author_name,
                           double width,
                           double height,
                           int aperture_size_denominator,
                           int exposure_time_denominator,
                           int iso_value,
                           bool flash_enabled)
{
	this->filename = filename;
	if (type == "PNG" || type == "GIF" || type == "JPEG")
		this->type = type;
	else
		this->type = "PNG";
	this->date = date;
	if (size >= 0)
		this->size = size;
	this->author_name = author_name;
	if (width > 0)
		this->width = width;
	else
		this->width = 100;
	if (height > 0)
		this->height = height;
	else
		this->height = 100;
	if (aperture_size_denominator > 0)
		this->aperture_size_denominator = aperture_size_denominator;
	else
		this->aperture_size_denominator = 8;
	if (exposure_time_denominator > 0)
		this->exposure_time_denominator = exposure_time_denominator;
	else
		this->exposure_time_denominator = 30;
	this->iso_value = iso_value;
	this->flash_enabled = flash_enabled;
}

void Camera_image::set_filename(std::string name)
{
	filename = name;
}

std::string Camera_image::get_filename() const
{
	return filename;
}

void Camera_image::set_type(std::string type)
{
	if (type == "PNG" || type == "GIF" || type == "JPEG")
		this->type = type;
}

std::string Camera_image::get_type() const
{
	return type;
}

void Camera_image::set_date(std::string date)
{
	this->date = date;
}

std::string Camera_image::get_date() const
{
	return date;
}

void Camera_image::set_size(double size)
{
	if (size >= 0)
		this->size = size;
}

double Camera_image::get_size() const
{
	return size;
}

void Camera_image::set_author_name(std::string name)
{
	author_name = name;
}

std::string Camera_image::get_author_name() const
{
	return author_name;
}

void Camera_image::set_dimension(double width, double height)
{
	if (width > 0)
		this->width = width;
	if (height > 0)
		this->height = height;
}

std::string Camera_image::get_dimension() const
{
	return std::to_string(width) + ":" + std::to_string(height);
}

void Camera_image::set_aperture_size(int denominator)
{
	if (denominator > 0)
		aperture_size_denominator = denominator;
}

std::string Camera_image::get_aperture_size() const
{
	return "f/" + std::to_string(aperture_size_denominator);
}

void Camera_image::set_exposure_time(int denominator)
{
	if (denominator > 0)
		exposure_time_denominator = denominator;
}

std::string Camera_image::get_exposure_time() const
{
	return "1/" + std::to_string(exposure_time_denominator);
}

void Camera_image::set_iso_value(int value)
{
	iso_value = value;
}

int Camera_image::get_iso_value() const
{
	return iso_value;
}

void Camera_image::set_flash_enabled(bool enabled)
{
	flash_enabled = enabled;
}

bool Camera_image::is_flash_enabled() const
{
	return flash_enabled;
}

std::ostream& operator<<(std::ostream& out, const Camera_image& image)
{
	out << "File Name: " << image.get_filename() << '\n'
	     << "Image Type: " << image.get_type() << '\n'
	     << "Date Created: " << image.get_date() << '\n'
	     << "Size (MB): " << image.get_size() << '\n'
	     << "Author Name: " << image.get_author_name() << '\n'
	     << "Image Dimensions: " << image.get_dimension() << '\n'
	     << "Aperture Size: " << image.get_aperture_size() << '\n'
	     << "Exposure time: " << image.get_exposure_time() << '\n'
	     << "ISO value: " << image.get_iso_value() << '\n'
	     << "Flash enabled: ";
	if (image.is_flash_enabled())
		out << "true\n";
	else
		out << "false\n";
	return out;
}
