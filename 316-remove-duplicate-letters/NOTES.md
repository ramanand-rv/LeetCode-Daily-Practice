First we put character c into our stack and mark it as true
​
Then we come to next character i.e. b we check is b < c to maintain lexicographically order. Yes b is samller then c we'll remove it from the stack.
​
But before removing we have to check that, is c more present in our string. So, how will we quickly check that for that we'll keep one more Array which will keep track of last index of all the character's present in our string
​
So, we see that c exists on 7th index.
​
We'll remove c from the stack & don't forgot to mark c in boolean array from true to false
​
Now add b into our stack. ANd mark b in boolean array as true
​
Now next character is a which is smaller then b & do the same process of checking if it exists somewhere in array & if so, remove it from stack update boolean to false. And put a into the stack. And in boolean array mark it as true.
​
Let's add c in the stack mark it as true & c > a so carry on....
​
Let's add d in the stack mark it as true & d > c so carry on....
​
Now we encounter c which is already visited so, carry on....
​
Let's add b in the stack mark it as true & b < d so carry on....
​
Now we encounter c which is already visited so, carry on....
​
End of the string.