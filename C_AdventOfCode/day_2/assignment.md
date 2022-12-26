---
marp: false
---

## Day 2

- Input: encrypted strategy guide for rock paper scissors in the form of a 2 column text file.
	- The first collumn contains what the opponent will play.
		- A: Rock
		- B: Paper
		- C: Scissors
	- The second collumn contains what you need to play.
		- X: Rock
		- Y: Paper
		- Z: Scissors
	- Score is gained for each round based on what you played and the outcome
		- Rock: 1
		- Paper: 2
		- Scissors: 3
		- Loss: 0
		- Draw: 3
		- Win: 6

rock/paper/scissor result grid

|		| rock	| paper	| scissor	|
|-------|-------|-------|-----------|
| rock	| 3		| 6		| 0			|		
| paper	| 0		| 3		| 6			|
|scissor| 6		| 0		| 3			|