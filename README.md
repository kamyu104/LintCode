LintCode
======== 

Up to date (2015-05-04), there are `182` problems on [LintCode Online Judge](https://lintcode.com/).
The number of problems is increasing recently.
Here is the classification of all `182` problems.
For extra problems and solutions, you can see my [LeetCode](https://github.com/kamyu104/LeetCode) repo.
I'll keep updating for full summary and better solutions. Stay tuned for updates.

--- 
Algorithms
====

* [Bit Manipulation](https://github.com/kamyu104/LintCode#bit-manipulation)
* [Array](https://github.com/kamyu104/LintCode#array)
* [String](https://github.com/kamyu104/LintCode#string)
* [Linked List](https://github.com/kamyu104/LintCode#linked-list)
* [Math](https://github.com/kamyu104/LintCode#math)
* [Tree](https://github.com/kamyu104/LintCode#tree)
* [Stack](https://github.com/kamyu104/LintCode#stack)
* [Queue](https://github.com/kamyu104/LintCode#queue)
* [Heap](https://github.com/kamyu104/LintCode#heap)
* [Hash Tables](https://github.com/kamyu104/LintCode#hash-tables)
* [Data Structure](https://github.com/kamyu104/LintCode#data-structure)
* [Sort](https://github.com/kamyu104/LintCode#sort)
* [Divide and Conquer](https://github.com/kamyu104/LintCode#divide-and-conquer)
* [Binary Search](https://github.com/kamyu104/LintCode#binary-search)
* [Depth First Search](https://github.com/kamyu104/LintCode#depth-first-search)
* [Breadth First Search](https://github.com/kamyu104/LintCode#breath-first-search)
* [Binary Search Trees](https://github.com/kamyu104/LintCode#binary-search-trees)
* [Dynamic Programming](https://github.com/kamyu104/LintCode#dynamic-programming)
* [Greedy](https://github.com/kamyu104/LintCode#greedy)
* [Design Pattern](https://github.com/kamyu104/LintCode#design-pattern)

---

##Bit Manipulation
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|1|[A + B Problem](http://lintcode.com/en/problem/a-b-problem/)| [C++](./C++/a-b-problem.cpp)| _O(1)_ | _O(1)_ | Hard | | |
|82|[Single Number](http://lintcode.com/en/problem/single-number-iii/)| [C++](./C++/single-number.cpp)| _O(n)_ | _O(1)_ | Easy | LeetCode| |
|83|[Single Number II](http://lintcode.com/en/problem/single-number-iii/)| [C++](./C++/single-number-ii.cpp)| _O(n)_ | _O(1)_ | Easy | LeetCode | |
|84|[Single Number III](http://lintcode.com/en/problem/single-number-iii/)| [C++](./C++/single-number-iii.cpp)| _O(n)_ | _O(1)_ | Medium | CC150 | |
|142|[O(1) Check Power of 2](http://lintcode.com/en/problem/o1-check-power-of-2/)| [C++](./C++/o1-check-power-of-2.cpp)| _O(1)_ | _O(1)_ | Easy | | |
|179|[Update Bits](http://lintcode.com/en/problem/update-bits/)| [C++](./C++/update-bits.cpp)| _O(1)_ | _O(1)_ | Medium | CC150 | |
|181|[Convert Integer A to Integer B](http://lintcode.com/en/problem/convert-integer-a-to-integer-b/)| [C++](./C++/convert-integer-a-to-integer-b.cpp)| _O(1)_ | _O(1)_ | Easy | CC150 | |

---

##Array
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|6|[Merge Sorted Array](http://lintcode.com/en/problem/merge-sorted-array/)| [C++](./C++/merge-sorted-array.cpp)| _O(m + n)_ | _O(1)_ | Easy | LeetCode | Two Pointers |
|9|[Fizz Buzz](http://lintcode.com/en/problem/fizz-buzz/)| [C++](./C++/fizz-buzz.cpp)| _O(n)_ | _O(1)_ | Easy | | |
|31|[Partition Array](http://lintcode.com/en/problem/partition-array/)| [C++](./C++/partition-array.cpp)| _O(n)_ | _O(1)_ | Medium | | Two Pointers |
|46|[Majority Number](http://lintcode.com/en/problem/majority-number/)| [C++](./C++/majority-number.cpp)| _O(n)_ | _O(1)_ | Easy | LeetCode | |
|47|[Majority Number II](http://lintcode.com/en/problem/majority-number/)| [C++](./C++/majority-number-ii.cpp)| _O(n)_ | _O(1)_ | Medium | EPI | |
|48|[Majority Number III](http://lintcode.com/en/problem/majority-number-iii/)| [C++](./C++/majority-number-iii.cpp)| _O(n)_ | _O(k)_ | Medium | EPI | |
|49|[Sort Letters by Case](http://lintcode.com/en/problem/sort-letters-by-case/)| [C++](./C++/sort-letters-by-case.cpp)| _O(n)_ | _O(1)_ | Medium | | Two Pointers |
|50|[Product of Array Exclude Itself](http://lintcode.com/en/problem/product-of-array-exclude-itself/)| [C++](./C++/product-of-array-exclude-itself.cpp)| _O(n)_ | _O(n)_ | Easy | | |
|51|[Previous Permutation](http://lintcode.com/en/problem/previous-permutation/)| [C++](./C++/previous-permutation.cpp)| _O(n)_ | _O(1)_ | Medium | | |
|52|[Next Permutation](http://lintcode.com/en/problem/next-permutation/)| [C++](./C++/next-permutation.cpp)| _O(n)_ | _O(1)_ | Medium | LeetCode | |
|57|[3 Sum](http://lintcode.com/en/problem/3-sum/)| [C++](./C++/3-sum.cpp)| _O(n^2)_ | _O(1)_ | Medium | LeetCode | Two Pointers, Sort |
|59|[3 Sum Closest](http://lintcode.com/en/problem/3-sum-closest/)| [C++](./C++/3-sum-closest.cpp)| _O(n^2)_ | _O(1)_ | Medium | LeetCode | Two Pointers, Sort |
|64|[Merge Sorted Array II](http://lintcode.com/en/problem/merge-sorted-array-ii/)| [C++](./C++/merge-sorted-array-ii.cpp)| _O(m + n)_ | _O(1)_ | Easy | LeetCode | Two Pointers |
|100|[Remove Duplicates from Sorted Array](http://lintcode.com/en/problem/remove-duplicates-from-sorted-array/)| [C++](./C++/remove-duplicates-from-sorted-array.cpp)| _O(n)_ | _O(1)_ | Easy | LeetCode | Two Pointers |
|101|[Remove Duplicates from Sorted Array II](http://lintcode.com/en/problem/remove-duplicates-from-sorted-array-ii/)| [C++](./C++/remove-duplicates-from-sorted-array-ii.cpp)| _O(n)_ | _O(1)_ | Easy | LeetCode | Two Pointers |
|172|[Remove Element](http://lintcode.com/en/problem/remove-element/)| [C++](./C++/remove-element.cpp)| _O(n)_ | _O(1)_ | Easy | LeetCode | Two Pointers |
|185|[Matrix Zigzag Traversal](http://lintcode.com/en/problem/matrix-zigzag-traversal/)| [C++](./C++/matrix-zigzag-traversal.cpp)| _O(m * n)_ | _O(1)_ | Easy | | |
|189|[First Missing Positive](http://lintcode.com/en/problem/first-missing-positive/)| [C++](./C++/first-missing-positive.cpp)| _O(n)_ | _O(1)_ | Easy | LeetCode, EPI | Hash |
|363|[Trapping Rain Water](http://lintcode.com/en/problem/trapping-rain-water/)| [C++](./C++/trapping-rain-water.cpp)| _O(n)_ | _O(1)_ | Medium | LeetCode | Two Pointers, Tricky |
|389|[Valid Sudoku](http://lintcode.com/en/problem/valid-sudoku/)| [C++](./C++/valid-sudoku.cpp)| _O(9^2)_ | _O(9)_ | Easy | LeetCode | |

---

##String
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|13|[strStr](http://lintcode.com/en/problem/strstr/)|[C++](./C++/strstr.cpp)| _O(n)_ | _O(k)_ | Easy | LeetCode | `KMP Algorithm` |
|54|[Convert String to Integer](http://lintcode.com/en/problem/convert-string-to-integer/)|[C++](./C++/convert-string-to-integer.cpp)| _O(n)_ | _O(1)_ | Hard | LeetCode | |
|55|[Compare Strings](http://lintcode.com/en/problem/compare-strings/)|[C++](./C++/compare-strings.cpp)| _O(n)_ | _O(c)_ | Easy | | |
|78|[Longest Common Prefix](http://lintcode.com/en/problem/longest-common-prefix/)|[C++](./C++/longest-common-prefix.cpp)| _O(n)_ | _O(1)_ | Medium | | |
|157|[Unique Characters](http://lintcode.com/en/problem/unique-characters/)|[C++](./C++/unique-characters.cpp)| _O(n)_ | _O(1)_ | Easy | CC150 | |
|158|[Two Strings Are Anagrams](http://lintcode.com/en/problem/two-strings-are-anagrams/)|[C++](./C++/two-strings-are-anagrams.cpp)| _O(n)_ | _O(1)_ | Easy | | |
|171|[Anagrams](http://lintcode.com/en/problem/anagrams/)|[C++](./C++/anagrams.cpp)| _O(n * klogk)_ | _O(m)_ | Easy | LeetCode, EPI | |

---

##Linked List
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|102|[Linked List Cycle](http://lintcode.com/en/problem/linked-list-cycle/)|[C++](./C++/linked-list-cycle.cpp)| _O(n)_ | _O(1)_ | Medium | LeetCode | |
|103|[Linked List Cycle II](http://lintcode.com/en/problem/linked-list-cycle-ii/)|[C++](./C++/linked-list-cycle-ii.cpp)| _O(n)_ | _O(1)_ | Hard | LeetCode | |

---

##Tree
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|85|[Insert Node in a Binary Search Tree](http://lintcode.com/en/problem/insert-node-in-a-binary-search-tree/)| [C++](./C++/insert-node-in-a-binary-search-tree.cpp)| _O(h)_ | _O(1)_ | Easy | | |
|88|[Lowest Common Ancestor](http://lintcode.com/en/problem/lowest-common-ancestor/)| [C++](./C++/lowest-common-ancestor.cpp)| _O(n)_ | _O(h)_ | Medium | EPI | |
|127|[Max Tree](http://lintcode.com/en/problem/max-tree/)| [C++](./C++/max-tree.cpp)| _O(n)_ | _O(n)_ | Hard | | |

---

##Stack
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|40|[Implement Queue by Two Stacks](http://lintcode.com/en/problem/implement-queue-by-two-stacks/)| [C++](./C++/implement-queue-by-two-stacks.cpp)| _O(1), amortized_ | _O(n)_ | Medium | EPI | |
|122|[Largest Rectangle in Histogram](http://lintcode.com/en/problem/largest-rectangle-in-histogram/)| [C++](./C++/largest-rectangle-in-histogram.cpp)| _O(n)_ | _O(n)_ | Hard | LeetCode, EPI | |
|368|[Expression evaluation](http://lintcode.com/en/problem/expression-evaluation/)| [C++](./C++/expression-evaluation.cpp)| _O(n)_ | _O(n)_ | Hard | | |

---

##Queue
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|362|[Sliding Window Maximum](http://lintcode.com/en/problem/sliding-window-maximum/)| [C++](./C++/sliding-window-maximum.cpp)| _O(n)_ | _O(k)_ | Hard | EPI | Deque, Tricky |

---

##Heap
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|4|[Ugly Number](http://lintcode.com/en/problem/ugly-number/)| [C++](./C++/ugly-number.cpp)| _O(k)_ | _O(1)_ | Medium | CC150 | |
|81|[Median in Data Stream](http://lintcode.com/en/problem/median-in-data-stream/)| [C++](./C++/median-in-data-stream.cpp)| _O(nlogn)_ | _O(n)_ | Hard | EPI | BST, Heap |
|130|[Heapify](http://lintcode.com/en/problem/heapify/)| [C++](./C++/heapify.cpp)| _O(n)_ | _O(1)_ | Medium | | |
|364|[Trapping Rain Water II](http://lintcode.com/en/problem/trapping-rain-water-ii/)| [C++](./C++/trapping-rain-water-ii.cpp)| _O(n^2 * logn)_ | _O(n^2)_ | Hard | | BFS, Heap, Tricky |

---

##Hash Tables
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|56|[2 Sum](http://lintcode.com/en/problem/2-sum/)| [C++](./C++/2-sum.cpp)| _O(n)_ | _O(n)_ | Medium | LeetCode | |
|58|[4 Sum](http://lintcode.com/en/problem/4-sum/)| [C++](./C++/4-sum.cpp)| _O(n^2 * p)_ | _O(n^2 * p)_ | Medium | LeetCode | Hash |
|124|[Longest Consecutive Sequence](http://lintcode.com/en/problem/longest-consecutive-sequence/)| [C++](./C++/longest-consecutive-sequence.cpp)| _O(n)_ | _O(n)_ | Medium | LeetCode, EPI | |
|128|[Hash Function](http://lintcode.com/en/problem/hash-function/)| [C++](./C++/hash-function.cpp)| _O(n)_ | _O(1)_ | Easy | | |
|129|[Rehashing](http://lintcode.com/en/problem/rehashing/)| [C++](./C++/rehashing.cpp)| _O(n)_ | _O(n)_ | Medium | | |
|138|[Subarray Sum](http://lintcode.com/en/problem/subarray-sum/)| [C++](./C++/subarray-sum.cpp)| _O(n)_ | _O(n)_ | Easy | | |

---

##Data Structure
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|134|[LRU Cache](http://lintcode.com/en/problem/lru-cache/)| [C++](./C++/lru-cache.cpp)| _O(1)_ | _O(c)_ | Hard | LeetCode, EPI | List, Hash |

---

##Math
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|2|[Trailing Zeros](http://lintcode.com/en/problem/trailing-zeros/)| [C++](./C++/trailing-zeros.cpp)| _O(logn)_ | _O(1)_ | Easy | LeetCode | |
|3|[Digit Counts](http://lintcode.com/en/problem/digit-counts/)| [C++](./C++/digit-counts.cpp)| _O(logn)_ | _O(1)_ | Medium | CC150 | |
|11|[Unique Paths](http://lintcode.com/en/problem/unique-paths/)| [C++](./C++/unique-paths.cpp)| _O(min(m, n))_ | _O(1)_ | Easy | CC150 | DP, Math |
|163|[Unique Binary Search Trees](http://lintcode.com/en/problem/unique-binary-search-trees/)| [C++](./C++/unique-binary-search-trees.cpp)| _O(n)_ | _O(1)_ | Medium | CC150 | DP, Math, `Catalan Number` |
|180|[Binary Represention](http://lintcode.com/en/problem/delete-digits/)| [C++](./C++/binary-representation.cpp)| _O(1)_ | _O(1)_ | Hard | CC150 | |

---

##Sort
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|80|[Median](http://lintcode.com/en/problem/median/)| [C++](./C++/median.cpp)| _O(n)_ | _O(1)_ | Easy | EPI | |
|139|[Subarray Sum Closest](http://lintcode.com/en/problem/subarray-sum-closest/)| [C++](./C++/subarray-sum-closest.cpp)| _O(nlogn)_ | _O(n)_ | Medium | | Sort |
|143|[Sort Colors II](http://lintcode.com/en/problem/sort-colors-ii/)| [C++](./C++/sort-colors-ii.cpp)| _O(n)_ | _O(1)_ | Medium | | |
|184|[Largest Number](http://lintcode.com/en/problem/largest-number/)| [C++](./C++/largest-number.cpp)| _O(nlogn)_ | _O(1)_ | Medium | LeetCode | |

---

##Divide and Conquer
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|93|[Balanced Binary Tree](http://lintcode.com/en/problem/balanced-binary-tree/)| [C++](./C++/balanced-binary-tree.cpp)| _O(n)_ | _O(h)_ | Easy | LeetCode | |
|94|[Binary Tree Maximum Path Sum](http://lintcode.com/en/problem/binary-tree-maximum-path-sum/)| [C++](./C++/binary-tree-maximum-path-sum.cpp)| _O(n)_ | _O(h)_ | Medium | LeetCode | |
|97|[Maximum Depth of Binary Tree](http://lintcode.com/en/problem/maximum-depth-of-binary-tree/)| [C++](./C++/maximum-depth-of-binary-tree.cpp)| _O(n)_ | _O(h)_ | Easy | LeetCode | |
|131|[Building Outline](http://lintcode.com/en/problem/building-outline/)| [C++](./C++/building-outline.cpp)| _O(nlogn)_ | _O(n)_ | Hard | EPI | |
|140|[Fast Power](http://lintcode.com/en/problem/fast-power/)| [C++](./C++/fast-power.cpp)| _O(logn)_ | _O(logn)_ | Medium | | |
|155|[Minimum Depth of Binary Tree](http://lintcode.com/en/problem/minimum-depth-of-binary-tree/)| [C++](./C++/minimum-depth-of-binary-tree.cpp)| _O(n)_ | _O(h)_ | Easy | LeetCode | |
|201|[Segment Tree Build](http://lintcode.com/en/problem/segment-tree-build/)| [C++](./C++/segment-tree-build.cpp)| _O(n)_ | _O(h)_ | Medium | | Segment Tree, BST |
|202|[Segment Tree Query](http://lintcode.com/en/problem/segment-tree-query/)| [C++](./C++/segment-tree-query.cpp)| _O(h)_ | _O(h)_ | Medium | | Segment Tree, BST |
|203|[Segment Tree Modify](http://lintcode.com/en/problem/segment-tree-modify/)| [C++](./C++/segment-tree-modify.cpp)| _O(h)_ | _O(h)_ | Medium | | Segment Tree, BST |
|205|[Interval Minimum Number](http://lintcode.com/en/problem/interval-minimum-number/)| [C++](./C++/interval-minimum-number.cpp)| build tree: _O(n)_, query: _(h)_ | _O(h)_ | Hard | | Segment Tree, BST |
|206|[Interval Sum](http://lintcode.com/en/problem/interval-sum/)| [C++](./C++/interval-sum.cpp)| build tree: _O(n)_, query: _O(h)_ | _O(h)_ | Hard | | Segment Tree, BST |
|207|[Interval Sum II](http://lintcode.com/en/problem/interval-sum-ii/)| [C++](./C++/interval-sum-ii.cpp)| build tree: _O(n)_, query: _O(h)_, modify: _O(h)_ | _O(h)_ | Hard | | Segment Tree, BST |
|247|[Segment Tree Query II](http://lintcode.com/en/problem/segment-tree-query-ii/)| [C++](./C++/segment-tree-query-ii.cpp)| _O(h)_ | _O(h)_ | Hard | | Segment Tree, BST |

---

##Binary Search
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|14|[Binary Search](http://lintcode.com/en/problem/binary-search/)| [C++](./C++/binary-search.cpp)| _O(logn)_ | _O(1)_ | Easy | | |
|28|[Search a 2D Matrix](http://lintcode.com/en/problem/search-a-2d-matrix/)| [C++](./C++/search-a-2d-matrix.cpp)| _O(logm + logn)_ | _O(1)_ | Easy | LeetCode | |
|60|[Search Insert Position](http://lintcode.com/en/problem/search-insert-position/)| [C++](./C++/search-insert-position.cpp)| _O(logn)_ | _O(1)_ | Easy | LeetCode | |
|61|[Search for a Range](http://lintcode.com/en/problem/search-for-a-range/)| [C++](./C++/search-for-a-range.cpp)| _O(logn)_ | _O(1)_ | Medium | LeetCode | |
|62|[Search in Rotated Sorted Array](http://lintcode.com/en/problem/search-in-rotated-sorted-array/)| [C++](./C++/search-in-rotated-sorted-array.cpp)| _O(logn)_ | _O(1)_ | Hard | LeetCode | |
|63|[Search in Rotated Sorted Array II](http://lintcode.com/en/problem/search-in-rotated-sorted-array-ii/)| [C++](./C++/search-in-rotated-sorted-array-ii.cpp)| _O(logn)_ | _O(1)_ | Medium | LeetCode | |
|65|[Median of two Sorted Arrays](http://lintcode.com/en/problem/median-of-two-sorted-arrays/)| [C++](./C++/median-of-two-sorted-arrays.cpp)| _O(log(min(m, n)))_ | _O(1)_ | Hard | LeetCode, EPI | Tricky |
|74|[First Bad Version](http://lintcode.com/en/problem/first-bad-version/)| [C++](./C++/first-bad-version.cpp)| _O(logn)_ | _O(1)_ | Medium | | |
|75|[Find Peak Element](http://lintcode.com/en/problem/find-peak-element/)| [C++](./C++/find-peak-element.cpp)| _O(logn)_ | _O(1)_ | Medium | LeetCode | |
|76|[Longest Increasing Subsequence](http://lintcode.com/en/problem/longest-increasing-subsequence/)| [C++](./C++/longest-increasing-subsequence.cpp)| _O(nlogn)_ | _O(n)_ | Medium | CC150 | |
|141|[Sqrt(x)](http://lintcode.com/en/problem/sqrtx/)| [C++](./C++/sqrtx.cpp)| _O(logn)_ | _O(1)_ | Easy | LeetCode | |
|159|[Find Minimum in Rotated Sorted Array](http://lintcode.com/en/problem/find-minimum-in-rotated-sorted-array/)| [C++](./C++/find-minimum-in-rotated-sorted-array.cpp)| _O(logn)_ | _O(1)_ | Medium | LeetCode | |
|160|[Find Minimum in Rotated Sorted Array II](http://lintcode.com/en/problem/find-minimum-in-rotated-sorted-array-ii/)| [C++](./C++/find-minimum-in-rotated-sorted-array-ii.cpp)| _O(logn)_ | _O(1)_ | Medium | LeetCode | |
|183|[Wood Cut](http://lintcode.com/en/problem/wood-cut/)| [C++](./C++/wood-cut.cpp)| _O(nlogL)_ | _O(1)_ | Medium | | |

---

##Depth First Search
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|90|[K Sum II](http://lintcode.com/en/problem/k-sum-ii/)| [C++](./C++/k-sum-ii.cpp)| _O(C(n, k))_ | _O(k)_ | Medium | | |
|123|[Word Search](http://lintcode.com/en/problem/word-search/)| [C++](./C++/word-search.cpp)| _O(m * n * l)_ | _O(l)_ | Medium | LeetCode | |
|132|[Word Search II](http://lintcode.com/en/problem/word-search-ii/)| [C++](./C++/word-search-ii.cpp)| _O(m * n * l)_ | _O(l)_ | Hard | | Trie, BFS |

---

##Breadth First Search
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|127|[Topological Sorting](http://lintcode.com/en/problem/topological-sorting/)| [C++](./C++/topological-sorting.cpp)| _O(\|V\|+\|E\|)_ | _O(\|E\|)_ | Medium | | DFS, BFS |
|176|[Route Between Two Nodes in Graph](http://lintcode.com/en/problem/route-between-two-nodes-in-graph/)| [C++](./C++/route-between-two-nodes-in-graph.cpp)| _O(n)_ | _O(n)_ | Medium | | DFS, BFS |

---

##Binary Search Trees
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|84|[Remove Node in Binary Search Tree](http://lintcode.com/en/problem/remove-node-in-binary-search-tree/)| [C++](./C++/remove-node-in-binary-search-tree.cpp)| _O(h)_ | _O(h)_ | Hard | | |
|85|[Implement Iterator of Binary Search Tree](http://lintcode.com/en/problem/implement-iterator-of-binary-search-tree/)| [C++](./C++/implement-iterator-of-binary-search-tree.cpp)| _O(1)_ | _O(h)_ | Hard | LeetCode | |
|360|[Sliding Window Median](http://lintcode.com/en/problem/sliding-window-median/)| [C++](./C++/sliding-window-median.cpp)| _O(nlogw)_ | _O(w)_ | Hard | | BST, Tricky |

---

##Dynamic Programming
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|43|[Maximum Subarray III](http://lintcode.com/en/problem/maximum-subarray-iii/)| [C++](./C++/maximum-subarray-iii.cpp)| _O(k * n^2)_ | _O(k * n)_ | Hard | | |
|77|[Longest Common Sequence](http://lintcode.com/en/problem/longest-common-sequence/)| [C++](./C++/longest-common-sequence.cpp)| _O(m * n)_ | _O(min(m, n))_ | Medium | | |
|79|[Longest Common Substring](http://lintcode.com/en/problem/longest-common-substring/)| [C++](./C++/longest-common-substring.cpp)| _O(m * n)_ | _O(min(m, n))_ | Medium | | |
|89|[K Sum](http://lintcode.com/en/problem/k-sum/)| [C++](./C++/k-sum.cpp)| _O(k * n * t)_ | _O(n * t)_ | Hard | | |
|91|[Minimum Adjustment Cost](http://lintcode.com/en/problem/minimum-adjustment-cost/)| [C++](./C++/minimum-adjustment-cost.cpp)| _O(k * n * t)_ | _O(k)_ | Medium | | |
|92|[Backpack](http://lintcode.com/en/problem/backpack/)| [C++](./C++/backpack.cpp)| _O(m * n)_ | _O(m)_ | Easy | | |
|107|[Word Segmentation](http://lintcode.com/en/problem/word-segmentation/)| [C++](./C++/word-segmentation.cpp)| _O(n^2)_ | _O(n)_ | Medium | LeetCode, EPI | |
|109|[Triangle](http://lintcode.com/en/problem/triangle/)| [C++](./C++/triangle.cpp)| _O(n)_ | _O(n)_ | Easy | LeetCode, EPI | |
|125|[Backpack II](http://lintcode.com/en/problem/backpack-ii/)| [C++](./C++/backpack-ii.cpp)| _O(m * n)_ | _O(m)_ | Medium | | |
|149|[Best Time to Buy and Sell Stock](http://lintcode.com/en/problem/best-time-to-buy-and-sell-stock/)| [C++](./C++/best-time-to-buy-and-sell-stock.cpp)| _O(n)_ | _O(1)_ | Medium | LeetCode, EPI | |
|150|[Best Time to Buy and Sell Stock II](http://lintcode.com/en/problem/best-time-to-buy-and-sell-stock-ii/)| [C++](./C++/best-time-to-buy-and-sell-stock-ii.cpp)| _O(n)_ | _O(1)_ | Medium | LeetCode, EPI | |
|151|[Best Time to Buy and Sell Stock III](http://lintcode.com/en/problem/best-time-to-buy-and-sell-stock-iii/)| [C++](./C++/best-time-to-buy-and-sell-stock-iii.cpp)| _O(n)_ | _O(1)_ | Medium | LeetCode, EPI | |
|152|[Regular Expression Matching](http://lintcode.com/en/problem/regular-expression-matching/)| [C++](./C++/regular-expression-matching.cpp)| _O(m * n)_ | _O(m)_ | Hard | LeetCode | DP, Recursion |
|191|[Maximum Product Subarray](http://lintcode.com/en/problem/maximum-product-subarray/)| [C++](./C++/maximum-product-subarray.cpp)| _O(n)_ | _O(1)_ | Medium | LeetCode | |

---

##Greedy
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|41|[Maximum Subarray](http://lintcode.com/en/problem/maximum-subarray/)| [C++](./C++/maximum-subarray.cpp)| _O(n)_ | _O(1)_ | Easy | LeetCode | |
|42|[Maximum Subarray II](http://lintcode.com/en/problem/maximum-subarray-ii/)| [C++](./C++/maximum-subarray-ii.cpp)| _O(n)_ | _O(n)_ | Medium | | |
|44|[Minimum Subarray](http://lintcode.com/en/problem/minimum-subarray/)| [C++](./C++/minimum-subarray.cpp)| _O(n)_ | _O(1)_ | Easy | | |
|45|[Maximum Subarray Difference](http://lintcode.com/en/problem/maximum-subarray-difference/)| [C++](./C++/maximum-subarray-difference.cpp)| _O(n)_ | _O(n)_ | Medium | | |
|116|[Jump Game](http://lintcode.com/en/problem/jump-game/)| [C++](./C++/jump-game.cpp)| _O(n)_ | _O(1)_ | Medium | LeetCode | |
|117|[Jump Game II](http://lintcode.com/en/problem/jump-game-ii/)| [C++](./C++/jump-game-ii.cpp)| _O(n)_ | _O(1)_ | Medium | LeetCode | |
|182|[Delete Digits](http://lintcode.com/en/problem/delete-digits/)| [C++](./C++/delete-digits.cpp)| _O(n)_ | _O(n)_ | Medium | | |
|187|[Gas Station](http://lintcode.com/en/problem/gas-station/)| [C++](./C++/gas-station.cpp)| _O(n)_ | _O(1)_ | Easy | LeetCode | |
|192|[Wildcard Matching](http://lintcode.com/en/problem/wildcard-matching/)| [C++](./C++/wildcard-matching.cpp)| _O(m + n)_ | _O(1)_ | Hard | LeetCode | Greedy, DP, Recursion |

---

##Design Pattern
| # | Title | Solution | Time | Space | Difficulty | Tag | Note |
|---| ----- | -------- | ---- | ----- | ---------- | --- | ---- |
|204|[Singleton](http://lintcode.com/en/problem/singleton/)| [C++](./C++/singleton.cpp)| _O(1)_ | _O(1)_ | Easy | | |

