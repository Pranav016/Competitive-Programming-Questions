# Linear Recurrence-
It is a function in which each term of the sequence is a linear combination of the prev terms.
Example- Fibonacci series

F(i) = F(i-1) + F(i-2)

F(i) = F(i-1) * F(i-2) -> Not a linear recurrence since this will be quadratic.

#### Question will come like, calculate nth term of this recurrence-
There are a number of ways to solve this-
* Recursion (2^n)
* DP O(N)
* Matrix Exponentiation (K^3(log n)) -> Mainly used to solve linear recurrences. 
here k is number of terms F(i) depends. Here k=2

Step1: Find k. K=2

Step2: Find out first k terms. 
F(i) matrix given.
|F(i-2)|
|F(i-1)|

Step3: Find out a matrix T (Transformation matrix) which is of size k x k
T x |F(i-2)| = |F(i-1)|
    |F(i-1)|   | F(i) |

Fn = T * F(n-1)
= T * T * F(n-2)
= T * T * T *F(n-3)
= T(n-1) * F1