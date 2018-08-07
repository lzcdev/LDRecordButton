//
//  ViewController.m
//  LDRecordButton
//
//  Created by lzcdev on 2017/5/18.
//  Copyright © 2017年 lzcdev. All rights reserved.
//

#import "ViewController.h"
#import "LDRecordButton.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.view.backgroundColor = [UIColor grayColor];
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


}


@end
