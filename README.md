# Computing-Arithmetic-Expression
Computing Arithmetic Expression in Polish Notation in C++. Did this by using an expression tree (a binary tree in which each internal node corresponds to operator and each leaf node corresponds to operand).

## Introduction 
The purpose of this algorithm is to compute the value of a mathematical expression read from a file using an expression tree. An expression tree is a binary tree in which each internal node corresponds to operator and each leaf node
corresponds to operand.
## The Algorithmic Part
After days of reading and studying solutions for this problem, I chose to work
by the following idea: I took the expression in reverse order and, using a stack,
we apply this rule for every character:
- If character is operand, push that into stack
- If character is operator pop two values from stack make them its child and
push current node again
At the end only element of stack will be root of expression tree.
## The Implementation
It took me more time to start implementing. I think I spent around 4-5 days to think about how should I start. I wanted to have a very clear view about what I was going to do because I think
that this way, I do not get lost in tons of code lines and freak out. I wrote this code in 2 days: one was spent doing the Expression class and the other one was for doing the ExpressionTree.
### Day 1
Initially, I was not going to do the class Expression, but after I saw how long was the code and complicated for only a verification (whether the expression read from the file was correctly built or not), I chose to form this class in order to simplify the view. This contains the full expression and its length, verify expression method, get length method and position.
get length method is easy, it just returns the length of the expression. position method returns the character on the position i. verify expression method verifies whether the expression is correctly built.
The algorithm is very simple: using a stack, every time we get to an open parenthesis, we put that into the stack and move further. We do the same when we
get to numbers and operators. When we get to a closed parenthesis, we check whether the last elements respect the order of a prefix Polish notation. If yes, we pop up from the stack these elements and push back a number. If not, this
means it is an incorrectly built expression and return 0. If we end up with only a number in the stack, that mean that the expression is correctly built.
### Day 2
I think I worked all day this day. I made the class ExpressionTree which forms
the actual tree of the expression. Here I have more methods that I want to
explain:
- FormTree takes as a parameter a variable of type Expression. This does
exactly what I explained earlier with the stack part, in the algorithmic part.
- Inorder and DisplayInorder are practically together. Inorder is a recursive
function that displays the node and get to the other two (obviously, in inorder
order). DisplayInorder calls the Inorder method with the parameter the head
of the tree.
- Result and Solve are again together. Solve method solves recursively the
expression. It returns the number if the node!val is a number, else it calculates
the sum/difference/... between the result of left and right (it depends what
operator there is in !val). Result return Solve of the head of the tree.
I want to add that I chose to do these last 4 methods this way because I found
it more clearer in my head. Also, the data is private and cannot be used outside
of the class.
I also made two additional functions that I think were very helpful. I am talking
about SwapString and FormNumber. SwapString reverses a string. I needed this
because I took the expression in reverse order and I needed to turn around the
numbers in order to compute the expression correctly. FormNumber transforms
a string into a number.
## Encountered Problems
### Forming the Expression Tree
I read tons of articles and books about the algorithm before choosing this one. I found it more simpler than the recursive idea I found on the internet. I do not know why, but this one was clearer in my head. To be honest, I only found
articles that transformed form the post fix Polish notation and I adapted myself to this project. I encountered tons of problem until I got to the final form of
the code, like different kinds of infinite loops and problems with the memory and pointers used and all sort of things like that.
### Numbers with more than one digit
I solved this quicker than I expected when I chose to use the string class in C++. It solved all the problems and was easy to use it like that. Using the char
type, it just complicated things (because characters are always complicated to
deal with in my opinion, you never know what they are up to).
## Examples of Expressions
I computed the sample you gave us and it gave me the result 14.
 I also tried simple expressions like (operator number number) when first trying out my program. It works fine.
I also tried more complicated expressions, like (+ (- 3 4) (* (- 5 6)(* 6 7 ))) and
it gave me the correct answer - 43.
My program also computes correctly expressions that contain numbers formed
from more than one digit. For example, (+ 43 50) it gives the output 93.
