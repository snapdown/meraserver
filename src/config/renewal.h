/// game renewal server mode
/// (disable by commenting the line)
///
/// leave this line to enable renewal specific support such as renewal formulas
//#define RENEWAL << Comment
/// renewal cast time
/// (disable by commenting the line)
///
/// leave this line to enable renewal casting time algorithms
/// cast time is decreased by DEX * 2 + INT while 20% of the cast time is not reduced by stats.
/// example:
/// on a skill whos cast time is 10s, only 8s may be reduced. the other 2s are part of a
/// "fixed cast time" which can only be reduced by specialist items and skills
//#define RENEWAL_CAST << Comment
/// renewal drop rate algorithms
/// (disable by commenting the line)
///
/// leave this line to enable renewal item drop rate algorithms
/// while enabled a special modified based on the difference between the player and monster level is applied
/// based on the http://irowiki.org/wiki/Drop_System#Level_Factor table
//#define RENEWAL_DROP << Comment
/// renewal exp rate algorithms
/// (disable by commenting the line)
///
/// leave this line to enable renewal item exp rate algorithms
/// while enabled a special modified based on the difference between the player and monster level is applied
//#define RENEWAL_EXP << Comment
/// renewal cast time variable cast requirement
///
/// this is the value required for no variable cast-time with stats.
/// formula: (DEX * 2) + INT
/// default: 530
#define RENEWAL_CAST_VMIN 530