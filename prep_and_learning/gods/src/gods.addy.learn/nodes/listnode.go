package nodes

type genericNode struct {
	links []*genericNode
	data interface{}
}

func newGenericNode() *genericNode {
	return &genericNode{}
}

func (g *genericNode) SetLink(link *genericNode, idx int) {
	g.links[idx] = link
}

func (g *genericNode) Link(idx int) *genericNode{
	return g.links[idx]
}

func (g *genericNode) Data() interface{} {
	return g.data
}

func (g *genericNode) SetData(d interface{}) {
	if d != nil {
		g.data = d
	}
}





