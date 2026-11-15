#include "global.h"
#include "achievements.h"
#include "event_data.h"
#include "item.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "pokedex.h"
#include "overworld.h"
#include "string_util.h"
#include "constants/battle_frontier.h"
#include "constants/flags.h"
#include "constants/game_stat.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/opponents.h"
#include "constants/species.h"
#include "constants/vars.h"

#define TRAINER_NONE_ACH 0xFFFF

STATIC_ASSERT(ITEM_BONDSTONE - ITEM_NORMALITE < 32, MegaCollectorItemsFitInBitset);

static bool32 Achievement_PredicateHoennDexComplete(void);
static bool32 Achievement_PredicateCameronPhoto(void);
static bool32 Achievement_PredicateAllCameronPhotos(void);
static bool32 Achievement_PredicateBuenaSuperfan(void);
static bool32 Achievement_PredicateTravellingHealer(void);
static bool32 Achievement_PredicateKurtMasterBall(void);
static bool32 Achievement_PredicateMegaCollector(void);
static bool32 Achievement_PredicateMasterOfMoves(void);
static bool32 Achievement_PredicateCaughtRayquaza(void);
static bool32 Achievement_PredicateCaughtLugia(void);
static bool32 Achievement_PredicateCaughtHoOh(void);
static bool32 Achievement_PredicateZephyrBadge(void);
static bool32 Achievement_PredicateHiveBadge(void);
static bool32 Achievement_PredicatePlainBadge(void);
static bool32 Achievement_PredicateFogBadge(void);
static bool32 Achievement_PredicateStormBadge(void);
static bool32 Achievement_PredicateMineralBadge(void);
static bool32 Achievement_PredicateGlacierBadge(void);
static bool32 Achievement_PredicateRisingBadge(void);
static bool32 Achievement_PredicateRouteExperts(void);
static bool32 Achievement_PredicateCaughtCelebi(void);
static bool32 Achievement_PredicateCaughtRegice(void);
static bool32 Achievement_PredicateCaughtRegisteel(void);
static bool32 Achievement_PredicateCaughtRegirock(void);
static bool32 Achievement_PredicateCaughtRegigigas(void);
static bool32 Achievement_PredicateCaughtChienPao(void);
static bool32 Achievement_PredicateCaughtHeatran(void);
static bool32 Achievement_PredicateCaughtOgerpon(void);
static bool32 Achievement_PredicateCaughtMesprit(void);
static bool32 Achievement_PredicateCaughtUxie(void);
static bool32 Achievement_PredicateCaughtAzelf(void);
static bool32 Achievement_PredicateCaughtLapras(void);
static bool32 Achievement_PredicateCaughtVictini(void);
static bool32 Achievement_PredicateCaughtPhione(void);
static bool32 Achievement_PredicateCaughtMewtwo(void);
static bool32 Achievement_PredicateCaughtMew(void);
static bool32 Achievement_PredicateCaughtSuicune(void);
static bool32 Achievement_PredicateCaughtEntei(void);
static bool32 Achievement_PredicateCaughtRaikou(void);
static bool32 Achievement_PredicateCaughtKyogre(void);
static bool32 Achievement_PredicateCaughtGroudon(void);
static bool32 Achievement_PredicateCaughtEonDuo(void);
static bool32 Achievement_PredicateCaughtJirachi(void);
static bool32 Achievement_PredicateCaughtHoopa(void);
static bool32 Achievement_PredicateCaughtDialga(void);
static bool32 Achievement_PredicateCaughtPalkia(void);
static bool32 Achievement_PredicateCaughtGiratina(void);
static bool32 Achievement_PredicateCaughtCresselia(void);
static bool32 Achievement_PredicateCaughtDarkrai(void);
static bool32 Achievement_PredicateCaughtShaymin(void);
static bool32 Achievement_PredicateAllOtherTrophies(void);
static bool32 Achievement_PredicateCaughtMagearna(void);
static bool32 Achievement_PredicateCaughtMarshadow(void);
static bool32 Achievement_PredicateCaughtCobalion(void);
static bool32 Achievement_PredicateCaughtTerrakion(void);
static bool32 Achievement_PredicateCaughtVirizion(void);
static bool32 Achievement_PredicateCaughtMeloetta(void);
static bool32 Achievement_PredicateCaughtZeraora(void);
static bool32 Achievement_PredicateObtainedGalarianBirds(void);
static bool32 Achievement_PredicateObtainedWeatherGenies(void);
static bool32 Achievement_PredicateObtainedTapus(void);
static bool32 Achievement_PredicateObtainedParadoxLegends(void);
static bool32 Achievement_PredicateCaughtAllParadoxPokemon(void);
static bool32 Achievement_PredicateHasLevel100Pokemon(void);
static bool32 Achievement_IsInScaledChaosFacility(void);
static u32 Achievement_CountCollectedTMs(void);
static u32 Achievement_GetBestBattlePyramidFloorStreak(void);
static void Achievement_QueuePopup(enum AchievementId id);

static const u8 sText_AchReceiveStarterName[] = _("就决定是你了！");
static const u8 sText_AchReceiveStarterDesc[] = _("获得你的第一只伙伴宝可梦。");
static const u8 sText_AchFirstCaptureName[] = _("初次捕获");
static const u8 sText_AchFirstCaptureDesc[] = _("用精灵球捕获你的第一只宝可梦。");
static const u8 sText_AchFirstCriticalName[] = _("幸运一击");
static const u8 sText_AchFirstCriticalDesc[] = _("首次击中要害。");
static const u8 sText_AchCritical100Name[] = _("会心达人");
static const u8 sText_AchCritical100Desc[] = _("击中要害100次。");
static const u8 sText_AchCapture100Name[] = _("收藏家");
static const u8 sText_AchCapture100Desc[] = _("捕获100只宝可梦。");
static const u8 sText_AchCaptureShinyName[] = _("稀有闪光");
static const u8 sText_AchCaptureShinyDesc[] = _("捕获一只异色宝可梦。");
static const u8 sText_AchDaycareEgg1Name[] = _("新生命");
static const u8 sText_AchDaycareEgg1Desc[] = _("从培育屋获得一枚蛋。");
static const u8 sText_AchDaycareEggs100Name[] = _("培育屋常客");
static const u8 sText_AchDaycareEggs100Desc[] = _("从培育屋获得30枚蛋。");
static const u8 sText_AchHatchEggs100Name[] = _("破壳高手");
static const u8 sText_AchHatchEggs100Desc[] = _("孵化30枚蛋。");
static const u8 sText_AchTower25Name[] = _("对战塔挑战者");
static const u8 sText_AchTower25Desc[] = _("在对战塔累计获胜25场。");
static const u8 sText_AchTower50Name[] = _("对战塔高手");
static const u8 sText_AchTower50Desc[] = _("在对战塔累计获胜50场。");
static const u8 sText_AchTower100Name[] = _("对战塔大师");
static const u8 sText_AchTower100Desc[] = _("在对战塔累计获胜100场。");
static const u8 sText_AchHoennDexName[] = _("城都博士");
static const u8 sText_AchHoennDexDesc[] = _("完成城都图鉴。\n(不含传说的宝可梦与幻之宝可梦)");
static const u8 sText_AchSayCheeseName[] = _("说“茄子”！");
static const u8 sText_AchSayCheeseDesc[] = _("请显影为你的队伍拍照。");
static const u8 sText_AchBloodMoonName[] = _("血月");
static const u8 sText_AchBloodMoonDesc[] = _("捕获血月月月熊。");
static const u8 sText_AchRayquazaName[] = _("天空霸主");
static const u8 sText_AchRayquazaDesc[] = _("捕获烈空坐。");
static const u8 sText_AchPlantBerries10Name[] = _("园艺好手");
static const u8 sText_AchPlantBerries10Desc[] = _("种下10颗树果。");
static const u8 sText_AchTm1Name[] = _("招式学习器学徒");
static const u8 sText_AchTm1Desc[] = _("获得你的第一个招式学习器。");
static const u8 sText_AchTm20Name[] = _("招式学习器追寻者");
static const u8 sText_AchTm20Desc[] = _("收集20个招式学习器。");
static const u8 sText_AchTm50Name[] = _("招式学习器高手");
static const u8 sText_AchTm50Desc[] = _("收集50个招式学习器。");
static const u8 sText_AchTm100Name[] = _("招式学习器大师");
static const u8 sText_AchTm100Desc[] = _("收集100个招式学习器。");
static const u8 sText_AchPokedex200Name[] = _("野外研究员");
static const u8 sText_AchPokedex200Desc[] = _("登记200只已捕获的宝可梦。");
static const u8 sText_AchPokedex350Name[] = _("图鉴专家");
static const u8 sText_AchPokedex350Desc[] = _("登记350只已捕获的宝可梦。");
static const u8 sText_AchPokedex500Name[] = _("行走图鉴");
static const u8 sText_AchPokedex500Desc[] = _("登记500只已捕获的宝可梦。");
static const u8 sText_AchRocketArcade25Name[] = _("游戏城玩家");
static const u8 sText_AchRocketArcade25Desc[] = _("在火箭游戏城累计获胜25场。");
static const u8 sText_AchRocketArcade50Name[] = _("游戏城王牌");
static const u8 sText_AchRocketArcade50Desc[] = _("在火箭游戏城累计获胜50场。");
static const u8 sText_AchRocketArcade100Name[] = _("游戏城传说");
static const u8 sText_AchRocketArcade100Desc[] = _("在火箭游戏城累计获胜100场。");
static const u8 sText_AchFactory25Name[] = _("对战工厂挑战者");
static const u8 sText_AchFactory25Desc[] = _("在对战工厂累计获胜25场。");
static const u8 sText_AchFactory50Name[] = _("对战工厂高手");
static const u8 sText_AchFactory50Desc[] = _("在对战工厂累计获胜50场。");
static const u8 sText_AchFactory100Name[] = _("对战工厂大师");
static const u8 sText_AchFactory100Desc[] = _("在对战工厂累计获胜100场。");
static const u8 sText_AchPyramid3Name[] = _("金字塔探险家");
static const u8 sText_AchPyramid3Desc[] = _("通关对战金字塔3轮。");
static const u8 sText_AchPyramid10Name[] = _("金字塔高手");
static const u8 sText_AchPyramid10Desc[] = _("通关对战金字塔6轮。");
static const u8 sText_AchPyramid20Name[] = _("金字塔大师");
static const u8 sText_AchPyramid20Desc[] = _("通关对战金字塔10轮。");
static const u8 sText_AchCatchLugiaName[] = _("海之守护者");
static const u8 sText_AchCatchLugiaDesc[] = _("捕获洛奇亚。");
static const u8 sText_AchCatchHoOhName[] = _("彩虹守护者");
static const u8 sText_AchCatchHoOhDesc[] = _("捕获凤王。");
static const u8 sText_AchZephyrBadgeName[] = _("折翼");
static const u8 sText_AchZephyrBadgeDesc[] = _("击败阿速，\n获得飞翼徽章。");
static const u8 sText_AchHiveBadgeName[] = _("破巢者");
static const u8 sText_AchHiveBadgeDesc[] = _("击败阿笔，获得昆虫徽章。");
static const u8 sText_AchPlainBadgeName[] = _("碾压");
static const u8 sText_AchPlainBadgeDesc[] = _("击败小茜，\n获得标准徽章。");
static const u8 sText_AchFogBadgeName[] = _("拨开迷雾");
static const u8 sText_AchFogBadgeDesc[] = _("击败松叶，获得魅影徽章。");
static const u8 sText_AchStormBadgeName[] = _("实力证明");
static const u8 sText_AchStormBadgeDesc[] = _("击败阿四，获得暴风徽章。");
static const u8 sText_AchMineralBadgeName[] = _("钢铁之雅");
static const u8 sText_AchMineralBadgeDesc[] = _("击败阿蜜，\n获得矿物徽章。");
static const u8 sText_AchGlacierBadgeName[] = _("破冰者");
static const u8 sText_AchGlacierBadgeDesc[] = _("击败柳伯，\n获得冰河徽章。");
static const u8 sText_AchRisingBadgeName[] = _("登上巅峰");
static const u8 sText_AchRisingBadgeDesc[] = _("击败小椿后，\n获得升龙徽章。");
static const u8 sText_AchFalknerRematchName[] = _("羽翼落地");
static const u8 sText_AchFalknerRematchDesc[] = _("击败阿速的再战。");
static const u8 sText_AchBugsyRematchName[] = _("灭虫者");
static const u8 sText_AchBugsyRematchDesc[] = _("击败阿笔的再战。");
static const u8 sText_AchWhitneyRematchName[] = _("二次践踏");
static const u8 sText_AchWhitneyRematchDesc[] = _("击败小茜的再战。");
static const u8 sText_AchMortyRematchName[] = _("幽灵克星");
static const u8 sText_AchMortyRematchDesc[] = _("击败松叶的再战。");
static const u8 sText_AchChuckRematchName[] = _("摔角手");
static const u8 sText_AchChuckRematchDesc[] = _("击败阿四的再战。");
static const u8 sText_AchJasmineRematchName[] = _("钢铁之心");
static const u8 sText_AchJasmineRematchDesc[] = _("击败阿蜜的再战。");
static const u8 sText_AchPryceRematchName[] = _("冷酷之心");
static const u8 sText_AchPryceRematchDesc[] = _("击败柳伯的再战。");
static const u8 sText_AchClairRematchName[] = _("驯龙大师");
static const u8 sText_AchClairRematchDesc[] = _("击败小椿的再战。");
static const u8 sText_AchLetsGoName[] = _("走吧！");
static const u8 sText_AchLetsGoDesc[] = _("获得伊布或皮卡丘\n作为初始伙伴。");
static const u8 sText_AchRouteExpertsName[] = _("换我当专家");
static const u8 sText_AchRouteExpertsDesc[] = _("击败所有路线专家。");
static const u8 sText_AchHallOfFameDebutName[] = _("冠军");
static const u8 sText_AchHallOfFameDebutDesc[] = _("首次进入名人堂。");
static const u8 sText_AchTitleDefenderName[] = _("卫冕者");
static const u8 sText_AchTitleDefenderDesc[] = _("卫冕冠军头衔1次。");
static const u8 sText_AchLongTermCareerName[] = _("长期事业");
static const u8 sText_AchLongTermCareerDesc[] = _("卫冕冠军头衔5次。");
static const u8 sText_AchUndefeatedChampionName[] = _("不败冠军");
static const u8 sText_AchUndefeatedChampionDesc[] = _("卫冕冠军头衔10次。");
static const u8 sText_AchBuenaSuperfanName[] = _("葵妍超级粉丝");
static const u8 sText_AchBuenaSuperfanDesc[] = _("在3天里答对\n葵妍的暗语。");
static const u8 sText_AchTravellingHealerName[] = _("巡回治疗师");
static const u8 sText_AchTravellingHealerDesc[] = _("治疗39号道路\n牧场里的大奶罐。");
static const u8 sText_AchMasterpieceName[] = _("杰作");
static const u8 sText_AchMasterpieceDesc[] = _("请钢铁为你制作\n一个大师球。");
static const u8 sText_AchUnderTheSeaName[] = _("海底世界");
static const u8 sText_AchUnderTheSeaDesc[] = _("钓上一只霏欧纳。");
static const u8 sText_AchMegaCollectorName[] = _("超级石收藏家");
static const u8 sText_AchMegaCollectorDesc[] = _("获得所有种类的超级石\n以及牵绊石。");
static const u8 sText_AchMasterOfMovesName[] = _("招式大师");
static const u8 sText_AchMasterOfMovesDesc[] = _("永久解锁蛋招式和\n教学招式。");
static const u8 sText_AchCatchCelebiName[] = _("森林守护者");
static const u8 sText_AchCatchCelebiDesc[] = _("捕获时拉比。");
static const u8 sText_AchCatchArticunoName[] = _("冰封传说");
static const u8 sText_AchCatchArticunoDesc[] = _("捕获急冻鸟。");
static const u8 sText_AchCatchMoltresName[] = _("火焰传说");
static const u8 sText_AchCatchMoltresDesc[] = _("捕获火焰鸟。");
static const u8 sText_AchCatchZapdosName[] = _("风暴传说");
static const u8 sText_AchCatchZapdosDesc[] = _("捕获闪电鸟。");
static const u8 sText_AchCatchRegiceName[] = _("冰之解封");
static const u8 sText_AchCatchRegiceDesc[] = _("捕获雷吉艾斯。");
static const u8 sText_AchCatchRegisteelName[] = _("钢之解封");
static const u8 sText_AchCatchRegisteelDesc[] = _("捕获雷吉斯奇鲁。");
static const u8 sText_AchCatchRegirockName[] = _("岩之解封");
static const u8 sText_AchCatchRegirockDesc[] = _("捕获雷吉洛克。");
static const u8 sText_AchCatchRegigigasName[] = _("远古苏醒");
static const u8 sText_AchCatchRegigigasDesc[] = _("捕获雷吉奇卡斯。");
static const u8 sText_AchCatchChienPaoName[] = _("灾祸之剑");
static const u8 sText_AchCatchChienPaoDesc[] = _("捕获古剑豹。");
static const u8 sText_AchCatchHeatranName[] = _("灼热之面");
static const u8 sText_AchCatchHeatranDesc[] = _("捕获席多蓝恩。");
static const u8 sText_AchCatchOgerponName[] = _("面具之友");
static const u8 sText_AchCatchOgerponDesc[] = _("捕获厄诡椪。");
static const u8 sText_AchCatchMespritName[] = _("情感之存在");
static const u8 sText_AchCatchMespritDesc[] = _("捕获艾姆利多。");
static const u8 sText_AchCatchUxieName[] = _("知识之存在");
static const u8 sText_AchCatchUxieDesc[] = _("捕获由克希。");
static const u8 sText_AchCatchAzelfName[] = _("意志之存在");
static const u8 sText_AchCatchAzelfDesc[] = _("捕获亚克诺姆。");
static const u8 sText_AchCatchMewtwoName[] = _("实验体");
static const u8 sText_AchCatchMewtwoDesc[] = _("捕获超梦。");
static const u8 sText_AchCatchMewName[] = _("原初");
static const u8 sText_AchCatchMewDesc[] = _("捕获梦幻。");
static const u8 sText_AchCatchSuicuneName[] = _("漂泊之风");
static const u8 sText_AchCatchSuicuneDesc[] = _("捕获水君。");
static const u8 sText_AchCatchEnteiName[] = _("漂泊之吼");
static const u8 sText_AchCatchEnteiDesc[] = _("捕获炎帝。");
static const u8 sText_AchCatchRaikouName[] = _("漂泊之雷");
static const u8 sText_AchCatchRaikouDesc[] = _("捕获雷公。");
static const u8 sText_AchCatchKyogreName[] = _("原始之海");
static const u8 sText_AchCatchKyogreDesc[] = _("捕获盖欧卡。");
static const u8 sText_AchCatchGroudonName[] = _("原始大地");
static const u8 sText_AchCatchGroudonDesc[] = _("捕获固拉多。");
static const u8 sText_AchCatchEonDuoName[] = _("无限双星");
static const u8 sText_AchCatchEonDuoDesc[] = _("同时捕获拉帝亚斯与拉帝欧斯。");
static const u8 sText_AchObtainJirachiName[] = _("向星许愿");
static const u8 sText_AchObtainJirachiDesc[] = _("获得基拉祈。");
static const u8 sText_AchCatchHoopaName[] = _("闯入者");
static const u8 sText_AchCatchHoopaDesc[] = _("捕获胡帕。");
static const u8 sText_AchCatchDialgaName[] = _("时间守护者");
static const u8 sText_AchCatchDialgaDesc[] = _("捕获帝牙卢卡。");
static const u8 sText_AchCatchPalkiaName[] = _("空间守护者");
static const u8 sText_AchCatchPalkiaDesc[] = _("捕获帕路奇亚。");
static const u8 sText_AchCatchGiratinaName[] = _("深渊之主");
static const u8 sText_AchCatchGiratinaDesc[] = _("捕获骑拉帝纳。");
static const u8 sText_AchCatchCresseliaName[] = _("美梦");
static const u8 sText_AchCatchCresseliaDesc[] = _("捕获克雷色利亚。");
static const u8 sText_AchCatchDarkraiName[] = _("噩梦终结");
static const u8 sText_AchCatchDarkraiDesc[] = _("捕获达克莱伊。");
static const u8 sText_AchObtainShayminName[] = _("绽放之花");
static const u8 sText_AchObtainShayminDesc[] = _("获得谢米。");
static const u8 sText_AchParadoxicalName[] = _("悖谬");
static const u8 sText_AchParadoxicalDesc[] = _("捕获所有悖谬宝可梦。");
static const u8 sText_AchMasterOfJohtoName[] = _("城都大师");
static const u8 sText_AchMasterOfJohtoDesc[] = _("获得所有奖杯。");
static const u8 sText_AchCatchLaprasName[] = _("温柔的旅人");
static const u8 sText_AchCatchLaprasDesc[] = _("捕获拉普拉斯。");
static const u8 sText_AchObtainVictiniName[] = _("胜利之星");
static const u8 sText_AchObtainVictiniDesc[] = _("击败所有道馆馆主完成再战后，\n获得比克提尼。");
static const u8 sText_AchCatchCobalionName[] = _("铁之正义");
static const u8 sText_AchCatchCobalionDesc[] = _("捕获勾帕路翁。");
static const u8 sText_AchCatchTerrakionName[] = _("石之正义");
static const u8 sText_AchCatchTerrakionDesc[] = _("捕获代拉基翁。");
static const u8 sText_AchCatchVirizionName[] = _("翠之正义");
static const u8 sText_AchCatchVirizionDesc[] = _("捕获毕力吉翁。");
static const u8 sText_AchCatchMeloettaName[] = _("旋转旋律");
static const u8 sText_AchCatchMeloettaDesc[] = _("捕获美洛耶塔。");
static const u8 sText_AchCatchZeraoraName[] = _("迅雷");
static const u8 sText_AchCatchZeraoraDesc[] = _("捕获捷拉奥拉。");
static const u8 sText_AchObtainDiancieName[] = _("王冠宝石");
static const u8 sText_AchObtainDiancieDesc[] = _("获得蒂安希。");
static const u8 sText_AchObtainGalarianBirdsName[] = _("伽勒尔特辑");
static const u8 sText_AchObtainGalarianBirdsDesc[] = _("获得伽勒尔地区的\n三只传说鸟宝可梦。");
static const u8 sText_AchMasterOfWishesName[] = _("愿望大师");
static const u8 sText_AchMasterOfWishesDesc[] = _("获得四只化身宝可梦。");
static const u8 sText_AchObtainTapusName[] = _("岛屿守护者");
static const u8 sText_AchObtainTapusDesc[] = _("获得四位守护神。");
static const u8 sText_AchObtainParadoxLegendsName[] = _("跨越时代");
static const u8 sText_AchObtainParadoxLegendsDesc[] = _("同时获得故勒顿与密勒顿。");
static const u8 sText_AchDefeatStevenName[] = _("矿物学");
static const u8 sText_AchDefeatStevenDesc[] = _("击败其他地区的\n冠军。");
static const u8 sText_AchAutophotographerName[] = _("自拍摄影师");
static const u8 sText_AchAutophotographerDesc[] = _("让显影在全部五个地点\n为你的队伍拍照。");
static const u8 sText_AchMillionaireName[] = _("百万富翁");
static const u8 sText_AchMillionaireDesc[] = _("累计赚取¥1,000,000。");
static const u8 sText_AchSpendthriftName[] = _("挥金如土");
static const u8 sText_AchSpendthriftDesc[] = _("累计花费¥1,000,000。");
static const u8 sText_AchBattleConnoisseurName[] = _("对战行家");
static const u8 sText_AchBattleConnoisseurDesc[] = _("累计获得100对战点数。");
static const u8 sText_AchPeakOfPowerName[] = _("力量巅峰");
static const u8 sText_AchPeakOfPowerDesc[] = _("将一只宝可梦培育到Lv. 100。");
static const u8 sText_AchGainingPowerName[] = _("力量增长");
static const u8 sText_AchGainingPowerDesc[] = _("让25只宝可梦进化。");
static const u8 sText_AchCatchMagearnaName[] = _("机械之心");
static const u8 sText_AchCatchMagearnaDesc[] = _("捕获玛机雅娜。");
static const u8 sText_AchCatchMarshadowName[] = _("神圣之影");
static const u8 sText_AchCatchMarshadowDesc[] = _("捕获玛夏多。");
static const u8 sText_AchBugCatcherName[] = _("捕虫少年");
static const u8 sText_AchBugCatcherDesc[] = _("在捕虫大赛中获得\n第一名。");
static const u8 sText_AchBattleCafeDailyName[] = _("咖啡常客");
static const u8 sText_AchBattleCafeDailyDesc[] = _("通关对战咖啡馆的每日挑战。");
static const u8 sText_AchBattleCafeRushName[] = _("高峰时段");
static const u8 sText_AchBattleCafeRushDesc[] = _("通关对战咖啡馆的冲刺模式。");
static const u8 sText_AchBattleCafeSuperChallengeName[] = _("全套餐");
static const u8 sText_AchBattleCafeSuperChallengeDesc[] = _("通关对战咖啡馆的超级挑战。");
static const u8 sText_AchBattleCafeEndlessMasterName[] = _("无尽大师");
static const u8 sText_AchBattleCafeEndlessMasterDesc[] = _("在无尽挑战中取得15连胜。");

static const u8 sText_TierBronze[] = _("精灵球");
static const u8 sText_TierSilver[] = _("超级球");
static const u8 sText_TierGold[] = _("高级球");
static const u8 sText_TierPlatinum[] = _("大师球");

static const struct Achievement sAchievements[] =
{
    // Common, easy achievements
    {ACH_RECEIVE_STARTER, sText_AchReceiveStarterName, sText_AchReceiveStarterDesc, ACH_TIER_BRONZE, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, NULL},
    {ACH_FIRST_CAPTURE, sText_AchFirstCaptureName, sText_AchFirstCaptureDesc, ACH_TIER_BRONZE, ACH_COUNTER_CAPTURED_MONS, 1, TRAINER_NONE_ACH, NULL},
    {ACH_FIRST_CRITICAL, sText_AchFirstCriticalName, sText_AchFirstCriticalDesc, ACH_TIER_BRONZE, ACH_COUNTER_CRITICAL_HITS, 1, TRAINER_NONE_ACH, NULL},
    {ACH_DAYCARE_EGG_1, sText_AchDaycareEgg1Name, sText_AchDaycareEgg1Desc, ACH_TIER_BRONZE, ACH_COUNTER_DAYCARE_EGGS, 1, TRAINER_NONE_ACH, NULL},
    {ACH_LETS_GO, sText_AchLetsGoName, sText_AchLetsGoDesc, ACH_TIER_SILVER, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, NULL},
    {ACH_SAY_CHEESE, sText_AchSayCheeseName, sText_AchSayCheeseDesc, ACH_TIER_BRONZE, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCameronPhoto},
    {ACH_JOHTO_BADGE_ZEPHYR, sText_AchZephyrBadgeName, sText_AchZephyrBadgeDesc, ACH_TIER_BRONZE, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateZephyrBadge},
    {ACH_JOHTO_BADGE_HIVE, sText_AchHiveBadgeName, sText_AchHiveBadgeDesc, ACH_TIER_BRONZE, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateHiveBadge},
    {ACH_JOHTO_BADGE_PLAIN, sText_AchPlainBadgeName, sText_AchPlainBadgeDesc, ACH_TIER_BRONZE, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicatePlainBadge},
    {ACH_JOHTO_BADGE_FOG, sText_AchFogBadgeName, sText_AchFogBadgeDesc, ACH_TIER_BRONZE, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateFogBadge},
    {ACH_JOHTO_BADGE_STORM, sText_AchStormBadgeName, sText_AchStormBadgeDesc, ACH_TIER_SILVER, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateStormBadge},
    {ACH_JOHTO_BADGE_MINERAL, sText_AchMineralBadgeName, sText_AchMineralBadgeDesc, ACH_TIER_SILVER, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateMineralBadge},
    {ACH_JOHTO_BADGE_GLACIER, sText_AchGlacierBadgeName, sText_AchGlacierBadgeDesc, ACH_TIER_SILVER, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateGlacierBadge},
    {ACH_JOHTO_BADGE_RISING, sText_AchRisingBadgeName, sText_AchRisingBadgeDesc, ACH_TIER_SILVER, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateRisingBadge},
    {ACH_HALL_OF_FAME_DEBUT, sText_AchHallOfFameDebutName, sText_AchHallOfFameDebutDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, NULL},
    {ACH_TITLE_DEFENDER, sText_AchTitleDefenderName, sText_AchTitleDefenderDesc, ACH_TIER_SILVER, ACH_COUNTER_TITLE_DEFENSE_WINS, 1, TRAINER_NONE_ACH, NULL},
    {ACH_LONG_TERM_CAREER, sText_AchLongTermCareerName, sText_AchLongTermCareerDesc, ACH_TIER_GOLD, ACH_COUNTER_TITLE_DEFENSE_WINS, 5, TRAINER_NONE_ACH, NULL},
    {ACH_UNDEFEATED_CHAMPION, sText_AchUndefeatedChampionName, sText_AchUndefeatedChampionDesc, ACH_TIER_PLATINUM, ACH_COUNTER_TITLE_DEFENSE_WINS, 10, TRAINER_NONE_ACH, NULL},
    {ACH_CATCH_LAPRAS, sText_AchCatchLaprasName, sText_AchCatchLaprasDesc, ACH_TIER_SILVER, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtLapras},

    // Miscellaneous achievements
    {ACH_CRITICAL_100, sText_AchCritical100Name, sText_AchCritical100Desc, ACH_TIER_SILVER, ACH_COUNTER_CRITICAL_HITS, 100, TRAINER_NONE_ACH, NULL},
    {ACH_CAPTURE_100, sText_AchCapture100Name, sText_AchCapture100Desc, ACH_TIER_SILVER, ACH_COUNTER_CAPTURED_MONS, 100, TRAINER_NONE_ACH, NULL},
    {ACH_CAPTURE_SHINY, sText_AchCaptureShinyName, sText_AchCaptureShinyDesc, ACH_TIER_GOLD, ACH_COUNTER_SHINY_CAPTURES, 1, TRAINER_NONE_ACH, NULL},
    {ACH_DAYCARE_EGGS_100, sText_AchDaycareEggs100Name, sText_AchDaycareEggs100Desc, ACH_TIER_GOLD, ACH_COUNTER_DAYCARE_EGGS, 30, TRAINER_NONE_ACH, NULL},
    {ACH_HATCH_EGGS_100, sText_AchHatchEggs100Name, sText_AchHatchEggs100Desc, ACH_TIER_GOLD, ACH_COUNTER_HATCHED_EGGS, 30, TRAINER_NONE_ACH, NULL},
    {ACH_TM_1, sText_AchTm1Name, sText_AchTm1Desc, ACH_TIER_BRONZE, ACH_COUNTER_TMS_COLLECTED, 1, TRAINER_NONE_ACH, NULL},
    {ACH_TM_20, sText_AchTm20Name, sText_AchTm20Desc, ACH_TIER_SILVER, ACH_COUNTER_TMS_COLLECTED, 20, TRAINER_NONE_ACH, NULL},
    {ACH_TM_50, sText_AchTm50Name, sText_AchTm50Desc, ACH_TIER_GOLD, ACH_COUNTER_TMS_COLLECTED, 50, TRAINER_NONE_ACH, NULL},
    {ACH_TM_100, sText_AchTm100Name, sText_AchTm100Desc, ACH_TIER_PLATINUM, ACH_COUNTER_TMS_COLLECTED, 100, TRAINER_NONE_ACH, NULL},
    {ACH_POKEDEX_200, sText_AchPokedex200Name, sText_AchPokedex200Desc, ACH_TIER_SILVER, ACH_COUNTER_POKEDEX_CAUGHT, 200, TRAINER_NONE_ACH, NULL},
    {ACH_POKEDEX_350, sText_AchPokedex350Name, sText_AchPokedex350Desc, ACH_TIER_GOLD, ACH_COUNTER_POKEDEX_CAUGHT, 350, TRAINER_NONE_ACH, NULL},
    {ACH_POKEDEX_500, sText_AchPokedex500Name, sText_AchPokedex500Desc, ACH_TIER_PLATINUM, ACH_COUNTER_POKEDEX_CAUGHT, 500, TRAINER_NONE_ACH, NULL},
    {ACH_COMPLETE_HOENN_DEX, sText_AchHoennDexName, sText_AchHoennDexDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateHoennDexComplete},
    {ACH_PLANT_BERRIES_10, sText_AchPlantBerries10Name, sText_AchPlantBerries10Desc, ACH_TIER_BRONZE, ACH_COUNTER_PLANTED_BERRIES, 10, TRAINER_NONE_ACH, NULL},
    {ACH_GAINING_POWER, sText_AchGainingPowerName, sText_AchGainingPowerDesc, ACH_TIER_SILVER, ACH_COUNTER_EVOLVED_POKEMON, 25, TRAINER_NONE_ACH, NULL},
    {ACH_PEAK_OF_POWER, sText_AchPeakOfPowerName, sText_AchPeakOfPowerDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateHasLevel100Pokemon},
    {ACH_BUG_CATCHER, sText_AchBugCatcherName, sText_AchBugCatcherDesc, ACH_TIER_SILVER, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, NULL},
    {ACH_BUENA_SUPERFAN, sText_AchBuenaSuperfanName, sText_AchBuenaSuperfanDesc, ACH_TIER_SILVER, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateBuenaSuperfan},
    {ACH_TRAVELLING_HEALER, sText_AchTravellingHealerName, sText_AchTravellingHealerDesc, ACH_TIER_SILVER, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateTravellingHealer},
    {ACH_MASTERPIECE, sText_AchMasterpieceName, sText_AchMasterpieceDesc, ACH_TIER_PLATINUM, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateKurtMasterBall},
    {ACH_MEGA_COLLECTOR, sText_AchMegaCollectorName, sText_AchMegaCollectorDesc, ACH_TIER_PLATINUM, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateMegaCollector},
    {ACH_MASTER_OF_MOVES, sText_AchMasterOfMovesName, sText_AchMasterOfMovesDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateMasterOfMoves},
    {ACH_AUTOPHOTOGRAPHER, sText_AchAutophotographerName, sText_AchAutophotographerDesc, ACH_TIER_SILVER, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateAllCameronPhotos},
    {ACH_MILLIONAIRE, sText_AchMillionaireName, sText_AchMillionaireDesc, ACH_TIER_GOLD, ACH_COUNTER_MONEY_EARNED, 1000000, TRAINER_NONE_ACH, NULL},
    {ACH_SPENDTHRIFT, sText_AchSpendthriftName, sText_AchSpendthriftDesc, ACH_TIER_GOLD, ACH_COUNTER_MONEY_SPENT, 1000000, TRAINER_NONE_ACH, NULL},

    // Battle facility achievements
    {ACH_BATTLE_CONNOISSEUR, sText_AchBattleConnoisseurName, sText_AchBattleConnoisseurDesc, ACH_TIER_SILVER, ACH_COUNTER_BATTLE_POINTS_EARNED, 100, TRAINER_NONE_ACH, NULL},
    {ACH_BATTLE_TOWER_25, sText_AchTower25Name, sText_AchTower25Desc, ACH_TIER_SILVER, ACH_COUNTER_BATTLE_TOWER_WINS, 25, TRAINER_NONE_ACH, NULL},
    {ACH_BATTLE_TOWER_50, sText_AchTower50Name, sText_AchTower50Desc, ACH_TIER_GOLD, ACH_COUNTER_BATTLE_TOWER_WINS, 50, TRAINER_NONE_ACH, NULL},
    {ACH_BATTLE_TOWER_100, sText_AchTower100Name, sText_AchTower100Desc, ACH_TIER_PLATINUM, ACH_COUNTER_BATTLE_TOWER_WINS, 100, TRAINER_NONE_ACH, NULL},
    {ACH_ROCKET_ARCADE_25, sText_AchRocketArcade25Name, sText_AchRocketArcade25Desc, ACH_TIER_SILVER, ACH_COUNTER_ROCKET_ARCADE_WINS, 25, TRAINER_NONE_ACH, NULL},
    {ACH_ROCKET_ARCADE_50, sText_AchRocketArcade50Name, sText_AchRocketArcade50Desc, ACH_TIER_GOLD, ACH_COUNTER_ROCKET_ARCADE_WINS, 50, TRAINER_NONE_ACH, NULL},
    {ACH_ROCKET_ARCADE_100, sText_AchRocketArcade100Name, sText_AchRocketArcade100Desc, ACH_TIER_PLATINUM, ACH_COUNTER_ROCKET_ARCADE_WINS, 100, TRAINER_NONE_ACH, NULL},
    {ACH_BATTLE_FACTORY_25, sText_AchFactory25Name, sText_AchFactory25Desc, ACH_TIER_SILVER, ACH_COUNTER_BATTLE_FACTORY_WINS, 25, TRAINER_NONE_ACH, NULL},
    {ACH_BATTLE_FACTORY_50, sText_AchFactory50Name, sText_AchFactory50Desc, ACH_TIER_GOLD, ACH_COUNTER_BATTLE_FACTORY_WINS, 50, TRAINER_NONE_ACH, NULL},
    {ACH_BATTLE_FACTORY_100, sText_AchFactory100Name, sText_AchFactory100Desc, ACH_TIER_PLATINUM, ACH_COUNTER_BATTLE_FACTORY_WINS, 100, TRAINER_NONE_ACH, NULL},
    {ACH_BATTLE_PYRAMID_3, sText_AchPyramid3Name, sText_AchPyramid3Desc, ACH_TIER_SILVER, ACH_COUNTER_BATTLE_PYRAMID_ROUNDS, 3, TRAINER_NONE_ACH, NULL},
    {ACH_BATTLE_PYRAMID_10, sText_AchPyramid10Name, sText_AchPyramid10Desc, ACH_TIER_GOLD, ACH_COUNTER_BATTLE_PYRAMID_ROUNDS, 6, TRAINER_NONE_ACH, NULL},
    {ACH_BATTLE_PYRAMID_20, sText_AchPyramid20Name, sText_AchPyramid20Desc, ACH_TIER_PLATINUM, ACH_COUNTER_BATTLE_PYRAMID_ROUNDS, 10, TRAINER_NONE_ACH, NULL},
    {ACH_BATTLE_CAFE_DAILY, sText_AchBattleCafeDailyName, sText_AchBattleCafeDailyDesc, ACH_TIER_BRONZE, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, NULL},
    {ACH_BATTLE_CAFE_RUSH, sText_AchBattleCafeRushName, sText_AchBattleCafeRushDesc, ACH_TIER_SILVER, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, NULL},
    {ACH_BATTLE_CAFE_SUPER_CHALLENGE, sText_AchBattleCafeSuperChallengeName, sText_AchBattleCafeSuperChallengeDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, NULL},
    {ACH_BATTLE_CAFE_ENDLESS_MASTER, sText_AchBattleCafeEndlessMasterName, sText_AchBattleCafeEndlessMasterDesc, ACH_TIER_PLATINUM, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, NULL},

    // Superboss achievements
    {ACH_REMATCH_FALKNER, sText_AchFalknerRematchName, sText_AchFalknerRematchDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_FALKNER_2, NULL},
    {ACH_REMATCH_BUGSY, sText_AchBugsyRematchName, sText_AchBugsyRematchDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_BUGSY_2, NULL},
    {ACH_REMATCH_WHITNEY, sText_AchWhitneyRematchName, sText_AchWhitneyRematchDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_WHITNEY_2, NULL},
    {ACH_REMATCH_MORTY, sText_AchMortyRematchName, sText_AchMortyRematchDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_MORTY_2, NULL},
    {ACH_REMATCH_CHUCK, sText_AchChuckRematchName, sText_AchChuckRematchDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_CHUCK_2, NULL},
    {ACH_REMATCH_JASMINE, sText_AchJasmineRematchName, sText_AchJasmineRematchDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_JASMINE_2, NULL},
    {ACH_REMATCH_PRYCE, sText_AchPryceRematchName, sText_AchPryceRematchDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_PRYCE_2, NULL},
    {ACH_REMATCH_CLAIR, sText_AchClairRematchName, sText_AchClairRematchDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_CLAIR_2, NULL},
    {ACH_ROUTE_EXPERTS, sText_AchRouteExpertsName, sText_AchRouteExpertsDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateRouteExperts},
    {ACH_CATCH_BLOOD_MOON_URSALUNA, sText_AchBloodMoonName, sText_AchBloodMoonDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, NULL},
    {ACH_DEFEAT_STEVEN, sText_AchDefeatStevenName, sText_AchDefeatStevenDesc, ACH_TIER_PLATINUM, ACH_COUNTER_NONE, 0, TRAINER_STEVEN, NULL},

    // Legendary and Mythical Pokémon - Generation I
    {ACH_CATCH_ARTICUNO, sText_AchCatchArticunoName, sText_AchCatchArticunoDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, NULL},
    {ACH_CATCH_ZAPDOS, sText_AchCatchZapdosName, sText_AchCatchZapdosDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, NULL},
    {ACH_CATCH_MOLTRES, sText_AchCatchMoltresName, sText_AchCatchMoltresDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, NULL},
    {ACH_CATCH_MEWTWO, sText_AchCatchMewtwoName, sText_AchCatchMewtwoDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtMewtwo},
    {ACH_CATCH_MEW, sText_AchCatchMewName, sText_AchCatchMewDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtMew},

    // Legendary and Mythical Pokémon - Generation II
    {ACH_CATCH_RAIKOU, sText_AchCatchRaikouName, sText_AchCatchRaikouDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtRaikou},
    {ACH_CATCH_ENTEI, sText_AchCatchEnteiName, sText_AchCatchEnteiDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtEntei},
    {ACH_CATCH_SUICUNE, sText_AchCatchSuicuneName, sText_AchCatchSuicuneDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtSuicune},
    {ACH_CATCH_LUGIA, sText_AchCatchLugiaName, sText_AchCatchLugiaDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtLugia},
    {ACH_CATCH_HO_OH, sText_AchCatchHoOhName, sText_AchCatchHoOhDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtHoOh},
    {ACH_CATCH_CELEBI, sText_AchCatchCelebiName, sText_AchCatchCelebiDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtCelebi},

    // Legendary and Mythical Pokémon - Generation III
    {ACH_CATCH_REGIROCK, sText_AchCatchRegirockName, sText_AchCatchRegirockDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtRegirock},
    {ACH_CATCH_REGICE, sText_AchCatchRegiceName, sText_AchCatchRegiceDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtRegice},
    {ACH_CATCH_REGISTEEL, sText_AchCatchRegisteelName, sText_AchCatchRegisteelDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtRegisteel},
    {ACH_CATCH_EON_DUO, sText_AchCatchEonDuoName, sText_AchCatchEonDuoDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtEonDuo},
    {ACH_CATCH_KYOGRE, sText_AchCatchKyogreName, sText_AchCatchKyogreDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtKyogre},
    {ACH_CATCH_GROUDON, sText_AchCatchGroudonName, sText_AchCatchGroudonDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtGroudon},
    {ACH_CATCH_RAYQUAZA, sText_AchRayquazaName, sText_AchRayquazaDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtRayquaza},
    {ACH_OBTAIN_JIRACHI, sText_AchObtainJirachiName, sText_AchObtainJirachiDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtJirachi},
    // Legendary and Mythical Pokémon - Generation IV
    {ACH_CATCH_UXIE, sText_AchCatchUxieName, sText_AchCatchUxieDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtUxie},
    {ACH_CATCH_MESPRIT, sText_AchCatchMespritName, sText_AchCatchMespritDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtMesprit},
    {ACH_CATCH_AZELF, sText_AchCatchAzelfName, sText_AchCatchAzelfDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtAzelf},
    {ACH_CATCH_DIALGA, sText_AchCatchDialgaName, sText_AchCatchDialgaDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtDialga},
    {ACH_CATCH_PALKIA, sText_AchCatchPalkiaName, sText_AchCatchPalkiaDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtPalkia},
    {ACH_CATCH_GIRATINA, sText_AchCatchGiratinaName, sText_AchCatchGiratinaDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtGiratina},
    {ACH_CATCH_HEATRAN, sText_AchCatchHeatranName, sText_AchCatchHeatranDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtHeatran},
    {ACH_CATCH_REGIGIGAS, sText_AchCatchRegigigasName, sText_AchCatchRegigigasDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtRegigigas},
    {ACH_CATCH_CRESSELIA, sText_AchCatchCresseliaName, sText_AchCatchCresseliaDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtCresselia},
    {ACH_UNDER_THE_SEA, sText_AchUnderTheSeaName, sText_AchUnderTheSeaDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtPhione},
    {ACH_CATCH_DARKRAI, sText_AchCatchDarkraiName, sText_AchCatchDarkraiDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtDarkrai},
    {ACH_OBTAIN_SHAYMIN, sText_AchObtainShayminName, sText_AchObtainShayminDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtShaymin},

    // Legendary and Mythical Pokémon - Generation V
    {ACH_OBTAIN_VICTINI, sText_AchObtainVictiniName, sText_AchObtainVictiniDesc, ACH_TIER_PLATINUM, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtVictini},
    {ACH_CATCH_COBALION, sText_AchCatchCobalionName, sText_AchCatchCobalionDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtCobalion},
    {ACH_CATCH_TERRAKION, sText_AchCatchTerrakionName, sText_AchCatchTerrakionDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtTerrakion},
    {ACH_CATCH_VIRIZION, sText_AchCatchVirizionName, sText_AchCatchVirizionDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtVirizion},
    {ACH_CATCH_MELOETTA, sText_AchCatchMeloettaName, sText_AchCatchMeloettaDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtMeloetta},
    {ACH_MASTER_OF_WISHES, sText_AchMasterOfWishesName, sText_AchMasterOfWishesDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateObtainedWeatherGenies},

    // Legendary and Mythical Pokémon - Generation VI
    {ACH_CATCH_HOOPA, sText_AchCatchHoopaName, sText_AchCatchHoopaDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtHoopa},
    {ACH_OBTAIN_DIANCIE, sText_AchObtainDiancieName, sText_AchObtainDiancieDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, NULL},

    // Legendary and Mythical Pokémon - Generation VII
    {ACH_CATCH_MAGEARNA, sText_AchCatchMagearnaName, sText_AchCatchMagearnaDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtMagearna},
    {ACH_CATCH_ZERAORA, sText_AchCatchZeraoraName, sText_AchCatchZeraoraDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtZeraora},
    {ACH_OBTAIN_TAPUS, sText_AchObtainTapusName, sText_AchObtainTapusDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateObtainedTapus},

    // Legendary and Mythical Pokémon - Generation VIII
    {ACH_CATCH_MARSHADOW, sText_AchCatchMarshadowName, sText_AchCatchMarshadowDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtMarshadow},
    {ACH_OBTAIN_GALARIAN_BIRDS, sText_AchObtainGalarianBirdsName, sText_AchObtainGalarianBirdsDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateObtainedGalarianBirds},

    // Legendary and Mythical Pokémon - Generation IX
    {ACH_CATCH_CHIEN_PAO, sText_AchCatchChienPaoName, sText_AchCatchChienPaoDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtChienPao},
    {ACH_CATCH_OGERPON, sText_AchCatchOgerponName, sText_AchCatchOgerponDesc, ACH_TIER_GOLD, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtOgerpon},
    {ACH_OBTAIN_PARADOX_LEGENDS, sText_AchObtainParadoxLegendsName, sText_AchObtainParadoxLegendsDesc, ACH_TIER_PLATINUM, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateObtainedParadoxLegends},

    {ACH_PARADOXICAL, sText_AchParadoxicalName, sText_AchParadoxicalDesc, ACH_TIER_PLATINUM, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateCaughtAllParadoxPokemon},
    {ACH_MASTER_OF_JOHTO, sText_AchMasterOfJohtoName, sText_AchMasterOfJohtoDesc, ACH_TIER_PLATINUM, ACH_COUNTER_NONE, 0, TRAINER_NONE_ACH, Achievement_PredicateAllOtherTrophies},
};

STATIC_ASSERT(ARRAY_COUNT(sAchievements) == ACH_COUNT, AchievementTableMatchesIdCount);
STATIC_ASSERT(ACH_ID_COUNT <= ACHIEVEMENTS_MAX, AchievementIdsWithinSaveBitmap);
STATIC_ASSERT(ACH_LEGACY_SOUTHERN_VACATION == 14, LegacySouthernVacationIdIsStable);
STATIC_ASSERT(ACH_LEGACY_CATCH_KYOGRE == 81, LegacyKyogreIdIsStable);
STATIC_ASSERT(ACH_LEGACY_CATCH_GROUDON == 82, LegacyGroudonIdIsStable);
STATIC_ASSERT(ACH_LEGACY_CATCH_DEOXYS == 84, LegacyDeoxysIdIsStable);
STATIC_ASSERT(ACH_PLANT_BERRIES_10 == 107, GreenThumbIdIsStable);
STATIC_ASSERT(ACH_CATCH_HOOPA == 108, HoopaIdIsStable);
STATIC_ASSERT(ACH_CATCH_COBALION == 109, CobalionIdIsStable);
STATIC_ASSERT(ACH_CATCH_TERRAKION == 110, TerrakionIdIsStable);
STATIC_ASSERT(ACH_CATCH_MELOETTA == 111, MeloettaIdAppendedAfterExistingIds);
STATIC_ASSERT(ACH_CATCH_ZERAORA == 112, ZeraoraIdAppendedAfterExistingIds);
STATIC_ASSERT(ACH_OBTAIN_DIANCIE == 113, DiancieIdAppendedAfterExistingIds);
STATIC_ASSERT(ACH_OBTAIN_GALARIAN_BIRDS == 114, GalarianBirdsIdAppendedAfterExistingIds);
STATIC_ASSERT(ACH_CATCH_KYOGRE == 115, KyogreIdAppendedAfterExistingIds);
STATIC_ASSERT(ACH_CATCH_GROUDON == 116, GroudonIdAppendedAfterExistingIds);
STATIC_ASSERT(ACH_MASTER_OF_WISHES == 117, MasterOfWishesIdAppendedAfterExistingIds);
STATIC_ASSERT(ACH_CATCH_GIRATINA == 118, GiratinaIdAppendedAfterExistingIds);
STATIC_ASSERT(ACH_BATTLE_CAFE_DAILY == 119, BattleCafeDailyIdAppendedAfterExistingIds);
STATIC_ASSERT(ACH_BATTLE_CAFE_RUSH == 120, BattleCafeRushIdAppendedAfterExistingIds);
STATIC_ASSERT(ACH_BATTLE_CAFE_SUPER_CHALLENGE == 121, BattleCafeSuperChallengeIdAppendedAfterExistingIds);
STATIC_ASSERT(ACH_BATTLE_CAFE_ENDLESS_MASTER == 122, BattleCafeEndlessMasterIdAppendedAfterExistingIds);
STATIC_ASSERT(ACH_OBTAIN_TAPUS == 123, TapusIdAppendedAfterExistingIds);
STATIC_ASSERT(ACH_OBTAIN_PARADOX_LEGENDS == 124, ParadoxLegendsIdAppendedAfterExistingIds);

static const u8 *const sTierLabels[] =
{
    [ACH_TIER_BRONZE] = sText_TierBronze,
    [ACH_TIER_SILVER] = sText_TierSilver,
    [ACH_TIER_GOLD] = sText_TierGold,
    [ACH_TIER_PLATINUM] = sText_TierPlatinum,
};

static const u16 sTierBallItems[] =
{
    [ACH_TIER_BRONZE] = ITEM_POKE_BALL,
    [ACH_TIER_SILVER] = ITEM_GREAT_BALL,
    [ACH_TIER_GOLD] = ITEM_ULTRA_BALL,
    [ACH_TIER_PLATINUM] = ITEM_MASTER_BALL,
};

static const u16 sRouteExpertFlags[] =
{
    FLAG_ROUTE31_EXPERT,
    FLAG_GOLDENRODSHORE_EXPERT,
    FLAG_ROUTE43_EXPERT,
    FLAG_ROUTE47_EXPERT,
    FLAG_ROUTE27_EXPERT,
};

void Achievement_EnsureSaveInitialized(void)
{
    if (gSaveBlock1Ptr->achievements.magic != ACHIEVEMENT_SAVE_MAGIC)
    {
        memset(&gSaveBlock1Ptr->achievements, 0, sizeof(gSaveBlock1Ptr->achievements));
        gSaveBlock1Ptr->achievements.magic = ACHIEVEMENT_SAVE_MAGIC;
    }
}

static bool32 Achievement_PredicateHoennDexComplete(void)
{
    return HasCompletedJohtoPokedex();
}

static bool32 Achievement_PredicateCameronPhoto(void)
{
    u16 flag;

    for (flag = FLAG_CAMERON_PHOTO1; flag <= FLAG_CAMERON_PHOTO5; flag++)
    {
        if (FlagGet(flag))
            return TRUE;
    }
    return FALSE;
}

static bool32 Achievement_PredicateAllCameronPhotos(void)
{
    u16 flag;

    for (flag = FLAG_CAMERON_PHOTO1; flag <= FLAG_CAMERON_PHOTO5; flag++)
    {
        if (!FlagGet(flag))
            return FALSE;
    }
    return TRUE;
}

static bool32 Achievement_PredicateBuenaSuperfan(void)
{
    return VarGet(VAR_BUENA_PASSWORDS_CORRECT) >= 3;
}

static bool32 Achievement_PredicateTravellingHealer(void)
{
    return VarGet(VAR_ROUTE39_BARN) >= 5;
}

static bool32 Achievement_PredicateKurtMasterBall(void)
{
    return FlagGet(FLAG_KURT_CRAFTED_MASTER_BALL);
}

static void Achievement_RecordOwnedTypeStone(u32 *ownedItems, enum Item item)
{
    u32 itemIndex = item - ITEM_NORMALITE;

    if (itemIndex <= ITEM_BONDSTONE - ITEM_NORMALITE)
        *ownedItems |= 1u << itemIndex;
}

static bool32 Achievement_PredicateMegaCollector(void)
{
    u32 ownedItems = 0;
    u32 allItems = (1u << (ITEM_BONDSTONE - ITEM_NORMALITE + 1)) - 1;
    u16 i;
    u8 boxId;
    u8 boxPosition;

    for (i = 0; i < gBagPockets[POCKET_MEGASTONES].capacity; i++)
        Achievement_RecordOwnedTypeStone(&ownedItems, GetBagItemId(POCKET_MEGASTONES, i));
    if (ownedItems == allItems)
        return TRUE;

    for (i = 0; i < PARTY_SIZE; i++)
        Achievement_RecordOwnedTypeStone(&ownedItems, (enum Item)GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM));
    if (ownedItems == allItems)
        return TRUE;

    if (gPokemonStoragePtr == NULL)
        return FALSE;

    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        for (boxPosition = 0; boxPosition < IN_BOX_COUNT; boxPosition++)
        {
            Achievement_RecordOwnedTypeStone(
                &ownedItems,
                (enum Item)GetBoxMonData(GetBoxedMonPtr(boxId, boxPosition), MON_DATA_HELD_ITEM));
            if (ownedItems == allItems)
                return TRUE;
        }
    }

    return FALSE;
}

static bool32 Achievement_PredicateMasterOfMoves(void)
{
    return FlagGet(FLAG_EGG_MOVES_UNLOCKED) && FlagGet(FLAG_TUTOR_MOVES_UNLOCKED);
}

static bool32 Achievement_PredicateBadgeFlag(u16 flag)
{
    return FlagGet(flag);
}

static bool32 Achievement_PredicateCaughtSpecies(u16 species)
{
    return GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT);
}

static bool32 Achievement_PredicateCaughtRayquaza(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_RAYQUAZA);
}

static bool32 Achievement_PredicateCaughtLugia(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_LUGIA);
}

static bool32 Achievement_PredicateCaughtHoOh(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_HO_OH);
}

static bool32 Achievement_PredicateZephyrBadge(void)
{
    return Achievement_PredicateBadgeFlag(FLAG_BADGE01_GET);
}

static bool32 Achievement_PredicateHiveBadge(void)
{
    return Achievement_PredicateBadgeFlag(FLAG_BADGE02_GET);
}

static bool32 Achievement_PredicatePlainBadge(void)
{
    return Achievement_PredicateBadgeFlag(FLAG_BADGE03_GET);
}

static bool32 Achievement_PredicateFogBadge(void)
{
    return Achievement_PredicateBadgeFlag(FLAG_BADGE04_GET);
}

static bool32 Achievement_PredicateStormBadge(void)
{
    return Achievement_PredicateBadgeFlag(FLAG_BADGE05_GET);
}

static bool32 Achievement_PredicateMineralBadge(void)
{
    return Achievement_PredicateBadgeFlag(FLAG_BADGE06_GET);
}

static bool32 Achievement_PredicateGlacierBadge(void)
{
    return Achievement_PredicateBadgeFlag(FLAG_BADGE07_GET);
}

static bool32 Achievement_PredicateRisingBadge(void)
{
    return Achievement_PredicateBadgeFlag(FLAG_BADGE08_GET);
}

static bool32 Achievement_PredicateRouteExperts(void)
{
    u16 i;

    for (i = 0; i < ARRAY_COUNT(sRouteExpertFlags); i++)
    {
        if (!FlagGet(sRouteExpertFlags[i]))
            return FALSE;
    }
    return TRUE;
}

static bool32 Achievement_PredicateCaughtCelebi(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_CELEBI);
}

static bool32 Achievement_PredicateCaughtRegice(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_REGICE);
}

static bool32 Achievement_PredicateCaughtRegisteel(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_REGISTEEL);
}

static bool32 Achievement_PredicateCaughtRegirock(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_REGIROCK);
}

static bool32 Achievement_PredicateCaughtRegigigas(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_REGIGIGAS);
}

static bool32 Achievement_PredicateCaughtChienPao(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_CHIEN_PAO);
}

static bool32 Achievement_PredicateCaughtHeatran(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_HEATRAN);
}

static bool32 Achievement_PredicateCaughtOgerpon(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_OGERPON);
}

static bool32 Achievement_PredicateCaughtMesprit(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_MESPRIT);
}

static bool32 Achievement_PredicateCaughtUxie(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_UXIE);
}

static bool32 Achievement_PredicateCaughtAzelf(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_AZELF);
}

static bool32 Achievement_PredicateCaughtLapras(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_LAPRAS);
}

static bool32 Achievement_PredicateCaughtVictini(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_VICTINI);
}

static bool32 Achievement_PredicateCaughtPhione(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_PHIONE);
}

static bool32 Achievement_PredicateCaughtMewtwo(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_MEWTWO);
}

static bool32 Achievement_PredicateCaughtMew(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_MEW);
}

static bool32 Achievement_PredicateCaughtSuicune(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_SUICUNE);
}

static bool32 Achievement_PredicateCaughtEntei(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_ENTEI);
}

static bool32 Achievement_PredicateCaughtRaikou(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_RAIKOU);
}

static bool32 Achievement_PredicateCaughtKyogre(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_KYOGRE);
}

static bool32 Achievement_PredicateCaughtGroudon(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_GROUDON);
}

static bool32 Achievement_PredicateCaughtEonDuo(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_LATIAS)
        && Achievement_PredicateCaughtSpecies(SPECIES_LATIOS);
}

static bool32 Achievement_PredicateCaughtJirachi(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_JIRACHI);
}

static bool32 Achievement_PredicateCaughtHoopa(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_HOOPA);
}

static bool32 Achievement_PredicateCaughtDialga(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_DIALGA);
}

static bool32 Achievement_PredicateCaughtPalkia(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_PALKIA);
}

static bool32 Achievement_PredicateCaughtGiratina(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_GIRATINA);
}

static bool32 Achievement_PredicateCaughtCresselia(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_CRESSELIA);
}

static bool32 Achievement_PredicateCaughtDarkrai(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_DARKRAI);
}

static bool32 Achievement_PredicateCaughtShaymin(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_SHAYMIN);
}

static bool32 Achievement_PredicateAllOtherTrophies(void)
{
    u16 i;

    for (i = 0; i < ARRAY_COUNT(sAchievements); i++)
    {
        enum AchievementId id = sAchievements[i].id;

        if (id != ACH_MASTER_OF_JOHTO && !Achievement_IsUnlocked(id))
            return FALSE;
    }

    return TRUE;
}

static bool32 Achievement_PredicateCaughtMagearna(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_MAGEARNA);
}

static bool32 Achievement_PredicateCaughtMarshadow(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_MARSHADOW);
}

static bool32 Achievement_PredicateCaughtCobalion(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_COBALION);
}

static bool32 Achievement_PredicateCaughtTerrakion(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_TERRAKION);
}

static bool32 Achievement_PredicateCaughtVirizion(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_VIRIZION);
}

static bool32 Achievement_PredicateCaughtMeloetta(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_MELOETTA);
}

static bool32 Achievement_PredicateCaughtZeraora(void)
{
    return Achievement_PredicateCaughtSpecies(SPECIES_ZERAORA);
}

static bool32 Achievement_PredicateObtainedGalarianBirds(void)
{
    return FlagGet(FLAG_BATTLE_CAFE_ARTICUNO_RECEIVED)
        && FlagGet(FLAG_BATTLE_CAFE_ZAPDOS_RECEIVED)
        && FlagGet(FLAG_BATTLE_CAFE_MOLTRES_RECEIVED);
}

static bool32 Achievement_PredicateObtainedWeatherGenies(void)
{
    return FlagGet(FLAG_BATTLE_CAFE_TORNADUS_RECEIVED)
        && FlagGet(FLAG_BATTLE_CAFE_THUNDURUS_RECEIVED)
        && FlagGet(FLAG_BATTLE_CAFE_LANDORUS_RECEIVED)
        && FlagGet(FLAG_BATTLE_CAFE_ENAMORUS_RECEIVED);
}

static bool32 Achievement_PredicateObtainedTapus(void)
{
    return FlagGet(FLAG_BATTLE_CAFE_TAPU_KOKO_RECEIVED)
        && FlagGet(FLAG_BATTLE_CAFE_TAPU_LELE_RECEIVED)
        && FlagGet(FLAG_BATTLE_CAFE_TAPU_BULU_RECEIVED)
        && FlagGet(FLAG_BATTLE_CAFE_TAPU_FINI_RECEIVED);
}

static bool32 Achievement_PredicateObtainedParadoxLegends(void)
{
    return FlagGet(FLAG_BATTLE_CAFE_MIRAIDON_RECEIVED)
        && FlagGet(FLAG_BATTLE_CAFE_KORAIDON_RECEIVED);
}

static const u16 sParadoxPokemon[] =
{
    SPECIES_GREAT_TUSK,
    SPECIES_SCREAM_TAIL,
    SPECIES_BRUTE_BONNET,
    SPECIES_FLUTTER_MANE,
    SPECIES_SLITHER_WING,
    SPECIES_SANDY_SHOCKS,
    SPECIES_ROARING_MOON,
    SPECIES_WALKING_WAKE,
    SPECIES_GOUGING_FIRE,
    SPECIES_RAGING_BOLT,
    SPECIES_IRON_TREADS,
    SPECIES_IRON_BUNDLE,
    SPECIES_IRON_HANDS,
    SPECIES_IRON_JUGULIS,
    SPECIES_IRON_MOTH,
    SPECIES_IRON_THORNS,
    SPECIES_IRON_VALIANT,
    SPECIES_IRON_LEAVES,
    SPECIES_IRON_BOULDER,
    SPECIES_IRON_CROWN,
};

static bool32 Achievement_PredicateCaughtAllParadoxPokemon(void)
{
    u16 i;
    bool32 hasEnabledSpecies = FALSE;

    for (i = 0; i < ARRAY_COUNT(sParadoxPokemon); i++)
    {
        if (IsSpeciesEnabled(sParadoxPokemon[i]))
        {
            hasEnabledSpecies = TRUE;
            if (!Achievement_PredicateCaughtSpecies(sParadoxPokemon[i]))
                return FALSE;
        }
    }

    return hasEnabledSpecies;
}

static bool32 Achievement_IsInScaledChaosFacility(void)
{
    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_OPEN)
        return FALSE;

    switch (gMapHeader.mapLayoutId)
    {
    case LAYOUT_BATTLE_ELEVATOR:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_TOWER_CORRIDOR:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_TOWER_BATTLE_ROOM:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_DOME_CORRIDOR:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_ARENA_BATTLE_ROOM:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_THREE_PATH_ROOM:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_FINAL:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_UNUSED:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM:
    case LAYOUT_GOLDENROD_BATTLE_ARCADE_HALLWAY:
    case LAYOUT_GOLDENROD_BATTLE_ARCADE_BATTLE_ROOM:
        return TRUE;
    case LAYOUT_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_DOME_LOBBY:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_ARENA_LOBBY:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY:
    case LAYOUT_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY:
    case LAYOUT_GOLDENROD_BATTLE_ARACDE_LOBBY:
        // Results can be processed before the temporary party is restored.
        return gSaveBlock2Ptr->frontier.challengeStatus != 0;
    default:
        return FALSE;
    }
}

static bool32 Achievement_PredicateHasLevel100Pokemon(void)
{
    u8 boxId;
    u8 boxPosition;
    u8 partyIndex;

    // Chaos temporarily scales selected parties (and Factory rentals) to level 100.
    if (!Achievement_IsInScaledChaosFacility())
    {
        for (partyIndex = 0; partyIndex < PARTY_SIZE; partyIndex++)
        {
            if (GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
             && GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
             && GetMonData(&gPlayerParty[partyIndex], MON_DATA_LEVEL) >= MAX_LEVEL)
                return TRUE;
        }
    }

    if (gPokemonStoragePtr == NULL)
        return FALSE;

    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        for (boxPosition = 0; boxPosition < IN_BOX_COUNT; boxPosition++)
        {
            struct BoxPokemon *boxMon = GetBoxedMonPtr(boxId, boxPosition);

            if (GetBoxMonData(boxMon, MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
             && GetBoxMonData(boxMon, MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
             && GetLevelFromBoxMonExp(boxMon) >= MAX_LEVEL)
                return TRUE;
        }
    }

    return FALSE;
}

static u32 Achievement_CountCollectedTMs(void)
{
    u16 i;
    u32 count = 0;

    for (i = 0; i < gBagPockets[POCKET_TM_HM].capacity; i++)
    {
        enum TMHMIndex index = GetItemTMHMIndex(GetBagItemId(POCKET_TM_HM, i));

        if (index > 0 && index <= NUM_TECHNICAL_MACHINES)
            count++;
    }
    return count;
}

static u32 Achievement_GetBestBattlePyramidFloorStreak(void)
{
    u8 lvlMode;
    u32 best = 0;

    for (lvlMode = 0; lvlMode < ARRAY_COUNT(gSaveBlock2Ptr->frontier.pyramidRecordStreaks); lvlMode++)
    {
        if (best < gSaveBlock2Ptr->frontier.pyramidRecordStreaks[lvlMode])
            best = gSaveBlock2Ptr->frontier.pyramidRecordStreaks[lvlMode];
        if (best < gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode])
            best = gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode];
    }
    return best;
}

u16 Achievement_GetCount(void)
{
    Achievement_EnsureSaveInitialized();
    return ARRAY_COUNT(sAchievements);
}

const struct Achievement *Achievement_GetByIndex(u16 index)
{
    if (index >= ARRAY_COUNT(sAchievements))
        return NULL;
    return &sAchievements[index];
}

const struct Achievement *Achievement_GetById(enum AchievementId id)
{
    u16 i;

    for (i = 0; i < ARRAY_COUNT(sAchievements); i++)
    {
        if (sAchievements[i].id == id)
            return &sAchievements[i];
    }
    return NULL;
}

const u8 *Achievement_GetTierLabel(enum AchievementTier tier)
{
    if (tier >= ARRAY_COUNT(sTierLabels))
        return sTierLabels[ACH_TIER_BRONZE];
    return sTierLabels[tier];
}

u16 Achievement_GetTierBallItem(enum AchievementTier tier)
{
    if (tier >= ARRAY_COUNT(sTierBallItems))
        return sTierBallItems[ACH_TIER_BRONZE];
    return sTierBallItems[tier];
}

bool32 Achievement_IsUnlocked(enum AchievementId id)
{
    if ((u32)id >= ACHIEVEMENTS_MAX)
        return FALSE;
    Achievement_EnsureSaveInitialized();
    return (gSaveBlock1Ptr->achievements.unlocked[id / 8] & (1 << (id % 8))) != 0;
}

u16 Achievement_CountUnlocked(void)
{
    u16 i, count = 0;

    Achievement_EnsureSaveInitialized();
    for (i = 0; i < ARRAY_COUNT(sAchievements); i++)
    {
        enum AchievementId id = sAchievements[i].id;

        if (gSaveBlock1Ptr->achievements.unlocked[id / 8] & (1 << (id % 8)))
            count++;
    }
    return count;
}

void GetCompletedAchievementsCount(void)
{
    Achievement_CheckAll();
    gSpecialVar_Result = Achievement_CountUnlocked();
}

u32 Achievement_GetCounter(enum AchievementCounter counter)
{
    switch (counter)
    {
    case ACH_COUNTER_PLANTED_BERRIES:
        return VarGet(VAR_ACHIEVEMENT_PLANTED_BERRIES);
    case ACH_COUNTER_EVOLVED_POKEMON:
        return GetGameStat(GAME_STAT_EVOLVED_POKEMON);
    case ACH_COUNTER_BATTLE_POINTS_EARNED:
        return gSaveBlock2Ptr->frontier.cardBattlePoints;
    case ACH_COUNTER_MONEY_SPENT:
        return GetGameStat(GAME_STAT_MONEY_SPENT);
    case ACH_COUNTER_MONEY_EARNED:
        return GetGameStat(GAME_STAT_MONEY_EARNED);
    case ACH_COUNTER_BATTLE_TOWER_WINS:
        return gSaveBlock2Ptr->frontier.towerNumWins;
    case ACH_COUNTER_TMS_COLLECTED:
        return Achievement_CountCollectedTMs();
    case ACH_COUNTER_POKEDEX_CAUGHT:
        return GetNationalPokedexCount(FLAG_GET_CAUGHT);
    case ACH_COUNTER_BATTLE_FACTORY_WINS:
        return gSaveBlock2Ptr->frontier.factoryTotalWins;
    case ACH_COUNTER_BATTLE_PYRAMID_ROUNDS:
        return GetGameStat(GAME_STAT_BATTLE_PYRAMID_FLOORS) / FRONTIER_STAGES_PER_CHALLENGE;
    case ACH_COUNTER_ROCKET_ARCADE_WINS:
        return gSaveBlock2Ptr->frontier.arcadeTotalWins;
    case ACH_COUNTER_TITLE_DEFENSE_WINS:
        return VarGet(VAR_TITLE_DEFENSE_WINS);
    default:
        break;
    }

    if (counter >= ACH_COUNTER_COUNT)
        return 0;
    Achievement_EnsureSaveInitialized();
    return gSaveBlock1Ptr->achievements.counters[counter];
}

u32 Achievement_GetProgress(const struct Achievement *achievement)
{
    if (achievement == NULL)
        return 0;
    if (achievement->counter != ACH_COUNTER_NONE)
        return Achievement_GetCounter(achievement->counter);
    if (achievement->predicate != NULL && achievement->predicate())
        return 1;
    return Achievement_IsUnlocked(achievement->id) ? 1 : 0;
}

u32 Achievement_GetTarget(const struct Achievement *achievement)
{
    if (achievement == NULL)
        return 0;
    if (achievement->counter != ACH_COUNTER_NONE)
        return achievement->targetValue;
    return 1;
}

static void Achievement_QueuePopup(enum AchievementId id)
{
    u8 i;

    Achievement_EnsureSaveInitialized();
    for (i = 0; i < ACHIEVEMENT_POPUP_QUEUE_SIZE; i++)
    {
        if (gSaveBlock1Ptr->achievements.popupQueue[i] == 0)
        {
            gSaveBlock1Ptr->achievements.popupQueue[i] = id + 1;
            return;
        }
    }
}

bool32 Achievement_Unlock(enum AchievementId id)
{
    if ((u32)id >= ACHIEVEMENTS_MAX || Achievement_GetById(id) == NULL || Achievement_IsUnlocked(id))
        return FALSE;

    Achievement_EnsureSaveInitialized();
    gSaveBlock1Ptr->achievements.unlocked[id / 8] |= (1 << (id % 8));
    Achievement_QueuePopup(id);
    if (id != ACH_MASTER_OF_JOHTO && Achievement_PredicateAllOtherTrophies())
        Achievement_Unlock(ACH_MASTER_OF_JOHTO);
    return TRUE;
}

void Achievement_OnPokemonObtained(u16 species)
{
    switch (species)
    {
    case SPECIES_EEVEE_STARTER:
    case SPECIES_PIKACHU_STARTER:
        Achievement_Unlock(ACH_LETS_GO);
        break;
    case SPECIES_URSALUNA_BLOODMOON:
        Achievement_Unlock(ACH_CATCH_BLOOD_MOON_URSALUNA);
        break;
    case SPECIES_ARTICUNO:
        Achievement_Unlock(ACH_CATCH_ARTICUNO);
        break;
    case SPECIES_ZAPDOS:
        Achievement_Unlock(ACH_CATCH_ZAPDOS);
        break;
    case SPECIES_MOLTRES:
        Achievement_Unlock(ACH_CATCH_MOLTRES);
        break;
    case SPECIES_DIANCIE:
        Achievement_Unlock(ACH_OBTAIN_DIANCIE);
        break;
    case SPECIES_ARTICUNO_GALAR:
        if (FlagGet(FLAG_BATTLE_CAFE_ZAPDOS_RECEIVED)
         && FlagGet(FLAG_BATTLE_CAFE_MOLTRES_RECEIVED))
            Achievement_Unlock(ACH_OBTAIN_GALARIAN_BIRDS);
        break;
    case SPECIES_ZAPDOS_GALAR:
        if (FlagGet(FLAG_BATTLE_CAFE_ARTICUNO_RECEIVED)
         && FlagGet(FLAG_BATTLE_CAFE_MOLTRES_RECEIVED))
            Achievement_Unlock(ACH_OBTAIN_GALARIAN_BIRDS);
        break;
    case SPECIES_MOLTRES_GALAR:
        if (FlagGet(FLAG_BATTLE_CAFE_ARTICUNO_RECEIVED)
         && FlagGet(FLAG_BATTLE_CAFE_ZAPDOS_RECEIVED))
            Achievement_Unlock(ACH_OBTAIN_GALARIAN_BIRDS);
        break;
    case SPECIES_TORNADUS:
        if (FlagGet(FLAG_BATTLE_CAFE_THUNDURUS_RECEIVED)
         && FlagGet(FLAG_BATTLE_CAFE_LANDORUS_RECEIVED)
         && FlagGet(FLAG_BATTLE_CAFE_ENAMORUS_RECEIVED))
            Achievement_Unlock(ACH_MASTER_OF_WISHES);
        break;
    case SPECIES_THUNDURUS:
        if (FlagGet(FLAG_BATTLE_CAFE_TORNADUS_RECEIVED)
         && FlagGet(FLAG_BATTLE_CAFE_LANDORUS_RECEIVED)
         && FlagGet(FLAG_BATTLE_CAFE_ENAMORUS_RECEIVED))
            Achievement_Unlock(ACH_MASTER_OF_WISHES);
        break;
    case SPECIES_LANDORUS:
        if (FlagGet(FLAG_BATTLE_CAFE_TORNADUS_RECEIVED)
         && FlagGet(FLAG_BATTLE_CAFE_THUNDURUS_RECEIVED)
         && FlagGet(FLAG_BATTLE_CAFE_ENAMORUS_RECEIVED))
            Achievement_Unlock(ACH_MASTER_OF_WISHES);
        break;
    case SPECIES_ENAMORUS:
        if (FlagGet(FLAG_BATTLE_CAFE_TORNADUS_RECEIVED)
         && FlagGet(FLAG_BATTLE_CAFE_THUNDURUS_RECEIVED)
         && FlagGet(FLAG_BATTLE_CAFE_LANDORUS_RECEIVED))
            Achievement_Unlock(ACH_MASTER_OF_WISHES);
        break;
    }
}

void Achievement_CheckAll(void)
{
    u16 i;

    Achievement_EnsureSaveInitialized();
    for (i = 0; i < ARRAY_COUNT(sAchievements); i++)
    {
        const struct Achievement *achievement = &sAchievements[i];

        if (Achievement_IsUnlocked(achievement->id))
            continue;
        if (achievement->counter != ACH_COUNTER_NONE
         && Achievement_GetCounter(achievement->counter) >= achievement->targetValue)
            Achievement_Unlock(achievement->id);
        else if (achievement->predicate != NULL && achievement->predicate())
            Achievement_Unlock(achievement->id);
    }
}

void Achievement_CheckCounter(enum AchievementCounter counter)
{
    u16 i;

    if (counter == ACH_COUNTER_NONE)
        return;
    Achievement_EnsureSaveInitialized();
    for (i = 0; i < ARRAY_COUNT(sAchievements); i++)
    {
        const struct Achievement *achievement = &sAchievements[i];

        if (achievement->counter == counter
         && !Achievement_IsUnlocked(achievement->id)
         && Achievement_GetCounter(counter) >= achievement->targetValue)
            Achievement_Unlock(achievement->id);
    }
}

void Achievement_UnlockHallOfFameDebut(void)
{
    Achievement_Unlock(ACH_HALL_OF_FAME_DEBUT);
}

void Achievement_IncrementCounter(enum AchievementCounter counter, u32 amount)
{
    u8 gameStat;
    u32 value;

    switch (counter)
    {
    case ACH_COUNTER_MONEY_SPENT:
        gameStat = GAME_STAT_MONEY_SPENT;
        break;
    case ACH_COUNTER_MONEY_EARNED:
        gameStat = GAME_STAT_MONEY_EARNED;
        break;
    default:
        gameStat = NUM_GAME_STATS;
        break;
    }

    if (gameStat != NUM_GAME_STATS)
    {
        value = GetGameStat(gameStat);
        if (UINT_MAX - value < amount)
            value = UINT_MAX;
        else
            value += amount;
        SetGameStat(gameStat, value);
        Achievement_CheckCounter(counter);
        return;
    }

    if (counter >= ACH_COUNTER_COUNT)
        return;

    Achievement_EnsureSaveInitialized();
    if (UINT_MAX - gSaveBlock1Ptr->achievements.counters[counter] < amount)
        gSaveBlock1Ptr->achievements.counters[counter] = UINT_MAX;
    else
        gSaveBlock1Ptr->achievements.counters[counter] += amount;

    Achievement_CheckCounter(counter);
}

void Achievement_AddBattlePointsEarned(u32 amount)
{
    u32 total = gSaveBlock2Ptr->frontier.cardBattlePoints + amount;

    if (total > 0xFFFF)
        total = 0xFFFF;
    gSaveBlock2Ptr->frontier.cardBattlePoints = total;
    Achievement_CheckCounter(ACH_COUNTER_BATTLE_POINTS_EARNED);
}

void Achievement_SetCounterMax(enum AchievementCounter counter, u32 value)
{
    if (counter >= ACH_COUNTER_COUNT)
        return;

    Achievement_EnsureSaveInitialized();
    if (gSaveBlock1Ptr->achievements.counters[counter] < value)
    {
        gSaveBlock1Ptr->achievements.counters[counter] = value;
        Achievement_CheckCounter(counter);
    }
}

void Achievement_MigrateBattlePyramidFloorClears(void)
{
    if (FlagGet(FLAG_PYRAMID_ACHIEVEMENT_MIGRATION_COMPLETE))
        return;

    SetGameStat(GAME_STAT_BATTLE_PYRAMID_FLOORS, Achievement_GetBestBattlePyramidFloorStreak());
    FlagSet(FLAG_PYRAMID_ACHIEVEMENT_MIGRATION_COMPLETE);
    Achievement_CheckCounter(ACH_COUNTER_BATTLE_PYRAMID_ROUNDS);
}

void Achievement_RecordBattlePyramidFloorClear(void)
{
    IncrementGameStat(GAME_STAT_BATTLE_PYRAMID_FLOORS);
    Achievement_CheckCounter(ACH_COUNTER_BATTLE_PYRAMID_ROUNDS);
}

void Achievement_OnTrainerDefeated(u16 trainerId)
{
    u16 i;

    for (i = 0; i < ARRAY_COUNT(sAchievements); i++)
    {
        if (sAchievements[i].trainerId == trainerId)
            Achievement_Unlock(sAchievements[i].id);
    }
    Achievement_CheckAll();
}
