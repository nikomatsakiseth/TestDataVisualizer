//
//  Parser.m
//  TestDataVisualizer
//
//  Created by Niko Matsakis on 11/3/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import "Parser.h"
#import "Model.h"

#define RUNNING @"Running "

@implementation Parser

- initWithTestDefns:(NSArray*)_testDefns input:(NSString*)_input
{
	if((self = [super init])) {
		testDefns = [_testDefns retain];
		input = [_input copy];
	}
	return self;
}

- (void)dealloc
{
	[testDefns release];
	[input release];
	[super dealloc];
}

- (TestDefn*)findTestDefn:(NSString*)commandLine
{
	for() {
	}
}

- (Session*)parse:(NSError**)error
{
	NSArray *lines = [input componentsSeparatedByString:@"\n"];
	
	// Find end of header:
	int line = 0, count = [lines count];
	while(line < count) {
		if([[lines objectAtIndex:line] hasPrefix:RUNNING])
			break;
		line++;			
	}
	
	NSArray *headerLines = [lines subarrayWithRange:NSMakeRange(0, line)];
	NSString *headerText = [headerLines componentsJoinedByString:@"\n"];
	Session *session = [[[Session alloc] init] autorelease];
	session.header = headerText;
	
	// Read in measurements:
	NSMutableArray *allTestRuns = [NSMutableArray array];
	while(line < count) {	
		NSMutableArray *theseTestRuns = [NSMutableArray array];
		
		// Identify variants:
		while(line < count && [[lines objectAtIndex:line] hasPrefix:RUNNING]) {
			NSString *lineText = [lines objectAtIndex:line];
			TestDefn *testDefn = [self findTestDefn:lineText];
		}
	}
}

@end
