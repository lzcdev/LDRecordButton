//
//  LDRecordButton.h
//  LDRecordButton
//
//  Created by lzcdev on 2018/8/6.
//  Copyright © 2017年 lzcdev. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, LDRecordButtonState) {
    LDRecordButtonStateBegan = 0,  // 开始长按
    LDRecordButtonStateMoving,     // 移动
    LDRecordButtonStateWillCancle, // 将要取消
    LDRecordButtonStateDidCancle,  // 已经取消
    LDRecordButtonStateEnd,        // 技术
    LDRecordButtonStateClick       // 点击
};

@interface LDRecordButton : UIView

typedef void(^RecordBlock)(LDRecordButtonState state);

@property (nonatomic, copy) RecordBlock recordBlock;

/**
 进度条走完一圈所用时间（默认10s）
 */
@property (nonatomic, assign) NSTimeInterval interval;

/**
 中间圈圈颜色（默认白色）
 */
@property (nonatomic) UIColor *centerLayerColor;

/**
 周围透明区域颜色（默认白色透明度0.6）
 */
@property (nonatomic) UIColor *circleLayerColor;

/**
 进度条颜色（默认绿色）
 */
@property (nonatomic) UIColor *progressLayerColor;

/**
 进度条宽度（默认4）
 */
@property (nonatomic, assign) CGFloat progressLayerWidth;

- (void)actionWithBlock:(RecordBlock)recordBlock;

@end
