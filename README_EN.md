### #42_tutorial: PUSH_SWAP
### L.I.S. algorithm (vers. 02/22)
grade: 125/100

Given the lack of solutions of the project through the use of the **Longest Increasing Suqsequence algorithms**, I decided to write this README to help all those students who do not have figured out how to implement it.

# The subject
The project requires you to sort any sequence of integers, just as any sort algorithm has been designed and tested for the last 60 years.
However, you wouldn't be reading this if you didn't belong to any 42 course around the world, and it's statistically proven that your likelihood of losing hair increases proportionally to your reading new subjects. So let's see what's wrong with this one.

# Moves

First of all we have two *stacks*: one filled with given random numbers, the _stack_a_, and an empty one that'll serve as a support, the _stack_b_.
Stacks **do not** have a mandatory definition! We worked on lists to overcome the fact that arrays of `int` do not have a null termination term, and thus it's impossible to calculate their own size.
Some mates worked with `struct`, made by _stack_a_ and _b_, their respective size and evenctually by other arrays for successive calculations. Personally I feel I cannot recommend this idea simply in order not to have to manage too many allocations, but this is up to you. After all, what matters is the result!

There are 11 moves available to us, but for simplicity's sake we will divide them into 4 types:
* `sa` 	/	`sb`	/	`ss`	: _**switch**_, swaps the first number in the stack with the second.
* `ra`	/	`rb`	/	`rr` 	: ___rotate___, moves the last number of the stack to the first position, consequently causing all the others to scale.
* `rra`	/	`rrb`	/	`rrr`	: ___reverse rotate___, trivially the same as above but in the opposite sense.
* `pa`	/	`pb`			    : ___push in *___, moves the number to the top position of the opposite stack in the named stack. So pb takes the first number from _a_ to _b_.

I won't explain in detail how they work and how they should be used, I think there are excellent works written by colleagues around the world in this regard. [Here's a link](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) that really helped me and [my teammate](https://github.com/fdrudi "Go follow him!") during initial brainstorming.
Just know his instructions are valid for our project too, but only up to _size 3_ and _size 5_. 

> The reason why we did not want to follow his entire line of thought is because unfortunately in our opinion you cannot get the highest marks with such a technique, but we would be happy to be proven wrong! In case you like his reasoning more than ours, another Italian guy posted [this very similar and super tidy code](https://github.com/AlessandroMetta/push_swap) with which he obtained an excellent score of 90/100. 

We now come to the real trouble of this project: ** the number of possible moves. **
If you read the subject thoroughly, you will not find a reference to it anywhere. However, you just need to know that to get the highest marks you need _700 moves with 100 numbers_ and _5.500 moves with 500 numbers_. We have estimated a 58% of curses on the project entirely dedicated to their optimization.
We have done so.

# The L.I.S. algorithm

The basic idea is particularly simple, but not as easy to think about without getting help from other people or sources.
For those who are particularly good at math, the logic is very similar to that of ordered subsets. For anybody else, let's start by analyzing the last word of the name of the algorithm: _subsequence_. It is a group of numbers taken from the total set, usually (but not necessarily) with a mathematical criterion.

Trivially, it means that among all the possible subsequences or combinations we must take one ___ordered___ in a ___increasing___ way, in particular ___the longest above all!___

Let's take an example: we have a series of random numbers like

```4 - 8 - 2 - 9 - 12 - 1 - 27 - 13 - 32 - 10```

Among these, an _increasing subsquence_ may of course be `4 - 8 - 9`,` 2 - 9 - 13 - 32` or even `1 - 10`.
Our goal however is to take the longest as possible, in this case:

`4 - 8 - 9 - 12 - 27 - 32` or `4 - 8 - 9 - 12 - 13 - 32`. 

The two subsequences are equivalent as they are both 6 in length.
> Pay attention to the maintenance of the initial order! We can't mix the numbers first and then take the values we like best, or we would have already sorted everything and our work would be done ...

It is not my job here to explain how to implement the code, the basic idea is actually 4 lines of code long (which I leave you here below) but the bulk comes in taking all the desired values.
The two necessary cycles are:

```
for (int i = 1; i < n; i++) 
{
	lis[i] = 1;
	for (int j = 0; j < i; j++)
	{
		if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			lis[i] = lis[j] + 1;
	}
}
```

[WORK IN PROGRESS]
