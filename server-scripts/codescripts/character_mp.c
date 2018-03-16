attachFromArray(a)
{
	self.headmodel = codescripts\character::randomElement(a);
	self attach(self.headmodel, "", true);
}
