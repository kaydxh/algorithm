package leetcode

func lengthOfLongestSubstring(s string) int {
	valueIndexMap := make(map[rune]int)
	maxLen := 0
	start := -1

	for i, v := range s {
		index, ok := valueIndexMap[v]
		if ok {
			if index > start {
				start = index
			}
		}

		valueIndexMap[v] = i
		if i-start > maxLen {
			maxLen = i - start
		}
	}

	return maxLen
}
