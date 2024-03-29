/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 12;
static const unsigned int snap      = 0;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
/* static const int user_bh            = 0; */      /* 0 means dwm will calculate bar size */
/* static const int vertpad            = 12; */
/* static const int sidepad            = 12; */
static const char *fonts[]          = { "monospace:size=13", "Hack Nerd Font Mono:size=13" };
static const char dmenufont[]       = "monospace:size=10";

static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";

static const char col_cyan[]        = "#344e5b";
static const char col_green[]       = "#6ac769";
static const char col_yellow[]      = "#e5c63f";
static const char col_white[]       = "#f8ecaa";
static const char col_red[]         = "#e3433f";

static const char col_rp_bg[]         = "#232136";
static const char col_rp_fg[]         = "#e0def4";
static const char col_rp_hl[]         = "#c4a7e7";

/*static const char col_retro_fg[]        = "
static const char col_retro_bg[]        = "
static const char col_retro_hl[]        = " */

/*static const char *colors[][3]      = {*/
	/*               fg         bg         border   */
/*	[SchemeNorm] = { col_rp_fg, col_rp_bg, col_rp_bg },
	[SchemeSel]  = { col_rp_bg, col_rp_hl,  col_rp_hl},
};*/

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_rp_fg, col_rp_bg, col_rp_bg },
	[SchemeSel]  = { col_rp_bg, col_rp_hl,  col_rp_hl},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
/* static const char *tags[] = { "α", "β", "γ", "δ", "ε", "ζ", "η", "θ", "ι" }; */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "CoreShot",     NULL,       NULL,       0,            1,           -1 },
	{ "Media Viewer",     NULL,       NULL,       0,            1,           -1 },
/*    { "processing-app-Base", NULL, NULL, 0, 1, -1 }, */
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ ">M>",      centeredfloatingmaster },
	{ "|M|",      centeredmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
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
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *tabtermcmd[]  = { "tabbed", "-c", "alacritty", "--embed", NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *othertermcmd[]  = { "st", NULL };
static const char *emacscmd[] = { "emacs", NULL };
static const char *firefoxcmd[] = { "firefox", NULL };

#include <X11/XF86keysym.h>

static const char *volumeupcmd[] = { "pulsemixer", "--change-volume", "+5", NULL };
static const char *volumedowncmd[] = { "pulsemixer", "--change-volume", "-5", NULL };

static const char *brightnessupcmd[] = { "brightnessctl", "set", "+10%", NULL };
static const char *brightnessdowncmd[] = { "brightnessctl", "set", "10-%", NULL };

static const char *searchcmd[] = { "/home/./yyvan/.config/dwm/search.sh", NULL };
static const char *powermenucmd[] = { "/home/./yyvan/.config/dwm/powermenu.sh", NULL };
static const char *runwithoutputcmd[] = { "/home/./yyvan/.config/dwm/run_with_output.sh", NULL };
/* static const char *searchcmd[] = { "surf", "$(dmenu", "-p", "'Website'", "<", "/dev/null)", NULL }; */

static const Key keys[] = {
	/* modifier                     key        function        argument */
    { MODKEY,                       XK_h,      spawn,          {.v = firefoxcmd } },  
    { MODKEY,                       XK_g,      spawn,          {.v = emacscmd } },  
	{ MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = tabtermcmd } },
	{ MODKEY|ControlMask,           XK_Return, spawn,          {.v = othertermcmd } },
	/* change the volume */
	{ 0,                            XF86XK_AudioLowerVolume, spawn, {.v = volumedowncmd } },
	{ 0,                            XF86XK_AudioRaiseVolume, spawn, {.v = volumeupcmd } },
    /* change the brightness */
    { 0,                            XF86XK_MonBrightnessUp, spawn, {.v = brightnessupcmd } },
    { 0,                            XF86XK_MonBrightnessDown, spawn, {.v = brightnessdowncmd } },
    /* search on the web */
    { MODKEY|ShiftMask,             XK_space,               spawn, {.v = searchcmd } },
    /* open the powermenu */
    { MODKEY|ShiftMask,             XK_p,                   spawn, {.v = powermenucmd } },
    /* open the run menu which gives an output into a notification */
    { MODKEY|ShiftMask,             XK_o,                   spawn, {.v = runwithoutputcmd } },
	/* toggle the bar */
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	/* focus between the windows */
	{ MODKEY,                       XK_l,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	/* increment/decrement number of master clients */
	{ MODKEY,                       XK_s,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	/* increment/decrement the size of the master client */
	{ MODKEY,                       XK_j,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_semicolon, setmfact,       {.f = +0.05} },
	/* zoom on a window */
	{ MODKEY,                       XK_f,      zoom,           {0} },
	/* i have no idea what this does */
	{ MODKEY,                       XK_Tab,    view,           {0} },
	/* kill the focused client */
	{ MODKEY,                       XK_q,      killclient,     {0} },
	/* change to tiling layout */
	{ MODKEY,                       XK_e,      setlayout,      {.v = &layouts[0]} },
	/* change to centeredmaster layout */
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[1]} },
	/* change to centeredfloatingmaster layout */
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[2]} },
    /* change to floating layout */
	{ MODKEY,                       XK_y,      setlayout,      {.v = &layouts[3]} },
    /* change to monocle layout */
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[4]} },
	/* toggle client back to tiling mode */
	{ MODKEY,                       XK_v,  setlayout,      {0} },
	/* toggle the client to floating mode */
	{ MODKEY,                       XK_w,  togglefloating, {0} },

    { MODKEY|ShiftMask,             XK_f,  togglefullscr,  {0} },

	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	/* focus the monitor to the left */
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	/* focus the monitor to the right */
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	/* move the client to the monitor to the left */
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	/* move the client to the monitor to the right */
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	/* move clients to workspaces/switch to different workspaces */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
    /* restart the wm */
	{ MODKEY|ControlMask|ShiftMask,             XK_q,      quit,           {0} },
	/* quit the wm */
	{ MODKEY|ControlMask|ShiftMask,             XK_r,      quit,           {1} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
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
