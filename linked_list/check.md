### Step-by-Step Analysis

1. **Minimum Sum Calculation**:
   - The smallest \( k \) distinct integers are \( 1, 2, 3, \ldots, k \).
   - The sum of these integers is given by the formula:
     \[
     S_{\text{min}} = 1 + 2 + 3 + \cdots + k = \frac{k(k + 1)}{2}
     \]
   - This is the minimum possible sum of \( k \) distinct integers.

2. **Maximum Sum Calculation**:
   - The largest \( k \) distinct integers between 1 and \( n \) are \( n, n-1, n-2, \ldots, (n-k+1) \).
   - The sum of these integers is given by the formula:
     \[
     S_{\text{max}} = n + (n-1) + (n-2) + \cdots + (n-k+1) = \frac{k(2n - k + 1)}{2}
     \]
   - This is the maximum possible sum of \( k \) distinct integers within the given range.

3. **Condition for \( x \)**:
   - For \( x \) to be achievable, it must satisfy:
     \[
     S_{\text{min}} \leq x \leq S_{\text{max}}
     \]