func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    if len(nums1) > len(nums2) {
		nums1, nums2 = nums2, nums1
	}


    n1 := len(nums1)
    n2 := len(nums2)

    l := 0
    h := n1

    for l<=h {
        c1 := (l + h)/2

        c2 := (n1 + n2 + 1)/2 - c1

        left1 := math.MinInt64
		if c1 > 0 {
			left1 = nums1[c1-1]
		}

		right1 := math.MaxInt64
		if c1 < n1 {
			right1 = nums1[c1]
		}

		left2 := math.MinInt64
		if c2 > 0 {
			left2 = nums2[c2-1]
		}

		right2 := math.MaxInt64
		if c2 < n2 {
			right2 = nums2[c2]
		}


        if (left1 <= right2) && (left2 <= right1) {
            if (n1 + n2) % 2 == 0 {
                return (float64(max(left1, left2) + min(right1, right2))/ 2.0);
            } else {
                return float64(max((left1), (left2)));
            }
        } else if left1 > right2 {
            h = c1 - 1
        } else {
            l = c1 + 1
        }
    }

    return 0.0
}