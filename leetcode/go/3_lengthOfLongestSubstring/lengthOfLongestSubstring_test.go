package leetcode

import "testing"

func TestLengthOfLongestSubstring(t *testing.T) {
	s := "abcabcbb"
	maxLen := lengthOfLongestSubstring(s)
	t.Logf("maxLen: %v", maxLen)
}
