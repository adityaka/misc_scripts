package reportcard

import (
	courses "addy.learn/courses"
	student "addy.learn/student"
	"fmt"
	"strconv"
)

type ReportCard struct {
	marks []courses.SubjectMarks
	student *student.Student
	averagePercentage float32
}

func NewReportCard(student *student.Student) *ReportCard {
	return &ReportCard{student: student, marks: make([]courses.SubjectMarks, 1, courses.MaxSubjects)}
}

func (r *ReportCard) SetMarksForSubject(subject courses.Subject, marks float32, maxMarks float32) {
	for index, val := range r.marks{
		if val.GetSubject() == subject{
			r.marks[index].SetMarks(subject, marks, maxMarks)
			return
		}
	}
	r.marks = append(r.marks, *courses.NewSubjectMarks(subject, marks, maxMarks))
}

func (r ReportCard) GetStudentAverage () float32{
	if r.averagePercentage == 0.0  {
		for _, val := range r.marks {
			r.averagePercentage +=  val.GetPercentage()
		}
		r.averagePercentage /= float32(len(r.marks))
	}

	return r.averagePercentage
}

func (r ReportCard) GetStudentReport() map[string] string {
	report := make(map[string] string)
	report["Name"] = r.student.GetName()
	report["Age"] = strconv.Itoa(r.student.GetAge())
	report["Class"] = r.student.GetClassAndSection()
	report["AveragePercentage"] = fmt.Sprintf("%f", r.GetStudentAverage())
	for _, val := range r.marks {
		report[val.GetSubject().GetName()] = fmt.Sprintf("%f Percent", val.GetPercentage())
	}
	return report
}




