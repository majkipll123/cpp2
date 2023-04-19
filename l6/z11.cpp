#include <iostream>
#include <algorithm> // std::abs
#include <numeric>   // std::gcd

class Fraction
{
    using ll = long long;
    ll n, d;
public:
    constexpr Fraction(ll n = 0, ll d = 1) : n{n/std::gcd(n, d)}, d{d/std::gcd(n, d)} {}

    constexpr ll num() const { return n; }
    constexpr ll den() const { return d; }

    constexpr Fraction& operator*=(const Fraction& rhs)
    {
        ll new_n = n * rhs.n / std::gcd(n * rhs.n, d * rhs.d);
        d = d * rhs.d / std::gcd(n * rhs.n, d * rhs.d);
        n = new_n;
        return *this;
    }

    constexpr Fraction& operator+=(const Fraction& rhs)
    {
        ll lcm = std::lcm(d, rhs.d);
        ll new_n = n * (lcm / d) + rhs.n * (lcm / rhs.d);
        d = lcm;
        n = new_n;
        return *this;
    }

    constexpr Fraction& operator-=(const Fraction& rhs)
    {
        ll lcm = std::lcm(d, rhs.d);
        ll new_n = n * (lcm / d) - rhs.n * (lcm / rhs.d);
        d = lcm;
        n = new_n;
        return *this;
    }

    constexpr Fraction& operator/=(const Fraction& rhs)
    {
        ll new_n = n * rhs.d;
        ll new_d = d * rhs.n;
        if (new_d < 0) {
            new_n = -new_n;
            new_d = -new_d;
        }
        n = new_n / std::gcd(new_n, new_d);
        d = new_d / std::gcd(new_n, new_d);
        return *this;
    }

    constexpr double to_double() const { return static_cast<double>(n) / d; }
};

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    out << f.num() << "/" << f.den();
    return out;
}

constexpr bool operator==(const Fraction& lhs, const Fraction& rhs)
{
    return lhs.num() == rhs.num() && lhs.den() == rhs.den();
}

constexpr bool operator!=(const Fraction& lhs, const Fraction& rhs)
{
    return !(lhs == rhs);
}

constexpr Fraction operator*(Fraction lhs, const Fraction& rhs)
{
    return lhs *= rhs;
}

constexpr Fraction operator+(Fraction lhs, const Fraction& rhs)
{
    return lhs += rhs;
}

constexpr Fraction operator-(Fraction lhs, const Fraction& rhs)
{
    return lhs -= rhs;
}

constexpr Fraction operator/(Fraction lhs, const Fraction& rhs)
{
    int new_n = lhs.num() * rhs.den();
    int new_d = lhs.den() * rhs.num();
    return Fraction{new_n, new_d};
}

constexpr Fraction& operator/=(Fraction& lhs, const Fraction& rhs)
{
    lhs = lhs / rhs;
    return lhs;
}

int main()
{
    constexpr Fraction f1{3, 8}, f2{1, 2}, f3{10, 2};
    std::cout << f1 << " * " << f2 << " = " << f1 * f2 << '\n'
              << f2 << " * " << f3 << " = " << f2 * f3 << '\n'
              <<  2 << " * " << f1 << " = " <<  2 * f1 << '\n'
              << f1 << " + " << f2 << " = " << f1 + f2 << '\n'
              << f1 << " - " << f2 << " = " << f1 - f2 << '\n'
              << f1 << " / " << f2 << " = " << f1 / f2 << '\n'
              << f1 << " / " << f2 << " = " << (f1 /= f2) << '\n'
              << f2 << " / " << f3 << " = " << f2 / f3 << '\n';

    static_assert(f3 == f2 * 10);
}