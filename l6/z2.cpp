#include <iostream>
#include <iomanip>

class Fraction
{
    int64_t n, d;
public:

    
    double to_double() const
    {
        return static_cast<double>(n) / static_cast<double>(d);
    }
    constexpr Fraction(int64_t n, int64_t d = 1) : n(n), d(d)
    {
        reduce();
    }
    constexpr Fraction& operator-=(const Fraction& rhs)
    {
        n = n * rhs.d - rhs.n * d;
        d *= rhs.d;
        reduce();

        return *this;
    }
    constexpr int64_t num() const
    {
        return n;
    }
    constexpr int64_t den() const
    {
        return d;
    }
    constexpr Fraction& operator*=(const Fraction& rhs)
    {
        n *= rhs.n;
        d *= rhs.d;
        reduce();

        return *this;
    }
    constexpr Fraction& operator+=(const Fraction& rhs)
    {
        n = n * rhs.d + rhs.n * d;
        d *= rhs.d;
        reduce();

        return *this;
    }
    
    constexpr Fraction& operator/=(const Fraction& rhs)
    {
        n *= rhs.d;
        d *= rhs.n;
        reduce();

        return *this;
    }


private:
    constexpr void reduce()
    {
        if (d < 0)
        {
            n = -n;
            d = -d;
        }

        int64_t div = gcd(n, d);
        n /= div;
        d /= div;
    }
    constexpr int64_t gcd(int64_t a, int64_t b) const
    {
        return b == 0 ? a : gcd(b, a % b);
    }
};

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
   return out << f.num() << '/' << f.den();
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
    return lhs /= rhs;
}

int main()
{
    Fraction sum{0};

    for (int i = 1; i <= 100; ++i)
    {
        sum += Fraction{1, i * (i + 1)};
        std::cout << "N = " << i << ": " << sum << " (margin to . " << std::setprecision(15) << sum.to_double() << ")\n";
    }

    return 0;
}
