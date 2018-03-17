/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/

iprintlnFIXED (locstring, player, target)
{

	if (isdefined (target))
		target iprintln (locstring, player);
	else
		iprintln (locstring, player);
}

iprintlnboldFIXED (locstring, player, target)
{

	if (isdefined (target))
		target iprintlnbold (locstring, player);
	else
		iprintlnbold (locstring, player);
}