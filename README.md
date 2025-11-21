# AlgoBenchSuite

AlgoBenchSuite is a small C program I built to test how long different algorithms take to run.  
The idea is simple: generate an array, run a few sorting and searching methods on it, and measure the execution time in microseconds.  
It’s mainly meant to show how time complexity actually behaves in practice.

The program compares a basic O(n²) sort with a faster insertion‑based sort, then tests both linear search and binary search on 10, 50, and 100 elements.  
Even with small sizes, the difference in speed becomes noticeable, especially when switching from linear to binary search.

Everything runs pretty fast because the data sets are small, but the timing still gives a clear idea of which algorithms scale better.

To try it out:
```bash
gcc -o algobench AlgoBenchSuite.c -lrt
./algobench
