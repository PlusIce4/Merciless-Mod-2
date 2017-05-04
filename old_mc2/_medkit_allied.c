main()
{				
	if(self.pers["class"]!="medic" || !self.medkitcount)
		return;
		
	if(isDefined(self.isHoldingMedkit))
		return;
		
//	medkit = spawn( "script_model", self.origin ); //remove this line?
//	medkit = spawnstruct();
//	medkit.origin = trace["position"];
//	medkit.angles = orientToNormal(trace["normal"]);
//		return medkit;
	
//------------------------------	
	level.medkitOnGround++;
	startOrigin = self.origin + (0, 0, 10);
    forward = anglesToForward(self getPlayerAngles());
    forward	= maps\mp\_utility::vectorScale(forward, 50);
    endOrigin = startOrigin + forward;    
	angle = int(self.angles[1])+180;
	
	medkit = spawn("script_model", (endOrigin[0],endOrigin[1],self.origin[2]+30));
	medkit setmodel("xmodel/allied_medkit1");
	medkit.angles = (0,angle-180,0);
	medkit.targetname="medkit";
	medkit.owner=self;
//-------------------------------		
	self disableWeapon();
	
	medkit linkto( self );
	
	medkit hide();
	
	self.isHoldingMedkit = true;
	
	self waitForButton();
	
	iprintln(self.name+" ^7dropped Medkit!");
	
	angle = int(self.angles[1])+180;
	currentAngle = (0,angle-180,0);
	ground = medkit getGround(currentAngle);
		
	self enableWeapon();
	
	medkit unlink();
	medkit show();
	
	medkit.origin = self.origin+(0,0,40);
	medkit moveto(ground.origin,.2);
	
	wait 0.2;
	
	medkit.origin = ground.origin;
					
	medkit.icon = newHudElem();
	medkit.icon.x = medkit.origin[0];
	medkit.icon.y = medkit.origin[1];
	medkit.icon.z = medkit.origin[2] + 20;
	medkit.icon.alpha = .75;
	medkit.icon setShader("inak_medkit_icon", 8, 8);
	medkit.icon setwaypoint(false);
					
	self.isHoldingMedkit = undefined;
//	self playSound("ROTU_take_medkit");
	self.medkitcount = 0;
//	self thread maps\mp\gametypes\_gametype::getmedkit();
	self setClientCvar("ui_medkit","^8"+self.medkitcount);
	
	wait 1;
	
	medkit thread giveHealth();
	medkit thread timer();
	return;
}
timer()
{
	self endon("delete_medkit");
	
	time = 60;
	
	for(;;)
	{
		time--;
		
		if(time<=0)
		self thread deletemedkit();
			
		wait 1;
	}
}

giveHealth()
{
	self endon("delete_medkit");
		
	for(;;)
	{
		players = getentarray("player", "classname");
		for(i=0;i<players.size;i++)
		{	
			if(isAlive(players[i]) && distancesquared(players[i].origin,self.origin)<15000) 
			{
				if(players[i].health < players[i].maxhealth)
				{
					if(players[i].health<80)
						players[i].health+=20;
					else
						players[i].health+=int(players[i].maxhealth-players[i].health);
				
//					if(players[i]!=self.owner)
//						self.owner thread maps\mp\gametypes\_gametype::points(50);
					
//					players[i] thread medkitOverlay();
				}
			}
		}
		wait 1;
	}
}

medkitOverlay() //future usage
{
	if(isDefined(self.medkitOverlayHud))
	self.medkitOverlayHud destroy();

	self.medkitOverlayHud = newClientHudElem(self);
	self.medkitOverlayHud.horzAlign = "fullscreen";
	self.medkitOverlayHud.vertAlign = "fullscreen";
	self.medkitOverlayHud.x = 0;
	self.medkitOverlayHud.y = 0;
	self.medkitOverlayHud.color = (0,1,0);
	self.medkitOverlayHud setShader("white", 640,480);
	self.medkitOverlayHud.alpha = 0.25;
	self.medkitOverlayHud fadeOverTime(0.5);
	self.medkitOverlayHud.alpha = 0;
	wait 0.6;
	self.medkitOverlayHud destroy();
}

deleteMedkit()
{
	self notify("delete_medkit");
	self.icon destroy();
	self delete();
	level.medkitOnGround--;
}

waitForButton() //future usage
{
	self endon("disconnect");
	self endon("killed_player");
	self endon("place_medkit");
	
	buttonPressed = false;
	
	wait .2;
	
	while(1)
	{
		wait .1;
		while(self attackButtonPressed())
		{	
			wait .1;
			self notify("place_medkit");
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