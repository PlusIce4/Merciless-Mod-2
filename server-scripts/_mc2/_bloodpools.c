/**************************************************************************
MERCILESS MOD 2 V3.4+
Developed by PlusIce (current), Merciless Mod Team (previous work)
See credits.txt for complete works cited
**************************************************************************/
PlayerKilled(eInflictor, attacker, iDamage, sMeansOfDeath, sWeapon, vDir, sHitLoc, psOffsetTime, deathAnimDuration)
{
	body linkto( self );

	body = self cloneplayer(deathAnimDuration);
	body.targetname="body";
	wait 0.5;
	
	if(level.scr_bloodpools)
	{
		if(!isdefined(self.burned))
			{
			playfx (level._effect["bloodpools_body"], body.origin);
			}
	}
	
	body hide();
	body unlink();
	body show();
}
bloodpool(a)
{
	playfx(level._effect["bloodpools_body"],a.origin);
}

