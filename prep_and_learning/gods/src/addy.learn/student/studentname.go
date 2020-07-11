package student

import "strings"

type Name struct {
	first string
	middle string
	last string
}

func NewName(first string, middle string, last string) *Name {
	return &Name{first: first, middle:middle, last:last}
}

type NameOrder int
const (
	NameOrderFirstMiddleLast = iota
	NameOrderLastFirstMiddle
	NameOrderLastMiddleFirst
)

func (n Name) GetFullName (order NameOrder, sep string) string {
	var allNames []string = make([]string, 1, 3)
	switch(order) {

	case NameOrderLastFirstMiddle: {
		allNames = append(allNames, n.last, n.first, n.middle)
		break
	}
	case NameOrderFirstMiddleLast:
		fallthrough
	default:{
		allNames = append(allNames, n.first, n.middle, n.last)
	}

	}
	return strings.Join(allNames,sep)

}