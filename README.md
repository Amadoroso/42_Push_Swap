*This project has been created as part of the 42 curriculum by jtravanc, apinho-a*

---
# Push_swap
## Description

### Quick Summary

This project consisted in creating a program capable of organizing a stack (stack_a) full of integers in ascending order.
To achieve this an additional stack (stack_b) could be used.
Importantly the integers of stack_a are passed as arguments throught the CLI.
Since the integers were inside stacks, only stack operations could be used, meaning that only the top, the second and bottom nodes of the stacks could be manipulated with the following operations:

- `sa (swap a)`: Swap the first two elements at the top of stack a. Do nothing if there is only one or no elements.
- `sb (swap b)`: Swap the first two elements at the top of stack b. Do nothing if there is only one or no elements.
- `ss (swap a and b)`: sa and sb at the same time.
- `pa (push a)`: Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- `pb (push b)`: Take the first element at the top of a and put it at the top of a. Do nothing if b is empty.
- `ra (rotate a)`: Shift up all elements of stack a by one. The first element becomes the last one.
- `rb (rotate b)`: Shift up all elements of stack b by one. The first element becomes the last one.
- `rr (rotate a and b)`: ra and rb at the same time.
- `rra (reverse rotate a)`: Shift down all elements of stack a by one. The last element becomes the first one.
- `rrb (reverse rotate b)`: Shift down all elements of stack b by one. The last element becomes the first one.
- `rrr (reverse rotate a and b)`: rra and rrb at the same time.

## Program parts

### Argument parsing

Following the subject: Valid inputs are considered to be any kind of non duplicate `integer`. This includes:

`./push_swap 2 3 5 6` but also `./push_swap 2 "3 5 6" 7` meaning that passing several integers in a single argument is a perfectly valid approach. We decided to approach this like an "atoi" function would, meaning that any kind of white space (see `man iswspace` to know which ones were considered) is permitted in the arguments, it doesn't need to be " " or 7 bit ASCII character number 32 to be correctly interpreted. As long as an "atoi" function would be able to converted it to an integer it works. i.e. "     3\n\n5 6  " would be divided into 3, 5 and 6. i.e. "     3\n\n5 ---6  " This wouldn't work, since the standard "atoi" function does and an error would be generated.

Error handling is done as asked in the subject. If an invalid argument is passed, i.e. any non-integer 7 bit ASCII character, any repeated integer, any repeated flag or invalid flag (further information in the `flag` chapter). When this happens the program halts, returns "Error\n" to standard error.

If no arguments are passed, besides the program name, the prompt is returned.

After processing each integer, these are populated onto a structure (t_stack_node) which contains:

`typedef struct s_stack_node
{
	int					index;
	int					nbr;
	int					pos;
	int					above_mid;
	int					cost_b;
	int					cost_a;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;`

Forming the node basis for our linked list (stack_a). All nodes are linked with each other in the order they were inputed.
The first inputted integer is considered the `top` of the stack, and its address is kept inside the following t_stack structure:

`typedef struct s_stack
{
	t_stack_node	*top;
	int				size;
	int				bench;
	char			*flag;
}					t_stack;`

This structure holds crucial information about the stack, such as the its `size`, and other `flag` state information that will be addressed in the following chapter.

#### Flags

The following flags are considered valid:

Forcing algorithms:

`--simple` - Forces the program to use the insertion sort algorithm to sort the stack;
`--medium` - Forces the program to use the chunk-based algorithm to sort the stack;
`--complex` -  Forces the program to use the radix sort algorithm to sort the stack;

Modifying output:

`--bench` - Benchmark mode, which modifies the output to:

`[bench] disorder: `XX.XX%`
[bench] strategy: `Algorithm that was used`
[bench] total_ops: `total number of operations performed`
[bench] sa: `X` sb: `X` ss: `X` pa: `X` pb: `X`
[bench] ra: `X` rb: `X` rr: `X` rra: `X` rrb: `X` rrr: `X` `counter for each operation type``

Example of an output for the given argument: `./push_swap --bench --medium (shuf -i 1-10000 -n 50 | tr '\n' ' ')`

`[bench] disorder: 47.67%
[bench] strategy: Medium / O(n√n)
[bench] total_ops: 297
[bench] sa: 0 sb: 0 ss: 0 pa: 50 pb: 50
[bench] ra: 134 rb: 0 rr: 31 rra: 0 rrb: 32 rrr: 0`

Valid flag usage:

You can only pass one flag of each type. You can pass each flag of each type in the order you'd like. Flags MUST come right after the programs name and before any integer.

Examples of invalid flag usage: 

`./push_swap --simple --medium 3 2 1`
`./push_swap --bench --simple --bench 3 2 1`
`./push_swap 3 --simple --bench 2 1`

Examples of valid flag usage:

`./push_swap --bench --simple 3 2 1`
`./push_swap --simple --bench 3 2 1`
`./push_swap --bench 3 2 1`
`./push_swap --simple 3 2 1`

### Disorder calculation

The disorder is an essential metric for the "algorithm routing" section of this program. It essentially determines which algorithm is used with the passed integers:

`disorder < 0.2` -> The "simple", insertion sort algorithm is used
`0.2 >= disorder < 0.5 -> The "medium", chunk-based algorithm is used
`disorder >= 0.5` -> the "complex", Radix algorithm is used

The use of several algorithms increases the overall effiency of the program, althought the "complex" O(n log n) algorithm number of operations scales much better with the amount of numbers it also performs worse at lower argument numbers than a "simple" O(n^2) algorithm.

### Sorting algorithms

Before performing any kind of sorting, the indexes of each node (see argument parsing to see the structure) are assigned according to their destined position in the correct ascending order using an algorithm inspired on the "insertion sort" standard algorithm.

All algorithms use stack b to order elements in stack a, as required by the subject.


#### Insertion sort - the "simple" algorithm O(n^2)

#### Chunk-based sort - the "medium" algorithm O(n*n^1/2)

This algorithm sorts `stack_a` by a two step system. Has the big O-notation implies, theres a first part that scales to n^1/2 and second part that scales to n.

First the algorithm determines a `chunk_size` by determing the square root of the size of the stack. If the square root isn't an integer, the integer before it is considered. ie: size = 2 and 2^1/2 = 1.41 so 1 is considered.

Rough Chunk sorting section:
Then the `stack_a` is scanned for nodes which their index falls inside the current `search_limit` (search_limit starts of has chunk_size and is incremented by chunk_size until the stack_a is empty) and pushes them to stack_b i.e. : if chunk_size = 2, all nodes containting the index 0 and 1 are pushed to b, then in the next cycle search_limit is 4, so indexes 2 and 3 are pushed to b -> this is independent of their order, which will be corrected in the next step.

Final sorting section:
The highest index in stack_b is searched for and is pushed to stack_a. If the node with the highest current index is in the first half of the stack a rotate operation is used to reach the pretended node (rotating from the top to bottom) and if its in the second half, a reverse rotate operation is used to reach the pretended node (rotating from the bottom to the top). This optimization improves on the O(n) scaling, which results on a overall more perfomant algorithm, which scales more efficiently then O(n*n^1/2).

After this `stack_a` is fully sorted.


#### Radix sort - the "complex" algorithm O(n log n)

### Instructions

to use the program you must first execute `make` to compile each necessary binary and generate the `push_swap` program.

`make re` recompiles the program;
`make clean` removes .o files;
`make fclean` removes all .a and .o files and any .out from testing;

After sucessfully compiling the program, to run it you simple run `./push_swap` followed by the flags `./push_swap --flag1 --flag2` (see the Flags chapter to know how to use them), followed by the list of integers (see the Argument parsing chapter to know what constitutes a valid argument).

Each .c file is organized in different folders according to its purpose.

### Resources