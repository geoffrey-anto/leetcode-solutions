func check(nums []int) bool {
    if len(nums) == 1{
        return true;
    }
    
    left := nums[0];
    right := nums[len(nums) - 1];
    
    c := 0;
    
    for i:=0; i<len(nums) - 1; i++ {
        if nums[i] <= nums[i+1] {
            c++;
        }
    }

    if (c == len(nums)-2) && (left >= right) {
        return true;
    } else if( c==len(nums)-1) {
        return true;
    }
    
    return false;
}