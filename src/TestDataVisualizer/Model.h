//
//  Model.h
//  TestDataVisualizer
//
//  Created by Niko Matsakis on 11/3/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark -
#pragma mark Test Definitions (loaded from a plist)

@interface TestDefn : NSObject
{
	NSString *name;
	NSString *regexp;
	NSArray *variants;
	NSArray *measurementKinds;
}
@property (copy) NSString *name;
@property (copy) NSString *regexp;
@property (retain) NSArray *variants;
@property (retain) NSArray *measurementKinds;
@end

@interface PropertyDefn : NSObject
{
	NSString *name;
	NSString *regexp;	
}
@property (copy) NSString *name;
@property (copy) NSString *regexp;
@end

#pragma mark -
#pragma mark Measurements

// Collection of related measurements.
@interface Session : NSObject
{
	NSString *header;
	NSArray *testRuns;
}
@property (copy) NSString *header;
@property (assign) NSArray *testRuns;
@end

// Collection of measurements which were taken with
// a single command line.
@interface TestRun : NSObject
{
	Session *session; // weak ref
	TestDefn *testDefn;
	NSString *commandLine;
	NSDictionary *info;
	NSArray *measurements;
}
@property (assign) Session *session;
@property (retain) TestDefn *testDefn;
@property (copy) NSString *commandLine;
@property (retain) NSDictionary *variants;
@property (retain) NSArray *measurements;
@end

// Actual measurement.  Kind is used when
// a single run generates multiple kinds of results,
// such as "init" vs "total" time.
@interface Measurement : NSObject
{
	NSString *kind;
	NSDecimalNumber *value;
}
@property (copy) NSString *kind;
@property (copy) NSDecimalNumber *value;
@end
