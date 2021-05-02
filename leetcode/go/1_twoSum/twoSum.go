package leetcode

func twoSum(nums []int, target int) []int {
	numIndexMap := make(map[int]int)
	for i, e := range nums {
		another := target - e
		index, ok := numIndexMap[another]
		if ok {
			return []int{i, index}
		}

		numIndexMap[e] = i
	}

	return nil

}
