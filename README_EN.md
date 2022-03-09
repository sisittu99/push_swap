### #42_tutorial: PUSH_SWAP
### L.I.S. algorithm (vers. 02/22)
grade: 125/100

# 🇬🇧🇺🇸

Given the lack of solutions of the project through the use of the **Longest Increasing Suqsequence algorithms**, I decided to write this README to help all those students who do not have figured out how to implement it.

1. [The subject](https://github.com/sisittu99/push_swap/blob/master/README_EN.md#the-subject)
2. [Moves](https://github.com/sisittu99/push_swap/blob/master/README_EN.md#moves)
3. [The L.I.S. algorithm](https://github.com/sisittu99/push_swap/blob/master/README_EN.md#the-lis-algorithm)
4. [Sorting and optimization](https://github.com/sisittu99/push_swap/blob/master/README_EN.md#sorting-and-optimization)
- [Moves calculation](https://github.com/sisittu99/push_swap/blob/master/README_EN.md#moves-calculation)
- [Choosing the best number](https://github.com/sisittu99/push_swap/blob/master/README_EN.md#choosing-the-best-number)
5. [Code conclusion](https://github.com/sisittu99/push_swap/blob/master/README_EN.md#code-conclusion)
 	

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

We now come to the real trouble of this project: **the number of possible moves.**
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
To help you make out the algorithm, I give you [the link of GeeksForGeeks](https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/ "Watch the videos!") which helped us understand the logic behind it. Be careful: they only return the maximum size of the subsequence...

Once you have found the ordered sequence, all that remains is to keep it on _stack_a_ and to bring all the other numbers to _stack_b_.

At the end of the work you will see a similar structure:

<img width="769" alt="Screen Shot 2022-02-28 at 11 53 26" src="https://user-images.githubusercontent.com/92301111/155971088-9a4ea247-8a76-4d11-958c-4bca2424fef5.png">

> Haven't I told you about the visualizer yet? [It will be very useful at the end of writing the code ...](https://github.com/o-reo/push_swap_visualizer)

# Sorting and optimization

In the previous steps I have not stated why we start the project by calculating the LIS. In case you haven't figured it out, the goal is to put all the other numbers in an already ordered stack, albeit not complete! In fact, this allows us to make exchanges between _stack_a_ and _stack_b_ only once and immediately return the right order.

Now there can be only one way to move the numbers: move the first number of the _stack_b_ in front of the successively greater number of the _stack_a_, which must necessarily be placed in first position. However, we have a non-trivial problem: always inserting the first number of the _stack_b_ in the _stack_a_ causes the latter to spin too many times, exponentially increasing the moves.
> Suffice it to say, the simplest algorithm far exceeds 100,000 moves with 500 numbers...
So, how to optimize?

Our solution we propose here is very much at risk of TLE (lit. _Time Limit Exceeded_). We are aware there are faster and less risky solutions, but we also are extremely sure that on a theoretical-practical level it works and that it allows one of the best optimizations on all possible ones.
But first, maybe it's better to take a break, shall we?

![gerry scotti caffè borbone](https://user-images.githubusercontent.com/92301111/157418321-9fbdbced-83e1-4565-8a45-ed56c204daa3.jpeg)
## Moves calculation

If you are envisioning about fifteen functions to write after this title, you have probably underestimated the work you still have to face.

There's nothing to say here, you must calculate for each number how many moves you need to do. We reasoned this way:

1. Create two support arrays (`mov_a` and `mov_b` can be fine!). Both must have dimension `size_b`: in fact the numbers to be saved refer only to the numbers in _stack_b_. Let me explain worse: since our goal is to bring all the numbers of _b_ into the _a_, we need to calculate how many moves we have to do both to move the number of _b_ to the first position, and to move the _stack_a_ so that we can correctly insert the number of _b_. Therefore, _not only_ to each number of b corresponds a number of moves to arrive in first position and then apply `pa`, _but also_ a number of moves to put the correct number of _a_ in first position, such that _stack_a_ remains ordered with the insertion of the number of _b_.
2. We then begin to do our calculations: take the _stack_b_ and **calculate the distance** of each number from the first position. Trivially, depending on whether they are above or below the `size_b / 2` position, we will use `rb` or `rrb` moves. The assigned value will be positive if `rb` is to be used, else negative for `rrb` or 0 for no moves.
3. in _stack_a_ the number _immediately greater_ than the one taken into consideration in _stack_b_ is found. Help yourself with the assumption that ** the _stack_a_ is already sorted! ** Find the pair for which `mov_a[i] < mov_b[j] < mov_a[i + 1]` and put `mov_a[i + 1]` in first position. 
> Example: if we have to insert a `5` in a _stack_a_ equal to `3 - 8 - 19 - 25`, number `8` will go to the first position. That's what I previously called `mov_a[i + 1]`.
4. compute the same value as in step 2, but concerning `mov_a[i + 1]`.

Here is a more complex pragmatic example, taken from a real simulation where I had 7 numbers on _stack_b_ and more than 12 numbers on _stack_a_:
```
MOV_A   MOV_B
4       0
-5      1
3       2
-1      3
0       -3
4       -2
-5      -1
```
Column B indicates the distance of each number of _stack_b_, while column A indicates the distance of the number of _stack_a_ immediately greater than its corresponding in _b_, the now famous `mov_a[i + 1]`. Let's see now how to get to the practical part of the code!

## Choosing the best number

Ok, we know all the moves for every number we have in stack_b. But which one do we take?
The answer depends on the case studies, according to the direction of rotation of the vector:
```
	|	mov_b +		|	mov_b -
--------|-----------------------|-----------------------
mov_a +	|   max(mov_a, mov_b)	|   mov_a + |mov_b|
--------|-----------------------|-----------------------
mov_a -	|  |mov_a| + mov_b	|  |min(mov_a, mov_b)|
```
> I assume you remember the absolute value...

In all four cases, the released value is the total count of moves you have to do before `pa`!

But first it must be emphasized why, in case of same sign, it is necessary to take the maximum or minimum of the two values. If we want to optimize the code we must necessarily take advantage of `rr` and `rrr` moves, which rotate both stacks with a single output line. It goes without saying, dividing the moves by 2 is a time-saver we cannot miss...

Thus, taking the example from the section above, `4   0` becomes less convenient than `3   2`, as 4 moves are made for the former while 3 moves for the latter.

Obviously all these calculations have to be repeated `size_b` times!


# Code conclusion

Once you have done all the possible `pa` moves, you should find yourself in a similar situation where the vector is ordered but does not start in the right position:

<img width="773" alt="Screen Shot 2022-02-28 at 14 45 02" src="https://user-images.githubusercontent.com/92301111/155993619-4d3da32d-d4fe-458d-9d80-c39f8e6c8e9e.png">

Remember to minimize the moves here as well, or you'll risk missing out on a few hundred moves in the last part.

***

Our project is now complete! Let me know if you have any problems or suggestions or translation/grammatical/semantic tips, I'll be happy to discuss them with you on Slack (@mcerchi) or [via mail](mailto:mcerchi@student.42roma.it).
