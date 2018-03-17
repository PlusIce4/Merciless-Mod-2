/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/

init()
{
	// Override callbacks
	level.mc2_callbackStartGameType = level.callbackStartGameType;
	level.mc2_callbackPlayerConnect = level.callbackPlayerConnect;
	level.mc2_callbackPlayerDisconnect = level.callbackPlayerDisconnect;
	level.mc2_callbackPlayerDamage = level.callbackPlayerDamage;
	level.mc2_callbackPlayerKilled = level.callbackPlayerKilled;

	level.callbackStartGameType = ::Callback_StartGameType;
	level.callbackPlayerConnect = ::Callback_PlayerConnect;
	level.callbackPlayerDisconnect = ::Callback_PlayerDisconnect;
	level.callbackPlayerDamage = ::Callback_PlayerDamage;
	level.callbackPlayerKilled = ::Callback_PlayerKilled;
}

Callback_StartGameType()
{
	_mc2\_player::StartGametype();
	[[level.mc2_callbackStartGameType]]();
}

Callback_PlayerConnect()
{
	self endon("disconnect");
	self _mc2\_player::PlayerConnect();
	[[level.mc2_callbackPlayerConnect]]();
}

Callback_PlayerDisconnect()
{
	self endon("disconnect");
	self _mc2\_player::PlayerDisconnect();
	[[level.mc2_callbackPlayerDisconnect]]();
}

Callback_PlayerDamage(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime)
{
	self endon("disconnect");

	iDamage = self _mc2\_player::PlayerDamage(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime);

	if(iDamage>=0)
	{
	 	[[level.mc2_callbackPlayerDamage]](eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime);
		_mc2\_player::PostPlayerDamage(eInflictor, eAttacker, iDamage, iDFlags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitLoc, psOffsetTime);
	}
	/* OFF TEMP
	// Update healthbar
	if (isdefined(self) && isPlayer(self))
		self mc2\_healthbar::UpdateHealthBar();
	if (isdefined(eAttacker) && isPlayer(eAttacker))
		eAttacker mc2\_healthbar::UpdateHealthBar();
	*/	
}

Callback_PlayerKilled(eInflictor, attacker, iDamage, sMeansOfDeath, sWeapon, vDir, sHitLoc, psOffsetTime, deathAnimDuration)
{
	self endon("disconnect");
	self _mc2\_player::PlayerKilled(eInflictor, attacker, iDamage, sMeansOfDeath, sWeapon, vDir, sHitLoc, psOffsetTime, deathAnimDuration);
	[[level.mc2_callbackPlayerKilled]](eInflictor, attacker, iDamage, sMeansOfDeath, sWeapon, vDir, sHitLoc, psOffsetTime, deathAnimDuration);
}