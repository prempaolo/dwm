# DWM

My personal version of dwm. In the `patches` folder there are all the patches that I applied, while in the `scripts` folder there are some useful scripts.

## Patches

- *mycenter*: when a new floating window appears it will be moved to the center of the screen
- *cyclelayouts*: adds a function to cycle through all available layouts (`win + ctrl + comma` and `win + ctrl + period` in my config)
- *myfullscreen*: adds the possibility to open a window in true fullscreen (`win + f` in my config)
- *mystatuscolor*: adds colors to the status bar
- *pertag*: adds the possibility to have different layouts per tag
- *scratchpad*: adds a scratchpad terminal (`win + minus` in my config)
- *uselessgap*: adds useless gaps
- *statuscmd*: clickable dwmblocks bar

## Scripts

**Deprecated**
`dwm-status-bar`: a script to show a colored status bar on dwm. You can put the following code in your `.xprofile` file:

```
while xsetroot -name "`dwm-status-bar`"
do
	sleep 1
done &
```

**Note:** instead of `dwm-status-bar` use my version of dwmblocks.

`toggle_telegram`: a script that initializes telegram if it is not running and then toggles it to show/hide using `xdo` and `xdotool` tools.
