Route49DesertGate_MapScripts::
	.byte 0


Route49GateJoy::
	lock
	faceplayer
	msgbox Route49GateJoy_Text_0
	playse SE_USE_ITEM
	special HealPlayerParty
	msgbox Route49GateJoy_Text_1
	release
	end


Route49GateJoy_Text_0:
	.string "您好！我来为您治疗宝可梦！$"

Route49GateJoy_Text_1:
	.string "好了！全都恢复精神了！$"
