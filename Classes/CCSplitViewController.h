//
//  CCSplitViewController.h
//  CCSplitViewControllerDemo
//
//  Created by Charles-Adrien Fournier on 10/04/15.
//  Copyright (c) 2015 Charles-Adrien Fournier. All rights reserved.
//

#import <UIKit/UIKit.h>

@class CCSplitViewController;

@interface UIViewController (CCSplitViewController)

@property (nonatomic, readonly) CCSplitViewController *ccSplitViewController;

@end

/**
 *  Implement this protocol to define controller in lateral view
 */
@protocol CCSplitViewControllerLateral <NSObject>
@optional

/**
 *  Warn lateral view controller about interface update
 *
 *  @param width   The new superview's width
 *  @param compact The compact value
 */
- (void)didUpdateLateralViewInterafaceWithWidth:(CGFloat)width compact:(BOOL)compact;

@end

@interface CCSplitViewController : UIViewController

/**
 *  Specifies the view controller to show, by default the second view controller was the lateral view
 */
@property (nonatomic, copy) NSArray *viewControllers;

/**
 *  Specifies the width of lateral view in landscape mode, by default 256
 */
@property (nonatomic, assign) CGFloat lateralViewWidth;

/**
 *  Color of the separation line between lateral and detail view. clearColor to make it invisible by default
 */
@property (nonatomic, strong) UIColor *separatorColor;

/**
 *  Specifies the minimal width of lateral view in portrait mode, by default 0
 */
@property (nonatomic, assign) CGFloat lateralMinimumViewWidth;

/**
 *  Specifies the insets between content view and lateral view
 */
@property (nonatomic) CGFloat insetsContentView;

/**
 *  Tell if the lateral view is hidden or compact.
 */
@property (nonatomic, readonly) BOOL isCompact;

/**
 *  Initialize CCSplitViewController
 *
 *  @return A CCSplitViewController object
 */
- (instancetype)init;

/**
 *  Initialize CCSplitViewController with view controller array
 *
 *  @param viewControllers An array of view controller
 *
 *  @return A CCSplitViewController object
 */
- (instancetype)initWithViewControllers:(NSArray *)viewControllers;

/**
 *  Set new width for lateral view and change interface
 *
 *  @param lateralViewWidth Width of lateralView
 *  @param animated         The animation value
 */
- (void)setLateralViewWidth:(CGFloat)lateralViewWidth animated:(BOOL)animated;

/**
 *  Change the detail content
 *
 *  @param vc     the new view controller
 *  @param sender the sender (is not used yet)
 */
- (void)showDetailViewController:(UIViewController *)vc sender:(id)sender;

@end
