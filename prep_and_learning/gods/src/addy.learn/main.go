package main

import (
	"addy.learn/basics"
	courses "addy.learn/courses"
	reportcard "addy.learn/reportcard"
	student "addy.learn/student"
	typecasts "addy.learn/typecasts"
	"fmt"
)

func main(){
	fmt.Println("Output from basics.SampleFunc " , basics.SampleFunction(10))

	o1:= 10.0
	var o2 = 5.0

	fmt.Println("Product ", o1, o2 , " = " ,basics.SimpleMaths(basics.Multiply, 10, 5))
	fmt.Println("Division ", o1, o2 , " = " ,basics.SimpleMaths(basics.Divide, 10, 5))
	fmt.Println("Addition ", o1, o2 , " = " ,basics.SimpleMaths(basics.Add, 10, 5))
	fmt.Println("Subtract ", o1, o2 , " = " ,basics.SimpleMaths(basics.Subtract, 10, 5))
	fmt.Println("Subtract ", o2, o1 , " = " ,basics.SimpleMaths(basics.Subtract, 10, 5))

	// Looper
	basics.LooperOps(10)
	basics.WhileLooper(10)

	// Decisions
	fmt.Println ("I am ", 39, " years old", " I can drink alcohol ", basics.CanIDrinkAlchohol(39))
	fmt.Println ("I am ", 18, " years old", " I can drink alcohol ", basics.WhenCanIDrinkAlchohol(18))
	fmt.Println ("I am ", 39, " years old", " I can drink alcohol ", basics.WhenCanIDrinkAlchohol(39))

	// reportcard shows types encapsulation and

	s := student.NewStudent()
	s.SetName("John", "Limo", "Doe")
	s.SetAge(17)
	s.SetClass(student.XII, student.SectionD)
	report := reportcard.NewReportCard(s)

	report.SetMarksForSubject(courses.Mathematics, 69, 100)
	report.SetMarksForSubject(courses.English, 70, 100)
	report.SetMarksForSubject(courses.ComputerScience, 79, 100)
	report.SetMarksForSubject(courses.Science, 49, 100)
	report.SetMarksForSubject(courses.SocialScience, 55, 100)
	report.SetMarksForSubject(courses.PhyEd, 50, 100)
	report.SetMarksForSubject(courses.ArtsAndDrawing, 33, 100)
	reportMap := report.GetStudentReport()
	for key, val := range reportMap {
		fmt.Println(key, " : " , val)
	}




}

