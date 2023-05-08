#include <iostream>

class Fraction
{
    
    constexpr int64_t gcd(int64_t a, int64_t b) { return b == 0 ? a : gcd(b, a % b); }
 
    int64_t n, d;
public:
    constexpr Fraction(int64_t n, int64_t d = 1) : n(n/gcd(n, d)), d(d/gcd(n, d)) {}
 
    constexpr int64_t num() const { return n; }
    constexpr int64_t den() const { return d; }
 
    constexpr Fraction& operator*=(const Fraction& rhs)
    {
        int64_t new_n = n * rhs.n / gcd(n * rhs.n, d * rhs.d);
        d = d * rhs.d / gcd(n * rhs.n, d * rhs.d);
        n = new_n;
        return *this;
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
    return Fraction(lhs.num() * rhs.den() + rhs.num() * lhs.den(), lhs.den() * rhs.den());
}

constexpr Fraction operator+=(Fraction lhs, const Fraction& rhs)
{
    return lhs = lhs + rhs;
}

constexpr Fraction operator-(Fraction lhs, const Fraction& rhs)
{
    return Fraction(lhs.num() * rhs.den() - rhs.num() * lhs.den(), lhs.den() * rhs.den());
}

constexpr Fraction operator-=(Fraction lhs, const Fraction& rhs)
{
    return lhs = lhs - rhs;
}

constexpr Fraction operator/(Fraction lhs, const Fraction& rhs)
{
    return Fraction(lhs.num()*rhs.den(), lhs.den()*rhs.num());
}

constexpr Fraction operator/=(Fraction lhs, const Fraction& rhs)
{
    return lhs = lhs/rhs;
}

double to_double(const Fraction& f)
{
    return static_cast<double>(f.num())/f.den();
}
 


int main()
{
    constexpr Fraction f1{3, 8}, f2{1, 2}, f3{10, 2};
    std::cout << f1 << " * mnozenie" << f2 << " = " << f1 * f2 << '\n'
              << f2 << " * " << f3 << " = " << f2 * f3 << '\n'
              <<  2 << " * " << f1 << " = " <<  2 * f1 << '\n'
              << f1 << " + dodawanie" << f2 << " = " << f1 + f2 << '\n'
              << f1 << " - odejmowanie" << f2 << " = " << f1 - f2 << '\n'
              << f1 << " / dzielenie" << f2 << " = " << f1 / f2 << '\n'
              << f2 << " / " << f3 << " = " << f2 / f3 << '\n'
              << f1 << " += dodaj to "<< f2 << " = " << (f1 += f2) << '\n'
              << f1 << " !=?? "<< f2 << " = " << (f1 != f2) << '\n';

}