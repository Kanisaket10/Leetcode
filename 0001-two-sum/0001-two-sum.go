func twoSum(nums []int, target int) []int {

  // brute force 
   // n := len(nums)
    // for i := 0; i < n; i++ {
    //     for j := i+1; j < n; j++{
    //         if nums[i] + nums[j] == target{
    //             return []int{i, j}
    //         }    
    //     }
    // }
    // return []int{}

    // optimize solution
    
    store := make(map[int]int)
    
    for idx, num := range nums{
        complement := target - num
        if otherIdx, exists := store[complement]; exists{
            return []int{otherIdx, idx}
        }
        store[num] = idx
    }

    return []int{}
}

