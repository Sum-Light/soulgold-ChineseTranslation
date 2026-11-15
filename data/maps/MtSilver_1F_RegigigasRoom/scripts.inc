MtSilver_1F_RegigigasRoom_MapScripts::
	.byte 0


MtSilver_Regigigas::
	lock
	checkspecies SPECIES_REGISTEEL
	compare VAR_RESULT, TRUE
	goto_if_eq MtSilver_Regigigas_2
	goto RegigigasSlumbers
MtSilver_Regigigas_1:
	release
	end

MtSilver_Regigigas_2:
	checkspecies SPECIES_REGIROCK
	compare VAR_RESULT, TRUE
	goto_if_eq MtSilver_Regigigas_5
	goto RegigigasSlumbers
	goto MtSilver_Regigigas_1

MtSilver_Regigigas_5:
	checkspecies SPECIES_REGICE
	compare VAR_RESULT, TRUE
	goto_if_eq MtSilver_Regigigas_8
	goto RegigigasSlumbers
	goto MtSilver_Regigigas_1

MtSilver_Regigigas_8:
	msgbox MtSilver_Regigigas_Text_0
	bosslegendaryencounter SPECIES_REGIGIGAS, 70, LOCALID_MTSILVER_REGIGIGAS, FLAG_HIDE_REGIGIGAS, 4, SPECIES_NONE, 110
	release
	end


RegigigasSlumbers::
	msgbox RegigigasSlumbers_Text_0
	release
	end


MtSilver_Regigigas_Text_0:
	.string "……！\p雕像在感应到你的宝可梦后，\n突然动了起来！\p雕像发动了攻击！$"

RegigigasSlumbers_Text_0:
	.string "一只巨大得几乎像雕像的\n宝可梦，似乎正在这里\l休息。\p……\p它对你的到来\n没有任何反应。$"
