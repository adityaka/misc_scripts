package student

type Student struct {
	rollNumber int
	name       Name
	age        int
	class      Class
	section    Section

}

func NewStudent() *Student {
	return &Student{}
}

func (r *Student) SetName(fname string, mname string, lname string) {
	if len(fname) != 0  && len(lname) != 0 {
		r.name = Name{first: fname, middle: mname, last:lname}
	} else {
		panic("Student First and Last name can't be 0 length")
	}
}

func (s *Student) SetAge(age int) {
	if age > 3 {
		s.age = age
	} else {
		panic ("Legal age for school is greater than 3 years")
	}
}

func (s *Student) SetClass(class Class, section Section) {
	s.class = class
	s.section = section
}

func (s Student) GetName() string {
	return s.name.GetFullName(NameOrderFirstMiddleLast, " ")
}

func (s Student) GetAge() int {
	return s.age
}

func (s Student) GetClassAndSection() string {
	return s.class.GetClassName() + "-" + s.section.GetSectionName()
}

