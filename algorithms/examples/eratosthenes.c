#include <stdio.h>
#include <math.h>

/* Asymptotic analysis 
* 
* Outer loop runs N times.
* Inner loop runs N/p times for every prime number less than or equal to N.
* 
* From numbers theory: approximate number of primes less than or equal to k
*     is k / ln(k)
*
* Then, using some advanced math, we can replace sum with integral, and solve
*     the integral. Finally, we get ln(ln(N)) complexity for the inner loop.
*
* At last, adding the outer loop's complexity, we get final asymptotic analysis
*     for this function, which is: N * ln(ln(N))
*
*/
void eratosthenes(size_t N) {
    int arr[N] = {0};
    for (int i = 2; i*i <= N; i++) {
        if (arr[i] == 1) {
            continue;
        } else {
            printf("%d ", i);

            for (int j = i*i; j <= N; j = j+i) {
                arr[j] = 1;
            }
        }
    }
}


/* Modified Eratosthenes Sieve
*
* Modified sieve can be used to not only get primes and composites, but also
* for prime factorization. In this method, instead of marking composite numbers
* as 1, we write thier smallest prime divisor.
*
*/
void eratosthenes_modified(size_t N) {
    int arr[N] = {0};
    for (i = 2; i <= N; i++) {
        if (arr[i] > 0) {
            continue;
        } else {
            for (j = i*i; j <= N; j = j+i) {
                if (arr[j] == 0) {
                    arr[j] = i;
                }
            }
        }
    }
}

/* Modified Eratosthenes Sieve in O(n) time */
void eratosthenes_modified_perf(size_t N) {
    int arr[N] = {0};
    int sieve[N] = {0};
    int k = 0;

    for (i = 2; i <= N; i++) {
        if (arr[i] == 0) {
            arr[i] = i;
            sieve[k++] = i;
        }
        for (j = 0; ; j++) {
        
        }
    }
}

int main() {
    const size_t N = 55;
    eratosthenes(N);
    printf("\n");
}
