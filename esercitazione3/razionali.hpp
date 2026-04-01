#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <concepts>
#include <numeric>   // std::gcd per semplicficare le frazioni


template<typename I>
requires std::integral<I>
class rational
{
    I num_;
    I den_;

    void normalize()	
    {
        // Casi speciali con denominatore zero:
        // num != 0, den == 0  -> infinito
        // num == 0, den == 0  -> NaN
        if (den_ == 0) {
            if (num_ != 0) {
									// ad es 3/0 e 7/0 non possono essere normalizzati in maniera ordinaria
                if (num_ > 0) {		// per comodità normalizzo tutti gli infiniti a +1/0 o -1/0 e li gestisco meglio
					num_ = I{1};
				} else {
					num_ = I{-1};
				}
            } else {
									// NaN rappresentato come 0/0
                num_ = I{0};
            }
            return;
        }

        // Porto il segno sempre al numeratore
        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }

        // 0/d -> 0/1
        if (num_ == 0) {
            den_ = 1;
            return;
        }

        I g = std::gcd(num_, den_);
        num_ /= g;
        den_ /= g;
    }

public:
    // Costruttore di default: 0/1
    rational()
        : num_(0), den_(1)
    {
    }

    // Costruttore user-defined
    rational(I num, I den)
        : num_(num), den_(den)
    {
        normalize();
    }
	
	//getter numeratore e denominatore 
    I num() const { return num_; }
    I den() const { return den_; }

    // overload di +=
    rational& operator+=(const rational& other) 	//rational& pk la funzione += restituisce un riferimento all’oggetto stesso
    {
        // NaN + qualunque cosa = NaN
        if (den_ == 0 && num_ == 0) {
            return *this;
        }
        if (other.den_ == 0 && other.num_ == 0) {
            num_ = 0;
            den_ = 0;
            return *this;
        }

        // Inf + Inf / numero
        if (den_ == 0 || other.den_ == 0) {
            // +Inf + -Inf = NaN
            if (den_ == 0 && other.den_ == 0 && num_ != other.num_) {
                num_ = 0;
                den_ = 0;
                return *this;
            }

            // altrimenti resta l'infinito corretto
            if (den_ == 0) {
                return *this;
            } else {
                num_ = other.num_;
                den_ = 0;
                return *this;
            }
        }

        num_ = num_ * other.den_ + other.num_ * den_;
        den_ = den_ * other.den_;
        normalize();
        return *this;
    }

    // +
    rational operator+(const rational& other) const
    {
        rational ret = *this;
        ret += other;
        return ret;
    }

    // -=
    rational& operator-=(const rational& other)
    {
        rational tmp(-other.num_, other.den_);
        *this += tmp;
        return *this;
    }

    // -
    rational operator-(const rational& other) const
    {
        rational ret = *this;
        ret -= other;
        return ret;
    }

    // *=
    rational& operator*=(const rational& other)
    {
        // NaN * qualunque cosa = NaN
        if ((den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)) {
            num_ = 0;
            den_ = 0;
            return *this;
        }

        // 0 * Inf = NaN
        if ((den_ == 0 && other.num_ == 0 && other.den_ != 0) ||
            (other.den_ == 0 && num_ == 0 && den_ != 0)) {
            num_ = 0;
            den_ = 0;
            return *this;
        }

        // Gestione infiniti: mi riduco direttamente ad analizzare il segno
        if (den_ == 0 || other.den_ == 0) {
			I segno_this;
			if (den_ == 0) {
				segno_this = num_;
			} else {
				if (num_ > 0) {
					segno_this = 1;
				} else {
					segno_this = -1;
				}
			}

			I segno_other;
			if (other.den_ == 0) {
				segno_other = other.num_;
			} 
			else {
				if (other.num_ > 0) {
					segno_other = 1;
				} 
				else {
					segno_other = -1;
					}
				}

			num_ = segno_this * segno_other;
			den_ = 0;
			normalize();
			return *this;
		}

        num_ *= other.num_;
        den_ *= other.den_;
        normalize();
        return *this;
    }

    // *
    rational operator*(const rational& other) const
    {
        rational ret = *this;
        ret *= other;
        return ret;
    }

    // /=
    rational& operator/=(const rational& other)
    {
        // divisione per NaN -> NaN
        if ((other.den_ == 0 && other.num_ == 0) || (den_ == 0 && num_ == 0)) {
            num_ = 0;
            den_ = 0;
            return *this;
        }

        // divisione per zero (0/1, 0/5, ecc.) -> infinito o NaN
        if (other.den_ != 0 && other.num_ == 0) {
            if (num_ == 0 && den_ != 0) {
                num_ = 0;
                den_ = 0; // 0 / 0 = NaN
            } 
			else {
                if (num_ > 0) {
					num_ = 1;
				} 
				else {
					num_ = -1;
				}
				den_ = 0; // numero_non_zero / 0 = inf
            }
            return *this;
        }

        // Inf / Inf = NaN
        if (den_ == 0 && other.den_ == 0) {
            num_ = 0;
            den_ = 0;
            return *this;
        }

        // Inf / numero = Inf
        if (den_ == 0) {
            I s;
			if (other.num_ > 0) {
				s = 1;
			} else {
				s = -1;
			}
            num_ *= s;
            den_ = 0;
            normalize();
            return *this;
        }

        // numero / Inf = 0
        if (other.den_ == 0) {
            num_ = 0;
            den_ = 1;
            return *this;
        }

        num_ *= other.den_;
        den_ *= other.num_;
        normalize();
        return *this;
    }

    // /
    rational operator/(const rational& other) const
    {
        rational ret = *this;
        ret /= other;
        return ret;
    }
};

// Stampa
template<typename I>
requires std::integral<I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r)
{
    if (r.den() == 0) {
        if (r.num() == 0) {
            os << "NaN";
        } else if (r.num() > 0) {
            os << "Inf";
        } else {
            os << "-Inf";
        }
        return os;
    }

    os << r.num() << "/" << r.den();
    return os;
}

#endif