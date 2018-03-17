/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/

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
model()
{
	self detachAll();
	
	if(self.pers["team"] == "allies")
		[[game["allies_model"] ]]();
	else if(self.pers["team"] == "axis")
		[[game["axis_model"] ]]();

	self.pers["savedmodel"] = saveModel();
}
saveModel()
{
	info["model"] = self.model;
	info["viewmodel"] = self getViewModel();
	
	if(isdefined(self.headModel))
		info["headModel"] = self.headModel;
	if(isdefined(self.hatModel))
		info["hatmodel"] = self.hatModel;
	attachSize = self getAttachSize();
	info["attach"] = [];
	
	for(i = 0; i < attachSize; i++)
	{
		info["attach"][i]["model"] = self getAttachModelName(i);
		info["attach"][i]["tag"] = self getAttachTagName(i);
		info["attach"][i]["ignoreCollision"] = self getAttachIgnoreCollision(i);
	}
	
	return info;
}
loadModel(info)
{
	self detachAll();
	self setModel(info["model"]);
	self setViewModel(info["viewmodel"]);

	if(isdefined(info["headModel"]))
		self.headModel = info["headModel"];
	if(isdefined(info["hatModel"]))
		self.hatModel = info["hatModel"];
	attachInfo = info["attach"];
	attachSize = attachInfo.size;
    
	for(i = 0; i < attachSize; i++)
		self attach(attachInfo[i]["model"], attachInfo[i]["tag"], attachInfo[i]["ignoreCollision"]);
}