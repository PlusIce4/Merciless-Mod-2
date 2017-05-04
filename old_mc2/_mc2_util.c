/*-------------------------------------------
 __  __
||\\//|| E R C I L E S S  2
|| \/ || 
--------------------------- 
(www.mercilessmod.com)
----------------------
-------------------------------------------*/
/*-------------------------------------------
Write/Read a file
Mid July 2015
-------------------------------------------*/
write()
{
	//Writing to a file
	f = OpenFile("test.txt", "write"); //int OpenFile(string filename, string readmode) readmode = "read", "write", "append"
	//fprintln(f, "Hello World"+"\n"); //void fprintln (int file, string text) Writes a csv line, ie. "Hello World!,"
	text=("wqeqwd");

	fprintln(f,text);
	closefile(f); //void closefile(int file) Closes the file and clears the buffer. DO NOT forget to do this, can cause errors if you don't!
}
read()
{
	//Reading From a File
	e = OpenFile("test.txt", "read");
	lines = freadln(e); //int freadln(int file) Returns the number of CSV elements in the file - only works the first time on a file, returns -1 afterwords.

	//fgetarg(e, 0); //string fgetarg (int file, int arg) Returns the contents of the CSV element at position arg.
	//An Example:
	//iprintln(lines + " total lines");
	for (i = 0; i < lines; i++)
	{
		a[i] = fgetarg(e, i);
		//iprintlnbold("Line " + i + ": " + a[i]);
		iprintlnbold(a[i]);
	}
	CloseFile(e);
}
/*-------------------------------------------
Model Stuff needed for SP
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
//-
scream(t)
{

	self endon("TimeToDie");
	self.scr = 1;
	if( randomint(100) > 40 || t == "mc" || t == "fc" || t == "p" || t == "h")
	{
		if(t == "f")
			self playsound("nikita_scream");
		else if(t == "m")
			self playsound("mc_scream");
		else if(t == "mc")
			self playsound("mchoke");
		else if(t == "fc")
			self playsound("fchoke");
		else if(t == "p")
			self playsound("puker");
		else if(t == "h")
			self playsound("heave");
		else if(t == "n")
			self playsound("pain");
	}
	else
	{
		self playsound (self.painsound);
	}
	wait 2;
	if(isAlive(self))
		self.scr = undefined;
}
/*-------------------------------------------
MERCILESS2 LOGO 
-------------------------------------------*/
merciless2_logo(shader, scalex, scaley, x, y)
{
	logo = newHudElem();
	logo setShader(shader, scalex, scaley);
	logo.y = y;
	logo.x = x;
	logo.alignX = "right";
	logo.alignY = "top";
	logo.horzAlign = "right";
	logo.vertAlign = "top";
}
/*-------------------------------------------
SPAWN PROTECTION 
-------------------------------------------*/
spawnprotect()
{
	
	self endon ("TimeToDie");
	self endon("killprotection");
	self endon ("killed_player");
	self endon ("disconnect");
	len = getcvarint("scr_spawnprotect_time");
	self.protected = 1;
	if(isdefined(self.protected)&&self.protected==1)
		iDamage=0;
	if(!isDefined(self.sprot))
	{
		self.sprot = newClientHudElem(self);
		self.sprot.x = 320;
		self.sprot.y = 340;
		self.sprot.alignX = "center";
		self.sprot.alignY = "middle";
		self.sprot.label = level._sprottext;
			
	}
	self thread watchWeaponUsage();
	for(i = 0; i < len ;i++)
	{
		self.sprot setvalue(len-i);
		wait 1;
	}
	self.protected = undefined;
	if(isDefined(self.sprot))
		self.sprot destroy();
	//self iprintlnbold("You Are No Longer Protected");
	self notify("killprotection");

}
watchWeaponUsage()
{
	self endon("TimeToDie");
	self endon("killprotection");
	self endon ("killed_player");
	self endon ("disconnect");
	while(isdefined(self)&&self attackButtonPressed())
		wait .05;

	while(isdefined(self)&&!(self attackButtonPressed()))
		wait .05;
	self.protected = undefined;
	if(isDefined(self.sprot))
		self.sprot destroy();

	//self iprintlnbold("You Are No Longer Protected");	
	self notify("killprotection");
}

nozombie()
{
	for(;;)
	{
		wait .05;
		player = getentarray("player", "classname");
		for(i = 0; i < player.size; i++)
		{
			h=player[i].health;	
			if(h<0)
			{
				player[i].suicide=1;
				player[i] suicide();
				break;
			}
		}
	}
}
/*-------------------------------------------
Breath FX for Winter. 
Based on single player missions 
and code from AWE
-------------------------------------------*/
breath()
{
	self endon ("TimeToDie");
	self endon ("killed_player");
	self endon ("disconnect");
	wait (2 + randomint(3));
	while(isdefined(self)&&isalive(self) && self.sessionstate == "playing")
	{
		playfxOnTag ( level._effect["breath"], self, "TAG_EYE" );
		wait randomfloatrange(1.5,3.5);
	}
	
}

/*-------------------------------------------
CLEAN UP THE HUD ELEMENTS WHEN A PLAYER DIES
-------------------------------------------*/
resetHUD()
{
	if (isDefined(self.Painscreen))
		self.Painscreen destroy();
	if (isDefined(self.Painscreen2))
		self.Painscreen2 destroy();
	if (isDefined(self.bloodyscreen))
		self.bloodyscreen destroy();
	if (isDefined(self.bloodyscreen1))
		self.bloodyscreen1 destroy();
	if (isDefined(self.bloodyscreen2))
		self.bloodyscreen2 destroy();		
}
/*-------------------------------------------
CLEAN UP THE HUD ELEMENTS WHEN A PLAYER DIES
-------------------------------------------*/
hud_playerdeath()
{
	if(isDefined(self.mortaricon))
		self.mortaricon destroy();

	if(isDefined(self.mortarcharge))
		self.mortarcharge destroy();

	if(isDefined(self.healicon))
		self.healicon = undefined;
	if(isdefined(self.hitblip))
		self.hitblip destroy();

	if (isDefined(self.Painscreen))
		self.Painscreen destroy();

	if (isDefined(self.Painscreen2))
		self.Painscreen2 destroy();
	if(isDefined(self.hlth))
		self.hlth destroy();
	if(isDefined(self.wpn_back))
		self.wpn_back destroy();
	if(isDefined(self.health_back))
		self.health_back destroy();
	if(isDefined(self.healthicon))
		self.healthicon destroy();
	if(isDefined(self.ammo_clip))
		self.ammo_clip destroy();
	if(isDefined(self.ammo))
		self.ammo destroy();
	if(isDefined(self.slash))
		self.slash destroy();
	if(isDefined(self.sprint_back))
		self.sprint_back destroy();
	if(isDefined(self.sprint_back2))
		self.sprint_back2 destroy();
	if(isDefined(self.sprint_bar))
		self.sprint_bar destroy();
		
	if(isDefined(self.turret_indicator)) 
		self.turret_indicator destroy();

	if(isdefined(self.heatbar))		
		self.heatbar destroy();
	if(isdefined(self.heatbar_back))	
		self.heatbar_back destroy();
	if(isdefined(self.info_text))	
		self.info_text destroy();
}
/*-------------------------------------------
Friendly fire warning if you shoot a teammate
-------------------------------------------*/
DontShoot()
{
	self playsound(self.nationality + "_Hold_Fire");
}
/*-------------------------------------------
Force to Prone
based on code by Matthias Lorenz
-------------------------------------------*/
forceto(a)
{
	if(a=="stand")
	{
		self openmenunomouse("stand");
		wait .05;
		self closeMenu();	
	}
	else if(a=="crouch"||a=="duck")
	{
		self openmenunomouse("crouch");
		wait .05;
		self closeMenu();	
	}
	else
	{

		self openmenunomouse("prone");
		wait .05;
		self closeMenu();
	}
}
/*-------------------------------------------
Check the stance
code by Matthias Lorenz
-------------------------------------------*/
checkStance()
{
	self endon("disconnect");
	self endon("TimeToDie");

	while(1) 
	{	
		wait 0.25;	
		trace 	= bulletTrace( self.origin + ( 20, 0, 60 ), self.origin + ( -20, 0, 60 ), true, undefined );
		trace2 	= bulletTrace( self.origin + ( 20, 0, 40 ), self.origin + ( -20, 0, 40 ), true, undefined );
		stance = 2;
		if(trace["fraction"] == 1) 
			stance = 1;
		if(trace2["fraction"] == 1) 
			stance = 0;
		self.stance = stance;
	}
}

check_adsbutton()
{
	self.key["adsButtonPressed"] = false;
	self endon("disconnect");
	self endon("TimeToDie");
	while(1)
	{
		if(self playerads() < .85)
		{
			self.key["adsButtonPressed"] = false;
		}
		else
		{
			self.key["adsButtonPressed"] = true;
		}
		wait .05;
	}
}
check_usebutton()
{
	self.key["useButtonPressed"] = undefined; //or false
	self endon("disconnect");
	self endon("TimeToDie");	
}
/*-------------------------------------------
End of Merciless Mod 2 Code
-------------------------------------------*/
