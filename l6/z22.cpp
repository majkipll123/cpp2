#include <iostream>
#include <cmath>

class Fraction  
{
    int64_t n, d;
public:
    constexpr Fraction(int64_t n, int64_t d = 1) : n(n), d(d)   
    {
        reduce();
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
    constexpr Fraction& operator-=(const Fraction& rhs) 
    {
        n = n * rhs.d - rhs.n * d;
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
    
    double to_double() const    
    {
        return static_cast<double>(n) / static_cast<double>(d);
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
//te same funkcje co w z2.cpp
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
    Fraction sum{0}, term{1};

    for (int n = 1; n <= 20; ++n)   
    {
        sum += term;
        term = Fraction{-term.num(), n + 1};
        
        std::cout << "N = " << n << ", " << sum << " " << sum.to_double() << '\n';
    }

    std::cout << "logn(2) = " << std::log(2.0) << '\n';

    return 0;
}
