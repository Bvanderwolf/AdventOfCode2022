---
marp: false
---

## Day 4

- Input: The section assignments for a pair of Elfes.
	- Example: 2-4, 3-5
		- 2-4: 2,3,4
		- 3-5: 3,4,5
	- The goal is to find overlapping assignments so that one section is fully contained in the other.
		- Examples:
			- 2-4, 3-4: 2-4 fully contains 3-4
			- 3-7, 2-8: 2-8 fully contains 3-7
- Output: The amount of pairs where one section fully contains the other.

condition check:

1. section one -> s1
2. section two -> s2

**2-4,6-8**
s1.start <= s2.start && s1.end >= s2.end

s2.start <= s1.start && s2.end >= s1.end