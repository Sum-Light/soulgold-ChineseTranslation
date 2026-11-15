RuinsOfAlph_SecretRoom_MapScripts::
	.byte 0


RuinsSecretRoom::
	lock
	checkspecies SPECIES_HOOPA
	compare VAR_RESULT, FALSE
	goto_if_eq RuinsSecretRoom_2
RuinsSecretRoom_1:
	compare VAR_RESULT, TRUE
	goto_if_eq RuinsSecretRoom_5
	msgbox RuinsSecretRoom_Text_1, MSGBOX_SIGN
	release
	end

RuinsSecretRoom_2:
	checkspecies SPECIES_HOOPA_UNBOUND
	goto RuinsSecretRoom_1

RuinsSecretRoom_5:
	msgbox RuinsSecretRoom_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq RuinsSecretRoom_8
RuinsSecretRoom_7:
	release
	end

RuinsSecretRoom_8:
	warp MAP_SPEAR_PILLAR_TOP, 16, 33
	waitstate
	goto RuinsSecretRoom_7


RuinsSecretRoom_Text_0:
	.string "胡帕似乎想让你看\n什么东西。\p要让它与墙壁互动吗？$"

RuinsSecretRoom_Text_1:
	.string "墙上画着一只小生物，\n正在打开通往遥远\l某处的传送门。$"
