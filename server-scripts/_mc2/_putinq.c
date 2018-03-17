/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/

putinQ(type)
{
	index = level.awe_objectQcurrent[type];

	level.awe_objectQcurrent[type]++;
	if(level.awe_objectQcurrent[type] >= level.awe_objectQsize[type])
		level.awe_objectQcurrent[type] = 0;

	if(isDefined(level.awe_objectQ[type][index]))
	{
		level.awe_objectQ[type][index] notify("awe_bounceobject");
		level.awe_objectQ[type][index] notify("awe_healthpack");
		wait .05; //Let thread die
		if(isDefined(level.awe_objectQ[type][index].anchor))
		{
			level.awe_objectQ[type][index] unlink();
			level.awe_objectQ[type][index].anchor delete();
		}
		level.awe_objectQ[type][index] delete();
	}
	
	level.awe_objectQ[type][index] = self;
}