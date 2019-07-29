# LDRecordButton
🔥仿微信拍照录像按钮📷，支持点击和长按事件

## 演示

<img src="http://cdn.lzcdev.xyz/record.gif" height="400" width="200"  />
## 原理


一个自定义组件，通过继承 UIView，给控件添加点击和长按的手势。通过 block 回调出去。通过 CADisplayLink 这个定时器每隔 1/60s 调用一次 drawRect 方法， 重新绘制界面的布局，包括中间的圈、周围透明部分和进度条。这三部分通过 CAShapeLayer 和 UIBezierPath 实现。通过 CGRectInset 缩放圈的 frame .

## 使用方式
```
    LDRecordButton *button = [[LDRecordButton alloc] initWithFrame:CGRectMake([UIScreen mainScreen].bounds.size.width / 2 - 25, 200, 50, 50)];
    [button actionWithBlock:^(LDRecordButtonState state) {
        switch (state) {
            case LDRecordButtonStateClick:
                NSLog(@"Click");
                break;
            case LDRecordButtonStateBegan:
                NSLog(@"longPressBegan");
                break;
            case LDRecordButtonStateEnd:
                NSLog(@"longPressEnd");
                break;
            default:
                break;
        }
    }];
    [self.view addSubview:button];
```
## 更多属性设置
```
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

如果要设置圈的缩放比例，可去 drawRect 中修改 CGRectInset 方法
```
