/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const unsigned int gappx     = 10;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 46;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */

static const int vertpad            = 10;       /* vertical padding of bar */
static const int sidepad            = 10;       /* horizontal padding of bar */

static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */

static const char *fonts[]          = { "UbuntuMonoNerdFont-Regular:size=13", "Unifont:size=13", "JetBrainsMono-Regular:style=Light:size=11", "monospace:size=11", "Symbola:size=11" };
static const char dmenufont[]       = "UbuntuMonoNerdFont-Regular:size=15";
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

static const char * const col_main = col_spaceblue;

// Hikers palette https://coolors.co/ffbe0b-fb5607-ff006e-8338ec-3a86ff

#define DARK_TURQUOISE "#0D2E35"
#define VERY_DARK_TURQUOISE "#15242B"
#define LIGHT_GREEN "#56986E"
#define DARK_GREEN "#1D4E43"

static const char *colors[][3]      = {
	//               fg         bg         border   
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_main,  col_main  },
	
	[SchemeStatus]    = { col_gray3, VERY_DARK_TURQUOISE,        VERY_DARK_TURQUOISE  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]   = { col_gray4, LIGHT_GREEN,                VERY_DARK_TURQUOISE  }, // Tagbar left selected {text,background,not used but cannot be empty}
    [SchemeTagsNorm]  = { col_gray3, VERY_DARK_TURQUOISE,        VERY_DARK_TURQUOISE  }, // Tagbar left unselected {text,background,not used but cannot be empty}
    [SchemeInfoSel]   = { col_gray4, DARK_TURQUOISE,             VERY_DARK_TURQUOISE  }, // infobar middle  selected {text,background,not used but cannot be empty}
    [SchemeInfoNorm]  = { col_gray3, VERY_DARK_TURQUOISE,        VERY_DARK_TURQUOISE  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};

/*
static const char *colors[][3]      = {
	//               fg         bg         border   
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	//	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
	[SchemeSel]  = { col_gray4, col_main,  col_main  },
	
	[SchemeStatus]    = { col_gray3, col_ocrered,      col_gray2  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]   = { col_gray4, col_bloodred,     col_gray2  }, // Tagbar left selected {text,background,not used but cannot be empty}
    [SchemeTagsNorm]  = { col_gray3, col_gray1,        col_gray2  }, // Tagbar left unselected {text,background,not used but cannot be empty}
    [SchemeInfoSel]   = { col_gray4, col_main,         col_gray2  }, // infobar middle  selected {text,background,not used but cannot be empty}
    [SchemeInfoNorm]  = { col_gray3, col_gray1,        col_gray2  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};
*/

/* tagging */
static const char *tags[] = { "⛺", "⚙", "📖", "🎧", "🎮", "💬", "📂", "💻", "🌐" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	// swallow: -1 -> swallow, 0 -> ?, 1 -> never(maybe?)
	/* class                          instance    title                          tags mask     isfloating   monitor */
	{ "Emacs",				          NULL,       NULL,                          1 << 7,       0,           -1 },
	{ "Firefox",			          NULL,       NULL,                          1 << 8,       0,           -1 },
	{ "Brave",				          NULL,       NULL,                          1 << 8,       0,           -1 },
	{ "jetbrains-idea",		          NULL,       NULL,                          1 << 7,       0,           -1 },
	{ "jetbrains-clion",	          NULL,       NULL,                          1 << 7,       0,           -1 },
	{ "Thunderbird",	              NULL,       NULL,                          1 << 5,       0,           -1 },
	{ "discord",     	              NULL,       NULL,                          1 << 5,       0,           -1 },
	{ "com.cisco.anyconnect.gui",     NULL,       NULL,                          0,            1,           -1 },
	{ NULL,                           NULL,       "Steam - News",                1 << 4,       1,           -1 },
	{ NULL,                           NULL,       "Steam",                       1 << 4,       0,           -1 },
	{ NULL,                           NULL,       "Rockstar Games Launcher",     1 << 4,       1,           -1 },
	{ NULL,                           NULL,       "Futter",                      0,            1,           -1 },
	{ NULL,                           NULL,       "Event Tester",                0,            0,           -1 },
	{ "org.pwmt.zathura",             NULL,       NULL,                          0,            0,           -1 },
	{ "st",                           NULL,       NULL,                          0,            0,           -1 },
	{ "Deadbeef",               "deadbeef",       NULL,                          1 << 3,       1,           -1 },
	{ "Pcmanfm",                 "pcmanfm",       NULL,                          0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.60; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static int attachbelow = 1;    /* 1 means attach after the currently active window */

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
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_main, "-sf", col_gray4, "-l", "20", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };


// Custom apps/commands/hotkeys
static const char  *firefoxcmd[] = { "/usr/bin/firefox",  NULL };
static const char  *bravecmd[] = { "/usr/bin/brave",  NULL };

static const char  *emacscmd[] = { "/usr/bin/emacs",  NULL };
static const char  *pcmanfmcmd[] = { "/usr/bin/pcmanfm",  NULL };
static const char  *screenshotcmd[] = { "/usr/bin/flameshot",  "gui", NULL };

static const char  *slockcmd[] = { "/usr/local/bin/slock",  NULL };
static const char  *systemcmd[] = { "/home/lorenzo/bin/system-control",  NULL };
static const char  *suspendcmd[] = {"systemctl", "suspend", NULL };
static const char  *shutdowncmd[] = { "/home/lorenzo/bin/shutdown-now",  NULL };
//static const char  *gamescmd[] = {"game-launcher.sh", NULL};
//static const char  *docscmd[] = {"open_doc.sh", NULL};
static const char  *nmtuicmd[] = {"st", "-e", "nmtui", NULL};

static const char  *volumelevelcmd[] = { "python3",  "/home/lori/scripts/volume_level.py", NULL };
static const char  *volumeup[] = { "amixer",  "set", "Master", "5%+", NULL };
static const char  *volumedown[] = { "amixer",  "set", "Master", "5%-", NULL };
static const char  *volumetoggle[] = { "amixer",  "-D", "pulse", "set", "Master", "toggle", NULL };

//static const char  *spotifyplaypause[] = { "dbus-send", "--print-reply", "--dest=org.mpris.MediaPlayer2.spotify", "/org/mpris/MediaPlayer2", "org.mpris.MediaPlayer2.Player.PlayPause", NULL };
static const char  *spotifyctlcmd[] = { "/home/lorenzo/bin/spotify-control.sh", NULL };

//static const char  *brightup[] = { "xbacklight",  "-inc", "5",  NULL };
//static const char  *brightdown[] = { "xbacklight",  "-dec", "5",  NULL };
//static const char  *brightmax[] = { "xbacklight",  "-set", "100",  NULL };

static const char  *wifistrengthcmd[] = { "python3",  "/home/lorenzo/bin/wifi_strength.py", NULL};

void suspend(const Arg *nullarg) {
	Arg slock = {.v = slockcmd};
	Arg suspend = {.v = suspendcmd};

	spawn(&slock);
	system("sleep 10");
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

#define WEB_TAG (1 << 8)

void open_web(const Arg *cmdarg) {
	Arg tagarg = { .ui = WEB_TAG };
	spawn(cmdarg);
	switch_to_tag(&tagarg);
}

int full_quit_flag = 0;
void quit_fully(const Arg *a) {
	(void) a;
	full_quit_flag = 1;
	quit(NULL);
}

void killclientpid(const Arg *a) {
	(void) system("kill -9 `xdotool getwindowfocus getwindowpid`");
}

static Key keys[] = {
	/* modifier                     key                             function        argument */
	{ MODKEY,                       XK_p,                           spawn,          {.v = dmenucmd } }, // Run the dmenu launcher
 	{ MODKEY|ShiftMask,             XK_Return,                      spawn,          {.v = termcmd } }, // Run st
	{ MODKEY,                       XK_dead_circumflex,             togglescratch,  {.v = scratchpadcmd } }, // Toggle scratchpad
	{ MODKEY,                       XK_b,                           togglebar,      {0} }, // Toggle bar
	{ MODKEY,                       XK_j,                           focusstack,     {.i = -1 } }, // Move up the stack
	{ MODKEY,                       XK_k,                           focusstack,     {.i = +1 } }, // Move down the stack
	{ MODKEY,                       XK_i,                           incnmaster,     {.i = +1 } }, // Increase master positions
	{ MODKEY,                       XK_d,                           incnmaster,     {.i = -1 } }, // Decrease master positions
                     
	{ MODKEY,                       XK_h,                           setmfact,       {.f = -0.05} }, // Move master-stack barrier to the left
	{ MODKEY,                       XK_l,                           setmfact,       {.f = +0.05} }, // Move master-stack barrier to the right
	{ MODKEY|ShiftMask,             XK_i,                           setcfact,       {.f = +0.25} }, // Increase height of window in the stack
	{ MODKEY|ShiftMask,             XK_d,                           setcfact,       {.f = -0.25} }, // Decrease height of window in the stack
	{ MODKEY|ShiftMask,             XK_r,                           setcfact,       {.f =  0.00} }, // Reset height of window in the stack
                     
	{ MODKEY,                       XK_Return,                      zoom,               {0} }, // Toggle to/from the master window
	{ MODKEY,                       XK_Tab,                         view,               {0} }, // Switch to previous tag
	{ MODKEY,                       XK_z,                           toggleAttachBelow,  {0} }, // Toggle attachbelow behaviour
                     
	{ MODKEY,                       XK_x,                           killclient,     {0} }, // Kill window
	{ MODKEY|ShiftMask,             XK_x,                           killclientpid,  {0} }, // Kill window
	{ MODKEY,                       XK_t,                           setlayout,      {.v = &layouts[0]} }, // Switch to tiling layout
    { MODKEY,                       XK_f,                           setlayout,      {.v = &layouts[1]} }, // Switch to floating layout
	{ MODKEY,                       XK_m,                           setlayout,      {.v = &layouts[2]} }, // Switch to monocle layout
	{ MODKEY,                       XK_c,                           setlayout,      {.v = &layouts[3]} }, // Switch to centered master layout
	{ MODKEY|ShiftMask,             XK_c,                           setlayout,      {.v = &layouts[4]} }, // Switch to centered floating master layout

	{ MODKEY|ShiftMask,             XK_f,                           togglefloating, {0} }, // Toggle floating behaviour for the focused window
	{ MODKEY,                       XK_space,                       togglefullscr,  {0} }, // Toggle fullscreen for the focused window
	{ MODKEY,                       XK_0,                           view,           {.ui = ~0 } }, // Show all tags
	{ MODKEY|ShiftMask,             XK_0,                           tag,            {.ui = ~0 } }, // Share  window with all tags
	//	{ MODKEY,                       XK_comma,                       focusmon,       {.i = -1 } },
	//	{ MODKEY,                       XK_period,                      focusmon,       {.i = +1 } },
	//	{ MODKEY|ShiftMask,             XK_comma,                       tagmon,         {.i = -1 } },
	//	{ MODKEY|ShiftMask,             XK_period,                      tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_numbersign,                  setgaps,        {.i = +1 } }, // Increase gap size by 1px
	{ MODKEY|ShiftMask,             XK_numbersign,                  setgaps,        {.i = -1  } }, // Decrease gap size by 1px
	
	TAGKEYS(                        XK_1,                           0) // Switch to tag 0
	TAGKEYS(                        XK_2,                           1) // Switch to tag 1
	TAGKEYS(                        XK_3,                           2) // Switch to tag 2
	TAGKEYS(                        XK_4,                           3) // Switch to tag 3
	TAGKEYS(                        XK_5,                           4) // Switch to tag 4
	TAGKEYS(                        XK_6,                           5) // Switch to tag 5
	TAGKEYS(                        XK_7,                           6) // Switch to tag 6
	TAGKEYS(                        XK_8,                           7) // Switch to tag 7
	TAGKEYS(                        XK_9,                           8) // Switch to tag 8
	{ MODKEY,                       XK_Escape,                      quit_fully,     {0} }, // Quit DWM
	{ MODKEY|ShiftMask,             XK_Escape,                      quit,           {0} }, // Restart DWM
	{ MODKEY,                       XK_q,                           spawn,          {.v = systemcmd} }, // Show system power options

	// Apps
	{ MODKEY|ShiftMask,             XK_w,                           open_web,            {.v = firefoxcmd} }, // Run firefox and switch to the web tag
	{ MODKEY,                       XK_w,                           open_web,            {.v = bravecmd} }, // Run brave and switch to the web tag
	{ MODKEY,                       XK_e,                           open_emacs,          {.ui = 1 << 7} }, // Run emacs and switch to the dev tag
	{ MODKEY,                       XK_o,                           spawn,               {.v = pcmanfmcmd} }, // Open the file manager
	{ MODKEY|ShiftMask,             XK_o,                           spawn,               {.v = screenshotcmd} }, // Run the screenshot utility
	{ MODKEY,                       XK_y,                           spawn,               {.v = nmtuicmd} }, // Open the network/wifi manager
                          
	{ MODKEY,                       XK_v,                           spawn,               {.v = volumelevelcmd} }, // Show current audio volume level
	{ MODKEY|ShiftMask,             XK_v,                           spawn,               {.v = wifistrengthcmd} }, // Show current network connection
                          
	{ MODKEY,                       XK_F1,                          suspend,             {.v = NULL} }, // Suspend
	{ MODKEY|ShiftMask,             XK_F1,                          spawn,               {.v = shutdowncmd} }, // Shutdown
	                          
	{ MODKEY,                       XK_Prior,                       spawn,               {.v = volumeup} }, // Increase audio volume level
	{ MODKEY,                       XK_Next,                        spawn,               {.v = volumedown} }, // Decrease audio volume level
	{ MODKEY,                       XK_Pause,                       spawn,               {.v = volumetoggle} }, // Toggle audio mute
	{ MODKEY|ShiftMask,             XK_Pause,                       spawn,               {.v = spotifyctlcmd} }, // Control spotify playback
          
	{ MODKEY,                       XK_Up,                          focusstack,          {.i = -1 } }, // Move up the stack
	{ MODKEY,                       XK_Down,                        focusstack,          {.i = +1 } }, // Move down the stack
	{ MODKEY,                       XK_Left,                        setmfact,            {.f = -0.05} }, // Move master-stack barrier to the left
	{ MODKEY,                       XK_Right,                       setmfact,            {.f = +0.05} }, // Move master-stack barrier to the right
}; // end kbds

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

