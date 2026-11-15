const struct AbilityInfo gAbilitiesInfo[ABILITIES_COUNT] =
{
    [ABILITY_NONE] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("没有特性"),
        .longDescription = COMPOUND_STRING("没有特殊的特性。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 0,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STENCH] =
    {
        .name = _("恶臭"),
        .description = COMPOUND_STRING("臭味有时会使对手畏缩"),
        .longDescription = COMPOUND_STRING("攻击招式有10%的几率\n使对手畏缩。\n排在队伍首位时，\n野生宝可梦的遇敌率\n降低50%。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 1,
    },

    [ABILITY_DRIZZLE] =
    {
        .name = _("降雨"),
        .description = COMPOUND_STRING("出场时，会将天气变为下雨"),
        .longDescription = COMPOUND_STRING("出场时，会在5回合内\n将天气变为下雨。"
                                           ""
                                           ""),
        .aiRating = 9,
    },

    [ABILITY_SPEED_BOOST] =
    {
        .name = _("加速"),
        .description = COMPOUND_STRING("每一回合速度会变快"),
        .longDescription = COMPOUND_STRING("每回合结束时，\n速度提高1级。"
                                           ""
                                           ""),
        .aiRating = 9,
    },

    [ABILITY_BATTLE_ARMOR] =
    {
        .name = _("战斗盔甲"),
        .description = COMPOUND_STRING("不会被攻击击中要害"),
        .longDescription = COMPOUND_STRING("受到的攻击\n不会击中要害。"
                                           ""
                                           ""),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_STURDY] =
    {
        .name = _("结实"),
        .description = COMPOUND_STRING("HP全满时不会被一击打倒"),
        .longDescription = COMPOUND_STRING("HP全满时，即使受到\n会被一击打倒的招式\n伤害，也会留下1HP\n撑住。"
                                           ""
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DAMP] =
    {
        .name = _("湿气"),
        .description = COMPOUND_STRING("双方无法使用爆炸类的招式"),
        .longDescription = COMPOUND_STRING("所有宝可梦都无法使出\n爆炸类的招式或特性。"
                                           ""
                                           ""),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_LIMBER] =
    {
        .name = _("柔软"),
        .description = COMPOUND_STRING("不会变为麻痹状态"),
        .longDescription = COMPOUND_STRING("因为身体柔软，\n不会陷入麻痹状态。"
                                           ""
                                           ""),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SAND_VEIL] =
    {
        .name = _("沙隐"),
        .description = COMPOUND_STRING("沙暴时，闪避率会提高"),
        .longDescription = COMPOUND_STRING("沙暴时，闪避率\n提高25%。\n排在队伍首位时，\n野生宝可梦的遇敌率\n降低50%。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_STATIC] =
    {
        .name = _("静电"),
        .description = COMPOUND_STRING("有时会让接触的对手麻痹"),
        .longDescription = COMPOUND_STRING("接触到自己的对手有\n30%的几率陷入麻痹。\n排在队伍首位时，\n更容易遇到电属性的\n宝可梦。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_VOLT_ABSORB] =
    {
        .name = _("蓄电"),
        .description = COMPOUND_STRING("受到电属性攻击时会回复"),
        .longDescription = COMPOUND_STRING("电属性的招式无效，\n反而会回复最大HP的\n1/4。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_WATER_ABSORB] =
    {
        .name = _("储水"),
        .description = COMPOUND_STRING("受到水属性攻击时会回复"),
        .longDescription = COMPOUND_STRING("水属性的招式无效，\n反而会回复最大HP的\n1/4。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_OBLIVIOUS] =
    {
        .name = _("迟钝"),
        .description = COMPOUND_STRING("不会因着迷挑衅威吓动摇"),
        .longDescription = COMPOUND_STRING("不会受到挑衅、着迷\n和威吓的影响。"
                                           ""
                                           ""),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_CLOUD_NINE] =
    {
        .name = _("无关天气"),
        .description = COMPOUND_STRING("任何天气的影响都会消失"),
        .longDescription = COMPOUND_STRING("天气的影响会消失。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_COMPOUND_EYES] =
    {
        .name = _("复眼"),
        .description = COMPOUND_STRING("招式的命中率会提高"),
        .longDescription = COMPOUND_STRING("招式的命中率\n提高30%。"
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_INSOMNIA] =
    {
        .name = _("不眠"),
        .description = COMPOUND_STRING("不会陷入睡眠状态"),
        .longDescription = COMPOUND_STRING("不会陷入瞌睡\n或睡眠状态。"
                                           ""
                                           ""),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_COLOR_CHANGE] =
    {
        .name = _("变色"),
        .description = COMPOUND_STRING("属性会变为对手招式的属性"),
        .longDescription = COMPOUND_STRING("自己的属性会变为\n所受招式的属性。"
                                           ""
                                           ""),
        .aiRating = 2,
    },

    [ABILITY_IMMUNITY] =
    {
        .name = _("免疫"),
        .description = COMPOUND_STRING("不会变为中毒状态"),
        .longDescription = COMPOUND_STRING("不会陷入中毒\n或剧毒状态。"
                                           ""
                                           ""),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_FLASH_FIRE] =
    {
        .name = _("引火"),
        .description = COMPOUND_STRING("受火属性攻击会强化火招式"),
        .longDescription = COMPOUND_STRING("吸收火属性招式，使自己\n的火属性招式威力提高\n50%。排在队伍首位时，\n更容易遇到火属性的\n宝可梦。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SHIELD_DUST] =
    {
        .name = _("鳞粉"),
        .description = COMPOUND_STRING("不会受到招式追加效果影响"),
        .longDescription = COMPOUND_STRING("不会受到攻击招式的\n追加效果影响。"
                                           ""
                                           ""),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_OWN_TEMPO] =
    {
        .name = _("我行我素"),
        .description = COMPOUND_STRING("不会被混乱或威吓"),
        .longDescription = COMPOUND_STRING("不会陷入"
                                           #if B_UPDATED_INTIMIDATE < GEN_8
                                           "混乱状态。"),
                                           #else
                                           "混乱状态，\n"
                                           "也不会受到"
                                           "威吓的影响。"),
                                           #endif
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SUCTION_CUPS] =
    {
        .name = _("吸盘"),
        .description = COMPOUND_STRING("让替换宝可梦的招式无效"),
        .longDescription = COMPOUND_STRING("不会被强制替换下场。\n排在队伍首位时，\n钓鱼时宝可梦更容易\n上钩。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_INTIMIDATE] =
    {
        .name = _("威吓"),
        .description = COMPOUND_STRING("出场时降低对手的攻击"),
        .longDescription = COMPOUND_STRING("出场时，对手的攻击\n降低1级。\n排在队伍首位时，\n比自己低5级以上的\n野生宝可梦的遇敌率\n降低50%。"
                                           ""
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_SHADOW_TAG] =
    {
        .name = _("踩影"),
        .description = COMPOUND_STRING("使对手无法逃走或替换"),
        .longDescription = COMPOUND_STRING("对手无法替换宝可梦。\n"
                                           ""
                                           #if B_SHADOW_TAG_ESCAPE < GEN_4
                                           "对幽灵属性宝可梦无效。"),
                                           #else
                                           "对幽灵属性宝可梦无效。\n"
                                           "对手也拥有踩影特性时\n"
                                           "该效果无效。"),
                                           #endif
        .aiRating = 10,
    },

    [ABILITY_ROUGH_SKIN] =
    {
        .name = _("粗糙皮肤"),
        .description = COMPOUND_STRING("受到攻击时弄伤接触的对手"),
        .longDescription = COMPOUND_STRING("受到接触类招式攻击时，\n对手会受到其最大HP\n1/8的伤害。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_WONDER_GUARD] =
    {
        .name = _("神奇守护"),
        .description = COMPOUND_STRING("只有效果绝佳招式才能击中"),
        .longDescription = COMPOUND_STRING("只有效果绝佳的招式\n才能造成伤害。\n间接伤害不受此限。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_LEVITATE] =
    {
        .name = _("飘浮"),
        .description = COMPOUND_STRING("不会受地面属性招式攻击"),
        .longDescription = COMPOUND_STRING("不会受到地面属性招式\n以及撒菱、毒菱、\n黏黏网的影响。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EFFECT_SPORE] =
    {
        .name = _("孢子"),
        .description = COMPOUND_STRING("有时会使接触的对手异常"),
        .longDescription = COMPOUND_STRING("受到接触类招式攻击时，\n"
                                           #if B_ABILITY_TRIGGER_CHANCE < GEN_4
                                           "有33%的几率使对手\n"
                                           #else
                                           "有30%的几率使对手\n"
                                           #endif
                                           "陷入中毒、睡眠\n或麻痹状态。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_SYNCHRONIZE] =
    {
        .name = _("同步"),
        .description = COMPOUND_STRING("将自己异常状态传染给对手"),
        .longDescription = COMPOUND_STRING("陷入麻痹、中毒或灼伤\n时，让造成该状态的对手\n陷入相同状态。\n排在队伍首位时，野生\n宝可梦的性格会与自己\n相同。"
                                           ""
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_CLEAR_BODY] =
    {
        .name = _("恒净之躯"),
        .description = COMPOUND_STRING("不会因为对手而被降低能力"),
        .longDescription = COMPOUND_STRING("不会因其他宝可梦的\n招式或特性而被降低\n能力。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_NATURAL_CURE] =
    {
        .name = _("自然回复"),
        .description = COMPOUND_STRING("被换下后治愈异常状态"),
        .longDescription = COMPOUND_STRING("替换下场时，\n异常状态会被治愈。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_LIGHTNING_ROD] =
    {
        .name = _("避雷针"),
        .description = COMPOUND_STRING("吸引免疫电招式并提高特攻"),
        .longDescription = COMPOUND_STRING("吸引电属性招式，\n使特攻提高1级。\n排在队伍首位时，\n更容易遇到电属性的\n宝可梦。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_SERENE_GRACE] =
    {
        .name = _("天恩"),
        .description = COMPOUND_STRING("招式的追加效果容易出现"),
        .longDescription = COMPOUND_STRING("自己使出招式时，\n追加效果的出现几率\n变为2倍。"
                                           ""
                                           ""
                                           ""
                                           #if B_SERENE_GRACE_BOOST < GEN_5
                                           "\n王者之证和锐利之牙\n的效果除外。"
                                           ""
                                           #endif
                                           ),
        .aiRating = 8,
    },

    [ABILITY_SWIFT_SWIM] =
    {
        .name = _("悠游自如"),
        .description = COMPOUND_STRING("下雨天气时，速度会提高"),
        .longDescription = COMPOUND_STRING("下雨时，\n速度变为2倍。"
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_CHLOROPHYLL] =
    {
        .name = _("叶绿素"),
        .description = COMPOUND_STRING("晴天时，速度会提高"),
        .longDescription = COMPOUND_STRING("晴天时，\n速度变为2倍。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_ILLUMINATE] =
    {
        .name = _("发光"),
        .description = COMPOUND_STRING("命中率不会被降低"),
        .longDescription = COMPOUND_STRING("野生宝可梦的遇敌率\n变为2倍。战斗中无视\n对手的闪避率变化，\n且命中率不会被降低。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_TRACE] =
    {
        .name = _("复制"),
        .description = COMPOUND_STRING("出场时，复制对手的特性"),
        .longDescription = COMPOUND_STRING("出场时，将自己的特性\n变为与对手相同的特性。\n部分特性除外。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE, //B_UPDATED_ABILITY_DATA >= GEN_4
    },

    [ABILITY_HUGE_POWER] =
    {
        .name = _("大力士"),
        .description = COMPOUND_STRING("物理攻击的威力会变为2倍"),
        .longDescription = COMPOUND_STRING("物理招式的威力\n变为2倍。"
                                           ""
                                           ""),
        .aiRating = 10,
    },

    [ABILITY_POISON_POINT] =
    {
        .name = _("毒刺"),
        .description = COMPOUND_STRING("有时会让接触到的对手中毒"),
        .longDescription = COMPOUND_STRING("受到接触类招式攻击时，\n"
                                           ""
                                           #if B_ABILITY_TRIGGER_CHANCE < GEN_4
                                           "对手有33%的几率\n"
                                           #else
                                           "对手有30%的几率\n"
                                           #endif
                                           "陷入中毒状态。"
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_INNER_FOCUS] =
    {
        .name = _("精神力"),
        .description = COMPOUND_STRING("不会畏缩或被威吓影响"),
        .longDescription = COMPOUND_STRING("受到攻击时\n"
                                           #if B_UPDATED_INTIMIDATE < GEN_8
                                           "不会畏缩。"),
                                           #else
                                           "不会畏缩，\n也不会受到威吓的影响。"
                                           ""
                                           ""),
                                           #endif

        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MAGMA_ARMOR] =
    {
        .name = _("熔岩铠甲"),
        .description = COMPOUND_STRING("不会变为冰冻状态"),
        .longDescription = COMPOUND_STRING("不会陷入冰冻状态。\n在队伍中时，\n蛋会更快孵化。"
                                           ""
                                           ""),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_WATER_VEIL] =
    {
        .name = _("水幕"),
        .description = COMPOUND_STRING("不会变为灼伤状态"),
        .longDescription = COMPOUND_STRING("因为有水幕包裹，\n不会陷入灼伤状态。"
                                           ""
                                           ""),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_MAGNET_PULL] =
    {
        .name = _("磁力"),
        .description = COMPOUND_STRING("使钢属性宝可梦无法逃走"),
        .longDescription = COMPOUND_STRING("让相邻的钢属性对手\n无法逃走或替换。\n排在队伍首位时，\n更容易遇到钢属性的\n宝可梦。"
                                           ""
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 9,
    },

    [ABILITY_SOUNDPROOF] =
    {
        .name = _("隔音"),
        .description = COMPOUND_STRING("不受到声音招式的影响"),
        .longDescription = COMPOUND_STRING("不会受到声音类招式\n的影响。"
                                           ""),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_RAIN_DISH] =
    {
        .name = _("雨盘"),
        .description = COMPOUND_STRING("下雨天气时，缓缓回复HP"),
        .longDescription = COMPOUND_STRING("下雨时，每回合结束时\n回复最大HP的1/16。"
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_SAND_STREAM] =
    {
        .name = _("扬沙"),
        .description = COMPOUND_STRING("出场时，会把天气变为沙暴"),
        .longDescription = COMPOUND_STRING("出场时，会在5回合内\n将天气变为沙暴。"
                                           ""
                                           ""),
        .aiRating = 9,
    },

    [ABILITY_PRESSURE] =
    {
        .name = _("压迫感"),
        .description = COMPOUND_STRING("减少对手使用招式的PP"),
        .longDescription = COMPOUND_STRING("对手向自己使出招式时，\n消耗的PP由1变为2。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_THICK_FAT] =
    {
        .name = _("厚脂肪"),
        .description = COMPOUND_STRING("使火冰属性的招式伤害减半"),
        .longDescription = COMPOUND_STRING("受到火属性和冰属性\n招式的伤害减半。"
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EARLY_BIRD] =
    {
        .name = _("早起"),
        .description = COMPOUND_STRING("睡眠时会提早醒来"),
        .longDescription = COMPOUND_STRING("从睡眠中醒来所需的\n回合数减半。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_FLAME_BODY] =
    {
        .name = _("火焰之躯"),
        .description = COMPOUND_STRING("有时会让接触的对手灼伤"),
        .longDescription = COMPOUND_STRING("接触到自己的对手有\n30%的几率陷入灼伤。\n在队伍中时，\n蛋会更快孵化。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_RUN_AWAY] =
    {
        .name = _("逃跑"),
        .description = COMPOUND_STRING("野生宝可梦面前一定能逃走"),
        .longDescription = COMPOUND_STRING("与野生宝可梦战斗时，\n即使处于无法逃走的\n状态也一定能逃走。"
                                           ""
                                           ""),
        .aiRating = 0,
    },

    [ABILITY_KEEN_EYE] =
    {
        .name = _("锐利目光"),
        .description = COMPOUND_STRING("命中率不会被降低"),
        .longDescription = COMPOUND_STRING("命中率不会被降低。\n此外，招式的命中率\n提高30%。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_HYPER_CUTTER] =
    {
        .name = _("怪力钳"),
        .description = COMPOUND_STRING("不会被对手降低攻击"),
        .longDescription = COMPOUND_STRING("不会因其他宝可梦的\n招式或特性而被降低\n攻击。"
                                           ""
                                           ""),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PICKUP] =
    {
        .name = _("捡拾"),
        .description = COMPOUND_STRING("有时会捡来对手用过的道具"),
        .longDescription = COMPOUND_STRING("没有携带道具时，战斗\n结束后有时会捡到道具。\n还能捡回自己用掉的\n携带道具。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 1,
    },

    [ABILITY_TRUANT] =
    {
        .name = _("懒惰"),
        .description = COMPOUND_STRING("每隔一回合就会休息"),
        .longDescription = COMPOUND_STRING("每隔1回合就会偷懒，\n无法使出招式。"
                                           ""
                                           ""),
        .aiRating = -2,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HUSTLE] =
    {
        .name = _("活力"),
        .description = COMPOUND_STRING("攻击变高，但命中率会降低"),
        .longDescription = COMPOUND_STRING("物理招式的伤害提高\n50%，但命中率会\n降至80%。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_CUTE_CHARM] =
    {
        .name = _("迷人之躯"),
        .description = COMPOUND_STRING("有时会让接触到的对手着迷"),
        .longDescription = COMPOUND_STRING("受到接触类招式攻击时，\n有30%的几率让性别\n不同的对手着迷。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 2,
    },

    [ABILITY_PLUS] =
    {
        .name = _("正电"),
        .description = COMPOUND_STRING("同伴正负电可提高特攻"),
        .longDescription = COMPOUND_STRING("场上的同伴拥有正电\n或负电特性时，\n特攻提高50%。"
                                           ""
                                           ""),
        .aiRating = 0,
    },

    [ABILITY_MINUS] =
    {
        .name = _("负电"),
        .description = COMPOUND_STRING("同伴正负电可提高特攻"),
        .longDescription = COMPOUND_STRING("场上的同伴拥有正电\n或负电特性时，\n特攻提高50%。"
                                           ""
                                           ""),
        .aiRating = 0,
    },

    [ABILITY_FORECAST] =
    {
        .name = _("阴晴不定"),
        .description = COMPOUND_STRING("受天气影响改变形态"),
        .longDescription = COMPOUND_STRING("下雨、晴天或冰雪天气\n时，飘浮泡泡会变为\n水、火或冰属性以及\n对应的样子。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_4,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_STICKY_HOLD] =
    {
        .name = _("黏着"),
        .description = COMPOUND_STRING("道具不会被对手夺走"),
        .longDescription = COMPOUND_STRING("携带的道具不会被\n其他宝可梦移除\n或夺走。"
                                           ""
                                           ""),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SHED_SKIN] =
    {
        .name = _("蜕皮"),
        .description = COMPOUND_STRING("有时会治愈异常状态"),
        .longDescription = COMPOUND_STRING("有时会通过蜕皮\n治愈自己的异常状态。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_GUTS] =
    {
        .name = _("毅力"),
        .description = COMPOUND_STRING("异常状态时攻击会提高"),
        .longDescription = COMPOUND_STRING("陷入异常状态时，\n攻击提高50%。\n灼伤造成的攻击降低\n也会被无视。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_MARVEL_SCALE] =
    {
        .name = _("神奇鳞片"),
        .description = COMPOUND_STRING("异常状态时防御会提高"),
        .longDescription = COMPOUND_STRING("陷入中毒等异常状态\n时，防御提高50%。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_LIQUID_OOZE] =
    {
        .name = _("污泥浆"),
        .description = COMPOUND_STRING("吸收污泥的对手会减少HP"),
        .longDescription = COMPOUND_STRING("从自己身上吸取HP的\n宝可梦不会回复，\n反而会减少HP。"
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_OVERGROW] =
    {
        .name = _("茂盛"),
        .description = COMPOUND_STRING("HP低时强化草属性招式"),
        .longDescription = COMPOUND_STRING("HP降到最大HP的1/3\n以下时，草属性招式的\n威力提高50%。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_BLAZE] =
    {
        .name = _("猛火"),
        .description = COMPOUND_STRING("HP低时强化火属性招式"),
        .longDescription = COMPOUND_STRING("HP降到最大HP的1/3\n以下时，火属性招式的\n威力提高50%。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_TORRENT] =
    {
        .name = _("激流"),
        .description = COMPOUND_STRING("HP低时强化水属性招式"),
        .longDescription = COMPOUND_STRING("HP降到最大HP的1/3\n以下时，水属性招式的\n威力提高50%。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_SWARM] =
    {
        .name = _("虫之预感"),
        .description = COMPOUND_STRING("HP低时强化虫属性招式"),
        .longDescription = COMPOUND_STRING("HP降到最大HP的1/3\n以下时，虫属性招式的\n威力提高50%。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_ROCK_HEAD] =
    {
        .name = _("坚硬脑袋"),
        .description = COMPOUND_STRING("不会受反作用力减少HP"),
        .longDescription = COMPOUND_STRING("使出攻击招式时，\n不会受到反作用力\n伤害。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_DROUGHT] =
    {
        .name = _("日照"),
        .description = COMPOUND_STRING("出场时，会将天气变为晴朗"),
        .longDescription = COMPOUND_STRING("在战斗中将天气变为\n晴朗。只要没有被气闸\n或无关天气抵消，\n就会持续5回合。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 9,
    },

    [ABILITY_ARENA_TRAP] =
    {
        .name = _("沙穴"),
        .description = COMPOUND_STRING("在战斗中让对手无法逃走"),
        .longDescription = COMPOUND_STRING("对手无法替换或逃走。\n对飞行属性或浮在空中\n的宝可梦无效。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 9,
    },

    [ABILITY_VITAL_SPIRIT] =
    {
        .name = _("干劲"),
        .description = COMPOUND_STRING("不会变为睡眠状态"),
        .longDescription = COMPOUND_STRING("充满干劲，不会陷入\n瞌睡或睡眠状态。"
                                           ""
                                           ""),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_WHITE_SMOKE] =
    {
        .name = _("白色烟雾"),
        .description = COMPOUND_STRING("不会被对手降低能力"),
        .longDescription = COMPOUND_STRING("不会被其他宝可梦\n降低能力。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_PURE_POWER] =
    {
        .name = _("瑜伽之力"),
        .description = COMPOUND_STRING("物理攻击的威力会变为2倍"),
        .longDescription = COMPOUND_STRING("攻击变为2倍。"
                                           ""),
        .aiRating = 10,
    },

    [ABILITY_SHELL_ARMOR] =
    {
        .name = _("硬壳盔甲"),
        .description = COMPOUND_STRING("对手的攻击不会击中要害"),
        .longDescription = COMPOUND_STRING("受到的攻击\n不会击中要害。"
                                           ""
                                           ""),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_AIR_LOCK] =
    {
        .name = _("气闸"),
        .description = COMPOUND_STRING("所有天气的影响都会消失"),
        .longDescription = COMPOUND_STRING("在场时，所有天气的\n影响都会消失。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_TANGLED_FEET] =
    {
        .name = _("蹒跚"),
        .description = COMPOUND_STRING("在混乱状态时闪避率会提高"),
        .longDescription = COMPOUND_STRING("混乱状态时，\n闪避率变为2倍。"
                                           ""
                                           ""),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MOTOR_DRIVE] =
    {
        .name = _("电气引擎"),
        .description = COMPOUND_STRING("免疫电属性攻击并提高速度"),
        .longDescription = COMPOUND_STRING("受到电属性招式攻击时，\n速度提高1级。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_RIVALRY] =
    {
        .name = _("斗争心"),
        .description = COMPOUND_STRING("对同性别对手变强反之变弱"),
        .longDescription = COMPOUND_STRING("对性别相同的宝可梦\n造成的伤害会提高。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 1,
    },

    [ABILITY_STEADFAST] =
    {
        .name = _("不屈之心"),
        .description = COMPOUND_STRING("每次畏缩时速度会提高"),
        .longDescription = COMPOUND_STRING("每次畏缩时，\n速度提高1级。"
                                           ""
                                           ""),
        .aiRating = 2,
    },

    [ABILITY_SNOW_CLOAK] =
    {
        .name = _("雪隐"),
        .description = COMPOUND_STRING("下雪天气时，闪避率会提高"),
        .longDescription = COMPOUND_STRING("冰雹或下雪时，闪避率\n提高20%。也不会受到\n冰雹的伤害。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_GLUTTONY] =
    {
        .name = _("贪吃鬼"),
        .description = COMPOUND_STRING("会在一半HP时提前吃树果"),
        .longDescription = COMPOUND_STRING("原本HP降到1/4时才会\n吃的树果，在HP降到\n1/2时就会吃掉。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_ANGER_POINT] =
    {
        .name = _("愤怒穴位"),
        .description = COMPOUND_STRING("要害被击中时攻击变为最大"),
        .longDescription = COMPOUND_STRING("被击中要害时，攻击\n会提高到最大的6级。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_UNBURDEN] =
    {
        .name = _("轻装"),
        .description = COMPOUND_STRING("失去道具时速度会提高"),
        .longDescription = COMPOUND_STRING("用掉或失去携带的道具\n时，速度变为2倍，\n直到离场或获得新的\n道具为止。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_HEATPROOF] =
    {
        .name = _("耐热"),
        .description = COMPOUND_STRING("受火属性招式的伤害减半"),
        .longDescription = COMPOUND_STRING("受到火属性招式的伤害\n和灼伤的伤害减半。"
                                           ""
                                           ""),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SIMPLE] =
    {
        .name = _("单纯"),
        .description = COMPOUND_STRING("能力变化会变为平时的2倍"),
        .longDescription = COMPOUND_STRING("自己的能力变化会变为\n2倍，但上下限仍为\n+6和-6。"
                                           ""
                                           ""),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_DRY_SKIN] =
    {
        .name = _("干燥皮肤"),
        .description = COMPOUND_STRING("雨天回复HP，晴天减少"),
        .longDescription = COMPOUND_STRING("下雨时回复1/8的HP，\n晴天时减少1/8的HP。\n会吸收水属性招式，\n受到火属性招式的伤害\n会增加。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DOWNLOAD] =
    {
        .name = _("下载"),
        .description = COMPOUND_STRING("根据情况提升攻击或特攻"),
        .longDescription = COMPOUND_STRING("出场时，对手的防御\n较低则攻击提高1级，\n特防较低则特攻提高\n1级。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_IRON_FIST] =
    {
        .name = _("铁拳"),
        .description = COMPOUND_STRING("使用拳类招式的威力会提高"),
        .longDescription = COMPOUND_STRING("拳类招式的威力\n提高20%。"
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_POISON_HEAL] =
    {
        .name = _("毒疗"),
        .description = COMPOUND_STRING("中毒时反而会回复HP"),
        .longDescription = COMPOUND_STRING("中毒时不会受到毒的\n伤害，反而每回合回复\n最大HP的1/8。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_ADAPTABILITY] =
    {
        .name = _("适应力"),
        .description = COMPOUND_STRING("强化自身同属性的招式"),
        .longDescription = COMPOUND_STRING("使出与自己属性相同的\n招式时，威力加成由\n1.5倍变为2倍。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_SKILL_LINK] =
    {
        .name = _("连续攻击"),
        .description = COMPOUND_STRING("连续招式总能使出最高次数"),
        .longDescription = COMPOUND_STRING("攻击2～5次的连续招式\n必定会击中5次。"
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_HYDRATION] =
    {
        .name = _("湿润之躯"),
        .description = COMPOUND_STRING("下雨天气时治愈异常状态"),
        .longDescription = COMPOUND_STRING("下雨时，每回合结束时\n治愈所有异常状态。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_SOLAR_POWER] =
    {
        .name = _("太阳之力"),
        .description = COMPOUND_STRING("晴天时减少HP提高特攻"),
        .longDescription = COMPOUND_STRING("晴天时，特攻提高50%，\n但每回合结束时减少\n最大HP的1/8。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_QUICK_FEET] =
    {
        .name = _("飞毛腿"),
        .description = COMPOUND_STRING("变为异常状态时速度会提高"),
        .longDescription = COMPOUND_STRING("陷入异常状态时，\n速度提高50%，\n并无视麻痹造成的\n速度降低。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_NORMALIZE] =
    {
        .name = _("一般皮肤"),
        .description = COMPOUND_STRING("招式变为一般属性并强化"),
        .longDescription = COMPOUND_STRING("自己的所有招式都变为\n一般属性，且伤害提高\n20%。"
                                           ""
                                           ""),
        .aiRating = -1,
    },

    [ABILITY_SNIPER] =
    {
        .name = _("狙击手"),
        .description = COMPOUND_STRING("击中要害时，威力提升"),
        .longDescription = COMPOUND_STRING("击中要害时的伤害由\n通常的1.5倍变为\n2.25倍。"
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_GUARD] =
    {
        .name = _("魔法防守"),
        .description = COMPOUND_STRING("不会受到攻击以外的伤害"),
        .longDescription = COMPOUND_STRING("只会受到直接攻击的\n伤害，不会受到间接\n伤害。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 9,
    },

    [ABILITY_NO_GUARD] =
    {
        .name = _("无防守"),
        .description = COMPOUND_STRING("双方的招式都必定会击中"),
        .longDescription = COMPOUND_STRING("自己使出的招式和\n以自己为目标的招式\n都必定命中。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_STALL] =
    {
        .name = _("慢出"),
        .description = COMPOUND_STRING("使出招式的顺序必定为最后"),
        .longDescription = COMPOUND_STRING("每回合都会在相同\n优先度的招式中\n最后行动。"
                                           ""
                                           ""),
        .aiRating = -1,
    },

    [ABILITY_TECHNICIAN] =
    {
        .name = _("技术高手"),
        .description = COMPOUND_STRING("强化低威力的招式"),
        .longDescription = COMPOUND_STRING("威力在60以下的招式\n威力提高50%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_LEAF_GUARD] =
    {
        .name = _("叶子防守"),
        .description = COMPOUND_STRING("晴天时不会变为异常状态"),
        .longDescription = COMPOUND_STRING("晴天时，\n不会陷入异常状态。"
                                           ""
                                           ""),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_KLUTZ] =
    {
        .name = _("笨拙"),
        .description = COMPOUND_STRING("无法使用持有的道具"),
        .longDescription = COMPOUND_STRING("无法发挥携带道具的\n效果。"
                                           ""
                                           ""),
        .aiRating = -1,
    },

    [ABILITY_MOLD_BREAKER] =
    {
        .name = _("破格"),
        .description = COMPOUND_STRING("使用招式不受对手特性影响"),
        .longDescription = COMPOUND_STRING("使出招式时，无视会\n妨碍或阻止招式效果的\n特性。"
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_SUPER_LUCK] =
    {
        .name = _("超幸运"),
        .description = COMPOUND_STRING("攻击容易击中对手的要害"),
        .longDescription = COMPOUND_STRING("击中要害率提高1级。"
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_AFTERMATH] =
    {
        .name = _("诱爆"),
        .description = COMPOUND_STRING("昏厥时伤害接触的对手"),
        .longDescription = COMPOUND_STRING("被接触类招式打倒时，\n给予对手其最大HP\n1/4的伤害。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_ANTICIPATION] =
    {
        .name = _("危险预知"),
        .description = COMPOUND_STRING("可以察觉到对手的危险招式"),
        .longDescription = COMPOUND_STRING("出场时，如果对手拥有\n效果绝佳的招式，\n就会发抖。"
                                           ""
                                           ""),
        .aiRating = 2,
    },

    [ABILITY_FOREWARN] =
    {
        .name = _("预知梦"),
        .description = COMPOUND_STRING("出场时读取对手的招式"),
        .longDescription = COMPOUND_STRING("出场时，可以得知对手\n宝可梦的招式中威力\n最高的那一个。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 2,
    },

    [ABILITY_UNAWARE] =
    {
        .name = _("纯朴"),
        .description = COMPOUND_STRING("可无视对手能力变化攻击"),
        .longDescription = COMPOUND_STRING("造成或受到伤害时，\n无视对手的能力变化。"
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_TINTED_LENS] =
    {
        .name = _("有色眼镜"),
        .description = COMPOUND_STRING("提升效果不好的招式威力"),
        .longDescription = COMPOUND_STRING("自己使出的效果不好的\n招式伤害变为2倍。"
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_FILTER] =
    {
        .name = _("过滤"),
        .description = COMPOUND_STRING("减轻效果绝佳的攻击伤害"),
        .longDescription = COMPOUND_STRING("受到效果绝佳的招式\n伤害降至75%。"
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SLOW_START] =
    {
        .name = _("慢启动"),
        .description = COMPOUND_STRING("在5回合内攻击和速度减半"),
        .longDescription = COMPOUND_STRING("出场后的5回合内，\n攻击和速度减半。"
                                           ""
                                           ""),
        .aiRating = -2,
    },

    [ABILITY_SCRAPPY] =
    {
        .name = _("胆量"),
        .description = COMPOUND_STRING("招式可击中幽灵并无视威吓"),
        .longDescription = COMPOUND_STRING("一般和格斗属性的招式\n可以击中幽灵属性的\n宝可梦。不受威吓影响。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_STORM_DRAIN] =
    {
        .name = _("引水"),
        .description = COMPOUND_STRING("吸引免疫水招式并提高特攻"),
        .longDescription = COMPOUND_STRING("吸引所有水属性招式，\n不会受到伤害，\n反而特攻提高1级。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_ICE_BODY] =
    {
        .name = _("冰冻之躯"),
        .description = COMPOUND_STRING("下雪天气时会缓缓回复HP"),
        .longDescription = COMPOUND_STRING("冰雹或下雪时，每回合\n结束时回复最大HP的\n1/16。不会受到冰雹的\n伤害。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_SOLID_ROCK] =
    {
        .name = _("坚硬岩石"),
        .description = COMPOUND_STRING("减轻效果绝佳的攻击伤害"),
        .longDescription = COMPOUND_STRING("受到效果绝佳的招式\n伤害降至75%。"
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SNOW_WARNING] =
    {
        .name = _("降雪"),
    #if B_SNOW_WARNING >= GEN_9
        .description = COMPOUND_STRING("出场时，会将天气变为下雪"),
        .longDescription = COMPOUND_STRING("出场时，会在5回合内\n将天气变为下雪。"
                                           ""
                                           ""),
    #else
        .description = COMPOUND_STRING("出场时，会将天气变为冰雹"),
        .longDescription = COMPOUND_STRING("出场时，\n会将天气变为冰雹。"
                                           ""
                                           ""
                                           ""
                                           ""),
    #endif
        .aiRating = 8,
    },

    [ABILITY_HONEY_GATHER] =
    {
        .name = _("采蜜"),
        .description = COMPOUND_STRING("战斗结束时有时捡来甜甜蜜"),
        .longDescription = COMPOUND_STRING("没有携带道具时，战斗\n结束后有时会捡到\n甜甜蜜。"
                                           ""
                                           ""),
        .aiRating = 0,
    },

    [ABILITY_FRISK] =
    {
        .name = _("察觉"),
        .description = COMPOUND_STRING("出场时，可察觉对手持有物"),
        .longDescription = COMPOUND_STRING("出场时，可以得知对手\n宝可梦携带的道具。"
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_RECKLESS] =
    {
        .name = _("舍身"),
        .description = COMPOUND_STRING("强化有反作用力伤害的招式"),
        .longDescription = COMPOUND_STRING("有反作用力伤害或未击中\n会受伤的招式威力提高\n20%。"
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_MULTITYPE] =
    {
        .name = _("多属性"),
        .description = COMPOUND_STRING("属性会根据持有的石板改变"),
        .longDescription = COMPOUND_STRING("阿尔宙斯的属性会变为\n所携带石板的属性，\n且道具不会被移除。"
                                           ""
                                           ""),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_FLOWER_GIFT] =
    {
        .name = _("花之礼"),
        .description = COMPOUND_STRING("晴天时提升我方攻击和特防"),
        .longDescription = COMPOUND_STRING("晴天时，我方的攻击和\n特防提高50%。"
                                           ""
                                           ""),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_5,
        .breakable = TRUE,
    },

    [ABILITY_BAD_DREAMS] =
    {
        .name = _("梦魇"),
        .description = COMPOUND_STRING("给予睡眠状态的对手伤害"),
        .longDescription = COMPOUND_STRING("睡眠状态的对手每回合\n结束时减少最大HP的\n1/8。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_PICKPOCKET] =
    {
        .name = _("顺手牵羊"),
        .description = COMPOUND_STRING("盗取接触到的对手的道具"),
        .longDescription = COMPOUND_STRING("没有携带道具时受到\n接触类招式攻击，\n会夺走对手携带的道具。"
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_SHEER_FORCE] =
    {
        .name = _("强行"),
        .description = COMPOUND_STRING("消除追加效果以强化招式"),
        .longDescription = COMPOUND_STRING("有追加效果的招式威力\n提高30%，但追加效果\n不会发动。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_CONTRARY] =
    {
        .name = _("唱反调"),
        .description = COMPOUND_STRING("能力的升降变化发生逆转"),
        .longDescription = COMPOUND_STRING("能力变化会发生逆转：\n提高变为降低，\n降低变为提高。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_UNNERVE] =
    {
        .name = _("紧张感"),
        .description = COMPOUND_STRING("让对手紧张得无法食用树果"),
        .longDescription = COMPOUND_STRING("让对手紧张得无法\n食用携带的树果。"
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_DEFIANT] =
    {
        .name = _("不服输"),
        .description = COMPOUND_STRING("被降低能力时大幅提高攻击"),
        .longDescription = COMPOUND_STRING("每当能力被对手降低\n时，攻击大幅提高2级。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_DEFEATIST] =
    {
        .name = _("软弱"),
        .description = COMPOUND_STRING("HP减半时攻击特攻会减半"),
        .longDescription = COMPOUND_STRING("HP降到1/2以下时，\n攻击和特攻减半。"
                                           ""
                                           ""),
        .aiRating = -1,
    },

    [ABILITY_CURSED_BODY] =
    {
        .name = _("咒术之躯"),
        .description = COMPOUND_STRING("受击时有时会使招式定身法"),
        .longDescription = COMPOUND_STRING("击中自己的招式有30%\n的几率陷入定身法状态。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_HEALER] =
    {
        .name = _("治愈之心"),
        .description = COMPOUND_STRING("有时会治愈异常状态的同伴"),
        .longDescription = COMPOUND_STRING("每回合有30%的几率\n治愈同伴的异常状态。"
                                           ""
                                           ""),
        .aiRating = 0,
    },

    [ABILITY_FRIEND_GUARD] =
    {
        .name = _("友情防守"),
        .description = COMPOUND_STRING("减轻同伴受到的攻击伤害"),
        .longDescription = COMPOUND_STRING("同伴受到的招式直接\n伤害减少25%。"
                                           ""
                                           ""),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_WEAK_ARMOR] =
    {
        .name = _("碎裂铠甲"),
        .description = COMPOUND_STRING("受物理攻击降防御提高速度"),
        .longDescription = COMPOUND_STRING("受到物理招式攻击时，\n防御降低1级，\n速度提高2级。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 2,
    },

    [ABILITY_HEAVY_METAL] =
    {
        .name = _("重金属"),
        .description = COMPOUND_STRING("自身的重量会变为2倍"),
        .longDescription = COMPOUND_STRING("自己的体重变为2倍，\n会影响与体重有关的\n招式。"
                                           ""
                                           ""),
        .aiRating = -1,
        .breakable = TRUE,
    },

    [ABILITY_LIGHT_METAL] =
    {
        .name = _("轻金属"),
        .description = COMPOUND_STRING("自身的重量会减半"),
        .longDescription = COMPOUND_STRING("自己的体重减半，\n会影响与体重有关的\n招式。"
                                           ""
                                           ""),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MULTISCALE] =
    {
        .name = _("多重鳞片"),
        .description = COMPOUND_STRING("HP全满时减轻受到的伤害"),
        .longDescription = COMPOUND_STRING("HP全满时，受到的\n招式伤害减半。"
                                           ""
                                           ""),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_TOXIC_BOOST] =
    {
        .name = _("中毒激升"),
        .description = COMPOUND_STRING("中毒时提高物理招式的威力"),
        .longDescription = COMPOUND_STRING("中毒状态时，\n攻击提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_FLARE_BOOST] =
    {
        .name = _("受热激升"),
        .description = COMPOUND_STRING("灼伤时提高特殊招式的威力"),
        .longDescription = COMPOUND_STRING("灼伤状态时，\n特攻提高50%。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_HARVEST] =
    {
        .name = _("收获"),
        .description = COMPOUND_STRING("可多次生成被使用掉的树果"),
        .longDescription = COMPOUND_STRING("每回合结束时，有时会\n重新获得用掉的树果。\n晴天时必定成功。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_TELEPATHY] =
    {
        .name = _("心灵感应"),
        .description = COMPOUND_STRING("闪避己方的招式伤害"),
        .longDescription = COMPOUND_STRING("不会受到同伴招式的\n伤害。"
                                           ""),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_MOODY] =
    {
        .name = _("心情不定"),
        .description = COMPOUND_STRING("每回合随机升降能力"),
        .longDescription = COMPOUND_STRING("每回合随机使1项能力\n提高2级，另1项能力\n降低1级。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 10,
    },

    [ABILITY_OVERCOAT] =
    {
        .name = _("防尘"),
        .description = COMPOUND_STRING("无视沙暴与粉末或孢子招式"),
        .longDescription = COMPOUND_STRING("不会受到天气的伤害，\n也不会受到粉末类或\n孢子类招式的影响。"
                                           ""
                                           ""),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_POISON_TOUCH] =
    {
        .name = _("毒手"),
        .description = COMPOUND_STRING("接触时可能会使对手中毒"),
        .longDescription = COMPOUND_STRING("用接触类招式击中对手\n时，有30%的几率使其\n中毒。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_REGENERATOR] =
    {
        .name = _("再生力"),
        .description = COMPOUND_STRING("换下后HP会少量回复"),
        .longDescription = COMPOUND_STRING("未昏厥而替换下场时，\n回复最大HP的1/3。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_BIG_PECKS] =
    {
        .name = _("健壮胸肌"),
        .description = COMPOUND_STRING("不会受到防御降低的效果"),
        .longDescription = COMPOUND_STRING("防御不会被其他\n宝可梦降低。"
                                           ""
                                           ""),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_SAND_RUSH] =
    {
        .name = _("拨沙"),
        .description = COMPOUND_STRING("沙暴天气时，速度会提高"),
        .longDescription = COMPOUND_STRING("沙暴时速度变为2倍，\n且不会受到沙暴的伤害。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_WONDER_SKIN] =
    {
        .name = _("奇迹皮肤"),
        .description = COMPOUND_STRING("不易受到变化招式攻击"),
        .longDescription = COMPOUND_STRING("对自己使出的变化招式\n命中率会降至50%。"
                                           ""
                                           ""),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANALYTIC] =
    {
        .name = _("分析"),
        .description = COMPOUND_STRING("在最后使出招式时威力提高"),
        .longDescription = COMPOUND_STRING("最后行动时，\n招式威力提高30%。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_ILLUSION] =
    {
        .name = _("幻觉"),
        .description = COMPOUND_STRING("幻化成同行宝可梦迷惑对手"),
        .longDescription = COMPOUND_STRING("出场时，会幻化成队伍\n中最后一只宝可梦的\n样子，直到受到攻击\n为止。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_IMPOSTER] =
    {
        .name = _("变身者"),
        .description = COMPOUND_STRING("变身为当前面对的宝可梦"),
        .longDescription = COMPOUND_STRING("出场时，变身为正对面\n的宝可梦。"
                                           ""),
        .aiRating = 9,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_INFILTRATOR] =
    {
        .name = _("穿透"),
        .description = COMPOUND_STRING("能穿透壁障或替身进行攻击"),
        .longDescription = COMPOUND_STRING("招式可以无视对手的\n壁障、神秘守护、白雾、\n替身和气场护盾。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_MUMMY] =
    {
        .name = _("木乃伊"),
        .description = COMPOUND_STRING("被接触后将对手变为木乃伊"),
        .longDescription = COMPOUND_STRING("接触到自己的对手，\n其特性会变为木乃伊。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_MOXIE] =
    {
        .name = _("自信过度"),
        .description = COMPOUND_STRING("打倒对手时攻击会提高"),
        .longDescription = COMPOUND_STRING("每打倒1只对手，\n攻击提高1级。"
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_JUSTIFIED] =
    {
        .name = _("正义之心"),
        .description = COMPOUND_STRING("受恶属性攻击时提高攻击"),
        .longDescription = COMPOUND_STRING("受到恶属性招式攻击时，\n攻击提高1级。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_RATTLED] =
    {
        .name = _("胆怯"),
        .description = COMPOUND_STRING("受恶鬼虫攻击威吓提高速度"),
        .longDescription = COMPOUND_STRING("受到虫、幽灵或恶属性\n招式的伤害时，速度\n提高1级。受到威吓时\n也会发动。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_BOUNCE] =
    {
        .name = _("魔法镜"),
        .description = COMPOUND_STRING("反弹对手使出的变化招式"),
        .longDescription = COMPOUND_STRING("将变化招式反弹给\n使出该招式的宝可梦。"
                                           ""
                                           ""),
        .aiRating = 9,
        .breakable = TRUE,
    },

    [ABILITY_SAP_SIPPER] =
    {
        .name = _("食草"),
        .description = COMPOUND_STRING("免疫草属性攻击并提高攻击"),
        .longDescription = COMPOUND_STRING("草属性的招式无效，\n反而会使攻击提高1级。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_PRANKSTER] =
    {
        .name = _("恶作剧之心"),
        .description = COMPOUND_STRING("可以率先使出变化招式"),
        .longDescription = COMPOUND_STRING("变化招式的优先度+1。\n但对恶属性的宝可梦\n不会命中。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_SAND_FORCE] =
    {
        .name = _("沙之力"),
        .description = COMPOUND_STRING("沙暴时强化岩地钢招式"),
        .longDescription = COMPOUND_STRING("沙暴时，岩石、地面和\n钢属性招式的威力提高\n30%，且不会受到沙暴\n的伤害。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_IRON_BARBS] =
    {
        .name = _("铁刺"),
        .description = COMPOUND_STRING("用铁刺给予接触的对手伤害"),
        .longDescription = COMPOUND_STRING("受到接触类招式攻击时，\n对手会受到其最大HP\n1/8的伤害。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_ZEN_MODE] =
    {
        .name = _("达摩模式"),
        .description = COMPOUND_STRING("HP一半以下时改变样子"),
        .longDescription = COMPOUND_STRING("HP降到1/2以下时变为\n达摩模式，高于1/2时\n变回原样。"
                                           ""
                                           ""),
        .aiRating = -1,
        .cantBeCopied = TRUE,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeOverwritten = B_UPDATED_ABILITY_DATA >= GEN_7,
        .failsOnImposter = TRUE,
    },

    [ABILITY_VICTORY_STAR] =
    {
        .name = _("胜利之星"),
        .description = COMPOUND_STRING("自己和同伴的命中率会提高"),
        .longDescription = COMPOUND_STRING("自己和同伴的命中率\n提高10%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_TURBOBLAZE] =
    {
        .name = _("涡轮火焰"),
        .description = COMPOUND_STRING("使用招式不受对手特性影响"),
        .longDescription = COMPOUND_STRING("招式可以无视飘浮等\n特性击中对手。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_TERAVOLT] =
    {
        .name = _("兆级电压"),
        .description = COMPOUND_STRING("使用招式不受对手特性影响"),
        .longDescription = COMPOUND_STRING("招式可以无视飘浮等\n特性击中对手。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_AROMA_VEIL] =
    {
        .name = _("芳香幕"),
        .description = COMPOUND_STRING("防守向己方发出的心灵攻击"),
        .longDescription = COMPOUND_STRING("保护我方不受限制招式\n选择或行动的心灵类\n效果影响。"
                                           ""
                                           ""),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_FLOWER_VEIL] =
    {
        .name = _("花幕"),
        .description = COMPOUND_STRING("守护己方草宝可梦能力状态"),
        .longDescription = COMPOUND_STRING("我方的草属性宝可梦\n不会被降低能力，\n也不会陷入异常状态。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_CHEEK_POUCH] =
    {
        .name = _("颊囊"),
        .description = COMPOUND_STRING("食用任意树果HP都会回复"),
        .longDescription = COMPOUND_STRING("食用树果时，除了树果\n原本的效果外，\n还会回复HP。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_PROTEAN] =
    {
        .name = _("变幻自如"),
        .description = COMPOUND_STRING("一次性变为使出招式的属性"),
        .longDescription = COMPOUND_STRING("攻击前，自己的属性\n会变为所使出招式的\n属性。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_FUR_COAT] =
    {
        .name = _("毛皮大衣"),
        .description = COMPOUND_STRING("受物理招式的伤害会减半"),
        .longDescription = COMPOUND_STRING("受到物理招式的伤害\n减半。"
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MAGICIAN] =
    {
        .name = _("魔术师"),
        .description = COMPOUND_STRING("夺走被自己击中对手的道具"),
        .longDescription = COMPOUND_STRING("使出攻击招式时，\n会夺走目标携带的道具。"
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_BULLETPROOF] =
    {
        .name = _("防弹"),
        .description = COMPOUND_STRING("防守球和弹类招式"),
        .longDescription = COMPOUND_STRING("不会受到球类和弹类\n招式的影响。"
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_COMPETITIVE] =
    {
        .name = _("好胜"),
        .description = COMPOUND_STRING("被降低能力时大幅提高特攻"),
        .longDescription = COMPOUND_STRING("能力被降低时，\n特攻提高2级。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_STRONG_JAW] =
    {
        .name = _("强壮之颚"),
        .description = COMPOUND_STRING("啃咬类招式的威力会提高"),
        .longDescription = COMPOUND_STRING("啃咬类招式的威力\n提高50%。"
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_REFRIGERATE] =
    {
        .name = _("冰冻皮肤"),
        .description = COMPOUND_STRING("一般招式变为冰属性并强化"),
        .longDescription = COMPOUND_STRING("一般属性的招式会变为\n冰属性，且伤害提高\n20%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_SWEET_VEIL] =
    {
        .name = _("甜幕"),
        .description = COMPOUND_STRING("己方宝可梦不会睡眠"),
        .longDescription = COMPOUND_STRING("自己和同伴都不会\n陷入睡眠状态。"
                                           ""
                                           ""),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_STANCE_CHANGE] =
    {
        .name = _("战斗切换"),
        .description = COMPOUND_STRING("根据招式切换刀剑盾牌形态"),
        .longDescription = COMPOUND_STRING("使出攻击招式时变为\n刀剑形态，使出王者盾牌\n等招式时变回盾牌形态。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GALE_WINGS] =
    {
        .name = _("疾风之翼"),
        .description = COMPOUND_STRING("满HP时能先使出飞行招式"),
        .longDescription = COMPOUND_STRING("HP全满时，飞行属性\n招式的优先度+1。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_MEGA_LAUNCHER] =
    {
        .name = _("超级发射器"),
        .description = COMPOUND_STRING("强化波动和波导类招式"),
        .longDescription = COMPOUND_STRING("波动和波导类招式的\n威力提高50%。"
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_GRASS_PELT] =
    {
        .name = _("草之毛皮"),
        .description = COMPOUND_STRING("青草场地时，防御会提高"),
        .longDescription = COMPOUND_STRING("青草场地时，\n防御提高50%。"
                                           ""
                                           ""),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SYMBIOSIS] =
    {
        .name = _("共生"),
        .description = COMPOUND_STRING("会把道具传递给同伴"),
        .longDescription = COMPOUND_STRING("同伴用掉道具后，\n立刻把自己携带的道具\n传递给同伴。"
                                           ""
                                           ""),
        .aiRating = 0,
    },

    [ABILITY_TOUGH_CLAWS] =
    {
        .name = _("硬爪"),
        .description = COMPOUND_STRING("接触类招式威力会提高"),
        .longDescription = COMPOUND_STRING("接触类招式的威力\n提高30%。"
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_PIXILATE] =
    {
        .name = _("妖精皮肤"),
        .description = COMPOUND_STRING("一般招式变妖精属性并强化"),
        .longDescription = COMPOUND_STRING("一般属性的招式会变为\n妖精属性，且伤害提高\n20%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_GOOEY] =
    {
        .name = _("黏滑"),
        .description = COMPOUND_STRING("降低接触自己的对手的速度"),
        .longDescription = COMPOUND_STRING("受到接触类招式攻击时，\n对手的速度降低1级。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_AERILATE] =
    {
        .name = _("飞行皮肤"),
        .description = COMPOUND_STRING("一般招式变飞行属性并强化"),
        .longDescription = COMPOUND_STRING("一般属性的招式会变为\n飞行属性，且伤害提高\n20%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_PARENTAL_BOND] =
    {
        .name = _("亲子爱"),
        .description = COMPOUND_STRING("亲子俩可以合计攻击2次"),
        .longDescription = COMPOUND_STRING("可以攻击2次，第2次的\n伤害为第1次的25%。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 10,
    },

    [ABILITY_DARK_AURA] =
    {
        .name = _("暗黑气场"),
        .description = COMPOUND_STRING("全体的恶属性招式变强"),
        .longDescription = COMPOUND_STRING("场上所有恶属性招式的\n威力提高33%。"
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_FAIRY_AURA] =
    {
        .name = _("妖精气场"),
        .description = COMPOUND_STRING("全体的妖精属性招式变强"),
        .longDescription = COMPOUND_STRING("场上所有妖精属性招式\n的威力提高33%。"
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_AURA_BREAK] =
    {
        .name = _("气场破坏"),
        .description = COMPOUND_STRING("让气场的效果发生逆转"),
        .longDescription = COMPOUND_STRING("逆转暗黑气场、妖精\n气场和恶意气场的效果，\n使对应招式的威力\n反而降低。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PRIMORDIAL_SEA] =
    {
        .name = _("始源之海"),
        .description = COMPOUND_STRING("变为不受火属性攻击的天气"),
        .longDescription = COMPOUND_STRING("降下让火属性招式失败\n的大雨，自己在场期间\n会一直持续。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 10,
    },

    [ABILITY_DESOLATE_LAND] =
    {
        .name = _("终结之地"),
        .description = COMPOUND_STRING("变为不受水属性攻击的天气"),
        .longDescription = COMPOUND_STRING("出场时让日照变得非常\n强烈，直到离场为止，\n水属性的攻击招式都\n会无效。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 10,
    },

    [ABILITY_DELTA_STREAM] =
    {
        .name = _("德尔塔气流"),
        .description = COMPOUND_STRING("变为飞行弱点消失的天气"),
        .longDescription = COMPOUND_STRING("自己在场期间刮起强风，\n使飞行属性的弱点消失。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 10,
    },

    [ABILITY_STAMINA] =
    {
        .name = _("持久力"),
        .description = COMPOUND_STRING("受到攻击时，防御会提高"),
        .longDescription = COMPOUND_STRING("每次受到攻击时，\n防御提高1级。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_WIMP_OUT] =
    {
        .name = _("跃跃欲逃"),
        .description = COMPOUND_STRING("HP变为一半时会慌张逃走"),
        .longDescription = COMPOUND_STRING("HP降到1/2以下时，\n会替换下场。"
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_EMERGENCY_EXIT] =
    {
        .name = _("危险回避"),
        .description = COMPOUND_STRING("HP变为一半时会回避危险"),
        .longDescription = COMPOUND_STRING("HP降到1/2以下时，\n会替换下场。"
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_WATER_COMPACTION] =
    {
        .name = _("遇水凝固"),
        .description = COMPOUND_STRING("受水招式攻击大幅提高防御"),
        .longDescription = COMPOUND_STRING("受到水属性招式攻击时，\n防御提高2级。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_MERCILESS] =
    {
        .name = _("不仁不义"),
        .description = COMPOUND_STRING("攻击中毒对手必定击中要害"),
        .longDescription = COMPOUND_STRING("攻击中毒状态的对手时\n必定击中要害。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_SHIELDS_DOWN] =
    {
        .name = _("界限盾壳"),
        .description = COMPOUND_STRING("HP变为一半时更有攻击性"),
        .longDescription = COMPOUND_STRING("HP高于1/2时，外壳能\n防住异常状态。HP降到\n1/2以下时外壳破碎，\n变为攻击模式。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STAKEOUT] =
    {
        .name = _("蹲守"),
        .description = COMPOUND_STRING("对替换出场的对手加倍伤害"),
        .longDescription = COMPOUND_STRING("对本回合替换出场的\n目标，招式伤害变为\n2倍。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_WATER_BUBBLE] =
    {
        .name = _("水泡"),
        .description = COMPOUND_STRING("降低火招式伤害且不会灼伤"),
        .longDescription = COMPOUND_STRING("受到火属性招式的伤害\n减半，水属性招式威力\n变为2倍，不会灼伤。"
                                           ""
                                           ""),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_STEELWORKER] =
    {
        .name = _("钢能力者"),
        .description = COMPOUND_STRING("钢属性的招式威力会提高"),
        .longDescription = COMPOUND_STRING("钢属性招式的威力\n提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_BERSERK] =
    {
        .name = _("怒火冲天"),
        .description = COMPOUND_STRING("受击HP变一半时提高特攻"),
        .longDescription = COMPOUND_STRING("因受到伤害而使HP\n降到一半以下时，\n特攻提高1级。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_SLUSH_RUSH] =
    {
        .name = _("拨雪"),
        .description = COMPOUND_STRING("下雪天气时，速度会提高"),
        .longDescription = COMPOUND_STRING("冰雹或下雪时速度变为\n2倍，且不会受到冰雹\n的伤害。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_LONG_REACH] =
    {
        .name = _("远隔"),
        .description = COMPOUND_STRING("可以不接触对手使出招式"),
        .longDescription = COMPOUND_STRING("使出的所有招式都\n不会接触到目标。"
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_LIQUID_VOICE] =
    {
        .name = _("湿润之声"),
        .description = COMPOUND_STRING("所有声音招式都变为水属性"),
        .longDescription = COMPOUND_STRING("自己的所有声音类招式\n都变为水属性。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_TRIAGE] =
    {
        .name = _("先行治疗"),
        .description = COMPOUND_STRING("可以率先使出回复招式"),
        .longDescription = COMPOUND_STRING("回复招式的优先度+3。"
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_GALVANIZE] =
    {
        .name = _("电气皮肤"),
        .description = COMPOUND_STRING("一般招式变为电属性并强化"),
        .longDescription = COMPOUND_STRING("一般属性的招式会变为\n电属性，且伤害提高\n20%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_SURGE_SURFER] =
    {
        .name = _("冲浪之尾"),
        .description = COMPOUND_STRING("电气场地时速度会变为2倍"),
        .longDescription = COMPOUND_STRING("电气场地时，\n速度变为2倍。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_SCHOOLING] =
    {
        .name = _("鱼群"),
        .description = COMPOUND_STRING("HP多则聚众变强少则分散"),
        .longDescription = COMPOUND_STRING("等级在20以上的弱丁鱼，\nHP在1/4以上时变为\n鱼群的样子，否则变为\n单独的样子。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_DISGUISE] =
    {
        .name = _("画皮"),
        .description = COMPOUND_STRING("通过画皮防住1次攻击"),
        .longDescription = COMPOUND_STRING("画皮可以防住1次攻击\n的伤害，之后画皮会\n破损并减少最大HP的\n1/8。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
        .breakable = TRUE,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_BATTLE_BOND] =
    {
        .name = _("牵绊变身"),
        .description = COMPOUND_STRING("打倒对手时提高能力"),
        .longDescription = COMPOUND_STRING("打倒对手后，\n甲贺忍蛙会变为\n小智版甲贺忍蛙。"
                                           ""
                                           ""),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_CONSTRUCT] =
    {
        .name = _("群聚变形"),
        .description = COMPOUND_STRING("HP一半时变成完全体形态"),
        .longDescription = COMPOUND_STRING("基格尔德的HP降到一半\n以下时，会变为完全体\n形态。"
                                           ""
                                           ""),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_CORROSION] =
    {
        .name = _("腐蚀"),
        .description = COMPOUND_STRING("可使钢毒属性的宝可梦中毒"),
        .longDescription = COMPOUND_STRING("即使目标是钢属性或\n毒属性，也能使其中毒。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_COMATOSE] =
    {
        .name = _("绝对睡眠"),
        .description = COMPOUND_STRING("在半梦半醒的状态下攻击"),
        .longDescription = COMPOUND_STRING("总是半梦半醒，视为\n睡眠状态，但不会陷入\n其他异常状态。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_QUEENLY_MAJESTY] =
    {
        .name = _("女王的威严"),
        .description = COMPOUND_STRING("使对手无法使出先制招式"),
        .longDescription = COMPOUND_STRING("对手无法用先制招式\n攻击自己。"
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_INNARDS_OUT] =
    {
        .name = _("飞出的内在物"),
        .description = COMPOUND_STRING("被击倒时造成剩余HP伤害"),
        .longDescription = COMPOUND_STRING("被攻击打倒时，给予\n对手与自己被打倒前\n剩余HP相同的伤害。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_DANCER] =
    {
        .name = _("舞者"),
        .description = COMPOUND_STRING("跟随着其他舞蹈使出舞蹈"),
        .longDescription = COMPOUND_STRING("其他宝可梦使出舞蹈类\n招式后，会立刻跟着\n使出相同的招式。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_BATTERY] =
    {
        .name = _("蓄电池"),
        .description = COMPOUND_STRING("提高我方的特殊招式的威力"),
        .longDescription = COMPOUND_STRING("同伴的特殊招式威力\n提高30%。"
                                           ""
                                           ""),
        .aiRating = 0,
    },

    [ABILITY_FLUFFY] =
    {
        .name = _("毛茸茸"),
        .description = COMPOUND_STRING("减轻接触伤害，但怕火"),
        .longDescription = COMPOUND_STRING("受到接触类招式的伤害\n减半，但受到火属性\n招式的伤害变为2倍。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_DAZZLING] =
    {
        .name = _("鲜艳之躯"),
        .description = COMPOUND_STRING("使对手无法使出先制招式"),
        .longDescription = COMPOUND_STRING("对手无法用先制招式\n攻击自己。"
                                           ""
                                           ""),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SOUL_HEART] =
    {
        .name = _("魂心"),
        .description = COMPOUND_STRING("有宝可梦倒下时提高特攻"),
        .longDescription = COMPOUND_STRING("每当有宝可梦被打倒时，\n特攻提高1级。"
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_TANGLING_HAIR] =
    {
        .name = _("卷发"),
        .description = COMPOUND_STRING("降低接触自己的对手的速度"),
        .longDescription = COMPOUND_STRING("受到接触类招式攻击时，\n对手的速度降低1级。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_RECEIVER] =
    {
        .name = _("接球手"),
        .description = COMPOUND_STRING("继承被打倒的同伴的特性"),
        .longDescription = COMPOUND_STRING("继承被打倒的同伴的\n特性。"
                                           ""),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POWER_OF_ALCHEMY] =
    {
        .name = _("化学之力"),
        .description = COMPOUND_STRING("继承被打倒的同伴的特性"),
        .longDescription = COMPOUND_STRING("继承被打倒的同伴的\n特性。"
                                           ""),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_BEAST_BOOST] =
    {
        .name = _("异兽提升"),
        .description = COMPOUND_STRING("打倒对手时，提升最高能力"),
        .longDescription = COMPOUND_STRING("每打倒1只对手，\n自己最高的那项能力\n提高1级。"
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_RKS_SYSTEM] =
    {
        .name = _("AR系统"),
        .description = COMPOUND_STRING("根据存储碟改变自己属性"),
        .longDescription = COMPOUND_STRING("银伴战兽的属性会变为\n所携带存储碟的属性，\n且该特性不会被替换。"
                                           ""
                                           ""),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_ELECTRIC_SURGE] =
    {
        .name = _("电气制造者"),
        .description = COMPOUND_STRING("出场时，会布下电气场地"),
        .longDescription = COMPOUND_STRING("出场时，在5回合内将\n脚下变为电气场地。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_PSYCHIC_SURGE] =
    {
        .name = _("精神制造者"),
        .description = COMPOUND_STRING("出场时，会布下精神场地"),
        .longDescription = COMPOUND_STRING("出场时，在5回合内将\n脚下变为精神场地。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_MISTY_SURGE] =
    {
        .name = _("薄雾制造者"),
        .description = COMPOUND_STRING("出场时，会布下薄雾场地"),
        .longDescription = COMPOUND_STRING("出场时，在5回合内将\n脚下变为薄雾场地。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_GRASSY_SURGE] =
    {
        .name = _("青草制造者"),
        .description = COMPOUND_STRING("出场时，会布下青草场地"),
        .longDescription = COMPOUND_STRING("出场时，在5回合内将\n脚下变为青草场地。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_FULL_METAL_BODY] =
    {
        .name = _("金属防护"),
        .description = COMPOUND_STRING("不因对手招式特性降低能力"),
        .longDescription = COMPOUND_STRING("不会因其他宝可梦的\n招式或特性而被降低\n能力。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_SHADOW_SHIELD] =
    {
        .name = _("幻影防守"),
        .description = COMPOUND_STRING("HP全满时减少受到的伤害"),
        .longDescription = COMPOUND_STRING("HP全满时，受到的\n招式伤害减半。\n此效果不会被破格\n无视。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_PRISM_ARMOR] =
    {
        .name = _("棱镜装甲"),
        .description = COMPOUND_STRING("减轻所受效果绝佳的伤害"),
        .longDescription = COMPOUND_STRING("受到效果绝佳的招式\n伤害降至75%。\n此效果不会被破格\n无视。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_NEUROFORCE] =
    {
        .name = _("脑核之力"),
        .description = COMPOUND_STRING("增强效果绝佳招式的伤害"),
        .longDescription = COMPOUND_STRING("效果绝佳的招式威力\n提高25%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_INTREPID_SWORD] =
    {
        .name = _("不挠之剑"),
        .description = COMPOUND_STRING("首次出场时，攻击会提高"),
        .longDescription = COMPOUND_STRING("出场时，攻击提高1级。\n每场战斗只能发动1次。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_DAUNTLESS_SHIELD] =
    {
        .name = _("不屈之盾"),
        .description = COMPOUND_STRING("首次出场时，防御会提高"),
        .longDescription = COMPOUND_STRING("出场时，防御提高1级。\n每场战斗只能发动1次。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_LIBERO] =
    {
        .name = _("自由者"),
        .description = COMPOUND_STRING("一次性变为使出招式的属性"),
        .longDescription = COMPOUND_STRING("自己的属性会变为\n即将使出的招式的属性。"
                                           ""
                                           ""),
    },

    [ABILITY_BALL_FETCH] =
    {
        .name = _("捡球"),
        .description = COMPOUND_STRING("拾取捕捉失败的精灵球"),
        .longDescription = COMPOUND_STRING("没有携带道具时，会在\n回合结束时捡回第1个\n捕捉失败的精灵球。"
                                           ""
                                           ""),
        .aiRating = 0,
    },

    [ABILITY_COTTON_DOWN] =
    {
        .name = _("棉絮"),
        .description = COMPOUND_STRING("受攻击降低其他宝可梦速度"),
        .longDescription = COMPOUND_STRING("受到攻击时，自己以外\n的所有宝可梦速度\n降低1级。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_PROPELLER_TAIL] =
    {
        .name = _("螺旋尾鳍"),
        .description = COMPOUND_STRING("招式不被对手特性招式吸引"),
        .longDescription = COMPOUND_STRING("无视会改变招式目标的\n招式和特性。"
                                           ""
                                           ""),
        .aiRating = 2,
    },

    [ABILITY_MIRROR_ARMOR] =
    {
        .name = _("镜甲"),
        .description = COMPOUND_STRING("反弹自己受到的能力降低"),
        .longDescription = COMPOUND_STRING("只反弹自己受到的\n能力降低效果。"
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_GULP_MISSILE] =
    {
        .name = _("一口导弹"),
        .description = COMPOUND_STRING("冲浪潜水捕食，受击吐出"),
        .longDescription = COMPOUND_STRING("使出冲浪或潜水后，\n古月鸟会衔住猎物。\n受到攻击时，会把猎物\n吐向对手。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 3,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeCopied = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeTraced = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STALWART] =
    {
        .name = _("坚毅"),
        .description = COMPOUND_STRING("招式不被对手特性招式吸引"),
        .longDescription = COMPOUND_STRING("无视会改变招式目标的\n招式和特性。"
                                           ""
                                           ""),
        .aiRating = 2,
    },

    [ABILITY_STEAM_ENGINE] =
    {
        .name = _("蒸汽机"),
        .description = COMPOUND_STRING("受水火攻击时速度巨幅提高"),
        .longDescription = COMPOUND_STRING("受到火属性或水属性\n招式攻击时，速度\n提高6级。"
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_PUNK_ROCK] =
    {
        .name = _("庞克摇滚"),
        .description = COMPOUND_STRING("强化声音招式并减轻其影响"),
        .longDescription = COMPOUND_STRING("声音类招式的威力\n提高30%，受到声音类\n招式的伤害减半。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SAND_SPIT] =
    {
        .name = _("吐沙"),
        .description = COMPOUND_STRING("受到攻击时，会刮起沙暴"),
        .longDescription = COMPOUND_STRING("受到攻击时，\n会刮起沙暴。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_ICE_SCALES] =
    {
        .name = _("冰鳞粉"),
        .description = COMPOUND_STRING("受到的特殊攻击伤害会减半"),
        .longDescription = COMPOUND_STRING("受到特殊招式的伤害\n减半。"
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_RIPEN] =
    {
        .name = _("熟成"),
        .description = COMPOUND_STRING("使树果成熟，效果变为2倍"),
        .longDescription = COMPOUND_STRING("自己使用的树果效果\n变为2倍。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_ICE_FACE] =
    {
        .name = _("结冻头"),
        .description = COMPOUND_STRING("头部冰块可抵挡物理攻击"),
        .longDescription = COMPOUND_STRING("结冻头的样子下，可以\n防住1次物理攻击。\n冰雹或下雪时结冻头\n会复原。"
                                           ""
                                           ""),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .breakable = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_SPOT] =
    {
        .name = _("能量点"),
        .description = COMPOUND_STRING("相邻宝可梦招式威力会提升"),
        .longDescription = COMPOUND_STRING("同伴的招式威力\n提高30%。"
                                           ""),
        .aiRating = 2,
    },

    [ABILITY_MIMICRY] =
    {
        .name = _("拟态"),
        .description = COMPOUND_STRING("属性会根据场地而变化"),
        .longDescription = COMPOUND_STRING("自己的属性会根据\n当前的场地而变化。"
                                           ""
                                           ""),
        .aiRating = 2,
    },

    [ABILITY_SCREEN_CLEANER] =
    {
        .name = _("除障"),
        .description = COMPOUND_STRING("出场时消除双方墙壁效果"),
        .longDescription = COMPOUND_STRING("出场时，消除双方场地\n上的光墙、反射壁和\n极光幕。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_STEELY_SPIRIT] =
    {
        .name = _("钢之意志"),
        .description = COMPOUND_STRING("我方钢属性攻击威力会提高"),
        .longDescription = COMPOUND_STRING("自己和同伴的钢属性\n招式威力会提高。"
                                           ""
                                           ""),
        .aiRating = 2,
    },

    [ABILITY_PERISH_BODY] =
    {
        .name = _("灭亡之躯"),
        .description = COMPOUND_STRING("受接触攻击双方3回合昏厥"),
        .longDescription = COMPOUND_STRING("接触到自己的对手和\n自己都会陷入3回合后\n昏厥的灭亡之歌状态。"
                                           ""
                                           ""),
        .aiRating = -1,
    },

    [ABILITY_WANDERING_SPIRIT] =
    {
        .name = _("游魂"),
        .description = COMPOUND_STRING("与接触攻击的宝可梦换特性"),
        .longDescription = COMPOUND_STRING("受到接触类招式攻击时，\n与对手互换特性。"
                                           ""
                                           ""),
        .aiRating = 2,
    },

    [ABILITY_GORILLA_TACTICS] =
    {
        .name = _("一猩一意"),
        .description = COMPOUND_STRING("攻击提高但只能用最初招式"),
        .longDescription = COMPOUND_STRING("攻击会提高，但只能\n使出最初选择的招式。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_NEUTRALIZING_GAS] =
    {
        .name = _("化学变化气体"),
        .description = COMPOUND_STRING("在场时全场特性消失或无效"),
        .longDescription = COMPOUND_STRING("自己在场期间，可被\n压制的特性和天赋特性\n会失效或无法发动。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_PASTEL_VEIL] =
    {
        .name = _("粉彩护幕"),
        .description = COMPOUND_STRING("守护己方不会中毒"),
        .longDescription = COMPOUND_STRING("自己和同伴都不会中毒。\n出场时会治愈同伴的\n中毒状态。"
                                           ""
                                           ""),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_HUNGER_SWITCH] =
    {
        .name = _("饱了又饿"),
        .description = COMPOUND_STRING("每回合结束时交替改变样子"),
        .longDescription = COMPOUND_STRING("每回合结束时，在满腹\n花纹和空腹花纹之间\n交替切换。"
                                           ""
                                           ""),
        .aiRating = 2,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUICK_DRAW] =
    {
        .name = _("速击"),
        .description = COMPOUND_STRING("有时能比对手先一步行动"),
        .longDescription = COMPOUND_STRING("攻击招式有30%的几率\n在相同优先度的招式中\n最先行动。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_UNSEEN_FIST] =
    {
        .name = _("无形拳"),
        .description = COMPOUND_STRING("接触招式可以无视守护效果"),
        .longDescription = COMPOUND_STRING("接触类招式可以无视\n守住、看穿等守护效果\n击中对手。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_CURIOUS_MEDICINE] =
    {
        .name = _("怪药"),
        .description = COMPOUND_STRING("出场时将我方能力变化复原"),
        .longDescription = COMPOUND_STRING("出场时，同伴的所有\n能力变化都会复原。"
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_TRANSISTOR] =
    {
        .name = _("电晶体"),
        .description = COMPOUND_STRING("电属性的招式威力会提高"),
        .longDescription = COMPOUND_STRING("电属性招式的威力\n提高30%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_DRAGONS_MAW] =
    {
        .name = _("龙颚"),
        .description = COMPOUND_STRING("龙属性的招式威力会提高"),
        .longDescription = COMPOUND_STRING("龙属性招式的威力\n提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_CHILLING_NEIGH] =
    {
        .name = _("苍白嘶鸣"),
        .description = COMPOUND_STRING("打倒对手时会提高攻击"),
        .longDescription = COMPOUND_STRING("每打倒1只对手，\n攻击提高1级。"
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_GRIM_NEIGH] =
    {
        .name = _("漆黑嘶鸣"),
        .description = COMPOUND_STRING("打倒对手时会提高特攻"),
        .longDescription = COMPOUND_STRING("每打倒1只对手，\n特攻提高1级。"
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_AS_ONE_ICE_RIDER] =
    {
        .name = _("人马一体"),
        .description = COMPOUND_STRING("兼备紧张感和苍白嘶鸣特性"),
        .longDescription = COMPOUND_STRING("兼备紧张感和苍白嘶鸣\n这两种特性的效果。"
                                           ""
                                           ""),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_AS_ONE_SHADOW_RIDER] =
    {
        .name = _("人马一体"),
        .description = COMPOUND_STRING("兼备紧张感和漆黑嘶鸣特性"),
        .longDescription = COMPOUND_STRING("兼备紧张感和漆黑嘶鸣\n的效果：对手无法食用\n树果，打倒对手时特攻\n会提高。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_LINGERING_AROMA] =
    {
        .name = _("甩不掉的气味"),
        .description = COMPOUND_STRING("被接触会沾上甩不掉的气味"),
        .longDescription = COMPOUND_STRING("接触到自己的对手，\n其特性会变为甩不掉的\n气味。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_SEED_SOWER] =
    {
        .name = _("掉出种子"),
        .description = COMPOUND_STRING("受到攻击时会生成青草场地"),
        .longDescription = COMPOUND_STRING("受到攻击时，\n将脚下变为青草场地。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_THERMAL_EXCHANGE] =
    {
        .name = _("热交换"),
        .description = COMPOUND_STRING("受火攻提高攻击，防灼伤"),
        .longDescription = COMPOUND_STRING("不会陷入灼伤状态。\n受到火属性招式攻击时，\n攻击提高1级。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANGER_SHELL] =
    {
        .name = _("愤怒甲壳"),
        .description = COMPOUND_STRING("受击HP变一半时变得愤怒"),
        .longDescription = COMPOUND_STRING("因受到伤害而使HP降到\n一半以下时，攻击、\n特攻和速度提高1级，\n防御和特防降低1级。"
                                           ""
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_PURIFYING_SALT] =
    {
        .name = _("洁净之盐"),
        .description = COMPOUND_STRING("免疫异常，减轻幽灵伤害"),
        .longDescription = COMPOUND_STRING("受到幽灵属性招式的\n伤害减半。不会陷入\n异常状态。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_WELL_BAKED_BODY] =
    {
        .name = _("焦香之躯"),
        .description = COMPOUND_STRING("免疫火招式并大幅提升防御"),
        .longDescription = COMPOUND_STRING("火属性的招式无效，\n反而会使防御大幅提高。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_WIND_RIDER] =
    {
        .name = _("乘风"),
        .description = COMPOUND_STRING("免疫风招式，顺风升攻击"),
        .longDescription = COMPOUND_STRING("风类招式无效，反而会\n使攻击提高。顺风时\n攻击也会提高。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_GUARD_DOG] =
    {
        .name = _("看门犬"),
        .description = COMPOUND_STRING("不被逼退，威吓反升攻击"),
        .longDescription = COMPOUND_STRING("不会被威吓影响，也不会\n被强制替换下场。受到\n威吓时攻击反而会提高。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ROCKY_PAYLOAD] =
    {
        .name = _("搬岩"),
        .description = COMPOUND_STRING("岩石属性的招式威力会提高"),
        .longDescription = COMPOUND_STRING("岩石属性招式的威力\n提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_WIND_POWER] =
    {
        .name = _("风力发电"),
        .description = COMPOUND_STRING("受风招式时会变为充电状态"),
        .longDescription = COMPOUND_STRING("受到风类招式时变为\n充电状态，下一次使出\n的电属性招式威力变为\n2倍。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_ZERO_TO_HERO] =
    {
        .name = _("全能变身"),
        .description = COMPOUND_STRING("换下后会变为全能形态"),
        .longDescription = COMPOUND_STRING("替换下场时，\n会变为全能形态。"
                                           ""
                                           ""),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_COMMANDER] =
    {
        .name = _("发号施令"),
        .description = COMPOUND_STRING("进入吃吼霸口中发出指令"),
        .longDescription = COMPOUND_STRING("出场时，如果同伴是\n吃吼霸，就会进入它的\n口中发出指令。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_ELECTROMORPHOSIS] =
    {
        .name = _("电力转换"),
        .description = COMPOUND_STRING("受伤时会变为充电状态"),
        .longDescription = COMPOUND_STRING("受到伤害时变为充电\n状态，下一次使出的\n电属性招式威力变为\n2倍。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_PROTOSYNTHESIS] =
    {
        .name = _("古代活性"),
        .description = COMPOUND_STRING("晴天时提升最高能力"),
        .longDescription = COMPOUND_STRING("晴天时或携带驱劲能量\n时，自己最高的那项\n能力会提高。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUARK_DRIVE] =
    {
        .name = _("夸克充能"),
        .description = COMPOUND_STRING("电气场地上提升最高能力"),
        .longDescription = COMPOUND_STRING("电气场地时或携带驱劲\n能量时，自己最高的\n那项能力会提高。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GOOD_AS_GOLD] =
    {
        .name = _("黄金之躯"),
        .description = COMPOUND_STRING("不会受到变化招式的影响"),
        .longDescription = COMPOUND_STRING("纯金的身体让自己完全\n不受变化招式的影响。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_VESSEL_OF_RUIN] =
    {
        .name = _("灾祸之鼎"),
        .description = COMPOUND_STRING("降低其他的宝可梦的特攻"),
        .longDescription = COMPOUND_STRING("鼎的力量会降低自己\n以外所有宝可梦的特攻。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SWORD_OF_RUIN] =
    {
        .name = _("灾祸之剑"),
        .description = COMPOUND_STRING("降低其他的宝可梦的防御"),
        .longDescription = COMPOUND_STRING("剑的力量会降低自己\n以外所有宝可梦的防御。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_TABLETS_OF_RUIN] =
    {
        .name = _("灾祸之简"),
        .description = COMPOUND_STRING("降低其他的宝可梦的攻击"),
        .longDescription = COMPOUND_STRING("简的力量会降低自己\n以外所有宝可梦的攻击。"
                                           ""
                                           ""),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_BEADS_OF_RUIN] =
    {
        .name = _("灾祸之玉"),
        .description = COMPOUND_STRING("降低其他的宝可梦的特防"),
        .longDescription = COMPOUND_STRING("玉的力量会降低自己\n以外所有宝可梦的特防。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ORICHALCUM_PULSE] =
    {
        .name = _("绯红脉动"),
        .description = COMPOUND_STRING("引发晴天，晴天提升攻击"),
        .longDescription = COMPOUND_STRING("出场时将天气变为晴朗。\n晴天时，攻击会提高。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HADRON_ENGINE] =
    {
        .name = _("强子引擎"),
        .description = COMPOUND_STRING("生成电场，电场提升特攻"),
        .longDescription = COMPOUND_STRING("出场时将脚下变为电气\n场地。电气场地时，\n特攻会提高。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_OPPORTUNIST] =
    {
        .name = _("跟风"),
        .description = COMPOUND_STRING("跟随对手趁机同样提高能力"),
        .longDescription = COMPOUND_STRING("对手的能力提高时，\n自己也会同样提高\n这些能力。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_CUD_CHEW] =
    {
        .name = _("反刍"),
        .description = COMPOUND_STRING("吃树果后会反刍再吃1次"),
        .longDescription = COMPOUND_STRING("吃了树果后，会在下一\n回合结束时再吃1次\n相同的树果。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_SHARPNESS] =
    {
        .name = _("锋锐"),
        .description = COMPOUND_STRING("提高切割对手的招式的威力"),
        .longDescription = COMPOUND_STRING("切割类招式的威力\n提高50%。"
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_SUPREME_OVERLORD] =
    {
        .name = _("大将"),
        .description = COMPOUND_STRING("按被打倒数提升攻击特攻"),
        .longDescription = COMPOUND_STRING("出场时，队伍中每有1只\n被打倒的同伴，招式\n威力提高10%，最多\n提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_COSTAR] =
    {
        .name = _("同台共演"),
        .description = COMPOUND_STRING("出场时复制同伴能力变化"),
        .longDescription = COMPOUND_STRING("出场时，复制同伴的\n能力变化。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_TOXIC_DEBRIS] =
    {
        .name = _("毒满地"),
        .description = COMPOUND_STRING("受物理伤害时，会散布毒菱"),
        .longDescription = COMPOUND_STRING("受到物理招式攻击时，\n会在对手的场地上散布\n毒菱。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_ARMOR_TAIL] =
    {
        .name = _("尾甲"),
        .description = COMPOUND_STRING("使对手无法使出先制招式"),
        .longDescription = COMPOUND_STRING("对手无法对自己和同伴\n使出先制招式。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_EARTH_EATER] =
    {
        .name = _("食土"),
        .description = COMPOUND_STRING("受到地面属性攻击时会回复"),
        .longDescription = COMPOUND_STRING("地面属性的招式无效，\n反而会回复最大HP的\n1/4。"
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MYCELIUM_MIGHT] =
    {
        .name = _("菌丝之力"),
        .description = COMPOUND_STRING("变化招式变慢，但无视特性"),
        .longDescription = COMPOUND_STRING("变化招式会最后行动，\n但可以无视目标特性的\n防护效果。"
                                           ""
                                           ""),
        .aiRating = 2,
    },

    [ABILITY_HOSPITALITY] =
    {
        .name = _("款待"),
        .description = COMPOUND_STRING("出场时回复同伴少量HP"),
        .longDescription = COMPOUND_STRING("出场时，回复同伴\n最大HP的1/4。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_MINDS_EYE] =
    {
        .name = _("心眼"),
        .description = COMPOUND_STRING("兼具胆量以及锐利目光特性"),
        .longDescription = COMPOUND_STRING("无视对手的闪避率变化，\n命中率不会被降低，\n一般和格斗属性的招式\n可以击中幽灵属性。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_TEAL_MASK] =
    {
        .name = _("面影辉映"),
        .description = COMPOUND_STRING("铭记回忆，提高自身速度"),
        .longDescription = COMPOUND_STRING("太晶化时，碧草面具\n会发出光辉，速度\n提高1级。"
                                           ""
                                           ""),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK] =
    {
        .name = _("面影辉映"),
        .description = COMPOUND_STRING("铭记回忆，提高自身攻击"),
        .longDescription = COMPOUND_STRING("太晶化时，火灶面具\n会发出光辉，攻击\n提高1级。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_WELLSPRING_MASK] =
    {
        .name = _("面影辉映"),
        .description = COMPOUND_STRING("铭记回忆，提高自身特防"),
        .longDescription = COMPOUND_STRING("太晶化时，水井面具\n会发出光辉，特防\n提高1级。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK] =
    {
        .name = _("面影辉映"),
        .description = COMPOUND_STRING("铭记回忆，提高自身防御"),
        .longDescription = COMPOUND_STRING("太晶化时，础石面具\n会发出光辉，防御\n提高1级。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TOXIC_CHAIN] =
    {
        .name = _("毒锁链"),
        .description = COMPOUND_STRING("有时能让击中对手陷入剧毒"),
        .longDescription = COMPOUND_STRING("用招式击中目标时，\n毒锁链有时会让目标\n陷入剧毒状态。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_SUPERSWEET_SYRUP] =
    {
        .name = _("甘露之蜜"),
        .description = COMPOUND_STRING("首次出场时降低对手闪避率"),
        .longDescription = COMPOUND_STRING("每场战斗首次出场时，\n对手的闪避率降低1级。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_TERA_SHIFT] =
    {
        .name = _("太晶变形"),
        .description = COMPOUND_STRING("出场时，会变为太晶形态"),
        .longDescription = COMPOUND_STRING("出场时，吸收周围的\n能量，变为太晶形态。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TERA_SHELL] =
    {
        .name = _("太晶甲壳"),
        .description = COMPOUND_STRING("HP全满时抵抗所有属性"),
        .longDescription = COMPOUND_STRING("HP全满时，击中自己的\n所有攻击招式都会变为\n效果不好。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_TERAFORM_ZERO] =
    {
        .name = _("归零化境"),
        .description = COMPOUND_STRING("会将天气场地影响全部归零"),
        .longDescription = COMPOUND_STRING("变为星晶形态时，\n消除所有天气和场地的\n影响。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POISON_PUPPETEER] =
    {
        .name = _("毒傀儡"),
        .description = COMPOUND_STRING("因其招式而中毒时会混乱"),
        .longDescription = COMPOUND_STRING("因自己的招式而中毒的\n宝可梦还会陷入混乱。"
                                           ""
                                           ""),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_INVERSION] =
    {
        .name = _("属性逆转"),
        .description = COMPOUND_STRING("弱点与抗性会互相逆转"),
        .longDescription = COMPOUND_STRING("受到攻击时，自己的\n弱点和抗性会发生逆转。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_FIGHTING_ATE] =
    {
        .name = _("格斗皮肤"),
        .description = COMPOUND_STRING("一般招式会变为格斗属性"),
        .longDescription = COMPOUND_STRING("一般属性的招式会变为\n格斗属性，且伤害提高\n20%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_POISON_ATE] =
    {
        .name = _("剧毒皮肤"),
        .description = COMPOUND_STRING("一般招式会变为毒属性"),
        .longDescription = COMPOUND_STRING("一般属性的招式会变为\n毒属性，且伤害提高\n20%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_GROUND_ATE] =
    {
        .name = _("大地皮肤"),
        .description = COMPOUND_STRING("一般招式会变为地面属性"),
        .longDescription = COMPOUND_STRING("一般属性的招式会变为\n地面属性，且伤害提高\n20%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_ROCK_ATE] =
    {
        .name = _("岩石皮肤"),
        .description = COMPOUND_STRING("一般招式会变为岩石属性"),
        .longDescription = COMPOUND_STRING("一般属性的招式会变为\n岩石属性，且伤害提高\n20%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_BUG_ATE] =
    {
        .name = _("虫群皮肤"),
        .description = COMPOUND_STRING("一般招式会变为虫属性"),
        .longDescription = COMPOUND_STRING("一般属性的招式会变为\n虫属性，且伤害提高\n20%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_GHOST_ATE] =
    {
        .name = _("幽灵皮肤"),
        .description = COMPOUND_STRING("一般招式会变为幽灵属性"),
        .longDescription = COMPOUND_STRING("一般属性的招式会变为\n幽灵属性，且伤害提高\n20%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_STEEL_ATE] =
    {
        .name = _("钢铁皮肤"),
        .description = COMPOUND_STRING("一般招式会变为钢属性"),
        .longDescription = COMPOUND_STRING("一般属性的招式会变为\n钢属性，且伤害提高\n20%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_FIRE_ATE] =
    {
        .name = _("火焰皮肤"),
        .description = COMPOUND_STRING("一般招式会变为火属性"),
        .longDescription = COMPOUND_STRING("一般属性的招式会变为\n火属性，且伤害提高\n20%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_WATER_ATE] =
    {
        .name = _("水流皮肤"),
        .description = COMPOUND_STRING("一般招式会变为水属性"),
        .longDescription = COMPOUND_STRING("一般属性的招式会变为\n水属性，且伤害提高\n20%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_GRASS_ATE] =
    {
        .name = _("草木皮肤"),
        .description = COMPOUND_STRING("一般招式会变为草属性"),
        .longDescription = COMPOUND_STRING("一般属性的招式会变为\n草属性，且伤害提高\n20%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_PSYCHIC_ATE] =
    {
        .name = _("超能皮肤"),
        .description = COMPOUND_STRING("一般招式会变为超能力属性"),
        .longDescription = COMPOUND_STRING("一般属性的招式会变为\n超能力属性，且伤害\n提高20%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_DRAGON_ATE] =
    {
        .name = _("龙族皮肤"),
        .description = COMPOUND_STRING("一般招式会变为龙属性"),
        .longDescription = COMPOUND_STRING("一般属性的招式会变为\n龙属性，且伤害提高\n20%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_DARK_ATE] =
    {
        .name = _("黑暗皮肤"),
        .description = COMPOUND_STRING("一般招式会变为恶属性"),
        .longDescription = COMPOUND_STRING("一般属性的招式会变为\n恶属性，且伤害提高\n20%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_STEEL_FEET] =
    {
        .name = _("钢铁之足"),
        .description = COMPOUND_STRING("踢类招式的威力会提高"),
        .longDescription = COMPOUND_STRING("自己使出的踢类招式\n伤害提高20%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_DUAL_STRIKE] =
    {
        .name = _("双重打击"),
        .description = COMPOUND_STRING("招式会击中2次"),
        .longDescription = COMPOUND_STRING("单体攻击招式会击中\n2次，第2次的威力会\n降低。"
                                           ""
                                           ""),
        .aiRating = 10,
    },

    [ABILITY_UNSTOPPABLE] =
    {
        .name = _("势不可挡"),
        .description = COMPOUND_STRING("不会因疲劳而陷入混乱"),
        .longDescription = COMPOUND_STRING("不会因逆鳞等招式的\n"
                                           "疲劳而混乱。"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_UNCANNY] =
    {
        .name = _("妖异威压"),
        .description = COMPOUND_STRING("降低对手的特攻"),
        .longDescription = COMPOUND_STRING("出场时，对手的特攻\n降低1级。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_MYSTIC_FORCE] =
    {
        .name = _("秘法之力"),
        .description = COMPOUND_STRING("精神场地时，速度会提高"),
        .longDescription = COMPOUND_STRING("精神场地时，\n速度变为2倍。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_MANEUVERABILITY] =
    {
        .name = _("机动自如"),
        .description = COMPOUND_STRING("能率先使出低威力的招式"),
        .longDescription = COMPOUND_STRING("威力在60以下的攻击\n招式优先度+1。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_ADRENALINE] =
    {
        .name = _("肾上腺素"),
        .description = COMPOUND_STRING("危急时速度会提高"),
        .longDescription = COMPOUND_STRING("HP在1/3以下时，\n速度提高30%。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_PACK_LEADER] =
    {
        .name = _("群体领袖"),
        .description = COMPOUND_STRING("同伴越多，招式威力越高"),
        .longDescription = COMPOUND_STRING("队伍中每有1只未昏厥\n的同伴，招式伤害\n提高5%。"
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_REACTIVE] =
    {
        .name = _("临机应变"),
        .description = COMPOUND_STRING("对效果绝佳的招式作出反应"),
        .longDescription = COMPOUND_STRING("对手选择了效果绝佳的\n攻击招式时，自己招式\n的优先度+1。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_TRUE_GRIT] =
    {
        .name = _("坚韧本色"),
        .description = COMPOUND_STRING("一般属性的招式威力会提高"),
        .longDescription = COMPOUND_STRING("自己使出的一般属性\n招式伤害提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_WARRIOR_SPIRIT] =
    {
        .name = _("武者气魄"),
        .description = COMPOUND_STRING("格斗属性的招式威力会提高"),
        .longDescription = COMPOUND_STRING("自己使出的格斗属性\n招式伤害提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_WIND_FORCE] =
    {
        .name = _("疾风之力"),
        .description = COMPOUND_STRING("飞行属性的招式威力会提高"),
        .longDescription = COMPOUND_STRING("自己使出的飞行属性\n招式伤害提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_TOXIC_CORE] =
    {
        .name = _("剧毒核心"),
        .description = COMPOUND_STRING("毒属性的招式威力会提高"),
        .longDescription = COMPOUND_STRING("自己使出的毒属性\n招式伤害提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_EARTHBOUND] =
    {
        .name = _("大地之缘"),
        .description = COMPOUND_STRING("地面属性的招式威力会提高"),
        .longDescription = COMPOUND_STRING("自己使出的地面属性\n招式伤害提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_HIVE_FORCE] =
    {
        .name = _("虫巢之力"),
        .description = COMPOUND_STRING("虫属性的招式威力会提高"),
        .longDescription = COMPOUND_STRING("自己使出的虫属性\n招式伤害提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_SPECTRAL_FORCE] =
    {
        .name = _("幽魂之力"),
        .description = COMPOUND_STRING("幽灵属性的招式威力会提高"),
        .longDescription = COMPOUND_STRING("自己使出的幽灵属性\n招式伤害提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_FIERY_HEART] =
    {
        .name = _("火焰鬃毛"),
        .description = COMPOUND_STRING("火属性的招式威力会提高"),
        .longDescription = COMPOUND_STRING("自己使出的火属性\n招式伤害提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_SEABOUND] =
    {
        .name = _("海洋之缘"),
        .description = COMPOUND_STRING("水属性的招式威力会提高"),
        .longDescription = COMPOUND_STRING("自己使出的水属性\n招式伤害提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_VERDANT_SOUL] =
    {
        .name = _("苍翠之心"),
        .description = COMPOUND_STRING("草属性的招式威力会提高"),
        .longDescription = COMPOUND_STRING("自己使出的草属性\n招式伤害提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_MIND_FORCE] =
    {
        .name = _("念力之源"),
        .description = COMPOUND_STRING("超能力属性招式威力会提高"),
        .longDescription = COMPOUND_STRING("自己使出的超能力属性\n招式伤害提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_FROST_FORCE] =
    {
        .name = _("冰霜之力"),
        .description = COMPOUND_STRING("冰属性的招式威力会提高"),
        .longDescription = COMPOUND_STRING("自己使出的冰属性\n招式伤害提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_NIGHTFALL] =
    {
        .name = _("夜幕降临"),
        .description = COMPOUND_STRING("恶属性的招式威力会提高"),
        .longDescription = COMPOUND_STRING("自己使出的恶属性\n招式伤害提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_FAE_HEART] =
    {
        .name = _("妖精之心"),
        .description = COMPOUND_STRING("妖精属性的招式威力会提高"),
        .longDescription = COMPOUND_STRING("自己使出的妖精属性\n招式伤害提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_PLANTATION] =
    {
        .name = _("播种"),
        .description = COMPOUND_STRING("攻击时有时会种下寄生种子"),
        .longDescription = COMPOUND_STRING("攻击招式有30%的几率\n给非草属性的目标种下\n寄生种子。使出点到为止\n时不会发动。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_ECHOING] =
    {
        .name = _("回声震荡"),
        .description = COMPOUND_STRING("声音招式有时会使对手畏缩"),
        .longDescription = COMPOUND_STRING("声音类招式有30%的\n几率使目标畏缩。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_TIRELESS] =
    {
        .name = _("不知疲倦"),
        .description = COMPOUND_STRING("可以跳过无法动弹的回合"),
        .longDescription = COMPOUND_STRING("使出之后本该有1回合\n无法动弹的招式时，\n可以跳过该回合。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_AURA_SHIELD] =
    {
        .name = _("气场护盾"),
        .description = COMPOUND_STRING("可以挡住1次攻击"),
        .longDescription = COMPOUND_STRING("挡住第1次将要击中\n自己的攻击。穿透和\n破格特性可以无视\n护盾。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_PLAIN_SOUL] =
    {
        .name = _("一般之魂"),
        .description = COMPOUND_STRING("追加一般属性"),
        .longDescription = COMPOUND_STRING("自己在场期间，\n会被追加一般属性。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_FIGHTER_SOUL] =
    {
        .name = _("格斗之魂"),
        .description = COMPOUND_STRING("追加格斗属性"),
        .longDescription = COMPOUND_STRING("自己在场期间，\n会被追加格斗属性。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_WIND_SOUL] =
    {
        .name = _("飞行之魂"),
        .description = COMPOUND_STRING("追加飞行属性"),
        .longDescription = COMPOUND_STRING("自己在场期间，\n会被追加飞行属性。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_VENOM_SOUL] =
    {
        .name = _("毒之魂"),
        .description = COMPOUND_STRING("追加毒属性"),
        .longDescription = COMPOUND_STRING("自己在场期间，\n会被追加毒属性。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_EARTH_SOUL] =
    {
        .name = _("地面之魂"),
        .description = COMPOUND_STRING("追加地面属性"),
        .longDescription = COMPOUND_STRING("自己在场期间，\n会被追加地面属性。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_STONE_SOUL] =
    {
        .name = _("岩石之魂"),
        .description = COMPOUND_STRING("追加岩石属性"),
        .longDescription = COMPOUND_STRING("自己在场期间，\n会被追加岩石属性。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_HIVE_SOUL] =
    {
        .name = _("虫之魂"),
        .description = COMPOUND_STRING("追加虫属性"),
        .longDescription = COMPOUND_STRING("自己在场期间，\n会被追加虫属性。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_PHANTOM_SOUL] =
    {
        .name = _("幽灵之魂"),
        .description = COMPOUND_STRING("追加幽灵属性"),
        .longDescription = COMPOUND_STRING("自己在场期间，\n会被追加幽灵属性。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_STEEL_SOUL] =
    {
        .name = _("钢之魂"),
        .description = COMPOUND_STRING("追加钢属性"),
        .longDescription = COMPOUND_STRING("自己在场期间，\n会被追加钢属性。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_FLAME_SOUL] =
    {
        .name = _("火之魂"),
        .description = COMPOUND_STRING("追加火属性"),
        .longDescription = COMPOUND_STRING("自己在场期间，\n会被追加火属性。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_SEA_SOUL] =
    {
        .name = _("水之魂"),
        .description = COMPOUND_STRING("追加水属性"),
        .longDescription = COMPOUND_STRING("自己在场期间，\n会被追加水属性。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_VERDANT_SOUL_TYPE] =
    {
        .name = _("草之魂"),
        .description = COMPOUND_STRING("追加草属性"),
        .longDescription = COMPOUND_STRING("自己在场期间，\n会被追加草属性。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_THUNDER_SOUL] =
    {
        .name = _("电之魂"),
        .description = COMPOUND_STRING("追加电属性"),
        .longDescription = COMPOUND_STRING("自己在场期间，\n会被追加电属性。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_MIND_SOUL] =
    {
        .name = _("超能力之魂"),
        .description = COMPOUND_STRING("追加超能力属性"),
        .longDescription = COMPOUND_STRING("自己在场期间，\n会被追加超能力属性。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_FROST_SOUL] =
    {
        .name = _("冰之魂"),
        .description = COMPOUND_STRING("追加冰属性"),
        .longDescription = COMPOUND_STRING("自己在场期间，\n会被追加冰属性。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_DRAGON_SOUL] =
    {
        .name = _("龙之魂"),
        .description = COMPOUND_STRING("追加龙属性"),
        .longDescription = COMPOUND_STRING("自己在场期间，\n会被追加龙属性。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_NIGHT_SOUL] =
    {
        .name = _("恶之魂"),
        .description = COMPOUND_STRING("追加恶属性"),
        .longDescription = COMPOUND_STRING("自己在场期间，\n会被追加恶属性。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_FAE_SOUL] =
    {
        .name = _("妖精之魂"),
        .description = COMPOUND_STRING("追加妖精属性"),
        .longDescription = COMPOUND_STRING("自己在场期间，\n会被追加妖精属性。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_SHOWTIME] =
    {
        .name = _("好戏开场"),
        .description = COMPOUND_STRING("出场时，会制造戏法空间"),
        .longDescription = COMPOUND_STRING("出场时，制造持续\n5回合的戏法空间。"
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_ROOTED] =
    {
        .name = _("扎根大地"),
        .description = COMPOUND_STRING("出场时，会进入扎根状态"),
        .longDescription = COMPOUND_STRING("出场时，\n自己进入扎根状态。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_RESTORING] =
    {
        .name = _("水环守护"),
        .description = COMPOUND_STRING("出场时，会进入水流环状态"),
        .longDescription = COMPOUND_STRING("出场时，\n自己进入水流环状态。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_READY_STANCE] =
    {
        .name = _("蓄势待发"),
        .description = COMPOUND_STRING("能率先使出一般属性招式"),
        .longDescription = COMPOUND_STRING("HP全满时，一般属性\n招式的优先度+1。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_FIRST_STRIKE] =
    {
        .name = _("先发制人"),
        .description = COMPOUND_STRING("能率先使出格斗属性招式"),
        .longDescription = COMPOUND_STRING("HP全满时，格斗属性\n招式的优先度+1。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_TOXIC_REFLEX] =
    {
        .name = _("毒性反射"),
        .description = COMPOUND_STRING("能率先使出毒属性招式"),
        .longDescription = COMPOUND_STRING("HP全满时，毒属性\n招式的优先度+1。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_EARTHEN_RUSH] =
    {
        .name = _("大地疾冲"),
        .description = COMPOUND_STRING("能率先使出地面属性招式"),
        .longDescription = COMPOUND_STRING("HP全满时，地面属性\n招式的优先度+1。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_STONE_SENTINEL] =
    {
        .name = _("岩石哨卫"),
        .description = COMPOUND_STRING("能率先使出岩石属性招式"),
        .longDescription = COMPOUND_STRING("HP全满时，岩石属性\n招式的优先度+1。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_SWARM_INSTINCT] =
    {
        .name = _("虫群本能"),
        .description = COMPOUND_STRING("能率先使出虫属性招式"),
        .longDescription = COMPOUND_STRING("HP全满时，虫属性\n招式的优先度+1。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_PHANTOM_STEP] =
    {
        .name = _("幽影步"),
        .description = COMPOUND_STRING("能率先使出幽灵属性招式"),
        .longDescription = COMPOUND_STRING("HP全满时，幽灵属性\n招式的优先度+1。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_QUICK_FORGE] =
    {
        .name = _("迅捷锻造"),
        .description = COMPOUND_STRING("能率先使出钢属性招式"),
        .longDescription = COMPOUND_STRING("HP全满时，钢属性\n招式的优先度+1。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_FLAME_RUSH] =
    {
        .name = _("热浪疾冲"),
        .description = COMPOUND_STRING("能率先使出火属性招式"),
        .longDescription = COMPOUND_STRING("HP全满时，火属性\n招式的优先度+1。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_TIDAL_REFLEX] =
    {
        .name = _("潮汐反射"),
        .description = COMPOUND_STRING("能率先使出水属性招式"),
        .longDescription = COMPOUND_STRING("HP全满时，水属性\n招式的优先度+1。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_VERDANT_GALE] =
    {
        .name = _("苍翠疾风"),
        .description = COMPOUND_STRING("能率先使出草属性招式"),
        .longDescription = COMPOUND_STRING("HP全满时，草属性\n招式的优先度+1。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_STATIC_BURST] =
    {
        .name = _("静电迸发"),
        .description = COMPOUND_STRING("能率先使出电属性招式"),
        .longDescription = COMPOUND_STRING("HP全满时，电属性\n招式的优先度+1。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_THINK_AHEAD] =
    {
        .name = _("先思一步"),
        .description = COMPOUND_STRING("能率先使出超能力属性招式"),
        .longDescription = COMPOUND_STRING("HP全满时，超能力属性\n招式的优先度+1。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_FROST_SNAP] =
    {
        .name = _("瞬息冰霜"),
        .description = COMPOUND_STRING("能率先使出冰属性招式"),
        .longDescription = COMPOUND_STRING("HP全满时，冰属性\n招式的优先度+1。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_DRACONIC_REFLEX] =
    {
        .name = _("龙之感知"),
        .description = COMPOUND_STRING("能率先使出龙属性招式"),
        .longDescription = COMPOUND_STRING("HP全满时，龙属性\n招式的优先度+1。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_NIGHT_STALKER] =
    {
        .name = _("暗夜猎手"),
        .description = COMPOUND_STRING("能率先使出恶属性招式"),
        .longDescription = COMPOUND_STRING("HP全满时，恶属性\n招式的优先度+1。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_FAIRY_BLINK] =
    {
        .name = _("妖精闪步"),
        .description = COMPOUND_STRING("能率先使出妖精属性招式"),
        .longDescription = COMPOUND_STRING("HP全满时，妖精属性\n招式的优先度+1。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_ELEMENTAL_FIST] =
    {
        .name = _("元素之拳"),
        .description = COMPOUND_STRING("拳类招式以特攻计算"),
        .longDescription = COMPOUND_STRING("拳类招式会用特攻代替\n攻击来计算伤害。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_ELEMENTALIST] =
    {
        .name = _("元素使"),
        .description = COMPOUND_STRING("物理招式以特攻计算"),
        .longDescription = COMPOUND_STRING("物理招式会用特攻代替\n攻击来计算伤害。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_SOOTHING] =
    {
        .name = _("安抚"),
        .description = COMPOUND_STRING("有时会让对手陷入睡眠"),
        .longDescription = COMPOUND_STRING("攻击招式有10%的几率\n使目标陷入睡眠。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_ROLLING_STONE] =
    {
        .name = _("滚动岩石"),
        .description = COMPOUND_STRING("滚动击中时速度会提高"),
        .longDescription = COMPOUND_STRING("滚动每击中1次，\n速度提高1级。"
                                           ""
                                           ""),
        .aiRating = 5,
    },
    [ABILITY_GENERALIST] =
    {
        .name = _("多面手"),
        .description = COMPOUND_STRING("强化非自身属性的招式"),
        .longDescription = COMPOUND_STRING("与自己属性不同的招式\n伤害提高25%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_WINDBURST] =
    {
        .name = _("疾风骤起"),
        .description = COMPOUND_STRING("出场时，会刮起顺风"),
        .longDescription = COMPOUND_STRING("出场时，\n为我方刮起顺风。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_BATTLE_FERVOR] =
    {
        .name = _("战斗热忱"),
        .description = COMPOUND_STRING("出场时，攻击会提高"),
        .longDescription = COMPOUND_STRING("出场时，\n攻击提高1级。"
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_GUARD_STANCE] =
    {
        .name = _("防守架势"),
        .description = COMPOUND_STRING("出场时，防御会提高"),
        .longDescription = COMPOUND_STRING("出场时，\n防御提高1级。"
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_MENTAL_SURGE] =
    {
        .name = _("精神涌动"),
        .description = COMPOUND_STRING("出场时，特攻会提高"),
        .longDescription = COMPOUND_STRING("出场时，\n特攻提高1级。"
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_RESOLUTE_GUARD] =
    {
        .name = _("坚毅守护"),
        .description = COMPOUND_STRING("出场时，特防会提高"),
        .longDescription = COMPOUND_STRING("出场时，\n特防提高1级。"
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_SKIP_STEP] =
    {
        .name = _("轻快步伐"),
        .description = COMPOUND_STRING("出场时，速度会提高"),
        .longDescription = COMPOUND_STRING("出场时，\n速度提高1级。"
                                           ""),
        .aiRating = 3,
    },

    [ABILITY_BREAKING_PRESENCE] =
    {
        .name = _("破防威势"),
        .description = COMPOUND_STRING("降低对手的防御"),
        .longDescription = COMPOUND_STRING("出场时，对手的防御\n降低1级。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_DISQUIET] =
    {
        .name = _("心神不宁"),
        .description = COMPOUND_STRING("降低对手的特防"),
        .longDescription = COMPOUND_STRING("出场时，对手的特防\n降低1级。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_HOBBLE] =
    {
        .name = _("纠缠"),
        .description = COMPOUND_STRING("降低对手的速度"),
        .longDescription = COMPOUND_STRING("出场时，对手的速度\n降低1级。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_SEER] =
    {
        .name = _("先知"),
        .description = COMPOUND_STRING("超能力招式击中时提高速度"),
        .longDescription = COMPOUND_STRING("超能力属性的攻击招式\n造成伤害时，速度\n提高1级。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_SMOULDERING] =
    {
        .name = _("余烬未熄"),
        .description = COMPOUND_STRING("受水属性招式时提高特防"),
        .longDescription = COMPOUND_STRING("吸收水属性招式，\n特防提高1级。"
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_CONSUME] =
    {
        .name = _("吞噬"),
        .description = COMPOUND_STRING("打倒对手后回复HP"),
        .longDescription = COMPOUND_STRING("打倒对手后，每有1只\n对手昏厥，回复最大\nHP的1/2。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_LIFESTEAL] =
    {
        .name = _("生命汲取"),
        .description = COMPOUND_STRING("从造成的伤害中吸取HP"),
        .longDescription = COMPOUND_STRING("使出攻击招式时，回复\n所造成伤害的1/8。"
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_HAUNTING] =
    {
        .name = _("阴魂缠身"),
        .description = COMPOUND_STRING("幽灵招式有时会使对手畏缩"),
        .longDescription = COMPOUND_STRING("幽灵属性的攻击招式\n有20%的几率使目标\n畏缩。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_WINDCALLER] =
    {
        .name = _("唤风者"),
        .description = COMPOUND_STRING("强化飞行属性招式与顺风"),
        .longDescription = COMPOUND_STRING("飞行属性招式的伤害\n提高30%，顺风的持续\n时间延长2回合。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_SIEGEBREAKER] =
    {
        .name = _("破阵者"),
        .description = COMPOUND_STRING("攻击招式以防御计算"),
        .longDescription = COMPOUND_STRING("攻击招式会用防御的\n2/3代替攻击或特攻来\n计算伤害。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_SANDSHIELD] =
    {
        .name = _("沙之护盾"),
        .description = COMPOUND_STRING("沙暴时，防御变为2倍"),
        .longDescription = COMPOUND_STRING("沙暴时，\n防御变为2倍。"
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_JADE_BLOOM] =
    {
        .name = _("翠玉绽放"),
        .description = COMPOUND_STRING("无异常时回血增特攻或特防"),
        .longDescription = COMPOUND_STRING("回合结束时，如果没有\n陷入异常状态，回复\n最大HP的1/16，并提高\n特攻或特防。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_BRIMSTONE] =
    {
        .name = _("硫磺之火"),
        .description = COMPOUND_STRING("火属性招式可无视免疫"),
        .longDescription = COMPOUND_STRING("自己攻击时，火属性\n招式可以无视引火等\n对火属性的免疫效果。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_STYGIAN] =
    {
        .name = _("冥河之影"),
        .description = COMPOUND_STRING("能率先攻击睡眠中的对手"),
        .longDescription = COMPOUND_STRING("招式预计会击中睡眠\n状态的目标时，\n优先度+1。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_OMEGA] =
    {
        .name = _("欧米伽"),
        .description = COMPOUND_STRING("属性相克上始终占优"),
        .longDescription = COMPOUND_STRING("自己的攻击都会变为\n效果绝佳，受到的攻击\n都会变为效果不好。\n属性免疫和吸收类特性\n仍然有效。"
                                           ""
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_PERMAFROST] =
    {
        .name = _("永冻"),
        .description = COMPOUND_STRING("不会灼伤，攻击不会被降低"),
        .longDescription = COMPOUND_STRING("不会陷入灼伤状态，\n攻击也不会被降低。\n攻击招式有时会让目标\n陷入冻伤状态。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_STONE_FACE] =
    {
        .name = _("岩石面孔"),
        .description = COMPOUND_STRING("结实，且能力不会被降低"),
        .longDescription = COMPOUND_STRING("HP全满时受到会被打倒\n的攻击，会留下最大HP\n的1/4撑住。不会被其他\n宝可梦降低能力。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_VOIDTOUCH] =
    {
        .name = _("虚空之触"),
        .description = COMPOUND_STRING("无视防守用的壁障"),
        .longDescription = COMPOUND_STRING("攻击招式可以无视\n反射壁、光墙、极光幕、\n神秘守护和白雾。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_GLACIAL] =
    {
        .name = _("冰川之躯"),
        .description = COMPOUND_STRING("提高特防，冰雹时回复HP"),
        .longDescription = COMPOUND_STRING("出场时，特防提高1级。\n冰雹或下雪时，回合\n结束时回复最大HP的\n1/8。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_LUNAR_CYCLE] =
    {
        .name = _("月相轮转"),
        .description = COMPOUND_STRING("攻击后速度会提高"),
        .longDescription = COMPOUND_STRING("用攻击招式对目标造成\n伤害后，速度提高1级。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_FROST_NOVA] =
    {
        .name = _("冰霜新星"),
        .description = COMPOUND_STRING("被打倒时冰冻对手"),
        .longDescription = COMPOUND_STRING("被攻击打倒时，让对手\n陷入正好持续1回合的\n冰冻状态。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_SHOCKWIRING] =
    {
        .name = _("电能布线"),
        .description = COMPOUND_STRING("出场时，会变为充电状态"),
        .longDescription = COMPOUND_STRING("出场时，\n自己变为充电状态。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_RITUAL] =
    {
        .name = _("仪式师"),
        .description = COMPOUND_STRING("吸收幽灵招式强化祸不单行"),
        .longDescription = COMPOUND_STRING("吸收幽灵属性招式并\n回复HP。祸不单行的\n威力提高到75。"
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_OVERLOCK] =
    {
        .name = _("超频"),
        .description = COMPOUND_STRING("换档后强化钢属性招式"),
        .longDescription = COMPOUND_STRING("使出换档后，自己下一次\n使出的钢属性招式威力\n变为2倍。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_SPECTRAL_DRAIN] =
    {
        .name = _("幽魂汲取"),
        .description = COMPOUND_STRING("地面和幽灵招式能吸取HP"),
        .longDescription = COMPOUND_STRING("地面和幽灵属性的招式\n会回复所造成伤害的\n25%。不受寄生种子\n影响。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_BLAZING_SUN] =
    {
        .name = _("烈日灼烧"),
        .description = COMPOUND_STRING("火属性攻击必定使对手灼伤"),
        .longDescription = COMPOUND_STRING("只要目标能被灼伤，\n火属性的攻击招式就\n必定使其灼伤。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_OVERLOAD] =
    {
        .name = _("超载"),
        .description = COMPOUND_STRING("无视对手的防御类道具"),
        .longDescription = COMPOUND_STRING("攻击时，无视目标携带\n道具的防御类效果。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_FILL_VOID] =
    {
        .name = _("填补虚空"),
        .description = COMPOUND_STRING("打倒对手时提高防御和特攻"),
        .longDescription = COMPOUND_STRING("打倒对手后，防御和\n特攻提高1级。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_DUST_DEVIL] =
    {
        .name = _("尘卷风"),
        .description = COMPOUND_STRING("攻击时有时会使对手混乱"),
        .longDescription = COMPOUND_STRING("攻击招式有15%的几率\n使目标混乱。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_SOLIDIFY] =
    {
        .name = _("凝固"),
        .description = COMPOUND_STRING("受特殊招式攻击时提高特防"),
        .longDescription = COMPOUND_STRING("受到特殊招式攻击时，\n特防提高1级。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_UNLEASHED] =
    {
        .name = _("解放之力"),
        .description = COMPOUND_STRING("破壳会提高所有能力"),
        .longDescription = COMPOUND_STRING("破壳会提高所有能力，\n但自己无法使用携带的\n道具。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_TETHER] =
    {
        .name = _("牵系"),
        .description = COMPOUND_STRING("复制对手的能力提高"),
        .longDescription = COMPOUND_STRING("对手的能力提高时，\n会复制提高的部分。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_SOLAR_PANEL] =
    {
        .name = _("太阳能板"),
        .description = COMPOUND_STRING("晴天时，电属性招式必中"),
        .longDescription = COMPOUND_STRING("晴天时，自己使出的\n电属性招式必定命中。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_INFERNAL] =
    {
        .name = _("炼狱威压"),
        .description = COMPOUND_STRING("降低对手的攻击和防御"),
        .longDescription = COMPOUND_STRING("出场时，对手的攻击和\n防御降低1级。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_REEF_WARDEN] =
    {
        .name = _("珊瑚礁守卫"),
        .description = COMPOUND_STRING("换下时回复，封住对手回复"),
        .longDescription = COMPOUND_STRING("替换下场时回复最大HP\n的1/2。接触到自己的\n对手会陷入回复封锁\n状态。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_SOLAR_ARMOR] =
    {
        .name = _("日光铠甲"),
        .description = COMPOUND_STRING("不受变化招式的影响"),
        .longDescription = COMPOUND_STRING("防住对自己使出的\n变化招式。"
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_ABYSSAL_VEIL] =
    {
        .name = _("深渊之幕"),
        .description = COMPOUND_STRING("HP较多时不受变化招式影响"),
        .longDescription = COMPOUND_STRING("HP高于75%时，防住\n对自己使出的变化招式。"
                                           ""
                                           ""),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_PLASMA_SURGE] =
    {
        .name = _("等离子涌动"),
        .description = COMPOUND_STRING("电气场地时攻击必定麻痹"),
        .longDescription = COMPOUND_STRING("电气场地时，只要目标\n能被麻痹，攻击招式就\n必定使其麻痹。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_PHALANX] =
    {
        .name = _("方阵"),
        .description = COMPOUND_STRING("受到的物理招式伤害减半"),
        .longDescription = COMPOUND_STRING("自己受到的物理招式\n伤害减半。"
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_SPECTRAL] =
    {
        .name = _("幽魂之躯"),
        .description = COMPOUND_STRING("受到的特殊招式伤害减半"),
        .longDescription = COMPOUND_STRING("自己受到的特殊招式\n伤害减半。"
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_SUNHARDENED] =
    {
        .name = _("烈日淬炼"),
        .description = COMPOUND_STRING("晴天时，特防变为2倍"),
        .longDescription = COMPOUND_STRING("晴天时，\n特防变为2倍。"
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_HEATSTORM] =
    {
        .name = _("炽热风暴"),
        .description = COMPOUND_STRING("出场时，会布下焦土场地"),
        .longDescription = COMPOUND_STRING("出场时布下焦土场地。\n强化火属性招式和热水，\n削弱热水以外的水属性\n招式及冰属性招式。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_COALWALKER] =
    {
        .name = _("踏炭者"),
        .description = COMPOUND_STRING("焦土场地时，防御变为2倍"),
        .longDescription = COMPOUND_STRING("焦土场地时，\n防御变为2倍。"
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_LAVA_SURFER] =
    {
        .name = _("熔岩冲浪"),
        .description = COMPOUND_STRING("焦土场地时，速度变为2倍"),
        .longDescription = COMPOUND_STRING("焦土场地时，\n速度变为2倍。"
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_ASH_ASSETS] =
    {
        .name = _("灰烬之利"),
        .description = COMPOUND_STRING("在焦土场地上更加强大"),
        .longDescription = COMPOUND_STRING("打倒对手后，如果没有\n焦土场地就会布下。\n焦土场地时，攻击招式\n的伤害提高15%。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_FORCE_RETURN] =
    {
        .name = _("力量反震"),
        .description = COMPOUND_STRING("反弹受到的攻击伤害"),
        .longDescription = COMPOUND_STRING("受到攻击时，对手会\n受到所造成伤害的30%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_ENIGMA] =
    {
        .name = _("谜团"),
        .description = COMPOUND_STRING("部分招式的威力变为2倍"),
        .longDescription = COMPOUND_STRING("大地之力、原始之力、\n辅助力量等指定招式的\n威力变为2倍，中文名\n无需含有“力量”二字。"
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_BURROWER] =
    {
        .name = _("掘地者"),
        .description = COMPOUND_STRING("挖洞无需蓄力且威力提高"),
        .longDescription = COMPOUND_STRING("挖洞只需1回合就能\n使出，且伤害提高50%。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_DIVER] =
    {
        .name = _("潜水者"),
        .description = COMPOUND_STRING("潜水无需蓄力且威力提高"),
        .longDescription = COMPOUND_STRING("潜水只需1回合就能\n使出，且伤害提高50%。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_LAST_STAND] =
    {
        .name = _("殊死一搏"),
        .description = COMPOUND_STRING("强化攻击，但会消耗HP"),
        .longDescription = COMPOUND_STRING("攻击招式的威力提高\n30%，但攻击后自己会\n失去最大HP的10%。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_HUNTER] =
    {
        .name = _("猎手"),
        .description = COMPOUND_STRING("擅长对付麻痹的对手"),
        .longDescription = COMPOUND_STRING("大蛇瞪眼还会使对手\n混乱。有对手处于麻痹\n状态时，攻击提高50%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_NINE_LIVES] =
    {
        .name = _("九条命"),
        .description = COMPOUND_STRING("结实，HP低时能率先行动"),
        .longDescription = COMPOUND_STRING("HP全满时，和结实一样\n能撑住会被打倒的攻击。\nHP在1/3以下时，\n优先度+2。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_DEBILITATE] =
    {
        .name = _("衰弱"),
        .description = COMPOUND_STRING("更快消耗对手的PP"),
        .longDescription = COMPOUND_STRING("对手向自己使出招式时，\n会额外多消耗3点PP。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_TITAN_GRIP] =
    {
        .name = _("泰坦之握"),
        .description = COMPOUND_STRING("把自身能力降低转给对手"),
        .longDescription = COMPOUND_STRING("使出近身战和蛮力时，\n降低的不是自己的能力，\n而是对手的能力。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_FLEXIBLE] =
    {
        .name = _("准备周全"),
        .description = COMPOUND_STRING("需要2回合的招式立刻使出"),
        .longDescription = COMPOUND_STRING("需要2回合的招式只需\n1回合就能使出。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_REBORN] =
    {
        .name = _("重生"),
        .description = COMPOUND_STRING("可以让自己复活1次"),
        .longDescription = COMPOUND_STRING("每场战斗1次，即将\n昏厥时不会倒下，\n并且HP会全部回复。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_REJUVENATION] =
    {
        .name = _("焕发生机"),
        .description = COMPOUND_STRING("未受伤害时回复HP"),
        .longDescription = COMPOUND_STRING("该回合没有受到伤害时，\n回合结束时回复最大HP\n的1/10。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_TIDAL_DEITY] =
    {
        .name = _("潮汐之神"),
        .description = COMPOUND_STRING("HP全满时可穿透防守"),
        .longDescription = COMPOUND_STRING("HP全满时，无视守护和\n壁障效果。HP不再全满\n时，会在5回合内将\n天气变为下雨。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_ROCKSTORM] =
    {
        .name = _("岩石风暴"),
        .description = COMPOUND_STRING("沙暴时，岩石属性招式必中"),
        .longDescription = COMPOUND_STRING("沙暴时，自己使出的\n岩石属性招式必定命中。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_STORMRIDER] =
    {
        .name = _("驭风者"),
        .description = COMPOUND_STRING("降低对手的特防"),
        .longDescription = COMPOUND_STRING("每回合结束时，对手的\n特防降低1级。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_VOLCANO_HOWL] =
    {
        .name = _("火山咆哮"),
        .description = COMPOUND_STRING("降低对手的防御"),
        .longDescription = COMPOUND_STRING("每回合结束时，对手的\n防御降低1级。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_ARCTIC_AURA] =
    {
        .name = _("极地气场"),
        .description = COMPOUND_STRING("降低对手的攻击"),
        .longDescription = COMPOUND_STRING("每回合结束时，对手的\n攻击降低1级。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_BLOODLUST] =
    {
        .name = _("嗜血"),
        .description = COMPOUND_STRING("击中要害时提高攻击和速度"),
        .longDescription = COMPOUND_STRING("击中对手要害时，攻击\n和速度各提高1级。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_GANG_UP] =
    {
        .name = _("合力围攻"),
        .description = COMPOUND_STRING("对受过伤害的对手更强"),
        .longDescription = COMPOUND_STRING("对本回合已受到过伤害\n的对手，招式伤害\n提高20%。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_PENDULUM] =
    {
        .name = _("钟摆"),
        .description = COMPOUND_STRING("连续使出相同招式威力提高"),
        .longDescription = COMPOUND_STRING("连续使出相同的招式时，\n每次威力提高20%，\n最多提高60%。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_MOMENTUM] =
    {
        .name = _("动量"),
        .description = COMPOUND_STRING("使出先制招式后提高速度"),
        .longDescription = COMPOUND_STRING("使出先制招式后，\n速度提高1级。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_DESPERADO] =
    {
        .name = _("亡命之徒"),
        .description = COMPOUND_STRING("受效果绝佳时提高攻击特攻"),
        .longDescription = COMPOUND_STRING("受到效果绝佳的伤害时，\n攻击和特攻提高1级。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_GLASS_CANNON] =
    {
        .name = _("玻璃大炮"),
        .description = COMPOUND_STRING("攻击更强，但防守更脆弱"),
        .longDescription = COMPOUND_STRING("出场时，攻击和特攻中\n较高的一项提高2级，\n防御和特防各降低2级。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_AEGIS] =
    {
        .name = _("神盾"),
        .description = COMPOUND_STRING("每回合限制1次攻击的伤害"),
        .longDescription = COMPOUND_STRING("每回合1次，受到的\n直接攻击伤害不会超过\n最大HP的1/4。"
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MARTYR] =
    {
        .name = _("舍身奉献"),
        .description = COMPOUND_STRING("昏厥时回复同伴的HP"),
        .longDescription = COMPOUND_STRING("自己昏厥时，同伴回复\n最大HP的1/4。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_INDOMITABLE] =
    {
        .name = _("百折不挠"),
        .description = COMPOUND_STRING("不会畏缩，易闪避变化招式"),
        .longDescription = COMPOUND_STRING("不会畏缩。对自己使出\n的变化招式命中率减半。"
                                           ""
                                           ""),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_COLOSSAL] =
    {
        .name = _("庞然巨躯"),
        .description = COMPOUND_STRING("防住低威力的攻击"),
        .longDescription = COMPOUND_STRING("威力在44以下的攻击\n招式对自己无效。"
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_PARRYING] =
    {
        .name = _("招架"),
        .description = COMPOUND_STRING("受到攻击也不会中断集中"),
        .longDescription = COMPOUND_STRING("真气拳不会被打断。\n蓄力期间受到攻击时，\n防御会提高。"
                                           ""
                                           ""),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_FAINTRATTLE] =
    {
        .name = _("濒倒震响"),
        .description = COMPOUND_STRING("被接触招式打倒时使其中毒"),
        .longDescription = COMPOUND_STRING("被接触类招式打倒时，\n让对手陷入剧毒状态。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_SHARDPLATE] =
    {
        .name = _("碎片铠甲"),
        .description = COMPOUND_STRING("铠甲会随战斗逐渐减弱"),
        .longDescription = COMPOUND_STRING("起初能减轻受到的直接\n伤害，但本场战斗中\n每受到1次攻击，效果\n就会减弱。"
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_HAUNTED] =
    {
        .name = _("幽魂附体"),
        .description = COMPOUND_STRING("视为处于异常状态"),
        .longDescription = COMPOUND_STRING("对于与异常状态有关的\n效果，视为处于异常\n状态，但不会陷入\n异常状态。"
                                           ""
                                           ""),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_MENDING] =
    {
        .name = _("自我修复"),
        .description = COMPOUND_STRING("回合结束时有时会回复"),
        .longDescription = COMPOUND_STRING("回合结束时，有30%的\n几率治愈异常状态并\n回复最大HP的1/8。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_PLAGUETOUCH] =
    {
        .name = _("疫病之触"),
        .description = COMPOUND_STRING("接触攻击有时造成异常状态"),
        .longDescription = COMPOUND_STRING("用接触类招式攻击时，\n有20%的几率让目标\n陷入随机一种异常状态。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_MONSOON] =
    {
        .name = _("季风"),
        .description = COMPOUND_STRING("下雨时强化水属性招式"),
        .longDescription = COMPOUND_STRING("下雨时，水属性招式\n必定命中，并且无视\n对水属性的免疫效果。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_MIRAGE] =
    {
        .name = _("海市蜃楼"),
        .description = COMPOUND_STRING("晴天时有时会使对手混乱"),
        .longDescription = COMPOUND_STRING("晴天时，攻击招式有\n25%的几率使目标混乱。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_BLIZZARD_HEART] =
    {
        .name = _("暴雪之心"),
        .description = COMPOUND_STRING("下雪时有时会冰冻对手"),
        .longDescription = COMPOUND_STRING("下雪或冰雹时，冰属性\n的攻击招式有20%的\n几率使目标冰冻或冻伤。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_MUDSLIDE] =
    {
        .name = _("泥石流"),
        .description = COMPOUND_STRING("沙暴时吸收水属性招式"),
        .longDescription = COMPOUND_STRING("沙暴时，吸收水属性\n招式，防御提高2级。"
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_CHANNEL_EARTH] =
    {
        .name = _("大地导流"),
        .description = COMPOUND_STRING("有场地时回复HP"),
        .longDescription = COMPOUND_STRING("存在任意场地时，回合\n结束时回复最大HP的\n1/16。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_MAGNIFY_FIELD] =
    {
        .name = _("场域扩张"),
        .description = COMPOUND_STRING("延长天气和场地的回合数"),
        .longDescription = COMPOUND_STRING("出场时，当前有回合数\n限制的天气和场地\n延长2回合。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_BLITZ] =
    {
        .name = _("闪击"),
        .description = COMPOUND_STRING("下一次攻击威力提高"),
        .longDescription = COMPOUND_STRING("使出守住后，下一次\n使出的攻击招式伤害\n提高20%。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_GUARDIAN] =
    {
        .name = _("守护者"),
        .description = COMPOUND_STRING("吸引攻击并减轻伤害"),
        .longDescription = COMPOUND_STRING("把对手瞄准同伴的单体\n攻击吸引到自己身上，\n且受到的伤害减少15%。"
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_BACKDRAFT] =
    {
        .name = _("回燃"),
        .description = COMPOUND_STRING("替换下场时降低对手的速度"),
        .longDescription = COMPOUND_STRING("自己主动替换下场时，\n对手的速度降低1级。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_RALLY] =
    {
        .name = _("鼓舞"),
        .description = COMPOUND_STRING("提高同伴最高的能力"),
        .longDescription = COMPOUND_STRING("在双打对战中出场时，\n同伴HP以外最高的\n那项能力提高1级。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_ECHO_CHAMBER] =
    {
        .name = _("回声室"),
        .description = COMPOUND_STRING("声音招式会产生回声"),
        .longDescription = COMPOUND_STRING("单体声音类招式会\n击中2次，第2次的威力\n较低。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_FLARE] =
    {
        .name = _("烈焰"),
        .description = COMPOUND_STRING("对灼伤的对手强化火招式"),
        .longDescription = COMPOUND_STRING("对灼伤状态的目标，\n火属性招式的伤害\n提高50%。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_SPLINTER] =
    {
        .name = _("裂伤"),
        .description = COMPOUND_STRING("对伤到的对手追加少量伤害"),
        .longDescription = COMPOUND_STRING("回合结束时，本回合被\n自己造成过伤害的对手\n减少最大HP的1/16。"
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_MAIM_AND_MEND] =
    {
        .name = _("伤敌愈己"),
        .description = COMPOUND_STRING("击中要害时回复自己的HP"),
        .longDescription = COMPOUND_STRING("击中对手要害时，回复\n所造成伤害的1/4。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_VALKYRIE] =
    {
        .name = _("女武神"),
        .description = COMPOUND_STRING("获得钢属性的抗性"),
        .longDescription = COMPOUND_STRING("获得钢属性的抗性和对\n毒属性的免疫，但不会\n获得钢属性的弱点。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_IMMOVABLE] =
    {
        .name = _("岿然不动"),
        .description = COMPOUND_STRING("最后行动，不会被强制替换"),
        .longDescription = COMPOUND_STRING("在相同优先度的招式中\n最后行动，且不会被\n强制替换下场。"
                                           ""
                                           ""),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_TRANSMUTE] =
    {
        .name = _("转化"),
        .description = COMPOUND_STRING("削弱受到的第1次攻击"),
        .longDescription = COMPOUND_STRING("每场战斗1次，将对手的\n直接攻击变为自己能\n抵抗的属性。"
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_TWIN_STARS] =
    {
        .name = _("双子星"),
        .description = COMPOUND_STRING("双子星会一同提高能力"),
        .longDescription = COMPOUND_STRING("双打对战中，拥有双子星\n特性的两只宝可梦搭档\n时，各有5项能力提高\n1级，仅限1次。"
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_COSMIC_FORM] =
    {
        .name = _("宇宙之形"),
        .description = COMPOUND_STRING("扭曲属性相克关系"),
        .longDescription = COMPOUND_STRING("自己的招式可以无视\n属性免疫，受到的效果\n绝佳伤害会减轻。"
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_TIME_SPIRAL] =
    {
        .name = _("时间螺旋"),
        .description = COMPOUND_STRING("扭曲优先度与天气场地"),
        .longDescription = COMPOUND_STRING("除强制替换的招式外，\n招式的优先度会逆转。\n有回合数限制的天气和\n场地，每回合结束时\n会多减少1回合。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_NULL_SPACE] =
    {
        .name = _("虚无空间"),
        .description = COMPOUND_STRING("可以穿透守护效果"),
        .longDescription = COMPOUND_STRING("攻击招式可以无视只持续\n1回合的守护效果，\n但此时伤害减半。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_SPACETIME_RIFT] =
    {
        .name = _("时空裂隙"),
        .description = COMPOUND_STRING("双神同场时可防御范围攻击"),
        .longDescription = COMPOUND_STRING("帕路奇亚和帝牙卢卡在\n同一方时，保护它们\n不受群体攻击招式影响。"
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_UNDERDOG] =
    {
        .name = _("以弱胜强"),
        .description = COMPOUND_STRING("对更强的对手造成更多伤害"),
        .longDescription = COMPOUND_STRING("对种族值合计比自己高\n的目标，伤害提高30%。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_ROCK_AND_STONE] =
    {
        .name = _("岩与石"),
        .description = COMPOUND_STRING("打倒对手时撒下隐形岩"),
        .longDescription = COMPOUND_STRING("打倒对手时，在对手的\n场地上撒下隐形岩。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_POLARITY_SHIFT] =
    {
        .name = _("极性转换"),
        .description = COMPOUND_STRING("出场时，与对手交换速度"),
        .longDescription = COMPOUND_STRING("出场时，与对手的\n宝可梦交换速度。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_HORSE_COUNCIL] =
    {
        .name = _("群马议会"),
        .description = COMPOUND_STRING("马类同伴会强化攻击招式"),
        .longDescription = COMPOUND_STRING("队伍中每有1只未昏厥的\n马类同伴，物理和特殊\n招式的伤害提高10%。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_POWER_SHIFT] =
    {
        .name = _("力量对调"),
        .description = COMPOUND_STRING("出场时与对手交换攻击特攻"),
        .longDescription = COMPOUND_STRING("出场时，与对手的\n宝可梦交换攻击和特攻。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_WISHMAKER] =
    {
        .name = _("祈愿者"),
        .description = COMPOUND_STRING("出场时，会使出祈愿"),
        .longDescription = COMPOUND_STRING("出场时，\n为自己使出祈愿。"
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_FLIER] =
    {
        .name = _("飞行者"),
        .description = COMPOUND_STRING("飞翔无需蓄力且威力提高"),
        .longDescription = COMPOUND_STRING("飞翔只需1回合就能\n使出，且伤害提高50%。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_FLAMEBURST] =
    {
        .name = _("焰爆"),
        .description = COMPOUND_STRING("昏厥时让对手灼伤"),
        .longDescription = COMPOUND_STRING("因攻击招式而昏厥时，\n让对手一方陷入灼伤\n状态。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_INKY] =
    {
        .name = _("泼墨"),
        .description = COMPOUND_STRING("受到攻击时降低对手命中率"),
        .longDescription = COMPOUND_STRING("受到攻击招式攻击时，\n降低对手的命中率。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_BRAND_OF_TORMENT] =
    {
        .name = _("无理烙印"),
        .description = COMPOUND_STRING("接触时有时令对手无理取闹"),
        .longDescription = COMPOUND_STRING("受到接触类招式攻击时，\n有30%的几率让对手\n陷入无理取闹状态。"
                                           ""
                                           ""),
        .aiRating = 4,
    },

    [ABILITY_DRAGONIZE] =
    {
        .name = _("龙皮肤"),
        .description = COMPOUND_STRING("一般招式变为龙属性并强化"),
        .longDescription = COMPOUND_STRING("一般属性的招式会变为\n龙属性，且伤害提高\n20%。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_EELEVATE] =
    {
        .name = _("鳗鳗高升"),
        .description = COMPOUND_STRING("飘浮，打倒对手时提高能力"),
        .longDescription = COMPOUND_STRING("不会受到地面属性招式\n的攻击。打倒对手时，\n自己最高的那项能力\n会提高。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_MEGA_SOL] =
    {
        .name = _("超级日光"),
        .description = COMPOUND_STRING("自己始终视为处于晴天"),
        .longDescription = COMPOUND_STRING("自己的招式和效果会\n视为处于晴天来发动。"
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_SPICY_SPRAY] =
    {
        .name = _("辣椒喷发"),
        .description = COMPOUND_STRING("受到伤害时让对手灼伤"),
        .longDescription = COMPOUND_STRING("受到直接攻击的伤害时，\n让对手陷入灼伤状态。"
                                           ""
                                           ""),
        .aiRating = 5,
    },

    [ABILITY_WIND_CHIME] =
    {
        .name = _("风铃"),
        .description = COMPOUND_STRING("受到风的招式时提高特攻"),
        .longDescription = COMPOUND_STRING("风类招式无效，反而会\n使特攻提高。顺风时\n特攻也会提高。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_GRAVITY_WELL] =
    {
        .name = _("重力井"),
        .description = COMPOUND_STRING("出场时，会使重力变强"),
        .longDescription = COMPOUND_STRING("出场时，在5回合内\n使重力变强。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_ALLSEEING_IDOL] =
    {
        .name = _("全视偶像"),
        .description = COMPOUND_STRING("飘浮，且重力下防御提高"),
        .longDescription = COMPOUND_STRING("即使在重力下，也不会\n受到地面属性招式和\n场地陷阱的影响。\n重力下防御还会提高\n30%。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_ACIDIC] =
    {
        .name = _("强酸"),
        .description = COMPOUND_STRING("毒属性招式能腐蚀钢属性"),
        .longDescription = COMPOUND_STRING("毒属性的攻击招式对\n钢属性宝可梦效果绝佳。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_AURA_GUARD] =
    {
        .name = _("波导防护"),
        .description = COMPOUND_STRING("受到的接触招式伤害减半"),
        .longDescription = COMPOUND_STRING("受到接触类招式的伤害\n减半。"
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_LIKE_A_DRAGON] =
    {
        .name = _("如龙"),
        .description = COMPOUND_STRING("获得龙属性的优势"),
        .longDescription = COMPOUND_STRING("获得龙属性的属性一致\n加成和抗性，但不会\n获得龙属性的弱点。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_ELECTROLEVITATE] =
    {
        .name = _("电磁作用"),
        .description = COMPOUND_STRING("不会受地面属性招式攻击"),
        .longDescription = COMPOUND_STRING("不会受到地面属性招式\n和地面上的场地陷阱\n影响，但仍能获得电气\n场地的效果。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MALICE_AURA] =
    {
        .name = _("恶意气场"),
        .description = COMPOUND_STRING("全体的幽灵属性招式变强"),
        .longDescription = COMPOUND_STRING("场上所有幽灵属性招式\n的威力提高33%。"
                                           ""
                                           ""),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_TRUESHOT_AURA] =
    {
        .name = _("精准气场"),
        .description = COMPOUND_STRING("我方的招式容易击中要害"),
        .longDescription = COMPOUND_STRING("自己和同伴的\n击中要害率提高2级。"
                                           ""
                                           ""),
        .aiRating = 10,
    },

    [ABILITY_OGRE_FORCE] =
    {
        .name = _("厄鬼之力"),
        .description = COMPOUND_STRING("强化有追加效果的招式"),
        .longDescription = COMPOUND_STRING("有追加效果的招式伤害\n提高15%。"
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_RESONANCE] =
    {
        .name = _("共鸣"),
        .description = COMPOUND_STRING("强化声音招式并减轻其伤害"),
        .longDescription = COMPOUND_STRING("声音类招式的威力\n提高30%，受到声音类\n招式的伤害减半。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_TEMPO] =
    {
        .name = _("节拍"),
        .description = COMPOUND_STRING("声音招式击中时提高速度"),
        .longDescription = COMPOUND_STRING("用声音类招式造成伤害\n后，速度提高1级。"
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_CONTROLLED_BURN] =
    {
        .name = _("控火"),
        .description = COMPOUND_STRING("强化有反作用力的火招式"),
        .longDescription = COMPOUND_STRING("有反作用力的火属性\n攻击招式伤害提高20%，\n且反作用力伤害或HP\n消耗减半。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_CROSSFIRE] =
    {
        .name = _("交叉火力"),
        .description = COMPOUND_STRING("交替使出不同属性威力提高"),
        .longDescription = COMPOUND_STRING("攻击招式的属性与自己\n上一次的攻击不同时，\n伤害提高25%。替换后\n重新计算。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
    },

    [ABILITY_HOT_TAG] =
    {
        .name = _("热力交接"),
        .description = COMPOUND_STRING("保护接替上场的宝可梦"),
        .longDescription = COMPOUND_STRING("用招式替换下场后，\n接替上场的宝可梦下一次\n受到的直接攻击伤害\n减少40%。"
                                           ""
                                           ""
                                           ""),
        .aiRating = 8,
    },

    [ABILITY_BULL_RUSH] =
    {
        .name = _("蛮牛冲锋"),
        .description = COMPOUND_STRING("出场后第1次攻击威力提高"),
        .longDescription = COMPOUND_STRING("出场后第1次使出的\n攻击招式伤害提高20%。"
                                           ""
                                           ""),
        .aiRating = 6,
    },

    [ABILITY_MIND_FLOAT] =
    {
        .name = _("精神浮游"),
        .description = COMPOUND_STRING("不会受地面属性招式攻击"),
        .longDescription = COMPOUND_STRING("不会受到地面属性招式\n和地面上的场地陷阱\n影响，但仍能获得精神\n场地的效果。"
                                           ""
                                           ""
                                           ""
                                           ""),
        .aiRating = 7,
        .breakable = TRUE,
    },
};
