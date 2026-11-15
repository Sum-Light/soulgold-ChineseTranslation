OlivineCity_LighthouseTop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_LighthouseTop_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

OlivineCity_LighthouseTop_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_unset FLAG_HIDE_ZAPDOS, OlivineCity_LighthouseTop_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setweather WEATHER_NONE
	return

OlivineCity_LighthouseTop_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setweather WEATHER_RAIN_THUNDERSTORM
	return


Lighthousetop_Zapdos::
	lock
	faceplayer
	legendaryencounter SPECIES_ZAPDOS, 50, LOCALID_LIGHTHOUSE_ZAPDOS, FLAG_HIDE_ZAPDOS
	release
	end


Lighthouse_Engineer::
	lock
	faceplayer
	msgbox Lighthouse_Engineer_Text_0
	release
	end


Lighthouse_Engineer_Text_0:
	.string "最近有宝可梦弄坏了\n通往顶层的梯子。\p我正在修，\n不过还得花些时间。$"
