//
//  FWTPopoverDescriptor.m
//  FWTPopoverHintView
//
//  Created by Marco Meschini on 8/8/12.
//  Copyright (c) 2012 Futureworkshops. All rights reserved.
//

#import "FWTAnnotation.h"

@interface FWTAnnotation ()
@property (nonatomic, readwrite, retain) NSString *guid;
@end

@implementation FWTAnnotation

- (void)dealloc
{
    self.guid = nil;
    self.text = nil;
    self.image = nil;
    [super dealloc];
}

- (id)init
{
    if ((self = [super init]))
    {
        self.guid = [[self class] _GUID];
        self.presentingRectPortrait = CGRectZero;
        self.presentingRectLandscape = CGRectZero;
        self.arrowDirection = FWTPopoverArrowDirectionNone;
        self.delay = .0f;
        self.animated = YES;
        self.dismissOnTouch = YES;
    }
    
    return self;
}

+ (NSString *)_GUID
{
	CFUUIDRef theUUID = CFUUIDCreate(NULL);
	CFStringRef theString = CFUUIDCreateString(NULL, theUUID);
	NSString *unique = [NSString stringWithString:(id)theString];
	CFRelease(theString);
    CFRelease(theUUID); // Cleanup
	return unique;
}

@end
