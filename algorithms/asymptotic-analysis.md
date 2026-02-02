The complexity of an algorithm is measured by the number of operations
required to find the  solution. The complexity function represents the
relationship between the input data and the number of operations.

*Asymptotic Analysis* shows how an algorithm's time or memory usage grows
as input size increases. Asymptotic analysis is crucial to find the most 
optimal algorithm to our problem.

## Bachmann-Landau Notations
Bachmann-Landau notation is a mathematical system used to describe the 
growth rates of functions, particularly in computer science for analyzing 
algorithms.

### Big Theta
Big Θ notation describes the exact asymptotic growth rate of an algorithm.
It provides a tight bound on a function, meaning it bounds the function 
from both above and below asymptotically.

For two functions `f(x)` and `g(x)`, we say that: `f(x) = Θ(g(x))`
if there exist positive constants `c₁`,`c₂` and `n₀` such that:
`0 ≤ c₁⋅g(n) ≤ f(n) ≤ c₂⋅g(n) for all n≥n₀`

Consider the polynomial function: `f(n)=4n³+3n²+2n+1a`
For large `n`, `4n³` term dominates the function's growth. Therefore, 
we can say that: `f(n) = Θ(n³)`

### Big O
Big O notation describes the upper asymptotic bound of an algorithm.
It bounds function from above only and represents an algotithm's
worst-case complexity. 

For two functions `f(x)` and `g(x)`, we say that: `f(x) = O(g(x))`
if there exist positive constants `c₁` and `n₀` such that:
`0 ≤ f(n) ≤ c⋅g(n) for all n≥n₀`

### Big Omega
Big Ω notation describes the lower asymptotic bound of an algorithm.
It bounds function from below only and generally represents an algotithm's
best-case complexity.

For two functions `f(x)` and `g(x)`, we say that: `f(x) = Ω(g(x))`
if there exist positive constants `c₁` and `n₀` such that:
`0 ≤ c⋅g(n) ≤ f(n) for all n≥n₀`

## Time Complexities From Best To Worst
O(1)
O(log n)
O(√n)
O(n)
O(n log n)
O(n²)
O(n³)
O(2ⁿ)
O(n!)

