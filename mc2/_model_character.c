/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Merciless Mod Team */
/* Script Code Snippets: PlusIce */
/* Character Attachment Models */

checkAttachment_head()
{
	self endon("disconnect");
	self endon("TimeToDie");
	self endon("kopp_wech");
	self.curhead = self.headmodel; // Added by bell
	if(!isdefined(self.curhead))return;
	while(1)
	{
		wait .05;
		curhead=self.curhead;
		attachSize_head = self getAttachSize();
		for(i = 0; i < attachSize_head; i++)
		{
			current=self getAttachModelName(i);
			if( current == self.headmodel) 
				curhead = self.headmodel;
			self.curhead=curhead;
		}
	}
}
checkAttachment_hat()
{
	self endon("disconnect");
	self endon("TimeToDie");
	self endon("helm_wech");
	self.curhat = self.hatmodel; // Added by bell
	if(!isdefined(self.curhat))return;
	while(1)
	{
		wait .05;
		curhat=self.curhat;
		attachSize_hat = self getAttachSize();
		for(i = 0; i < attachSize_hat; i++)
		{
			current=self getAttachModelName(i);
			if( current == self.hatmodel) 
				curhat = self.hatmodel;
			self.curhat=curhat;
		}
	}
}
/* Off for now
checkAttachment_arm() //PlusIce: Classes can now have own viewModel for arms and hands
{
	self endon("disconnect");
	self endon("TimeToDie");
	self endon("helm_wech");
	self.curarm = self.armModel;
//	self.armModel = self.viewModel;
	if(!isdefined(self.curarm))return;
	while(1)
	{
		wait .05;
		curarm=self.curarm;
		attachSize_arm = self getAttachSize();
		for(i = 0; i < attachSize_arm; i++)
		{
			current=self getAttachModelName(i);
			if( current == self.armModel) 
				curarm = self.armModel;
			self.curarm=curarm;
		}
	}
}
*/
