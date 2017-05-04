/*************************************************
	MERCILESS MOD 2 V3.5+
	Developed by PlusIce
	Previously developed by Merciless Mod Team
**************************************************/
/* Script Credits: Merciless Mod Team */
/* Script Code Snippets: PlusIce */
/* Utils Character Models */

/*-------------------------------------------
Defines _model_character.gsc
-------------------------------------------*/
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
/*
getViewModel() //test this
{
	if(isdefined(self.viewModel))
		info["viewModel"] = self.viewModel;

	return info;
}
*/
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