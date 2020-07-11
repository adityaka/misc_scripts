package courses

type SubjectMarks struct {
	subject  Subject
	maxMarks float32
	marks    float32
}

type Subject int
const(
	Mathematics = iota
	English
	ComputerScience
	Science
	SocialScience
	PhyEd
	ArtsAndDrawing
)
const MaxSubjects int = 7

func (s *SubjectMarks) SetMarks(subject Subject, marks float32, maxMarks float32) {
	s.subject = subject
	if marks > maxMarks {
		panic("max marks can't be less than marks")
	}
	s.marks = marks
	s.maxMarks = maxMarks
}

func (s SubjectMarks) GetPercentage() float32 {
	var percentage float32 = 0.0
	if s.maxMarks == 100 {
		percentage =  s.marks
	} else if s.maxMarks > 0 {
		percentage = (s.marks/s.maxMarks)*100
	} else {
		percentage = 0.0
	}
	return percentage
}

func NewSubjectMarks(subject  Subject, marks float32, maxMarks float32  ) *SubjectMarks {
	s := SubjectMarks{maxMarks: maxMarks, marks: marks, subject: subject}
	return &s
}
func (s SubjectMarks) GetSubjectReport() (Subject, float32) {
	return s.subject , s.GetPercentage()
}

func (s SubjectMarks) GetSubject() Subject {
	return s.subject
}

func (s Subject) GetName() string {
	switch s {
	case Mathematics: {return "Mathematics"}
	case English: {return "English"}
	case Science: {return "Science"}
	case ComputerScience: {return "Computer Science"}
	case SocialScience: {return "Social Science"}
	case ArtsAndDrawing: { return "Arts and Drawing"}
	case PhyEd: {return "Physical Education"}
	default: { panic("Unknown Subject") }
	}
}
