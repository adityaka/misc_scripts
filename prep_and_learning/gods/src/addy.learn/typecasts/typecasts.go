package typecasts

type Base struct {
	field1 string
	field2 int
}

func newBase() *Base {
	return &Base{}
}

func  (b *Base) Field1() string {
	return b.field1
}

func (b *Base) Field2() int {
	return b.field2
}

func (b *Base) SetField1(val string) {
	b.field1 = val
}

func (b *Base) SetField2(val int) {
	b.field2 = val
}

type Derived struct {
	base *Base
	field3 string
	field4 float32
}

func NewDerived() *Derived {
	d  := Derived{base:newBase()}
	return &d
}

func (d *Derived) Field1() string {
	return d.base.Field1()
}

func (d *Derived) Field2() int {
	return d.base.Field2()
}

func (d *Derived) Field3() string {
	return d.field3
}

func (d *Derived) Field4() float32 {
	return d.field4
}

