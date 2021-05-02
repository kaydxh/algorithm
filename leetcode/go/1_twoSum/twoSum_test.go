package leetcode

import "testing"

func TestTwoSum(t *testing.T) {
	nums := []int{2, 7, 11, 15}
	target := 9
	indexs := twoSum(nums, target)

	t.Logf("indexs: %v", indexs)

}
