#include "global.h"
#include "buenas_password.h"
#include "rtc.h"
#include "string_util.h"

#define BUENAS_PASSWORD_START_HOUR 18
#define BUENAS_PASSWORD_END_HOUR   24
#define BUENAS_PASSWORD_OPTIONS     3

enum BuenasPasswordGroup
{
    BUENA_PASSWORD_STARTERS,
    BUENA_PASSWORD_MEDICINE,
    BUENA_PASSWORD_BALLS,
    BUENA_PASSWORD_ROUTE_MONS,
    BUENA_PASSWORD_NIGHT_MONS,
    BUENA_PASSWORD_TOWNS,
    BUENA_PASSWORD_CATEGORIES,
    BUENA_PASSWORD_MOVES,
    BUENA_PASSWORD_X_ITEMS,
    BUENA_PASSWORD_RADIO_SHOWS,
    BUENA_PASSWORD_COUNT
};

static const u8 sText_Cyndaquil[] = _("火球鼠");
static const u8 sText_Totodile[] = _("小锯鳄");
static const u8 sText_Chikorita[] = _("菊草叶");
static const u8 sText_Potion[] = _("伤药");
static const u8 sText_Antidote[] = _("解毒药");
static const u8 sText_ParlyzHeal[] = _("解麻药");
static const u8 sText_PokeBall[] = _("精灵球");
static const u8 sText_GreatBall[] = _("超级球");
static const u8 sText_UltraBall[] = _("高级球");
static const u8 sText_Pikachu[] = _("皮卡丘");
static const u8 sText_Rattata[] = _("小拉达");
static const u8 sText_Geodude[] = _("小拳石");
static const u8 sText_Hoothoot[] = _("咕咕");
static const u8 sText_Spinarak[] = _("圆丝蛛");
static const u8 sText_Drowzee[] = _("催眠貘");
static const u8 sText_NewBarkTown[] = _("若叶镇");
static const u8 sText_CherrygroveCity[] = _("吉花市");
static const u8 sText_AzaleaTown[] = _("桧皮镇");
static const u8 sText_BugPokemon[] = _("虫属性宝可梦");
static const u8 sText_BirdPokemon[] = _("鸟宝可梦");
static const u8 sText_GrassPokemon[] = _("草属性宝可梦");
static const u8 sText_Tackle[] = _("撞击");
static const u8 sText_Growl[] = _("叫声");
static const u8 sText_MudSlap[] = _("掷泥");
static const u8 sText_XAttack[] = _("力量强化");
static const u8 sText_XDefend[] = _("防御强化");
static const u8 sText_XSpeed[] = _("速度强化");
static const u8 sText_PokemonTalk[] = _("宝可梦讲座");
static const u8 sText_PokemonMusic[] = _("宝可梦音乐");
static const u8 sText_BuenasPassword[] = _("葵妍的密语");

static const u8 sText_BuenasPasswordRadio[] = _(
    "大家好！我是葵妍！\n现在公布今天的密语！\p今天的密语是……\n{STR_VAR_1}！\p可别忘了哦！\p我很期待大家\n到满金市的广播塔\l来找我哦！{PAUSE_UNTIL_PRESS}"
    ""
    ""
    ""
    ""
    ""
    ""
    "");

static const u8 *const sBuenasPasswordOptions[][BUENAS_PASSWORD_OPTIONS] =
{
    [BUENA_PASSWORD_STARTERS] =
    {
        sText_Cyndaquil,
        sText_Totodile,
        sText_Chikorita,
    },
    [BUENA_PASSWORD_MEDICINE] =
    {
        sText_Potion,
        sText_Antidote,
        sText_ParlyzHeal,
    },
    [BUENA_PASSWORD_BALLS] =
    {
        sText_PokeBall,
        sText_GreatBall,
        sText_UltraBall,
    },
    [BUENA_PASSWORD_ROUTE_MONS] =
    {
        sText_Pikachu,
        sText_Rattata,
        sText_Geodude,
    },
    [BUENA_PASSWORD_NIGHT_MONS] =
    {
        sText_Hoothoot,
        sText_Spinarak,
        sText_Drowzee,
    },
    [BUENA_PASSWORD_TOWNS] =
    {
        sText_NewBarkTown,
        sText_CherrygroveCity,
        sText_AzaleaTown,
    },
    [BUENA_PASSWORD_CATEGORIES] =
    {
        sText_BugPokemon,
        sText_BirdPokemon,
        sText_GrassPokemon,
    },
    [BUENA_PASSWORD_MOVES] =
    {
        sText_Tackle,
        sText_Growl,
        sText_MudSlap,
    },
    [BUENA_PASSWORD_X_ITEMS] =
    {
        sText_XAttack,
        sText_XDefend,
        sText_XSpeed,
    },
    [BUENA_PASSWORD_RADIO_SHOWS] =
    {
        sText_PokemonTalk,
        sText_PokemonMusic,
        sText_BuenasPassword,
    },
};

static u16 GetBuenasPasswordIndex(u16 modulo, u32 salt)
{
    u32 seed;

    RtcCalcLocalTime();
    seed = gSaveBlock1Ptr->dailySeed ^ (gLocalTime.days * 1103515245);
    seed ^= salt * 0x45d9f3b;
    seed ^= seed >> 16;
    return seed % modulo;
}

u16 BuenasPassword_IsBroadcastTime(void)
{
    RtcCalcLocalTime();
    return IsBetweenHours(gLocalTime.hours, BUENAS_PASSWORD_START_HOUR, BUENAS_PASSWORD_END_HOUR);
}

u16 BuenasPassword_GetCurrentGroup(void)
{
    return GetBuenasPasswordIndex(BUENA_PASSWORD_COUNT, 0);
}

u16 BuenasPassword_GetCorrectAnswer(void)
{
    return GetBuenasPasswordIndex(BUENAS_PASSWORD_OPTIONS, 1);
}

void BuenasPassword_BufferCurrentPassword(void)
{
    StringCopy(gStringVar1, sBuenasPasswordOptions[BuenasPassword_GetCurrentGroup()][BuenasPassword_GetCorrectAnswer()]);
}

const u8 *BuenasPassword_GetRadioText(void)
{
    BuenasPassword_BufferCurrentPassword();
    return sText_BuenasPasswordRadio;
}
