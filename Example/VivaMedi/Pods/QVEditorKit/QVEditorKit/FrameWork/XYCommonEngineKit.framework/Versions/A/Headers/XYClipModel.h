//
//  XYClipModel.h
//  XYCommonEngineKit
//
//  Created by 夏澄 on 2019/10/19.
//


#import "XYBaseEngineModel.h"
#import "XYEffectPropertyData.h"
#import "XYVeRangeModel.h"
#import "XYEffectPropertyMgr.h"
#import "XYClipEffectModel.h"
#import "XYCommonEngineGlobalData.h"

NS_ASSUME_NONNULL_BEGIN

@class XYStoryboard;
@class XYCommonEngineRequest;
@class XYEffectVisionTextModel;
@class XYAdjustEffectValueModel;
@class PHAsset;

@interface XYClipModel : XYBaseEngineModel

@property (nonatomic, copy) NSString *clipFilePath;
@property (nonatomic, copy) NSString *filterFilePath;
@property (nonatomic) NSInteger filterConfigIndex;
@property (nonatomic, copy) NSString *musicFilePath;
@property (nonatomic) NSInteger dwMusicTrimStartPos;
@property (nonatomic) NSInteger dwMusicTrimLen;
@property (nonatomic) CGRect cropRect;
@property (nonatomic) NSInteger rotation;//值范围 0-360
@property (nonatomic) NSInteger clipIndex;//当前的clipIndex
@property (nonatomic) NSInteger globalIndex;//用于切换到了临时storyboard 时使用
@property (nonatomic) BOOL isReversed;//是否被倒放

@property (nonatomic, assign) NSInteger objIndex;
@property (nonatomic, assign) BOOL isSwitchSourceRange;// 切换临时时变速后的源的长度
@property (readonly, nonatomic, assign) XYCommonEngineClipModuleType clipType;
@property (nonatomic, copy) NSArray <XYClipModel*> *clipModels;//cut model add clip model 等
@property (nonatomic, strong) XYClipEffectModel *clipEffectModel;//滤镜 转场
@property(nonatomic, assign) CGFloat storyboardRatioValue;

@property (nonatomic, assign) BOOL     isMute;//是否静音  type为video时有效
@property (nonatomic, assign) CGFloat  volumeValue;//音量值 值范围
@property (nonatomic, assign) CGFloat  voiceChangeValue;//变声值 值范围 -60~60
@property (nonatomic, assign) CGFloat  speedValue;//视频变速
@property (nonatomic, assign) BOOL     speedAdjustEffect;//视频变速是否刷新效果
@property (nonatomic, assign) BOOL     iskeepTone;//是否保持原声调
@property (nonatomic, assign) BOOL     isAudioNSXOn;//是否开启音频降噪功能
//@property (nonatomic, assign) BOOL     isAnimOn;//是否开启动画

@property (nonatomic, assign) XYClipMirrorMode mirrorMode;
@property (nonatomic, copy) NSArray <XYAdjustItem *> *adjustItems;// 参数调节等
@property (nonatomic, strong) XYEffectPropertyData *clipPropertyData;//图片动画 clip的手势 背景颜色 背景图片 属性
//@property (nonatomic, assign) NSInteger splitVideoPositon;//相对视频总时长的postion
@property (nonatomic, assign) NSInteger splitClipPostion;//相对clip分割的postion

@property (nonatomic, strong) XYClipModel *duplicateClipModel;
@property (nonatomic, assign) CGSize clipSize;//clip 的原始尺寸
@property (nonatomic, assign) CGSize sourceSize;//源视频宽高，相对streamSize的尺寸

//交互顺序
@property (nonatomic, assign) NSInteger sourceIndex;
@property (nonatomic, assign) NSInteger destinationIndex;
@property (nonatomic, strong) CXiaoYingClip *pClip;
@property (nonatomic, strong) XYAdjustEffectValueModel *adjustEffectValueModel;//如trim 变化的绝对值 左边 用于效果重新计算

@property (nonatomic, assign) NSInteger frontTransTime;//转场前部分时间
@property (nonatomic, assign) NSInteger backTransTime;//转场后部分时间
@property (nonatomic, assign) NSInteger fixTime;//用于缩略图的起始时间的校准


/// 根据phAsset 获取到给引擎的镜头路径
/// @param phAsset PHAsset对象
+ (NSString *)getClipFilePathForEngine:(PHAsset *)phAsset;
- (void)updateIdentifier:(NSString *)identifier;
- (void)reload;
- (void)reloadIsMute;
- (void)reloadVolumeValue;
- (void)reloadVoiceChangeValue;
- (void)reloadCustomCoverTextModel;
- (void)reloadFilterData;

- (XYEffectVisionTextModel *)fetchCustomBackTextModel;

@end

NS_ASSUME_NONNULL_END