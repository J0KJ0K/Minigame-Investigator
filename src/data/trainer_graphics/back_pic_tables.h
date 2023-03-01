const struct MonCoords gTrainerBackPicCoords[] =
{
    [TRAINER_BACK_PIC_SCOTT] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_YEVA] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_RED] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_LEAF] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_WALLY] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_STEVEN] = {.size = 8, .y_offset = 4},
};

// this table goes functionally unused, since none of these pics are compressed
// and the place they would get extracted to gets overwritten later anyway
// the casts are so they'll play nice with the strict struct definition
#define TRAINER_BACK_SPRITE(trainerPic, sprite, size) [TRAINER_BACK_PIC_##trainerPic] = {(const u32 *)sprite, size, TRAINER_BACK_PIC_##trainerPic}

const struct CompressedSpriteSheet gTrainerBackPicTable[] =
{
    TRAINER_BACK_SPRITE(SCOTT, gTrainerBackPic_Brendan, 0x2000),
    TRAINER_BACK_SPRITE(YEVA, gTrainerBackPic_May, 0x2000),

    TRAINER_BACK_SPRITE(RED, gTrainerBackPic_Red, 0x2800),
    TRAINER_BACK_SPRITE(LEAF, gTrainerBackPic_Leaf, 0x2800),
    TRAINER_BACK_SPRITE(RUBY_SAPPHIRE_BRENDAN, gTrainerBackPic_RubySapphireBrendan, 0x2000),
    TRAINER_BACK_SPRITE(RUBY_SAPPHIRE_MAY, gTrainerBackPic_RubySapphireMay, 0x2000),
    TRAINER_BACK_SPRITE(WALLY, gTrainerBackPic_Wally, 0x2000),
    TRAINER_BACK_SPRITE(STEVEN, gTrainerBackPic_Steven, 0x2000),
};

#define TRAINER_BACK_PAL(trainerPic, pal) [TRAINER_BACK_PIC_##trainerPic] = {pal, TRAINER_BACK_PIC_##trainerPic}

const struct CompressedSpritePalette gTrainerBackPicPaletteTable[] =
{
    TRAINER_BACK_PAL(SCOTT, gTrainerPalette_Scott),
    TRAINER_BACK_PAL(YEVA, gTrainerPalette_Yeva),
    TRAINER_BACK_PAL(RED, gTrainerBackPicPalette_Red),
    TRAINER_BACK_PAL(LEAF, gTrainerBackPicPalette_Leaf),
    TRAINER_BACK_PAL(RUBY_SAPPHIRE_BRENDAN, gTrainerPalette_RubySapphireBrendan),
    TRAINER_BACK_PAL(RUBY_SAPPHIRE_MAY, gTrainerPalette_RubySapphireMay),
    TRAINER_BACK_PAL(WALLY, gTrainerPalette_Wally),
    TRAINER_BACK_PAL(STEVEN, gTrainerPalette_Steven),
};
