#include "global.h"
#include "achievements.h"
#include "battle_setup.h"
#include "event_data.h"
#include "field_message_box.h"
#include "field_mugshot.h"
#include "random.h"
#include "title_defense.h"
#include "constants/battle_setup.h"
#include "constants/event_objects.h"
#include "constants/field_mugshots.h"
#include "constants/opponents.h"

static const u8 sText_FalknerIntro[] = _(
    "阿速：冠军可不能\n永远停在地面上！\p我和我的宝可梦，是来看看\n你的实力究竟能飞多高的！$"
    ""
    ""
    "");
static const u8 sText_FalknerDefeat[] = _(
    "你的实力，已经飞到了\n连我的翅膀都够不着的高度！$"
    "");
static const u8 sText_FalknerFarewell[] = _(
    "阿速：冠军头衔依然属于你。\p继续翱翔吧，冠军。我会为了\n下一次飞行继续锻炼的！$"
    ""
    "");

static const u8 sText_BugsyIntro[] = _(
    "阿笔：自从上次对战之后，\n我又学到了好多宝可梦的知识！\p今天我要证明，虫属性宝可梦\n足以挑战任何一位冠军！$"
    ""
    ""
    "");
static const u8 sText_BugsyDefeat[] = _(
    "太厉害了！你的战术\n依然找不到明显的弱点！$"
    "");
static const u8 sText_BugsyFarewell[] = _(
    "阿笔：这场对战给了我\n好多新的研究思路！\p我一定会找到取胜的方法！$"
    ""
    "");

static const u8 sText_WhitneyIntro[] = _(
    "小茜：当冠军看起来\n好好玩哦！\p不过，别以为我们是朋友，\n我就会对你手下留情！$"
    ""
    ""
    "");
static const u8 sText_WhitneyDefeat[] = _(
    "呜哇——！你还是太强了啦！\p……好吧！这场对战很精彩！$"
    "");
static const u8 sText_WhitneyFarewell[] = _(
    "小茜：这场胜利，\n你赢得堂堂正正。\p等我再多锻炼一下，还会再来的！$"
    ""
    "");

static const u8 sText_MortyIntro[] = _(
    "松叶：我曾预见到，有一天\n自己会站在冠军面前。\p就让我们来看看，谁预见的\n胜利会成为现实吧。$"
    ""
    ""
    "");
static const u8 sText_MortyDefeat[] = _(
    "原来这就是在我的预见之外\n等待着的未来……$"
    "");
static const u8 sText_MortyFarewell[] = _(
    "松叶：这个结果我没能预见到。\p看来我的预见能力还得再磨练。$"
    "");

static const u8 sText_ChuckIntro[] = _(
    "阿四：喝啊——！\p为了这次挑战头衔的机会，\n我锻炼了身体和精神！\p做好准备吧，冠军！$"
    ""
    ""
    "");
static const u8 sText_ChuckDefeat[] = _(
    "哇哈哈！你的强大\n震撼到我的心底了！$"
    "");
static const u8 sText_ChuckFarewell[] = _(
    "阿四：了不起的胜利！\p我会加倍努力锻炼，\n再回来和你较量一场！$"
    ""
    "");

static const u8 sText_JasmineIntro[] = _(
    "阿蜜：你的强大\n一直激励着我。\p今天，就由我和身披钢铁的伙伴们\n来亲自考验冠军。$"
    ""
    ""
    "");
static const u8 sText_JasmineDefeat[] = _(
    "你的决心，比最上等的钢铁\n还要坚强……$"
    "");
static const u8 sText_JasmineFarewell[] = _(
    "阿蜜：谢谢你带来了\n这么精彩的对战。\p希望有一天，我也能有\n你一半那么强。$"
    ""
    ""
    "");

static const u8 sText_PryceIntro[] = _(
    "柳伯：光凭经验\n并不能决定对战的胜负。\p让我看看，支撑你背负\n冠军头衔的那份决心吧。$"
    ""
    ""
    "");
static const u8 sText_PryceDefeat[] = _(
    "你那毫不动摇的精神，\n融化了面前的一切阻碍。$"
    "");
static const u8 sText_PryceFarewell[] = _(
    "柳伯：冷静，却绝不温吞。\p这可是很危险的组合。$"
    "");

static const u8 sText_ClairIntro[] = _(
    "小椿：这场再战，\n我已经等得够久了。\p这一次，我要打败你，证明\n谁才是真正的驯龙大师！$"
    ""
    ""
    "");
static const u8 sText_ClairDefeat[] = _(
    "不！即使是最强状态的我，\n你也依然在我之上吗？$"
    "");
static const u8 sText_ClairFarewell[] = _(
    "小椿：哼……头衔就先由你保管。\p我们之间的较量还远没有结束，\n冠军！$"
    ""
    "");

static const u8 sText_LanceIntro[] = _(
    "阿渡：是时候由我来挑战\n曾在这里迎接过的冠军了。\p我和我的龙已经超越了\n从前的极限。来守住你的头衔吧！$"
    ""
    ""
    "");
static const u8 sText_LanceDefeat[] = _(
    "精彩！你已经成长得\n超越了我记忆中的那位冠军。$"
    "");
static const u8 sText_LanceFarewell[] = _(
    "阿渡：联盟依然掌握在\n值得托付的人手中。\p我期待着我们再次\n在对战中相遇的那一天。$"
    ""
    ""
    "");

static const u8 sText_StevenIntro[] = _(
    "大吾：我以收集稀有的石头为业，\n不过冠军的头衔，\p比任何石头都要稀有。\n让我看看它适不适合你吧。$"
    ""
    ""
    "");
static const u8 sText_StevenDefeat[] = _(
    "多么耀眼的对战！你的队伍\n是无与伦比的珍宝。$"
    "");
static const u8 sText_StevenFarewell[] = _(
    "大吾：你的头衔\n丝毫没有失去光彩。\p谢谢你让我见识到它的价值。$"
    ""
    "");

static const u8 sText_ElderLiIntro[] = _(
    "李长老：这么说，你成了冠军啊。\p让我看看，没有了道馆馆主那种\n留手，你是否还像从前那样敏锐。$"
    ""
    "");
static const u8 sText_ElderLiDefeat[] = _(
    "后辈们的光芒\n比以往任何时候都要耀眼！$"
    "");
static const u8 sText_ElderLiFarewell[] = _(
    "李长老：真是精彩的表现。\p那就去吧！整个城都\n都在等着听到你的名字。$"
    ""
    "");

static const u8 sText_DirectorIntro[] = _(
    "局长：嗬嗬嗬！冠军走到哪里\n都是头条新闻啊！\p今天，就让你见识一下\n前四天王成员的实力！$"
    ""
    ""
    "");
static const u8 sText_DirectorDefeat[] = _(
    "真是令人怀念的感觉啊！$");
static const u8 sText_DirectorFarewell[] = _(
    "局长：这场对战接下来几个星期\n都会是城都的热门话题！\p好了，去吧！$"
    ""
    "");

static const u8 sText_LeafIntro[] = _(
    "叶子：嘿，冠军！还记得我吗？\p我说过下次一定会赢你，\n现在就是那个“下次”！\p准备好挨揍吧！$"
    ""
    ""
    "");
static const u8 sText_LeafDefeat[] = _(
    "可恶，你真厉害！\p没想到……又是这样！$"
    "");
static const u8 sText_LeafFarewell[] = _(
    "叶子：你在对战里\n还是强得像个怪物！\p头衔先替我保管好。我还会\n再来挑战的！回头见！$"
    ""
    ""
    "");

const struct TitleDefenseChallenger gTitleDefenseNormalChallengers[] =
{
    { TRAINER_TITLE_DEFENSE_FALKNER, OBJ_EVENT_GFX_FALKNER, sText_FalknerIntro, sText_FalknerDefeat, sText_FalknerFarewell },
    { TRAINER_TITLE_DEFENSE_BUGSY,   OBJ_EVENT_GFX_BUGSY,   sText_BugsyIntro,   sText_BugsyDefeat,   sText_BugsyFarewell },
    { TRAINER_TITLE_DEFENSE_WHITNEY, OBJ_EVENT_GFX_WHITNEY, sText_WhitneyIntro, sText_WhitneyDefeat, sText_WhitneyFarewell },
    { TRAINER_TITLE_DEFENSE_MORTY,   OBJ_EVENT_GFX_MORTY,   sText_MortyIntro,   sText_MortyDefeat,   sText_MortyFarewell },
    { TRAINER_TITLE_DEFENSE_CHUCK,   OBJ_EVENT_GFX_CHUCK,   sText_ChuckIntro,   sText_ChuckDefeat,   sText_ChuckFarewell },
    { TRAINER_TITLE_DEFENSE_JASMINE, OBJ_EVENT_GFX_JASMINE, sText_JasmineIntro, sText_JasmineDefeat, sText_JasmineFarewell },
    { TRAINER_TITLE_DEFENSE_PRYCE,   OBJ_EVENT_GFX_PRYCE,   sText_PryceIntro,   sText_PryceDefeat,   sText_PryceFarewell },
    { TRAINER_TITLE_DEFENSE_CLAIR,   OBJ_EVENT_GFX_CLAIR,   sText_ClairIntro,   sText_ClairDefeat,   sText_ClairFarewell },
};

const struct TitleDefenseChallenger gTitleDefenseHardChallengers[] =
{
    { TRAINER_TITLE_DEFENSE_LANCE,    OBJ_EVENT_GFX_LANCE,     sText_LanceIntro,    sText_LanceDefeat,    sText_LanceFarewell },
    { TRAINER_TITLE_DEFENSE_STEVEN,   OBJ_EVENT_GFX_STEVEN,    sText_StevenIntro,   sText_StevenDefeat,   sText_StevenFarewell },
    { TRAINER_TITLE_DEFENSE_ELDER_LI, OBJ_EVENT_GFX_EXPERT_M,  sText_ElderLiIntro,  sText_ElderLiDefeat,  sText_ElderLiFarewell },
    { TRAINER_TITLE_DEFENSE_DIRECTOR, OBJ_EVENT_GFX_GENTLEMAN, sText_DirectorIntro, sText_DirectorDefeat, sText_DirectorFarewell },
    { TRAINER_TITLE_DEFENSE_LEAF,     OBJ_EVENT_GFX_LEAF,      sText_LeafIntro,     sText_LeafDefeat,     sText_LeafFarewell },
};

const u32 gTitleDefenseNormalChallengerCount = ARRAY_COUNT(gTitleDefenseNormalChallengers);
const u32 gTitleDefenseHardChallengerCount = ARRAY_COUNT(gTitleDefenseHardChallengers);

static const struct TitleDefenseChallenger *GetChallengerByPoolIndex(u32 index)
{
    if (index < gTitleDefenseNormalChallengerCount)
        return &gTitleDefenseNormalChallengers[index];

    index -= gTitleDefenseNormalChallengerCount;
    if (index < gTitleDefenseHardChallengerCount)
        return &gTitleDefenseHardChallengers[index];

    return NULL;
}

static const struct TitleDefenseChallenger *FindChallenger(u16 trainerId)
{
    u32 i;

    for (i = 0; i < gTitleDefenseNormalChallengerCount; i++)
    {
        if (gTitleDefenseNormalChallengers[i].trainerId == trainerId)
            return &gTitleDefenseNormalChallengers[i];
    }

    for (i = 0; i < gTitleDefenseHardChallengerCount; i++)
    {
        if (gTitleDefenseHardChallengers[i].trainerId == trainerId)
            return &gTitleDefenseHardChallengers[i];
    }

    return NULL;
}

const struct TitleDefenseChallenger *TitleDefense_GetCurrentChallenger(void)
{
    const struct TitleDefenseChallenger *challenger = FindChallenger(VarGet(VAR_TITLE_DEFENSE_LAST_CHALLENGER));

    if (challenger == NULL)
        challenger = &gTitleDefenseNormalChallengers[0];
    return challenger;
}

u16 TitleDefense_GetCurrentMugshotId(void)
{
    const struct TitleDefenseChallenger *challenger = TitleDefense_GetCurrentChallenger();

    if (challenger->trainerId == TRAINER_TITLE_DEFENSE_ELDER_LI)
        return MUGSHOT_ELDER_LI;

    return GetFieldMugshotIdByObjectGraphicsId(challenger->objectGfxId);
}

static void ShowChallengerMessage(const u8 *text)
{
    u16 mugshotId = TitleDefense_GetCurrentMugshotId();

    if (mugshotId == MUGSHOT_NONE)
        RemoveFieldMugshot();
    else
        _CreateFieldMugshot(mugshotId, EMOTE_NORMAL);
    ShowFieldMessage(text);
}

void TitleDefense_SelectChallenger(void)
{
    const struct TitleDefenseChallenger *challenger;
    u32 poolCount;
    u32 selectableCount;
    u32 selectedIndex;
    u32 i;
    u16 lastTrainerId = VarGet(VAR_TITLE_DEFENSE_LAST_CHALLENGER);
    bool32 excludeLast = FALSE;

    poolCount = gTitleDefenseNormalChallengerCount;
    if (VarGet(VAR_TITLE_DEFENSE_WINS) >= 5)
        poolCount += gTitleDefenseHardChallengerCount;

    if (poolCount > 1)
    {
        for (i = 0; i < poolCount; i++)
        {
            const struct TitleDefenseChallenger *candidate = GetChallengerByPoolIndex(i);

            if (candidate->trainerId == lastTrainerId)
            {
                excludeLast = TRUE;
                break;
            }
        }
    }

    selectableCount = poolCount - excludeLast;
    selectedIndex = RandomUniform(RNG_TITLE_DEFENSE_CHALLENGER, 0, selectableCount - 1);
    challenger = NULL;
    for (i = 0; i < poolCount; i++)
    {
        const struct TitleDefenseChallenger *candidate = GetChallengerByPoolIndex(i);

        if (excludeLast && candidate->trainerId == lastTrainerId)
            continue;
        if (selectedIndex == 0)
        {
            challenger = candidate;
            break;
        }
        selectedIndex--;
    }

    if (challenger == NULL)
        challenger = &gTitleDefenseNormalChallengers[0];

    VarSet(VAR_TITLE_DEFENSE_LAST_CHALLENGER, challenger->trainerId);
    VarSet(VAR_OBJ_GFX_ID_0, challenger->objectGfxId);
}

void TitleDefense_ShowIntro(void)
{
    ShowChallengerMessage(TitleDefense_GetCurrentChallenger()->introText);
}

void TitleDefense_ShowFarewell(void)
{
    ShowChallengerMessage(TitleDefense_GetCurrentChallenger()->farewellText);
}

void TitleDefense_PrepareBattle(void)
{
    const struct TitleDefenseChallenger *challenger = TitleDefense_GetCurrentChallenger();

    InitTrainerBattleParameter();
    TRAINER_BATTLE_PARAM.mode = TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT;
    TRAINER_BATTLE_PARAM.playMusicA = TRUE;
    TRAINER_BATTLE_PARAM.opponentA = challenger->trainerId;
    TRAINER_BATTLE_PARAM.opponentB = TRAINER_NONE;
    TRAINER_BATTLE_PARAM.defeatTextA = (u8 *)challenger->defeatText;
}

void TitleDefense_IncrementWins(void)
{
    u16 wins = VarGet(VAR_TITLE_DEFENSE_WINS);

    if (wins < MAX_u16)
        VarSet(VAR_TITLE_DEFENSE_WINS, wins + 1);
    Achievement_CheckCounter(ACH_COUNTER_TITLE_DEFENSE_WINS);
}
