//
//  FWTPopoverController.h
//  FWTPopoverHintView
//
//  Created by Marco Meschini on 8/8/12.
//  Copyright (c) 2012 Futureworkshops. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FWTAnnotationView.h"
#import "FWTAnnotation.h"

@class FWTAnnotationManager;
@protocol FWTAnnotationManagerDelegate <NSObject>
@optional
- (FWTAnnotationView *)annotationManager:(FWTAnnotationManager *)annotationManager viewForAnnotation:(FWTAnnotation *)annotation;
- (void)annotationManager:(FWTAnnotationManager *)annotationManager didTapAnnotationView:(FWTAnnotationView *)annotationView annotation:(FWTAnnotation *)annotation;
@end

@interface FWTAnnotationManager : NSObject
{
    UIView *_view, *_contentView;
    NSMutableArray *_annotations;
    NSMutableDictionary *_annotationsDictionary;
    UITapGestureRecognizer *_tapGestureRecognizer;
    
    id<FWTAnnotationManagerDelegate> _delegate;
    struct
    {
        BOOL viewForAnnotation: 1;
        BOOL didTapAnnotationView: 1;
    } _delegateHas;
    
    BOOL _removeAnnotationsWithRandomDelay;
}

@property (nonatomic, retain) UIView *view;
@property (nonatomic, readonly, retain) NSMutableArray *annotations;
@property (nonatomic, assign) id<FWTAnnotationManagerDelegate> delegate;
@property (nonatomic, assign) BOOL removeAnnotationsWithRandomDelay;

- (void)addAnnotation:(FWTAnnotation *)annotation;
- (void)addAnnotations:(NSArray *)annotations;

- (void)removeAnnotation:(FWTAnnotation *)annotation;
- (void)removeAnnotations:(NSArray *)annotations;

- (FWTAnnotationView *)viewForAnnotation:(FWTAnnotation *)annotation;
- (FWTAnnotation *)annotationForView:(FWTAnnotationView *)view;
- (FWTAnnotationView *)viewAtPoint:(CGPoint)point;

- (void)cancel;

- (BOOL)hasSuperview;

@end