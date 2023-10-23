func fitsCapacity(cap int, weights []int, days int) bool {

    s, d := 0, 0

    for i := 0; i < len(weights) && d < days; i++ {

        w := weights[i]

        if s+w <= cap {

            s += w

        } else {

            d++

            s = w

        }

    }
    return d < days
}

func shipWithinDays(weights []int, days int) int {
	i, j := 0, 0

	for _, w := range weights {

		if w > i {

			i = w

		}

		j += w

	}

	for i < j {

		h := int(uint(i+j) >> 1)

		if !fitsCapacity(h, weights, days) {

			i = h + 1

		} else {

			j = h

		}

	}
	return i
}