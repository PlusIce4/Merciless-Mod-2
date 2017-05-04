/*-------------------------------------------
 __  __
||\\//|| E R C I L E S S  2
|| \/ || 
--------------------------- 
(www.mercilessmod.com)
----------------------
models
Marked unneeded stuff for elimination
-------------------------------------------*/
/*
ein anfang...später klassenspezifiert
de: 3
us: 6
uk: 6
ru: 6 und 2(female)
*/
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
do_dmg_skins() //leaving alone for now
{
	hlth = self.health;
	if(hlth>=85||hlth<1)return;
	if(hlth<85&&hlth>50)return;
}