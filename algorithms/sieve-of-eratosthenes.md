Sieve of Eratosthenes is a simple algorithm used to find the prime numbers
up to any given limit. For a given upper limit `n` the algorithm works by
iteratively marking the multiples of primes as composite, starting from 2.
Once all multiples of 2 have been marked composite, the muliples of next 
unmarked number are marked composite. This process continues until `p ≤ √n`
where `p` is a prime number.

Only primes up to `√n` need to be processed because at least one factor of
every composite number is less than or equal to its square root.

