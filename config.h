/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 6;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
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

static const char *colors[][3]      = {
	/*					fg         bg          border   */
	[SchemeNorm]			= { normfgcolor, normbgcolor, normbordercolor },
  [SchemeSel]				= { selfgcolor,  selbgcolor,  selbordercolor  },

	// Color scheme 1
	//[SchemeCol1]=		 { col_black, "#faa275",	normbordercolor },
	//[SchemeCol2]=		 { col_black, "#ff8c61",  normbordercolor },
	//[SchemeCol3]=		 { col_black, "#ce6a85",  normbordercolor },
	//[SchemeCol4]=		 { col_white, "#985277",  normbordercolor },
	//[SchemeCol5]=		 { col_white, "#5c374c",  normbordercolor },
	//[SchemeCol6]=		 { col_white, "#5c373c",  normbordercolor },
	
	// Color scheme 2
	//[SchemeCol1]=		 { col_black, "#fe938c",	normbordercolor },
	//[SchemeCol2]=		 { col_black, "#e6b89c",  normbordercolor },
	//[SchemeCol3]=		 { col_black, "#ead2ac",  normbordercolor },
	//[SchemeCol4]=		 { col_black, "#9cafb7",  normbordercolor },
	//[SchemeCol5]=		 { col_white, "#4281a4",  normbordercolor },
	//[SchemeCol6]=		 { col_white, "#4263a4",  normbordercolor },

	// Color scheme 3
	[SchemeCol1]=		 { col_black, "#c9cba3",	normbordercolor },
	[SchemeCol2]=		 { col_black, "#ffe1a8",  normbordercolor },
	[SchemeCol3]=		 { col_black, "#e26d5c",  normbordercolor },
	[SchemeCol4]=		 { col_white, "#723d46",  normbordercolor },
	[SchemeCol5]=		 { col_white, "#472d30",  normbordercolor },
	[SchemeCol6]=		 { col_white, "#723d46",  normbordercolor },

	[SchemeStatus]		= { normfgcolor, normbgcolor, normbordercolor },
	[SchemeTagsSel]		= { selfgcolor,	 selbgcolor,  selbordercolor	 },
	[SchemeTagsNorm]	= { normfgcolor, normbgcolor, normbordercolor  },
  [SchemeInfoSel]		= { selfgcolor,	 selbgcolor,  selbordercolor },
  [SchemeInfoNorm]  = { normfgcolor, normbgcolor, normbordercolor },
};

static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },

	[SchemeCol1]=	{ OPAQUE, OPAQUE, OPAQUE },
	[SchemeCol2]=	{ OPAQUE, OPAQUE, OPAQUE },
	[SchemeCol3]=	{ OPAQUE, OPAQUE, OPAQUE },
	[SchemeCol4]=	{ OPAQUE, OPAQUE, OPAQUE },
	[SchemeCol5]=	{ OPAQUE, OPAQUE, OPAQUE },
	[SchemeCol6]=	{ OPAQUE, OPAQUE, OPAQUE },

	[SchemeStatus]		= { OPAQUE, OPAQUE,	OPAQUE }, 
	[SchemeTagsSel]		= { OPAQUE, OPAQUE,	OPAQUE  },
	[SchemeTagsNorm]	= { OPAQUE, OPAQUE, OPAQUE  },
  [SchemeInfoSel]		= { OPAQUE, OPAQUE,		OPAQUE},
  [SchemeInfoNorm]  = { OPAQUE, OPAQUE,		OPAQUE },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     iscentered		isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            0,						1,           -1 },
	{ "firefox",  NULL,       NULL,       0,						1,						1,           -1 },
	{ "Telegram", NULL,       NULL,       0,						1,						1,           -1 },
	{ "St",				"float",		NULL,				0,            1,						1,           -1 },
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
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", col_black, NULL };
static const char *termcmd[]  = { "termite", NULL };
static const char *lockcmd[]  = { "lock_screen", NULL };
static const char *emailcmd[]  = { "st", "-n", "float", "-g", "140x50", "-e", "neomutt", NULL };
static const char *newscmd[]  = { "st", "-n", "float", "-g", "140x50", "-e", "newsboat", NULL };
static const char *musiccmd[]  = { "st", "-n", "float", "-g", "120x40", "-e", "ncmpcpp", NULL };
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
static const char *emojicmd[]  = { "dmenuunicode", NULL };
static const char *mountcmd[]  = { "dmenu_mount", NULL };
static const char *unmountcmd[]  = { "dmenu_unmount", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "termite", "-t", scratchpadname, NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	/* ------------------------------ apps ---------------------------------- */
	{ MODKEY,                       XK_space,						 spawn,          {.v = dmenucmd } },
	{ MODKEY,												XK_Return, 					 spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_minus,  					 togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,												XK_e,			 					 spawn,          {.v = emailcmd } },
	{ MODKEY,												XK_n,			 					 spawn,          {.v = newscmd } },
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
	{ MODKEY,												XK_z,			 					 spawn,          {.v = lockcmd } },
	{ MODKEY,												XK_y,			 					 spawn,          {.v = screenshotcmd } },
	{ MODKEY|ShiftMask,							XK_y,			 					 spawn,          {.v = screenshotcropcmd } },
	{ MODKEY,												XK_grave,	 					 spawn,					 {.v = emojicmd } },
	{ MODKEY|ShiftMask,							XK_r,			 					 quit,           {0} },
	{ MODKEY,												XK_F1,		 					 spawn,          {.v = mountcmd } },
	{ MODKEY,												XK_F2,		 					 spawn,          {.v = unmountcmd } },
	{ MODKEY,                       XK_b,      					 togglebar,      {0} },
	{ MODKEY,                       XK_j,      					 focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      					 focusstack,     {.i = -1 } },
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
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
