- [source](https://cp-algorithms.com/data_structures/fenwick.html)

### What is it?
- Supposing an function f that defines an operation $*$ in a group $A$
	- So, to calculate f through the range l, r
		- $RESULT \ = \ A_l * A_{l+1} * ... * A_{r-1} * A_r$ 
- Calculates the result of the operation through an defined interval in $O(log\ n)$ time
- Updates a value in $A$ in $O(log\ n)$ time
- $O(n)$ memory allocation
- Normally -> Addition
- An array of sums of the operation to the point defined
	- Supposing the operation of addition
	- $T_i = \sum ^i _{j=g(i)} A_j$ -> The results of the operation applied in the values to that point
	- $g(i)$ is a number between 0 and $i$ -> Used for optimization of the problem
		- Can instead be used 0
		- Possibility for dynamic starts 
	
	
## Defining
- The way everything will behave will need to be defined by the code you are working with
- For the implementation on cp-algorithms
	- $g(i) = i \ \& \ (i+1)$ -> Replacing all trailing ones with zero
	- $h(j) = j \ | \ (j + 1)$ -> To iterate over all possible j's such as $g(j) \leq i \leq j$
	- The result would be:
		![Result](Images/FenwickTreeBIT-cp_result.png)
- But, as another way to think it through
	- To get this result 
		![Result](FenwickTreeBIT-gcc_result.png)
	- You could think it as the biggest power of 2 that can divide the index instead
	- Easier to comprehend
	- To iterate over all values that need to be updated and then update them accordingly
		- `for (i + 1; i <= n; i += i & -i)` -> To travel the tree upwards until $n$ 
		- `for (i + 1; i; i -= i & -i)` -> To travel the tree downards
		- 