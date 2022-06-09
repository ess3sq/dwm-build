/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const unsigned int gappx     = 10;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 48;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */

static const int vertpad            = 10;       /* vertical padding of bar */
static const int sidepad            = 10;       /* horizontal padding of bar */

static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */

static const char *fonts[]          = { "SF Mono:style=Light:size=14", "monospace:size=14", "Symbola:size=14" };
static const char dmenufont[]       = "monospace:size=14";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";

// Custom colors: https://www.color-hex.com/color/00539b
static const char col_oceanblue[]     = "#00539b";
static const char col_draculapurple[] = "#6272A4";
static const char col_charcoal[]      = "#2E4052";
static const char col_phtalogreen[]   = "#264027";
static const char col_oxfordblue[]    = "#0B2545";
static const char col_bloodred[]      = "#5A1807";
static const char col_ocrered[]       = "#55251D";
static const char col_spaceblue[]     = "#283044";
static const char * const col_main = col_oxfordblue;

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	//	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
	[SchemeSel]  = { col_gray4, col_main,  col_main  },
};

/* tagging */
static const char *tags[] = { "⛺", "2", "3", "🎧", "🎮", "💬", "📂", "💻", "🌐" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                  instance    title               tags mask     isfloating   monitor */
	{ "Emacs",				  NULL,       NULL,               1 << 7,       0,           -1 },
	{ "Firefox",			  NULL,       NULL,               1 << 8,       0,           -1 },
	{ "Brave",				  NULL,       NULL,               1 << 8,       0,           -1 },
	{ "jetbrains-idea",		  NULL,       NULL,               1 << 7,       0,           -1 },
	{ "jetbrains-clion",	  NULL,       NULL,               1 << 7,       0,           -1 },
	{ "Thunderbird",	      NULL,       NULL,               1 << 5,       0,           -1 },
	{ "discord",     	      NULL,       NULL,               1 << 5,       0,           -1 },
	{ NULL,          	      NULL,       "Spotify",          1 << 5,       0,           -1 },
	{ "org.remmina.Remmina",  NULL,       "Remmina Remote",   0,            0,           -1 }, // remote machine selection
	//	{ "org.remmina.Remmina",  NULL,       "Remmina",          1 << 1,       0,           -1 }, // remote machine window
	{ "org.remmina.Remmina",  NULL,       "newraider",        1 << 1,       0,           -1 }, // newraider window
};

/* layout(s) */
static const float mfact     = 0.60; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
};

/* key definitions */
// Mod1Mask is Alt
// Mod4Mask is Super/Winkey
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
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_main, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };
// static const char *termcmd[]  = { "gnome-terminal", NULL };
static const char *configscmd[] = {"config-edit.sh", NULL};

// Custom apps/commands/hotkeys
// static const char  *firefoxcmd[] = { "/usr/bin/firefox",  NULL };
static const char  *bravecmd[] = { "/usr/bin/brave-browser",  NULL };
//static const char  *surfcmd[] = { "/home/lorenzo/bin/surf-open.sh",  NULL };
static const char  *surfcmd[] = { "surf",  NULL };
static const char  *surfhistcmd[] = { "/home/lorenzo/bin/open-web-history",  NULL };
static const char  *surfbookcmd[] = { "/home/lorenzo/bin/open-web",  NULL };

static const char  *emacscmd[] = { "/usr/bin/emacs",  NULL };
static const char  *nautiluscmd[] = { "/usr/bin/nautilus",  NULL };
static const char  *screenshotcmd[] = { "/usr/bin/gnome-screenshot",  "-i", NULL };
static const char  *thunderbirdcmd[] = { "/usr/bin/thunderbird", NULL };

static const char  *slockcmd[] = { "/usr/local/bin/slock",  NULL };
static const char  *systemcmd[] = { "/home/lorenzo/bin/system-control",  NULL };
static const char  *suspendcmd[] = {"systemctl", "suspend", NULL };
static const char  *shutdowncmd[] = { "/home/lorenzo/bin/shutdown-now",  NULL };
static const char  *gamescmd[] = {"game-launcher.sh", NULL};
static const char  *docscmd[] = {"open_doc.sh", NULL};
static const char  *nmtuicmd[] = {"st", "-e", "nmtui", NULL};

static const char  *volumelevelcmd[] = { "python3",  "/home/lorenzo/bin/volume_level.py", NULL };
static const char  *volumeup[] = { "amixer",  "set", "Master", "3+", NULL };
static const char  *volumedown[] = { "amixer",  "set", "Master", "3-", NULL };
static const char  *volumetoggle[] = { "amixer",  "-D", "pulse", "set", "Master", "toggle", NULL };

static const char  *brightup[] = { "xbacklight",  "-inc", "5",  NULL };
static const char  *brightdown[] = { "xbacklight",  "-dec", "5",  NULL };
static const char  *brightmax[] = { "xbacklight",  "-set", "100",  NULL };

static const char  *wifistrengthcmd[] = { "python3",  "/home/lorenzo/bin/wifi_strength.py", NULL};

void suspend(const Arg *nullarg) {
	Arg slock = {.v = slockcmd};
	Arg suspend = {.v = suspendcmd};
	spawn(&slock);
	spawn(&suspend);
}

void switch_to_tag(const Arg *arg) {
	// {.ui = 1 << TAG}
	view(arg);
	toggleview(arg);
	tag(arg);
	toggletag(arg);
}

void open_emacs(const Arg *arg) {
	Arg emacsarg = {.v = emacscmd};
	spawn(&emacsarg);
	switch_to_tag(arg);
}

void open_web(const Arg *arg) {
	Arg bravearg = {.v = bravecmd};
	spawn(&bravearg);
	switch_to_tag(arg);
}

static Key keys[] = {
	/* modifier                     key             function        argument */
	{ MODKEY,                       XK_p,           spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_p,           spawn,          {.v = configscmd } },
 	{ MODKEY|ShiftMask,             XK_Return,      spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,           togglebar,      {0} },
	{ MODKEY,                       XK_j,           focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_k,           focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_i,           incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,           incnmaster,     {.i = -1 } },
     
	{ MODKEY,                       XK_h,           setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,           setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_i,           setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_d,           setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_r,           setcfact,       {.f =  0.00} },
     
	{ MODKEY,                       XK_Return,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,         view,           {0} },
     
	{ MODKEY,                       XK_x,           killclient,     {0} },
	{ MODKEY,                       XK_t,           setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,           setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,           setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_c,           setlayout,      {.v = &layouts[3]} }, // centeredmaster
	{ MODKEY|ShiftMask,             XK_c,           setlayout,      {.v = &layouts[4]} }, // centeredfloatingmaster
	{ MODKEY,                       XK_space,       setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,       togglefloating, {0} },
	{ MODKEY,                       XK_0,           view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,           tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,       focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,      focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,       tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,      tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_numbersign,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_numbersign,  setgaps,        {.i = 0  } },
	
	TAGKEYS(                        XK_1,                           0)
	TAGKEYS(                        XK_2,                           1)
	TAGKEYS(                        XK_3,                           2)
	TAGKEYS(                        XK_4,                           3)
	TAGKEYS(                        XK_5,                           4)
	TAGKEYS(                        XK_6,                           5)
	TAGKEYS(                        XK_7,                           6)
	TAGKEYS(                        XK_8,                           7)
	TAGKEYS(                        XK_9,                           8)
	{ MODKEY,                       XK_q,      spawn,               {.v = systemcmd} },
	{ MODKEY|ShiftMask,             XK_q,      quit,                {0} },

	// Apps
	//	{ MODKEY,                       XK_w,      spawn,          {.v = firefoxcmd} },
	{ MODKEY,                       XK_w,      open_web,            {.ui = 1 << 8} },
	{ MODKEY|ShiftMask,             XK_w,      spawn,               {.v = surfcmd} },
	{ MODKEY,                       XK_s,      spawn,               {.v = surfbookcmd} },
	{ MODKEY|ShiftMask,             XK_s,      spawn,               {.v = surfhistcmd} },
	{ MODKEY,                       XK_e,      open_emacs,          {.ui = 1 << 7} },
	{ MODKEY,                       XK_o,      spawn,               {.v = nautiluscmd} },
	{ MODKEY|ShiftMask,             XK_o,      spawn,               {.v = screenshotcmd} },
	{ MODKEY|ShiftMask,             XK_e,      spawn,               {.v = thunderbirdcmd} },
	{ MODKEY,                       XK_y,      spawn,               {.v = nmtuicmd} },
     
	{ MODKEY,                       XK_v,      spawn,               {.v = volumelevelcmd} },
	{ MODKEY|ShiftMask,             XK_v,      spawn,               {.v = wifistrengthcmd} },
     
	{ MODKEY,                       XK_F1,     suspend,             {.v = NULL} },
	{ MODKEY|ShiftMask,             XK_F1,     spawn,               {.v = shutdowncmd} },
	{ MODKEY,                       XK_g,      spawn,               {.v = gamescmd} },
	{ MODKEY|ShiftMask,             XK_g,      spawn,               {.v = docscmd} },
	     
	{ MODKEY,                       XK_F12,    spawn,               {.v = volumeup} },
	{ MODKEY,                       XK_F11,    spawn,               {.v = volumedown} },
	{ MODKEY,                       XK_F10,    spawn,               {.v = volumetoggle} },
     
	{ MODKEY,                       XK_F6,     spawn,               {.v = brightup} },
	{ MODKEY,                       XK_F5,     spawn,               {.v = brightdown} },
	{ MODKEY,                       XK_F7,     spawn,               {.v = brightmax} },
     
	{ MODKEY,                       XK_Up,     focusstack,          {.i = -1 } },
	{ MODKEY,                       XK_Down,   focusstack,          {.i = +1 } },
	{ MODKEY,                       XK_Left,   setmfact,            {.f = -0.05} },
	{ MODKEY,                       XK_Right,  setmfact,            {.f = +0.05} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
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

