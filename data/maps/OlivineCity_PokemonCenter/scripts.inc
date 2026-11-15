.set LOCALID_NURSE, 1

OlivineCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_PokemonCenter_OnTransition
	.byte 0

OlivineCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_OLIVINE_CITY
	end

OlivineCity_EventScript_Fisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterFisher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Teacher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PokecenterFisher:
	.string "隔壁浅葱咖啡馆里的那位水手\n非常大方。\p他教会了我的宝可梦怪力。\p现在它搬起大石头\n连大气都不喘。$"
	.string ""
	.string ""
	.string ""
	.string ""

OlivineCity_Text_PokecenterTeacher:
	.string "大海对岸的湛蓝市\n有个人。\p我听说他总在吹嘘\n自己珍稀的宝可梦。$"
	.string ""
	.string ""
	.string ""
