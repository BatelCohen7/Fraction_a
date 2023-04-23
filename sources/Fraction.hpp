#pragma once

namespace ariel {

    class Fraction {
        int numerator;
        int denominator;

    public:
        Fraction(int num = 0, int den = 1);
        Fraction(float f);

        int get_numerator() const;
        int get_denominator() const;
        void reduce();

        // Overloaded operators
        // Arithmetic operators
        Fraction operator+(const Fraction& other) const;
        Fraction operator-(const Fraction& other) const;
        Fraction operator*(const Fraction& other) const;
        Fraction operator/(const Fraction& other) const;

        Fraction operator+(const float f) const;
        Fraction operator-(const float f) const;
        Fraction operator*(const float f) const;
        Fraction operator/(const float f) const;

        friend Fraction operator+(const float f, const Fraction& fraction);
        friend Fraction operator-(const float f, const Fraction& fraction);
        friend Fraction operator*(const float f, const Fraction& fraction);
        friend Fraction operator/(const float f, const Fraction& fraction);

        // Comparison operators
        bool operator==(const Fraction& other) const;
        bool operator!=(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        bool operator<(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;

        bool operator==(const float f) const;
        bool operator!=(const float f) const;
        bool operator>(const float f) const;
        bool operator<(const float f) const;
        bool operator>=(const float f) const;
        bool operator<=(const float f) const;

        friend bool operator==(const float f, const Fraction& fraction);
        friend bool operator!=(const float f, const Fraction& fraction);
        friend bool operator>(const float f, const Fraction& fraction);
        friend bool operator<(const float f, const Fraction& fraction);
        friend bool operator>=(const float f, const Fraction& fraction);
        friend bool operator<=(const float f, const Fraction& fraction);

        // Increment and decrement operators
        Fraction& operator++(); // Prefix
        Fraction operator++(int); // Postfix
        Fraction& operator--(); // Prefix
        Fraction operator--(int); // Postfix

        // Stream operators
        friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
        friend std::istream& operator>>(std::istream& is, Fraction& fraction);
    };
} // namespace ariel



