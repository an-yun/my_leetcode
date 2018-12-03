# Longest Valid Parentheses

## 描述

Given a string containing just the characters `'('` and `')'`, find the length of the longest valid (well-formed) parentheses substring.

**Example 1:**

> **Input:** "(()"
> **Output:** 2
> **Explanation:** The longest valid parentheses substring is "()"

**Example 2:**

> **Input:** ")()())"
> **Output:** 4
> **Explanation:** The longest valid parentheses substring is "()()"

## 分析

### Approach 1: Brute Force

##### Algorithm

In this approach, we consider every possible non-empty even length substring from the given string and check whether it's a valid string of parentheses or not. In order to check the validity, we use the Stack's Method.

Every time we encounter a `‘(’`, we push it onto the stack. For every `‘)’` encountered, we pop a `‘(’` from the stack. If `‘(’`isn't available on the stack for popping at anytime or if stack contains some elements after processing complete substring, the substring of parentheses is invalid. In this way, we repeat the process for every possible substring and we keep on storing the length of the longest valid string found so far.

> Example:
> "((())"
>
> (( --> invalid
> (( --> invalid
> () --> valid, length=2
> )) --> invalid
> ((()--> invalid
> (())--> valid, length=4
> maxlength=4



```java
public class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push('(');
            } else if (!stack.empty() && stack.peek() == '(') {
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.empty();
    }
    public int longestValidParentheses(String s) {
        int maxlen = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 2; j <= s.length(); j+=2) {
                if (isValid(s.substring(i, j))) {
                    maxlen = Math.max(maxlen, j - i);
                }
            }
        }
        return maxlen;
    }
}
```

