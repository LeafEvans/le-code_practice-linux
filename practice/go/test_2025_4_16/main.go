package main

import "fmt"

func quickSort(arr []int) []int {
	if len(arr) < 2 {
		return arr
	}
	pivot := arr[0]
	less := []int{}
	greater := []int{}
	for _, v := range arr[1:] {
		if v <= pivot {
			less = append(less, v)
		} else {
			greater = append(greater, v)
		}
	}
	return append(append(quickSort(less), pivot), quickSort(greater)...)
}

func main() {
	arr := []int{5, 3, 8, 4, 2, 7, 1, 6}
	sorted := quickSort(arr)
	fmt.Println(sorted)
}
