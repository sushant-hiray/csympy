// Following number theoretic functions just make use of GMP's number theoretic
// function implementations. Please refer the following manual:
// https://gmplib.org/manual/Number-Theoretic-Functions.html

#ifndef CSYMPY_NTHEORY_H
#define CSYMPY_NTHEORY_H

#include "integer.h"

namespace CSymPy {

// Prime Functions
int probab_prime_p(const Integer &a, int reps = 25);
RCP<const Integer> nextprime(const Integer &a);

// Basic Number-theoretic functions
RCP<const Integer> gcd(const Integer &a, const Integer &b);
RCP<const Integer> lcm(const Integer &a, const Integer &b);
void gcd_ext(const Ptr<RCP<const Integer>> &g, const Ptr<RCP<const Integer>> &s,
        const Ptr<RCP<const Integer>> &t, const Integer &a, const Integer &b);

int mod_inverse(const Ptr<RCP<const Integer>> &b, const Integer &a,
        const Integer &m);
bool divides(const RCP<const Integer> &a, const RCP<const Integer> &b);

// Factorization
// parameter B1 is only used when `n` is factored using gmp-ecm
int factor(const Ptr<RCP<const Integer>> &f, const Integer &n, double B1 = 1.0);

// Factor using trial division. Returns 1 if a non-trivial factor is found,
// otherwise 0.
int factor_trial_division(const Ptr<RCP<const Integer>> &f, const Integer &n);
// Returns all primes up to the `limit` (excluding). The vector `primes` should
// be empty on input and it will be filled with the primes.
// The implementation is a very basic Eratosthenes sieve, but the code should
// be quite optimized. For limit=1e8, it is about 50x slower than the
// `primesieve` library (1498ms vs 28.29ms).
void eratosthenes_sieve(unsigned limit, std::vector<unsigned> &primes);

// Factor using lehman's methods
int factor_lehman_method(const Ptr<RCP<const Integer>> &f, const Integer &n);

// Find prime factors of `n`
void prime_factors(const RCP<const Integer> &n,
        std::vector<RCP<const Integer>> &primes);
// Find multiplicities of prime factors of `n`
void prime_factor_multiplicities(const RCP<const Integer> &n,
        map_integer_uint &primes);

//Factorial using GMP's predefined function
RCP<const Integer> factorial(const Integer &a);

}

#endif

