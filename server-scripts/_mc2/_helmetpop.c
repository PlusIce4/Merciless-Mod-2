/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/
#include _mc2\_painsounds;
#include _mc2\_bounceobject;

HelmetPlayerDamage(sHitLoc, sMeansOfDeath, self.helm, vPoint, self.curhat, iDamage, "death", org, ch, vDir, model)
{

	if(sHitLoc=="helmet")
	{	
		if ( sMeansOfDeath == "HEADSHOT" )
			{
				
				self notify ("headpop");
				self.helm = 0;
				playfx (level._effect["headpop1"],vPoint);
				self playsound ("splash");	
				self detach(self.curhat,"");
				self [[game["POPHELMET"]]](vPoint,5,vDir,self.curhat,iDamage);
				self thread _doSounds("death",sMeansOfDeath);	
				self thread popHelm(org,ch,vDir,model,iDamage);

				// Iprint to obitsys ???
			
			}
		
	}
}
popHelm(org,ch,vDir,model,iDamage)
{
	
	if(self.helm==1)return;
	self notify("helm_wech");
	if (isDefined (org))
	{
		// If chance is not one, then get random number
		// based on value passed to function	
		if (ch != 1)
		{
			if (randomint(ch) != 1)
			{
				self.helm=0;
				return self.helm;
			}
		}
		if(!isdefined(model))return;
		self detach (model,"");

		rotation = (randomFloat(540), randomFloat(540), randomFloat(540)); 
		offset = (0,0,-6); 
		radius = 6;
		velocity = maps\mp\_utility::vectorScale(vDir, (iDamage/20 + randomFloat(5)) ) + (0,0,(iDamage/20 + randomFloat(5)) ); 
		helmet = spawn("script_model",org); 
		helmet setmodel( model );
		helmet.angles = self.angles;
		helmet thread bounceObject(rotation, velocity, offset, (-90,0,-90), radius, 0.7, undefined, undefined,"helmet",5);
	}
	self.helm=1;
}	