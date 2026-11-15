Route26_House2_MapScripts::
	.byte 0

Route26_House2_EventScript_Book::
	lock
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE,Route26_House2_EventScript_BookRead
	closemessage
	release
	end

Route26_House2_EventScript_BookRead::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route26_House2_EventScript_BookRead2
	closemessage
	release
	end
	
Route26_House2_EventScript_BookRead2::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex3, MSGBOX_DEFAULT
	closemessage
	release
	end

DayOfWeekSiblingsHouse_Text_Pokedex1:
    .string "这里写着些什么。\p要读吗？$"
    .string ""

DayOfWeekSiblingsHouse_Text_Pokedex2:
    .string "致我的兄弟姐妹们：\p能为宝可梦训练家出力，\n我们深感自豪。\p训练家跟你搭话时，\n就送点实用的东西。\p爱你们的\n星琪怡\p要继续读吗？$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

DayOfWeekSiblingsHouse_Text_Pokedex3:
    .string "星期一，星琪怡\n40号水路\p星期二，星琪儿\n29号道路\p星期三，星琪山\n愤怒之湖\p星期四，星琪思\n36号道路\p星期五，星琪舞\n32号道路\p星期六，星琪柳\n烟墨市\p星期日，星琪天\n37号道路$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""
