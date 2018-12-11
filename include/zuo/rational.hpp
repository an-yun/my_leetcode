#include "boost/rational.hpp"

namespace zuo
{
/*
* for public typedef
*/
typedef double F;
typedef long I;
typedef unsigned long UI;
typedef boost::rational<unsigned long long> unsigned_rational;

class rational : public unsigned_rational
{
  public:
    // Constructors
    constexpr rational(); // Zero
    constexpr rational(F num);
    constexpr rational(I num);
    constexpr rational(UI num);
    rational(UI n, UI d, bool negative); // General case (n/d)
    rational(UI n, I d);
    rational(I n, UI d);
    rational(I n, I d);

    // Normal copy constructors and assignment operators

    // Assignment from I
    rational &operator=(I n);

    // Assign in place
    rational &assign(I n, I d);

    // Representation
    constexpr I numerator() const;
    constexpr I denominator() const;
    constexpr bool negative() const;

    // In addition to the following operators, all of the "obvious" derived
    // operators are available - see operators.hpp

    // Arithmetic operators
    rational &operator+=(const rational &r);
    rational &operator-=(const rational &r);
    rational &operator*=(const rational &r);
    rational &operator/=(const rational &r);

    // Arithmetic with integers
    rational &operator+=(I i);
    rational &operator-=(I i);
    rational &operator*=(I i);
    rational &operator/=(I i);

    // Increment and decrement
    const rational &operator++();
    const rational &operator--();

    // Operator not
    constexpr bool operator!() const;

    // Boolean conversion
    constexpr operator bool() const;

    // Comparison operators
    bool operator<(const rational &r) const;
    constexpr bool operator==(const rational &r) const;

    // Comparison with integers
    bool operator<(I i) const;
    bool operator>(I i) const;
    constexpr bool operator==(I i) const;

  private:
    bool m_negative;
};

// Unary operators
constexpr rational operator+(const rational &r);
rational operator-(const rational &r);

// Reversed order operators for - and / between (types convertible to) I and rational
template <typename T>
inline rational operator+(T i, const rational &r);
template <typename T>
inline rational operator-(T i, const rational &r);
template <typename T>
inline rational operator*(T i, const rational &r);
template <typename T>
inline rational operator/(T i, const rational &r);

// Absolute value
rational abs(const rational &r);

// Input and output
std::istream &operator>>(std::istream &is, rational &r);
std::ostream &operator<<(std::ostream &os, const rational &r);

// Type conversion
template <typename T>
constexpr T rational_cast(const rational &r);

/*
 * Implemention for rational
 * 
 * */
constexpr rational::rational() : unsigned_rational(), m_negative(false) {}

constexpr rational::rational(F num)
{
}
constexpr rational::rational(I num)
{
}
constexpr rational::rational(UI num)
{
}
rational(UI n, UI d, bool negative)
{
}
rational(UI n, I d)
{
}
rational(I n, UI d)
{
}
rational(I n, I d);

std::ostream &operator<<(std::ostream &os, const rational &r)
{
    const unsigned_rational *p = &r;
    if (r.negative())
        os << "-" << *p;
    else
        os << *p;
    return os;
}
} // namespace zuo