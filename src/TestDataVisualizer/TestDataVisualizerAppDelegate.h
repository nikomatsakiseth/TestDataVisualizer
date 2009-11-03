//
//  TestDataVisualizerAppDelegate.h
//  TestDataVisualizer
//
//  Created by Niko Matsakis on 11/3/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface TestDataVisualizerAppDelegate : NSObject <NSApplicationDelegate> {
    NSWindow *window;
}

@property (assign) IBOutlet NSWindow *window;

@end
