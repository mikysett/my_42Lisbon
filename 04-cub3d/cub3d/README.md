# 42Lisbon - Cub3D

* m: toggle minimap
* f: toggle fps count

* Render distance related shadows
* Skybox feature
* Delta time used to normalize mouvement speed
* Lifebar with healing/damaging items and traps
* Map extras: 3: Healing object, 4: Trap

## To compile on linux/mac
* You should install first MinilibX on your machine
* In ft_constants.h toggle IS_OS_MAC accordingly
* In Makefile take the LIBS definition accordingly

### Linux Notes
* On linux alpha-byte for pixels doesn't seems to work
In order to have a proper render on linux you should write every layer on the scene layer and sacrifice the shadow effect (background will be black especially because of obj layer, which is used for sprites and normally is transparent everywhere exept on opaque sprites segments).

### Resources
Special thanks to @dda-silv. You can find his repo with useful resources here:
[dda-silv cub3D repo](https://github.com/DimitriDaSilva/42_cub3d)