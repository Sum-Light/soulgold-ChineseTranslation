.set LOCALID_DIGLETT_BROCK, 1

DiglettsCave_EntranceNorth_MapScripts::
	.byte 0


DiglettsCave_EntranceNorth_EventScript_Brock::
    lock
    faceplayer
    msgbox DiglettsCave_EntranceNorth_Text_Brock, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_DIGLETT_BROCK
    removeobject LOCALID_DIGLETT_BROCK
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_BROCK
    release
    end

DiglettsCave_EntranceNorth_Text_Brock:
    .string "小刚：被岩石环绕的狭小空间\n会让人内心平静，\l你不觉得吗？\p如果还想再和我较量，\n我会在格斗道场。$"
    .string ""
    .string ""
	.string ""
	.string ""




