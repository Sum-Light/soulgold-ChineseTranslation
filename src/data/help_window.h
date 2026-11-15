// Add new IDs here
enum {
    HELP_START_MENU,
    HELP_MEGA_EVOLUTION,
    HELP_MASTER_BALL,
    HELP_GIMMIGHOUL_COINS,
    HELP_COUNT
};

// Add entries here
// These entries are example entries which you can replace, but they exist to get you started.
const struct HelpWindow gHelpWindowInfo[] =
{
    [HELP_START_MENU] =
    {
        .header = COMPOUND_STRING("说明：宝可梦图鉴"),
        .desc = COMPOUND_STRING("想打开宝可梦图鉴的话，\n请在地图上按{START_BUTTON}！"
                                ""
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL
    },
    [HELP_MEGA_EVOLUTION] =
    {
        .header = COMPOUND_STRING("说明：超级进化"),
        .desc = COMPOUND_STRING("对战中按{START_BUTTON}就能超级进化！\n\n宝可梦必须携带对应的超级石\n才能进行超级进化。\n每场对战只能超级进化1次。"
                                ""
                                ""
                                ""
                            ),
    },
    [HELP_MASTER_BALL] =
    {
        .header = COMPOUND_STRING("说明：大师球"),
        .desc = COMPOUND_STRING("宝可梦游戏里只有1个大师球，\n请谨慎使用！\n大木博士建议把它用在想加入\n队伍却很难捕捉的宝可梦身上，\n比如大嘴雀或毒刺水母！"
                                ""
                                ""
                                ""
                                ""
                            ),
    },
    [HELP_GIMMIGHOUL_COINS] =
    {
        .header = COMPOUND_STRING("说明：索财灵进化为赛富豪"),
        .desc = COMPOUND_STRING("要让索财灵进化为赛富豪，\n需要收集999枚{COLOR RED}索财灵的硬币{COLOR DARK_GRAY}。\n\n索财灵的硬币散落在\n帕底亚各地。"
                                ""
                                ""
                                ""
                            ),
        .headerFont = FONT_NARROWER,
    },
    // Add more entries
};