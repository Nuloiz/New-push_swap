This project has been created as part of the 42 curriculum by nschutz
## Description

**Push_swap** is an algorithmic challenge that requires sorting a stack of integers using only two stacks (A and B) and a limited set of operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rra`, `rb`, `rrb`, `rr`, `rrr`. The goal is to minimize the number of operations while handling up to 500 unique integers within strict performance constraints.

This implementation features a highly optimized **Turk Sort algorithm** that achieves exceptional performance:
- **Reverse sorted 500 numbers**: 1493 moves (top 1% performance)  
- **Random 500 numbers**: ~5400 moves average (top 10%)
- Full support for all 11 push_swap operations including optimized `rr`/`rrr` detection

Key optimizations include precise target node finding, cost-based position selection, rotation optimization (using list size/2), and intelligent combined rotation handling (`rr_posibility`).

## Instructions

### Compilation
```bash
make
# or
make bonus
# or
make check
# or
make small_check
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