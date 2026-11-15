.set LOCALID_NURSE, 1

Route32_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_PokemonCenter_OnTransition	
	.byte 0

Route32_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ROUTE_32
	end

Route32_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox Route32_Pokecenter_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_PokemonCenter_EventScript_FishingGuru::
	lock
	faceplayer
	checkitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru3
	msgbox Route32_Pokecenter_Text_FishingGuruQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru2
	msgbox Route32_Pokecenter_Text_FishingGuruNo, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru2::
	msgbox Route32_Pokecenter_Text_FishingGuruYes, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route32_Pokecenter_Text_FishingGuruGiveRod, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru3::
	msgbox Route32_Pokecenter_Text_FishingGuruAfter, MSGBOX_DEFAULT
	release
	end



Route32_Pokecenter_Text_FishingGuruQuestion:
	.string "这里是个绝佳的钓鱼点。\p你看到有人在钓鱼了吧？\n你呢？\p想要一根我的钓竿吗？$"
	.string ""
	.string ""
	.string ""

Route32_Pokecenter_Text_FishingGuruYes:
	.string "嘿嘿，这话我爱听。\p现在你也是钓鱼人了！$"
	.string ""

Route32_Pokecenter_Text_FishingGuruGiveRod:
	.string "钓鱼真不错！\p只要有水，不管是海\n还是小河，都用钓竿试试吧。$"
	.string ""
	.string ""

Route32_Pokecenter_Text_FishingGuruNo:
	.string "哦，那可真遗憾……$"

Route32_Pokecenter_Text_FishingGuruAfter:
	.string "哟，小家伙。钓得怎么样？$"

Route32_Pokecenter_Text_CooltrainerF:
	.string "该让我的宝可梦\n携带什么呢？\p也许是能提高\n攻击力的道具……$"
	.string ""
	.string ""

