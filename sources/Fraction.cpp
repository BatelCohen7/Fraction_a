#include <iostream>
#include <stdexcept>
#include <cmath>
#include <numeric>
#include "Fraction.hpp"

using namespace std;

namespace ariel
{
    Fraction::Fraction(int num, int den) : numerator(num), denominator(den)
    {
        if (denominator == 0)
        {
            throw std::invalid_argument("Denominator cannot be 0");
        }
        reduce();
    }

    Fraction::Fraction(float f)
    {
        denominator = 1000;
        numerator = static_cast<int>(round(f * 1000));
        reduce();
    }

    int Fraction::get_numerator() const
    {
        return numerator;
    }

    int Fraction::get_denominator() const
    {
        return denominator;
    }

    void Fraction::reduce()
    {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    // Arithmetic operators
    Fraction Fraction::operator+(const Fraction &other) const
    {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        Fraction result(num, den);
        result.reduce();
        return result;
    }

    Fraction Fraction::operator-(const Fraction &other) const
    {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        Fraction result(num, den);
        result.reduce();
        return result;
    }

    Fraction Fraction::operator*(const Fraction &other) const
    {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        Fraction result(num, den);
        result.reduce();
        return result;
    }

    Fraction Fraction::operator/(const Fraction &other) const
    {
        if (other.numerator == 0)
        {
            throw std::invalid_argument("Division by zero");
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        Fraction result(num, den);
        result.reduce();
        return result;
    }


    Fraction& Fraction::operator++()
    {
        return *this;
    }

    Fraction Fraction::operator++(int)
    {
        return *this;
    }

    Fraction& Fraction::operator--()
    {
        return *this;
    }

    Fraction Fraction::operator--(int)
    {
        return *this;
    }

    Fraction Fraction::operator+(const float f) const
    {
        return Fraction(f);
    }

    Fraction Fraction::operator-(const float f) const
    {
        return Fraction(f);
    }

    Fraction Fraction::operator*(const float f) const
    {
        return Fraction(f);
    }

    Fraction Fraction::operator/(const float f) const
    {
        return Fraction(f);
    }

    Fraction operator+(const float f, const Fraction &fraction)
    {
        return Fraction(f);
    }

    Fraction operator-(const float f, const Fraction &fraction)
    {
        return Fraction(f);
    }

    Fraction operator*(const float f, const Fraction &fraction)
    {
        return Fraction(f);
    }

    Fraction operator/(const float f, const Fraction &fraction)
    {
        return Fraction(f);
    }

    // Comparison operators
    bool Fraction::operator==(const Fraction &other) const
    {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool Fraction::operator!=(const Fraction &other) const
    {
        return !(*this == other);
    }

    bool Fraction::operator>(const Fraction &other) const
    {
        return numerator * other.denominator > other.numerator * denominator;
    }

    bool Fraction::operator<(const Fraction &other) const
    {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool Fraction::operator>=(const Fraction &other) const
    {
        return !(*this < other);
    }

    bool Fraction::operator<=(const Fraction& other) const
    {
        return !(*this > other);
    }

    bool Fraction::operator==(const float f) const
    {
        return true;
    }

    bool Fraction::operator!=(const float f) const
    {
        return true;
    }

    bool Fraction::operator>(const float f) const
    {
        return true;
    }

    bool Fraction::operator<(const float f) const
    {
        return true;
    }

    bool Fraction::operator>=(const float f) const
    {
        return true;
    }

    bool Fraction::operator<=(const float f) const
    {
        return true;
    }

    bool operator==(const float f, const Fraction &fraction)
    {
        return true;
    }

    bool operator!=(const float f, const Fraction &fraction)
    {
        return true;
    }

    bool operator>(const float f, const Fraction &fraction)
    {
        return true;
    }

    bool operator<(const float f, const Fraction &fraction)
    {
        return true;
    }

    bool operator>=(const float f, const Fraction &fraction)
    {
        return true;
    }

    bool operator<=(const float f, const Fraction &fraction)
    {
        return true;
    }

    // Stream operators
    std::ostream &operator<<(std::ostream &os, const Fraction &fraction)
    {
        return os;
    }

    std::istream &operator>>(std::istream &is, Fraction &fraction)
    {
        return is;
    }

} // namespace ariel