#include "boost/rational.hpp"

namespace zuo
{
/*
* for public typedef
*/
typedef unsigned long int_type;
typedef boost::rational<int_type> unsigned_rational;

class rational : public unsigned_rational
{
  public:
    typedef int_type I;

    // Constructors
    rational() = default;           // Zero
    constexpr rational(double num);
    constexpr rational(long int num);
    rational(I n, I d, bool negative);             // General case (n/d)

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
 constexpr rational operator+ (const rational& r);
           rational operator- (const rational& r);

// Reversed order operators for - and / between (types convertible to) I and rational
template <typename I, typename II> inline rational operator- (II i, const rational& r);
template <typename I, typename II> inline rational operator/ (II i, const rational& r);

// Absolute value
 rational abs (const rational& r);

// Input and output
 std::istream& operator>> (std::istream& is, rational& r);
 std::ostream& operator<< (std::ostream& os, const rational& r);

// Type conversion
template <typename T> constexpr T rational_cast (const rational& r);
} // namespace zuo