#include "lvgl.h"

/*******************************************************************************
 * Size: 9 px
 * Bpp: 1
 * Opts:
 ******************************************************************************/

#ifndef SOURCE_CODE_PRO_9
#define SOURCE_CODE_PRO_9 1
#endif

#if SOURCE_CODE_PRO_9

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t gylph_bitmap[] = {
    /* U+20 " " */
    0x0,

    /* U+21 "!" */
    0xf2,

    /* U+22 "\"" */
    0xb6, 0x80,

    /* U+23 "#" */
    0x2a, 0xfa, 0xea, 0x80,

    /* U+24 "$" */
    0x4a, 0x44, 0x4e, 0x40,

    /* U+25 "%" */
    0xe5, 0x6d, 0xf6, 0xd4, 0xe0,

    /* U+26 "&" */
    0x63, 0x18, 0x9b, 0x4b, 0xa0,

    /* U+27 "'" */
    0xe0,

    /* U+28 "(" */
    0x4a, 0x49, 0x22, 0x20,

    /* U+29 ")" */
    0x48, 0x92, 0x4a, 0x80,

    /* U+2A "*" */
    0x25, 0x5c, 0xa0,

    /* U+2B "+" */
    0x27, 0xc8, 0x40,

    /* U+2C "," */
    0xd8,

    /* U+2D "-" */
    0xf0,

    /* U+2E "." */
    0x80,

    /* U+2F "/" */
    0x22, 0x24, 0x44, 0x88, 0x80,

    /* U+30 "0" */
    0x69, 0x9b, 0x99, 0x60,

    /* U+31 "1" */
    0x61, 0x8, 0x42, 0x13, 0xe0,

    /* U+32 "2" */
    0x69, 0x12, 0x24, 0xf0,

    /* U+33 "3" */
    0x69, 0x16, 0x11, 0xe0,

    /* U+34 "4" */
    0x11, 0x95, 0x2f, 0x88, 0x40,

    /* U+35 "5" */
    0x7a, 0x10, 0xe0, 0x85, 0xc0,

    /* U+36 "6" */
    0x6c, 0x8f, 0x99, 0x60,

    /* U+37 "7" */
    0xf2, 0x24, 0x44, 0x40,

    /* U+38 "8" */
    0x69, 0x96, 0x99, 0x60,

    /* U+39 "9" */
    0x69, 0x99, 0x71, 0x60,

    /* U+3A ":" */
    0x88,

    /* U+3B ";" */
    0x8e,

    /* U+3C "<" */
    0x16, 0x84, 0x21,

    /* U+3D "=" */
    0xf0, 0xf0,

    /* U+3E ">" */
    0x84, 0x32, 0xc0,

    /* U+3F "?" */
    0x69, 0x12, 0x40, 0x40,

    /* U+40 "@" */
    0x72, 0x63, 0x7c, 0xfd, 0xe,

    /* U+41 "A" */
    0x22, 0x94, 0xa7, 0x46, 0x20,

    /* U+42 "B" */
    0xe9, 0x9e, 0x99, 0xe0,

    /* U+43 "C" */
    0x76, 0x21, 0x8, 0x61, 0xc0,

    /* U+44 "D" */
    0xeb, 0x99, 0x9b, 0xe0,

    /* U+45 "E" */
    0xf8, 0x8e, 0x88, 0xf0,

    /* U+46 "F" */
    0xf8, 0x8e, 0x88, 0x80,

    /* U+47 "G" */
    0x6c, 0x8b, 0x99, 0x70,

    /* U+48 "H" */
    0x99, 0x9f, 0x99, 0x90,

    /* U+49 "I" */
    0xe9, 0x24, 0xb8,

    /* U+4A "J" */
    0x71, 0x11, 0x19, 0x60,

    /* U+4B "K" */
    0x95, 0x29, 0xca, 0x4a, 0x40,

    /* U+4C "L" */
    0x88, 0x88, 0x88, 0xf0,

    /* U+4D "M" */
    0x99, 0xff, 0xd9, 0x90,

    /* U+4E "N" */
    0x9d, 0xdd, 0xbb, 0x90,

    /* U+4F "O" */
    0x76, 0xe3, 0x18, 0xed, 0xc0,

    /* U+50 "P" */
    0xe9, 0x99, 0xe8, 0x80,

    /* U+51 "Q" */
    0x76, 0xe3, 0x18, 0xc5, 0xc4, 0x18,

    /* U+52 "R" */
    0xe9, 0x9e, 0xaa, 0x90,

    /* U+53 "S" */
    0x68, 0x86, 0x11, 0xe0,

    /* U+54 "T" */
    0xf9, 0x8, 0x42, 0x10, 0x80,

    /* U+55 "U" */
    0x99, 0x99, 0x99, 0x60,

    /* U+56 "V" */
    0x8a, 0x54, 0xa5, 0x18, 0x80,

    /* U+57 "W" */
    0x8c, 0x6b, 0x5d, 0xed, 0x60,

    /* U+58 "X" */
    0x4a, 0x8c, 0x45, 0x29, 0x20,

    /* U+59 "Y" */
    0x8a, 0x94, 0xc2, 0x10, 0x80,

    /* U+5A "Z" */
    0xf1, 0x24, 0x48, 0xf0,

    /* U+5B "[" */
    0xf2, 0x49, 0x24, 0xe0,

    /* U+5C "\\" */
    0x88, 0x84, 0x44, 0x22, 0x10,

    /* U+5D "]" */
    0xe4, 0x92, 0x49, 0xe0,

    /* U+5E "^" */
    0x56, 0xd0,

    /* U+5F "_" */
    0xf0,

    /* U+60 "`" */
    0x10,

    /* U+61 "a" */
    0x71, 0x79, 0xf0,

    /* U+62 "b" */
    0x88, 0xe9, 0x99, 0xe0,

    /* U+63 "c" */
    0x78, 0x88, 0x70,

    /* U+64 "d" */
    0x11, 0x79, 0x99, 0x70,

    /* U+65 "e" */
    0x72, 0x5f, 0x7, 0x0,

    /* U+66 "f" */
    0x74, 0xf4, 0x44, 0x40,

    /* U+67 "g" */
    0xfc, 0x9d, 0x7, 0xc7, 0xc0,

    /* U+68 "h" */
    0x88, 0xbd, 0x99, 0x90,

    /* U+69 "i" */
    0x23, 0x92, 0x48,

    /* U+6A "j" */
    0x23, 0x92, 0x49, 0xc0,

    /* U+6B "k" */
    0x88, 0x9a, 0xea, 0x90,

    /* U+6C "l" */
    0xe1, 0x8, 0x42, 0x10, 0xe0,

    /* U+6D "m" */
    0xfd, 0x6b, 0x5a, 0x80,

    /* U+6E "n" */
    0xbd, 0x99, 0x90,

    /* U+6F "o" */
    0x69, 0x99, 0x60,

    /* U+70 "p" */
    0xe9, 0x99, 0xe8, 0x80,

    /* U+71 "q" */
    0x79, 0x99, 0x71, 0x10,

    /* U+72 "r" */
    0xbc, 0x88, 0x80,

    /* U+73 "s" */
    0xe8, 0x61, 0xf0,

    /* U+74 "t" */
    0x44, 0xf4, 0x44, 0x70,

    /* U+75 "u" */
    0x99, 0x99, 0xf0,

    /* U+76 "v" */
    0x8a, 0x94, 0xa2, 0x0,

    /* U+77 "w" */
    0xad, 0x6f, 0xb5, 0x0,

    /* U+78 "x" */
    0xaa, 0x4a, 0xa0,

    /* U+79 "y" */
    0x8a, 0x94, 0x62, 0x11, 0x0,

    /* U+7A "z" */
    0xf2, 0x48, 0xf0,

    /* U+7B "{" */
    0x74, 0x44, 0x84, 0x44, 0x70,

    /* U+7C "|" */
    0xff, 0xc0,

    /* U+7D "}" */
    0xe2, 0x22, 0x12, 0x22, 0xe0,

    /* U+7E "~" */
    0xda,

    /* U+A0 " " */
    0x0,

    /* U+A1 "¡" */
    0x9e,

    /* U+A2 "¢" */
    0x27, 0xaa, 0xa7, 0x20,

    /* U+A3 "£" */
    0x74, 0x4f, 0x44, 0xf0,

    /* U+A4 "¤" */
    0xf, 0x99, 0xf0,

    /* U+A5 "¥" */
    0x8a, 0x94, 0xcf, 0xfc, 0x80,

    /* U+A6 "¦" */
    0xf3, 0xc0,

    /* U+A7 "§" */
    0x68, 0x4b, 0xd2, 0x26,

    /* U+A8 "¨" */
    0xa0,

    /* U+A9 "©" */
    0x76, 0xfb, 0x9c, 0xfd, 0xc0,

    /* U+AA "ª" */
    0xdf, 0x80,

    /* U+AB "«" */
    0xa, 0xaa,

    /* U+AC "¬" */
    0xf1, 0x10,

    /* U+AD "­" */
    0xf0,

    /* U+AE "®" */
    0x6b, 0xd6,

    /* U+AF "¯" */
    0xe0,

    /* U+B0 "°" */
    0xf7, 0x80,

    /* U+B1 "±" */
    0x27, 0xc8, 0x4f, 0x80,

    /* U+B2 "²" */
    0xe5, 0x70,

    /* U+B3 "³" */
    0xe8, 0xf0,

    /* U+B4 "´" */
    0x60,

    /* U+B5 "µ" */
    0x99, 0x99, 0xf8, 0x80,

    /* U+B6 "¶" */
    0x7f, 0xf7, 0x11, 0x10,

    /* U+B7 "·" */
    0x80,

    /* U+B8 "¸" */
    0x90,

    /* U+B9 "¹" */
    0xc9, 0x70,

    /* U+BA "º" */
    0x55, 0x0,

    /* U+BB "»" */
    0x5, 0x5a,

    /* U+BC "¼" */
    0xca, 0x90, 0x27, 0x5c,

    /* U+BD "½" */
    0xca, 0x90, 0x35, 0x4c,

    /* U+BE "¾" */
    0xc2, 0x55, 0x81, 0x3a, 0xe0,

    /* U+BF "¿" */
    0x41, 0x29, 0x70,

    /* U+C0 "À" */
    0x20, 0x8, 0xa5, 0x29, 0xd1, 0x88,

    /* U+C1 "Á" */
    0x11, 0x8, 0xa5, 0x29, 0xd1, 0x88,

    /* U+C2 "Â" */
    0x22, 0x88, 0xa5, 0x29, 0xd1, 0x88,

    /* U+C3 "Ã" */
    0x62, 0x88, 0xa5, 0x29, 0xd1, 0x88,

    /* U+C4 "Ä" */
    0x51, 0x14, 0xa5, 0x3a, 0x31,

    /* U+C5 "Å" */
    0x31, 0x43, 0xc, 0x51, 0x27, 0x92, 0x88,

    /* U+C6 "Æ" */
    0x3c, 0xc5, 0x16, 0x72, 0x49, 0xc0,

    /* U+C7 "Ç" */
    0x76, 0x21, 0x8, 0x61, 0xc4, 0x20,

    /* U+C8 "È" */
    0x42, 0xf8, 0x8e, 0x88, 0xf0,

    /* U+C9 "É" */
    0x20, 0xf8, 0x8e, 0x88, 0xf0,

    /* U+CA "Ê" */
    0x24, 0xf8, 0x8e, 0x88, 0xf0,

    /* U+CB "Ë" */
    0x6f, 0x88, 0xe8, 0x8f,

    /* U+CC "Ì" */
    0x8b, 0xa4, 0x92, 0xe0,

    /* U+CD "Í" */
    0x2b, 0xa4, 0x92, 0xe0,

    /* U+CE "Î" */
    0x57, 0xa4, 0x92, 0xe0,

    /* U+CF "Ï" */
    0xbd, 0x24, 0x97,

    /* U+D0 "Ð" */
    0x72, 0xd3, 0xd4, 0xad, 0xc0,

    /* U+D1 "Ñ" */
    0x52, 0x9d, 0xdd, 0xbb, 0x90,

    /* U+D2 "Ò" */
    0x41, 0x1d, 0xb8, 0xc6, 0x3b, 0x70,

    /* U+D3 "Ó" */
    0x11, 0x1d, 0xb8, 0xc6, 0x3b, 0x70,

    /* U+D4 "Ô" */
    0x22, 0x9d, 0xb8, 0xc6, 0x3b, 0x70,

    /* U+D5 "Õ" */
    0x61, 0x9d, 0xb8, 0xc6, 0x3b, 0x70,

    /* U+D6 "Ö" */
    0x53, 0xb7, 0x18, 0xc7, 0x6e,

    /* U+D7 "×" */
    0xaa, 0xc0,

    /* U+D8 "Ø" */
    0x7e, 0xa7, 0x5c, 0xaf, 0xc0,

    /* U+D9 "Ù" */
    0x40, 0x99, 0x99, 0x99, 0x60,

    /* U+DA "Ú" */
    0x20, 0x99, 0x99, 0x99, 0x60,

    /* U+DB "Û" */
    0x6, 0x99, 0x99, 0x99, 0x60,

    /* U+DC "Ü" */
    0xa9, 0x99, 0x99, 0x96,

    /* U+DD "Ý" */
    0x11, 0x22, 0xa5, 0x30, 0x84, 0x20,

    /* U+DE "Þ" */
    0x8e, 0x99, 0x9e, 0x80,

    /* U+DF "ß" */
    0xea, 0xac, 0xa9, 0xb0,

    /* U+E0 "à" */
    0x44, 0x7, 0x17, 0x9f,

    /* U+E1 "á" */
    0x2, 0x7, 0x17, 0x9f,

    /* U+E2 "â" */
    0x6, 0x7, 0x17, 0x9f,

    /* U+E3 "ã" */
    0x70, 0x71, 0x79, 0xf0,

    /* U+E4 "ä" */
    0x60, 0x71, 0x79, 0xf0,

    /* U+E5 "å" */
    0x66, 0x7, 0x17, 0x9f,

    /* U+E6 "æ" */
    0xd9, 0x7f, 0x4d, 0x80,

    /* U+E7 "ç" */
    0x78, 0x88, 0x74, 0x20,

    /* U+E8 "è" */
    0x1, 0x0, 0xe4, 0xbe, 0xe,

    /* U+E9 "é" */
    0x11, 0x0, 0xe4, 0xbe, 0xe,

    /* U+EA "ê" */
    0x22, 0x80, 0xe4, 0xbe, 0xe,

    /* U+EB "ë" */
    0x50, 0x1c, 0x97, 0xc1, 0xc0,

    /* U+EC "ì" */
    0x44, 0x72, 0x49,

    /* U+ED "í" */
    0x12, 0xe, 0x22, 0x22,

    /* U+EE "î" */
    0x25, 0xe, 0x22, 0x22,

    /* U+EF "ï" */
    0x50, 0xe2, 0x22, 0x20,

    /* U+F0 "ð" */
    0x52, 0x27, 0x99, 0x96,

    /* U+F1 "ñ" */
    0x70, 0xbd, 0x99, 0x90,

    /* U+F2 "ò" */
    0x44, 0x6, 0x99, 0x96,

    /* U+F3 "ó" */
    0x24, 0x6, 0x99, 0x96,

    /* U+F4 "ô" */
    0x6, 0x6, 0x99, 0x96,

    /* U+F5 "õ" */
    0x60, 0x69, 0x99, 0x60,

    /* U+F6 "ö" */
    0x50, 0x69, 0x99, 0x60,

    /* U+F7 "÷" */
    0x40, 0xf0, 0x40,

    /* U+F8 "ø" */
    0x7b, 0xdd, 0xe0,

    /* U+F9 "ù" */
    0x44, 0x9, 0x99, 0x9f,

    /* U+FA "ú" */
    0x24, 0x9, 0x99, 0x9f,

    /* U+FB "û" */
    0x6, 0x9, 0x99, 0x9f,

    /* U+FC "ü" */
    0xa0, 0x99, 0x99, 0xf0,

    /* U+FD "ý" */
    0x11, 0x1, 0x15, 0x28, 0xc4, 0x22, 0x0,

    /* U+FE "þ" */
    0x88, 0xe9, 0x99, 0xe8, 0x80,

    /* U+FF "ÿ" */
    0x50, 0x22, 0xa5, 0x18, 0x84, 0x40};

/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0,
     .adv_w = 0,
     .box_w = 0,
     .box_h = 0,
     .ofs_x = 0,
     .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0,
     .adv_w = 86,
     .box_w = 1,
     .box_h = 1,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1,
     .adv_w = 86,
     .box_w = 1,
     .box_h = 7,
     .ofs_x = 2,
     .ofs_y = 0},
    {.bitmap_index = 2,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 3,
     .ofs_x = 1,
     .ofs_y = 4},
    {.bitmap_index = 4,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 8,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = -1},
    {.bitmap_index = 12,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 17,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 22,
     .adv_w = 86,
     .box_w = 1,
     .box_h = 3,
     .ofs_x = 2,
     .ofs_y = 4},
    {.bitmap_index = 23,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 9,
     .ofs_x = 2,
     .ofs_y = -2},
    {.bitmap_index = 27,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 31,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 2},
    {.bitmap_index = 34,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 1},
    {.bitmap_index = 37,
     .adv_w = 86,
     .box_w = 2,
     .box_h = 3,
     .ofs_x = 2,
     .ofs_y = -2},
    {.bitmap_index = 38,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 1,
     .ofs_x = 1,
     .ofs_y = 3},
    {.bitmap_index = 39,
     .adv_w = 86,
     .box_w = 1,
     .box_h = 1,
     .ofs_x = 2,
     .ofs_y = 0},
    {.bitmap_index = 40,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 45,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 49,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 54,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 58,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 62,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 67,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 72,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 76,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 80,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 84,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 88,
     .adv_w = 86,
     .box_w = 1,
     .box_h = 5,
     .ofs_x = 2,
     .ofs_y = 0},
    {.bitmap_index = 89,
     .adv_w = 86,
     .box_w = 1,
     .box_h = 7,
     .ofs_x = 2,
     .ofs_y = -2},
    {.bitmap_index = 90,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 6,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 93,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 3,
     .ofs_x = 1,
     .ofs_y = 2},
    {.bitmap_index = 95,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 6,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 98,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 102,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = -1},
    {.bitmap_index = 107,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 112,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 116,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 121,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 125,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 129,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 133,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 137,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 141,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 144,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 148,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 153,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 157,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 161,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 165,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 170,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 174,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 180,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 184,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 188,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 193,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 197,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 202,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 207,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 212,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 217,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 221,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 9,
     .ofs_x = 2,
     .ofs_y = -2},
    {.bitmap_index = 225,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 230,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 234,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 4,
     .ofs_x = 1,
     .ofs_y = 3},
    {.bitmap_index = 236,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 1,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 237,
     .adv_w = 86,
     .box_w = 2,
     .box_h = 2,
     .ofs_x = 1,
     .ofs_y = 6},
    {.bitmap_index = 238,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 241,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 245,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 248,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 252,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 256,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 260,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 265,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 269,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 272,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 276,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 280,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 285,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 289,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 292,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 295,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 299,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 303,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 306,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 309,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 313,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 316,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 320,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 324,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 327,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 332,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 335,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 340,
     .adv_w = 86,
     .box_w = 1,
     .box_h = 10,
     .ofs_x = 2,
     .ofs_y = -3},
    {.bitmap_index = 342,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 9,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 347,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 2,
     .ofs_x = 1,
     .ofs_y = 2},
    {.bitmap_index = 348,
     .adv_w = 86,
     .box_w = 1,
     .box_h = 1,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 349,
     .adv_w = 86,
     .box_w = 1,
     .box_h = 7,
     .ofs_x = 2,
     .ofs_y = -2},
    {.bitmap_index = 350,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 354,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 358,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 6,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 361,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 366,
     .adv_w = 86,
     .box_w = 1,
     .box_h = 10,
     .ofs_x = 2,
     .ofs_y = -3},
    {.bitmap_index = 368,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = -1},
    {.bitmap_index = 372,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 1,
     .ofs_x = 1,
     .ofs_y = 6},
    {.bitmap_index = 373,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 378,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 3,
     .ofs_x = 1,
     .ofs_y = 4},
    {.bitmap_index = 380,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 4,
     .ofs_x = 1,
     .ofs_y = 1},
    {.bitmap_index = 382,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 3,
     .ofs_x = 1,
     .ofs_y = 1},
    {.bitmap_index = 384,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 1,
     .ofs_x = 1,
     .ofs_y = 3},
    {.bitmap_index = 385,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 4,
     .ofs_x = 1,
     .ofs_y = 3},
    {.bitmap_index = 387,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 1,
     .ofs_x = 1,
     .ofs_y = 6},
    {.bitmap_index = 388,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 3,
     .ofs_x = 2,
     .ofs_y = 4},
    {.bitmap_index = 390,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 394,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 4,
     .ofs_x = 1,
     .ofs_y = 4},
    {.bitmap_index = 396,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 4,
     .ofs_x = 1,
     .ofs_y = 4},
    {.bitmap_index = 398,
     .adv_w = 86,
     .box_w = 2,
     .box_h = 2,
     .ofs_x = 2,
     .ofs_y = 6},
    {.bitmap_index = 399,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 403,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 407,
     .adv_w = 86,
     .box_w = 1,
     .box_h = 1,
     .ofs_x = 2,
     .ofs_y = 3},
    {.bitmap_index = 408,
     .adv_w = 86,
     .box_w = 2,
     .box_h = 2,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 409,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 4,
     .ofs_x = 1,
     .ofs_y = 4},
    {.bitmap_index = 411,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 3,
     .ofs_x = 1,
     .ofs_y = 4},
    {.bitmap_index = 413,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 4,
     .ofs_x = 1,
     .ofs_y = 1},
    {.bitmap_index = 415,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 419,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 423,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 428,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 431,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 9,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 437,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 9,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 443,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 9,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 449,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 9,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 455,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 460,
     .adv_w = 86,
     .box_w = 6,
     .box_h = 9,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 467,
     .adv_w = 86,
     .box_w = 6,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 473,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 479,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 484,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 489,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 494,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 498,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 502,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 506,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 510,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 513,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 518,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 523,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 529,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 535,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 541,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 547,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 552,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 4,
     .ofs_x = 1,
     .ofs_y = 1},
    {.bitmap_index = 554,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 559,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 564,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 569,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 574,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 578,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 9,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 584,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 588,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 592,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 596,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 600,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 604,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 608,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 612,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 616,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 620,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 624,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 629,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 634,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 639,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 644,
     .adv_w = 86,
     .box_w = 3,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 647,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 651,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 655,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 659,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 663,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 667,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 671,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 675,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 679,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 683,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 687,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 1},
    {.bitmap_index = 690,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 693,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 697,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 701,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 705,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 709,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 10,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 716,
     .adv_w = 86,
     .box_w = 4,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 721,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 9,
     .ofs_x = 0,
     .ofs_y = -2}};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] = {
    {.range_start = 32,
     .range_length = 95,
     .glyph_id_start = 1,
     .unicode_list = NULL,
     .glyph_id_ofs_list = NULL,
     .list_length = 0,
     .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY},
    {.range_start = 160,
     .range_length = 96,
     .glyph_id_start = 96,
     .unicode_list = NULL,
     .glyph_id_ofs_list = NULL,
     .list_length = 0,
     .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY}};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {.glyph_bitmap = gylph_bitmap,
                                         .glyph_dsc = glyph_dsc,
                                         .cmaps = cmaps,
                                         .kern_dsc = NULL,
                                         .kern_scale = 0,
                                         .cmap_num = 2,
                                         .bpp = 1,
                                         .kern_classes = 0,
                                         .bitmap_format = 0};

/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t source_code_pro_9 = {
    .get_glyph_dsc =
        lv_font_get_glyph_dsc_fmt_txt, /*Function pointer to get glyph's data*/
    .get_glyph_bitmap =
        lv_font_get_bitmap_fmt_txt, /*Function pointer to get glyph's bitmap*/
    .line_height = 12, /*The maximum line height required by the font*/
    .base_line = 3,    /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0)
    .underline_position = -1,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc /*The custom font data. Will be accessed by
                        `get_glyph_bitmap/dsc` */
};

#endif /*#if SOURCE_CODE_PRO_9*/
