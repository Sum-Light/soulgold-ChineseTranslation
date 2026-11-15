// Dialogue selected from the user-provided XY/ORAS Maison quote transcriptions.
// Longer lines are trimmed or reflowed to fit the two-line facility text box.
static const struct FacilityTrainerQuote sYouthQuotes[] =
{
    {
        .before = COMPOUND_STRING("嘻嘻嘻……"),
        .win = COMPOUND_STRING("嘻嘻嘻！"),
        .lose = COMPOUND_STRING("呜呜呜……"),
    },
    {
        .before = COMPOUND_STRING("我就是英雄！\n我绝对不会输！"),
        .win = COMPOUND_STRING("我果然是英雄！\n我打败坏蛋啦！"),
        .lose = COMPOUND_STRING("英雄是不会输的。\n英雄是不会死的。"),
    },
    {
        .before = COMPOUND_STRING("好嘞！上吧！"),
        .win = COMPOUND_STRING("呀吼！呀—吼！\n成功啦！我又赢啦！"),
        .lose = COMPOUND_STRING("不！我输了！"),
    },
    {
        .before = COMPOUND_STRING("妈妈！爸爸！看着我！\n我会加油的！"),
        .win = COMPOUND_STRING("妈妈！爸爸！你们看到了吗？\n我可厉害了！"),
        .lose = COMPOUND_STRING("妈妈、爸爸……我输了……\n帮我报仇啊……"),
    },
};

static const struct FacilityTrainerQuote sSchoolQuotes[] =
{
    {
        .before = COMPOUND_STRING("嘀嘀咕咕……"),
        .win = COMPOUND_STRING("嘀嘀咕咕……\n咦？我赢了吗？"),
        .lose = COMPOUND_STRING("嘀嘀咕咕……\n哦？这就结束了？"),
    },
    {
        .before = COMPOUND_STRING("……嘿嘿。我对自己的\n计算和分析很有信心。"),
        .win = COMPOUND_STRING("嘿嘿。完全在我的计划之中……\n我是不可能输的。"),
        .lose = COMPOUND_STRING("噢……也许计算\n终究敌不过偶然……"),
    },
    {
        .before = COMPOUND_STRING("我是来这里偷懒的。\n我不想死读书……"),
        .win = COMPOUND_STRING("现在可不能输……\n我不想学习！"),
        .lose = COMPOUND_STRING("不要！我不想回家！\n我不想学习！"),
    },
    {
        .before = COMPOUND_STRING("呜哇哈哈哈哈……\n请协助我做个实验吧。"),
        .win = COMPOUND_STRING("呜哇哈哈哈……成了！\n实验成功了。"),
        .lose = COMPOUND_STRING("唉。这可不妙……\n实验失败了。"),
    },
};

static const struct FacilityTrainerQuote sWealthQuotes[] =
{
    {
        .before = COMPOUND_STRING("啊哈哈哈！"),
        .win = COMPOUND_STRING("啊哈哈哈！！！"),
        .lose = COMPOUND_STRING("啊哈哈—呃啊……"),
    },
    {
        .before = COMPOUND_STRING("被选中的训练家，\n会选择被选中的宝可梦。"),
        .win = COMPOUND_STRING("看来胜利\n选择了我。"),
        .lose = COMPOUND_STRING("看来我是被选中\n来输的那一个……"),
    },
    {
        .before = COMPOUND_STRING("没错！我就是富家少爷！"),
        .win = COMPOUND_STRING("再见！你被富家少爷\n打败啦！"),
        .lose = COMPOUND_STRING("谢谢！Merci bien！\n你打败了富家少爷！"),
    },
    {
        .before = COMPOUND_STRING("我就长话短说吧。\n你赢不了我。"),
        .win = COMPOUND_STRING("你赢不了，\n因为你太弱了。"),
        .lose = COMPOUND_STRING("唔……你很不错。\n你真的相当不错。"),
    },
};

static const struct FacilityTrainerQuote sBeautyQuotes[] =
{
    {
        .before = COMPOUND_STRING("我人生中最后一场对战……\n就把这场比赛当成那样吧。"),
        .win = COMPOUND_STRING("总有一天我们会再见的……\n呵。要是真能那样就好了……"),
        .lose = COMPOUND_STRING("真开心……改天再来一场\n“最后的对战”吧。"),
    },
    {
        .before = COMPOUND_STRING("真好啊……\n你还是个孩子……"),
        .win = COMPOUND_STRING("我已经成了世故的大人，\n所以连对战都会耍诈。"),
        .lose = COMPOUND_STRING("那时候的我多么纯真啊……\n那个女孩去哪儿了呢？"),
    },
    {
        .before = COMPOUND_STRING("准备好迎接大赛了吗？\n帽子戴正了没有？"),
        .win = COMPOUND_STRING("哎呀呀！我的宝可梦\n打出了一记全垒打！"),
        .lose = COMPOUND_STRING("嘿，又出局了。那又怎样？\n我们会扳回来的！"),
    },
    {
        .before = COMPOUND_STRING("嘿，训练家！\n你觉得我是大人吗？"),
        .win = COMPOUND_STRING("嘻嘻……我赢了，\n因为我是大人嘛！"),
        .lose = COMPOUND_STRING("嘻嘻！妆是妈妈帮我化的！\n其实我才7岁！"),
    },
};

static const struct FacilityTrainerQuote sVeteranQuotes[] =
{
    {
        .before = COMPOUND_STRING("哦……训练家……是不是\n该……对战了？"),
        .win = COMPOUND_STRING("哦……训练家……是不是\n该……对战了？"),
        .lose = COMPOUND_STRING("哦……训练家……是不是\n该……对战了？"),
    },
    {
        .before = COMPOUND_STRING("真正的绅士，内心\n在对战中绝不动摇。"),
        .win = COMPOUND_STRING("哈……嘻嘻嘻……\n我……笑得停不下来……"),
        .lose = COMPOUND_STRING("呜……呜……\n我……哭得停不下来……"),
    },
    {
        .before = COMPOUND_STRING("让我来评估一下你的实力。"),
        .win = COMPOUND_STRING("作为训练家，你的水平\n相当于幼儿园小朋友。"),
        .lose = COMPOUND_STRING("作为训练家，你的水平\n相当于宝可梦发烧友。"),
    },
    {
        .before = COMPOUND_STRING("我就长话短说吧。\n你赢不了我。"),
        .win = COMPOUND_STRING("你赢不了，\n因为你太弱了。"),
        .lose = COMPOUND_STRING("唔……你很不错。\n你真的相当不错。"),
    },
};

static const struct FacilityTrainerQuote sAceQuotes[] =
{
    {
        .before = COMPOUND_STRING("呜哇哈哈！我的不败传说\n就从你开始！"),
        .win = COMPOUND_STRING("我完全是无敌的！\n我的传说就从这里开始！"),
        .lose = COMPOUND_STRING("哈……你是想说，\n你的传说才刚刚开始？"),
    },
    {
        .before = COMPOUND_STRING("立刻站住！说的就是你！\n来与我交锋吧！"),
        .win = COMPOUND_STRING("训练家，你已任我处置！"),
        .lose = COMPOUND_STRING("训练家，我认输！\n请饶了我吧！"),
    },
    {
        .before = COMPOUND_STRING("这个故事的主角……\n我来告诉你是谁！"),
        .win = COMPOUND_STRING("主角就是我！\n你只是个跑龙套的！"),
        .lose = COMPOUND_STRING("当然，你才是\n主角！"),
    },
    {
        .before = COMPOUND_STRING("让我在这里\n终结你的连胜吧。"),
        .win = COMPOUND_STRING("你要学的还多着呢。\n我来给你上一堂速成课！"),
        .lose = COMPOUND_STRING("你不是一个人赢的。\n是你的宝可梦帮了你。"),
    },
};

static const struct FacilityTrainerQuote sMartialQuotes[] =
{
    {
        .before = COMPOUND_STRING("哟！"),
        .win = COMPOUND_STRING("哟！哟！哟！"),
        .lose = COMPOUND_STRING("哟！"),
    },
    {
        .before = COMPOUND_STRING("准备好了吗？\n我要动真格的了。"),
        .win = COMPOUND_STRING("你根本不是我的对手。\n这简直像在欺负人。"),
        .lose = COMPOUND_STRING("啊……真不敢相信我输了！\n你到底是谁？！"),
    },
    {
        .before = COMPOUND_STRING("来一场愉快的对战吧！\n输赢都别往心里去！"),
        .win = COMPOUND_STRING("别那么垂头丧气嘛！\n我只是碰巧运气好！"),
        .lose = COMPOUND_STRING("嘿……"),
    },
    {
        .before = COMPOUND_STRING("敢来挑战我，\n你的勇气值得称赞！"),
        .win = COMPOUND_STRING("对付你，还用不着\n我最强的踢技。"),
        .lose = COMPOUND_STRING("我强力的踢技\n一点用都没有。"),
    },
};

static const struct FacilityTrainerQuote sMysticQuotes[] =
{
    {
        .before = COMPOUND_STRING("……别过来。"),
        .win = COMPOUND_STRING("……走开。"),
        .lose = COMPOUND_STRING("……再见。"),
    },
    {
        .before = COMPOUND_STRING("我的妖精说，\n要把你打倒！"),
        .win = COMPOUND_STRING("是我的妖精叫我这么做的！\n全都怪我的妖精！"),
        .lose = COMPOUND_STRING("我的妖精说，\n你危险得不得了！"),
    },
    {
        .before = COMPOUND_STRING("嘿！集中精神！"),
        .win = COMPOUND_STRING("呼—！"),
        .lose = COMPOUND_STRING("咿呀—！"),
    },
    {
        .before = COMPOUND_STRING("嘿嘿嘿。你要是输了，\n我就把你变成宝可梦。"),
        .win = COMPOUND_STRING("嘿嘿嘿。从今天起，\n你就已经是宝可梦了！"),
        .lose = COMPOUND_STRING("下一次，我会用我的力量\n把你变成宝可梦。"),
    },
};

static const struct FacilityTrainerQuote sNatureQuotes[] =
{
    {
        .before = COMPOUND_STRING("当一名宝可梦培育家，\n要操心的事可多了。"),
        .win = COMPOUND_STRING("最开心的，\n就是和宝可梦变得亲近。"),
        .lose = COMPOUND_STRING("最难受的，\n就是和宝可梦道别。"),
    },
    {
        .before = COMPOUND_STRING("我是个园丁，\n不过宝可梦对战也很拿手。"),
        .win = COMPOUND_STRING("也许我该试着\n去当个冠军。"),
        .lose = COMPOUND_STRING("我是个园丁，\n所以本职工作是园艺。"),
    },
    {
        .before = COMPOUND_STRING("让我来考验一下\n你培育的宝可梦。"),
        .win = COMPOUND_STRING("哼！你就这点本事吗？\n我还以为会更厉害呢……"),
        .lose = COMPOUND_STRING("哇！你真了不起！\n把宝可梦培育得这么出色！"),
    },
    {
        .before = COMPOUND_STRING("我把它们培育得太强了。\n已经不受我控制了……"),
        .win = COMPOUND_STRING("一切都完了……\n谁也阻止不了它们了……"),
        .lose = COMPOUND_STRING("它们终于平静下来了……\n你救了我。谢谢你！"),
    },
};

static const struct FacilityTrainerQuote sTravelerQuotes[] =
{
    {
        .before = COMPOUND_STRING("啦啦啦啦……啦啦啦啦……\n我是独行侠……"),
        .win = COMPOUND_STRING("啦啦啦啦……啦啦啦啦……\n像云一样漂泊……"),
        .lose = COMPOUND_STRING("啦啦啦啦……啦啦啦啦……\n后会有期……"),
    },
    {
        .before = COMPOUND_STRING("我可不是普通的登山男。\n请叫我登山家。"),
        .win = COMPOUND_STRING("像我这样的山痴，\n就叫作登山家。"),
        .lose = COMPOUND_STRING("精通山岳的专家。\n那就是登山家。"),
    },
    {
        .before = COMPOUND_STRING("哼！哈噜—！"),
        .win = COMPOUND_STRING("哈噜—！"),
        .lose = COMPOUND_STRING("哼！！"),
    },
    {
        .before = COMPOUND_STRING("不管是宝可梦还是人生，\n都放轻松一点吧。"),
        .win = COMPOUND_STRING("拼命努力是可以的。\n不过也得留点喘息的余地。"),
        .lose = COMPOUND_STRING("没关系，没关系。\n我还会有机会的。"),
    },
};

static const struct FacilityTrainerQuote sWaterQuotes[] =
{
    {
        .before = COMPOUND_STRING("这是粗糙皮肤，对吧？！\n雨盘、雨盘？"),
        .win = COMPOUND_STRING("这不是粗糙皮肤！\n雨盘、雨盘。"),
        .lose = COMPOUND_STRING("这是粗糙皮肤，对吧？！\n雨盘、雨盘……"),
    },
    {
        .before = COMPOUND_STRING("天气太糟糕了，\n我没法干活！"),
        .win = COMPOUND_STRING("哇！我现在的心情\n就像大晴天一样！！"),
        .lose = COMPOUND_STRING("要是我的特性\n是雨盘就好了……"),
    },
    {
        .before = COMPOUND_STRING("清澈湛蓝的海水！\n沙滩！到处都是比基尼！"),
        .win = COMPOUND_STRING("这里凭什么叫度假地啊？\n来的全是认真的训练家！"),
        .lose = COMPOUND_STRING("这哪是度假地—简直是\n折磨！到处都是对战！"),
    },
};

static const struct FacilityTrainerQuote sAthleteQuotes[] =
{
    {
        .before = COMPOUND_STRING("呜哇哈哈！我的不败传说\n就从你开始！"),
        .win = COMPOUND_STRING("我完全是无敌的！\n我的传说就从这里开始！"),
        .lose = COMPOUND_STRING("哈……你是想说，\n你的传说才刚刚开始？"),
    },
    {
        .before = COMPOUND_STRING("我的战术，就是用速度\n迷惑对手。"),
        .win = COMPOUND_STRING("啊哈哈……怎么样？\n把你转晕了吧。"),
        .lose = COMPOUND_STRING("你怎么会比我还快？\n你穿的是什么啊？"),
    },
    {
        .before = COMPOUND_STRING("我的轮滑鞋\n可没有刹车！"),
        .win = COMPOUND_STRING("我不会停！也停不下来！\n这就是我的滑法！"),
        .lose = COMPOUND_STRING("这鞋肯定有毛病！\n来人啊！谁都行！快让我停下！"),
    },
    {
        .before = COMPOUND_STRING("我们一起痛痛快快地\n出身汗吧，好吗？"),
        .win = COMPOUND_STRING("嘿，别太在意……\n有时候就得学会放手。"),
        .lose = COMPOUND_STRING("你让我捏了一把冷汗！\n这就是年轻啊！"),
    },
};

static const struct FacilityTrainerQuote sEnthusiastQuotes[] =
{
    {
        .before = COMPOUND_STRING("听好了，我爱宝可梦\n胜过自己的生命！"),
        .win = COMPOUND_STRING("我下辈子\n要当宝可梦。"),
        .lose = COMPOUND_STRING("我也好喜欢你的宝可梦！\n拜托，让我摸摸它们吧！"),
    },
    {
        .before = COMPOUND_STRING("想看看我最引以为傲的\n宝可梦吗？"),
        .win = COMPOUND_STRING("你觉得我心爱的宝可梦\n怎么样？很棒吧？"),
        .lose = COMPOUND_STRING("哎呀，天哪！\n我可怜的宝可梦……"),
    },
    {
        .before = COMPOUND_STRING("我认为我是宝可梦发烧友，\n所以我就是宝可梦发烧友。"),
        .win = COMPOUND_STRING("宝可梦发烧友就是力量。"),
        .lose = COMPOUND_STRING("记住了：\n我是宝可梦发烧友。"),
    },
    {
        .before = COMPOUND_STRING("加入宝可梦发烧友俱乐部吧！\n你的人生会变得幸福！"),
        .win = COMPOUND_STRING("加入宝可梦发烧友俱乐部吧！\n你会变得像我一样强！"),
        .lose = COMPOUND_STRING("加入宝可梦发烧友俱乐部吧！\n你的人生会得到拯救！"),
    },
};

static const struct FacilityTrainerQuote sPerformerQuotes[] =
{
    {
        .before = COMPOUND_STRING("和我对战，\n考验的是你的审美感觉。"),
        .win = COMPOUND_STRING("嗯……还不错……\n你有超现实的一面……"),
        .lose = COMPOUND_STRING("嗯……还不错……\n你有写实的一面……"),
    },
    {
        .before = COMPOUND_STRING("宝可梦每动一下，\n我的心就跟着颤抖！"),
        .win = COMPOUND_STRING("没有什么比宝可梦的招式\n更能触动灵魂了。"),
        .lose = COMPOUND_STRING("宝可梦的招式太美了！\n我都快晕过去了！"),
    },
    {
        .before = COMPOUND_STRING("我的宝可梦会压过你的！\n赌你输准没错！"),
        .win = COMPOUND_STRING("好！胜利是我的了！\n幸运女神在对我微笑！"),
        .lose = COMPOUND_STRING("啊……我输得精光……\n什么都不剩了……"),
    },
    {
        .before = COMPOUND_STRING("那好吧。我看着。\n尽情释放你的热情吧！"),
        .win = COMPOUND_STRING("什么？这就结束了？\n我可不答应！"),
        .lose = COMPOUND_STRING("你确定吗？你不觉得\n自己还能继续吗？"),
    },
};

static const struct FacilityTrainerQuote sBreederQuotes[] =
{
    {
        .before = COMPOUND_STRING("当一名宝可梦培育家，\n要操心的事可多了。"),
        .win = COMPOUND_STRING("最开心的，\n就是和宝可梦变得亲近。"),
        .lose = COMPOUND_STRING("最难受的，\n就是和宝可梦道别。"),
    },
    {
        .before = COMPOUND_STRING("我把它们培育得太强了。\n已经不受我控制了……"),
        .win = COMPOUND_STRING("一切都完了……\n谁也阻止不了它们了……"),
        .lose = COMPOUND_STRING("它们终于平静下来了……\n你救了我。谢谢你！"),
    },
    {
        .before = COMPOUND_STRING("我是顶尖的培育家。\n任何宝可梦我都能驯服。"),
        .win = COMPOUND_STRING("看到了吧？我的宝可梦\n对我非常忠诚，对吧？"),
        .lose = COMPOUND_STRING("它们太黏我了。\n不适合对战。"),
    },
    {
        .before = COMPOUND_STRING("让我来考验一下\n你培育的宝可梦。"),
        .win = COMPOUND_STRING("哼！你就这点本事吗？\n我还以为会更厉害呢……"),
        .lose = COMPOUND_STRING("哇！你真了不起！\n把宝可梦培育得这么出色！"),
    },
};

enum FacilityQuotePoolId
{
    FACILITY_QUOTE_POOL_NONE,
    FACILITY_QUOTE_POOL_YOUTH,
    FACILITY_QUOTE_POOL_SCHOOL,
    FACILITY_QUOTE_POOL_WEALTH,
    FACILITY_QUOTE_POOL_BEAUTY,
    FACILITY_QUOTE_POOL_VETERAN,
    FACILITY_QUOTE_POOL_ACE,
    FACILITY_QUOTE_POOL_MARTIAL,
    FACILITY_QUOTE_POOL_MYSTIC,
    FACILITY_QUOTE_POOL_NATURE,
    FACILITY_QUOTE_POOL_TRAVELER,
    FACILITY_QUOTE_POOL_WATER,
    FACILITY_QUOTE_POOL_ATHLETE,
    FACILITY_QUOTE_POOL_ENTHUSIAST,
    FACILITY_QUOTE_POOL_PERFORMER,
    FACILITY_QUOTE_POOL_BREEDER,
};

#define QUOTE_POOL(quotes_)             \
    {                                   \
        .quotes = quotes_,              \
        .count = ARRAY_COUNT(quotes_),  \
    }

static const struct FacilityTrainerQuotePool sFacilityTrainerQuotePools[] =
{
    [FACILITY_QUOTE_POOL_YOUTH] = QUOTE_POOL(sYouthQuotes),
    [FACILITY_QUOTE_POOL_SCHOOL] = QUOTE_POOL(sSchoolQuotes),
    [FACILITY_QUOTE_POOL_WEALTH] = QUOTE_POOL(sWealthQuotes),
    [FACILITY_QUOTE_POOL_BEAUTY] = QUOTE_POOL(sBeautyQuotes),
    [FACILITY_QUOTE_POOL_VETERAN] = QUOTE_POOL(sVeteranQuotes),
    [FACILITY_QUOTE_POOL_ACE] = QUOTE_POOL(sAceQuotes),
    [FACILITY_QUOTE_POOL_MARTIAL] = QUOTE_POOL(sMartialQuotes),
    [FACILITY_QUOTE_POOL_MYSTIC] = QUOTE_POOL(sMysticQuotes),
    [FACILITY_QUOTE_POOL_NATURE] = QUOTE_POOL(sNatureQuotes),
    [FACILITY_QUOTE_POOL_TRAVELER] = QUOTE_POOL(sTravelerQuotes),
    [FACILITY_QUOTE_POOL_WATER] = QUOTE_POOL(sWaterQuotes),
    [FACILITY_QUOTE_POOL_ATHLETE] = QUOTE_POOL(sAthleteQuotes),
    [FACILITY_QUOTE_POOL_ENTHUSIAST] = QUOTE_POOL(sEnthusiastQuotes),
    [FACILITY_QUOTE_POOL_PERFORMER] = QUOTE_POOL(sPerformerQuotes),
    [FACILITY_QUOTE_POOL_BREEDER] = QUOTE_POOL(sBreederQuotes),
};

static const u8 sFacilityClassQuotePoolIds[FACILITY_CLASSES_COUNT] =
{
    [FACILITY_CLASS_HIKER] = FACILITY_QUOTE_POOL_TRAVELER,
    [FACILITY_CLASS_PKMN_BREEDER_F] = FACILITY_QUOTE_POOL_BREEDER,
    [FACILITY_CLASS_COOLTRAINER_M] = FACILITY_QUOTE_POOL_ACE,
    [FACILITY_CLASS_BIRD_KEEPER] = FACILITY_QUOTE_POOL_NATURE,
    [FACILITY_CLASS_COLLECTOR] = FACILITY_QUOTE_POOL_ENTHUSIAST,
    [FACILITY_CLASS_SWIMMER_M] = FACILITY_QUOTE_POOL_WATER,
    [FACILITY_CLASS_EXPERT_M] = FACILITY_QUOTE_POOL_VETERAN,
    [FACILITY_CLASS_BLACK_BELT] = FACILITY_QUOTE_POOL_MARTIAL,
    [FACILITY_CLASS_HEX_MANIAC] = FACILITY_QUOTE_POOL_MYSTIC,
    [FACILITY_CLASS_AROMA_LADY] = FACILITY_QUOTE_POOL_NATURE,
    [FACILITY_CLASS_RUIN_MANIAC] = FACILITY_QUOTE_POOL_TRAVELER,
    [FACILITY_CLASS_TUBER_F] = FACILITY_QUOTE_POOL_YOUTH,
    [FACILITY_CLASS_TUBER_M] = FACILITY_QUOTE_POOL_YOUTH,
    [FACILITY_CLASS_COOLTRAINER_F] = FACILITY_QUOTE_POOL_ACE,
    [FACILITY_CLASS_LADY] = FACILITY_QUOTE_POOL_WEALTH,
    [FACILITY_CLASS_BEAUTY] = FACILITY_QUOTE_POOL_BEAUTY,
    [FACILITY_CLASS_RICH_BOY] = FACILITY_QUOTE_POOL_WEALTH,
    [FACILITY_CLASS_EXPERT_F] = FACILITY_QUOTE_POOL_VETERAN,
    [FACILITY_CLASS_POKEMANIAC] = FACILITY_QUOTE_POOL_ENTHUSIAST,
    [FACILITY_CLASS_GUITARIST] = FACILITY_QUOTE_POOL_PERFORMER,
    [FACILITY_CLASS_KINDLER] = FACILITY_QUOTE_POOL_PERFORMER,
    [FACILITY_CLASS_CAMPER] = FACILITY_QUOTE_POOL_NATURE,
    [FACILITY_CLASS_PICNICKER] = FACILITY_QUOTE_POOL_NATURE,
    [FACILITY_CLASS_BUG_MANIAC] = FACILITY_QUOTE_POOL_ENTHUSIAST,
    [FACILITY_CLASS_PSYCHIC_M] = FACILITY_QUOTE_POOL_MYSTIC,
    [FACILITY_CLASS_PSYCHIC_F] = FACILITY_QUOTE_POOL_MYSTIC,
    [FACILITY_CLASS_GENTLEMAN] = FACILITY_QUOTE_POOL_WEALTH,
    [FACILITY_CLASS_SCHOOL_KID_M] = FACILITY_QUOTE_POOL_SCHOOL,
    [FACILITY_CLASS_SCHOOL_KID_F] = FACILITY_QUOTE_POOL_SCHOOL,
    [FACILITY_CLASS_POKEFAN_M] = FACILITY_QUOTE_POOL_ENTHUSIAST,
    [FACILITY_CLASS_POKEFAN_F] = FACILITY_QUOTE_POOL_ENTHUSIAST,
    [FACILITY_CLASS_YOUNGSTER] = FACILITY_QUOTE_POOL_YOUTH,
    [FACILITY_CLASS_FISHERMAN] = FACILITY_QUOTE_POOL_WATER,
    [FACILITY_CLASS_CYCLING_TRIATHLETE_M] = FACILITY_QUOTE_POOL_ATHLETE,
    [FACILITY_CLASS_CYCLING_TRIATHLETE_F] = FACILITY_QUOTE_POOL_ATHLETE,
    [FACILITY_CLASS_RUNNING_TRIATHLETE_M] = FACILITY_QUOTE_POOL_ATHLETE,
    [FACILITY_CLASS_RUNNING_TRIATHLETE_F] = FACILITY_QUOTE_POOL_ATHLETE,
    [FACILITY_CLASS_SWIMMING_TRIATHLETE_M] = FACILITY_QUOTE_POOL_WATER,
    [FACILITY_CLASS_SWIMMING_TRIATHLETE_F] = FACILITY_QUOTE_POOL_WATER,
    [FACILITY_CLASS_DRAGON_TAMER] = FACILITY_QUOTE_POOL_ACE,
    [FACILITY_CLASS_NINJA_BOY] = FACILITY_QUOTE_POOL_YOUTH,
    [FACILITY_CLASS_BATTLE_GIRL] = FACILITY_QUOTE_POOL_MARTIAL,
    [FACILITY_CLASS_PARASOL_LADY] = FACILITY_QUOTE_POOL_NATURE,
    [FACILITY_CLASS_SWIMMER_F] = FACILITY_QUOTE_POOL_WATER,
    [FACILITY_CLASS_SAILOR] = FACILITY_QUOTE_POOL_WATER,
    [FACILITY_CLASS_PKMN_BREEDER_M] = FACILITY_QUOTE_POOL_BREEDER,
    [FACILITY_CLASS_BUG_CATCHER] = FACILITY_QUOTE_POOL_YOUTH,
    [FACILITY_CLASS_PKMN_RANGER_M] = FACILITY_QUOTE_POOL_NATURE,
    [FACILITY_CLASS_PKMN_RANGER_F] = FACILITY_QUOTE_POOL_NATURE,
    [FACILITY_CLASS_LASS] = FACILITY_QUOTE_POOL_YOUTH,
};

#undef QUOTE_POOL
