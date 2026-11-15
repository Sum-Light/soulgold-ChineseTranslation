Kitakami_Temple_Storage_MapScripts::
	.byte 0


StorageMienfoo::
	lock
	faceplayer
	playmoncry SPECIES_MIENFOO, CRY_MODE_NORMAL
	msgbox StorageMienfoo_Text_0
	waitmoncry
	release
	end


StorageKeeper::
	lock
	faceplayer
	goto_if_set FLAG_OBTAINED_OGERPON_MASKS, StorageKeeper_2
	msgbox StorageKeeper_Text_1
	checkspecies SPECIES_OGERPON
	compare VAR_RESULT, TRUE
	goto_if_eq StorageKeeper_5
	release
	end

StorageKeeper_2:
	msgbox StorageKeeper_Text_0
	release
	end

	release
	end

StorageKeeper_5:
	playse SE_PIN
	applymovement LOCALID_TEMPLE_STOREKEEPER, Common_Movement_ExclamationMark
	waitse
	delay 30
	msgbox StorageKeeper_Text_2
	giveitem ITEM_CORNERSTONE_MASK
	giveitem ITEM_WELLSPRING_MASK
	giveitem ITEM_HEARTHFLAME_MASK
	setflag FLAG_OBTAINED_OGERPON_MASKS
	msgbox StorageKeeper_Text_0
	release
	end


StorageMienfoo_Text_0:
	.string "功夫鼬：呼！$"

StorageKeeper_Text_0:
	.string "这些面具能让厄诡椪在战斗中\n运用其他属性的力量。$"

StorageKeeper_Text_1:
	.string "我的职责是看管北上的\n神圣宝物。\p我们村子的守护者厄诡椪，\n曾把强大的宝物托付给我们。\p我们一直守护着它们，\n直到厄诡椪再次需要。$"

StorageKeeper_Text_2:
	.string "难道说……？厄诡椪\n选你当它的搭档了？\p太不可思议了！\p既然如此，这些神圣宝物\n就该由你来保管。$"
