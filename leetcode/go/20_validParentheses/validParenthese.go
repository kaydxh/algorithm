package main

import (
	"fmt"
)

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true


Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

func isValid(s string) bool {
	stacks := []byte{}
	brackets := map[byte]byte{
		')': '(',
		']': '[',
		'}': '{',
	}

	for i := range s {
		if _, ok := brackets[s[i]]; !ok {
			stacks = append(stacks, s[i])
		} else {
			if len(stacks) > 0 && brackets[s[i]] == stacks[len(stacks)-1] {
				stacks = stacks[:len(stacks)-1]
			} else {
				return false
			}
		}
	}

	return true
}

func main() {
	s := "()[]{}"
	valid := isValid(s)
	fmt.Println(valid)
}
