set(srcs "src/Engine.c" "src/Resource.c" "src/Render.c")
set(requires st7789 fontx pngle decode_png)

idf_component_register(SRCS "${srcs}"
                    INCLUDE_DIRS "include"
                    REQUIRES "${requires}")   