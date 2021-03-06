/**
 * @file camera_ov3640.h
 * @brief camera driver file
 * Copyright (C) 2010 Anyka (Guangzhou) Microelectronics Technology Co., Ltd
 * @author xia_wenting 
 * @date 2010-12-01
 * @version 1.0
 * @ref
 */ 
#ifndef __CAMERA_OV3640_H__
#define __CAMERA_OV3640_H__

#include "drv_cfg.h"
#if (DRV_SUPPORT_CAMERA > 0) && (CAMERA_OV3640 > 0)

#define DELAY_FLAG   0xfe
#define END_FLAG     0xff

////////////////////////////////////////////////
static const T_U16 INIT_TAB[] = 
{     
     0x3012, 0x80,
     //delay 10ms 
     0x304d, 0x45,
     0x30a7, 0x5e,
     0x3087, 0x16,
     0x309C, 0x1a,
     0x30a2, 0xe4,
     0x30aa, 0x42,
     0x30b0, 0xff,
     0x30b1, 0xff,
     0x30b2, 0x10,
     0x300e, 0x39,
     0x300f, 0x21,
     0x3010, 0x20,
     0x304c, 0x81,
     0x30d7, 0x10,
     0x30d9, 0x0d,
     0x30db, 0x08,
     0x3016, 0x82,
     0x3018, 0x48,
     0x3019, 0x40,
     0x301a, 0x82,
     0x307d, 0x00,
     0x3087, 0x02,
     0x3082, 0x20,
     0x3015, 0x12,
     0x3014, 0x84,
     0x3013, 0xf7,
     0x303c, 0x08,
     0x303d, 0x18,
     0x303e, 0x06,
     0x303F, 0x0c,
     0x3030, 0x62,
     0x3031, 0x26,
     0x3032, 0xe6,
     0x3033, 0x6e,
     0x3034, 0xea,
     0x3035, 0xae,
     0x3036, 0xa6,
     0x3037, 0x6a,
     0x3104, 0x02,
     0x3105, 0xfd,
     0x3106, 0x00,
     0x3107, 0xff,
     0x3300, 0x13,
     0x3301, 0xde,
     0x3302, 0xcf,
     0x3312, 0x26,
     0x3314, 0x42,
     0x3313, 0x2b,
     0x3315, 0x42,
     0x3310, 0xd0,
     0x3311, 0xbd,
     0x330c, 0x18,
     0x330d, 0x18,
     0x330e, 0x56,
     0x330f, 0x5c,
     0x330b, 0x1c,
     0x3306, 0x5c,
     0x3307, 0x11,
     0x336a, 0x52,
     0x3370, 0x46,
     0x3376, 0x38,
     0x30b8, 0x20,
     0x30b9, 0x17,
     0x30ba, 0x00,
     0x30bb, 0x08,
     0x3507, 0x06,
     0x350a, 0x4f,
     0x3100, 0x02,
     0x3301, 0xde,
     0x3304, 0xfc,
     0x3400, 0x00,
     0x3404, 0x02, //00,
     0x3600, 0xc0, //c4,
     0x3088, 0x08,
     0x3089, 0x00,
     0x308a, 0x06,
     0x308b, 0x00,
     0x308d, 0x04,
     0x3086, 0x03,
     0x3086, 0x00,
     0x30a9, 0xbd,
     0x3317, 0x04,
     0x3316, 0xf8,
     0x3312, 0x31,
     0x3314, 0x57,
     0x3313, 0x28,
     0x3315, 0x3d,
     0x3311, 0xd0,
     0x3310, 0xb6,
     0x330c, 0x16,
     0x330d, 0x16,
     0x330e, 0x5f,
     0x330f, 0x5c,
     0x330b, 0x18,
     0x3306, 0x5c,
     0x3307, 0x11,
     0x3308, 0x25,
     0x3340, 0x20,
     0x3341, 0x58,
     0x3342, 0x08,
     0x3343, 0x21,
     0x3344, 0xbe,
     0x3345, 0xe0,
     0x3346, 0xca,
     0x3347, 0xc6,
     0x3348, 0x04,
     0x3349, 0x98,
     0x3355, 0x02,
     0x3358, 0x44,
     0x3359, 0x44,
     0x3300, 0x13,
     0x3367, 0x23,
     0x3368, 0xBB,
     0x3369, 0xD6,
     0x336A, 0x2A,
     0x336B, 0x07,
     0x336C, 0x00,
     0x336D, 0x23,
     0x336E, 0xC3,
     0x336F, 0xDE,
     0x3370, 0x2b,
     0x3371, 0x07,
     0x3372, 0x00,
     0x3373, 0x23,
     0x3374, 0x9e,
     0x3375, 0xD6,
     0x3376, 0x29,
     0x3377, 0x07,
     0x3378, 0x00,
     0x332a, 0x1d,
     0x331b, 0x08,
     0x331c, 0x16,
     0x331d, 0x2d,
     0x331e, 0x54,
     0x331f, 0x66,
     0x3320, 0x73,
     0x3321, 0x80,
     0x3322, 0x8c,
     0x3323, 0x95,
     0x3324, 0x9d,
     0x3325, 0xac,
     0x3326, 0xb8,
     0x3327, 0xcc,
     0x3328, 0xdd,
     0x3329, 0xee,
     0x332e, 0x04,
     0x332f, 0x06,
     0x3331, 0x03,
    
     //for preview 
     0x3012, 0x10,
     0x3023, 0x06,
     0x3026, 0x03,
     0x3027, 0x04,
     0x302a, 0x03,
     0x302b, 0x10,
     0x3075, 0x24,
     0x300d, 0x01,
     0x30d7, 0x90,
     0x3069, 0x04,
     0x303e, 0x00,
     0x303f, 0xc0,
     0x300e, 0x32,
     0x300f, 0x21,
     0x3010, 0x20,
     0x3011, 0x00,
    
     // XGA-VGA   
     0x3302, 0xef,
     0x335f, 0x34,
     0x3360, 0x0c,
     0x3361, 0x04,
     0x3362, 0x12,
     0x3363, 0x88,
     0x3364, 0xe4,
     0x3403, 0x42,
     0x3088, 0x12,
     0x3089, 0x80,
     0x308a, 0x01,
     0x308b, 0xe0,
     0x304c, 0x85,
     
     0x3302, 0xef,
     0x3355, 0x06,     
     0x3354, 0x09,
     0x335e, 0x10,    
     0x3358, 0x37,
     0x3359, 0x37,
     0x335c, 0x20,
     0x335d, 0x20,     
     END_FLAG, END_FLAG

};

static const T_U16 JPEG_TAB[] = 
{
     //JPEG                                
     0x3100, 0x32,                         
     0x3304, 0x00,                        
     0x3400, 0x02,                         
     0x3404, 0x22,                         
     0x3500, 0x00,                         
     0x3600, 0xc0, //Vsync mode2 select   
     0x3610, 0x00,                         
     0x3611, 0x20, //fixed width 1024 pclk
     0x3507, 0x0f, //QScale               
     0x350a, 0x4f,
     0x304c, 0x88,
     END_FLAG, END_FLAG
};

/****************   Camera Resolution Table   ****************/    
static const T_U16 QXGA_MODE_TAB[] = 
{ 
    //2048*1536                            
    0x3012, 0x00,
    0x3020, 0x01,
    0x3021, 0x1d,
    0x3022, 0x00,
    0x3023, 0x0a,
    0x3024, 0x08,
    0x3025, 0x18,
    0x3026, 0x06,
    0x3027, 0x0c,
    0x302a, 0x06,
    0x302b, 0x20,
    0x3075, 0x44,
    0x300d, 0x00,
    0x30d7, 0x10,
    0x3069, 0x44,
    0x303e, 0x01,
    0x303f, 0x80,
    
    0x3302, 0xcf,
    0x335f, 0x68,
    0x3360, 0x18,
    0x3361, 0x0c,
    0x3362, 0x68,
    0x3363, 0x08,
    0x3364, 0x04,
    0x3366, 0x10,
    0x3403, 0x42,
    0x3088, 0x08,
    0x3089, 0x00,
    0x308a, 0x06,
    0x308b, 0x00,
    
    0x300e, 0x39,//39,
    0x300f, 0x21,
    0x3010, 0x20,
    0x3011, 0x01,//01,
    0x304c, 0x81,//81,
    
    0x332a, 0x20,
    0x331b, 0x1c,
    0x331c, 0x28,
    0x331d, 0x3c,
    0x331e, 0x5a,
    0x331f, 0x68,
    0x3320, 0x76,
    0x3321, 0x80,
    0x3322, 0x88,
    0x3323, 0x8f,
    0x3324, 0x96,
    0x3325, 0xa3,
    0x3326, 0xaf,
    0x3327, 0xc4,
    0x3328, 0xd7,
    0x3329, 0xe8,

    0x3302, 0xef,
    0x3355, 0x06,
    0x3354, 0x09,
    0x335e, 0x10,     
    0x3358, 0x37,
    0x3359, 0x37,
    0x335c, 0x20,
    0x335d, 0x20,
    END_FLAG, END_FLAG
};

static const T_U16 UXGA_MODE_TAB[] = 
{ 
    //1600*1200    
      //QXGA->UXGA 
    0x3012, 0x00,
    0x3020, 0x01,
    0x3021, 0x1d,
    0x3022, 0x00,
    0x3023, 0x0a,
    0x3024, 0x08,
    0x3025, 0x18,
    0x3026, 0x06,
    0x3027, 0x0c,
    0x302a, 0x06,
    0x302b, 0x20,
    0x3075, 0x44,
    0x300d, 0x00,
    0x30d7, 0x10,
    0x3069, 0x40,
    0x303e, 0x01,
    0x303f, 0x80,
                 
    0x3302, 0xef,
    0x335f, 0x68,
    0x3360, 0x00,
    0x3361, 0x00,
    0x3362, 0x46,
    0x3363, 0x48,
    0x3364, 0xb4,
    0x3403, 0x42,
    0x3088, 0x06,
    0x3089, 0x40,
    0x308a, 0x04,
    0x308b, 0xb0,
                 
    0x300e, 0x39,//39,
    0x300f, 0x21,
    0x3010, 0x20,
    0x3011, 0x01,//01,
    0x304c, 0x81,//81,

    END_FLAG, END_FLAG
};

static const T_U16 SXGA_MODE_TAB[] = 
{
    //1280*1024     
    //QXGA->SXGA  
    0x3012, 0x00, 
    0x3020, 0x01, 
    0x3021, 0x1d, 
    0x3022, 0x00, 
    0x3023, 0x0a, 
    0x3024, 0x08, 
    0x3025, 0x18, 
    0x3026, 0x06, 
    0x3027, 0x0c, 
    0x302a, 0x06, 
    0x302b, 0x20, 
    0x3075, 0x44, 
    0x300d, 0x00, 
    0x30d7, 0x10, 
    0x3069, 0x40, 
    0x303e, 0x01, 
    0x303f, 0x80, 
                     
    0x3302, 0xef, 
    0x335f, 0x68, 
    0x3360, 0x18, 
    0x3361, 0x0c, 
    0x3362, 0x45, 
    0x3363, 0x08, 
    0x3364, 0x04, 
    0x3403, 0x42, 
    0x3088, 0x05, 
    0x3089, 0x00, 
    0x308a, 0x04, 
    0x308b, 0x00, 
                    
    0x300e, 0x39,//39,
    0x300f, 0x21,
    0x3010, 0x20,
    0x3011, 0x00,//01,
    0x304c, 0x82,//81,

    0x332a, 0x20,
    0x331b, 0x1c,
    0x331c, 0x28,
    0x331d, 0x3c,
    0x331e, 0x5a,
    0x331f, 0x68,
    0x3320, 0x76,
    0x3321, 0x80,
    0x3322, 0x88,
    0x3323, 0x8f,
    0x3324, 0x96,
    0x3325, 0xa3,
    0x3326, 0xaf,
    0x3327, 0xc4,
    0x3328, 0xd7,
    0x3329, 0xe8,

    0x3302, 0xef,
    0x3355, 0x06,
    0x3354, 0x09,
    0x335e, 0x10,     
    0x3358, 0x37,
    0x3359, 0x37,
    0x335c, 0x20,
    0x335d, 0x20,

    END_FLAG, END_FLAG
};

static const T_U16 XGA_MODE_TAB[] = 
{  //1024*768     
   //QXGA->XGA  
   0x3012, 0x00,
   0x3020, 0x01,
   0x3021, 0x1d,
   0x3022, 0x00,
   0x3023, 0x0a,
   0x3024, 0x08,
   0x3025, 0x18,
   0x3026, 0x06,
   0x3027, 0x0c,
   0x302a, 0x06,
   0x302b, 0x20,
   0x3075, 0x44,
   0x300d, 0x00,
   0x30d7, 0x10,
   0x3069, 0x40,
   0x303e, 0x01,
   0x303f, 0x80,
                
   0x3302, 0xef,
   0x335f, 0x68,
   0x3360, 0x18,
   0x3361, 0x0c,
   0x3362, 0x34,
   0x3363, 0x08,
   0x3364, 0x04,
   0x3403, 0x42,
   0x3088, 0x04,
   0x3089, 0x00,
   0x308a, 0x03,
   0x308b, 0x00,
                               
   0x300e, 0x39,//39,
   0x300f, 0x21,
   0x3010, 0x20,
   0x3011, 0x00,//01,
   0x304c, 0x82,//81,


    END_FLAG, END_FLAG
};

static const T_U16 SVGA_MODE_TAB[] = 
{ 
    //800*600       
    //QXGA->SVGA 
    0x3012, 0x00,
    0x3020, 0x01,
    0x3021, 0x1d,
    0x3022, 0x00,
    0x3023, 0x0a,
    0x3024, 0x08,
    0x3025, 0x18,
    0x3026, 0x06,
    0x3027, 0x0c,
    0x302a, 0x06,
    0x302b, 0x20,
    0x3075, 0x44,
    0x300d, 0x00,
    0x30d7, 0x10,
    0x3069, 0x40,
    0x303e, 0x01,
    0x303f, 0x80,
                 
    0x3302, 0xef,
    0x335f, 0x68,
    0x3360, 0x18,
    0x3361, 0x0c,
    0x3362, 0x23,
    0x3363, 0x28,
    0x3364, 0x5c,
    0x3403, 0x42,
    0x3088, 0x03,
    0x3089, 0x20,
    0x308a, 0x02,
    0x308b, 0x58,
                                 
    0x300e, 0x39,//39,
    0x300f, 0x21,
    0x3010, 0x20,
    0x3011, 0x00,//01,
    0x304c, 0x82,//81,

    END_FLAG, END_FLAG
};

static const T_U16 VGA_MODE_TAB[] = 
{  
    //640*480       
    //QXGA->VGA  
    0x3012, 0x00,
    0x3020, 0x01,
    0x3021, 0x1d,
    0x3022, 0x00,
    0x3023, 0x0a,
    0x3024, 0x08,
    0x3025, 0x18,
    0x3026, 0x06,
    0x3027, 0x0c,
    0x302a, 0x06,
    0x302b, 0x20,
    0x3075, 0x44,
    0x300d, 0x00,
    0x30d7, 0x10,
    0x3069, 0x40,
    0x303e, 0x01,
    0x303f, 0x80,
                 
    0x3302, 0xef,
    0x335f, 0x68,
    0x3360, 0x18,
    0x3361, 0x0c,
    0x3362, 0x12,
    0x3363, 0x88,
    0x3364, 0xe4,
    0x3403, 0x42,
    0x3088, 0x02,
    0x3089, 0x80,
    0x308a, 0x01,
    0x308b, 0xe0,
                 
    0x300e, 0x32,//39,
    0x300f, 0x21,
    0x3010, 0x20,
    0x3011, 0x00,
    0x304c, 0x85,//85,
    
    END_FLAG, END_FLAG
};

static const T_U16 CIF_MODE_TAB[] = 
{
    //352*288       
    //QXGA->CIF  
    0x3012, 0x00,
    0x3020, 0x01,
    0x3021, 0x1d,
    0x3022, 0x00,
    0x3023, 0x0a,
    0x3024, 0x08,
    0x3025, 0x18,
    0x3026, 0x06,
    0x3027, 0x0c,
    0x302a, 0x06,
    0x302b, 0x20,
    0x3075, 0x44,
    0x300d, 0x00,
    0x30d7, 0x10,
    0x3069, 0x40,
    0x303e, 0x01,
    0x303f, 0x80,
                 
    0x3302, 0xef,
    0x335f, 0x68,
    0x3360, 0x18,
    0x3361, 0x0c,
    0x3362, 0x11,
    0x3363, 0x68,
    0x3364, 0x24,
    0x3403, 0x42,
    0x3088, 0x01,
    0x3089, 0x60,
    0x308a, 0x01,
    0x308b, 0x20,
                 
    0x300e, 0x32,//39,
    0x300f, 0x21,
    0x3010, 0x20,
    0x3011, 0x00,
    0x304c, 0x85,//85,

    END_FLAG, END_FLAG
};

static const T_U16 QVGA_MODE_TAB[] = {
   
    //320*240      
    //QXGA->QVGA
    0x3012, 0x00,
    0x3020, 0x01,
    0x3021, 0x1d,
    0x3022, 0x00,
    0x3023, 0x0a,
    0x3024, 0x08,
    0x3025, 0x18,
    0x3026, 0x06,
    0x3027, 0x0c,
    0x302a, 0x06,
    0x302b, 0x20,
    0x3075, 0x44,
    0x300d, 0x00,
    0x30d7, 0x10,
    0x3069, 0x40,
    0x303e, 0x01,
    0x303f, 0x80,
                 
    0x3302, 0xef,
    0x335f, 0x68,
    0x3360, 0x18,
    0x3361, 0x0c,
    0x3362, 0x01,
    0x3363, 0x48,
    0x3364, 0xf4,
    0x3403, 0x42,
    0x3088, 0x01,
    0x3089, 0x40,
    0x308a, 0x00,
    0x308b, 0xf0,
                 
    0x300e, 0x32,//39,
    0x300f, 0x21,
    0x3010, 0x20,
    0x3011, 0x00,
    0x304c, 0x85,//85,

    END_FLAG, END_FLAG
};

static const T_U16 QCIF_MODE_TAB[] = {
    //176*144       
    //QXGA->QCIF 
    0x3012, 0x00,
    0x3020, 0x01,
    0x3021, 0x1d,
    0x3022, 0x00,
    0x3023, 0x0a,
    0x3024, 0x08,
    0x3025, 0x18,
    0x3026, 0x06,
    0x3027, 0x0c,
    0x302a, 0x06,
    0x302b, 0x20,
    0x3075, 0x44,
    0x300d, 0x00,
    0x30d7, 0x10,
    0x3069, 0x40,
    0x303e, 0x01,
    0x303f, 0x80,
                 
    0x3302, 0xef,
    0x335f, 0x68,
    0x3360, 0x18,
    0x3361, 0x0c,
    0x3362, 0x00,
    0x3363, 0xb8,
    0x3364, 0x94,
    0x3403, 0x42,
    0x3088, 0x00,
    0x3089, 0xb0,
    0x308a, 0x00,
    0x308b, 0x90,
                 
    0x300e, 0x32,//39,
    0x300f, 0x21,
    0x3010, 0x20,
    0x3011, 0x00,
    0x304c, 0x85,//85,

    END_FLAG, END_FLAG
};

static const T_U16 PREV_MODE_TAB[] = 
{    
//add by xia in 20101203
    0x3100, 0x02,
    0x3301, 0xde,
    0x3304, 0xfc,
    0x3400, 0x00,
    0x3404, 0x02, //00,
    0x3600, 0xc0, //c4,
    //640*480       
    //QXGA->VGA  
    0x3012, 0x00,
    0x3020, 0x01,
    0x3021, 0x1d,
    0x3022, 0x00,
    0x3023, 0x0a,
    0x3024, 0x08,
    0x3025, 0x18,
    0x3026, 0x06,
    0x3027, 0x0c,
    0x302a, 0x06,
    0x302b, 0x20,
    0x3075, 0x44,
    0x300d, 0x00,
    0x30d7, 0x10,
    0x3069, 0x40,
    0x303e, 0x01,
    0x303f, 0x80,
                 
    0x3302, 0xef,
    0x335f, 0x68,
    0x3360, 0x18,
    0x3361, 0x0c,
    0x3362, 0x12,
    0x3363, 0x88,
    0x3364, 0xe4,
    0x3403, 0x42,
    0x3088, 0x02,
    0x3089, 0x80,
    0x308a, 0x01,
    0x308b, 0xe0,
                 
    0x300e, 0x32,//39,
    0x300f, 0x21,
    0x3010, 0x20,
    0x3011, 0x00,
    0x304c, 0x85,//85,
    END_FLAG, END_FLAG
};

static const T_U16 RECORD_MODE_TAB[] = 
{   //352*288       
    //QXGA->CIF  
    0x3012, 0x00,
    0x3020, 0x01,
    0x3021, 0x1d,
    0x3022, 0x00,
    0x3023, 0x0a,
    0x3024, 0x08,
    0x3025, 0x18,
    0x3026, 0x06,
    0x3027, 0x0c,
    0x302a, 0x06,
    0x302b, 0x20,
    0x3075, 0x44,
    0x300d, 0x00,
    0x30d7, 0x10,
    0x3069, 0x40,
    0x303e, 0x01,
    0x303f, 0x80,
                 
    0x3302, 0xef,
    0x335f, 0x68,
    0x3360, 0x18,
    0x3361, 0x0c,
    0x3362, 0x11,
    0x3363, 0x68,
    0x3364, 0x24,
    0x3403, 0x42,
    0x3088, 0x01,
    0x3089, 0x60,
    0x308a, 0x01,
    0x308b, 0x20,
                 
    0x300e, 0x32,//39,
    0x300f, 0x21,
    0x3010, 0x20,
    0x3011, 0x00,
    0x304c, 0x85,//85,
    END_FLAG, END_FLAG
};

static const T_U8 NIGHT_MODE_CAP_TAB[] = 
{
    END_FLAG, END_FLAG
};

/****************   Camera Exposure Table   ****************/
static const T_U8 EXPOSURE_WHOLE_TAB[] = 
{
    END_FLAG, END_FLAG
};

static const T_U8 EXPOSURE_CENTER_TAB[] = 
{
    END_FLAG, END_FLAG
};

static const T_U8 EXPOSURE_MIDDLE_TAB[] = 
{
    END_FLAG, END_FLAG
};

/****************   Camera Brightness Table   ****************/
static const T_U16 BRIGHTNESS_0_TAB[] = 
{//Brightness -3
    0x3302, 0xef,
    0x3355, 0x04,
    0x3354, 0x09,
    0x335e, 0x30,
    
    END_FLAG, END_FLAG
};

static const T_U16 BRIGHTNESS_1_TAB[] = 
{//Brightness -2
    0x3302, 0xef,
    0x3355, 0x04,
    0x3354, 0x09,
    0x335e, 0x20,
    
    END_FLAG, END_FLAG
};

static const T_U16 BRIGHTNESS_2_TAB[] = 
{//Brightness -1
    0x3302, 0xef,
    0x3355, 0x04,
    0x3354, 0x09,
    0x335e, 0x10,
    END_FLAG, END_FLAG
};

static const T_U16 BRIGHTNESS_3_TAB[] = 
{//Brightness 0
    0x3302, 0xef,
    0x3355, 0x04,
    0x3354, 0x01,
    0x335e, 0x00,
    
    END_FLAG, END_FLAG
};

static const T_U16 BRIGHTNESS_4_TAB[] = 
{//Brightness +1
    0x3302, 0xef,
    0x3355, 0x04,
    0x3354, 0x01,
    0x335e, 0x10,
    
    END_FLAG, END_FLAG
};

static const T_U16 BRIGHTNESS_5_TAB[] = 
{//Brightness +2
    0x3302, 0xef,
    0x3355, 0x04,
    0x3354, 0x01,
    0x335e, 0x20,
    
    END_FLAG, END_FLAG
};

static const T_U16 BRIGHTNESS_6_TAB[] = 
{//Brightness +3
    0x3302, 0xef,
    0x3355, 0x04, //bit[2] enable
    0x3354, 0x01, //bit[3] sign of brightness
    0x335e, 0x30,

    END_FLAG, END_FLAG
};

/****************   Camera Contrast Table   ****************/
static const T_U16 CONTRAST_1_TAB[] = 
{//Contrast -3
    0x3302, 0xef,
    0x3355, 0x04,
    0x3354, 0x01,
    0x335c, 0x14,
    0x335d, 0x14,
    
    END_FLAG, END_FLAG
};

static const T_U16 CONTRAST_2_TAB[] = 
{//Contrast -2
    0x3302, 0xef,
    0x3355, 0x04,
    0x3354, 0x01,
    0x335c, 0x18,
    0x335d, 0x18,
    END_FLAG, END_FLAG
};

static const T_U16 CONTRAST_3_TAB[] = 
{//Contrast -1
    0x3302, 0xef,
    0x3355, 0x04,
    0x3354, 0x01,
    0x335c, 0x1c,
    0x335d, 0x1c,
    END_FLAG, END_FLAG
};

static const T_U16 CONTRAST_4_TAB[] = 
{//Contrast 0
    0x3302, 0xef,
    0x3355, 0x04,
    0x3354, 0x01,
    0x335c, 0x20,
    0x335d, 0x20,
    END_FLAG, END_FLAG
};

static const T_U16 CONTRAST_5_TAB[] = 
{//Contrast +1
    0x3302, 0xef,
    0x3355, 0x04,
    0x3354, 0x01,
    0x335c, 0x24,
    0x335d, 0x24,
    END_FLAG, END_FLAG
};

static const T_U16 CONTRAST_6_TAB[] = 
{//Contrast +2
    0x3302, 0xef,
    0x3355, 0x04,
    0x3354, 0x01,
    0x335c, 0x28,
    0x335d, 0x28,
    END_FLAG, END_FLAG
};

static const T_U16 CONTRAST_7_TAB[] = 
{//Contrast +3
    0x3302, 0xef,
    0x3355, 0x04, //bit[2] enable contrast/brightness
    0x3354, 0x01, //bit[2] Yoffset sign
    0x335c, 0x2c,
    0x335d, 0x2c,
    END_FLAG, END_FLAG
};


/****************   Camera Saturation Table   ****************/
static const T_U16 SATURATION_1_TAB[] = 
{//Saturation – 2
    0x3302, 0xef,
    0x3355, 0x02,
    0x3358, 0x20,
    0x3359, 0x20,
    END_FLAG, END_FLAG
};

static const T_U16 SATURATION_2_TAB[] = 
{//Saturation -1
    0x3302, 0xef,
    0x3355, 0x02,
    0x3358, 0x30,
    0x3359, 0x30,
    END_FLAG, END_FLAG
};

static const T_U16 SATURATION_3_TAB[] = 
{//Saturation 0
    0x3302, 0xef,
    0x3355, 0x02,
    0x3358, 0x40,
    0x3359, 0x40,
    END_FLAG, END_FLAG
};

static const T_U16 SATURATION_4_TAB[] = 
{//Saturation + 1
    0x3302, 0xef,
    0x3355, 0x02,
    0x3358, 0x50,
    0x3359, 0x50,
    END_FLAG, END_FLAG
};

static const T_U16 SATURATION_5_TAB[] = 
{//Saturation + 2
    0x3302, 0xef,
    0x3355, 0x02,
    0x3358, 0x50,
    0x3359, 0x50,
    END_FLAG, END_FLAG
};


/****************   Camera Sharpness Table   ****************/
static const T_U16 SHARPNESS_0_TAB[] = 
{
    END_FLAG, END_FLAG
};

static const T_U16 SHARPNESS_1_TAB[] = 
{
    END_FLAG, END_FLAG
};

static const T_U16 SHARPNESS_2_TAB[] = 
{
    END_FLAG, END_FLAG
};

static const T_U16 SHARPNESS_3_TAB[] = 
{
    END_FLAG, END_FLAG
};

static const T_U16 SHARPNESS_4_TAB[] = 
{
    END_FLAG, END_FLAG
};

static const T_U16 SHARPNESS_5_TAB[] = 
{
    END_FLAG, END_FLAG
};

static const T_U16 SHARPNESS_6_TAB[] = 
{
    END_FLAG, END_FLAG
};

/****************   Camera AWB Table   ****************/
static const T_U16 AWB_AUTO_TAB[] = 
{
    0x332b, 0x00,        //AWB auto, bit[3]:0,auto
    END_FLAG, END_FLAG
};

static const T_U16 AWB_SUNNY_TAB[] = 
{
    0x332b, 0x08,        //AWB off
    0x33a7, 0x5e,
    0x33a8, 0x40,
    0x33a9, 0x46,
    END_FLAG, END_FLAG
};

static const T_U16 AWB_CLOUDY_TAB[] = 
{
    0x332b, 0x08,
    0x33a7, 0x68,
    0x33a8, 0x40,
    0x33a9, 0x4e,
    END_FLAG, END_FLAG
};

static const T_U16 AWB_OFFICE_TAB[] = 
{
    0x332b, 0x08,
    0x33a7, 0x52,
    0x33a8, 0x40,
    0x33a9, 0x58,
    END_FLAG, END_FLAG
};

static const T_U16 AWB_HOME_TAB[] =
{
    0x332b, 0x08,
    0x33a7, 0x44,
    0x33a8, 0x40,
    0x33a9, 0x70,
    END_FLAG, END_FLAG
};

static const T_U16 AWB_NIGHT_TAB[] = 
{
    END_FLAG, END_FLAG
//    0x0f, 0x4b,   //这个参数会导致蓝线,和帧率不会改变
};

/****************   Camera Mirror Table   ****************/
static const T_U16 MIRROR_V_TAB[] =     
{
    //flip
    0x307c, 0x11,  //flip               
    0x3090, 0xc0,                       
    END_FLAG, END_FLAG                
};

static const T_U16 MIRROR_H_TAB[] =     
{
    //mirror
    0x307c, 0x12,  //mirror             
    0x3090, 0xc8,                       
    //0x3023, 0x0a,                     
    END_FLAG, END_FLAG                 
};

static const T_U16 MIRROR_NORMAL_TAB[] =
{
    //no mirror/flip
    0x307c, 0x10, //no mirror/flip      
    0x3090, 0xc0,                       
    //0x3023, 0x0a,                     
    END_FLAG, END_FLAG             
};

static const T_U16 MIRROR_FLIP_TAB[] =  
{
    //flip/mirror
    0x307c, 0x13, //flip/mirror         
    0x3090, 0xc8,                       
    END_FLAG, END_FLAG                 
};

/****************   Camera Effect Table   ****************/
static const T_U16 EFFECT_NORMAL_TAB[] = 
{
    0x3302, 0xef,
    0x3355, 0x00,
    END_FLAG, END_FLAG
};

static const T_U16 EFFECT_SEPIA_TAB[] = 
{
    0x3302, 0xef,
    0x3355, 0x18,
    0x335a, 0x40,
    0x335b, 0xa6,
    END_FLAG, END_FLAG
};

static const T_U16 EFFECT_ANTIQUE_TAB[] = 
{
    END_FLAG, END_FLAG
};
static const T_U16 EFFECT_BLUISH_TAB[] =
{
    0x3302, 0xef,
    0x3355, 0x18,
    0x335a, 0xa0,
    0x335b, 0x40,
    END_FLAG, END_FLAG
};

static const T_U16 EFFECT_GREENISH_TAB[] = 
{
    0x3302, 0xef,
    0x3355, 0x18,
    0x335a, 0x60,
    0x335b, 0x60,
    END_FLAG, END_FLAG
};

static const T_U16 EFFECT_REDDISH_TAB[] = 
{
    0x3302, 0xef,
    0x3355, 0x18,
    0x335a, 0x80,
    0x335b, 0xc0,
    END_FLAG, END_FLAG
};

static const T_U16 EFFECT_YELLOWDISH_TAB[] = 
{
    0x3302, 0xef,
    0x3355, 0x18,
    0x335a, 0x30,
    0x335b, 0x90,
    END_FLAG, END_FLAG
};

static const T_U16 EFFECT_NEGATIVE_TAB[] = 
{
    0x3302, 0xef,
    0x3355, 0x40, //bit[6] negative
    END_FLAG, END_FLAG
};

static const T_U16 EFFECT_BW_TAB[] = 
{
    0x3302, 0xef,
    0x3355, 0x18, //bit[4]fix u enable, bit[3]fix v enable
    0x335a, 0x80,
    0x335b, 0x80,
    END_FLAG, END_FLAG
};

static const T_U16 EFFECT_BWN_TAB[] = 
{
      0x3302, 0xef,                  
      0x3355, 0x40, //bit[6] negative

      END_FLAG, END_FLAG
};
static const T_U16 EFFECT_AQUA_TAB[] = 
{        
      END_FLAG, END_FLAG
};

/****************   Camera night/day mode   ****************/
static const T_U16 NIGHT_MODE_TAB[] = 
{
    //14.28fps
    0x300e, 0x32,
    0x3011, 0x00,
    0x3010, 0x20,
    0x302a, 0x03,
    0x302b, 0x92, //add 130 line
    0x302c, 0x00,
    0x3014, 0x04,
    0x302e, 0x00,
    0x302d, 0x00,
    0x3015, 0x42,
    END_FLAG, END_FLAG
};

static const T_U16 DAY_MODE_TAB[] = 
{
    0x300e, 0x32,
    0x3011, 0x00,    
    0x3010, 0x20,
    0x302a, 0x03,
    0x302b, 0x10,
    0x302c, 0x00,
    0x3014, 0x04,
    0x302e, 0x00,
    0x302d, 0x00,
    0x3015, 0x12, //8x
    END_FLAG, END_FLAG
};

#endif
#endif

