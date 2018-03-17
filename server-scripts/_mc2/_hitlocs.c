/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/

getHitLocTag(sHitLoc)
{
	switch(sHitloc)
	{
		case "right_hand":
			return "j_wrist_ri";
		case "left_hand":
			return "j_wrist_le";	
		case "right_arm_upper":	
			return "j_shoulder_ri";
		case "left_arm_upper":
			return "j_shoulder_le";
		case "right_arm_lower":	
			return "j_elbow_ri";
		case "left_arm_lower":
			return "j_elbow_le";
		case "head":
			return "J_Head";
		case "neck":
			return "J_Neck";			
		case "right_foot":
			return "j_ankle_ri";
		case "left_foot":
			return "j_ankle_le";
		case "right_leg_lower":
			return "j_knee_ri";
		case "left_leg_lower":
			return "j_knee_le";
		case "right_leg_upper":
			return "j_hip_ri";					
		case "left_leg_upper":
			return "j_hip_le";
		case "torso_upper":
			switch(randomint(2))
			{
				case 0:
					return "J_Clavicle_RI";
				case 1:
					return "J_Clavicle_LE";
			}		
		case "torso_lower":
			switch(randomint(3))
			{
				case 0:
					return "J_Spine1";
				case 1:
					return "J_Spine2";
				case 2:
					return "J_Spine3";
			}
		case "none":
		default:
			return "J_MainRoot";
	}
}
hitloc(sHitLoc)
{
	switch(sHitLoc)
	{
	case "right_hand":
	case "left_hand":
		return "hand";
	case "right_arm_upper":	
	case "right_arm_lower":	
	case "left_arm_upper":
	case "left_arm_lower":
		return "arm";
	case "head":
	case "helmet":
		return "head";
	case "neck":
		return "neck";
	case "right_foot":
	case "left_foot":
		return "foot";
	case "right_leg_lower":
	case "left_leg_lower":
	case "right_leg_upper":
	case "left_leg_upper":
		return "leg";
	case "torso_upper":
		return "torso_up";
	case "torso_lower":
		return "torso_dn";
	default:
		return "none";
	}
}