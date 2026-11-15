Route27_House_MapScripts::
	.byte 0

Route27_House_EventScript_Woman::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_TM_SANDSTORM, Route27_House_EventScript_WomanBeforeGiven
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanBeforeGiven::
	msgbox SandstormHouse_Text_Woman1, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, Route27_House_EventScript_WomanHighFriendship
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAway
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_QuestionMark
	waitmovement 0
	msgbox SandstormHouse_Text_DisloyalMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanHighFriendship::
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerDance
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER ContestHall_Movement_Heart
	waitmovement 0
	msgbox SandstormHouse_Text_LoyalMon, MSGBOX_DEFAULT
	giveitem ITEM_TM_SANDSTORM
	setflag FLAG_GOT_TM_SANDSTORM
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_Movement_FollowerJump:
	jump_in_place_down
	jump_in_place_down
	step_end

SandstormHouse_Text_Woman1:
    .string "你要带着宝可梦\n去哪儿啊？\p宝可梦联盟？\p你的宝可梦够不够忠心，\n能让你赢下来呢？\p让我看看……$"
    .string ""
    .string ""
    .string ""
    .string ""
    .string ""

SandstormHouse_Text_LoyalMon:
    .string "哦！你的宝可梦\n很信任你。\p看到优秀的训练家\n真是件好事。\p来，这个送给你\n当饯别礼。$"
    .string ""
    .string ""
    .string ""

SandstormHouse_Text_TM37Description:
    .string "招式学习器37里装的是沙暴。\p这招会对对战的\n双方都造成伤害。\p这是给高水平训练家\n准备的招式。\p有胆量就用用看。祝你好运！$"
    .string ""
    .string ""
    .string ""
    .string ""

SandstormHouse_Text_DisloyalMon:
    .string "要是它还不能更信任你，\n往后的路怕是会很艰难。\p把宝可梦和训练家\n连在一起的，就是信赖啊。$"
    .string ""
    .string ""
    .string ""


