package main

import (
	"fmt"
	"sort"
)

func threeSum(nums []int) [][]int {
	result := make([][]int, 0)
	sort.Ints(nums)
	for i := 0; i < len(nums); i++ {
		low := i + 1
		high := len(nums) - 1
		for low < high {
			low_num := nums[low]
			high_num := nums[high]
			if nums[i]+nums[low]+nums[high] == 0 {
				elems := make([]int, 0)
				elems = append(elems, nums[i], nums[low], nums[high])
				result = append(result, elems)
				for low < high && nums[low] == low_num {
					low++
				}
				for low < high && nums[high] == high_num {
					high--
				}
			} else if nums[i]+nums[low]+nums[high] < 0 {
				low++
			} else {
				high--
			}
		}

		for i+1 < len(nums) && nums[i] == nums[i+1] {
			i++
		}
	}
	return result
}

func main() {
	fmt.Println("vim-go")
	nums := []int{-1, -0, 1, 2, -1, -4}
	result := threeSum(nums)
	fmt.Println(result)
}
