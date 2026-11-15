#include "global.h"
#include "battle_facility_bgm.h"
#include "event_data.h"
#include "malloc.h"
#include "random.h"
#include "script_menu.h"
#include "string_util.h"
#include "constants/songs.h"
#include "constants/vars.h"

enum BattleFacilityBgmChoice
{
    FACILITY_BGM_DEFAULT,
    FACILITY_BGM_RANDOM,
    FACILITY_BGM_FIRST_TRACK,
};

struct BattleFacilityBgmOption
{
    const u8 *name;
    u16 songId;
};

// This is the only table that needs editing to add more facility battle music.
// Every entry after Random is also automatically included in the random pool.
static const struct BattleFacilityBgmOption sBattleFacilityBgmOptions[] =
{
    [FACILITY_BGM_DEFAULT] = { COMPOUND_STRING("默认"), MUS_NONE },
    [FACILITY_BGM_RANDOM]  = { COMPOUND_STRING("随机"),  MUS_NONE },
    { COMPOUND_STRING("绿宝石训练家战"), MUS_VS_TRAINER },
    { COMPOUND_STRING("火红训练家战"), MUS_RG_VS_TRAINER },
    { COMPOUND_STRING("D/P/Pt训练家战"), MUS_DP_VS_TRAINER },
    { COMPOUND_STRING("HG/SS训练家战"), MUS_HG_VS_TRAINER },
    { COMPOUND_STRING("HG/SS关都训练家战"), MUS_HG_VS_TRAINER_KANTO },
    { COMPOUND_STRING("关都馆主战"), MUS_HG_VS_GYM_LEADER_KANTO},
    { COMPOUND_STRING("城都馆主战"), MUS_HG_VS_GYM_LEADER},
    { COMPOUND_STRING("丰缘馆主战"), MUS_VS_GYM_LEADER},
    { COMPOUND_STRING("神奥馆主战"), MUS_DP_VS_GYM_LEADER},
    { COMPOUND_STRING("关都冠军战"), MUS_RG_VS_CHAMPION },
    { COMPOUND_STRING("城都冠军战"), MUS_HG_VS_CHAMPION },
    { COMPOUND_STRING("丰缘冠军战"), MUS_VS_CHAMPION },
    { COMPOUND_STRING("神奥冠军战"), MUS_DP_VS_CHAMPION },
    { COMPOUND_STRING("火箭队战"), MUS_HG_VS_ROCKET },
    { COMPOUND_STRING("开拓头脑战(RSE)"), MUS_VS_FRONTIER_BRAIN },
    { COMPOUND_STRING("开拓头脑战(HGSS)"), MUS_HG_VS_FRONTIER_BRAIN},
};

#define FACILITY_BGM_TRACK_COUNT (ARRAY_COUNT(sBattleFacilityBgmOptions) - FACILITY_BGM_FIRST_TRACK)

// Random mode uses every track once before reshuffling. This is cosmetic
// runtime state and deliberately is not saved.
static EWRAM_DATA u16 sRandomBattleFacilityBgmBag[FACILITY_BGM_TRACK_COUNT] = {0};
static EWRAM_DATA u16 sRandomBattleFacilityBgmBagPos = 0;
static EWRAM_DATA bool8 sRandomBattleFacilityBgmBagInitialized = FALSE;
static EWRAM_DATA u16 sLastRandomBattleFacilityBgm = FACILITY_BGM_DEFAULT;

static void ShuffleBattleFacilityBgmBag(void)
{
    u32 i;

    for (i = 0; i < FACILITY_BGM_TRACK_COUNT; i++)
        sRandomBattleFacilityBgmBag[i] = FACILITY_BGM_FIRST_TRACK + i;

    for (i = FACILITY_BGM_TRACK_COUNT - 1; i > 0; i--)
    {
        u32 j = Random2_32() % (i + 1);
        u16 temp = sRandomBattleFacilityBgmBag[i];

        sRandomBattleFacilityBgmBag[i] = sRandomBattleFacilityBgmBag[j];
        sRandomBattleFacilityBgmBag[j] = temp;
    }

    // Do not repeat the final track of the previous bag at the boundary.
    if (FACILITY_BGM_TRACK_COUNT > 1
     && sRandomBattleFacilityBgmBag[0] == sLastRandomBattleFacilityBgm)
    {
        u16 temp = sRandomBattleFacilityBgmBag[0];

        sRandomBattleFacilityBgmBag[0] = sRandomBattleFacilityBgmBag[1];
        sRandomBattleFacilityBgmBag[1] = temp;
    }

    sRandomBattleFacilityBgmBagPos = 0;
    sRandomBattleFacilityBgmBagInitialized = TRUE;
}

void BuildBattleFacilityBgmMenu(void)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sBattleFacilityBgmOptions); i++)
    {
        u8 *name = Alloc(64);
        struct ListMenuItem item;

        StringCopy(name, sBattleFacilityBgmOptions[i].name);
        item.name = name;
        item.id = i;
        MultichoiceDynamic_PushElement(item);
    }
}

u16 GetBattleFacilityBgmOverride(void)
{
    u16 choice = VarGet(VAR_BATTLE_FACILITY_BGM);

    if (choice >= ARRAY_COUNT(sBattleFacilityBgmOptions))
    {
        VarSet(VAR_BATTLE_FACILITY_BGM, FACILITY_BGM_DEFAULT);
        return MUS_NONE;
    }

    if (choice == FACILITY_BGM_RANDOM)
    {
        if (!sRandomBattleFacilityBgmBagInitialized
         || sRandomBattleFacilityBgmBagPos >= FACILITY_BGM_TRACK_COUNT)
            ShuffleBattleFacilityBgmBag();
        choice = sRandomBattleFacilityBgmBag[sRandomBattleFacilityBgmBagPos++];
        sLastRandomBattleFacilityBgm = choice;
    }

    return sBattleFacilityBgmOptions[choice].songId;
}
