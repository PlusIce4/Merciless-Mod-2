main()
{				
	if(self.pers["pClass"]!="support" || !self.ammoboxcount)
		return;
		
	if(isDefined(self.isHoldingAmmo))
		return;

	level.ammoOnGround++;
		
	startOrigin = self.origin+(0,0,3);
    forward = anglesToForward(self getPlayerAngles());
    forward	= maps\mp\_utility::vectorScale(forward, 50);
    endOrigin = startOrigin + forward;    
	
	angle = int(self.angles[1])+180;
	
	ammobox = spawn("script_model", (endOrigin[0],endOrigin[1],self.origin[2]+30));
	ammobox setmodel ("xmodel/axis_ammobox1");
	ammobox.angles = (0,angle-180,0);
	ammobox.targetname="ammo";
	ammobox.owner=self;
		
	self disableWeapon();
	
	ammobox linkto( self );
	
	ammobox hide();
	
	self.isHoldingAmmo = true;
	
	self waitForButton();
	
	iprintln(self.name+" ^7dropped Ammobox!");
	
	angle = int(self.angles[1])+180;
	currentAngle = (0,angle-180,0);
	ground = ammobox getGround(currentAngle);
		
	self enableWeapon();
	
	ammobox unlink();
	ammobox show();
	
	ammobox.origin = self.origin+(0,0,40);
	ammobox moveto(ground.origin,.2);
	
	wait 0.2;
	
	ammobox.origin = ground.origin;
					
//	ammobox.icon = newHudElem();
//	ammobox.icon.x = ammobox.origin[0];
//	ammobox.icon.y = ammobox.origin[1];
//	ammobox.icon.z = ammobox.origin[2] + 20;
//	ammobox.icon.alpha = .75;
//	ammobox.icon setShader("inak_ammobox_icon", 8, 8);
//	ammobox.icon setwaypoint(false);
					
	self.isHoldingAmmo = undefined;
//	self playSound("ROTU_take_ammo");
	self.ammoboxcount = 0;
//	self thread maps\mp\gametypes\_gametype::getammobox();
	self setClientCvar("ui_ammobox","^8"+self.ammoboxcount);
	
	wait 1;
	
	ammobox thread giveAmmo();
	ammobox thread timer();
}
timer()
{
	self endon("delete_ammo");
	
	time = 20;
	
	for(;;)
	{
		time--;
		
		if(time<=0)
		self thread deleteAmmo();
			
		wait 1;
	}
}

giveAmmo()
{
	if(isdefined(self.pers["team"]) && self.pers["team"] != "axis")
		return;

	self endon("delete_ammo");
		
	for(;;)
	{
		players = getentarray("player", "classname");
		for(i=0;i<players.size;i++)
		{	
			if(isAlive(players[i]) && distancesquared(players[i].origin,self.origin)<15000)
			{
				a1=players[i] getWeaponSlotAmmo("primary");
				a2=players[i] getWeaponSlotAmmo("primaryb");
				
				players[i] givemaxammo(players[i] getWeaponSlotWeapon("primary"));
				players[i] givemaxammo(players[i] getWeaponSlotWeapon("primaryb"));
					
				primaryammo=int(players[i] getWeaponSlotAmmo("primary")/20);
				primarybammo=int(players[i] getWeaponSlotAmmo("primaryb")/20);
					
				if(primaryammo>0||primarybammo>=0)
				{
					players[i] setWeaponSlotAmmo("primary", a1 + primaryammo);
					players[i] setWeaponSlotAmmo("primaryb", a2 + primaryammo);
				}
				else
				{
					players[i] setWeaponSlotAmmo("primary", a1 + 1);
					players[i] setWeaponSlotAmmo("primaryb", a2 + 1);
				}
					
				if(a1!=players[i] getWeaponSlotAmmo("primary") || a2!=players[i] getWeaponSlotAmmo("primaryb")) 
				{
//					if(players[i]!=self.owner)
//						self.owner thread maps\mp\gametypes\_gametype::points(50);
						
					players[i] playlocalsound("weap_pickup");
					players[i] thread ammoOverlay();
				}
			}
		}
		wait 1;
	}
}

ammoOverlay()
{
	if(isDefined(self.ammoOverlayHud))
	self.ammoOverlayHud destroy();

	self.ammoOverlayHud = newClientHudElem(self);
	self.ammoOverlayHud.horzAlign = "fullscreen";
	self.ammoOverlayHud.vertAlign = "fullscreen";
	self.ammoOverlayHud.x = 0;
	self.ammoOverlayHud.y = 0;
	self.ammoOverlayHud.color = (0,0,1);
	self.ammoOverlayHud setShader("white", 640,480);
	self.ammoOverlayHud.alpha = 0.25;
	self.ammoOverlayHud fadeOverTime(0.5);
	self.ammoOverlayHud.alpha = 0;
	wait 0.6;
	self.ammoOverlayHud destroy();
}

deleteAmmo()
{
	self notify("delete_ammo");
	self.icon destroy();
	self delete();
	level.ammoOnGround--;
}

waitForButton()
{
	self endon("disconnect");
	self endon("killed_player");
	self endon("place_ammo");
	
	buttonPressed = false;
	
	wait .2;
	
	while(1)
	{
		wait .1;
		while(self attackButtonPressed())
		{	
			wait .1;
			self notify("place_ammo");
		}
	}
}

getGround(currentAngle)
{
	start = self.origin + (0, 0, 20);

	range = 1;
	forward = anglesToForward(currentAngle);
	forward = maps\mp\_utility::vectorScale(forward, range);

	traceorigins[0] = start + forward;
	traceorigins[1] = start;

	trace = bulletTrace(traceorigins[0], (traceorigins[0] + (0, 0, -28)), false, undefined);
	if(trace["fraction"] < 1)
	{	
		temp = spawnstruct();
		temp.origin = trace["position"];
		return temp;
	}

	trace = bulletTrace(traceorigins[1], (traceorigins[1] + (0, 0, -28)), false, undefined);
	if(trace["fraction"] < 1)
	{
		temp = spawnstruct();
		temp.origin = trace["position"];
		return temp;
	}

	traceorigins[2] = start + (26, 26, 0);
	traceorigins[3] = start + (26, -26, 0);
	traceorigins[4] = start + (-26, -26, 0);
	traceorigins[5] = start + (-26, 26, 0);

	besttracefraction = undefined;
	besttraceposition = undefined;
	for(i = 0; i < traceorigins.size; i++)
	{
		trace = bulletTrace(traceorigins[i], (traceorigins[i] + (0, 0, -1000)), false, undefined);

		if(!isdefined(besttracefraction) || (trace["fraction"] < besttracefraction))
		{
			besttracefraction = trace["fraction"];
			besttraceposition = trace["position"];
		}
	}
	
	if(besttracefraction == 1)
		besttraceposition = self.origin;
	
	temp = spawnstruct();
	temp.origin = besttraceposition;
	return temp;
}