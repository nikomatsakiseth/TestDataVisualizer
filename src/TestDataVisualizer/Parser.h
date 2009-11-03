//
//  Parser.h
//  TestDataVisualizer
//
//  Created by Niko Matsakis on 11/3/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 Parses text files containing measurements.  The "format"
 wasn't defined organically, of course, but is rather ad-hoc.
 
 Run files begin with a header.  After the header come a series of 
 measurement sections. Measurement sections look like:
 
 Running java -Xmx2048M jgfmt.section2.JGFSeriesBenchSizeA 8 
 Running java -Xmx2048M jgfmt.section2.JGFSeriesBenchSizeA 8 
 Running java -Xmx2048M jgfmt.section2.JGFSeriesBenchSizeA 8 
 Running java -Xmx2048M jgfmt.section2.JGFSeriesBenchSizeB 8 
 Running java -Xmx2048M jgfmt.section2.JGFSeriesBenchSizeB 8 
 Running java -Xmx2048M jgfmt.section2.JGFSeriesBenchSizeB 8 
 Running java -Xmx2048M jgfmt.section2.JGFSeriesBenchSizeC 8 
 Running java -Xmx2048M jgfmt.section2.JGFSeriesBenchSizeC 8 
 Running java -Xmx2048M jgfmt.section2.JGFSeriesBenchSizeC 8 
 SizeA   SizeB   SizeC
 0.991   9.707   189.668
 1.0     9.73    192.481
 1.001   9.823   190.04
 
 Lines beginning with "Running " are the queue to the
 parser that we have ended the header or previous section.
 The parser looks for a contiguous set of such lines.  Each
 Running line will be matched against the test definitions.
 As a result, a particular TestDefn and property dictionary
 will be extracted (if no test defn matches, an error occurs).
 
 Lines containing numbers and spaces each define a set of measurements.
 It is expected that the line will contain one column for each
 variant.  Furthermore, each row defines a value for the next 
 measurement kind.  In the above example there was one kind of measurement,
 but for other tests, each test run may generate two rows (say, "init" and "total").
 In that case, the first row is considered "init" for the first run,
 and the second row is considered "total", or what have you.
 It's an error if the number of rows is not a multiple for the number of
 measurement kinds.
*/
@interface Parser : NSObject {
	NSString *input;
	NSArray *testDefns;
}
- initWithTestDefns:(NSArray*)testDefns input:(NSString*)input;

// Returns nil on parse error (and sets *error).
- (Session*)parse:(NSError**)error;
@end
