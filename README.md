# CodeReference

A growing collection of reusable code snippets, practical examples, and programming references for ANQL.

## What you'll find here

CodeReference is intended to make useful development knowledge easier to find and reuse. Entries may include:

- Small, focused code snippets
- Practical examples for common programming tasks
- Notes and references that explain when and how to use them

The collection is evolving; check back as new material is added.

## Repository structure

Sorting examples are grouped by algorithm. Each algorithm folder contains the source files for all supported languages:

```text
sorting/
├── bubble-sort/
│   ├── bubble_sort.py
│   ├── BubbleSort.java
│   ├── bubble_sort.rs
│   └── ...
├── merge-sort/
│   ├── merge_sort.py
│   ├── MergeSort.java
│   └── ...
└── quick-sort/
    ├── quick_sort.py
    ├── QuickSort.java
    └── ...
```

Each source file is named after its algorithm and uses the appropriate language extension. Sorting algorithms are provided in Python, Java, Rust, C, C++, C#, JavaScript, and Go.

The collection includes bubble, selection, insertion, merge, quick, heap, counting, radix, bucket, and shell sort. Counting sort and bucket sort operate on integers; radix sort accepts non-negative integers.

## Using this repository

Browse the repository for a topic or example relevant to your work. Adapt snippets to your project, and review their assumptions and requirements before using them in production.

## Contributing

Contributions that make the collection clearer and more useful are welcome. When adding an example, keep it focused, explain any important context or prerequisites, and make sure the code is easy to understand and reuse.

## License

This project is distributed under the [MIT License](./LICENSE).
