package student


type Section int
const (
	SectionA = iota + 1
	SectionB
	SectionC
	SectionD
	SectionE
	SectionF
)

func (s Section) GetSectionName() string {
	switch s {
	case SectionA: {return "A"}
	case SectionB: {return "B"}
	case SectionC: {return "C"}
	case SectionD: {return "D"}
	case SectionE: {return "E"}
	case SectionF: {return "F"}
	}
	return ""
}

type Class int
const (
	I    = iota + 1
	II
	III
	IV
	V
	VI
	VII
	VIII
	IX
	X
	XI
	XII
)

func (c Class) GetClassName() string {
	switch c {
	case I: {return "1"}
	case II: {return "2"}
	case III: {return "3"}
	case IV: {return "4"}
	case V: {return "5"}
	case VI: {return "6"}
	case VII: {return "7"}
	case VIII: {return "8"}
	case IX: {return "9"}
	case X: {return "10"}
	case XI: {return "11"}
	case XII: {return "12"}
	}
	return ""
}
