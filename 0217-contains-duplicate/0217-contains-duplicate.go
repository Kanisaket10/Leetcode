
func containsDuplicate(nums []int) bool {
    // sort.Ints(nums)

    // for i:=0; i<len(nums)-1; i++ {
    //     if nums[i] == nums[i+1]{
    //         return true
    //     }
    // }
    // return false

//Optimized
    seen := make(map[int]bool)

    for _, num := range nums {
        if seen[num] {
            return true
        }
        seen[num] = true
    }

    return false
}