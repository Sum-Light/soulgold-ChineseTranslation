
Gate_Route40_TrainerHill_Courtyard_MapScripts::
	.byte 0

BattleTowerGuard::
	msgbox BattleTowerGuard_Text_0, MSGBOX_NPC
	return


BattleTowerTunnelFrustrationNPC::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_FRUSTRATION, BattleTowerTunnelFrustrationNPC_2
BattleTowerTunnelFrustrationNPC_1:
	msgbox BattleTowerTunnelFrustrationNPC_Text_1
	release
	end

BattleTowerTunnelFrustrationNPC_2:
	msgbox BattleTowerTunnelFrustrationNPC_Text_0
	giveitem ITEM_TM_FRUSTRATION
	setflag FLAG_GOT_FRUSTRATION
	goto BattleTowerTunnelFrustrationNPC_1


BattleTowerGuard_Text_0:
	.string "前面是对战塔，\n强大的训练家都聚集在那里。$"

BattleTowerTunnelFrustrationNPC_Text_0:
	.string "我在对战塔第一轮就输了，\n得把郁闷发泄出来，这个给你。$"

BattleTowerTunnelFrustrationNPC_Text_1:
	.string "迁怒的威力，会随宝可梦\n对你的好感降低而提高。\l老像我这样输，\l就会变成这样！$"
