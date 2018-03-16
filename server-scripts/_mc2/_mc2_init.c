/*-------------------------------------------
 __  __
||\\//|| E R C I L E S S  2
|| \/ ||
---------------------------
(www.mercilessmod.com)
----------------------
Initialize Merciless2 and precache
all the goodies which are needed
---------------------------------
Updated July 2015
Ditched Adding MG thing back idea
-------------------------------------
Will remove MG stuff later
-------------------------------------------*/

init()
{
	// INIT MERCILESS CVARS
	_mc2\_mc2_vars::initialize_cvars();
	_mc2\_mc2_classes::InitializeClasses();


	// BLOOD & GORE FX
	if(level.bloodfx<=1)
	{
		level._effect["bloodpools_body"]=loadfx("fx/effects/gore/blood_pool_big_mc.efx");
		level._effect["headpop1"]=loadfx("fx/effects/gore/headpop1.efx");
		level._effect["bloodspurt"]=loadfx("fx/effects/gore/neck_squirt_master_mc.efx");
		level._effect["ChunkyDeath"] = loadfx("fx/effects/gore/chunky_hit_mc.efx");
		level._effect["hit_extra1_mc"]=loadfx("fx/effects/gore/hit_extra1_mc.efx");
		level._effect["hit_extra2_mc"]=loadfx("fx/effects/gore/hit_extra2_mc.efx");
		level._effect["hit_extra3_mc"]=loadfx("fx/effects/gore/hit_extra3_mc.efx");

		precacheShader("blood_stain_sml01");
		precacheShader("blood_stain_sml02");
		precacheShader("blood_stain_sml03");
		precacheShader("blood_stain_sml04");
		precacheShader("blood_stain_sml05");
		precacheShader("blood_stain_sml06");
		precacheShader("blood_stain_lrg01");
		precacheShader("blood_stain_lrg02");
		precacheShader("blood_stain_lrg03");
		precacheShader("blood_stain_big01");
		precacheShader("blood_stain_big02");
		precacheShader("blood_stain_big03");
	}
	if(level.bloodfx>=2)
	{
		level._effect["bloodpools_body"]=loadfx("fx/effects/gore/blood_pool_big.efx");
		level._effect["headpop1"]=loadfx("fx/effects/gore/headpop2.efx");
		level._effect["bloodspurt"]=loadfx("fx/effects/gore/neck_squirt_master.efx");
		level._effect["ChunkyDeath"] = loadfx("fx/effects/gore/chunky_hit.efx");
		level._effect["hit_extra1"]=loadfx("fx/effects/gore/hit_extra1.efx");
		level._effect["hit_extra2"]=loadfx("fx/effects/gore/hit_extra2.efx");
		level._effect["hit_extra3"]=loadfx("fx/effects/gore/hit_extra3.efx");

		precacheShader("blood_stain_sml07");
		precacheShader("blood_stain_sml08");
		precacheShader("blood_stain_sml09");
		precacheShader("blood_stain_sml10");
		precacheShader("blood_stain_sml11");
		precacheShader("blood_stain_lrg04");
		precacheShader("blood_stain_lrg05");
		precacheShader("blood_stain_lrg06");
		precacheShader("blood_stain_big01");
		precacheShader("blood_stain_big02");
		precacheShader("blood_stain_big03");
	}
	level._effect["gib"]=loadfx("fx/effects/gore/gib3.efx");
	level._effect["gib2"]=loadfx("fx/effects/gore/gib2.efx");

	level._effect["bleed"] = loadfx("fx/effects/gore/blood_drip_sm.efx");
	level._effect["bleed2"] = loadfx("fx/effects/gore/blood_drips2.efx");
	level._effect["blood_spray"] = loadfx("fx/effects/gore/blood_drips.efx");
	level._effect["brain_splat"] = loadfx("fx/effects/gore/brain_splat.efx");

	level._effect["bloodfx"]=loadfx("fx/effects/gore/bloodfx.efx");
	level._effect["bloodimpact"]=loadfx("fx/effects/gore/bloodimpact.efx");
	level._effect["hit_flesh_org"]=loadfx("fx/effects/gore/flesh_hit.efx");
	level._effect["hit_flesh_mc"]=loadfx("fx/effects/gore/hit_flesh_mc.efx");
	level._effect["hit_flesh_mc2"]=loadfx("fx/effects/gore/hit_flesh_mc2_mp.efx");
	level._effect["hit_pistol"]=loadfx("fx/effects/gore/hit_pistol.efx");
	level._effect["hit_rifle"]=loadfx("fx/effects/gore/hit_rifle.efx");
	level._effect["hit_rifle2"]=loadfx("fx/effects/gore/hit_rifle2.efx");
	level._effect["hit_smg"]=loadfx("fx/effects/gore/hit_smg.efx");
	level._effect["hit_turret"]=loadfx("fx/effects/gore/hit_turret.efx");
	level._effect["hit_shotgun"]=loadfx("fx/effects/gore/hit_shotgun.efx");

	// GENERAL FX
	level._effect["breath"]=loadfx("fx/misc/cold_breath.efx");
	level._effect["bounce"]=loadfx("fx/dust/dust_impact_small.efx");
	level._effect["playerburn"] = loadfx("fx/fire/character_torso_fire.efx");
	level._effect["playerburn2"] = loadfx("fx/fire/character_arm_fire.efx");
	level._effect["playerburn3"] = loadfx("fx/smoke/molotov_flames2.efx");
	level._effect["playerburn4"] = loadfx("fx/fire/building_fire_small.efx");
	//level._effect["playersmoke"] = loadfx ("fx/smoke/grenade_smoke.efx");
	level._effect["playersmoke"] = loadfx ("fx/smoke/bodysmoke.efx");
	level._effect["burnpool_body"]=loadfx("fx/effects/gore/burn_pool_sml.efx");
	level._effect["burn_stains"]=loadfx("fx/effects/gore/burn_stain.efx");
	level._effect["smoke"]=loadfx("fx/props/american_smoke_grenade2.efx");
	level._effect["puke"] = loadfx ("fx/misc/vomit.efx");
	level._effect["tnt_boom"]=loadfx("fx/explosions/default_explosion.efx");
	level._effect["mine_boom"]=loadfx("fx/effects/mine.efx");

	//ITEMS
	precacheItem("axisgas_mp");
	precacheItem("alliedgas_mp");
	precacheItem("axisfire_mp");
	precacheItem("fire_mp");
	precacheItem("artillery_mp");
	precacheItem("tnt_mp");
	precacheItem("sixpack_mp");
	//MODELS

	//MENU
	precacheMenu("stand");
	precacheMenu("prone");
	precacheMenu("crouch");
	precacheMenu("noads");
	precacheMenu("ansgewehr");
	precacheMenu("wegvomgewehr");

	precacheShader("gfx/hud/hud@fire_ready.tga");
	precacheShader("gfx/hud/hud@redpain_tr.tga");
	precacheShader("gfx/hud/hud@fire_ready_shel.dds");
	precacheShader("gfx/hud/hud@fire_ready_shll.dds");
	precacheShader("gfx/hud/hud@health_back.tga");
	precacheShader("gfx/hud/hud@health_bar.tga");
	precacheShader("gfx/hud/hud@health_cross.tga");
	precacheShader("gfx/icons/hud@icon_bullet.tga");
	precacheShader("gfx/hud/hud@healthcros.tga");
	precacheShader("gfx/icons/hud@iconslash.tga");
	precacheShader("gfx/hud/hud@weaponnameback.tga");
	precacheShader("gfx/hud/hud@weaponameback2.tga");
	precacheShader("gfx/hud/hud@helth_back.tga");
	precacheShader("gfx/icons/hud@icon_shotgn.tga");
	precacheShader("gfx/icons/hud@icon_pistol.tga");
	precacheShader("gfx/hud/logo_ooo.tga");

	precacheShader("gfx/hud/logo_mc1.tga");
	precacheShader("gfx/hud/hud@sprntback1.tga");
	precacheShader("gfx/hud/hud@sprntback2.tga");
	precacheShader("gfx/hud/hud@sprint_bar.tga");

	//STREAK
	/*precacheShader("_blood_streak_01");
	precacheShader("_blood_streak_02");
	precacheShader("_blood_streak_03");
	precacheShader("_blood_streak_04");
	precacheShader("_blood_streak_05");
	precacheShader("_blood_streak_06");
	precacheShader("_blood_streak_07");
	precacheShader("_blood_streak_08");
	precacheShader("_blood_streak_09");
	precacheShader("_blood_streak_10");
	precacheShader("_blood_streak_11");
	precacheShader("_blood_streak_12");
	precacheShader("_blood_streak_13");
	precacheShader("_blood_streak_14");
	precacheShader("_blood_streak_15");*/

	//SHELLSHOCK
	precacheShellShock("mc_mustard");
	precacheShellShock("mc_default");
	precacheShellShock("mc_hit3");

	//TEXT
	precacheString(&"MC2_WARN_MSG");
	precacheString(&"MC2_PUNISH_MSG");
	precacheString(&"MC2_ARTILLERY_READY");
	level._legdmg=(&"MC2_LEGDMG");
	precacheString(level._legdmg);

	// MISC
	level._sprottext = (&"Spawn Protected: ^3");
//	level._schaurunter= (&"Look on the ground and press [{+activate}] to plant your MG!");
//	level._hiergehts= (&"^2Planting MG ...");
//	level._bistzunahdran= (&"^1MG-Position to near");
//	level._bistzuweitweg= (&"^1MG-Position to far");

	level._oo= (&"oo");
	level._leer= (&"");
//	precacheString(level._oo);
//	precacheString(level._leer);
	precacheString(level._sprottext);
//	precacheString(level._schaurunter);
//	precacheString(level._hiergehts);
//	precacheString(level._bistzunahdran);
//	precacheString(level._bistzuweitweg);

	level.objectQ["helmet"] = [];
	level.objectQcurrent["helmet"] = 0;
	level.objectQsize["helmet"] = 6;

	//FUNCTIONS
	game["POPHELMET"] = _mc2\_mc2_gore::popHelm;
}
