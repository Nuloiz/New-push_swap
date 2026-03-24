This project has been created as part of the 42 curriculum by nschutz
## Description

**Push_swap** is a project which requires to code an algorithm. This algorithm hast to sort a stack of integers using only two stacks and a limited set of operations: 
`sa` (Switch the first two Elements in Stack A),
`sb` (Switch the first two Elements in Stack B),
`ss` (Switch the first two Elements in Stack A & in Stack B),
`pa` (Push the first Element of Stack B on Stack A),
`pb` (Push the first Element of Stack A on Stack B),
`ra` (Rotate Elements in Stack A),
`rra`(Reverse rotate Elements in Stack A),
`rb` (Rotate Elements in Stack B),
`rrb` (REverse rotate Elements in Stack B),
`rr` (Rotate Elements in Stack A & in Stack B),
`rrr` (Reverse rotate Elements in Stack A & in Stack B).
The algorithm should sort up to 500 unique integers with a minimized amount of operations, while also be efficient in performance.

This project was already once done by me three years earlier than this Implementaion, using the **Radix Sort algorithm**. The radix implementation worked fine, but wasn't as efficient as the algorithm I am using now.

This implementation features a highly optimized **Turk Sort algorithm** that achieves far better performance:
- **Reverse sorted 500 numbers**: up to 600 moves 
- **Random 500 numbers**: up to 5400 moves
- Full support for all 11 push_swap operations, except `ss`.
- Including optimized `rr`/`rrr` detection

Key optimizations include precise target node finding, cost-based position selection, rotation optimization (using list size/2), and intelligent combined rotation handling (`rr_posibility`).

## Instructions

### Compilation
```bash
make
# or
make bonus
# or
make check #Own written full scale check
# or
make small_check #Own written small scale check
# or 
make bcn #n = number 1 to 5 // Own written bonus check
```

## Ressources

Algorithmic References
Push_swap Official Subject

Turk Sort algorithm research and optimization patterns from 42 community implementations

Stack rotation optimization techniques (rr/rrr cost reduction)

Core Concepts Studied
Doubly linked list implementation for O(1) rotations

Optimal target finding for minimal move cost

Cost function optimization with rotation distance minimization

Combined operation detection (rr/rrr possibility analysis)

AI Usage
AI assistance was used exclusively for:

Debugging compiler errors (name shadowing, prototype issues)

Memory leak analysis (ft_calloc indexing bugs, array termination)

Input validation edge cases (empty strings, whitespace handling)

Performance verification (worst-case input generation, move counting)

No algorithmic logic, cost functions, target finding, or core sorting strategy was AI-generated. The Turk Sort implementation, optimization heuristics, and all performance-critical code is 100% human-written.

Performance benchmarks and input validation logic were human-verified through extensive testing.