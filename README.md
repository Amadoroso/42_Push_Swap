*This project has been created as part of the 42 curriculum by jtravanc, apinho-a.*

---
# Push_swap

## Description
This project sorts data on a stack, with a limited set of instructions, using the lowest possible number of actions. We start with an unsorted stack of integers (`stack_a`) and an empty auxiliary stack (`stack_b`). The goal is to sort `stack_a` in ascending order using specific stack manipulation operations.

### Allowed Operations
* `sa` / `sb`: Swap the first two elements at the top of stack a / b.
* `ss`: `sa` and `sb` at the same time.
* `pa` / `pb`: Push the top element from b to a / from a to b.
* `ra` / `rb`: Rotate stack a / b up by one. (Top element becomes bottom).
* `rr`: `ra` and `rb` at the same time.
* `rra` / `rrb`: Reverse rotate stack a / b down by one. (Bottom element becomes top).
* `rrr`: `rra` and `rrb` at the same time.

## Instructions
Run `make` to compile the binary. 

**Makefile Commands:**
* `make`: Compiles the `push_swap` program.
* `make re`: Recompiles the program.
* `make clean`: Removes `.o` files.
* `make fclean`: Removes all `.a`, `.o`, and executable files.

**Usage:**
```
./push_swap [flags] <list_of_integers>
```

## Program Architecture

### Argument Parsing & Error Handling
Valid inputs are non-duplicate integers. Arguments can be passed individually or grouped within strings (e.g., `./push_swap 2 "3 5 6" 7`). We implemented a custom parsing function that handles any standard whitespace characters. 

If an invalid argument is passed (non-integers, duplicates, invalid flags), the program halts and outputs `Error\n` to `stderr`. After validation, integers are loaded into a doubly linked list representing `stack_a`.

### Flags
Flags must immediately follow the program name, preceding any integers. 

**Algorithm Forcing:**
* `--simple`: Forces the O(n^2) insertion sort.
* `--medium`: Forces the O(n√n) chunk-based sort.
* `--complex`: Forces the O(n log n) radix sort.
* `--adaptive` (Default): Selects the algorithm based on the stack's disorder.

**Output Modification:**
* `--bench`: Prints benchmark metrics to `stderr` instead of standard operations. Outputs disorder percentage, chosen strategy, total operations, and individual operation counts.

### Disorder Calculation & Algorithm Routing
Disorder dictates the algorithm choice when the `--adaptive` flag is active (or by default):
* **Disorder < 0.2**: Routes to the "simple" algorithm.
* **0.2 <= Disorder < 0.5**: Routes to the "medium" algorithm.
* **Disorder >= 0.5**: Routes to the "complex" algorithm.

---

## Sorting Algorithms
Before sorting, node indexes are pre-assigned based on their final target position to simplify logic.

### 1. Insertion Sort - "Simple" Algorithm O(n^2)
This algorithm sorts by maintaining a sorted state in `stack_a` while pushing elements from `stack_b`. First, all elements except three are pushed to `stack_b`. The remaining three are sorted using a hardcoded sequence. Then, for every element in `stack_b`, the algorithm scans stack_a to find its correct target position based on index values. It calculates the most efficient path to bring that insertion point to the top of `stack_a` (using `ra` for the top half and `rra` for the bottom half), executes the rotations, and pushes the element (`pa`). A final alignment step rotates `stack_a` to bring the absolute minimum index to the top.

### 2. Chunk-Based Sort - "Medium" Algorithm O(n√n)
This algorithm sorts `stack_a` in a two-step process:

1. **Chunking:** A `chunk_size` is determined by the square root of the stack size. `stack_a` is scanned for nodes with indexes falling within the current `search_limit`. Matching nodes are pushed to `stack_b`. The `search_limit` increments by `chunk_size` until `stack_a` is empty.
2. **Final Sorting:** `stack_b` is scanned for the highest index. If the target node is in the upper half of the stack, standard rotations (`rb`) are used; if in the bottom half, reverse rotations (`rrb`) are used. This optimization ensures efficient O(n) retrieval, pushing nodes back to `stack_a` in final sorted order.

### 3. Radix Sort - "Complex" Algorithm O(n log n)
This implementation uses a base-2 (binary) Radix sort. Because node indexes are pre-assigned contiguously from `0 to size - 1`, the algorithm only evaluates positive integers without gaps. It calculates the maximum number of bits needed to represent the highest index. Iterating bit by bit starting from the least significant bit, it checks each node in `stack_a`. If the current bit is 0, the node is pushed to `stack_b` (`pb`). If the bit is 1, it is rotated to the bottom of `stack_a` (`ra`). After checking all nodes for the current bit, everything in `stack_b` is pushed back to `stack_a`. This loop repeats for the maximum number of bits required, resulting in a fully sorted stack.

---

## Resources
* **Big O Notation explanation:** https://www.geeksforgeeks.org/dsaanalysis-algorithms-big-o-analysis/;
* **Stacks explanation:** https://en.wikipedia.org/wiki/Stack_(abstract_data_type);
* **AI Usage:** Used to visualize algorithms and help translate them into stack compatible versions;