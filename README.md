# DWM

My personal version of dwm. In the `patches` folder there are all the patches that I applied, while in the `scripts` folder there are some useful scripts.

## Patches

## Scripts

- `dwm-status-bar`: a script to show a colored status bar on dwm. You can put the following code in your `.xprofile` file.

```
while xsetroot -name "`dwm-status-bar`"
do
	sleep 1
done &
```

- `toggle_telegram`: a script that initializes telegram if it is not running and then toggles it to show/hide using `xdo` and `xdotool` tools.
