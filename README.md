# CodeReference

A growing collection of reusable code snippets, practical examples, and programming references for ANQL.

## What you'll find here

CodeReference is intended to make useful development knowledge easier to find and reuse. Entries may include:

- Small, focused code snippets
- Practical examples for common programming tasks
- Notes and references that explain when and how to use them

The collection is evolving; check back as new material is added.

## Repository structure

Examples are organized by category, then by algorithm. Each algorithm folder contains the source files for all supported languages:

```text
<category>/
├── <algorithm>/
│   ├── <algorithm>.py
│   ├── <Algorithm>.java
│   └── ...
```

Categories currently include sorting, searching, graphs, dynamic programming, and mathematics. Each algorithm's source files are placed directly in its folder and use the appropriate language extension. Implementations are provided in Python, Java, Rust, C, C++, C#, JavaScript, and Go.

The sorting collection includes bubble, selection, insertion, merge, quick, heap, counting, radix, bucket, and shell sort. Counting sort and bucket sort operate on integers; radix sort accepts non-negative integers.

Searching includes linear, binary, and interpolation search. Graph algorithms include breadth-first and depth-first search, Dijkstra's and Bellman-Ford shortest paths, A*, topological sort, Kruskal's and Prim's minimum spanning trees. Dynamic programming includes Fibonacci, 0/1 knapsack, and longest common subsequence. Mathematics includes Euclid's GCD, the Sieve of Eratosthenes, and fast exponentiation.

## Using this repository

Browse the repository for a topic or example relevant to your work. Adapt snippets to your project, and review their assumptions and requirements before using them in production.

## Contributing

Contributions that make the collection clearer and more useful are welcome. When adding an example, keep it focused, explain any important context or prerequisites, and make sure the code is easy to understand and reuse.

## License

This project is distributed under the [MIT License](./LICENSE).
