#include "boost/rational.hpp"
#include <algorithm>
#include <iostream>
namespace zuo
{

class rational
{
    friend std::istream &operator>>(std::istream &is, rational &r);
    friend std::ostream &operator<<(std::ostream &os, const rational &r);

  public:
    typedef double F;
    typedef long I;
    typedef unsigned long UI;
    typedef boost::rational<UI> unsigned_rational;
    static const UI UI_MAX = ULONG_MAX;

    // Constructors
    constexpr rational(); // Zero
    rational(int num);
    rational(I num);
    constexpr rational(UI num);
    rational(F num);

    rational(int n, int d);
    rational(I n, I d);
    rational(I n, UI d);
    rational(UI n, I d);
    rational(UI n, UI d, bool negative = false); // General case (n/d)

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
    unsigned_rational m_unsigned_rational;
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
constexpr rational::rational()
    : m_negative(false), m_unsigned_rational() {}

rational::rational(int num)
    : rational(std::abs(num), 1, num < 0)
{
}

rational::rational(I num)
    : rational(std::abs(num), 1, num < 0)
{
}
constexpr rational::rational(UI num)
    : m_negative(), m_unsigned_rational(num)
{
}

rational::rational(F num)
{
    m_negative = num < 0;
    F n = std::abs(num);
    UI i = 1;
    while (n - static_cast<UI>(n) > 1e-9)
    {
        if (n > UI_MAX / 10 || i > UI_MAX / 10)
        {
            std::cerr << "this frational number : " << num << " can not be transfer to rational number, it's too long, now set it 0." << std::endl;
            m_unsigned_rational = unsigned_rational(0, 1);
            return;
        }
        else
        {
            i *= 10;
            n *= 10;
        }
    }
    m_unsigned_rational = unsigned_rational(static_cast<UI>(n), i);
}

rational::rational(int n, int d)
: rational(std::abs(n), std::abs(d), (n ^ d) < 0)
{
}

rational::rational(UI n, I d)
    : m_negative(d < 0), m_unsigned_rational(n, d)
{
}

rational::rational(I n, UI d)
    : rational(std::abs(n), d, n < 0)
{
}

rational::rational(I n, I d)
    : rational(std::abs(n), std::abs(d), (n ^ d) < 0)
{
}

rational::rational(UI n, UI d, bool negative)
    : m_negative(negative && n != 0), m_unsigned_rational(n, 1)
{
    if (d == 0)
    {
        std::cerr << "denominator is zero for "<< (negative?"-":"")<<n<<"\\" <<d <<", now set it 0." << std::endl;
        m_unsigned_rational = unsigned_rational(0, 1);
    }
    else
        m_unsigned_rational = unsigned_rational(n, d);
}


constexpr bool rational::negative() const
{
    return m_negative;
}

std::ostream &operator<<(std::ostream &os, const rational &r)
{
    if (r.negative())
        os << "-" << r.m_unsigned_rational;
    else
        os << r.m_unsigned_rational;
    return os;
}
} // namespace zuo