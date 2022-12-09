#include "./Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int &num)
{
  std::cout << "Int constructor called" << std::endl;
  fixed_point = num << 8;
}

Fixed::Fixed(const float &num)
{
  std::cout << "Float constructor called" << std::endl;
  fixed_point = roundf(num * (1 << 8));
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
  std::cout << "Copy assignment operator called" << std::endl;
  fixed_point = src.getRawBits();
  return *this;
}

void Fixed::setRawBits(const int set)
{
  fixed_point = set;
}

int Fixed::getRawBits(void) const
{
  // std::cout << "getRawBits member function called" << std::endl;
  return (
      fixed_point);
}

Fixed::Fixed(const Fixed &src)
{

  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}

int Fixed::toInt(void) const
{
  return (fixed_point >> 8);
}

float Fixed::toFloat(void) const
{
  float r = (float(fixed_point) / (1 << 8));
  return r;
}

std::ostream &operator<<(std::ostream &out, const Fixed &c)
{
  out << float(c.toFloat());
  return (out);
}

bool Fixed::operator<(const Fixed& n) {
  return (this->fixed_point < n.fixed_point);
}

bool Fixed::operator<=(const Fixed& n) {
  return (this->fixed_point <= n.fixed_point);
}

bool Fixed::operator>(const Fixed& n) {
  return (this->fixed_point > n.fixed_point);
}

bool Fixed::operator>=(const Fixed& n) {
  return (this->fixed_point >= n.fixed_point);
}

bool Fixed::operator==(const Fixed& n) {
  return (this->fixed_point == n.fixed_point);
}

bool Fixed::operator!=(const Fixed& n) {
  return (this->fixed_point != n.fixed_point);
}

float Fixed::operator*(const Fixed& n) {
  return (
    this->toFloat() * n.toFloat()
  );
}

float Fixed::operator-(const Fixed& n) {
  return (
    this->toFloat() - n.toFloat()
  );
}

float Fixed::operator+(const Fixed& n) {
  return (
    this->toFloat() + n.toFloat()
  );
}

float Fixed::operator/(const Fixed& n) {
  return (
    this->toFloat() / n.toFloat()
  );
}

