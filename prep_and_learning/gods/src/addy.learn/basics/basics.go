package basics

import (
	"fmt"
	"math"
	"strconv"
)

// basic type declarations

// enums
type MathOp int
const  (
		Add = iota
		Subtract
		Multiply
		Divide
		Mod
	)

// basic function definition
func SampleFunction(intArg int) int{
	return 100
}

func SimpleMaths(operation MathOp, op1 float64, op2 float64  ) float64 {
	switch operation {
	case Add: { return op1+op2 }
	case Subtract: { return math.Abs(op1 - op2) }
	case Multiply: { return op1 * op2 }
	case Divide: { return op1/op2 }
	default:
		panic("ooh ooh don't know what to do here!!!")
	}
}

func LooperOps( maxIter int ){
	fmt.Println("Looper is gona go for ", maxIter, "iterations")
	for i:=0; i < maxIter; i++{
		fmt.Print(i, " ")
	}
	fmt.Println()
}

func WhileLooper(maxIter int) {
	fmt.Println("Looper is gona go for ", maxIter, "iterations")

	var i int = maxIter
	for i > 0  {
		fmt.Print(i, " ")
		i--
	}
	fmt.Println()
}

const legalAgeForDrinking = 21
func CanIDrinkAlchohol(age int) bool {
	if age < legalAgeForDrinking {
		return false
	}
	return true
}

func WhenCanIDrinkAlchohol(age int) string {
	if !CanIDrinkAlchohol(age){
		return "in " + strconv.Itoa(legalAgeForDrinking- age) + " years"
	}

	return "now"
}
