/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 6;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
//static const char *fonts[]          = { "Fontawesome:size=9", "Hack Nerd Font:size=10" };
static const char *fonts[]          = { "Fontawesome:size=10", "Ubuntu Mono derivative Powerline:size=12", "JoyPixels:pixelsize=12:antialias=true:autohint=true" };
static const char dmenufont[]       = "monospace:size=10";

static const char col_black[]       = "#000000";
static const char col_white[]       = "#ffffff";

static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;

static char normbgcolor[]           = "#282828";
static char normbordercolor[]       = "#222222";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#000000";
static char selbordercolor[]        = "#c9cba3";
static char selbgcolor[]            = "#282828";

static char color0bg[]					    = "#c9cba3";
static char color1bg[]        	    = "#ffe1a8";
static char color2bg[]        	    = "#e26d5c";
static char color3bg[]        	    = "#723d46";
static char color4bg[]        	    = "#472d30";
static char color5bg[]        	    = "#723d46";
                                              
static char color0fg[]        	    = "#000000";
static char color1fg[]        	    = "#000000";
static char color2fg[]        	    = "#000000";
static char color3fg[]        	    = "#ffffff";
static char color4fg[]        	    = "#ffffff";
static char color5fg[]        	    = "#ffffff";

static const char *colors[][3]      = {
	/*					fg         bg          border   */
	[SchemeNorm]			= { normfgcolor, normbgcolor, normbordercolor },
  [SchemeSel]				= { selfgcolor,  selbgcolor,  selbordercolor  },

	[SchemeStatus]		= { normfgcolor, normbgcolor, normbordercolor },
	[SchemeTagsSel]		= { selfgcolor,	 selbgcolor,  selbordercolor	 },
	[SchemeTagsNorm]	= { normfgcolor, normbgcolor, normbordercolor  },
  [SchemeInfoSel]		= { selfgcolor,	 selbgcolor,  selbordercolor },
  [SchemeInfoNorm]  = { normfgcolor, normbgcolor, normbordercolor },

	[SchemeColor0]		= { color0fg,		 color0bg,		normbordercolor },
	[SchemeColor1]		= { color1fg,		 color1bg,		normbordercolor },
	[SchemeColor2]		= { color2fg,		 color2bg,		normbordercolor },
	[SchemeColor3]		= { color3fg,		 color3bg,		normbordercolor },
	[SchemeColor4]		= { color4fg,		 color4bg,		normbordercolor },
	[SchemeColor5]		= { color5fg,		 color5bg,		normbordercolor },
};

static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },

	[SchemeStatus]		= { OPAQUE, OPAQUE,	OPAQUE }, 
	[SchemeTagsSel]		= { OPAQUE, OPAQUE,	OPAQUE },
	[SchemeTagsNorm]	= { OPAQUE, OPAQUE, OPAQUE },
  [SchemeInfoSel]		= { OPAQUE, OPAQUE,	OPAQUE },
  [SchemeInfoNorm]  = { OPAQUE, OPAQUE,	OPAQUE },

  [SchemeColor0]		= { OPAQUE, OPAQUE,	OPAQUE }, 
  [SchemeColor1]    = { OPAQUE, OPAQUE,	OPAQUE },
  [SchemeColor2]    = { OPAQUE, OPAQUE, OPAQUE },
  [SchemeColor3]    = { OPAQUE, OPAQUE,	OPAQUE },
  [SchemeColor4]    = { OPAQUE, OPAQUE,	OPAQUE },
  [SchemeColor5]		= { OPAQUE, OPAQUE,	OPAQUE },
};

/* tagging */
//static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title						tags mask     iscentered		isfloating   isterminal		noswallow		monitor */
	{ "Gimp",     NULL,       NULL,       		0,            0,						1,           0,						0,					-1 },
	{ "Telegram", NULL,       NULL,       		0,						1,						1,           0,						0,					-1 },
	{ "St",				NULL,				NULL,						0,            1,						0,           1,						-1,					-1 },
	{ "St",				"float",		NULL,						0,            1,						1,           1,						-1,					-1 },
	{ "Sxiv",			"float",		NULL,						0,            1,						1,           0,						0,					-1 },
	{ NULL,       NULL,       "Event Tester", 0,						1,						1,					 0,           1,					-1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
//#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, XK_w,     ACTION##stack, {.i = 0 } }, \
	//{ MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \
	//{ MOD, XK_a,     ACTION##stack, {.i = 1 } }, \
	//{ MOD, XK_z,     ACTION##stack, {.i = 2 } }, \
	//{ MOD, XK_x,     ACTION##stack, {.i = -1 } },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", col_black, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *lockcmd[]  = { "lock_screen", NULL };
static const char *emailcmd[]  = { "st", "-n", "float", "-g", "140x50", "-e", "neomutt", NULL };
static const char *newscmd[]  = { "st", "-e", "newsboat", NULL };
static const char *musiccmd[]  = { "st", "-n", "float", "-g", "120x40", "-e", "ncmpcpp", NULL };
static const char *urlcmd[]  = { "urxvt", "-e", "search_w3m", NULL };
static const char *screenshotcmd[]  = { "screenshot", NULL };
static const char *screenshotcropcmd[]  = { "screenshot", "-s", NULL };
static const char *telegramcmd[]  = { "toggle_telegram", NULL };
static const char *togglemusiccmd[]  = { "mpc", "toggle", NULL };

static const char *volumeupcmd[]  = { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "+1000", NULL };
static const char *volumedowncmd[]  = { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "-1000", NULL };
static const char *nextsongcmd[]  = { "mpc", "next", NULL };
static const char *previoussongcmd[]  = { "mpc", "prev", NULL };
static const char *togglemutecmd[]  = { "pactl", "set-sink-mute", "@DEFAULT_SINK@", "toggle", NULL };

static const char *quitcmd[]  = { "killall", "xinit", NULL };
static const char *systemcmd[]  = { "sysact", NULL };
static const char *emojicmd[]  = { "dmenuunicode", NULL };
static const char *mountcmd[]  = { "dmenu_mount", NULL };
static const char *unmountcmd[]  = { "dmenu_unmount", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, NULL };
static const char *screenkeycmd[]  = { "toggle_screenkey", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	/* ------------------------------ apps ---------------------------------- */
	{ MODKEY,                       XK_space,						 spawn,          {.v = dmenucmd } },
	{ MODKEY,												XK_Return, 					 spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_minus,  					 togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,												XK_e,			 					 spawn,          {.v = emailcmd } },
	{ MODKEY,												XK_s,			 					 spawn,          {.v = screenkeycmd } },
	{ MODKEY,												XK_n,			 					 spawn,          {.v = newscmd } },
	{ MODKEY,												XK_u,			 					 spawn,          {.v = urlcmd } },
	{ MODKEY,												XK_equal,	 					 spawn,          {.v = telegramcmd } },
	/* ------------------------------ music ---------------------------------- */
	{ MODKEY,												XK_m,								 spawn,					 {.v = musiccmd } },
	{ MODKEY,												XK_p,								 spawn,          {.v = togglemusiccmd } },
	{ MODKEY|ShiftMask,							XK_bracketright,		 spawn,          {.v = nextsongcmd } },
	{ MODKEY|ShiftMask,							XK_bracketleft,			 spawn,          {.v = previoussongcmd } },
	/* ------------------------------ various ---------------------------------- */
	{ MODKEY,												XK_bracketright,		 spawn,          {.v = volumeupcmd } },
	{ MODKEY,												XK_bracketleft,			 spawn,          {.v = volumedowncmd } },
	{ MODKEY,												XK_backslash,			 	 spawn,          {.v = togglemutecmd } },
	{ MODKEY,												XK_BackSpace,			 	 spawn,          {.v = systemcmd } },
	{ MODKEY,												XK_z,			 					 spawn,          {.v = lockcmd } },
	{ MODKEY,												XK_y,			 					 spawn,          {.v = screenshotcmd } },
	{ MODKEY|ShiftMask,							XK_y,			 					 spawn,          {.v = screenshotcropcmd } },
	{ MODKEY,												XK_grave,	 					 spawn,					 {.v = emojicmd } },
	{ MODKEY|ShiftMask,							XK_r,			 					 quit,           {0} },
	{ MODKEY,												XK_F1,		 					 spawn,          {.v = mountcmd } },
	{ MODKEY,												XK_F2,		 					 spawn,          {.v = unmountcmd } },
	{ MODKEY,                       XK_b,      					 togglebar,      {0} },
	STACKKEYS(MODKEY,                          focus)
	STACKKEYS(MODKEY|ShiftMask,                push)
	{ MODKEY,                       XK_i,      					 incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      					 incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      					 setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      					 setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, 					 zoom,           {0} },
	{ MODKEY,                       XK_Tab,    					 view,           {0} },
	{ MODKEY,												XK_q,      					 killclient,     {0} },
	//{ MODKEY,                       XK_t,    					   setlayout,      {.v = &layouts[0]} },
	//{ MODKEY|ShiftMask,             XK_f,    					   setlayout,      {.v = &layouts[1]} },
	//{ MODKEY,                       XK_m,    					   setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ControlMask,						XK_comma,  					 cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, 					 cyclelayout,    {.i = +1 } },
	{ MODKEY,					              XK_f,      					 togglefullscr,     {0} },
	//{ MODKEY,                       XK_d,		 					   setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,	 					 togglefloating, {0} },
	{ MODKEY,                       XK_0,      					 view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      					 tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  					 focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, 					 focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  					 tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, 					 tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_F5,							 xrdb,           {.v = NULL } },
	TAGKEYS(                        XK_1,      					                 0)
	TAGKEYS(                        XK_2,      					                 1)
	TAGKEYS(                        XK_3,      					                 2)
	TAGKEYS(                        XK_4,      					                 3)
	TAGKEYS(                        XK_5,      					                 4)
	TAGKEYS(                        XK_6,      					                 5)
	TAGKEYS(                        XK_7,      					                 6)
	TAGKEYS(                        XK_8,      					                 7)
	TAGKEYS(                        XK_9,      					                 8)
	{ MODKEY|ShiftMask,             XK_q,      					 spawn,          {.v = quitcmd } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        cyclelayout,    {.i = +1 } },
	{ ClkLtSymbol,          0,              Button3,        cyclelayout,    {.i = -1 } },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
