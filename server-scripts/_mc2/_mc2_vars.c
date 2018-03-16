/*-------------------------------------------
 __  __
||\\//|| E R C I L E S S  2
|| \/ || 
--------------------------- 
(www.mercilessmod.com)
----------------------
Initialize the cvars used by Merciless
-------------------------------------------*/
initialize_cvars()
{
	if (getcvar("hud_fade_compass") != "0")
		setcvar("hud_fade_compass", "0");
	if (getcvar("hud_fade_offhand") != "0")
		setcvar("hud_fade_offhand", "0");
	if (getcvar("hud_fade_stance") != "0")
		setcvar("hud_fade_stance", "0");
	if(getcvar("scr_healthregen") == "")
		setcvar("scr_healthregen","0");
	if(getcvar("scr_grenadeindicator") == "")
		setcvar("scr_grenadeindicator","0");
		

	setcvar("cg_HudCompassSize","0.9");

	level.healthregen=getcvarint("scr_healthregen");
	level.grenadeindicator=getcvarint("scr_grenadeindicator");
/*	
	//Power CTF DVARS
	if(getcvar("scr_ctf_mode") == "")
		setcvar("scr_ctf_mode","4");
		
	if(getcvar("scr_ctf_swap_roundwinner") == "")
		setcvar("scr_ctf_swap_roundwinner","1");	
	
	if(getcvar("scr_ctf_scorelimit") == "100")
		setcvar("scr_ctf_scorelimit","500");
		
	if(getcvar("scr_ctf_roundlimit") == "4")
		setcvar("scr_ctf_roundlimit","20");

	if(getcvar("scr_ctf_roundlength") == "4")
		setcvar("scr_ctf_roundlength","3600");

	if(getcvar("scr_ctf_spawntickets") == "6")
		setcvar("scr_ctf_spawntickets","66");
	
	//Power CTF levels
	level.ctf_mode = getcvarint ("scr_ctf_mode");
	level.campaign_per_map = getcvarint ("scr_ctf_campaign_per_map");
	level.lastwinner = getcvarint ("scr_ctf_lastwinner");
	level.swap_roundwinner = getcvarint ("scr_ctf_swap_roundwinner");
	level.roundwinner = getcvarint ("scr_ctf_roundwinner");
	level.timelimit = getcvarint ("scr_ctf_timelimit");
	level.scorelimit = getcvarint ("scr_ctf_timelimit");
	level.roundlimit = getcvarint ("scr_ctf_roundlimit");
	level.roundlength = getcvarint ("scr_ctf_roundlength");
	level.spawnlimit = getcvarint ("scr_ctf_spawntickets");
	level.graceperiod = getcvarint ("scr_ctf_graceperiod");
*/	
	//Merciless
	if(getcvar("scr_merciless2_logo") == "")
		setcvar("scr_merciless2_logo","1");
	if(getcvar("scr_bloodfx") == "")
		setcvar("scr_bloodfx","2");
	if(getcvar("scr_bloodpools") == "")
		setcvar("scr_bloodpools", "1");
	if(getcvar("scr_painsounds") == "")
		setcvar("scr_painsounds","65");
	if(getcvar("scr_painscreen") == "")
		setcvar("scr_painscreen", "1");
	if(getcvar("scr_bloodyscreen") == "")
		setcvar("scr_bloodyscreen","1");
	if(getcvar("scr_extragore") == "")
		setcvar("scr_extragore","1");
	if(getcvar("scr_dropweaponhit") == "")
		setcvar("scr_dropweaponhit","50");
	if(getcvar("scr_crosshairs") == "")
		setcvar("scr_crosshairs","1");
	if(getcvar("scr_obituary") == "")
		setcvar("scr_obituary","1");
	if(getcvar("scr_showhit") == "")
		setcvar("scr_showhit","0");
	if(getcvar("scr_tkpunish") == "")
		setcvar("scr_tkpunish","500");
	if(getcvar("scr_forceprone") == "")
		setcvar("scr_forceprone","1");
	if(getcvar("scr_bleed") == "")
		setcvar("scr_bleed","1");
	if(getcvarint("scr_decap_min") < 160 )
		setcvar("scr_decap_min","160");
	if(getcvar("scr_decap_chance") == "")
		setcvar("scr_decap_chance","60");
	if(getcvar("scr_msgdelay") == "")
		setcvar("scr_msgdelay","30");
		
	if(getcvar("scr_coldbreath") == "")
		setcvar("scr_coldbreath","1");

	if(getcvar("scr_mine_teamkill") == "")
		setcvar("scr_mine_teamkill","1");

	if(getcvar("scr_medic_heal") == "")
		setcvar("scr_medic_heal","25");
		
	if(getcvar("scr_ss_drop") == "")
		setcvar("scr_ss_drop","1");

	if(getcvar("scr_sniper_artillery") == "")
		setcvar("scr_sniper_artillery","1");	

	if(getcvar("scr_gasgrenades") == "")
		setcvar("scr_gasgrenades","1");
		
	if(getcvar("scr_extragrenades") == "")
		setcvar("scr_extragrenades","1");	
		
	if(getcvar("scr_biggrenades") == "")
		setcvar("scr_biggrenades","1");

	if(getcvar("scr_testclients") == "")
		setcvar("scr_testclients","0");
		
	if(getcvar("scr_payload_artillery") == "")
		setcvar("scr_payload_artillery","1");	
	
	level.scr_payload_artillery = getcvarint ("scr_payload_artillery");	
	level.scr_testclients = getcvarint ("scr_testclients");
	level.scr_biggrenades = getcvarint ("scr_biggrenades");
	level.scr_extragrenades =getcvarint ("scr_extragrenades");
	level.scr_gasgrenades = getcvarint ("scr_gasgrenades");
	level.scr_merciless2_logo= getcvarint("scr_merciless2_logo");
	level.bloodfx = getcvarint("scr_bloodfx");
	level.scr_bloodpools = getcvarint("scr_bloodpools");

	level.scr_shellshock = getcvarint("scr_shellshock");
	level.scr_bloodpools = getcvarint("scr_bloodpools");
	level.scr_painsounds = getcvarint("scr_painsounds");
	level.scr_painscreen = getcvarint("scr_painscreen");
	level.scr_bloodyscreen = getcvarint("scr_bloodyscreen");
	level.scr_extragore = getcvarint("scr_extragore");
	level.scr_dropweaponhit = getcvarint("scr_dropweaponhit");
	level.scr_crosshairs = getcvarint("scr_crosshairs");
	level.scr_obituary = getcvarint("scr_obituary");
	level.scr_tkpunish = getcvarint("scr_tkpunish");
	level.scr_showhit = getcvarint("scr_showhit");
	level.scr_forceprone = getcvarint("scr_forceprone");
	level.scr_decap_min = getcvarint("scr_decap_min");
	level.scr_decap_chance = getcvarint("scr_decap_chance");
	level.realism = getcvarint("scr_realism");

	level.scr_coldbreath = getcvarint("scr_coldbreath");
	level.scr_mine_teamkill = getcvarint("scr_mine_teamkill");
	level.scr_medic_heal = getcvarint("scr_medic_heal");
	level.scr_ss_drop = getcvarint("scr_ss_drop");
	level.scr_sniper_artillery = getcvarint("scr_sniper_artillery");

}