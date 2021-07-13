//
//  ZTLogManager.h
//  ZTCloudMirror
//
//  Created by ZWL on 2018/12/7.
//  Copyright © 2018 CITCC4. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, ZTLogType) {
    ZTLogTypeSysReminder, // 系统提示
    ZTLogTypeCommonLog // 普通日志
};

@class ZTLogController;
@interface ZTLogManager : NSObject

+(instancetype)shareManager;

/// 创建根视图控制器，包含日志界面控制器和主程序控制器。摇一摇打开日志页面
/// @param mainViewController 主程序控制器
-(UIViewController *)createRootViewController:(UIViewController *)mainViewController;

/// 开始日志采集。默认连接Xcode时，仍然通过App内部显示日志。摇一摇打开日志页面
-(void)start;

/// 开始日志采集。如果连接Xcode，是否仍要通过App内部显示日志。摇一摇打开日志页面
/// @param showInAppWhenConnectedXcode YES 是  NO 否。
/// 当为YES时，Xcode里将不再显示日志信息，当为NO时，app里面仅显示通过下面print方法所打印的日志信息。
/// 为了能够直接显示NSLog方法的信息，需要您用宏定义重写NSLog方法，具体如下：
/// #ifdef DEBUG
/// #define NSLog(FORMAT, ...) fprintf(stderr,"%s:%d\n%s\n-----------------------------------------\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);[ZTLogManager.shareManager printByNSlog:[NSString stringWithFormat:@"%@:%d\n%@\n-----------------------------------------\n",[[NSString stringWithUTF8String:__FILE__] lastPathComponent],__LINE__,[NSString stringWithFormat:FORMAT, ##__VA_ARGS__]] textColor:UIColor.whiteColor];
/// #else
/// #define NSLog(...)
/// #endif
-(void)start:(BOOL)showInAppWhenConnectedXcode;

/// 停止日志采集
-(void)stop;

/// 继续日志采集
-(void)proceed;

/// 暂停日志采集
-(void)pause;

/// 清除日志
-(void)clear;

/// 滚动到底部
/// @param animated YES带动画 NO 无动画
-(void)scrollToBottom:(BOOL)animated;

/// 滚动到顶部
/// @param animated YES带动画 NO 无动画
-(void)scrollToTop:(BOOL)animated;

/// 打印日志，仅用于重写NSLog自动打印的日志
/// @param text 日志内容
/// @param textColor 日志颜色
-(void)printByNSlog:(NSString *)text textColor:(UIColor * )textColor;

/// 打印日志
/// @param text 日志内容
/// @param textColor 日志颜色
/// @param type 日志类型：当为ZTLogTypeSysReminder时，暂停日志显示时，仍可显示。否则，不显示
-(void)print:(NSString *)text textColor:(UIColor * )textColor logType:(ZTLogType)type;

/// 打印日志
/// @param text 日志内容
/// @param type 日志类型：当为ZTLogTypeSysReminder时，暂停日志显示时，仍可显示。否则，不显示
-(void)print:(NSAttributedString *)text logType:(ZTLogType)type;

/// 获取图片，此方法会先从主应用中获取，若没有，则获取Resource.bundle中的图片。若需要自定义图片，请在您的主应用中，添加与Resource.bundle中名字相同的图片即可
/// @param name 图片名字
+(UIImage *)imageNamed:(NSString *)name;

@end
