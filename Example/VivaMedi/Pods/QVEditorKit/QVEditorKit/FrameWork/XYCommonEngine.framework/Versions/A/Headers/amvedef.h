/*
 * File Name:	amvedef.h					
 *
 * Reference:
 *
 * Description: This file define the structs and consts App will use.
 * 
 * History:	
 *
 * CodeReview Log:
 * 
 */

#ifndef _AMVE_DEF_H_
#define _AMVE_DEF_H_

#include "amcomdef.h"
#include "amdisplay.h"
#include "amimageprocess.h"


#ifndef AMVE_MAXPATH
	#if defined (_LINUX_) || (__IPHONE__)
		#define AMVE_MAXPATH 1024
	#elif defined(_WINCE_)
		#define AMVE_MAXPATH 260
	#else
		#define AMVE_MAXPATH 256
	#endif //(_LINUX_)
#endif	//AMVE_MAXPATH


// Constants are used to identify the session type.
//Unknown session.
#define AMVE_UNKNOWN                                   0X00000000
//Player session.
#define AMVE_PLAYER                                    0X91040200
//Producer session.
#define AMVE_PRODUCER                                  0X91080200
//Storyboard session
#define AMVE_STORYBOARD                                0X91080300
//SlideShow session
#define AMVE_SLIDESHOW								   0X91080400
//Audio Provider session
#define AMVE_AUDIOPROVIDER                             0X91080500

//Constants used to identify the property for session context
#define AMVE_PROP_CONTEXT_BASE                         0X00000000
#define AMVE_PROP_CONTEXT_TEMP_PATH                    (AMVE_PROP_CONTEXT_BASE+1)
#define AMVE_PROP_CONTEXT_DEFAULT_OUTPUT_VIDEO_FORMAT  (AMVE_PROP_CONTEXT_BASE+2)
#define AMVE_PROP_CONTEXT_DEFAULT_OUTPUT_AUDIO_FORMAT  (AMVE_PROP_CONTEXT_BASE+3)
#define AMVE_PROP_CONTEXT_DEFAULT_OUTPUT_FILE_FORMAT   (AMVE_PROP_CONTEXT_BASE+4)
#define AMVE_PROP_CONTEXT_DEFAULT_RESAMPLE_MODE        (AMVE_PROP_CONTEXT_BASE+5)
#define AMVE_PROP_CONTEXT_DEFAULT_PLAYBACK_VOLUME      (AMVE_PROP_CONTEXT_BASE+6)
#define AMVE_PROP_CONTEXT_DEFAULT_PLAYBACK_MUTE		   (AMVE_PROP_CONTEXT_BASE+7)
#define AMVE_PROP_CONTEXT_USER_BUBBLETEXT_CALLBACK	   (AMVE_PROP_CONTEXT_BASE+8)
#define AMVE_PROP_CONTEXT_MAX_SUPPORT_RESOLUTION	   (AMVE_PROP_CONTEXT_BASE+9)
#define AMVE_PROP_CONTEXT_TEMPLATE_PATH				   (AMVE_PROP_CONTEXT_BASE+10)
//#define AMVE_PROP_CONTEXT_TRANSITION_PATH			   (AMVE_PROP_CONTEXT_BASE+11)
//#define AMVE_PROP_CONTEXT_TEXT_FRAME_PATH			   (AMVE_PROP_CONTEXT_BASE+12)
//#define AMVE_PROP_CONTEXT_IMAGE_EFFECT_PATH			   (AMVE_PROP_CONTEXT_BASE+13)	
//#define AMVE_PROP_CONTEXT_COVER_PATH                   (AMVE_PROP_CONTEXT_BASE+14)
#define AMVE_PROP_CONTEXT_STATIC_DURATION			   (AMVE_PROP_CONTEXT_BASE+19)
#define AMVE_PROP_CONTEXT_DEFAULT_TRIM_TYPE			   (AMVE_PROP_CONTEXT_BASE+20)
//#define AMVE_PROP_CONTEXT_DEFAULT_PREVIEW_SKIP_TRANSITION (AMVE_PROP_CONTEXT_BASE+21)
//#define AMVE_PROP_CONTEXT_FRAME_LAYER_VIEWS			   (AMVE_PROP_CONTEXT_BASE+22)
#define AMVE_PROP_CONTEXT_HW_READER_PP_MULTI_THREAD	   (AMVE_PROP_CONTEXT_BASE+23)
#define AMVE_PROP_CONTEXT_PP_PROCESS_TYPE			   (AMVE_PROP_CONTEXT_BASE+24)
#define AMVE_PROP_CONTEXT_TEMPLATE_ADAPTER			   (AMVE_PROP_CONTEXT_BASE+25)
#define AMVE_PROP_CONTEXT_HW_READER_LIB_PATH           (AMVE_PROP_CONTEXT_BASE+26)
#define AMVE_PROP_CONTEXT_HW_WRITER_LIB_PATH           (AMVE_PROP_CONTEXT_BASE+27)
#define AMVE_PROP_CONTEXT_FILEPATH_MODIFIER			    (AMVE_PROP_CONTEXT_BASE+28)
#define AMVE_PROP_CONTEXT_TRCFILE_DECRYPTOR				(AMVE_PROP_CONTEXT_BASE+29)
#define AMVE_PROP_CONTEXT_THEME_DEFAULT_MUSIC_TEMPLATE_ID			(AMVE_PROP_CONTEXT_BASE+30)
#define AMVE_PROP_CONTEXT_HWCODEC_QUERY                 (AMVE_PROP_CONTEXT_BASE+31)
#define AMVE_PROP_CONTEXT_APP_CONTEXT                   (AMVE_PROP_CONTEXT_BASE+32)
#define AMVE_PROP_CONTEXT_FONT_FINDER                   (AMVE_PROP_CONTEXT_BASE+33)
#define AMVE_PROP_CONTEXT_TEXT_TRANSFORMER              (AMVE_PROP_CONTEXT_BASE+34)
#define AMVE_PROP_CONTEXT_DEF_IMG_FILE                   (AMVE_PROP_CONTEXT_BASE+35)
#define AMVE_PROP_CONTEXT_RENDER_API                     (AMVE_PROP_CONTEXT_BASE+36)
#define AMVE_PROP_CONTEXT_AR							(AMVE_PROP_CONTEXT_BASE+37) //getValue is *MHandle, setValue is MHandle
#define AMVE_PROP_CONTEXT_HWCODEC_XML_PATH               (AMVE_PROP_CONTEXT_BASE+38)
#define AMVE_PROP_CONTEXT_PLAY_DOWN_SCALE               (AMVE_PROP_CONTEXT_BASE+39)



//Constants used to identify the media type for clip's source
#define AMVE_CLIP_TYPE_BASE                            0X00000000
#define AMVE_VIDEO_CLIP                                (AMVE_CLIP_TYPE_BASE+1)
#define AMVE_IMAGE_CLIP                                (AMVE_CLIP_TYPE_BASE+2)
#define AMVE_AUDIO_CLIP                                (AMVE_CLIP_TYPE_BASE+3)
#define AMVE_SVG_CLIP                                  (AMVE_CLIP_TYPE_BASE+4)
#define AMVE_SWF_CLIP                                  (AMVE_CLIP_TYPE_BASE+5)
#define AMVE_BUBBLETEXT_CLIP                           (AMVE_CLIP_TYPE_BASE+6)
#define AMVE_MPO_CLIP								   (AMVE_CLIP_TYPE_BASE+7)
#define AMVE_SCENE_CLIP								   (AMVE_CLIP_TYPE_BASE+8)
#define AMVE_GIF_CLIP                                  (AMVE_CLIP_TYPE_BASE+9)
#define AMVE_WEBP_CLIP								   (AMVE_CLIP_TYPE_BASE+0xA)
#define AMVE_RAW_VIDEO_CLIP							   (AMVE_CLIP_TYPE_BASE+0xB)

//Constants used to identify the type for effect track type
#define AMVE_EFFECT_TRACK_TYPE_BASE                    0X00000000
#define AMVE_EFFECT_TRACK_TYPE_PRIMAL_VIDEO            (AMVE_EFFECT_TRACK_TYPE_BASE+1)
#define AMVE_EFFECT_TRACK_TYPE_VIDEO                   (AMVE_EFFECT_TRACK_TYPE_BASE+2)
#define AMVE_EFFECT_TRACK_TYPE_AUDIO                   (AMVE_EFFECT_TRACK_TYPE_BASE+3)
#define AMVE_EFFECT_TRACK_TYPE_FREEZE_FRAME            (AMVE_EFFECT_TRACK_TYPE_BASE+4)
#define AMVE_EFFECT_TRACK_TYPE_LYRIC                   (AMVE_EFFECT_TRACK_TYPE_BASE+5)

//Constants used to identify the type for effect
#define AMVE_EFFECT_TYPE_BASE                          0X00000000
#define AMVE_EFFECT_TYPE_VIDEO_IE                      (AMVE_EFFECT_TYPE_BASE+1)
#define AMVE_EFFECT_TYPE_VIDEO_FRAME                   (AMVE_EFFECT_TYPE_BASE+2)
#define AMVE_EFFECT_TYPE_AUDIO_FRAME                   (AMVE_EFFECT_TYPE_BASE+3)
#define AMVE_EFFECT_TYPE_FREEZE_FRAME                  (AMVE_EFFECT_TYPE_BASE+4)
#define AMVE_EFFECT_TYPE_LYRIC                         (AMVE_EFFECT_TYPE_BASE+5)
//#define AMVE_EFFECT_TYPE_VIDEO_SCENE				   (AMVE_EFFECT_TYPE_BASE+4)
//#define AMVE_EFFECT_TYPE_TEXT_FRAME				   (AMVE_EFFECT_TYPE_BASE+5)

//Constants used to identify the property for effect
#define AMVE_PROP_EFFECT_BASE                          0X00001000
#define AMVE_PROP_EFFECT_TYPE						   (AMVE_PROP_EFFECT_BASE+1)
#define AMVE_PROP_EFFECT_RANGE                         (AMVE_PROP_EFFECT_BASE+2)
#define AMVE_PROP_EFFECT_GROUP						   (AMVE_PROP_EFFECT_BASE+3)
#define AMVE_PROP_EFFECT_LAYER						   (AMVE_PROP_EFFECT_BASE+4)
#define AMVE_PROP_EFFECT_USERDATA					   (AMVE_PROP_EFFECT_BASE+5)	
#define AMVE_PROP_EFFECT_VIDEO_REGION_RATIO            (AMVE_PROP_EFFECT_BASE+6)
#define AMVE_PROP_EFFECT_VIDEO_IE_SOURCE               (AMVE_PROP_EFFECT_BASE+7)
#define AMVE_PROP_EFFECT_VIDEO_FRAME_SOURCE            (AMVE_PROP_EFFECT_BASE+8)
#define AMVE_PROP_EFFECT_VIDEO_FRAME_MASK              (AMVE_PROP_EFFECT_BASE+9)
#define AMVE_PROP_EFFECT_VIDEO_FRAME_EFFECT		       (AMVE_PROP_EFFECT_BASE+10)
#define AMVE_PROP_EFFECT_VIDEO_FRAME_TRANSPARENCY      (AMVE_PROP_EFFECT_BASE+11)
#define AMVE_PROP_EFFECT_VIDEO_FRAME_RANGE             (AMVE_PROP_EFFECT_BASE+12)
#define AMVE_PROP_EFFECT_VIDEO_FRAME_FPS               (AMVE_PROP_EFFECT_BASE+13)
#define AMVE_PROP_EFFECT_VIDEO_FRAME_BG_RESOLUTION     (AMVE_PROP_EFFECT_BASE+14)
#define AMVE_PROP_EFFECT_AUDIO_FRAME_SOURCE            (AMVE_PROP_EFFECT_BASE+15)
#define AMVE_PROP_EFFECT_AUDIO_FRAME_RANGE             (AMVE_PROP_EFFECT_BASE+16)
#define AMVE_PROP_EFFECT_AUDIO_FRAME_REPEAT_MODE       (AMVE_PROP_EFFECT_BASE+17)
#define AMVE_PROP_EFFECT_AUDIO_FRAME_MIXPERCENT        (AMVE_PROP_EFFECT_BASE+18)
#define AMVE_PROP_EFFECT_AUDIO_FRAME_ADJUST_DB         (AMVE_PROP_EFFECT_BASE+19)
#define AMVE_PROP_EFFECT_AUDIO_FRAME_FADEIN            (AMVE_PROP_EFFECT_BASE+20)
#define AMVE_PROP_EFFECT_AUDIO_FRAME_FADEOUT           (AMVE_PROP_EFFECT_BASE+21)
#define AMVE_PROP_EFFECT_IS_READ_ONLY				   (AMVE_PROP_EFFECT_BASE+22)
#define AMVE_PROP_EFFECT_ORIGINAL_RANGE				   (AMVE_PROP_EFFECT_BASE+23)
#define AMVE_PROP_EFFECT_VIDEO_IE_CONFIGURE			   (AMVE_PROP_EFFECT_BASE+24)
#define AMVE_PROP_EFFECT_VIDEO_FRAME_ROTATION		   (AMVE_PROP_EFFECT_BASE+25)//单位是角度，而非弧度
#define AMVE_PROP_EFFECT_VIDEO_FRAME_X_FLIP			   (AMVE_PROP_EFFECT_BASE+26)
#define AMVE_PROP_EFFECT_VIDEO_FRAME_Y_FLIP			   (AMVE_PROP_EFFECT_BASE+27)
#define AMVE_PROP_EFFECT_VIDEO_FRAME_TEMPLATE		   (AMVE_PROP_EFFECT_BASE+28)
#define AMVE_PROP_EFFECT_VISIBILITY					   (AMVE_PROP_EFFECT_BASE+29)
#define AMVE_PROP_EFFECT_VIDEO_FRAME_STATIC			   (AMVE_PROP_EFFECT_BASE+30)
#define AMVE_PROP_EFFECT_RTA_ENABLED				   (AMVE_PROP_EFFECT_BASE+31)
#define AMVE_PROP_EFFECT_ADDEDBYTHEME       		   (AMVE_PROP_EFFECT_BASE+32)
#define AMVE_PROP_EFFECT_PROPDATA					   (AMVE_PROP_EFFECT_BASE+33)
//#define AMVE_PROP_EFFECT_THEME_POS_TYPE                (AMVE_PROP_EFFECT_BASE+34)
#define AMVE_PROP_EFFECT_ANIMATE_POINT_OPERATOR        (AMVE_PROP_EFFECT_BASE+35)
#define AMVE_PROP_EFFECT_FRAME_BGSIZE                  (AMVE_PROP_EFFECT_BASE+36)
#define AMVE_PROP_EFFECT_AUDIO_ADDITIONAL_TIME		   (AMVE_PROP_EFFECT_BASE+37)
#define AMVE_PROP_EFFECT_TA_SOURCE_LIST                (AMVE_PROP_EFFECT_BASE+38)
#define AMVE_PROP_EFFECT_PARAM_DATA					   (AMVE_PROP_EFFECT_BASE+39)
#define AMVE_PROP_EFFECT_TA_SOURCE                     (AMVE_PROP_EFFECT_BASE+40)
#define AMVE_PROP_EFFECT_VIEW_ROTATION                 (AMVE_PROP_EFFECT_BASE+41)
#define AMVE_PROP_EFFECT_FACIAL_PASTER_DATA            (AMVE_PROP_EFFECT_BASE+42)
#define AMVE_PROP_EFFECT_AV_SRC						(AMVE_PROP_EFFECT_BASE+43) //AV = Audio Visualization, MTChar*
#define AMVE_PROP_EFFECT_AV_SRC_RANGE				(AMVE_PROP_EFFECT_BASE+44) //AV = Audio Visualization, AMVE_POSTION_RANGE_TYPE
#define AMVE_PROP_EFFECT_AV_SRC_REPEAT				(AMVE_PROP_EFFECT_BASE+45) //AV = Audio Visualization, MBool
#define AMVE_PROP_EFFECT_FACIAL_PASTER_ROTATION        (AMVE_PROP_EFFECT_BASE+46)
#define AMVE_PROP_EFFECT_FACIAL_PASTER_REGION          (AMVE_PROP_EFFECT_BASE+47)
#define AMVE_PROP_EFFECT_SOFTEN_VALUE                  (AMVE_PROP_EFFECT_BASE+48)
#define AMVE_PROP_EFFECT_BRIGHTEN_VALUE                (AMVE_PROP_EFFECT_BASE+49)
#define AMVE_PROP_EFFECT_POSITION_ALIGNMENT            (AMVE_PROP_EFFECT_BASE+50)
#define AMVE_PROP_EFFECT_LANGUAGE_ID                   (AMVE_PROP_EFFECT_BASE+51)
#define AMVE_PROP_EFFECT_AUDIO_FRAME_MUTE              (AMVE_PROP_EFFECT_BASE+52)
#define AMVE_PROP_EFFECT_PASTER_OT_INFO                (AMVE_PROP_EFFECT_BASE+53)
#define AMVE_PROP_EFFECT_IS_OT_SUPPORT                 (AMVE_PROP_EFFECT_BASE+54)
#define AMVE_PROP_EFFECT_OT_RECT                       (AMVE_PROP_EFFECT_BASE+55)
#define AMVE_PROP_EFFECT_OT_COORD_FILE                 (AMVE_PROP_EFFECT_BASE+56)
#define AMVE_PROP_EFFECT_OT_COORD_FILE_FINISHED        (AMVE_PROP_EFFECT_BASE+57)
#define AMVE_PROP_EFFECT_OT_COORD_FILE_HANDLE          (AMVE_PROP_EFFECT_BASE+58)
#define AMVE_PROP_EFFECT_EXPRESSION_INFO               (AMVE_PROP_EFFECT_BASE+59)
#define AMVE_PROP_EFFECT_AUDIO_FRAME_LRC_SOURCE        (AMVE_PROP_EFFECT_BASE+60)
#define AMVE_PROP_EFFECT_AUDIO_FRAME_LRCTMP_ID         (AMVE_PROP_EFFECT_BASE+61)
#define AMVE_PROP_EFFECT_IS_FRAME_MODE                 (AMVE_PROP_EFFECT_BASE+62) 
#define AMVE_PROP_EFFECT_PS_EMITTER_POS_POINT		   (AMVE_PROP_EFFECT_BASE+63) //只设置了单个点
#define AMVE_PROP_EFFECT_PS_EMITTER_POS_END			   (AMVE_PROP_EFFECT_BASE+64) //只是标识一下，是否结束移动
#define AMVE_PROP_EFFECT_PS_EMITTER_POS_LIST		   (AMVE_PROP_EFFECT_BASE+65) //JNI层没开，app应该没用到
#define AMVE_PROP_EFFECT_PS_EMITTER_POS_FOR_RENDER	   (AMVE_PROP_EFFECT_BASE+66)
#define AMVE_PROP_EFFECT_PS_DOODLE_FLAG                (AMVE_PROP_EFFECT_BASE+67)
#define AMVE_PROP_EFFECT_BLEND_ALPHA				   (AMVE_PROP_EFFECT_BASE+68)
#define AMVE_PROP_EFFECT_3D_MATERIAL_LIST              (AMVE_PROP_EFFECT_BASE+69)
#define AMVE_PROP_EFFECT_VIEW_ANGLES                   (AMVE_PROP_EFFECT_BASE+70)
#define AMVE_PROP_EFFECT_VIEW_ANGLES_FLAG              (AMVE_PROP_EFFECT_BASE+71)
#define AMVE_PROP_EFFECT_DST_RATIO                     (AMVE_PROP_EFFECT_BASE+72)
#define AMVE_PROP_EFFECT_FD_RESULT                     (AMVE_PROP_EFFECT_BASE+73)
#define AMVE_PROP_EFFECT_FD_SET_FLAG                   (AMVE_PROP_EFFECT_BASE+74)
#define AMVE_PROP_EFFECT_FRAME_STATIC_PICTURE          (AMVE_PROP_EFFECT_BASE+76)
#define AMVE_PROP_EFFECT_IS_EMPTY_TEMPLATE             (AMVE_PROP_EFFECT_BASE+77)

#define AMVE_PROP_EFFECT_SUB_EFFECT_LIST               (AMVE_PROP_EFFECT_BASE+81)
#define AMVE_PROP_EFFECT_ADJUST_PROP_ID                (AMVE_PROP_EFFECT_BASE+82)
#define AMVE_PROP_VIDEO_FRAME_MULTI_SOURCE             (AMVE_PROP_EFFECT_BASE+89)

#define AMVE_PROP_EFFECT_TRAJECTORY					   (AMVE_PROP_EFFECT_BASE+91)


//#define AVME_PROP_EFFECT_KEYFRAME_SET   				(AMVE_PROP_EFFECT_BASE+100)
#define AVME_PROP_EFFECT_KEYFRAME_CLEAR   				(AMVE_PROP_EFFECT_BASE+101)
#define AVME_PROP_EFFECT_KEYFRAME_TRANSFORM				(AMVE_PROP_EFFECT_BASE+102)
#define AVME_PROP_EFFECT_KEYFRAME_TRANSFORM_SET			(AMVE_PROP_EFFECT_BASE+103)
#define AVME_PROP_EFFECT_KEYFRAME_COLORA				(AMVE_PROP_EFFECT_BASE+104)
#define AVME_PROP_EFFECT_KEYFRAME_COLORA_SET			(AMVE_PROP_EFFECT_BASE+105)

#define AVME_PROP_EFFECT_KEYFRAME_AUDIO				    (AMVE_PROP_EFFECT_BASE+106)
#define AVME_PROP_EFFECT_KEYFRAME_AUDIO_SET				(AMVE_PROP_EFFECT_BASE+107)

#define AVME_PROP_EFFECT_KEYFRAME_LEVEL				    (AMVE_PROP_EFFECT_BASE+108)
#define AVME_PROP_EFFECT_KEYFRAME_LEVEL_SET				(AMVE_PROP_EFFECT_BASE+109)

#define AVME_PROP_EFFECT_KEYFRAME_OPACITY				    (AMVE_PROP_EFFECT_BASE+110)
#define AVME_PROP_EFFECT_KEYFRAME_OPACITY_SET				(AMVE_PROP_EFFECT_BASE+111)

#define AVME_PROP_EFFECT_KEYFRAME_TRANSFORM_ORIGIN_REGION (AMVE_PROP_EFFECT_BASE+112)





/*
 *  audio gain >= 0, to set/get the audio gain. 
 *	the new audio gain will replace the old gain you set
 *	Default is 1.0 from audio head to tail.  The data of this prop is QVET_AUDIO_GAIN
 *	this prop can be change when you are in player, but if there is no more change to audio frame gain, you need to call AMVES_PlayerPerformOperation to perform the changement on audio
 *	AMVE_PROP_EFFECT_AUDIO_GAIN is related to AMVE_PROP_EFFECT_USE_NEW_ADUIO_MIX_MODE
 */
#define AMVE_PROP_EFFECT_AUDIO_GAIN							(AMVE_PROP_EFFECT_BASE+113) //to set/get the gain of audio frame
/*
 * audio frame new mix mode:
 *	src1 audio will be processed with gain set by user, and src2 audio will be processed with gain, and mixed together
 *	the new mix mode need to know the gain which is set by AMVE_PROP_EFFECT_AUDIO_GAIN
 *	data is MBool, true means use new mix mode, false means use the old mix  mode which is related to mix percent
 *	default is false
 *	AMVE_PROP_EFFECT_USE_NEW_ADUIO_MIX_MODE is related to AMVE_PROP_EFFECT_AUDIO_GAIN 
 */
#define AMVE_PROP_EFFECT_USE_NEW_ADUIO_MIX_MODE					(AMVE_PROP_EFFECT_BASE+114) 





//Add freeze frame section
#define AMVE_PROP_EFFECT_FFRAME_BASE                   (AMVE_PROP_EFFECT_BASE + 0xF00)
#define AMVE_PROP_EFFECT_FFRAME_RANGE                  (AMVE_PROP_EFFECT_FFRAME_BASE+1)
#define AMVE_PROP_EFFECT_FFRAME_TYPE                   (AMVE_PROP_EFFECT_FFRAME_BASE+2)
#define AMVE_PROP_EFFECT_FFRAME_SOURCE                 (AMVE_PROP_EFFECT_FFRAME_BASE+3)
#define AMVE_PROP_EFFECT_FFRAME_AUDIO_SOURCE           (AMVE_PROP_EFFECT_FFRAME_BASE+4)
#define AMVE_PROP_EFFECT_FFRAME_AUDIO_RANGE            (AMVE_PROP_EFFECT_FFRAME_BASE+5)
#define AMVE_PROP_EFFECT_FFRAME_SETTING                (AMVE_PROP_EFFECT_FFRAME_BASE+6)
#define AMVE_PROP_EFFECT_FFRAME_ORG_RANGE              (AMVE_PROP_EFFECT_FFRAME_BASE+7)
#define AMVE_PROP_EFFECT_FFRAME_ENABLED                (AMVE_PROP_EFFECT_FFRAME_BASE+8)

//Constants used to identify the property for clip
#define AMVE_PROP_CLIP_BASE                            0X00003000
#define AMVE_PROP_CLIP_TYPE                            (AMVE_PROP_CLIP_BASE+1)
#define AMVE_PROP_CLIP_SOURCE                          (AMVE_PROP_CLIP_BASE+2)
#define AMVE_PROP_CLIP_SOURCE_INFO                     (AMVE_PROP_CLIP_BASE+3)
#define AMVE_PROP_CLIP_TRIM_RANGE	                   (AMVE_PROP_CLIP_BASE+4)
#define AMVE_PROP_CLIP_TIME_SCALE                      (AMVE_PROP_CLIP_BASE+5)
#define AMVE_PROP_CLIP_TRANSITION	                   (AMVE_PROP_CLIP_BASE+6)
#define AMVE_PROP_CLIP_RESAMPLE_MODE                   (AMVE_PROP_CLIP_BASE+7)
#define AMVE_PROP_CLIP_USERDATA						   (AMVE_PROP_CLIP_BASE+8)

#define AMVE_PROP_CLIP_AUDIO_FADEIN                    (AMVE_PROP_CLIP_BASE+9)
#define AMVE_PROP_CLIP_AUDIO_FADEOUT                   (AMVE_PROP_CLIP_BASE+10)
#define AMVE_PROP_CLIP_AUDIO_ADJUSTDB                  (AMVE_PROP_CLIP_BASE+11)
#define AMVE_PROP_CLIP_AUDIO_DISABLED                  (AMVE_PROP_CLIP_BASE+12)
#define AMVE_PROP_CLIP_PRIMAL_AUDIO_DISABLED           (AMVE_PROP_CLIP_BASE+13)

#define AMVE_PROP_CLIP_VIDEO_FADEIN                    (AMVE_PROP_CLIP_BASE+14)
#define AMVE_PROP_CLIP_VIDEO_FADEOUT                   (AMVE_PROP_CLIP_BASE+15)
#define AMVE_PROP_CLIP_VIDEO_DISABLED                  (AMVE_PROP_CLIP_BASE+16)
#define AMVE_PROP_CLIP_PRIMAL_VIDEO_DISABLED           (AMVE_PROP_CLIP_BASE+17)

#define AMVE_PROP_CLIP_BUBBLE_BG_COLOR                 (AMVE_PROP_CLIP_BASE+18)
#define AMVE_PROP_CLIP_BUBBLE_VER_REVERSAL             (AMVE_PROP_CLIP_BASE+19)
#define AMVE_PROP_CLIP_BUBBLE_HOR_REVERSAL             (AMVE_PROP_CLIP_BASE+20)
#define AMVE_PROP_CLIP_BUBBLE_ROTATE_ANGLE			   (AMVE_PROP_CLIP_BASE+21)
#define AMVE_PROP_CLIP_BUBBLE_ROTATE_CENTER			   (AMVE_PROP_CLIP_BASE+22)
#define AMVE_PROP_CLIP_BUBBLE_REGION_RATIO			   (AMVE_PROP_CLIP_BASE+23)
#define AMVE_PROP_CLIP_BUBBLE_TRANSPARENCY			   (AMVE_PROP_CLIP_BASE+24)
#define AMVE_PROP_CLIP_COVER_TYPE                      (AMVE_PROP_CLIP_BASE+25)
#define AMVE_PROP_CLIP_CROP_REGION		  			   (AMVE_PROP_CLIP_BASE+26)
#define AMVE_PROP_CLIP_ROTATION		                   (AMVE_PROP_CLIP_BASE+27)
#define AMVE_PROP_CLIP_BUBBLE_TEXT_COLOR               (AMVE_PROP_CLIP_BASE+28)
#define AMVE_PROP_CLIP_IMAGE_DURATION				   (AMVE_PROP_CLIP_BASE+29)
#define AMVE_PROP_CLIP_SRC_RANGE					   (AMVE_PROP_CLIP_BASE+30)
#define AMVE_PROP_CLIP_AUDIO_MIX_PERCENT			   (AMVE_PROP_CLIP_BASE+31)
#define AMVE_PROP_CLIP_FILE_MISSING					   (AMVE_PROP_CLIP_BASE+32)
#define AMVE_PROP_CLIP_PANZOOM_DISABLED				   (AMVE_PROP_CLIP_BASE+33)
#define AMVE_PROP_CLIP_USE_SURFACETEXTURE			   (AMVE_PROP_CLIP_BASE+34)
#define AMVE_PROP_CLIP_SINGLE_FRAME_PARAM			   (AMVE_PROP_CLIP_BASE+35)
#define AMVE_PROP_CLIP_VIDEO_INTERLACE                 (AMVE_PROP_CLIP_BASE+36)
#define AMVE_PROP_CLIP_IS_REVERSE_MODE                 (AMVE_PROP_CLIP_BASE+37)
#define AMVE_PROP_CLIP_IS_REVERSE_CLIP                 (AMVE_PROP_CLIP_BASE+38)
#define AMVE_PROP_CLIP_RVERSE_SOURCE                   (AMVE_PROP_CLIP_BASE+39)
#define AMVE_PROP_CLIP_ALPHA_NEED_PREMULTI             (AMVE_PROP_CLIP_BASE+40)
#define AMVE_PROP_CLIP_REMOVE_TRACK_INDENTIFIER        (AMVE_PROP_CLIP_BASE+41)
#define AMVE_PROP_CLIP_LANGUAGE_ID                     (AMVE_PROP_CLIP_BASE+42)



/**
 *  AMVE_PROP_CLIP_AUDIO_PITCH_DELTA
 *  The object set with this property should be the type of MFloat</br>
 *	if value > 0, the audio will sounds like women, more bigger more like women</br>
 *  if value < 0, the audio will sounds like men, more smaller more like a men</br>
 *  if value = 0, it's same with the original sound, no-pitch changed</br>
 *  The available value is [-60, 60]
 *  You can also use the suggetingvalue defined as AUDIO_PITCH_DELTA_VALUE_WOMAN_STYLE and AUDIO_PITCH_DELTA_VALUE_MEN_STYLE
 */
#define AMVE_PROP_CLIP_AUDIO_PITCH_DELTA			 (AMVE_PROP_CLIP_BASE+43)	//used to modify the audio pitch of clip
/**
 *  AMVE_PROP_CLIP_AUDIO_MODIFY_BY_ASP
 *  Backgroud:</br>
 * 	Modify Audio Style(such as tempo, pitch, etc) by ASP Module is a new feature added. 
 *  Before Adding the ASP module, engine use a simple processing method.</br>
 *  Now, engine has both process for your selection. The old-simple processing method is the default.
 *  So if you want to active the ASP Module to process the audio style modification, you need to set this property to clip</br>
 *  The property value is int the form of MBool
 */
#define AMVE_PROP_CLIP_AUDIO_MODIFY_BY_ASP			 (AMVE_PROP_CLIP_BASE+44) //if use asp module to modify audio PCM


#define AMVE_PROP_CLIP_SCENE_DURATION                  (AMVE_PROP_CLIP_BASE+45)
#define AMVE_PROP_CLIP_SCENE_TIME_INFO                 (AMVE_PROP_CLIP_BASE+46)
#define AMVE_PROP_CLIP_AVPD_AUDIO_SRC				   (AMVE_PROP_CLIP_BASE+47) //AVPD=AV Parameter Demonstrator
#define AMVE_PROP_CLIP_LYRIC_ENABLE                    (AMVE_PROP_CLIP_BASE+48)
#define AMVE_PROP_CLIP_IS_FRAME_MODE                   (AMVE_PROP_CLIP_BASE+49)
#define AMVE_PROP_CLIP_WATERMARK_CACHED                (AMVE_PROP_CLIP_BASE+50)
#define AMVE_PROP_CLIP_REVERSE_TRIM_MDOE               (AMVE_PROP_CLIP_BASE+51)
#define AMVE_PROP_CLIP_REVERSE_TRIM_RANGE              (AMVE_PROP_CLIP_BASE+52)
#define AMVE_PROP_CLIP_MEDIA_DURATION                  (AMVE_PROP_CLIP_BASE+53)
#define AMVE_PROP_CLIP_CAM_EXPORT_EFFECT_LIST          (AMVE_PROP_CLIP_BASE+54)
#define AMVE_PROP_CLIP_FLIP                            (AMVE_PROP_CLIP_BASE+55) //设置clip 镜像,AMVE_X_FLIP_MASK,AMVE_Y_FLIP_MASK



/*
 *  audio gain >= 0, to set/get the audio gain. 
 *	the new audio gain will replace the old gain you set 
 *	Default is 1.0 from audio head to tail. The data of this prop is QVET_AUDIO_GAIN
 *	this prop can be change when you are in player,  If there is no more change to clip audio gain, you need to call AMVES_PlayerPerformOperation to perform the changement on audio
 */
#define AMVE_PROP_CLIP_AUDIO_GAIN						 (AMVE_PROP_CLIP_BASE+59)

//constants used to identify the property for storyboard
#define AMVE_PROP_STORYBOARD_BASE                      0X00004000
#define AMVE_PROP_STORYBOARD_FIT_TRACK                 (AMVE_PROP_STORYBOARD_BASE+1)
//#define AMVE_PROP_STORYBOARD_3D_OUTPUT				   (AMVE_PROP_STORYBOARD_BASE+2)
#define AMVE_PROP_STORYBOARD_AUTO_APPLY_THEME		   (AMVE_PROP_STORYBOARD_BASE+3)
#define AMVE_PROP_STORYBOARD_THEME_OPERATE_CALLBACK	   (AMVE_PROP_STORYBOARD_BASE+4)
//#define AMVE_PROP_STORYBOARD_COVER					   (AMVE_PROP_STORYBOARD_BASE+5)
//#define AMVE_PROP_STORYBOARD_BACK_COVER				   (AMVE_PROP_STORYBOARD_BASE+6)
#define AMVE_PROP_STORYBOARD_THEME_TEMPLATE			   (AMVE_PROP_STORYBOARD_BASE+7)
#define AMVE_PROP_STORYBOARD_THEME_COVER			   (AMVE_PROP_STORYBOARD_BASE+8)
#define AMVE_PROP_STORYBOARD_THEME_BACK_COVER		   (AMVE_PROP_STORYBOARD_BASE+9)
#define AMVE_PROP_STORYBOARD_THEME_ID				   (AMVE_PROP_STORYBOARD_BASE+10)
#define AMVE_PROP_STORYBOARD_OUTPUT_RESOLUTION		   (AMVE_PROP_STORYBOARD_BASE+11)
#define AMVE_PROP_STORYBOARD_ORIGINAL_DURATION		   (AMVE_PROP_STORYBOARD_BASE+12)
#define AMVE_PROP_STORYBOARD_SCENECLIP_DATAPROVIDER	   (AMVE_PROP_STORYBOARD_BASE+13)
#define AMVE_PROP_STORYBOARD_FORCE_STATIC_TRANS        (AMVE_PROP_STORYBOARD_BASE+14)
#define AMVE_PROP_STORYBOARD_SINGLE_HW_INSTANCE        (AMVE_PROP_STORYBOARD_BASE+15)
#define AMVE_PROP_STORYBOARD_RATIO_SETTED              (AMVE_PROP_STORYBOARD_BASE+16)
#define AMVE_PROP_STORYBOARD_RESET_THEME_ELEM          (AMVE_PROP_STORYBOARD_BASE+17)


//constants used to identify the property for SlideShow
#define AMVE_PROP_SLIDESHOW_BASE                       0X00005000
#define AMVE_PROP_SLIDESHOW_SEQUENCE                   (AMVE_PROP_SLIDESHOW_BASE+1)
#define AMVE_PROP_SLIDESHOW_RESOLUTION                 (AMVE_PROP_SLIDESHOW_BASE+2)
#define AMVE_PROP_SLIDESHOW_CLIP_RESAMPLE_MODE         (AMVE_PROP_SLIDESHOW_BASE+3)
#define AMVE_PROP_SLIDESHOW_OUTPUT_RESOLUTION          (AMVE_PROP_SLIDESHOW_BASE+4)
#define AMVE_PROP_SLIDESHOW_SCENE_RESOLUTION           (AMVE_PROP_SLIDESHOW_BASE+5)
#define AMVE_PROP_SLIDESHOW_MUSIC_FADEIN	           (AMVE_PROP_SLIDESHOW_BASE+6)
#define AMVE_PROP_SLIDESHOW_MUSIC_FADEOUT              (AMVE_PROP_SLIDESHOW_BASE+7)
#define AMVE_PROP_SLIDESHOW_CLIP_TAINFO_LIST           (AMVE_PROP_SLIDESHOW_BASE+8)
#define AMVE_PROP_SLIDESHOW_LANGUAGE_ID                (AMVE_PROP_SLIDESHOW_BASE+9)
#define AMVE_PROP_SLIDESHOW_DEC_USE_TYPE               (AMVE_PROP_SLIDESHOW_BASE+10)
#define AMVE_PROP_SLIDESHOW_AUDIO_MIX_PERCENT          (AMVE_PROP_SLIDESHOW_BASE+11)
#define AMVE_PROP_SLIDESHOW_LYRIC_ENABLE               (AMVE_PROP_SLIDESHOW_BASE+12)
#define AMVE_PROP_SLIDESHOW_LRC_FILE                   (AMVE_PROP_SLIDESHOW_BASE+13)
#define AMVE_PROP_SLIDESHOW_LRCTMP_ID                  (AMVE_PROP_SLIDESHOW_BASE+14)

//constants used to identify the property for producer
#define AMVE_PROP_PRODUCER_BASE						   0X00006000
#define AMVE_PROP_PRODUCER_PARAM	                   (AMVE_PROP_PRODUCER_BASE+1)
#define AMVE_PROP_PRODUCER_REVERSE	                   (AMVE_PROP_PRODUCER_BASE+2)
#define AMVE_PROP_PRODUCER_EXP_LEN                     (AMVE_PROP_PRODUCER_BASE+3)
#define AMVE_PROP_PRODUCER_USE_GIF_ENCODER             (AMVE_PROP_PRODUCER_BASE+4)
#define AMVE_PROP_PRODUCER_CB_INTERVAL                 (AMVE_PROP_PRODUCER_BASE+5)
#define AMVE_PROP_PRODUCER_ERR_INFO                    (AMVE_PROP_PRODUCER_BASE+6)
#define AMVE_PROP_PRODUCER_EXPORT_VIDEO_SIZE           (AMVE_PROP_PRODUCER_BASE+7)
#define AMVE_PROP_PRODUCER_USE_INPUT_FILE_NAME         (AMVE_PROP_PRODUCER_BASE+8)


//constants used to identify the property for auto editor
#define AMVE_PROP_AUTOCUT_BASE						   0X00007000


//constants used to identify the property for player
#define AMVE_PROP_PLAYER_BASE						   0X00008000
#define AMVE_PROP_PLAYER_RANGE						   (AMVE_PROP_PLAYER_BASE+1)	
#define AMVE_PROP_PLAYER_SEEK_DIR					   (AMVE_PROP_PLAYER_BASE+2)
#define AMVE_PROP_PLAYER_FINISH_OPENGL                 (AMVE_PROP_PLAYER_BASE+3)
#define AMVE_PROP_PLAYER_PREVIEW_FPS	               (AMVE_PROP_PLAYER_BASE+4)
#define AMVE_PROP_PLAYER_VIDEO_PLAYED_TIMESTAMP        (AMVE_PROP_PLAYER_BASE+5)
#define AMVE_PROP_PLAYER_STREAM_FRAME_SIZE             (AMVE_PROP_PLAYER_BASE+6)



#define AMVE_PROP_AUDIO_PROVIDER_BASE                  0X00009000
#define AMVE_PROP_AP_AUDIO_INFO                        (AMVE_PROP_AUDIO_PROVIDER_BASE+1)
#define AMVE_PROP_AP_AUDIO_RANGE                       (AMVE_PROP_AUDIO_PROVIDER_BASE+2)
#define AMVE_PROP_AP_AUDIO_OBSERVER_CALLBACK           (AMVE_PROP_AUDIO_PROVIDER_BASE+3)
#define AMVE_PROP_AP_AUDIO_OBSERVER_DATA               (AMVE_PROP_AUDIO_PROVIDER_BASE+4)

/**
 * AUDIO_PITCH_DELTA_VALUE_XXX
 *  It's a suggesting value of audio-pitch-delta when you set the AMVE_PROP_CLIP_AUDIO_PITCH_DELTA
 */
#define AUDIO_PITCH_DELTA_VALUE_WOMAN_STYLE             (4.0)
#define AUDIO_PITCH_DELTA_VALUE_MEN_STYLE               (-7.0)


//constants used to identify the playback mode
#define AMVE_PLAYBACKMODE_NORMAL                       0X00000000
#define AMVE_PLAYBACKMODE_FF2X                         0X00000001
#define AMVE_PLAYBACKMODE_FF4X                         0X00000002
#define AMVE_PLAYBACKMODE_SF2X                         0X00000003
#define AMVE_PLAYBACKMODE_SF4X                         0X00000004
#define AMVE_PLAYBACKMODE_I_FRAME                      0X00000005

//constants used to identify the playback status
#define AMVE_SESSION_STATUS_NONE                       0X00000000
#define AMVE_SESSION_STATUS_READY                      0X00000001
#define AMVE_SESSION_STATUS_RUNNING                    0X00000002
#define AMVE_SESSION_STATUS_PAUSED                     0X00000003
#define AMVE_SESSION_STATUS_STOPPED                    0X00000004
#define AMVE_SESSION_STATUS_INITIALIZING               0X00000005

//constants used to identify the file format
#define AMVE_FILEFORMAT_UNKNOWN                        0X00000000
#define AMVE_FILEFORMAT_MP4                            0X00000001
#define AMVE_FILEFORMAT_3GP                            0X00000002
#define AMVE_FILEFORMAT_3G2                            0X00000003
#define AMVE_FILEFORMAT_M4A                            0X00000004
#define AMVE_FILEFORMAT_AMR                            0X00000005
#define AMVE_FILEFORMAT_AAC                            0X00000006
#define AMVE_FILEFORMAT_QCP                            0X00000007
#define AMVE_FILEFORMAT_SKM                            0X00000008
#define AMVE_FILEFORMAT_AVI                            0X00000009
#define AMVE_FILEFORMAT_WMA							   0X0000000A
#define AMVE_FILEFORMAT_WMV							   0X0000000B
#define AMVE_FILEFORMAT_ASF							   0X0000000C
#define AMVE_FILEFORMAT_K3G							   0X0000000D
#define AMVE_FILEFORMAT_MP3							   0X0000000E
#define AMVE_FILEFORMAT_MOV							   0X0000000F
#define AMVE_FILEFORMAT_M4V                            0x00000010
#define AMVE_FILEFORMAT_RAWVIDEO					   0x00000011
#define AMVE_FILEFORMAT_GIF                            0x00000012

//constants used to identify the video codec
#define AMVE_VIDEOFORMAT_NONE                          0X00000000
#define AMVE_VIDEOFORMAT_UNKNOWN                       0X00000001
#define AMVE_VIDEOFORMAT_MPEG4                         0X00000002
#define AMVE_VIDEOFORMAT_H263                          0X00000003
#define AMVE_VIDEOFORMAT_H264                          0X00000004
#define AMVE_VIDEOFORMAT_DX50                          0X00000005
#define AMVE_VIDEOFORMAT_WMV						   0X00000006
#define AMVE_VIDEOFORMAT_XVID						   0X00000007
#define AMVE_VIDEOFORMAT_DIVX						   0X00000008
#define AMVE_VIDEOFORMAT_I420						   0X00000009
#define AMVE_VIDEOFORMAT_GIF						   0X0000000a
#define AMVE_VIDEOFORMAT_M4A						   0X0000000b
#define AMVE_VIDEOFORMAT_H265                          0X0000000c
#define AMVE_VIDEOFORMAT_AUTO                          AMVE_VIDEOFORMAT_UNKNOWN

//constants used to identify the audio codec
#define AMVE_AUDIOFORMAT_NONE                          0X00000000
#define AMVE_AUDIOFORMAT_UNKNOWN                       0X00000001
#define AMVE_AUDIOFORMAT_AMRNB                         0X00000002
#define AMVE_AUDIOFORMAT_QCELP                         0X00000003
#define AMVE_AUDIOFORMAT_AACLC                         0X00000004
#define AMVE_AUDIOFORMAT_EVRC                          0X00000005
#define AMVE_AUDIOFORMAT_MP3                           0X00000006
#define AMVE_AUDIOFORMAT_AMRWB                         0X00000007
#define AMVE_AUDIOFORMAT_WMA_V1						   0X00000008
#define AMVE_AUDIOFORMAT_WMA_V2						   0X00000009
#define AMVE_AUDIOFORMAT_WMA_9PRO					   0X0000000A
#define AMVE_AUDIOFORMAT_WMA_9LOS					   0X0000000B
#define AMVE_AUDIOFORMAT_AAC_HE						   0X0000000C
#define AMVE_AUDIOFORMAT_AAC_HE_V2					   0X0000000D
#define AMVE_AUDIOFORMAT_PCM                           0x0000000E
#define AMVE_AUDIOFORMAT_AUTO                          AMVE_AUDIOFORMAT_UNKNOWN

//constants used to identify the track type
#define AMVE_TRACK_TYPE_VIDEO                          0X00000000
#define AMVE_TRACK_TYPE_AUDIO                          0X00000001

//constants used to identify the source type
#define AMVE_MEDIA_SOURCE_TYPE_FILE                    0X00000000
#define AMVE_MEDIA_SOURCE_TYPE_BITMAP                  0X00000001
#define AMVE_MEDIA_SOURCE_TYPE_BUBBLETEXT              0x00000002 //字幕effect对应的source,数据结构AMVE_BUBBLETEXT_SOURCE_TYPE
                                                                  //动画字幕为了方便APP操作，同时也兼容了这个类型
                      
#define AMVE_MEDIA_SOURCE_TYPE_PKG_FILE				   0x00000003
#define AMVE_MEDIA_SOURCE_TYPE_TRC_LYRICS			   0x00000004 //TRC 是一种第三方提供的歌词，有其特定的格式
#define AMVE_MEDIA_SOURCE_TYPE_CAMERA				   0x00000005 //这个结构只在pip frame picker时会用到
#define AMVE_MEDIA_SOURCE_TYPE_WATERMARK			   0x00000006 //水印Source格式
#define AMVE_MEDIA_SOURCE_TYPE_TEXT_ANIMATION          0x00000007 //动画字幕对应的source,数据类型为AMVE_TEXTANIMATION_SOURCE_TYPE

//constants used to identify display rotation
#define AMVE_DISPLAY_ROTATION_NONE                     0
#define AMVE_DISPLAY_ROTATION_90                       90
#define AMVE_DISPLAY_ROTATION_180                      180
#define AMVE_DISPLAY_ROTATION_270                      270

//constants used to identify display orientation
#define AMVE_DISPLAY_ORIENTATION_NORMAL	               0x00000000
#define AMVE_DISPLAY_ORIENTATION_LEFT_HANDED           0x00000001
#define AMVE_DISPLAY_ORIENTATION_RIGHT_HANDED          0x00000002
#define AMVE_DISPLAY_ORIENTATION_REVERSAL              0x00000003

//constants used to identify stream source type
#define AMVE_STREAM_SOURCE_TYPE_STORYBOARD             0x00000001
#define AMVE_STREAM_SOURCE_TYPE_CLIP                   0x00000002
#define AMVE_STREAM_SOURCE_TYPE_STORYBOARD_ORIGINAL	   0x00000003

//constants used to identify the resample mode
#define AMVE_RESAMPLE_MODE_NONE						   0x00000000
#define AMVE_RESAMPLE_MODE_FITIN                       0x00000001
#define AMVE_RESAMPLE_MODE_FITOUT                      0x00000002
#define AMVE_RESAMPLE_MODE_FILL                        0x00000003
#define AMVE_RESAMPLE_MODE_UPSCALE_FITIN               0x00010001
#define AMVE_RESAMPLE_MODE_UPSCALE_FITOUT              0x00010002

//constants used to identify un-support reasons
#define AMVE_UNSUPPORT_NONE							   0x00000000		// Supported
#define AMVE_UNSUPPORT_FILE							   0x00000001		// Other case
#define AMVE_UNSUPPORT_RESOLUTION					   0x00000002		// Unsupport resolution	
#define AMVE_UNSUPPORT_VCODEC						   0x00000003		// Unsupport video codec
#define AMVE_UNSUPPORT_ACODEC						   0x00000004		// Unsupport audio codec
#define AMVE_UNSUPPORT_IMAGECODEC					   0x00000005		// Unsupport image codec
#define AMVE_UNSUPPORT_NOVIDEO						   0x00000006		// No video track
#define AMVE_UNSUPPORT_NOAUDIO						   0x00000007		// No audio track
#define AMVE_UNSUPPORT_MPEG4_HEADER					   0x00000008		// Unsupport mpeg4 header
#define AMVE_UNSUPPORT_UNSEEKABLE					   0x00000009		// Unseekable file
#define AMVE_UNSUPPORT_H264_HEADER					   0x0000000A		// Unsupport h264 header

//constants used to identify editable check type
#define AMVE_CHECK_BASE								   0x00000000
#define AMVE_CHECK_AUDIO							   0x00000001		// Check audio
#define AMVE_CHECK_NO_AUDIO_TRACK					   0x00000002		// If set this flag, video with no audio track will be determined to be editable
#define AMVE_CHECK_VIDEO							   0x00010000		// Check video
#define AMVE_CHECK_ALLOW_UNSEEKABLE					   0X00020000		// If set this flag, video/audio that is not seekable will be determined to be editable

//constants used to identify repeat mode of audio frame
#define AMVE_AUDIO_FRAME_MODE_NORMAL				   0x00000000
#define AMVE_AUDIO_FRAME_MODE_REPEAT				   0x00000001
#define AMVE_AUDIO_FRAME_MODE_ALIGN_LEFT			   0x00000002
#define AMVE_AUDIO_FRAME_MODE_ALIGN_RIGHT			   0x00000003

/*
*	Comments added by jgong@2012.11.29
*	QVET_THEME_OP_TYPE_XXXXXX 分两种:
*	1. 既有 状态通知 又有 数据交互的
*			QVET_THEME_OP_TYPE_REMOVE_COVER
*			QVET_THEME_OP_TYPE_ADD_COVER
*			QVET_THEME_OP_TYPE_ADD_TEXT
*	2. 只有状态通知的(除了第一点提到的其他OP)
*/
#define QVET_THEME_OP_TYPE_ADD_EFFECT				   0x00000001
#define QVET_THEME_OP_TYPE_REMOVE_EFFECT			   0x00000002
#define QVET_THEME_OP_TYPE_ADD_TRANSITION			   0x00000003
#define QVET_THEME_OP_TYPE_REMOVE_TRANSITION		   0x00000004	
#define QVET_THEME_OP_TYPE_REMOVE_COVER				   0x00000005
#define QVET_THEME_OP_TYPE_ADD_COVER				   0x00000006   
#define QVET_THEME_OP_TYPE_ADD_TEXT					   0x00000007
#define QVET_THEME_OP_TYPE_REMOVE_TEXT				   0x00000008
#define QVET_THEME_OP_TYPE_ADD_MUSIC				   0x00000009
#define QVET_THEME_OP_TYPE_REMOVE_MUSIC				   0x0000000A
#define QVET_THEME_OP_TYPE_ADD_FX					   0x0000000B
#define QVET_THEME_OP_TYPE_REMOVE_FX				   0x0000000C
#define QVET_THEME_OP_TYPE_ADD_PASTER				   0x0000000D
#define QVET_THEME_OP_TYPE_REMOVE_PASTER			   0x0000000E
#define QVET_THEME_OP_TYPE_ADD_FREEZE_FRAME            0x0000000F
#define QVET_THEME_OP_TYPE_REMOVE_FREEZE_FRAME         0x00000010


//constant used to identify precision of percent
#define AMVE_PERCENT_PRECISION						   10000


#define QVET_THEME_NONE_TEMPLATE_ID						0x0100000000000000L
#define QVET_TRANSITION_NONE_TEMPLATE_ID				0x0300000000000000L
#define QVET_EFFECT_NONE_TEMPLATE_ID					0x0400000000000000L
#define QVET_FX_NONE_TEMPLATE_ID						0x0600000000000000L
#define QVET_MUSIC_NONE_TEMPLATE_ID						0x0700000000000000L
#define QVET_BUBBLE_NONE_TEMPLATE_ID					0x0900000000000000L
#define QVET_PIP_NONE_TEMPLATE_ID						0x0C00000000000000L

#define AMVE_CLIP_COVER_TYPE_NONE                      0x00000000
#define AMVE_CLIP_COVER_TYPE_COVER                     0x00000001
#define AMVE_CLIP_COVER_TYPE_BACKCOVER                 0x00000002

//constant used to identify the codec type, h/w or s/w
#define AMVE_DECODER_USAGE_TYPE_HW					   		0x00000001
#define AMVE_DECODER_USAGE_TYPE_SW                      	0x00000002
#define AMVE_DECODER_USAGE_TYPE_AUTO					    0x00000004
#define AMVE_DECODER_USAGE_TYPE_THUMBNAIL				    0x00000008
#define AMVE_DECODER_USAGE_TYPE_PLAYBACK_THUMBNAIL		    0x00000010
#define AMVE_ENCODER_TYPE_HW								0x00000100
#define AMVE_ENCODER_TYPE_SW                      			0x00000200
#define AMVE_ENCODER_TYPE_AUTO					   	 		0x00000400

#define AMVE_TRIM_TYPE_NORMAL							0x00000000
#define AMVE_TRIM_TYPE_LEFT_KEYFRAME					0x00000001
#define AMVE_TRIM_TYPE_RIGHT_KEYFRAME					0x00000002

#define AMVE_SEEK_PRE									0x00000000
#define AMVE_SEEK_NEXT									0x00000001

//Macro definition for poster function
#define QVET_POSTER_ITEM_TYPE_IMAGE		0x00000001 	//the src of image maybe bitmap or image-file
#define QVET_POSTER_ITEM_TYPE_SVGTEXT	0x00000002	//the src of svgtext is a svg-file


//constants used to identify process status
#define AMVE_PROCESS_STATUS_NONE                       0X00000000
#define AMVE_PROCESS_STATUS_READY                      0X00000001
#define AMVE_PROCESS_STATUS_RUNNING                    0X00000002
#define AMVE_PROCESS_STATUS_PAUSED                     0X00000003
#define AMVE_PROCESS_STATUS_STOPPED                    0X00000004
#define AMVE_PROCESS_STATUS_INITIALIZING               0X00000005



#define QVET_CPU_OVERLOAD_LEVEL_NONE				0x00000000
#define QVET_CPU_OVERLOAD_LEVEL_LOW					0x00000001
#define QVET_CPU_OVERLOAD_LEVEL_MEDIUM				0x00000002
#define QVET_CPU_OVERLOAD_LEVEL_HIGH				0x00000003


//constants used to identify format of bubble's background file
#define QVET_BUBBLE_BG_FORMAT_NONE			0x00000000		//NONE 表示无需BG文件
#define QVET_BUBBLE_BG_FORMAT_SVG			0x00000001
#define QVET_BUBBLE_BG_FORMAT_PNG			0x00000002
#define QVET_BUBBLE_BG_FORMAT_MPO			0x00000003
#define QVET_BUBBLE_BG_FORMAT_JPG                    0x00000004
#define QVET_BUBBLE_BG_FORMAT_WEBP                   0x00000005

#define QVET_FONT_NAME_MAX_LENGTH			128
#define QVET_BUBBLE_TEXT_MAX_LENGTH			1024
#define QVET_DEFAULT_FONT_SIZE              50

#define QVET_LYRICS_MODE_NONE				0x00000000
#define QVET_LYRICS_MODE_MV					0x00000001
#define QVET_LYRICS_MODE_KTV				0x00000002


#define QVET_TRANSITION_ANIMATED_CFG_NONE		0
#define QVET_TRANSITION_ANIMATED_CFG_LEFT		1
#define QVET_TRANSITION_ANIMATED_CFG_RIGHT		2
#define QVET_TRANSITION_ANIMATED_CFG_TWO		3
#define QVET_TRANSITION_ANIMATED_CFG_AUTO		4

//Animate point的操作类型说明
//进行操作时，需要传入QVET_AINIMATE_POINT_OPERATION_DATA作为参数
//1.Insert,可以一次插入一个point
//2.Delete,一次只能delete一个point，此时QVET_AINIMATE_POINT_DATA里面的内容只需赋值point index即可
//3.delete all,删除所有point,此时QVET_AINIMATE_POINT_DATA数组可以为空
//4.Modify,一次只能修改一个point

#define QVET_ANIMATE_POINT_OPERATION_INSERT        0
#define QVET_ANIMATE_POINT_OPERATION_DELETE        1
#define QVET_ANIMATE_POINT_OPERATION_DELETE_ALL    2
#define QVET_ANIMATE_POINT_OPERATION_MODIFY        3

#define AMVE_VIDEO_4K_WIDTH                        3840
#define AMVE_VIDEO_4K_HEIGHT                       2160
#define AMVE_VIDEO_2K_WIDTH                        2560
#define AMVE_VIDEO_2K_HEIGHT                       1600
#define AMVE_VIDEO_1080P_WIDTH                     1920
#define AMVE_VIDEO_1080P_HEIGHT                    1080
#define AMVE_VIDEO_1080P_HEIGHT_ALIGN              1088
#define AMVE_VIDEO_720P_WIDTH                      1280
#define AMVE_VIDEO_720P_HEIGHT                     720
#define AMVE_VIDEO_FWVGA_WIDTH                     854
#define AMVE_VIDEO_FWVGA_HEIGHT                    480
#define AMVE_VIDEO_WVGA_WIDTH                      800
#define AMVE_VIDEO_WVGA_HEIGHT                     480
#define AMVE_VIDEO_VGA_WIDTH                       640
#define AMVE_VIDEO_VGA_HEIGHT                      480
#define AMVE_VIDEO_QVGA_WIDTH                      320
#define AMVE_VIDEO_QVGA_HEIGHT                     240


#define AMVE_COVER_CLIP_INDEX                      0xffffffff
#define AMVE_BACK_COVER_CLIP_INDEX                 0xfffffffe

//Add for text animation
#define QVET_TEXT_ANIMATE_FONT_COLOR_TYPE_FIXED    1   //固定字体颜色
#define QVET_TEXT_ANIMATE_FONT_COLOR_TYPE_RANDOM   2   //随机字体颜色
#define QVET_TEXT_ANIMATE_FONT_SIZE_TYPE_FIXED     1   //固定字体大小
#define QVET_TEXT_ANIMATE_FONT_SIZE_TYPE_RANDOM    2   //随机字体大小


#define AMVE_PASTER_CATEGROY_TYPE_GEN              0x01
#define AMVE_PASTER_CATEGROY_TYPE_FUNNY            0x02
#define AMVE_PASTER_CATEGROY_TYPE_LOVE             0x03
#define AMVE_PASTER_CATEGROY_TYPE_ACTION           0x04
#define AMVE_PASTER_CATEGROY_TYPE_DRESS            0x05
#define AMVE_PASTER_CATEGROY_TYPE_BAOBAO           0x06
#define AMVE_PASTER_CATEGROY_TYPE_FESTIVAL         0x07
#define AMVE_PASTER_CATEGROY_TYPE_BIRTHDAY         0x10
#define AMVE_PASTER_CATEGROY_TYPE_RUIXIAOTU        0x0E
#define AMVE_PASTER_CATEGROY_TYPE_ALI              0x0F
#define AMVE_PASTER_CATEGROY_TYPE_FACIAL           0x100
#define AMVE_PASTER_CATEGROY_TYPE_FACIAL_ATTACH    0x101


#define AMVE_PASTER_FACIAL_SUBTYPE_HAIR            0x00
#define AMVE_PASTER_FACIAL_SUBTYPE_EYEBROWS        0x01
#define AMVE_PASTER_FACIAL_SUBTYPE_EYE             0x02
#define AMVE_PASTER_FACIAL_SUBTYPE_NOSE            0x03
#define AMVE_PASTER_FACIAL_SUBTYPE_BEARD           0x04

#define AMVE_PASTER_FACIAL_POS_TYPE_HAIR_BOUND          0x00
#define AMVE_PASTER_FACIAL_POS_TYPE_EYEBROWS_BOUND      0x01
#define AMVE_PASTER_FACIAL_POS_TYPE_EYEBROWS_LBOUND     0x02
#define AMVE_PASTER_FACIAL_POS_TYPE_EYEBROWS_RBOUND     0x03
#define AMVE_PASTER_FACIAL_POS_TYPE_EYE_BOUND           0x04
#define AMVE_PASTER_FACIAL_POS_TYPE_EYE_LBOUND          0x05
#define AMVE_PASTER_FACIAL_POS_TYPE_EYE_RBOUND          0x06
#define AMVE_PASTER_FACIAL_POS_TYPE_EYE_LPUPIL          0x07
#define AMVE_PASTER_FACIAL_POS_TYPE_EYE_RPUPIL          0x08
#define AMVE_PASTER_FACIAL_POS_TYPE_NOSE_BOUND          0x09
#define AMVE_PASTER_FACIAL_POS_TYPE_NOSE_TIP            0x0A
#define AMVE_PASTER_FACIAL_POS_TYPE_NOSE_LNOSTRIL       0X0B
#define AMVE_PASTER_FACIAL_POS_TYPE_NOSE_RNOSTRIL       0X0C
#define AMVE_PASTER_FACIAL_POS_TYPE_BEARD_BOUND         0X0D
#define AMVE_PASTER_FACIAL_POS_TYPE_BEARD_UPPERLIP      0X0E
#define AMVE_PASTER_FACIAL_POS_TYPE_BEARD_LOWERLIP      0X0F
#define AMVE_PASTER_FACIAL_POS_TYPE_BEARD_CHEEK         0X10

#define AMVE_FACE_DT_LIB_TYPE_SENCETIME                 0x0
#define AMVE_FACE_DT_LIB_TYPE_ARCSOFT_41                0x1
#define AMVE_FACE_DT_LIB_TYPE_ARCSOFT_101               0x2

#define AMVE_FACEDT_MAX_FACE_COUNT                      4  //最多支持4张人脸
#define AMVE_FACEDT_RESULT_POINT_COUNT                  106


#define AMVE_FACEDT_EXPRESSION_TYPE_NONE                0
#define AMVE_FACEDT_EXPRESSION_TYPE_MOUTH_OPEN          1
#define AMVE_FACEDT_EXPRESSION_TYPE_EYEBROW_RAISE       2
#define AMVE_FACEDT_EXPRESSION_TYPE_BLINK               3
#define AMVE_FACEDT_EXPRESSION_TYPE_HEADSHAKE           4
#define AMVE_FACEDT_EXPRESSION_TYPE_HEADNOD             5
#define AMVE_FACEDT_EXPRESSION_TYPE_HEADSHAKE_NOD       6


#define AMVE_FACEDT_EXPRESSION_PASTE_SHOW               0
#define AMVE_FACEDT_EXPRESSION_PASTE_HIDE               1
#define AMVE_FACEDT_EXPRESSION_PASTE_SWITCH             2



#define AMVE_H264_PROFILE_UNKNOW                        0x0
#define AMVE_H264_PROFILE_BASELINE                      0x1
#define AMVE_H264_PROFILE_MAIN                          0x2
#define AMVE_H264_PROFILE_HIGH                          0x3

#define AMVE_H264_LEVEL_UNKNOW                           0
#define AMVE_H264_LEVEL_30                               30
#define AMVE_H264_LEVEL_31                               31
#define AMVE_H264_LEVEL_40                               40
#define AMVE_H264_LEVEL_41                               41

#define AMVE_VIDEO_ENC_BITRATE_MODE_LOW                  0x0
#define AMVE_VIDEO_ENC_BITRATE_MODE_HIGH                 0x1
#define AMVE_VIDEO_ENC_BITRATE_MODE_VERY_LOW             0x2

#define QVET_TIME_POSITION_ALIGNMENT_MODE_START		0
#define QVET_TIME_POSITION_ALIGNMENT_MODE_END		1
#define QVET_TIME_POSITION_ALIGNMENT_MODE_MIDDLE	2

#define QVET_REFRESH_STREAM_OPCODE_ADD_EFFECT					1
#define QVET_REFRESH_STREAM_OPCODE_UPDATE_EFFECT				2
#define QVET_REFRESH_STREAM_OPCODE_REMOVE_EFFECT				3
#define QVET_REFRESH_STREAM_OPCODE_UPDATE_PANZOOM				4
#define QVET_REFRESH_STREAM_OPCODE_UPDATE_ALL_CLIP_ALL_EFFECT	5
#define QVET_REFRESH_STREAM_OPCODE_UPDATE_ALL_EFFECT			6
#define QVET_REFRESH_STREAM_OPCODE_UPDATE_ALL_MUSIC				7
#define QVET_REFRESH_STREAM_OPCODE_UPDATE_TRANSITION			8
#define QVET_REFRESH_STREAM_OPCODE_UPDATE_ALL_TRANSITION		9
#define QVET_REFRESH_STREAM_OPCODE_UPDATE_TIME_SCALE			10
#define QVET_REFRESH_STREAM_OPCODE_REOPEN						11

#define QVET_DURATION_MODE_NO_ADD_FREEZE_TIME                   0
#define QVET_DURATION_MODE_CLIP_ADD_FREEZE_TIME                 1
#define QVET_DURATION_MODE_STORYBOARD_ADD_FREEZE_TIME           2
#define QVET_DURATION_MODE_ALL_ADD_FREEZE_TIME                  (QVET_DURATION_MODE_CLIP_ADD_FREEZE_TIME | QVET_DURATION_MODE_STORYBOARD_ADD_FREEZE_TIME)

#define QVET_EFFECT_ABFACE_TYPE_LEFT                            0  //应用于左脸
#define QVET_EFFECT_ABFACE_TYPE_RIGHT                           1  //应用于右脸
#define QVET_EFFECT_ABFACE_TYPE_COMBO                           2  //应用于组合后的脸
#define QVET_EFFECT_ABFACE_TYPE_INDEX                           3  //指定应用到某张人脸上
#define QVET_EFFECT_ABFACE_TYPE_RANDOM                          4
#define QVET_EFFECT_ABFACE_APPLY_LEFT                           0  //combo 应用到left
#define QVET_EFFECT_ABFACE_APPLY_RIGHT                          1  //combo应用到right

#define QVET_THEME_RESET_CODE_MUSIC                             1  //还原主题配乐

#define QVET_RENDER_API_UNKNOW                                  0
#define QVET_RENDER_API_OpenGLES20                              0x00000010
#define QVET_RENDER_API_OpenGLES30                              0x00000011
#define QVET_RENDER_API_OpenGLES31                              0x00000012
#define QVET_RENDER_API_OpenGLES32                              0x00000013
#define QVET_RENDER_API_Metal10                                 0x00000020
#define QVET_RENDER_API_Vulkan10                                0x00000040
#define QVET_RENDER_API_D3D11                                   0x00000080


#define AMVE_SESSION_OP_TYPE_NONE				0
#define AMVE_PS_OP_BASE										AMVE_SESSION_OP_TYPE_NONE		//PS = player session
#define AMVE_PS_OP_REFRESH_AUDIO							(AMVE_PS_OP_BASE+1)	 	//0x00000001, for AMVES_PlayerPerformOperation, opParam is NULL
#define AMVE_PS_OP_REFRESH_AUDIO_EX							(AMVE_PS_OP_BASE+2)	 	//0x00000002, for AMVES_PlayerPerformOperation, opParam is NULL



#define QVET_CHECK_VALID_RET(ret)   \
        if (ret) {                  \
            return ret;             \
        }

#define QVET_CHECK_VALID_GOTO(ret)  \
        if (ret) {                  \
            goto FUN_EXIT;          \
        }

#define QVET_CHECK_POINTER_GOTO(p, err)     \
        if (!p) {                           \
            res = err;                      \
            goto FUN_EXIT;                  \
        }

#define QVET_SET_ERR_AND_GOTO(err)  \
        {                           \
            res = (err);            \
            goto FUN_EXIT;          \
        }

#define QVET_CHECK_POINTER_RET(p, err)  \
        {                               \
            if (!p)                     \
            return err;                 \
        }


#define QVET_SLSH_TRANSFORM_TYPE_BLUR                           0x08
#define QVET_SLSH_TRANSFORM_TYPE_COLOR_FILL                     0x09

typedef struct _tag_QVET_FRAME_VECTOR_3
{
    MFloat x;
    MFloat y;
    MFloat z;
}QVET_FRAME_VECTOR_3;

typedef struct _tag_QVET_FRAME_TRANSFORM
{
    QVET_FRAME_VECTOR_3 scale;
    QVET_FRAME_VECTOR_3 shift;
    QVET_FRAME_VECTOR_3 angle;
    QVET_FRAME_VECTOR_3 center;
}QVET_FRAME_TRANSFORM;


typedef struct _tag_QVET_TRANSFORM_PARAMETERS
{
	MDWord	dwEffectTransformType;
	MDWord 	dwBlurLenV;
	MDWord 	dwBlurLenH;

	MFloat	fScaleX;
	MFloat	fScaleY;
    MFloat	fScaleZ;

    MDWord	dwAngleX;
    MDWord	dwAngleY;
	MDWord	dwAngleZ;

	MFloat	fShiftX;
	MFloat	fShiftY;
    MFloat	fShiftZ;

    MFloat	fRectL;
	MFloat	fRectT;
	MFloat	fRectR;
	MFloat	fRectB;
    
    MDWord	dwClearR;
    MDWord	dwClearG;
	MDWord	dwClearB;
    MDWord	dwClearA;
}QVET_TRANSFORM_PARAMETERS;


//The structure called by AMVE_FNSTATUSCALLBACK
typedef struct _tagAMVE_CBDATA_TYPE
{
	MDWord dwStatus;
	MDWord dwCurTime;
	MDWord dwDuration;
	MDWord dwErrorCode;
	MHandle hStream;
	MDWord dwLastDrawnVFTS; //Last Drawn video frame timestamp
	MDWord dwLastDrawnVFTSP;//Last Drawn video frame timespan
	MTChar* pszUserData;
	MDWord dwAudioErr; //audio process error code
	MDWord dwVDecErr;  //video decoding error code
	MDWord dwVEncErr;  //video encoding error code
	MDWord dwOpenglErr; //opengl es error code
} AMVE_CBDATA_TYPE;

//The callback function
typedef MDWord  (*AMVE_FNSTATUSCALLBACK)(
		AMVE_CBDATA_TYPE* pCBData,
		MVoid* pUserData);

typedef MVoid (*AMVE_FNAUDIOSOURCECALLBACK)(MByte* pBuf,MDWord dwBufLen,MVoid* pUserData);


typedef struct _tagAMVE_INITPARAM_TYPE
{
	MHandle hSessionContext;
	AMVE_FNSTATUSCALLBACK fnCallback;
	MVoid *pUserData;
} AMVE_INITPARAM_TYPE;

typedef MRESULT (*AMVE_FNUSERBUBBLETEXTCALLBACK)(
		MBITMAP* pCBRGB32Data, 
		MVoid* pBubbleSrc,	//type is AMVE_BUBBLETEXT_SOURCE_TYPE*
		MDWord dwDstWidth, 
		MDWord dwDstHeight,
		MVoid* pUserData);

typedef MRESULT (*AMVE_FUNFILEPATHMODIFYCALLBACK)(
		MTChar *pszSrcFileToModified, /*in,out*/
		MDWord	dwStrBufLen,
		MVoid* pUserData);

typedef struct _tagQVET_FILEPATH_MODIFIER{
	AMVE_FUNFILEPATHMODIFYCALLBACK fp;
	MVoid* pUserData;
}QVET_FILEPATH_MODIFIER;

typedef struct _tagAMVE_USER_DATA_TYPE
{
	MByte*	  pbyUserData;
	MDWord	  dwUserDataLen;
} AMVE_USER_DATA_TYPE;

typedef struct _tagQVET_RENDER_CONTEXT
{
	MHandle   hDisplayContext;
	MRECT     rectScreen;
	MRECT     rectClip;
	MCOLORREF colorBackground;
	MDWord    dwRotation;
//	MDWord    dwOrientation;
	MDWord    dwResampleMode;
	MDWord	  dwRenderTarget;
} QVET_RENDER_CONTEXT_TYPE;

typedef struct _tagAMVE_VIDEO_INFO_TYPE
{
	MDWord dwFileFormat;
	MDWord dwVideoFormat;
	MDWord dwAudioFormat;
	MDWord dwFrameWidth;
	MDWord dwFrameHeight;
	MDWord dwVideoDuration;
	MDWord dwAudioDuration;
	MDWord dwFileSize;
	MDWord dwBitrate;
	MDWord dwVideoFrameRate;
	MDWord dwVideoBitrate;
	MDWord dwAudioSampleRate;
	MDWord dwAudioChannel;
	MDWord dwAudioBitrate;
	MDWord dwAudioBitsPerSample;
	MDWord dwAudioBlockAlign;
} AMVE_VIDEO_INFO_TYPE;


typedef struct _tagSourceExternalInfo
{
	MDWord dwSplitterSize;
	MDWord dwAVCLength;
	MBool  bSeekable;
	MDWord dwRotate;
	MBool  bInterlace;
	MBool bAlphaNeedPreMulti;
} AMVE_SOURCE_EXT_INFO;

typedef struct _tagAMVE_PLAYER_STATE_TYPE
{
	AMVE_VIDEO_INFO_TYPE videoInfo;
	MDWord dwStatus;
	MDWord dwCurTime;
	MDWord dwPlaybackMode;
	MDWord dwVolume;
	MBool  bMuted;
	MDWord dwLastDrawnVFTS; //last drawn video frame timestamp
	MDWord dwLastDrawnVFTSP; //last drawn video frame timespan
} AMVE_PLAYER_STATE_TYPE;

typedef struct _tagAMVE_PRODUCER_STATE_TYPE
{
	AMVE_VIDEO_INFO_TYPE srcVideoInfo;
	AMVE_VIDEO_INFO_TYPE dstVideoInfo;
	MDWord dwStatus;
	MDWord dwCurTime;
} AMVE_PRODUCER_STATE_TYPE;

typedef struct _tagAMVE_DETECTOR_STATE_TYPE
{
	MDWord dwStatus;
	MDWord dwCurTime;
	MDWord dwDuration;
} AMVE_DETECTOR_STATE_TYPE;

typedef struct _tagAMVE_AUDIO_PROVIDER_STATE_TYPE
{
    MDWord dwStatus;
	MDWord dwCurTime;
}AMVE_AUDIO_PROVIDER_STATE_TYPE;

typedef struct _tagAMVE_TRANSITION_TYPE
{
	MVoid*  pTemplate;
	MLong   lCfgIndex;
	MDWord  dwDuration;
	MDWord  dwAnimatedCfg;
	MBool   bSetByEngine;
} AMVE_TRANSITION_TYPE;

typedef struct _tagAMVE_BUBBLETEXT_SOURCE_TYPE
{
	MVoid     *pSVGFile;
	MCOLORREF clrBackground;
	MBool	  bVerReversal;
	MBool	  bHorReversal;
	MFloat    fRotateAngle;
	MPOINT	  ptRotateCenter;
	//below parameters only work when it is set has clip source or text frame source, not frame source
	MRECT	  rcRegionRatio;
	MDWord	  dwTransparency;
	MCOLORREF clrText;  //ARGB
	MDWord	  dwTextAlignment;
	MTChar	  *pszText;
	MTChar	  *pszAuxiliaryFont;
	MInt64    llTemplateID; 
	MDWord    dwParamID;
	struct
	{
		MBool		bEnableEffect; //true: all the effect parameter will be actived; false: all the effect parameter will be ignored
		MDWord		dwShadowColor;
		MFloat		fDShadowBlurRadius; //fDShadowBlurRadius: iOS必须>=0; android 上必须 > 0;
		MFloat		fDShadowXShift;
		MFloat		fDShadowYShift;

		MDWord		dwStrokeColor;
		MFloat		fStrokeWPercent; //WidthPercent,这个参数是按iOS的定义走的，android下引擎底层会做转换，转换成绝对值
	}TextExtraEffect;	
} AMVE_BUBBLETEXT_SOURCE_TYPE;


typedef struct __tagAMVE_GLYPH_STYLE
{
	MDWord dwGStartIdx;	//the start index of glyphs which have the same style in string, idx started by 0
	MDWord dwGCount;	//glyph counts which has the same style in string by sequence
	
	MDWord	dwGColor;
    MFloat  fSizeFactor; //考虑到一段文字的字号可以不同，同时文字又可以缩放----非绝对字号，所以用这个尺寸因子来描述。常规大小取1.0即可
	
	//all the variable names start with "D" mean it's only UI Design value, 
	//it may be modified by auto-fit-calculation, such as auto-multi-line calculation
	MDWord		dwShadowColor;
	MFloat		fDFontSize;  
	MFloat		fDShadowBlurRadius; //fDShadowBlurRadius: iOS必须>=0; android 上必须 > 0;
	MFloat		fDShadowXShift;
	MFloat		fDShadowYShift;

	MDWord		dwStrokeColor;
	MFloat		fStrokeWPercent; //WidthPercent,这个参数是按iOS的定义走的，android要做转换，转换成绝对值
	
}AMVE_GLYPH_STYLE;


typedef struct _tagAMVE_TEXTANIMATION_SOURCE_TYPE
{
	MTChar	  *pszText;
	MTChar    *pszDefaultText;
	MTChar    *pszAuxiliaryFont;
	MDWord    dwAlignment;
	MDWord    dwEditable;
	MDWord    dwPosAlignment;
	MDWord    dwPreviewPos;
	MInt64    llTemplateID;
	MFloat    fFontSize;
	MBool     bFontSizeSetted;
	MDWord    dwFontColor;
	MBool     bFontColorSetted;
	MDWord    dwAnimateItemID;
	MDWord    dwParamID;
	//Add for VivaVideo text animation
	MBool	  bVerReversal;
	MBool	  bHorReversal;
	MRECT	  rcRegionRatio;
    MFloat    fRotation;
	//Add shadow property
	MDWord		dwShadowColor;
	MFloat		fDShadowBlurRadius;
	MFloat		fDShadowXShift;
	MFloat		fDShadowYShift;
    //Add stroke property
    MDWord		dwStrokeColor;
	MFloat		fStrokeWPercent;
}AMVE_TEXTANIMATION_SOURCE_TYPE;

typedef struct _tagAMVE_TEXTANIMATION_SOURCE_LIST
{
    MDWord dwCount;
	AMVE_TEXTANIMATION_SOURCE_TYPE* pTASource;
}AMVE_TEXTANIMATION_SOURCE_LIST;

typedef struct _tagAMVE_TEXTANIMATION_INFO_LIST
{
    MDWord dwListCount;
	MDWord* pdwClipIndex;
	AMVE_TEXTANIMATION_SOURCE_LIST* pTASourceList;
}AMVE_TEXTANIMATION_INFO_LIST;

typedef struct _tagAMVE_PKG_SOURCE_TYPE
{
	MVoid*	pPKGFile;
	MDWord	dwFileID;
} AMVE_PKG_SOURCE_TYPE;

typedef struct _tagQVET_TRC_SOURCE_TYPE
{
	MTChar *pszTRCFile; //TRC 歌词文件
	MTChar *pszFont;	//在生成歌词时要用到的TTF文件
	MCOLORREF bgColor;	//一开始只会用到单色的歌词svg显示，所有只会用到这个颜色
	MCOLORREF foreColor;//foreColor在一开始还用不到，以后要做歌词滚动的话，势必有2层svg，颜色要区分，上层滚动的颜色与底板要不一样
	MDWord  dwMode;	//QVET_LYRICS_MODE_XXXX,  veutily的duplicate函数要跟进
	MWChar *pszPrepareChars; //用于KTV模式下，正式开唱前的提示符，原则上只设置一个字符即可，因涉及到特殊字符的字库支持问题，所以最好外面来设置，引擎不要写死
}QVET_TRC_SOURCE_TYPE; //TRC是第三方提供的歌词，有其特定的格式

typedef struct _tagAMVE_BUBBLETEXT_INFO_TYPE
{
	MVoid     *pFontFile;
	MVoid     *pBubbleFile;
	MBool 	  bBubbleIsTemplate; // true means pBubbleFile is a template, false means it's a svg file
	MWChar    *pszText;
	MCOLORREF clrBubble;
	MCOLORREF clrText;
}AMVE_BUBBLETEXT_INFO_TYPE;

typedef struct _tagAMVE_MEDIA_SOURCE_TYPE
{
	MDWord dwSrcType; //AMVE_MEDIA_SOURCE_TYPE_FILE, etc.
	MVoid* pSource;
	MBool bIsTmpSrc;
} AMVE_MEDIA_SOURCE_TYPE;

//structure to used by property
typedef struct _tagAMVE_POSITION_RANGE_TYPE
{
	MDWord dwPos;
	MDWord dwLen;
} AMVE_POSITION_RANGE_TYPE;

typedef struct _tagQVET_TRC_LYRICS_INFO
{
	MDWord dwMusicDuration;
	AMVE_POSITION_RANGE_TYPE TimeRange;
}QVET_TRC_LYRICS_INFO;

//structure to used by stream
typedef struct _tagAMVE_STREAM_SOURCE_TYPE
{
	MDWord  dwType;
	MHandle hData;		// 对应的是 m_hSession, 如 
} AMVE_STREAM_SOURCE_TYPE;

typedef struct _tagAMVE_WM_HIDER_DATA
{
     MTChar* pszWMUserCode;                  //用户id字符串
	MDWord dwWMHiderInterval;                //数字水印嵌入周期
}AMVE_WM_HIDER_DATA;

typedef struct _tagAMVE_STREAM_PARAM_TYPE
{
	MSIZE	FrameSize;
	MSIZE	RenderTargetSize;
	//Rotation和ResampleMode都带有RenderContext的味道，只所以要在这里带上这些参数是因为要让
	//SessionCore替app做一些事情。一个清晰的STREAM_PARAM结构是不应该出现这些..........
	MDWord	dwRotation;
	MDWord	dwResampleMode;
	MDWord dwDecoderUsageType;				//指定Decoder的使用方式
	MHandle hWatermark;						//如果空表示不带水印
	MTChar* pszFaceDTDataFile;
    AMVE_WM_HIDER_DATA WMHiderData;
} AMVE_STREAM_PARAM_TYPE;

typedef struct _tagAMVE_PRODUCER_PARAM_TYPE
{
	MDWord dwFileFormat;
	MDWord dwVideoFormat;
	MDWord dwAudioFormat;
	MDWord dwVideoFrameRate;
	MDWord dwVideoBitrate;
    //MDWord dwMaxFileSize;
    MInt64 llMaxFileSize;  //文件尺寸允许超过4G
	MTChar *pszDestFile;
	MDWord dwEncoderType;	//dwEncoderType: AMVE_ENCODER_TYPE_XXX
	AMVE_POSITION_RANGE_TYPE range;
    MDWord dwProfile;  //If video format is h264,profile and level should be set
    MDWord dwLevel;

	MTChar *wmCode;
	MDWord dwMaxExpFPS; //允许导出的最高fps,用于控制导出时跳帧

} AMVE_PRODUCER_PARAM_TYPE;

typedef struct _tagAMVE_FADE_PARAM_TYPE
{
	MDWord dwDuration;
	MDWord dwStartPercent;
	MDWord dwEndPercent;
} AMVE_FADE_PARAM_TYPE;

typedef struct _tagQVET_ADDITIONAL_TIME 
{
	MDWord dwStartLen;
	MDWord dwEndLen;
} QVET_ADDITIONAL_TIME ;

typedef struct
{
    MInt64 llTemplateID;
    AMVE_MEDIA_SOURCE_TYPE* pTextSource;
} QVET_THEME_TEXT;

typedef struct
{
    MBool bCover;
    MVoid *pTemplateFile;
    MDWord dwCoverWidth;
    MDWord dwCoverHeight;
    MDWord dwSourceCount;
    AMVE_MEDIA_SOURCE_TYPE *pSource;  //cover上面的几个嵌入的图片MediaSrc
	MDWord dwTextCount;	//reserved
    QVET_THEME_TEXT* pText;
} QVET_THEME_ADD_COVER_DATA;

typedef struct  
{
	MDWord dwTextCount;
	QVET_THEME_TEXT* pText;
} QVET_THEME_ADD_TEXT_DATA;

typedef struct _tagAMVE_PS_POSITION {
	MFloat fx, fy, fz;
	MUInt64 llTimeStamp;
} AMVE_PS_POSITION;
/*
*	AMVE_THEME_OPERATE_TYPE:
*		pOperateData  	目前只针对AMVE_THEME_OP_TYPE_REMOVE_COVER 或是 AMVE_THEME_OP_TYPE_ADD_COVER 不为空，因为暂时只有这两种Type跟外面会有数据交互
*						AMVE_THEME_OP_TYPE_REMOVE_COVER ---- pOperateData = &(MBool 变量)
*						AMVE_THEME_OP_TYPE_ADD_COVER    ---- pOperateData = &(AMVE_THEME_ADD_COVER 变量)
*/
typedef struct
{
	MDWord dwOperateType;
	MBool bOnStoryboard;
	MDWord dwClipIndex;
	MDWord dwEffectTrackType;
	MDWord dwEffectGroupID;
    MDWord dwErrorCode;
    MBool  bOperatorFinish;
    MVoid *pOperateData;
} AMVE_THEME_OPERATE_TYPE;

typedef struct
{
    MDWord dwDataType;   //AMVE_TEXT_TRANSFORM_DATA_TYPE_xxx
	MVoid* pData;
}AMVE_TEXT_TRANSFORM_PARAM;

#define AMVE_TEXT_TRANSFORM_DATA_TYPE_NONE     0
#define AMVE_TEXT_TRANSFORM_DATA_TYPE_STRING   1

//The callback function
typedef MRESULT  (*AMVE_FNTHEMEOPERATECALLBACK)(
		AMVE_THEME_OPERATE_TYPE* pCBData,
		MVoid* pUserData);


//The callback of get template path function
typedef MRESULT (*QVET_TEMPLATE_GET_PATH_CALLBACK)(MInt64 llID/*in*/, 
				MTChar* szFilePath/*out*/, MDWord dwLen/*in*/, MVoid* pUserData);

//The callback of get template id function
typedef MInt64 (*QVET_TEMPLATE_GET_ID_CALLBACK)(const MTChar* szFilePath/*in*/, MVoid* pUserData);

typedef MRESULT (*QVET_TEMPLATE_GET_EXTERNAL_FILE_CALLBACK)(MInt64 llID, MDWord dwSubTemplateID, 
							MDWord dwFileID, MTChar* szFilePath/*out*/, MDWord dwLen/*in*/, MVoid* pUserData);


typedef MDWord (*QVET_GET_MAXHWDEC_COUNT_CALLBACK) (MDWord dwIndex,MVoid* pUserData);
typedef MBool  (*QVET_QUERY_HWENC_CAP_CALLBACK) (MDWord dwIndex,MVoid* pUserData);
typedef MRESULT (*QVET_QUERY_VIDEO_IMPORT_FORMAT_CALLBACK) (MDWord dwVImportType,MDWord* pdwVImportFormat,MVoid* pUserData);
typedef MBool  (*QVET_GET_HW_BETATESTED_FLAG_CALLBACK) (MVoid* pUserData);

typedef MRESULT (*QVET_FIND_FONT_CALLBACK) (MDWord dwFontID,MTChar* pszFontPath,MDWord dwMaxLength,MVoid* pUserData);

typedef MRESULT (*QVET_TEXT_TRANSFORM_CALLBACK) (MTChar* pszOrgText,MTChar** ppszTgtText,AMVE_TEXT_TRANSFORM_PARAM* pParam,MVoid* pUserData);


typedef struct _tagTemplateAdapter
{
	QVET_TEMPLATE_GET_PATH_CALLBACK fnGetPath;
	QVET_TEMPLATE_GET_ID_CALLBACK fnGetID;
	QVET_TEMPLATE_GET_EXTERNAL_FILE_CALLBACK fnGetExternalFile;
	MVoid* pUserData;
} QVET_TEMPLATE_ADAPTER;

typedef struct _tagHWCodecQuery
{
    QVET_GET_MAXHWDEC_COUNT_CALLBACK fnGetHWDecCount;
	QVET_QUERY_HWENC_CAP_CALLBACK fnQueryHWEncCap;
	QVET_QUERY_VIDEO_IMPORT_FORMAT_CALLBACK fnQueryVImpFormat;
	QVET_GET_HW_BETATESTED_FLAG_CALLBACK fnGetHWBetaTestedFlag;
	MVoid* pUserData;
}QVET_HWCODEC_QUERY;

typedef struct _tagFontFinder
{
    QVET_FIND_FONT_CALLBACK fnFindFontCb;
	MVoid* pUserData;
}QVET_FONT_FINDER;

typedef struct _tagTextTransformer
{
    QVET_TEXT_TRANSFORM_CALLBACK fnTextTransformCb;
	MVoid* pUserData;
}QVET_TEXT_TRANSFORMER;

#define AMVE_MAKE_RGB(r, g, b)		((MCOLORREF)(((MByte)(r)|((MWord)((MByte)(g))<<8))|(((MDWord)(MByte)(b))<<16)))



//Macro definition for poster function
typedef struct _tagQVET_POSTER_ITEM_ATTR
{
	MRECT  rcRegion;	//外接矩形的区域（相对于目标的比例，精度为万分之一）
	MFloat fAngle;		//旋转的角度
	MBool  bIsInternalItem; //poster 模板中有些 图是内置不让app修改的，用此项标示。这个属性本可以不开放给app，之所以依旧开放，主要为了简化引擎代码逻辑
//	MCOLORREF color;	//color 只针对svg text有用，而且只是告诉外部text的颜色，外部可以根据这个颜色去生产svg 文件，此变量不影响merge行为
} QVET_POSTER_ITEM_ATTR;

typedef struct _tagQVET_POSTER_ITEM_DATA
{
//	MTChar* szDataFile; //image or svg file
	AMVE_MEDIA_SOURCE_TYPE MediaSrc;
	MRECT rcRegion;		//相对于QVET_POSTER_ITEM_ATTR::rcRegion的比例，精度为万分之一. 
	MDWord dwResmapleMode; 
} QVET_POSTER_ITEM_DATA;

typedef MDWord  (*QVET_POSTER_COMPOSE_CALLBACK)(MDWord dwCurStep, MDWord dwTotalSteps, MVoid* pUserData);

typedef struct _tagQVET_AUDIO_FRAME_INFO{

//	AMVE_FADE_PARAM_TYPE;
	MDWord dwMixPercent;
}QVET_AUDIO_FRAME_INFO;

/*
*  QVET_AE_SEGMENT_INFO
*  1.此结构命名为 QVET_AE_SEGMENT_INFO_FOR_STREAM 可能更能体现其用意，但是这样太长，所以缩写了
*    AE = AudioEffect(也可理解为AudioEditing)
*
*  2.引擎旧有的编辑模式所带来的问题:
*    目前引擎是属于Clip编辑模式，并不是Stream编辑模式，Clip一旦转成Stream之后，Clip和Stream就两个独立的数据体，没有关联。
*    因此每次Clip被编辑过后，如果想要以实时播放预览的方式看到编辑效果，预览用的Stream都要重新生成。
*    Create Stream 往往是一个耗时的操作，如果编辑越频繁，ReCreate Stream也就频繁，由此会引发应用层很多性能上的问题。
*		
*  3.此数据结构建立的初衷是:
*    如果有编辑特性的变动，只要更新一下Stream的Effect Segment Info，然后UpdateStream即可，不用rebuild stream就可以体现出新的编辑特性了
*    所以这个数据结构中涉及的一些effect都是stream可以实时更新的编辑特性
*
*  4.例外:
*    并不是所有编辑行为都可以不用rebuild stream----比如trim clip操作。
*    因此这一优化只能的针对那些对于 clip和stream 无差别的编辑特性
*
*  5.QVET_AE_SEGMENT_INFO 的数据归属者 以及 针对CVEStoryboardClip和CVEStoryboardData的通用性
*    CVEStoryboardClip  <-- 转换 --> CVEComboVidoeTrack(CVEComboVideoOutputStream) -----> 要包含 一个 SEGMENT_INFO List 对应单个clip上 的effect stream 分段
*    CVEStoryboardData  <-- 转换 --> CVEComboVidoeTrack(CVEComboVideoOutputStream) -----> 也要包含一个SEGMENT_INFO List 对应StoryboardData上的effect stream 分段
*    首先支持StoryboardData转Stream之后的分段, Segment Info数据组织的发生时机在 CVEStoryboardData::ExportAudioToTrack()
*
*  6.目前的QVET_AE_SEGMENT_INFO数据结构缺陷 及 分段依据:
*    AE有好几种，比如mix，fade。理想情况下一个AE只对应一个QVET_AE_SEGMENT_INFO, 因为不同种类的AE在时间轴上可能会有交错(即他们的起始结束点不一样)
*    理论上处理这种交错最好的方法是每种AE都有自己的一个info list-----但这种case的复杂度相当大-----因此第一步默认这种case不会出现。
*    目前CVEStoryboardData-ComboAudioStream 上的Segment 分段首先考虑clip duration分段，再结合某个effect的分段
*    目前CVEStoryboardClip-ComboAudioStream 上的Segment 分段暂不支持
*/
typedef struct _tagQVET_AE_SEGMENT_INFO{
	AMVE_POSITION_RANGE_TYPE Range;	//特别注意: 这里的range是针对目标时间轴的(DstTime)，不是源时间轴(SrcTime)
	MDWord	dwMixPercent;	//dwMixPercent=0 means no mix
	AMVE_FADE_PARAM_TYPE FadeIn;	//has not been actived
	AMVE_FADE_PARAM_TYPE FadeOut;   //has not been actived
}QVET_AE_SEGMENT_INFO;


/*
*  QVET_VE_SEGMENT_INFO:
*    此结构的引入用意与QVET_AE_SEGMENT_INFO 相同
*    VE = VideoEffect(也可理解为VideoEditing)
*/
typedef struct _tagQVET_VE_SEGMENT_INFO{
	AMVE_POSITION_RANGE_TYPE Range;//has not been actived
}QVET_VE_SEGMENT_INFO;


/*
*	QVET_BASIC_TEXT_INFO 的诞生源于海报模板的国际化，但是考虑到以后数据结构的复用性，只把一些文字Basic的数据放在这个结构里。
*
*/
typedef struct _tagQVET_BASIC_TEXT_INFO{
	MBool 		bEditable;
	MCOLORREF	ForeColor;
	MCOLORREF   BGColor;	//not actived
	MTChar     *pszFontName;
	MDWord      dwFontStyle; //QVET_TEXT_STYLE_XXXX
	MDWord      dwAlignment; //AMVE_STYLE_TEXT_ALIGNMENT_XXXXX
	MDWord      dwTransparent;//not actived
}QVET_BASIC_TEXT_INFO;


/*
* QVET_UIREF_FONT_SIZE:
*	UIREF = UI Reference.
*	这个数据结构用于描述:
*		UI上层在放Text控件时，所需要用到的字号大小，比如9,12......
*	数据结构的来源:
*		虽然所有text在模板中都会有相应的rect用以表示其大小，但是实际设备屏幕大小存在差异，
*		对于小屏幕设备，如果按照等比例缩小来计算UI text控件大小，会使得控件小的容不下一个手指，无法操作，
*		所以，模板通过实际手机上的测试后，会记录在特殊设备上的 参考大小，以备以后APP遇到相同情况时参考
*/
typedef struct _tagQVET_UIREF_FONT_SIZE{
	MDWord dwScreenW;
	MDWord dwScreenH;
	MDWord dwFatherWidgetW;
	MDWord dwFatherWidgetH;
	MDWord dwUIRefFontSize;
}QVET_UIREF_FONT_SIZE;


typedef struct _tagQVET_I18N_ITEM_INFO{
	MDWord dwLanguageID;	//如果dwLanguageID==0 表示是default string;  如果dwLanguageID=0xFFFFFFFF, 表示是一个无效的ID
	MTChar *pszI18NStr;
}QVET_I18N_ITEM_INFO;

typedef struct
{
	MDWord dwRefWidth;
	MDWord dwRefHeight;
	MDWord dwWidth;
	MDWord dwHeight;
	MDWord dwAlignment;
	MLong  lxOff;
	MLong  lyOff;
	MDWord dwAdjustPositionWay;
} QVET_SIZE_POSITION;

typedef struct{
	MDWord dwSrcW;
	MDWord dwSrcH;
	MDWord dwDstW;
	MDWord dwDstH;
}QVET_IE_FRAME_SIZE;


typedef struct __tag_BubbleTemplateInfo
{
    MDWord dwVersion;
	MFloat fRotation;
	MCOLORREF clrBubble;
	MRECT rcRegion;
	MBool bIsAnimated;
	MDWord dwMinDuration;
	MDWord dwStaticPos;
	MDWord dwBGFormat;	//QVET_BUBBLE_BG_FORMAT_XXXX
	MDWord dwBGFileID;
	MBool  bAutoMultiLine;
	MSIZE  BGOriSize; //Ori=Original
	struct 
	{
		MDWord dwEditable;
		MDWord dwAlignment;
		MCOLORREF clrText;
		MDWord dwFontSize;
		MRECT rcRegion;
		MDWord dwMaxLength;

		MDWord	dwShadowColor;
		MFloat	fDShadowBlurRadius; //fDShadowBlurRadius: iOS必须>=0; android 上必须 > 0;
		MFloat	fDShadowXShift;
		MFloat	fDShadowYShift;

		MDWord	dwStrokeColor;
		MFloat	fStrokeWPercent; //WidthPercent,这个参数是按iOS的定义走的，android要做转换，转换成绝对值		
		
		// fill type
		// 0 -> none
    	// 1 -> pure color // color from dwTxtColor
   		// 2 -> linear gradient
    	MDWord dwFillType;//
    	struct FillConfig {
        
	        // for gradient
	        MDWord color0;
	        MDWord color1;
			MDWord angle;
			// start point
	        //MDWord x0;
	        //MDWord y0;
			// stop point
	        //MDWord x1;
	        //MDWord y1;
        
    	} fillConfig;
    
		MDWord dwStrokeType;//
    	struct StrokeConfig {
        
	        // for gradient
	        MDWord color0; //MDWord	dwStrokeColor;
	        MDWord color1;
			MDWord angle;
			// start point
	        //MDWord x0;
	        //MDWord y0;
			// stop point
	        //MDWord x1;
	        //MDWord y1;
			
        	MFloat fWidthPercent; //WidthPercent,这个参数是按iOS的定义走的，android要做转换，转换成绝对值		
    	} strokeConfig;

		
		MTChar szFontName[QVET_FONT_NAME_MAX_LENGTH];
		MTChar szDefaultText[QVET_BUBBLE_TEXT_MAX_LENGTH];
	
		
	}text;
} QVET_BUBBLE_TEMPLATE_INFO;

typedef struct _tagAMVE_MUL_BubbleTemplateInfo
{
	MDWord dwParamID;	
	MRECT textRegion;
	QVET_BUBBLE_TEMPLATE_INFO btInfo;
}AMVE_MUL_BUBBLE_TEMPLATE_INFO;

typedef struct _tagAMVE_MUL_BUBBLETEXT_INFO
{
	MDWord dwTextCount;
	MRECT rcRegionRect;
	MDWord dwPreviewPos;
	MInt64    llTemplateID;
	AMVE_MUL_BUBBLE_TEMPLATE_INFO *pMulBTInfo;
}AMVE_MUL_BUBBLETEXT_INFO;

typedef struct __tag_SwitchGroupInfo{
    MDWord dwItemCount;
    MDWord* pItemList;
}QVET_PASTE_SWITCH_GROUP_INFO;

typedef struct __tag_PasteSwitchInfo
{
    MDWord dwType;
    MDWord dwRandom;
    MDWord dwGroupCount;
    QVET_PASTE_SWITCH_GROUP_INFO* pGroupList;
}QVET_PASTE_SWITCH_INFO;

typedef struct __tagQVET_COVER_TITLE_INFO
{
	MDWord dwTextStart;
	MDWord dwTextEnd;
	MFloat fLayerID;
	QVET_BUBBLE_TEMPLATE_INFO bubbleInfo;
} QVET_COVER_TITLE_INFO;

typedef struct __tagEffectDisplayInfo
{
	MFloat fRotation;
	MDWord dwTransparency;
	MRECT rcRegion;
} QVET_EFFECT_DISPLAY_INFO;

typedef struct __tagQVET_ANIMATED_FRAME_INFO
{
	MDWord dwVersion;
	MRECT rcDispRegion;
	MDWord dwDuration;
	MDWord dwExamplePos;
	MBool bHasAudio;
	MDWord dwVideoID;
	MDWord dwMusicID;
	MDWord dwFrameWidth;
	MDWord dwFrameHeight;
	MBool bAlphaNeedPreMulti;
    MFloat fPitchValue;
} QVET_ANIMATED_FRAME_TEMPLATE_INFO;

typedef struct __tagQVET_SCENE_ELEMENT_TIME
{
	AMVE_POSITION_RANGE_TYPE range; //Source出现的时间范围
	MDWord dwSingleTime;			//单次Source的时间，如果这个值为0，同时忽略dwSingleTime和dwIntervalTime
	MDWord dwIntervalTime;			//两次Source的间隔时间，如果这个值为0，同时忽略dwSingleTime和dwIntervalTime
} QVET_SCENE_ELEMENT_TIME;

typedef struct __tagQVET_SCENE_ELEMENT_INFO
{
	MDWord dwFocusImageID;
	MRECT rcDisplay;
	MPOINT ptTipsLocation;
	MDWord dwAlignment;
	MDWord dwShadeFrameID;
    MBool  bApplyPanzoom;
	QVET_SCENE_ELEMENT_TIME time;
} QVET_SCENE_ELEMENT_INFO;


typedef struct __tagQVET_SCENE_INFO_CFG
{
	MDWord dwDuration;
	MDWord dwFPS;
	MDWord dwElementCount;
	QVET_SCENE_ELEMENT_INFO* pElementInfo;
} QVET_SCENE_INFO_CFG;

typedef struct  
{
	MIntPtr pClipID;
	MBool bIsTransition;
	MDWord dwPosition;
} QVET_CLIP_POSITION;

typedef struct
{
    MDWord dwDataType;
	MChar pName[32];
	MVoid* pData;
}QVET_IEPARAM_DATA_UNIT;

typedef struct  
{
    MDWord dwAttrDataCount;
	QVET_IEPARAM_DATA_UNIT* pAttrData;
	MDWord dwUniformDataCount;
	QVET_IEPARAM_DATA_UNIT* pUniformData;
	MDWord dwTextureCount;
	MBool bNeedOrgTexture;
}QVET_EFFECT_PARAM;

typedef struct
{
	MDWord dwFilterType;
	MChar* pVShader;
	MChar* pFShader;
	MDWord dwTableCount;
	QVET_EFFECT_PARAM param;
}QVET_EFFECT_SETTING;

typedef struct  
{
	MTChar szTemplateFile[AMVE_MAXPATH];
	MSIZE layoutSize;
	MFloat fRotation;
}QVET_TEMPLATE_IDENTIFIER;

typedef struct  
{
	MBool bIsSingleFrame;
	MDWord dwTimeStamp;
}QVET_SINGLEFRAME_PARAM;

typedef struct  
{
	MDWord dwPropID;
	MLong lValue;
}QVET_EFFECT_PROPDATA;

typedef struct
{
	MDWord dwDuration;
	MDWord dwOpacity;
	MRECT rcCrop;
	MRECT rcDisplay;
	MFloat fRotation;
}QVET_ANIMATE_POINT_DATA;

typedef struct
{
    MDWord dwOptType;
	MDWord dwPointIndex;
	QVET_ANIMATE_POINT_DATA PointData;
}QVET_AINIMATE_POINT_OPERATION_DATA;

typedef MRESULT (*QVET_TRCFILE_DECRYPT_CALLBACK)(MTChar *pszTRCFile,  MWChar** ppszWLyrics/*out*/,  MLong *plCharNum, MVoid* pUserData);

typedef struct _tagQVET_TRCFILE_DECRYPTOR{
	QVET_TRCFILE_DECRYPT_CALLBACK pfnDecryptCB;
	MVoid*	pUserData;	//pUserData在android上是一个java接口的global ref，iOS上是delegate
}QVET_TRCFILE_DECRYPTOR;




//Add for slideplus support video
#define QVET_SLSH_SOURCE_TYPE_NONE      0x0
#define QVET_SLSH_SOURCE_TYPE_IMAGE     0x1
#define QVET_SLSH_SOURCE_TYPE_VIDEO     0x2

#define QVET_MAX_CLIP_POSITION_COUNT    8

#define AMVE_FLIP_NONE							0x00000000
#define AMVE_X_FLIP_MASK						0x00000001  //沿X方向镜像
#define AMVE_Y_FLIP_MASK						0x00000002  //沿Y方向镜像


typedef struct
{
    MLong lFaceCenterX;
	MLong lFaceCenterY;
	MBool bFaceDetected;
	//MDWord dwImageWidth;
	//MDWord dwImageHeight;
}QVET_SLSH_IMAGE_SOURCE_INFO;

typedef struct
{
    MLong lFaceCenterX;
	MLong lFaceCenterY;
	MBool bFaceDetected;
	//MDWord dwImageWidth;
	//MDWord dwImageHeight;
}QVET_SLSH_VIRTUAL_IMAGE_SOURCE_INFO;

typedef struct
{
    AMVE_POSITION_RANGE_TYPE srcRange;
	MDWord dwCurPos;
	MDWord dwSceneCount;
	MDWord dwUsedSceneCount;
}QVET_SLSH_VIDEO_SOURCE_INFO;

typedef struct
{
    MDWord dwSourceType;
	MTChar szSourcePath[AMVE_MAXPATH];
	MDWord dwRotation;
	MDWord dwFrameWidth;
	MDWord dwFrameHeight;
	union
	{
	    QVET_SLSH_IMAGE_SOURCE_INFO imageSourceInfo;
		QVET_SLSH_VIDEO_SOURCE_INFO videoSourceInfo;
	}source_info_node;
}QVET_SLSH_SOURCE_INFO_NODE;


typedef struct
{
    MLong lPicCenterX;   //用于标注video显示时 图像的中心点
	MLong lPicCenterY;
    AMVE_POSITION_RANGE_TYPE trimRange;
	MBool bPlayToEnd;
}QVET_SLSH_VIRTUAL_VIDEO_SOURCE_INFO;

typedef struct
{
    MDWord dwRealSourceIndex;
	MDWord dwSourceType;
	MTChar szSourcePath[AMVE_MAXPATH];
	MDWord dwPreviewPos;
	MDWord dwSceneDuration;
    MDWord dwSceneIndex;
	MFloat fAspectRatio; //结点所在场景的显示比例
    MBool bTransformFlag;
	QVET_TRANSFORM_PARAMETERS transformPara;
	MDWord dwFrameWidth;
	MDWord dwFrameHeight;
	MBool bApplyPanzoom;
	MBool bCropFlag; //表示app是否设置了crop区域的flag
	MRECT rcCrop; //app设置下来 的crop区域
	MRECT region; //源在场景中显示的区域,用于app点中

	union
	{
	    QVET_SLSH_VIRTUAL_IMAGE_SOURCE_INFO imageSourceInfo;
		QVET_SLSH_VIRTUAL_VIDEO_SOURCE_INFO videoSourceInfo;
	}source_info_node;
}QVET_SLSH_VIRTUAL_SOURCE_INFO_NODE;

typedef struct
{
    MTChar* pszFilePath;
	MBool bPIP;
	MBool bHDOutput;
	MBool bReverse;
	MBool bHWEnc;
	MBool bHWDec;
	MDWord dwCPUNum;
}QVET_VIDEO_IMPORT_QUERY_PARAM;

typedef struct _tag_AMVE_EFFECT_EXPRESSION_INFO
{
    MDWord dwType;  //AMVE_FACEDT_EXPRESSION_TYPE_XXX
    MFloat fMinRatio;
	MFloat fMaxRatio;
	MBool bDisappearAtOnce;
    MDWord dwBehavior;
}AMVE_EFFECT_EXPRESSION_INFO;

typedef struct _tag_AMVE_EFFECT_ABFACE_INFO
{
    MBool bABFace;
    MDWord dwType; //QVET_EFFECT_ABFACE_TYPE_XXX
	MDWord dwApplyFace; //QVET_EFFECT_ABFACE_APPLY_XXX for QVET_EFFECT_ABFACE_TYPE_COMBO
	                    //face index for QVET_EFFECT_ABFACE_TYPE_INDEX
    MDWord dwComboMode;
    MDWord dwTotalCount;
}AMVE_EFFECT_ABFACE_INFO;

typedef struct _tag_AMVE_PASTER_FACIAL_INFO
{
    MBool bFollowFace;          //是否跟随人脸,有些人脸贴纸仅仅和表情有关,大小和位置与人脸无关
    MDWord dwFdlibType;         // 0 SenceTime  1 Arcsoft
    MFloat fAnchorPoint[3];    //Anchor point of paster
    MDWord dwXPointNo;         //The point number of x axis refer to(0~105)
    MLong  lXOffset;          //The offset to x axis refer point in pixels
    MDWord dwYPointNo;         //The point number of y axis refer to(0~105)
    MLong  lYOffset;          //The offset to y axis refer point in pexels
    MDWord dwAlignment;
	MSIZE  faceSize;
	MSIZE  pasterSize;
	MDWord dwAdjustPositionWay;
	AMVE_EFFECT_EXPRESSION_INFO expressionInfo;
	AMVE_EFFECT_ABFACE_INFO ABFaceInfo;
}AMVE_PASTER_FACIAL_INFO;

typedef struct _tag_AMVE_FACIAL_PASTER_DATA_TYPE
{
    MDWord dwCateID;
	MDWord dwSubType;
	AMVE_PASTER_FACIAL_INFO FacialInfo;
}AMVE_FACIAL_PASTER_DATA_TYPE;

typedef struct _tag_QVET_FRAME_SIZE_REF_ITEM
{
    MDWord dwParamID;  //frame param xml id
    MDWord dwOriginType; //refered image origin type
    MDWord dwSizeCount; //material size count
	MSIZE* pSizeList;
}QVET_FRAME_SIZE_REF_ITEM;

typedef struct _tag_QVET_FRAME_SIZE_REF_LIST
{
    MDWord dwItemCount;
	QVET_FRAME_SIZE_REF_ITEM* pFrameSizeRefItem;
}QVET_FRAME_SIZE_REF_LIST;


typedef struct __tagQVET_BUFFER
{
	MByte *pData;
	MDWord dwBufLen;
	MDWord dwDataLen;
	MDWord dwHeadEmptyLen; //buffer头上空了多少字节

	MDWord dwTimeStamp;
	MDWord dwTimeSpan;
}QVET_BUFFER;


typedef struct
{
    MTChar szTemplateFile[AMVE_MAXPATH];
    AMVE_USER_DATA_TYPE tpmData;
} QVET_EP_TPM_DATA;

typedef struct
{
    MFloat fScale;       //字幕动画的放大倍数
	MFloat fRotation;    //字幕动画绕自身的旋转角度
	MDWord dwFlip;       //字幕动画的翻转状态
	MPOINT curCenter;    //用户设置的文字显示的中心位置
	MPOINT orgCenter;    //模板中定义的文字显示的中心位置
}QVET_TA_PROPERTY_DATA;


typedef struct
{
    MDWord dwEditable;
	MDWord dwAlignment;
	MDWord dwPosAlignment;
	MDWord dwPreviewPos;
	MTChar szDefaultText[QVET_BUBBLE_TEXT_MAX_LENGTH];
	MDWord dwFontID;
	MDWord dwParamID;
	MRECTF  rcRegion;
}QVET_TEXT_ANIMATE_INFO_TEXT_SETTTINGS;

//因为etieframe不对sessioncore以外的模块开放,
//所以这里 重新定义一套vector和transform,object info

typedef struct _tag_QVET_FRAME_OBJECT_INFO
{
    MFloat cxNode;
	MFloat cyNode;
	MFloat cxView;
	MFloat cyView;
	MDWord resize;
	MDWord node_size_mode;
	MDWord resampleMode;
}QVET_FRAME_OBJECT_INFO;




typedef struct _tag_QVET_FRAME_SP_INFO
{
    QVET_FRAME_OBJECT_INFO objInfo;
	MRECTF textRect;   //文字在底图中所占区域,用归一化的比值
	QVET_FRAME_TRANSFORM transform;
}QVET_FRAME_SP_INFO;

typedef struct
{
    MDWord dwVersion;
    MDWord dwDefLength;
    MBool bLengthEditable;
    MDWord dwMinLength;
    MDWord dwMaxLength;
}QVET_FREEZE_FRAME_BASICINFO;

typedef struct
{
    MFloat fAnchorPoint[3];  
	MLong lXOff;
	MLong lYOff;
	MDWord dwAlignment;
	MSIZE ObjSize;
	MSIZE PasterSize;
	MDWord dwAjustPosWay;
}QVET_PASTER_OBJECT_TRACKING_INFO;

typedef struct _tag_QVET_OT_RESULT
{
    MRECT resultRect; //被跟踪物体的rect
}QVET_OT_RESULT;

typedef struct _tag_QVET_EFFECT_EXTERNAL_SOURCE
{
	AMVE_POSITION_RANGE_TYPE dataRange;
	MDWord dwRotation;
	MRECT cropRect;
	AMVE_MEDIA_SOURCE_TYPE* pSource;
} QVET_EFFECT_EXTERNAL_SOURCE;

typedef struct _tag_QVET_3D_MATERIAL_ITEM
{
    MTChar* pszMaterialName;
	MDWord dwParamID; //3D Config param id
	MSIZE NodeSize;
	MSIZE ViewSize;
	MDWord dwResampleMode;
    MDWord dwTAParamID; //ID for text animation param
    MDWord dwTAOrigin;  //text animation origin type
}QVET_3D_MATERIAL_ITEM;

typedef struct _tag_QVET_3D_MATERIAL_LIST
{
    MDWord dwCount;
	QVET_3D_MATERIAL_ITEM* pMaterialItem;
}QVET_3D_MATERIAL_LIST;

typedef struct _tag_QVET_3D_HITTEST_RES
{
    MHandle h3DHandle;
	MHandle hAtom3D;
}QVET_3D_HITTEST_RES;

typedef struct _tag_QVET_3D_HITTEST_DATA
{
    QVET_3D_HITTEST_RES TestRes;
	MLong lX;
	MLong lY;
	MLong lZ;
}QVET_3D_HITTEST_DATA;


typedef struct _tag_QVET_3D_TRANSFORM_DATA
{
    QVET_3D_HITTEST_RES TestRes;
	MFloat fValue[3];
}QVET_3D_TRANSFORM_DATA;

typedef struct _tag_QVET_3D_BOUND_BOX_DATA
{
    QVET_3D_HITTEST_RES TestRes;
	MBool bDisplay;
}QVET_3D_BOUND_BOX_DATA;



typedef struct _tagQVET_WM_DETECT_CALLBACK_DATA
{
	MDWord status; //AMVE_PROCESS_STATUS_XXX

	MDWord startTimePos;
	MDWord curTimePos;
	MDWord timeLength;
	MDWord detectActionCnt;


	MChar* wmCode;

	MRESULT dbgRunErr;
	MRESULT dbgWMErr;
}QVET_WM_DETECT_CALLBACK_DATA;


typedef MVoid (*QVET_PFN_WM_DETECT_CALLBACK)(
		QVET_WM_DETECT_CALLBACK_DATA *cbData,
		MVoid* pUserData);


typedef struct _tagQVET_WM_DETECT_PARAM
{
	QVET_PFN_WM_DETECT_CALLBACK fnCallBack;
	MVoid* userData;
	
	MTChar videoFile[AMVE_MAXPATH];

	MDWord startPos; //time pos
	MDWord length;	//-1 means detect to the end of video

	MBool   bKeyFrameDetect;
	MDWord maxDetectActionCnt;
	MDWord maxDetectResultCnt;
	MDWord	frameUnitCnt;
}QVET_WM_DETECT_PARAM;

typedef struct _tagQVET_FACEDT_UTILS_CONTEXT
{
    MHandle hFaceDTContext;
	MHandle hAPPContext;
	MHandle hSessonContext;
}QVET_FACEDT_UTILS_CONTEXT;



typedef struct _tag_AMVE_FACE_EXPRESSION_INFO
{
   MFloat fLEyeOpenRatio;  //左眼睁开的ratio
   MFloat fREyeOpenRatio;  //右眼睁开的ratio
   MFloat fLEyebrowRaiseRatio; //左眉挑起的ratio
   MFloat fREyebrowRaiseRatio; //右眉挑起的ratio
   MFloat fMouthOpenRatio; //嘴巴张开的ratio
}AMVE_FACE_EXPRESSION_INFO;

typedef struct _tag_AMVE_FACE_INFO
{
   MPOINT Point[AMVE_FACEDT_RESULT_POINT_COUNT];
   MRECT faceRect;
   MFloat fRotation[3];
   AMVE_FACE_EXPRESSION_INFO expressionInfo;
}AMVE_FACE_INFO;

typedef struct _tag_AMVE_FACEDT_RESULT_TYPE 
{
   MDWord dwFaceCount;
   MDWord dwMaxFaceID; //最大脸ID
   AMVE_FACE_INFO mFaceInfo[AMVE_FACEDT_MAX_FACE_COUNT];
   MBool bFaceDetected;
   MDWord dwDTOriention;
}AMVE_FACEDT_RESULT_TYPE;




typedef struct __tagQVET_TRAJECTORY_VALUE
{
	MDWord ts; //timestamp list, it's  the effect-self timestamp
	MFloat rotation; //self-rotation angle around the object's center ——未启用
	MRECT region; //与effect的PROP_VIDEO_REGION概念一致，对于只有"点"概念的对象，只需确保rect的中心与实际点一致即可。rect的size不重要
}QVET_TRAJECTORY_VALUE;


#define QVET_TRAJECTORY_UPDATE_MODE_REPLACE				0 //不仅数据替换，老轨迹的属性也会替换
#define QVET_TRAJECTORY_UPDATE_MODE_EXPAND 				1 //数据会扩展，属性扩展没意义，属性替换成新轨迹的
typedef struct __tagQVET_TRAJECTORY_DATA
{
	MDWord	updateMode; //expand or replace the old trajectory; default mode is "replace"
	MBool	useTimePos; //是否使用timePos信息， CE侧涂鸦是静态呈现，不随时间变化。VE侧可以随时间变化，也可以不变化
	QVET_TRAJECTORY_VALUE *value;	
	MDWord cnt;
	MDWord capacity;
}QVET_TRAJECTORY_DATA;




typedef struct __tagQVET_KEYFRAME_TRANSFORM_VALUE
{
	MDWord ts;	   //时间戳
	MPOINT pos;    //中心点位置
	//MSIZE size;	   //宽高
	MFloat rotation; //旋转角度
	MFloat widthRatio;	// size.cx = origin.size.cx * widthRatio
	MFloat heightRatio;	// size.cy = origin.size.cy * heightRatio
}QVET_KEYFRAME_TRANSFORM_VALUE;


typedef struct __tagQVET_KEYFRAME_TRANSFORM_DATA
{
	MDWord dwMethod; // not used
	QVET_KEYFRAME_TRANSFORM_VALUE* values;
	MDWord size; // values数组包含的个数

}QVET_KEYFRAME_TRANSFORM_DATA;


typedef struct __tagQVET_KEYFRAME_FLOAT_VALUE
{
	MDWord ts;
	MFloat floatValue;
}QVET_KEYFRAME_FLOAT_VALUE;


typedef struct __tagQVET_KEYFRAME_FLOAT_DATA
{
	MDWord dwMethod;
	QVET_KEYFRAME_FLOAT_VALUE* values;
	MDWord size;

}QVET_KEYFRAME_FLOAT_DATA;



typedef struct __tagQVET_KEYFRAME_COLORA_VALUE
{
	MDWord ts;
	MDWord color;
}QVET_KEYFRAME_COLORA_VALUE;

typedef struct __tagQVET_KEYFRAME_COLORA_DATA
{
	MDWord dwMethod;
	QVET_KEYFRAME_COLORA_VALUE* values;
	MDWord size;

}QVET_KEYFRAME_COLORA_DATA;



typedef struct __tagQVET_KEYFRAME_AUDIO_VALUE
{
	MDWord ts;
	MDWord volume;
	MDWord tone;
}QVET_KEYFRAME_AUDIO_VALUE;


typedef struct __tagQVET_KEYFRAME_AUDIO_DATA
{
	MDWord dwMethod;
	QVET_KEYFRAME_AUDIO_VALUE* values;
	MDWord size;

}QVET_KEYFRAME_AUDIO_DATA;






typedef struct
{
    MInt64 ID;
	MDWord dwImgSrcCount;
	MDWord dwReserveCount;
	MSIZE viewSize; //该场景的view size
	MDWord* pdwPreviewPos; //preview position in this scene
	MRECT* pRegion; //万分比表示源在场景中的区域
}QVET_THEME_SCECFG_ITEM;

typedef struct
{
    MDWord dwVersion;
	MDWord dwBestDispTime;				// 该主题的总时长 m_dwTotalSceneTime;
	MDWord dwImgCacheCount;
	MDWord dwCoverCount;
    QVET_THEME_SCECFG_ITEM* pCoverItem;	// 封面
	MDWord dwBackCount;
	QVET_THEME_SCECFG_ITEM* pBackItem;	// 封底
	MDWord dwBodyCount;
	MBool bRandom;
	QVET_THEME_SCECFG_ITEM* pBodyItem;	// 实际内容;
}QVET_THEME_SCECFG_SETTINGS;

typedef struct __tagEffect_Preview_Position
{
	MBool bIsSettingPosition;
	MDWord dwPreviewPosition;
	MUInt64 llTemplateId;
}QEVT_EFFECT_PREVIEW_INFO;
/*
    Camera录制时加的effect,由于不会被保存在工程，
    为了方便app做埋点，这里加一个数据结构保存到工程里
*/
typedef struct
{
	MInt64 llTemplateID; //template id
	MDWord dwPorpCount;  //property count
	QVET_EFFECT_PROPDATA* pPropData; //property data,可以记录比如美颜程度等信息
}QVET_CAM_EXPORT_EFFECT_DATA;

typedef struct
{
    MDWord dwCount;
	QVET_CAM_EXPORT_EFFECT_DATA* pExportData;
}QVET_CAM_EXPORT_EFFECT_DATA_LIST;



typedef struct _tagAMVE_MULTI_MEDIA_SOURCE_TYPE
{
	MDWord dwSrcType; //AMVE_MEDIA_SOURCE_TYPE_FILE, etc.
	MVoid* pSource;	
	MDWord dwSourceCount;
	MBool bIsTmpSrc;
}AMVE_MEDIA_MULTI_SOURCE_TYPE;

typedef struct
{
    MDWord dwType;
	MDWord dwTrackType;
	MDWord dwGroupID;
	MDWord dwSubType;
	MFloat fLayerID;
	AMVE_MEDIA_SOURCE_TYPE mediaSource;
}QVET_PRODUCER_EFFECT_INFO;

typedef struct
{
    MDWord dwTimeStamp;
    MDWord dwCount;
	QVET_PRODUCER_EFFECT_INFO* pEffectInfo;
}QVET_PRODUCER_EFFECT_INFO_LIST;


typedef struct
{
    MDWord dwClipIndex;
	MDWord dwType;
	AMVE_MEDIA_SOURCE_TYPE mediaSource;
	QVET_PRODUCER_EFFECT_INFO_LIST ClipVEffectInfoList;  //clip video effect
}QVET_PRODUCER_CLIP_INFO;

typedef struct
{
    MInt64 llTemplatID;
	QVET_PRODUCER_CLIP_INFO leftClipInfo;
	QVET_PRODUCER_CLIP_INFO rightClipInfo;
}QVET_PRODUCER_TRANSITION_CLIP_INFO;



typedef struct
{
    QVET_PRODUCER_CLIP_INFO clipInfo;
	QVET_PRODUCER_TRANSITION_CLIP_INFO transitionClipInfo;
	QVET_PRODUCER_EFFECT_INFO_LIST StoryboardVEffectInfoList;  //storyboard video effect
	QVET_PRODUCER_EFFECT_INFO_LIST StoryboardAEffectInfoList;  //storyboard audio effect
}QVET_PRODUCER_CUR_STORYBOARD_INFO;


typedef struct
{
    MDWord dwErrTime;
	MDWord dwAPrcErr;
	MDWord dwVDecErr;
	MDWord dwVPrcErr;
	MBool bTransition;
	MDWord dwLClipIndex;
	MDWord dwRClipIndex;
	MDWord dwClipIndex;
	MBool bHWException;
}QVET_PRODUCER_ERR_INFO;

typedef struct _tagAudioWorkBuffer
{
	MByte* pBuffer;  //pcm buffer
	MDWord dwBufSize; //buffer size
	MDWord dwUsedSize; //已使用的buffer size
} AUDIO_WORK_BUFFER_TYPE;

/*
 * audio gain is a list description 
 */
typedef struct _tagQVET_AUDIO_GAIN
{
	//1. must start from 0;  2. must end with "-1",  "-1" means end of the audio; 
	union
	{
		MDWord  *timePos; //this name is for app. Bases on millisecond
		MDWord *smpIdx;  //this name if for adk-internal, it should be transformed from timePos before sending to the process module.
	};

	
	MFloat *gain; //gain >= 0; 1.0 means no change; 2.0 mean twice.....

	MDWord count; //count of timePos and gain. it should >=2 if you wannt to set audio gain, or 0 means clean audio gain you; count <=cap;
	MDWord cap;	 //capacity of the list

}QVET_AUDIO_GAIN;




/// LoadProjectData
typedef struct
{
	MDWord dwProjectID;

	MDWord templateCount;
	MUInt64* templates;

	MUInt64 theme;
	

	//MUInt64 cover;

} AMVE_STORYBOARD_PROJECT_DATA;



/*
 *	by Jonathan:
 *	Scale List:
 *		it can be the timePos before time-mapping or after time mapping.    RULES:  timePos * timeScale = timePos in the other  "time field"
 *	
 *	1. This struct is induced when implement the feature of time-mapping requred by designer in slideshow scene template
 *	2. in scene's template xml, the configured scale-list is the data after time-mapping
 **/
typedef struct __tagQVET_SCALE_LIST
{
	MDWord *timePos; //every timePos is correpsonding to one timeScale, it's millisecond.  for scene, it should start from 0
	MFloat *timeScale; //timeScalep[3] covers  from timePos[3] to timePos[4] (or end)


	MDWord	cnt;
	MDWord capacity; 
}QVET_SCALE_LIST;




#endif //_AMVE_DEF_H_
